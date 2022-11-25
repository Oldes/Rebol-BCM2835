
# Rebol/BCM2835

Broadcom BCM 2835 extension for [Rebol3](https://github.com/Oldes/Rebol3).

Using Mike McCauley's C code taken from: https://www.airspayce.com/mikem/bcm2835/

This extension is useful only on Raspberry PI or devices with the Broadcom chip.
So far tested only with [RPi Relay Board](https://www.waveshare.com/wiki/RPi_Relay_Board_(B)).


## Usage example:
```rebol
bcm: import 'bcm2835

pins: [5 6 13 16 19 20 21 26] ;; BCM pin numbers
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

## Extension commands:
#### `gpio_fsel` `:pin` `:mode`
Sets the Function Select register for the given pin, which configures the pin as Input, Output or one of the 6 alternate functions.
* `pin` `[integer!]` GPIO number, or one of RPI_GPIO_P1_*
* `mode` `[integer!]` Mode to set the pin to, one of GPIO_FSEL_*

#### `gpio_set` `:pin`
Sets the specified pin output to HIGH.
* `pin` `[integer!]` GPIO number, or one of RPI_GPIO_P1_*

#### `gpio_clr` `:pin`
Sets the specified pin output to LOW.
* `pin` `[integer!]` GPIO number, or one of RPI_GPIO_P1_*

#### `gpio_set_multi` `:mask`
Sets any of the first 32 GPIO output pins specified in the mask to HIGH.
* `mask` `[integer!]` Mask of pins to affect. Use eg: (1 << RPI_GPIO_P1_03) | (1 << RPI_GPIO_P1_05)

#### `gpio_clr_multi` `:mask`
Sets any of the first 32 GPIO output pins specified in the mask to LOW.
* `mask` `[integer!]` Mask of pins to affect. Use eg: (1 << RPI_GPIO_P1_03) | (1 << RPI_GPIO_P1_05)

#### `gpio_lev` `:pin`
Reads the current level on the specified pin and returns either HIGH or LOW. Works whether or not the pin is an input or an output.
* `pin` `[integer!]` GPIO number, or one of RPI_GPIO_P1_*

#### `gpio_eds` `:pin`
Event Detect Status. Tests whether the specified pin has detected a level or edge as requested by gpio_ren, gpio_fen, gpio_hen, gpio_len, gpio_aren, gpio_afen. Clear the flag for a given pin by calling gpio_set_eds
* `pin` `[integer!]` GPIO number, or one of RPI_GPIO_P1_*

#### `gpio_eds_multi` `:mask`
Same as gpio_eds but checks if any of the pins specified in the mask have detected a level or edge.
* `mask` `[integer!]` Mask of pins to affect. Use eg: (1 << RPI_GPIO_P1_03) | (1 << RPI_GPIO_P1_05)

#### `gpio_set_eds` `:pin`
Sets the Event Detect Status register for a given pin to 1, which has the effect of clearing the flag. Use this afer seeing an Event Detect Status on the pin.
* `pin` `[integer!]` GPIO number, or one of RPI_GPIO_P1_*

#### `gpio_set_eds_multi` `:mask`
Same as bcm2835_gpio_set_eds() but clears the flag for any pin which is set in the mask.
* `mask` `[integer!]` Mask of pins to affect. Use eg: (1 << RPI_GPIO_P1_03) | (1 << RPI_GPIO_P1_05)

#### `gpio_ren` `:pin`
Enable Rising Edge Detect Enable for the specified pin. When a rising edge is detected, sets the appropriate pin in Event Detect Status.
* `pin` `[integer!]` GPIO number, or one of RPI_GPIO_P1_*

#### `gpio_clr_ren` `:pin`
Disable Rising Edge Detect Enable for the specified pin.
* `pin` `[integer!]` GPIO number, or one of RPI_GPIO_P1_*

#### `gpio_fen` `:pin`
Enable Falling Edge Detect Enable for the specified pin. When a falling edge is detected, sets the appropriate pin in Event Detect Status.
* `pin` `[integer!]` GPIO number, or one of RPI_GPIO_P1_*

#### `gpio_clr_fen` `:pin`
Disable Falling Edge Detect Enable for the specified pin.
* `pin` `[integer!]` GPIO number, or one of RPI_GPIO_P1_*

#### `gpio_hen` `:pin`
Enable High Detect Enable for the specified pin. When a HIGH level is detected on the pin, sets the appropriate pin in Event Detect Status.
* `pin` `[integer!]` GPIO number, or one of RPI_GPIO_P1_*

#### `gpio_clr_hen` `:pin`
Disable High Edge Detect Enable for the specified pin.
* `pin` `[integer!]` GPIO number, or one of RPI_GPIO_P1_*

#### `gpio_len` `:pin`
Enable Low Detect Enable for the specified pin. When a LOW level is detected on the pin, sets the appropriate pin in Event Detect Status.
* `pin` `[integer!]` GPIO number, or one of RPI_GPIO_P1_*

#### `gpio_clr_len` `:pin`
Disable Low Edge Detect Enable for the specified pin.
* `pin` `[integer!]` GPIO number, or one of RPI_GPIO_P1_*

#### `gpio_aren` `:pin`
Enable Asynchronous Rising Edge Detect Enable for the specified pin. When a rising edge is detected, sets the appropriate pin in Event Detect Status.
* `pin` `[integer!]` GPIO number, or one of RPI_GPIO_P1_*

#### `gpio_clr_aren` `:pin`
Disable Asynchronous Rising Edge Detect Enable for the specified pin.
* `pin` `[integer!]` GPIO number, or one of RPI_GPIO_P1_*

#### `gpio_afen` `:pin`
Enable Asynchronous Falling Edge Detect Enable for the specified pin. When a falling edge is detected, sets the appropriate pin in Event Detect Status.
* `pin` `[integer!]` GPIO number, or one of RPI_GPIO_P1_*

#### `gpio_clr_afen` `:pin`
Disable Asynchronous Falling Edge Detect Enable for the specified pin.
* `pin` `[integer!]` GPIO number, or one of RPI_GPIO_P1_*

#### `gpio_pud` `:pud`
Sets the Pull-up/down register for the given pin. This is used with gpio_pudclk to set the Pull-up/down resistor for the given pin.
* `pud` `[integer!]` The desired Pull-up/down mode. One of GPIO_PUD_*

#### `gpio_pudclk` `:pin` `:on`
Clocks the Pull-up/down value set earlier by gpio_pud into the pin.
* `pin` `[integer!]` GPIO number, or one of RPI_GPIO_P1_*
* `on` `[integer!]` HIGH to clock the value from gpio_pud into the pin.

#### `gpio_pad` `:group`
Reads and returns the Pad Control for the given GPIO group. Caution: requires root access.
* `group` `[integer!]` The GPIO pad group number, one of PAD_GROUP_GPIO_*

#### `gpio_set_pad` `:group` `:control`
Sets the Pad Control for the given GPIO group. Caution: requires root access.
* `group` `[integer!]` The GPIO pad group number, one of PAD_GROUP_GPIO_*
* `control` `[integer!]` Mask of bits from BCM2835_PAD_*

#### `gpio_write` `:pin` `:on`
Sets the output state of the specified pin.
* `pin` `[integer!]` GPIO number, or one of RPI_GPIO_P1_*
* `on` `[integer!]` HIGH sets the output to HIGH and LOW to LOW.

#### `gpio_write_multi` `:mask` `:on`
Sets any of the first 32 GPIO output pins specified in the mask to the state given by on.
* `mask` `[integer!]` Mask of pins to affect. Use eg: (1 << RPI_GPIO_P1_03) | (1 << RPI_GPIO_P1_05)
* `on` `[integer!]` HIGH sets the output to HIGH and LOW to LOW.

#### `gpio_write_mask` `:value` `:mask`
Sets the first 32 GPIO output pins specified in the mask to the value given by value.
* `value` `[integer!]` Values required for each bit masked in by mask.
* `mask` `[integer!]` Mask of pins to affect. Use eg: (1 << RPI_GPIO_P1_03) | (1 << RPI_GPIO_P1_05)

#### `gpio_set_pud` `:pin` `:pud`
Sets the Pull-up/down mode for the specified pin. This is more convenient than clocking the mode in with gpio_pud and gpio_pudclk.
* `pin` `[integer!]` GPIO number, or one of RPI_GPIO_P1_*
* `pud` `[integer!]` The desired Pull-up/down mode. One of GPIO_PUD_*

#### `gpio_get_pud` `:pin`
On the BCM2711 based RPI 4, gets the current Pull-up/down mode for the specified pin.
* `pin` `[integer!]` GPIO number, or one of RPI_GPIO_P1_*

#### `gpio_reset`
Sets all pins to GPIO_PUD_OFF and GPIO_FSEL_INPT

#### `spi_begin`
Start SPI operations.

#### `spi_end`
End SPI operations.

#### `spi_setBitOrder` `:order`
Set the bit order to be used for transmit and receive. The bcm2835 SPI0 only supports SPI_BIT_ORDER_MSB, so if you select SPI_BIT_ORDER_LSB, the bytes will be reversed in software.
* `order` `[integer!]` The desired bit order, one of SPI_BIT_ORDER_*

#### `spi_setClockDivider` `:divider`
Sets the SPI clock divider and therefore the SPI clock speed.
* `divider` `[integer!]` The desired SPI clock divider, one of SPI_CLOCK_DIVIDER_*

#### `spi_set_speed_hz` `:speed_hz`
Sets the SPI clock divider by converting the speed parameter to the equivalent SPI clock divider.
* `speed_hz` `[integer!]` The desired SPI clock speed in Hz

#### `spi_setDataMode` `:mode`
Sets the clock polariy and phase.
* `mode` `[integer!]` The desired data mode, one of SPI_MODE*

#### `spi_chipSelect` `:cs`
Sets the chip select pin(s). When an spi_transfer is made, the selected pin(s) will be asserted during the transfer.
* `cs` `[integer!]` Specifies the CS pins(s) that are used to activate the desired slave. One of SPI_CS*

#### `spi_setChipSelectPolarity` `:cs` `:active`
Sets the chip select pin polarity for a given pin. When an spi_transfer occurs, the currently selected chip select pin(s) will be asserted to the value given by active. When transfers are not happening, the chip select pin(s) return to the complement (inactive) value.
* `cs` `[integer!]` Specifies the CS pins(s) that are used to activate the desired slave. One of SPI_CS*
* `active` `[integer!]` Whether the chip select pin is to be active HIGH.

#### `spi_transfer` `:value`
Transfers one byte to and from the currently selected SPI slave. Asserts the currently selected CS pins (as previously set by bcm2835_spi_chipSelect) during the transfer. Clocks the 8 bit value out on MOSI, and simultaneously clocks in data from MISO. Returns the read data byte from the slave.
* `value` `[integer! char! binary!]` The 8 bit data byte to write to MOSI, or buffer

#### `spi_write` `:data`
Transfers any number of bytes to the currently selected SPI slave.
* `data` `[binary! integer! char!]` Buffer of bytes to send or the 8 bit data byte to write to MOSI

#### `version`
Returns the bcm2835 version.

#### `set_debug` `:state`
Prevents access to the kernel memory, and does not do any peripheral access. Instead it prints out what it _would_ do if debug were 0.
* `state` `[logic! integer!]`

#### `delay` `:millis`
Delays for the specified number of milliseconds.
* `millis` `[integer!]` Delay in milliseconds

#### `delayMicroseconds` `:micros`
Delays for the specified number of microseconds
* `micros` `[integer!]` Delay in microseconds


