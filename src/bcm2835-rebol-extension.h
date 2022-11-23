//
// auto-generated file, do not modify!
//

#include "common.h"

#define MIN_REBOL_VER 3
#define MIN_REBOL_REV 5
#define MIN_REBOL_UPD 4
#define VERSION(a, b, c) (a << 16) + (b << 8) + c
#define MIN_REBOL_VERSION VERSION(MIN_REBOL_VER, MIN_REBOL_REV, MIN_REBOL_UPD)

enum ext_commands {
	CMD_BCM2835_INIT_WORDS,
	CMD_BCM2835_GPIO_FSEL,
	CMD_BCM2835_GPIO_SET,
	CMD_BCM2835_GPIO_CLR,
	CMD_BCM2835_GPIO_SET_MULTI,
	CMD_BCM2835_GPIO_CLR_MULTI,
	CMD_BCM2835_GPIO_LEV,
	CMD_BCM2835_GPIO_EDS,
	CMD_BCM2835_GPIO_EDS_MULTI,
	CMD_BCM2835_GPIO_SET_EDS,
	CMD_BCM2835_GPIO_SET_EDS_MULTI,
	CMD_BCM2835_GPIO_REN,
	CMD_BCM2835_GPIO_CLR_REN,
	CMD_BCM2835_GPIO_FEN,
	CMD_BCM2835_GPIO_CLR_FEN,
	CMD_BCM2835_GPIO_HEN,
	CMD_BCM2835_GPIO_CLR_HEN,
	CMD_BCM2835_GPIO_LEN,
	CMD_BCM2835_GPIO_CLR_LEN,
	CMD_BCM2835_GPIO_AREN,
	CMD_BCM2835_GPIO_CLR_AREN,
	CMD_BCM2835_GPIO_AFEN,
	CMD_BCM2835_GPIO_CLR_AFEN,
	CMD_BCM2835_GPIO_PUD,
	CMD_BCM2835_GPIO_PUDCLK,
	CMD_BCM2835_GPIO_PAD,
	CMD_BCM2835_GPIO_SET_PAD,
	CMD_BCM2835_GPIO_WRITE,
	CMD_BCM2835_GPIO_WRITE_MULTI,
	CMD_BCM2835_GPIO_WRITE_MASK,
	CMD_BCM2835_GPIO_SET_PUD,
	CMD_BCM2835_GPIO_GET_PUD,
	CMD_BCM2835_GPIO_RESET,
	CMD_BCM2835_SPI_BEGIN,
	CMD_BCM2835_SPI_END,
	CMD_BCM2835_SPI_SETBITORDER,
	CMD_BCM2835_SPI_SETCLOCKDIVIDER,
	CMD_BCM2835_SPI_SET_SPEED_HZ,
	CMD_BCM2835_SPI_SETDATAMODE,
	CMD_BCM2835_SPI_CHIPSELECT,
	CMD_BCM2835_SPI_SETCHIPSELECTPOLARITY,
	CMD_BCM2835_SPI_TRANSFER,
	CMD_BCM2835_SPI_WRITE,
	CMD_BCM2835_VERSION,
	CMD_BCM2835_DELAY,
	CMD_BCM2835_DELAYMICROSECONDS,
};
enum ext_cmd_words {W_BCM2835_CMD_0,
};
enum ext_arg_words {W_BCM2835_ARG_0,
};


