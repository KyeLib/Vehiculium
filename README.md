# Vehiculum
Current Version {2}

Vehiculum is an embedded systems project that uses GPS data to track distance traveled and automatically determine when vehicle maintenance is due via display.

This project shows my progress as I test and improve the system through many different versions.

## How It Works

- The GPS module continuously provides latitude and longitude data.
- The system calculates distance traveled using coordinate changes.
- Mileage is accumulated and saved to non-volatile memory.
- When the total mileage reaches a predefined service interval, the system triggers a maintenance alert.
- The display shows current mileage, trip distance, and maintenance status.

## Hardware Used 

- ESP-32
- NEO-6M GPS
- SSD1309 OLED SPI

## License

This project is open-source and available under the MIT License.

## Contributing

Contributions, suggestions, and discussions are welcome.
Please open an issue or submit a pull request.

## Acknowledgments

- TinyGPSPlus libary by mikalhart
- SSD1306 libary by Adafruit
