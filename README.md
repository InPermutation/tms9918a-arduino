# tms9918a-arduino
Talk to a Texas Instruments TMS9918A video display processor chip via an Arduino Mega clone.

## Pinout

TI, annoyingly, named the least-significant bit (LSB) on its buses "XX0",
and the most-significant bit (MSB) "XX7" or "XX15" if it was a 16-bit bus.

| Arduino pin number | TMS9918A Pin Name | TMS9918A Pin Number |
| ----------: | ----------------: | :------------------ |
| 51 | !CSW | 14 |
| 2 | CD7 (LSB) | 17 |
| 3 | CD6 | 18 |
| 4 | CD5 | 19 |
| 5 | CD4 | 20 |
| 6 | CD3 | 21 |
| 7 | CD2 | 22 |
| 8 | CD1 | 23 |
| 9 | CD0 (MSB) | 24 |
| GND | VSS | 12 |

Feel free to adapt this sketch to whatever pins you'd like to use. For example, an Arduino Nano
is definitely powerful enough to run this sketch -- I simply already owned the
Keyestudio Mega 2560 R3 that came with [Ben Eater's 6502 kit](https://eater.net/6502).

## Things that could be improved

* Use port registers instead of bit-twiddling each of the pins
* `delayMicroseconds` instead of `delay` for lower latency
* Write VRAM
* Read VRAM
* Read status register
* Refactor into a library