int cmd_init_words(RXIFRM *frm, void *ctx);
int cmd_gpio_fsel(RXIFRM *frm, void *ctx);
int cmd_gpio_set(RXIFRM *frm, void *ctx);
int cmd_gpio_clr(RXIFRM *frm, void *ctx);
int cmd_gpio_set_multi(RXIFRM *frm, void *ctx);
int cmd_gpio_clr_multi(RXIFRM *frm, void *ctx);
int cmd_gpio_lev(RXIFRM *frm, void *ctx);
int cmd_gpio_eds(RXIFRM *frm, void *ctx);
int cmd_gpio_eds_multi(RXIFRM *frm, void *ctx);
int cmd_gpio_set_eds(RXIFRM *frm, void *ctx);
int cmd_gpio_set_eds_multi(RXIFRM *frm, void *ctx);
int cmd_gpio_ren(RXIFRM *frm, void *ctx);
int cmd_gpio_clr_ren(RXIFRM *frm, void *ctx);
int cmd_gpio_fen(RXIFRM *frm, void *ctx);
int cmd_gpio_clr_fen(RXIFRM *frm, void *ctx);
int cmd_gpio_hen(RXIFRM *frm, void *ctx);
int cmd_gpio_clr_hen(RXIFRM *frm, void *ctx);
int cmd_gpio_len(RXIFRM *frm, void *ctx);
int cmd_gpio_clr_len(RXIFRM *frm, void *ctx);
int cmd_gpio_aren(RXIFRM *frm, void *ctx);
int cmd_gpio_clr_aren(RXIFRM *frm, void *ctx);
int cmd_gpio_afen(RXIFRM *frm, void *ctx);
int cmd_gpio_clr_afen(RXIFRM *frm, void *ctx);
int cmd_gpio_pud(RXIFRM *frm, void *ctx);
int cmd_gpio_pudclk(RXIFRM *frm, void *ctx);
int cmd_gpio_pad(RXIFRM *frm, void *ctx);
int cmd_gpio_set_pad(RXIFRM *frm, void *ctx);
int cmd_gpio_write(RXIFRM *frm, void *ctx);
int cmd_gpio_write_multi(RXIFRM *frm, void *ctx);
int cmd_gpio_write_mask(RXIFRM *frm, void *ctx);
int cmd_gpio_set_pud(RXIFRM *frm, void *ctx);
int cmd_gpio_get_pud(RXIFRM *frm, void *ctx);
int cmd_gpio_reset(RXIFRM *frm, void *ctx);
int cmd_spi_begin(RXIFRM *frm, void *ctx);
int cmd_spi_end(RXIFRM *frm, void *ctx);
int cmd_spi_setBitOrder(RXIFRM *frm, void *ctx);
int cmd_spi_setClockDivider(RXIFRM *frm, void *ctx);
int cmd_spi_set_speed_hz(RXIFRM *frm, void *ctx);
int cmd_spi_setDataMode(RXIFRM *frm, void *ctx);
int cmd_spi_chipSelect(RXIFRM *frm, void *ctx);
int cmd_spi_setChipSelectPolarity(RXIFRM *frm, void *ctx);
int cmd_spi_transfer(RXIFRM *frm, void *ctx);
int cmd_spi_write(RXIFRM *frm, void *ctx);
int cmd_version(RXIFRM *frm, void *ctx);
int cmd_delay(RXIFRM *frm, void *ctx);
int cmd_delayMicroseconds(RXIFRM *frm, void *ctx);

typedef int (*MyCommandPointer)(RXIFRM *frm, void *ctx);

