REBOL [
	title: "bcm2835 module builder"
	type: module
]

cmd-words: []
arg-words: [
	;@@ order of these is important!
]

commands: [
	; init-words is internal extension initialization (for mapping Rebol words to local equivalents)
	init-words: [cmd-words [block!] arg-words [block!]]

	;-----------------------------------------------------------------------------------------------
	;- GPIO register access                                                                         
    ;-   These functions allow you to control the GPIO interface. You can set the                   
    ;-   function of each GPIO pin, read the input state and set the output                         
	;-----------------------------------------------------------------------------------------------

	gpio_fsel: [
		{Sets the Function Select register for the given pin, which configures the pin as Input, Output or one of the 6 alternate functions.}
		pin  [integer!] "GPIO number, or one of RPI_GPIO_P1_*"
		mode [integer!] "Mode to set the pin to, one of GPIO_FSEL_*"
	]
	gpio_set: [
		"Sets the specified pin output to HIGH."
		pin  [integer!] "GPIO number, or one of RPI_GPIO_P1_*"
	]
	gpio_clr: [
		"Sets the specified pin output to LOW."
		pin  [integer!] "GPIO number, or one of RPI_GPIO_P1_*"
	]
	gpio_set_multi: [
		"Sets any of the first 32 GPIO output pins specified in the mask to HIGH."
		mask [integer!] "Mask of pins to affect. Use eg: (1 << RPI_GPIO_P1_03) | (1 << RPI_GPIO_P1_05)"
	]
	gpio_clr_multi: [
		"Sets any of the first 32 GPIO output pins specified in the mask to LOW."
		mask [integer!] "Mask of pins to affect. Use eg: (1 << RPI_GPIO_P1_03) | (1 << RPI_GPIO_P1_05)"
	]
	gpio_lev: [
		"Reads the current level on the specified pin and returns either HIGH or LOW. Works whether or not the pin is an input or an output."
		pin  [integer!] "GPIO number, or one of RPI_GPIO_P1_*"
	]
	gpio_eds: [
		{Event Detect Status. Tests whether the specified pin has detected a level or edge as requested by gpio_ren, gpio_fen, gpio_hen, gpio_len, gpio_aren, gpio_afen. Clear the flag for a given pin by calling gpio_set_eds}
		pin  [integer!] "GPIO number, or one of RPI_GPIO_P1_*"
	]
	gpio_eds_multi: [
		{Same as gpio_eds but checks if any of the pins specified in the mask have detected a level or edge.}
		mask [integer!] "Mask of pins to affect. Use eg: (1 << RPI_GPIO_P1_03) | (1 << RPI_GPIO_P1_05)"
	]
	gpio_set_eds: [
		{Sets the Event Detect Status register for a given pin to 1, which has the effect of clearing the flag. Use this afer seeing an Event Detect Status on the pin.}
		pin  [integer!] "GPIO number, or one of RPI_GPIO_P1_*"
	]
	gpio_set_eds_multi: [
		{Same as bcm2835_gpio_set_eds() but clears the flag for any pin which is set in the mask.}
		mask [integer!] "Mask of pins to affect. Use eg: (1 << RPI_GPIO_P1_03) | (1 << RPI_GPIO_P1_05)"
	]
	gpio_ren: [
		"Enable Rising Edge Detect Enable for the specified pin. When a rising edge is detected, sets the appropriate pin in Event Detect Status."
		pin  [integer!] "GPIO number, or one of RPI_GPIO_P1_*"
	]
	gpio_clr_ren: [
		"Disable Rising Edge Detect Enable for the specified pin."
		pin  [integer!] "GPIO number, or one of RPI_GPIO_P1_*"
	]
	gpio_fen: [
		"Enable Falling Edge Detect Enable for the specified pin. When a falling edge is detected, sets the appropriate pin in Event Detect Status."
		pin  [integer!] "GPIO number, or one of RPI_GPIO_P1_*"
	]
	gpio_clr_fen: [
		"Disable Falling Edge Detect Enable for the specified pin."
		pin  [integer!] "GPIO number, or one of RPI_GPIO_P1_*"
	]
	gpio_hen: [
		"Enable High Detect Enable for the specified pin. When a HIGH level is detected on the pin, sets the appropriate pin in Event Detect Status."
		pin  [integer!] "GPIO number, or one of RPI_GPIO_P1_*"
	]
	gpio_clr_hen: [
		"Disable High Edge Detect Enable for the specified pin."
		pin  [integer!] "GPIO number, or one of RPI_GPIO_P1_*"
	]
	gpio_len: [
		"Enable Low Detect Enable for the specified pin. When a LOW level is detected on the pin, sets the appropriate pin in Event Detect Status."
		pin  [integer!] "GPIO number, or one of RPI_GPIO_P1_*"
	]
	gpio_clr_len: [
		"Disable Low Edge Detect Enable for the specified pin."
		pin  [integer!] "GPIO number, or one of RPI_GPIO_P1_*"
	]

	gpio_aren: [
		"Enable Asynchronous Rising Edge Detect Enable for the specified pin. When a rising edge is detected, sets the appropriate pin in Event Detect Status."
		pin  [integer!] "GPIO number, or one of RPI_GPIO_P1_*"
	]
	gpio_clr_aren: [
		"Disable Asynchronous Rising Edge Detect Enable for the specified pin."
		pin  [integer!] "GPIO number, or one of RPI_GPIO_P1_*"
	]
	gpio_afen: [
		"Enable Asynchronous Falling Edge Detect Enable for the specified pin. When a falling edge is detected, sets the appropriate pin in Event Detect Status."
		pin  [integer!] "GPIO number, or one of RPI_GPIO_P1_*"
	]
	gpio_clr_afen: [
		"Disable Asynchronous Falling Edge Detect Enable for the specified pin."
		pin  [integer!] "GPIO number, or one of RPI_GPIO_P1_*"
	]

	gpio_pud: [
		"Sets the Pull-up/down register for the given pin. This is used with gpio_pudclk to set the Pull-up/down resistor for the given pin."
		pud  [integer!] "The desired Pull-up/down mode. One of GPIO_PUD_*"
	]
	gpio_pudclk: [
		"Clocks the Pull-up/down value set earlier by gpio_pud into the pin."
		pin  [integer!] "GPIO number, or one of RPI_GPIO_P1_*"
		on   [integer!] "HIGH to clock the value from gpio_pud into the pin."
	]

	gpio_pad: [
		"Reads and returns the Pad Control for the given GPIO group. Caution: requires root access."
		group [integer!] "The GPIO pad group number, one of PAD_GROUP_GPIO_*"
	]
	gpio_set_pad: [
		"Sets the Pad Control for the given GPIO group. Caution: requires root access."
		group [integer!] "The GPIO pad group number, one of PAD_GROUP_GPIO_*"
		control [integer!] "Mask of bits from BCM2835_PAD_*"
	]

	gpio_write: [
		"Sets the output state of the specified pin."
		pin  [integer!] "GPIO number, or one of RPI_GPIO_P1_*"
		on   [integer!] "HIGH sets the output to HIGH and LOW to LOW."
	]
	gpio_write_multi: [
		"Sets any of the first 32 GPIO output pins specified in the mask to the state given by on."
		mask [integer!] "Mask of pins to affect. Use eg: (1 << RPI_GPIO_P1_03) | (1 << RPI_GPIO_P1_05)"
		on   [integer!] "HIGH sets the output to HIGH and LOW to LOW."
	]
	gpio_write_mask: [
		"Sets the first 32 GPIO output pins specified in the mask to the value given by value."
		value [integer!] "Values required for each bit masked in by mask."
		mask [integer!] "Mask of pins to affect. Use eg: (1 << RPI_GPIO_P1_03) | (1 << RPI_GPIO_P1_05)"
	]

	gpio_set_pud: [
		"Sets the Pull-up/down mode for the specified pin. This is more convenient than clocking the mode in with gpio_pud and gpio_pudclk."
		pin  [integer!] "GPIO number, or one of RPI_GPIO_P1_*"
		pud  [integer!] "The desired Pull-up/down mode. One of GPIO_PUD_*"
	]
	gpio_get_pud: [
		"On the BCM2711 based RPI 4, gets the current Pull-up/down mode for the specified pin."
		pin  [integer!] "GPIO number, or one of RPI_GPIO_P1_*"
	]
	gpio_reset: [
		"Sets all pins to GPIO_PUD_OFF and GPIO_FSEL_INPT"
	]

	;-----------------------------------------------------------------------------------------------
	;- SPI access                                                                                   
    ;-   These functions let you use SPI0 (Serial Peripheral Interface) to                          
    ;-   interface with an external SPI device.                                                     
	;-----------------------------------------------------------------------------------------------

	spi_begin: ["Start SPI operations."]
	spi_end: ["End SPI operations."]
	spi_setBitOrder: [
		"Set the bit order to be used for transmit and receive. The bcm2835 SPI0 only supports SPI_BIT_ORDER_MSB, so if you select SPI_BIT_ORDER_LSB, the bytes will be reversed in software."
		order  [integer!] "The desired bit order, one of SPI_BIT_ORDER_*"
	]
	spi_setClockDivider: [
		"Sets the SPI clock divider and therefore the SPI clock speed."
		divider [integer!] "The desired SPI clock divider, one of SPI_CLOCK_DIVIDER_*"
	]
	spi_set_speed_hz: [
		"Sets the SPI clock divider by converting the speed parameter to the equivalent SPI clock divider."
		speed_hz [integer!] "The desired SPI clock speed in Hz"
	]
	spi_setDataMode: [
		"Sets the clock polariy and phase."
		mode [integer!] "The desired data mode, one of SPI_MODE*"
	]
	spi_chipSelect: [
		"Sets the chip select pin(s). When an spi_transfer is made, the selected pin(s) will be asserted during the transfer."
		cs [integer!] "Specifies the CS pins(s) that are used to activate the desired slave. One of SPI_CS*"
	]
	spi_setChipSelectPolarity: [
		"Sets the chip select pin polarity for a given pin. When an spi_transfer occurs, the currently selected chip select pin(s) will be asserted to the value given by active. When transfers are not happening, the chip select pin(s) return to the complement (inactive) value."
		cs [integer!] "Specifies the CS pins(s) that are used to activate the desired slave. One of SPI_CS*"
		active [integer!] "Whether the chip select pin is to be active HIGH."
	]
	spi_transfer: [
		"Transfers one byte to and from the currently selected SPI slave. Asserts the currently selected CS pins (as previously set by bcm2835_spi_chipSelect) during the transfer. Clocks the 8 bit value out on MOSI, and simultaneously clocks in data from MISO. Returns the read data byte from the slave."
		value [integer! char! binary!] "The 8 bit data byte to write to MOSI, or buffer"
	]
	spi_write: [
		"Transfers any number of bytes to the currently selected SPI slave."
		data [binary! integer! char!] "Buffer of bytes to send or the 8 bit data byte to write to MOSI"
	]

	;-----------------------------------------------------------------------------------------------
	;- Utilities                                                                                    
	;-----------------------------------------------------------------------------------------------
	version: ["Returns the bcm2835 version."]
	delay: [
		"Delays for the specified number of milliseconds."
		millis [integer!] "Delay in milliseconds"
	]
	delayMicroseconds: [
		"Delays for the specified number of microseconds"
		micros [integer!] "Delay in microseconds"
	]
]


