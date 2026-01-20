#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SoftwareSerial.h>
#include <TinyGPSPlus.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire,);
SoftwareSerial gpsSerial(2, 3);
TinyGPSPlus gps;

double mileage {168000.0};
unsigned long lastDisplay {0};
double totalDistance {0};
double lastLat {0.0};
double lastLng {0.0};
bool hasFix {false};

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);

  gpsSerial.begin(9600);

  display.setCursor(0, 0);
  display.println("Vehicle Logger");
  display.display();
  delay(1000);
}

void loop() {
  while (gpsSerial.available()) {
    gps.encode(gpsSerial.read());
  }

  if (gps.location.isValid() && gps.location.isUpdated()) {
    double lat = gps.location.lat();
    double lng = gps.location.lng();

    if (hasFix) {
      double distMeters = TinyGPSPlus::distanceBetween(
        lastLat, lastLng, lat, lng
      );

      totalDistance += distMeters;
      mileage += distMeters / 1609.34; // meters → miles
    }

    lastLat {lat};
    lastLng {lng};
    hasFix {true};
  }

  if (millis() - lastDisplay > 500) {
    display.clearDisplay();
    display.setCursor(0, 0);

    display.print("Odometer:");
    display.println();

    display.print(mileage, 1);
    display.println(" miles");

    display.print("Trip: ");
    display.print(totalDistance / 1609.34, 2);
    display.println(" mi");

    display.display();
    lastDisplay = millis();
  }
}
