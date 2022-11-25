
# Rebol/BCM2835

Broadcom BCM 2835 extension for [Rebol3](https://github.com/Oldes/Rebol3).

Using Mike McCauley's C code taken from: https://www.airspayce.com/mikem/bcm2835/

## Usage example:
```rebol
bcm: import 'bcm2835

pins: [5 6 13 16 19 20 21 26]
with bcm [
	;; Set all pins to an output mode
	forall pins	[
		gpio_fsel pins/1 GPIO_FSEL_OUTP
	]
	;; Blink some pins
	loop 10 [
		pin: pins/(random 8)
		gpio_clr :pin
		delay 150
		gpio_set :pin
		delay 50
	]
]
```