#define BCM2835_EXT_INIT_CODE \
	"REBOL [Title: {Rebol OpenCV Extension} Type: module Exports: []]\n"\
	"init-words: command [cmd-words [block!] arg-words [block!]]\n"\
	"gpio_fsel: command [{Sets the Function Select register for the given pin, which configures the pin as Input, Output or one of the 6 alternate functions.} pin [integer!] \"GPIO number, or one of RPI_GPIO_P1_*\" mode [integer!] \"Mode to set the pin to, one of GPIO_FSEL_*\"]\n"\
	"gpio_set: command [\"Sets the specified pin output to HIGH.\" pin [integer!] \"GPIO number, or one of RPI_GPIO_P1_*\"]\n"\
	"gpio_clr: command [\"Sets the specified pin output to LOW.\" pin [integer!] \"GPIO number, or one of RPI_GPIO_P1_*\"]\n"\
	"gpio_set_multi: command [{Sets any of the first 32 GPIO output pins specified in the mask to HIGH.} mask [integer!] {Mask of pins to affect. Use eg: (1 << RPI_GPIO_P1_03) | (1 << RPI_GPIO_P1_05)}]\n"\
	"gpio_clr_multi: command [{Sets any of the first 32 GPIO output pins specified in the mask to LOW.} mask [integer!] {Mask of pins to affect. Use eg: (1 << RPI_GPIO_P1_03) | (1 << RPI_GPIO_P1_05)}]\n"\
	"gpio_lev: command [{Reads the current level on the specified pin and returns either HIGH or LOW. Works whether or not the pin is an input or an output.} pin [integer!] \"GPIO number, or one of RPI_GPIO_P1_*\"]\n"\
	"gpio_eds: command [{Event Detect Status. Tests whether the specified pin has detected a level or edge as requested by gpio_ren, gpio_fen, gpio_hen, gpio_len, gpio_aren, gpio_afen. Clear the flag for a given pin by calling gpio_set_eds} pin [integer!] \"GPIO number, or one of RPI_GPIO_P1_*\"]\n"\
	"gpio_eds_multi: command [{Same as gpio_eds but checks if any of the pins specified in the mask have detected a level or edge.} mask [integer!] {Mask of pins to affect. Use eg: (1 << RPI_GPIO_P1_03) | (1 << RPI_GPIO_P1_05)}]\n"\
	"gpio_set_eds: command [{Sets the Event Detect Status register for a given pin to 1, which has the effect of clearing the flag. Use this afer seeing an Event Detect Status on the pin.} pin [integer!] \"GPIO number, or one of RPI_GPIO_P1_*\"]\n"\
	"gpio_set_eds_multi: command [{Same as bcm2835_gpio_set_eds() but clears the flag for any pin which is set in the mask.} mask [integer!] {Mask of pins to affect. Use eg: (1 << RPI_GPIO_P1_03) | (1 << RPI_GPIO_P1_05)}]\n"\
	"gpio_ren: command [{Enable Rising Edge Detect Enable for the specified pin. When a rising edge is detected, sets the appropriate pin in Event Detect Status.} pin [integer!] \"GPIO number, or one of RPI_GPIO_P1_*\"]\n"\
	"gpio_clr_ren: command [{Disable Rising Edge Detect Enable for the specified pin.} pin [integer!] \"GPIO number, or one of RPI_GPIO_P1_*\"]\n"\
	"gpio_fen: command [{Enable Falling Edge Detect Enable for the specified pin. When a falling edge is detected, sets the appropriate pin in Event Detect Status.} pin [integer!] \"GPIO number, or one of RPI_GPIO_P1_*\"]\n"\
	"gpio_clr_fen: command [{Disable Falling Edge Detect Enable for the specified pin.} pin [integer!] \"GPIO number, or one of RPI_GPIO_P1_*\"]\n"\
	"gpio_hen: command [{Enable High Detect Enable for the specified pin. When a HIGH level is detected on the pin, sets the appropriate pin in Event Detect Status.} pin [integer!] \"GPIO number, or one of RPI_GPIO_P1_*\"]\n"\
	"gpio_clr_hen: command [{Disable High Edge Detect Enable for the specified pin.} pin [integer!] \"GPIO number, or one of RPI_GPIO_P1_*\"]\n"\
	"gpio_len: command [{Enable Low Detect Enable for the specified pin. When a LOW level is detected on the pin, sets the appropriate pin in Event Detect Status.} pin [integer!] \"GPIO number, or one of RPI_GPIO_P1_*\"]\n"\
	"gpio_clr_len: command [{Disable Low Edge Detect Enable for the specified pin.} pin [integer!] \"GPIO number, or one of RPI_GPIO_P1_*\"]\n"\
	"gpio_aren: command [{Enable Asynchronous Rising Edge Detect Enable for the specified pin. When a rising edge is detected, sets the appropriate pin in Event Detect Status.} pin [integer!] \"GPIO number, or one of RPI_GPIO_P1_*\"]\n"\
	"gpio_clr_aren: command [{Disable Asynchronous Rising Edge Detect Enable for the specified pin.} pin [integer!] \"GPIO number, or one of RPI_GPIO_P1_*\"]\n"\
	"gpio_afen: command [{Enable Asynchronous Falling Edge Detect Enable for the specified pin. When a falling edge is detected, sets the appropriate pin in Event Detect Status.} pin [integer!] \"GPIO number, or one of RPI_GPIO_P1_*\"]\n"\
	"gpio_clr_afen: command [{Disable Asynchronous Falling Edge Detect Enable for the specified pin.} pin [integer!] \"GPIO number, or one of RPI_GPIO_P1_*\"]\n"\
	"gpio_pud: command [{Sets the Pull-up/down register for the given pin. This is used with gpio_pudclk to set the Pull-up/down resistor for the given pin.} pud [integer!] \"The desired Pull-up/down mode. One of GPIO_PUD_*\"]\n"\
	"gpio_pudclk: command [{Clocks the Pull-up/down value set earlier by gpio_pud into the pin.} pin [integer!] \"GPIO number, or one of RPI_GPIO_P1_*\" on [integer!] {HIGH to clock the value from gpio_pud into the pin.}]\n"\
	"gpio_pad: command [{Reads and returns the Pad Control for the given GPIO group. Caution: requires root access.} group [integer!] \"The GPIO pad group number, one of PAD_GROUP_GPIO_*\"]\n"\
	"gpio_set_pad: command [{Sets the Pad Control for the given GPIO group. Caution: requires root access.} group [integer!] \"The GPIO pad group number, one of PAD_GROUP_GPIO_*\" control [integer!] \"Mask of bits from BCM2835_PAD_*\"]\n"\
	"gpio_write: command [\"Sets the output state of the specified pin.\" pin [integer!] \"GPIO number, or one of RPI_GPIO_P1_*\" on [integer!] \"HIGH sets the output to HIGH and LOW to LOW.\"]\n"\
	"gpio_write_multi: command [{Sets any of the first 32 GPIO output pins specified in the mask to the state given by on.} mask [integer!] {Mask of pins to affect. Use eg: (1 << RPI_GPIO_P1_03) | (1 << RPI_GPIO_P1_05)} on [integer!] \"HIGH sets the output to HIGH and LOW to LOW.\"]\n"\
	"gpio_write_mask: command [{Sets the first 32 GPIO output pins specified in the mask to the value given by value.} value [integer!] \"Values required for each bit masked in by mask.\" mask [integer!] {Mask of pins to affect. Use eg: (1 << RPI_GPIO_P1_03) | (1 << RPI_GPIO_P1_05)}]\n"\
	"gpio_set_pud: command [{Sets the Pull-up/down mode for the specified pin. This is more convenient than clocking the mode in with gpio_pud and gpio_pudclk.} pin [integer!] \"GPIO number, or one of RPI_GPIO_P1_*\" pud [integer!] \"The desired Pull-up/down mode. One of GPIO_PUD_*\"]\n"\
	"gpio_get_pud: command [{On the BCM2711 based RPI 4, gets the current Pull-up/down mode for the specified pin.} pin [integer!] \"GPIO number, or one of RPI_GPIO_P1_*\"]\n"\
	"gpio_reset: command [\"Sets all pins to GPIO_PUD_OFF and GPIO_FSEL_INPT\"]\n"\
	"spi_begin: command [\"Start SPI operations.\"]\n"\
	"spi_end: command [\"End SPI operations.\"]\n"\
	"spi_setBitOrder: command [{Set the bit order to be used for transmit and receive. The bcm2835 SPI0 only supports SPI_BIT_ORDER_MSB, so if you select SPI_BIT_ORDER_LSB, the bytes will be reversed in software.} order [integer!] \"The desired bit order, one of SPI_BIT_ORDER_*\"]\n"\
	"spi_setClockDivider: command [{Sets the SPI clock divider and therefore the SPI clock speed.} divider [integer!] {The desired SPI clock divider, one of SPI_CLOCK_DIVIDER_*}]\n"\
	"spi_set_speed_hz: command [{Sets the SPI clock divider by converting the speed parameter to the equivalent SPI clock divider.} speed_hz [integer!] \"The desired SPI clock speed in Hz\"]\n"\
	"spi_setDataMode: command [\"Sets the clock polariy and phase.\" mode [integer!] \"The desired data mode, one of SPI_MODE*\"]\n"\
	"spi_chipSelect: command [{Sets the chip select pin(s). When an spi_transfer is made, the selected pin(s) will be asserted during the transfer.} cs [integer!] {Specifies the CS pins(s) that are used to activate the desired slave. One of SPI_CS*}]\n"\
	"spi_setChipSelectPolarity: command [{Sets the chip select pin polarity for a given pin. When an spi_transfer occurs, the currently selected chip select pin(s) will be asserted to the value given by active. When transfers are not happening, the chip select pin(s) return to the complement (inactive) value.} cs [integer!] {Specifies the CS pins(s) that are used to activate the desired slave. One of SPI_CS*} active [integer!] \"Whether the chip select pin is to be active HIGH.\"]\n"\
	"spi_transfer: command [{Transfers one byte to and from the currently selected SPI slave. Asserts the currently selected CS pins (as previously set by bcm2835_spi_chipSelect) during the transfer. Clocks the 8 bit value out on MOSI, and simultaneously clocks in data from MISO. Returns the read data byte from the slave.} value [integer! char! binary!] \"The 8 bit data byte to write to MOSI, or buffer\"]\n"\
	"spi_write: command [{Transfers any number of bytes to the currently selected SPI slave.} data [binary! integer! char!] {Buffer of bytes to send or the 8 bit data byte to write to MOSI}]\n"\
	"version: command [\"Returns the bcm2835 version.\"]\n"\
	"delay: command [\"Delays for the specified number of milliseconds.\" millis [integer!] \"Delay in milliseconds\"]\n"\
	"delayMicroseconds: command [\"Delays for the specified number of microseconds\" micros [integer!] \"Delay in microseconds\"]\n"\
	"init-words words: [] []\n"\
	"protect/hide 'init-words\n"\
	";; RPiGPIOPin:\n"\
	"RPI_GPIO_P1_03:   0  ;; Version 1, Pin P1-03\n"\
	"RPI_GPIO_P1_05:   1  ;; Version 1, Pin P1-05\n"\
	"RPI_GPIO_P1_07:   4  ;; Version 1, Pin P1-07\n"\
	"RPI_GPIO_P1_08:  14  ;; Version 1, Pin P1-08, defaults to alt function 0 UART0_TXD\n"\
	"RPI_GPIO_P1_10:  15  ;; Version 1, Pin P1-10, defaults to alt function 0 UART0_RXD\n"\
	"RPI_GPIO_P1_11:  17  ;; Version 1, Pin P1-11\n"\
	"RPI_GPIO_P1_12:  18  ;; Version 1, Pin P1-12, can be PWM channel 0 in ALT FUN 5\n"\
	"RPI_GPIO_P1_13:  21  ;; Version 1, Pin P1-13\n"\
	"RPI_GPIO_P1_15:  22  ;; Version 1, Pin P1-15\n"\
	"RPI_GPIO_P1_16:  23  ;; Version 1, Pin P1-16\n"\
	"RPI_GPIO_P1_18:  24  ;; Version 1, Pin P1-18\n"\
	"RPI_GPIO_P1_19:  10  ;; Version 1, Pin P1-19, MOSI when SPI0 in use\n"\
	"RPI_GPIO_P1_21:   9  ;; Version 1, Pin P1-21, MISO when SPI0 in use\n"\
	"RPI_GPIO_P1_22:  25  ;; Version 1, Pin P1-22\n"\
	"RPI_GPIO_P1_23:  11  ;; Version 1, Pin P1-23, CLK when SPI0 in use\n"\
	"RPI_GPIO_P1_24:   8  ;; Version 1, Pin P1-24, CE0 when SPI0 in use\n"\
	"RPI_GPIO_P1_26:   7  ;; Version 1, Pin P1-26, CE1 when SPI0 in use\n"\
	"\n"\
	";; RPi Version 2\n"\
	"RPI_V2_GPIO_P1_03:   2  ;; Version 2, Pin P1-03\n"\
	"RPI_V2_GPIO_P1_05:   3  ;; Version 2, Pin P1-05\n"\
	"RPI_V2_GPIO_P1_07:   4  ;; Version 2, Pin P1-07\n"\
	"RPI_V2_GPIO_P1_08:  14  ;; Version 2, Pin P1-08, defaults to alt function 0 UART0_TXD\n"\
	"RPI_V2_GPIO_P1_10:  15  ;; Version 2, Pin P1-10, defaults to alt function 0 UART0_RXD\n"\
	"RPI_V2_GPIO_P1_11:  17  ;; Version 2, Pin P1-11\n"\
	"RPI_V2_GPIO_P1_12:  18  ;; Version 2, Pin P1-12, can be PWM channel 0 in ALT FUN 5\n"\
	"RPI_V2_GPIO_P1_13:  27  ;; Version 2, Pin P1-13\n"\
	"RPI_V2_GPIO_P1_15:  22  ;; Version 2, Pin P1-15\n"\
	"RPI_V2_GPIO_P1_16:  23  ;; Version 2, Pin P1-16\n"\
	"RPI_V2_GPIO_P1_18:  24  ;; Version 2, Pin P1-18\n"\
	"RPI_V2_GPIO_P1_19:  10  ;; Version 2, Pin P1-19, MOSI when SPI0 in use\n"\
	"RPI_V2_GPIO_P1_21:   9  ;; Version 2, Pin P1-21, MISO when SPI0 in use\n"\
	"RPI_V2_GPIO_P1_22:  25  ;; Version 2, Pin P1-22\n"\
	"RPI_V2_GPIO_P1_23:  11  ;; Version 2, Pin P1-23, CLK when SPI0 in use\n"\
	"RPI_V2_GPIO_P1_24:   8  ;; Version 2, Pin P1-24, CE0 when SPI0 in use\n"\
	"RPI_V2_GPIO_P1_26:   7  ;; Version 2, Pin P1-26, CE1 when SPI0 in use\n"\
	"RPI_V2_GPIO_P1_29:   5  ;; Version 2, Pin P1-29\n"\
	"RPI_V2_GPIO_P1_31:   6  ;; Version 2, Pin P1-31\n"\
	"RPI_V2_GPIO_P1_32:  12  ;; Version 2, Pin P1-32\n"\
	"RPI_V2_GPIO_P1_33:  13  ;; Version 2, Pin P1-33\n"\
	"RPI_V2_GPIO_P1_35:  19  ;; Version 2, Pin P1-35, can be PWM channel 1 in ALT FUN 5 \n"\
	"RPI_V2_GPIO_P1_36:  16  ;; Version 2, Pin P1-36\n"\
	"RPI_V2_GPIO_P1_37:  26  ;; Version 2, Pin P1-37\n"\
	"RPI_V2_GPIO_P1_38:  20  ;; Version 2, Pin P1-38\n"\
	"RPI_V2_GPIO_P1_40:  21  ;; Version 2, Pin P1-40\n"\
	"\n"\
	";; RPi Version 2, new plug P5\n"\
	"RPI_V2_GPIO_P5_03:  28  ;; Version 2, Pin P5-03\n"\
	"RPI_V2_GPIO_P5_04:  29  ;; Version 2, Pin P5-04\n"\
	"RPI_V2_GPIO_P5_05:  30  ;; Version 2, Pin P5-05\n"\
	"RPI_V2_GPIO_P5_06:  31  ;; Version 2, Pin P5-06\n"\
	"\n"\
	";; RPi B+ J8 header, also RPi 2 40 pin GPIO header\n"\
	"RPI_BPLUS_GPIO_J8_03:   2  ;; B+, Pin J8-03\n"\
	"RPI_BPLUS_GPIO_J8_05:   3  ;; B+, Pin J8-05\n"\
	"RPI_BPLUS_GPIO_J8_07:   4  ;; B+, Pin J8-07\n"\
	"RPI_BPLUS_GPIO_J8_08:  14  ;; B+, Pin J8-08, defaults to alt function 0 UART0_TXD\n"\
	"RPI_BPLUS_GPIO_J8_10:  15  ;; B+, Pin J8-10, defaults to alt function 0 UART0_RXD\n"\
	"RPI_BPLUS_GPIO_J8_11:  17  ;; B+, Pin J8-11\n"\
	"RPI_BPLUS_GPIO_J8_12:  18  ;; B+, Pin J8-12, can be PWM channel 0 in ALT FUN 5\n"\
	"RPI_BPLUS_GPIO_J8_13:  27  ;; B+, Pin J8-13\n"\
	"RPI_BPLUS_GPIO_J8_15:  22  ;; B+, Pin J8-15\n"\
	"RPI_BPLUS_GPIO_J8_16:  23  ;; B+, Pin J8-16\n"\
	"RPI_BPLUS_GPIO_J8_18:  24  ;; B+, Pin J8-18\n"\
	"RPI_BPLUS_GPIO_J8_19:  10  ;; B+, Pin J8-19, MOSI when SPI0 in use\n"\
	"RPI_BPLUS_GPIO_J8_21:   9  ;; B+, Pin J8-21, MISO when SPI0 in use\n"\
	"RPI_BPLUS_GPIO_J8_22:  25  ;; B+, Pin J8-22\n"\
	"RPI_BPLUS_GPIO_J8_23:  11  ;; B+, Pin J8-23, CLK when SPI0 in use\n"\
	"RPI_BPLUS_GPIO_J8_24:   8  ;; B+, Pin J8-24, CE0 when SPI0 in use\n"\
	"RPI_BPLUS_GPIO_J8_26:   7  ;; B+, Pin J8-26, CE1 when SPI0 in use\n"\
	"RPI_BPLUS_GPIO_J8_29:   5  ;; B+, Pin J8-29\n"\
	"RPI_BPLUS_GPIO_J8_31:   6  ;; B+, Pin J8-31\n"\
	"RPI_BPLUS_GPIO_J8_32:  12  ;; B+, Pin J8-32\n"\
	"RPI_BPLUS_GPIO_J8_33:  13  ;; B+, Pin J8-33\n"\
	"RPI_BPLUS_GPIO_J8_35:  19  ;; B+, Pin J8-35, can be PWM channel 1 in ALT FUN 5\n"\
	"RPI_BPLUS_GPIO_J8_36:  16  ;; B+, Pin J8-36 \n"\
	"RPI_BPLUS_GPIO_J8_37:  26  ;; B+, Pin J8-37 \n"\
	"RPI_BPLUS_GPIO_J8_38:  20  ;; B+, Pin J8-38 \n"\
	"RPI_BPLUS_GPIO_J8_40:  21  ;; B+, Pin J8-40 \n"\
	"\n"\
	";; bcm2835FunctionSelect:\n"\
	"GPIO_FSEL_INPT:  0   ;; Input  0b000\n"\
	"GPIO_FSEL_OUTP:  1   ;; Output 0b001\n"\
	"GPIO_FSEL_ALT0:  4   ;; Alternate function 0 0b100\n"\
	"GPIO_FSEL_ALT1:  5   ;; Alternate function 1 0b101\n"\
	"GPIO_FSEL_ALT2:  6   ;; Alternate function 2 0b110\n"\
	"GPIO_FSEL_ALT3:  7   ;; Alternate function 3 0b111\n"\
	"GPIO_FSEL_ALT4:  3   ;; Alternate function 4 0b011\n"\
	"GPIO_FSEL_ALT5:  2   ;; Alternate function 5 0b010\n"\
	"GPIO_FSEL_MASK:  7   ;; Function select bits mask 0b111\n"\
	"\n"\
	";; bcm2835PUDControl:\n"\
	"GPIO_PUD_OFF:    0   ;; Off ? disable pull-up/down 0b00\n"\
	"GPIO_PUD_DOWN:   1   ;; Enable Pull Down control 0b01\n"\
	"GPIO_PUD_UP:     2   ;; Enable Pull Up control 0b10\n"\
	"\n"\
	";; bcm2835PadGroup:\n"\
	"PAD_GROUP_GPIO_0_27:  0  ;; Pad group for GPIO pads  0 to 27\n"\
	"PAD_GROUP_GPIO_28_45: 1  ;; Pad group for GPIO pads 28 to 45\n"\
	"PAD_GROUP_GPIO_46_53: 2  ;; Pad group for GPIO pads 46 to 53\n"\
	"\n"\
	";; bcm2835SPIBitOrder:\n"\
	"SPI_BIT_ORDER_LSBFIRST: 0 ;; LSB First\n"\
	"SPI_BIT_ORDER_MSBFIRST: 1 ;; MSB First\n"\
	"\n"\
	";; bcm2835SPIMode:\n"\
	"SPI_MODE0: 0  ;; CPOL = 0, CPHA = 0\n"\
	"SPI_MODE1: 1  ;; CPOL = 0, CPHA = 1\n"\
	"SPI_MODE2: 2  ;; CPOL = 1, CPHA = 0\n"\
	"SPI_MODE3: 3  ;; CPOL = 1, CPHA = 1\n"\
	"\n"\
	";; bcm2835SPIChipSelect:\n"\
	"SPI_CS0:     0  ;; Chip Select 0\n"\
	"SPI_CS1:     1  ;; Chip Select 1\n"\
	"SPI_CS2:     2  ;; Chip Select 2 (ie pins CS1 and CS2 are asserted)\n"\
	"SPI_CS_NONE: 3  ;; No CS, control it yourself\n"\
	"\n"\
