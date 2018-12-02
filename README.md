# Arduino Christmas Lights 

WS2811 (WS2812) based christmas lights with wired remote control for my daughter. Features: 8 buttons to choose colors, 1 button to change brightness, 1 button to choose effects. 

## Hardware from Aliexpress: 
- [50 WS2811 LEDs on green wire](https://www.aliexpress.com/item/50pcs-unit-DC5V-WS2811-LED-Pixel-Module-Black-Green-White-RGB-Wire-String-Lights-Christmas-Holiday/32806647416.html?spm=a2g0s.9042311.0.0.1cd74c4d6VKTIY)
- [Arduino micro clone](https://www.aliexpress.com/item/B29-1pcs-With-the-bootloader-New-Pro-Micro-ATmega32U4-5V-16MHz-Module-For-Arduino/32833555748.html?spm=a2g0s.9042311.0.0.27424c4d6erJJN) (because of 5V logic)
- [Plastic box](https://www.aliexpress.com/item/New-100x60x25mm-Plastic-Electronic-Project-Box-Black-DIY-Enclosure-Instrument-Case-Electrical-Supplies-5-PCS/32740590702.html?spm=a2g0s.9042311.0.0.27424c4d7diHZP)
- [Push buttons](https://www.aliexpress.com/item/10Pcs-New-OFF-ON-mini-Momentary-push-button-switch/32711341102.html?spm=2114.10010108.1000023.2.6afb40d2Lwal5i) (10 pcs)
- 5V power supply (15W, 3A at least)

## Wiring

| Arduino Pin | Purpose |
| ----------- | ------- |
| 2 | White button |
| 3 | Violet button |
| 4 | Blue button |
| 5 | Green button |
| 6 | LED data |
| 7 | Yellow button |
| 8 | Orange button |
| 9 | Red button |
| 10 | Pink button |
| 14 | Brightness button |
| 16 | Mode button |

- All buttons have common ground, OneButton library sets internal pullup resistor 
- Used Arduino micro has voltage regulator on USB input, to avoid its overload bypass it via shortcutting J1 contacts on the board.

## Used libraries: 
- [WS2812FX](https://github.com/kitesurfer1404/WS2812FX)
- [OneButton](https://github.com/mathertel/OneButton)