header: {REBOL [Title: {Rebol OpenCV Extension} Type: module Exports: []]}
enum-commands:  "enum ext_commands {"
enum-cmd-words: "enum ext_cmd_words {W_BCM2835_CMD_0,"
enum-arg-words: "enum ext_arg_words {W_BCM2835_ARG_0,"
cmd-declares: ""
cmd-dispatch: ""
uname: none

foreach word cmd-words [
	word: uppercase form word
	replace/all word #"-" #"_"
	append enum-cmd-words ajoin ["^/^-W_BCM2835_CMD_" word #","]
]
foreach word arg-words [
	word: uppercase form word
	replace/all word #"-" #"_"
	append enum-arg-words ajoin ["^/^-W_BCM2835_ARG_" word #","]
]

foreach [name spec] commands [
	append header ajoin [lf name ": command "]
	new-line/all spec false
	append/only header mold spec

	name: form name
	replace/all name #"-" #"_"
	uname: uppercase copy name
	
	append enum-commands ajoin ["^/^-CMD_BCM2835_" uname #","]

	append cmd-declares ajoin ["^/int cmd_" name "(RXIFRM *frm, void *ctx);"]
	append cmd-dispatch ajoin ["^-cmd_" name ",^/"]
]

new-line/all cmd-words false
new-line/all arg-words false
append header rejoin [{^/init-words words: } mold cmd-words #" " mold arg-words]
append header {^/protect/hide 'init-words}
append header {
;; RPiGPIOPin:
RPI_GPIO_P1_03:   0  ;; Version 1, Pin P1-03
RPI_GPIO_P1_05:   1  ;; Version 1, Pin P1-05
RPI_GPIO_P1_07:   4  ;; Version 1, Pin P1-07
RPI_GPIO_P1_08:  14  ;; Version 1, Pin P1-08, defaults to alt function 0 UART0_TXD
RPI_GPIO_P1_10:  15  ;; Version 1, Pin P1-10, defaults to alt function 0 UART0_RXD
RPI_GPIO_P1_11:  17  ;; Version 1, Pin P1-11
RPI_GPIO_P1_12:  18  ;; Version 1, Pin P1-12, can be PWM channel 0 in ALT FUN 5
RPI_GPIO_P1_13:  21  ;; Version 1, Pin P1-13
RPI_GPIO_P1_15:  22  ;; Version 1, Pin P1-15
RPI_GPIO_P1_16:  23  ;; Version 1, Pin P1-16
RPI_GPIO_P1_18:  24  ;; Version 1, Pin P1-18
RPI_GPIO_P1_19:  10  ;; Version 1, Pin P1-19, MOSI when SPI0 in use
RPI_GPIO_P1_21:   9  ;; Version 1, Pin P1-21, MISO when SPI0 in use
RPI_GPIO_P1_22:  25  ;; Version 1, Pin P1-22
RPI_GPIO_P1_23:  11  ;; Version 1, Pin P1-23, CLK when SPI0 in use
RPI_GPIO_P1_24:   8  ;; Version 1, Pin P1-24, CE0 when SPI0 in use
RPI_GPIO_P1_26:   7  ;; Version 1, Pin P1-26, CE1 when SPI0 in use

;; RPi Version 2
RPI_V2_GPIO_P1_03:   2  ;; Version 2, Pin P1-03
RPI_V2_GPIO_P1_05:   3  ;; Version 2, Pin P1-05
RPI_V2_GPIO_P1_07:   4  ;; Version 2, Pin P1-07
RPI_V2_GPIO_P1_08:  14  ;; Version 2, Pin P1-08, defaults to alt function 0 UART0_TXD
RPI_V2_GPIO_P1_10:  15  ;; Version 2, Pin P1-10, defaults to alt function 0 UART0_RXD
RPI_V2_GPIO_P1_11:  17  ;; Version 2, Pin P1-11
RPI_V2_GPIO_P1_12:  18  ;; Version 2, Pin P1-12, can be PWM channel 0 in ALT FUN 5
RPI_V2_GPIO_P1_13:  27  ;; Version 2, Pin P1-13
RPI_V2_GPIO_P1_15:  22  ;; Version 2, Pin P1-15
RPI_V2_GPIO_P1_16:  23  ;; Version 2, Pin P1-16
RPI_V2_GPIO_P1_18:  24  ;; Version 2, Pin P1-18
RPI_V2_GPIO_P1_19:  10  ;; Version 2, Pin P1-19, MOSI when SPI0 in use
RPI_V2_GPIO_P1_21:   9  ;; Version 2, Pin P1-21, MISO when SPI0 in use
RPI_V2_GPIO_P1_22:  25  ;; Version 2, Pin P1-22
RPI_V2_GPIO_P1_23:  11  ;; Version 2, Pin P1-23, CLK when SPI0 in use
RPI_V2_GPIO_P1_24:   8  ;; Version 2, Pin P1-24, CE0 when SPI0 in use
RPI_V2_GPIO_P1_26:   7  ;; Version 2, Pin P1-26, CE1 when SPI0 in use
RPI_V2_GPIO_P1_29:   5  ;; Version 2, Pin P1-29
RPI_V2_GPIO_P1_31:   6  ;; Version 2, Pin P1-31
RPI_V2_GPIO_P1_32:  12  ;; Version 2, Pin P1-32
RPI_V2_GPIO_P1_33:  13  ;; Version 2, Pin P1-33
RPI_V2_GPIO_P1_35:  19  ;; Version 2, Pin P1-35, can be PWM channel 1 in ALT FUN 5 
RPI_V2_GPIO_P1_36:  16  ;; Version 2, Pin P1-36
RPI_V2_GPIO_P1_37:  26  ;; Version 2, Pin P1-37
RPI_V2_GPIO_P1_38:  20  ;; Version 2, Pin P1-38
RPI_V2_GPIO_P1_40:  21  ;; Version 2, Pin P1-40

;; RPi Version 2, new plug P5
RPI_V2_GPIO_P5_03:  28  ;; Version 2, Pin P5-03
RPI_V2_GPIO_P5_04:  29  ;; Version 2, Pin P5-04
RPI_V2_GPIO_P5_05:  30  ;; Version 2, Pin P5-05
RPI_V2_GPIO_P5_06:  31  ;; Version 2, Pin P5-06

;; RPi B+ J8 header, also RPi 2 40 pin GPIO header
RPI_BPLUS_GPIO_J8_03:   2  ;; B+, Pin J8-03
RPI_BPLUS_GPIO_J8_05:   3  ;; B+, Pin J8-05
RPI_BPLUS_GPIO_J8_07:   4  ;; B+, Pin J8-07
RPI_BPLUS_GPIO_J8_08:  14  ;; B+, Pin J8-08, defaults to alt function 0 UART0_TXD
RPI_BPLUS_GPIO_J8_10:  15  ;; B+, Pin J8-10, defaults to alt function 0 UART0_RXD
RPI_BPLUS_GPIO_J8_11:  17  ;; B+, Pin J8-11
RPI_BPLUS_GPIO_J8_12:  18  ;; B+, Pin J8-12, can be PWM channel 0 in ALT FUN 5
RPI_BPLUS_GPIO_J8_13:  27  ;; B+, Pin J8-13
RPI_BPLUS_GPIO_J8_15:  22  ;; B+, Pin J8-15
RPI_BPLUS_GPIO_J8_16:  23  ;; B+, Pin J8-16
RPI_BPLUS_GPIO_J8_18:  24  ;; B+, Pin J8-18
RPI_BPLUS_GPIO_J8_19:  10  ;; B+, Pin J8-19, MOSI when SPI0 in use
RPI_BPLUS_GPIO_J8_21:   9  ;; B+, Pin J8-21, MISO when SPI0 in use
RPI_BPLUS_GPIO_J8_22:  25  ;; B+, Pin J8-22
RPI_BPLUS_GPIO_J8_23:  11  ;; B+, Pin J8-23, CLK when SPI0 in use
RPI_BPLUS_GPIO_J8_24:   8  ;; B+, Pin J8-24, CE0 when SPI0 in use
RPI_BPLUS_GPIO_J8_26:   7  ;; B+, Pin J8-26, CE1 when SPI0 in use
RPI_BPLUS_GPIO_J8_29:   5  ;; B+, Pin J8-29
RPI_BPLUS_GPIO_J8_31:   6  ;; B+, Pin J8-31
RPI_BPLUS_GPIO_J8_32:  12  ;; B+, Pin J8-32
RPI_BPLUS_GPIO_J8_33:  13  ;; B+, Pin J8-33
RPI_BPLUS_GPIO_J8_35:  19  ;; B+, Pin J8-35, can be PWM channel 1 in ALT FUN 5
RPI_BPLUS_GPIO_J8_36:  16  ;; B+, Pin J8-36 
RPI_BPLUS_GPIO_J8_37:  26  ;; B+, Pin J8-37 
RPI_BPLUS_GPIO_J8_38:  20  ;; B+, Pin J8-38 
RPI_BPLUS_GPIO_J8_40:  21  ;; B+, Pin J8-40 

;; bcm2835FunctionSelect:
GPIO_FSEL_INPT:  0   ;; Input  0b000
GPIO_FSEL_OUTP:  1   ;; Output 0b001
GPIO_FSEL_ALT0:  4   ;; Alternate function 0 0b100
GPIO_FSEL_ALT1:  5   ;; Alternate function 1 0b101
GPIO_FSEL_ALT2:  6   ;; Alternate function 2 0b110
GPIO_FSEL_ALT3:  7   ;; Alternate function 3 0b111
GPIO_FSEL_ALT4:  3   ;; Alternate function 4 0b011
GPIO_FSEL_ALT5:  2   ;; Alternate function 5 0b010
GPIO_FSEL_MASK:  7   ;; Function select bits mask 0b111

;; bcm2835PUDControl:
GPIO_PUD_OFF:    0   ;; Off ? disable pull-up/down 0b00
GPIO_PUD_DOWN:   1   ;; Enable Pull Down control 0b01
GPIO_PUD_UP:     2   ;; Enable Pull Up control 0b10

;; bcm2835PadGroup:
PAD_GROUP_GPIO_0_27:  0  ;; Pad group for GPIO pads  0 to 27
PAD_GROUP_GPIO_28_45: 1  ;; Pad group for GPIO pads 28 to 45
PAD_GROUP_GPIO_46_53: 2  ;; Pad group for GPIO pads 46 to 53

;; bcm2835SPIBitOrder:
SPI_BIT_ORDER_LSBFIRST: 0 ;; LSB First
SPI_BIT_ORDER_MSBFIRST: 1 ;; MSB First

;; bcm2835SPIMode:
SPI_MODE0: 0  ;; CPOL = 0, CPHA = 0
SPI_MODE1: 1  ;; CPOL = 0, CPHA = 1
SPI_MODE2: 2  ;; CPOL = 1, CPHA = 0
SPI_MODE3: 3  ;; CPOL = 1, CPHA = 1

;; bcm2835SPIChipSelect:
SPI_CS0:     0  ;; Chip Select 0
SPI_CS1:     1  ;; Chip Select 1
SPI_CS2:     2  ;; Chip Select 2 (ie pins CS1 and CS2 are asserted)
SPI_CS_NONE: 3  ;; No CS, control it yourself
}

;print header

out: make string! 2000
append out reword {//
// auto-generated file, do not modify!
//

#include "common.h"

#define MIN_REBOL_VER 3
#define MIN_REBOL_REV 5
#define MIN_REBOL_UPD 4
#define VERSION(a, b, c) (a << 16) + (b << 8) + c
#define MIN_REBOL_VERSION VERSION(MIN_REBOL_VER, MIN_REBOL_REV, MIN_REBOL_UPD)

$enum-commands
^};
$enum-cmd-words
^};
$enum-arg-words
^};

$cmd-declares

typedef int (*MyCommandPointer)(RXIFRM *frm, void *ctx);

#define BCM2835_EXT_INIT_CODE \} self


foreach line split header lf [
	replace/all line #"^"" {\"}
	append out ajoin [{^/^-"} line {\n"\}] 
]
append out "^/"


;print out

write %bcm2835-rebol-extension.h out

write %bcm2835-commands-table.c reword {//
// auto-generated file, do not modify!
//
#include "bcm2835-rebol-extension.h"
MyCommandPointer Command[] = {
$cmd-dispatch};
} self


