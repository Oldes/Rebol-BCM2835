
#include "bcm2835-rebol-extension.h"
#include "bcm2835.h"


#define COMMAND            int
#define PAIR_X(frm, n)    (int)RXA_PAIR(frm,n).x
#define PAIR_Y(frm, n)    (int)RXA_PAIR(frm,n).y

#define FRM_IS_HANDLE(n, t)     (RXA_TYPE(frm,n) == RXT_HANDLE && RXA_HANDLE_TYPE(frm, n) == t)
#define ARG_Is_Image(n)         (RXA_TYPE(frm,n) == RXT_IMAGE)
#define ARG_Is_Pair(n)          (RXA_TYPE(frm,n) == RXT_PAIR)
#define ARG_Is_Integer(n)       (RXA_TYPE(frm,n) == RXT_INTEGER)
#define ARG_Is_None(n)          (RXA_TYPE(frm,n) == RXT_NONE)
#define ARG_Is_Not_None(n)      (RXA_TYPE(frm,n) != RXT_NONE)
#define ARG_Is_Block(n)         (RXA_TYPE(frm,n) == RXT_BLOCK)
#define ARG_Is_Binary(n)        (RXA_TYPE(frm,n) == RXT_BINARY)
#define ARG_Double(n)           (RXA_TYPE(frm,n) == RXT_DECIMAL ? RXA_DEC64(frm,n) : (double)RXA_INT64(frm,n))
#define ARG_Int(n)              (RXA_TYPE(frm,n) == RXT_INTEGER ? RXA_INT32(frm,n) : (int)RXA_DEC64(frm,n))
#define ARG_UINT8(n)            ((uint8_t)RXA_INT32(frm,n))
#define ARG_UINT16(n)           ((uint16_t)RXA_INT32(frm,n))
#define ARG_UINT32(n)           ((uint32_t)RXA_INT32(frm,n))
#define ARG_UINT64(n)           ((uint64_t)RXA_INT64(frm,n))


COMMAND cmd_version(RXIFRM *frm, void *ctx) {
	RXA_TYPE(frm,1) = RXT_INTEGER;
	RXA_ARG(frm,1).int64 = bcm2835_version();
	return RXR_VALUE;
}

COMMAND cmd_gpio_fsel(RXIFRM *frm, void *ctx) {
	bcm2835_gpio_fsel(ARG_UINT8(1), ARG_UINT8(2));
	return RXR_UNSET;
}

COMMAND cmd_gpio_set(RXIFRM *frm, void *ctx) {
	bcm2835_gpio_set(ARG_UINT8(1));
	return RXR_UNSET;
}

COMMAND cmd_gpio_clr(RXIFRM *frm, void *ctx) {
	bcm2835_gpio_clr(ARG_UINT8(1));
	return RXR_UNSET;
}

COMMAND cmd_gpio_set_multi(RXIFRM *frm, void *ctx) {
	bcm2835_gpio_set_multi(ARG_UINT32(1));
	return RXR_UNSET;
}

COMMAND cmd_gpio_clr_multi(RXIFRM *frm, void *ctx) {
	bcm2835_gpio_clr_multi(ARG_UINT32(1));
	return RXR_UNSET;
}

COMMAND cmd_gpio_lev(RXIFRM *frm, void *ctx) {
	RXA_TYPE(frm,1) = RXT_INTEGER;
	RXA_ARG(frm,1).int64 = bcm2835_gpio_lev(ARG_UINT8(1));
	return RXR_VALUE;
}

COMMAND cmd_gpio_eds(RXIFRM *frm, void *ctx) {
	RXA_TYPE(frm,1) = RXT_INTEGER;
	RXA_ARG(frm,1).int64 = bcm2835_gpio_eds(ARG_UINT8(1));
	return RXR_VALUE;
}

COMMAND cmd_gpio_eds_multi(RXIFRM *frm, void *ctx) {
	RXA_TYPE(frm,1) = RXT_INTEGER;
	RXA_ARG(frm,1).int64 = bcm2835_gpio_eds_multi(ARG_UINT32(1));
	return RXR_VALUE;
}

COMMAND cmd_gpio_set_eds(RXIFRM *frm, void *ctx) {
	bcm2835_gpio_set_eds(ARG_UINT8(1));
	return RXR_UNSET;
}

COMMAND cmd_gpio_set_eds_multi(RXIFRM *frm, void *ctx) {
	bcm2835_gpio_set_eds_multi(ARG_UINT32(1));
	return RXR_UNSET;
}

COMMAND cmd_gpio_ren(RXIFRM *frm, void *ctx) {
	bcm2835_gpio_ren(ARG_UINT8(1));
	return RXR_UNSET;
}

COMMAND cmd_gpio_clr_ren(RXIFRM *frm, void *ctx) {
	bcm2835_gpio_clr_ren(ARG_UINT8(1));
	return RXR_UNSET;
}

COMMAND cmd_gpio_fen(RXIFRM *frm, void *ctx) {
	bcm2835_gpio_fen(ARG_UINT8(1));
	return RXR_UNSET;
}

COMMAND cmd_gpio_clr_fen(RXIFRM *frm, void *ctx) {
	bcm2835_gpio_clr_fen(ARG_UINT8(1));
	return RXR_UNSET;
}

COMMAND cmd_gpio_hen(RXIFRM *frm, void *ctx) {
	bcm2835_gpio_hen(ARG_UINT8(1));
	return RXR_UNSET;
}

COMMAND cmd_gpio_clr_hen(RXIFRM *frm, void *ctx) {
	bcm2835_gpio_clr_hen(ARG_UINT8(1));
	return RXR_UNSET;
}

COMMAND cmd_gpio_len(RXIFRM *frm, void *ctx) {
	bcm2835_gpio_len(ARG_UINT8(1));
	return RXR_UNSET;
}

COMMAND cmd_gpio_clr_len(RXIFRM *frm, void *ctx) {
	bcm2835_gpio_clr_len(ARG_UINT8(1));
	return RXR_UNSET;
}

COMMAND cmd_gpio_aren(RXIFRM *frm, void *ctx) {
	bcm2835_gpio_aren(ARG_UINT8(1));
	return RXR_UNSET;
}

COMMAND cmd_gpio_clr_aren(RXIFRM *frm, void *ctx) {
	bcm2835_gpio_clr_aren(ARG_UINT8(1));
	return RXR_UNSET;
}

COMMAND cmd_gpio_afen(RXIFRM *frm, void *ctx) {
	bcm2835_gpio_afen(ARG_UINT8(1));
	return RXR_UNSET;
}

COMMAND cmd_gpio_clr_afen(RXIFRM *frm, void *ctx) {
	bcm2835_gpio_clr_afen(ARG_UINT8(1));
	return RXR_UNSET;
}

COMMAND cmd_gpio_pud(RXIFRM *frm, void *ctx) {
	bcm2835_gpio_pud(ARG_UINT8(1));
	return RXR_UNSET;
}
COMMAND cmd_gpio_pudclk(RXIFRM *frm, void *ctx) {
	bcm2835_gpio_pudclk(ARG_UINT8(1), ARG_UINT8(2));
	return RXR_UNSET;
}

COMMAND cmd_gpio_pad(RXIFRM *frm, void *ctx) {
	RXA_TYPE(frm,1) = RXT_INTEGER;
	RXA_ARG(frm,1).int64 = bcm2835_gpio_pad(ARG_UINT8(1));
	return RXR_VALUE;
}
COMMAND cmd_gpio_set_pad(RXIFRM *frm, void *ctx) {
	bcm2835_gpio_set_pad(ARG_UINT8(1), ARG_UINT32(2));
	return RXR_UNSET;
}

COMMAND cmd_gpio_write(RXIFRM *frm, void *ctx) {
	bcm2835_gpio_write(ARG_UINT8(1), ARG_UINT8(2));
	return RXR_UNSET;
}
COMMAND cmd_gpio_write_multi(RXIFRM *frm, void *ctx) {
	bcm2835_gpio_write_multi(ARG_UINT32(1), ARG_UINT8(2));
	return RXR_UNSET;
}
COMMAND cmd_gpio_write_mask(RXIFRM *frm, void *ctx) {
	bcm2835_gpio_write_mask(ARG_UINT32(1), ARG_UINT32(2));
	return RXR_UNSET;
}

COMMAND cmd_gpio_set_pud(RXIFRM *frm, void *ctx) {
	bcm2835_gpio_set_pud(ARG_UINT8(1), ARG_UINT8(2));
	return RXR_UNSET;
}
COMMAND cmd_gpio_get_pud(RXIFRM *frm, void *ctx) {
	RXA_TYPE(frm,1) = RXT_INTEGER;
	RXA_ARG(frm,1).int64 = bcm2835_gpio_get_pud(ARG_UINT8(1));
	return RXR_VALUE;
}

COMMAND cmd_gpio_reset(RXIFRM *frm, void *ctx) {
	bcm2835_gpio_set_pud(RPI_V2_GPIO_P1_03, BCM2835_GPIO_PUD_OFF);
	bcm2835_gpio_set_pud(RPI_V2_GPIO_P1_05, BCM2835_GPIO_PUD_OFF);
	bcm2835_gpio_set_pud(RPI_V2_GPIO_P1_07, BCM2835_GPIO_PUD_OFF);
	bcm2835_gpio_set_pud(RPI_V2_GPIO_P1_26, BCM2835_GPIO_PUD_OFF);
	bcm2835_gpio_set_pud(RPI_V2_GPIO_P1_24, BCM2835_GPIO_PUD_OFF);
	bcm2835_gpio_set_pud(RPI_V2_GPIO_P1_21, BCM2835_GPIO_PUD_OFF);
	bcm2835_gpio_set_pud(RPI_V2_GPIO_P1_19, BCM2835_GPIO_PUD_OFF);
	bcm2835_gpio_set_pud(RPI_V2_GPIO_P1_23, BCM2835_GPIO_PUD_OFF);
	bcm2835_gpio_set_pud(RPI_V2_GPIO_P1_10, BCM2835_GPIO_PUD_OFF);
	bcm2835_gpio_set_pud(RPI_V2_GPIO_P1_11, BCM2835_GPIO_PUD_OFF);
	bcm2835_gpio_set_pud(RPI_V2_GPIO_P1_12, BCM2835_GPIO_PUD_OFF);
	bcm2835_gpio_set_pud(RPI_V2_GPIO_P1_13, BCM2835_GPIO_PUD_OFF);
	bcm2835_gpio_set_pud(RPI_V2_GPIO_P1_15, BCM2835_GPIO_PUD_OFF);
	bcm2835_gpio_set_pud(RPI_V2_GPIO_P1_16, BCM2835_GPIO_PUD_OFF);
	bcm2835_gpio_set_pud(RPI_V2_GPIO_P1_18, BCM2835_GPIO_PUD_OFF);
	bcm2835_gpio_set_pud(RPI_V2_GPIO_P1_22, BCM2835_GPIO_PUD_OFF);

	bcm2835_gpio_fsel(RPI_V2_GPIO_P1_03, BCM2835_GPIO_FSEL_INPT);
	bcm2835_gpio_fsel(RPI_V2_GPIO_P1_05, BCM2835_GPIO_FSEL_INPT);
	bcm2835_gpio_fsel(RPI_V2_GPIO_P1_07, BCM2835_GPIO_FSEL_INPT);
	bcm2835_gpio_fsel(RPI_V2_GPIO_P1_26, BCM2835_GPIO_FSEL_INPT);
	bcm2835_gpio_fsel(RPI_V2_GPIO_P1_24, BCM2835_GPIO_FSEL_INPT);
	bcm2835_gpio_fsel(RPI_V2_GPIO_P1_21, BCM2835_GPIO_FSEL_INPT);
	bcm2835_gpio_fsel(RPI_V2_GPIO_P1_19, BCM2835_GPIO_FSEL_INPT);
	bcm2835_gpio_fsel(RPI_V2_GPIO_P1_23, BCM2835_GPIO_FSEL_INPT);
	bcm2835_gpio_fsel(RPI_V2_GPIO_P1_10, BCM2835_GPIO_FSEL_INPT);
	bcm2835_gpio_fsel(RPI_V2_GPIO_P1_11, BCM2835_GPIO_FSEL_INPT);
	bcm2835_gpio_fsel(RPI_V2_GPIO_P1_12, BCM2835_GPIO_FSEL_INPT);
	bcm2835_gpio_fsel(RPI_V2_GPIO_P1_13, BCM2835_GPIO_FSEL_INPT);
	bcm2835_gpio_fsel(RPI_V2_GPIO_P1_15, BCM2835_GPIO_FSEL_INPT);
	bcm2835_gpio_fsel(RPI_V2_GPIO_P1_16, BCM2835_GPIO_FSEL_INPT);
	bcm2835_gpio_fsel(RPI_V2_GPIO_P1_18, BCM2835_GPIO_FSEL_INPT);
	bcm2835_gpio_fsel(RPI_V2_GPIO_P1_22, BCM2835_GPIO_FSEL_INPT);
	return RXR_UNSET;
}

//===========================================================================

COMMAND cmd_spi_begin(RXIFRM *frm, void *ctx) {
	RXA_TYPE(frm,1) = RXT_LOGIC;
	RXA_LOGIC(frm,1) = bcm2835_spi_begin();
	return RXR_VALUE;
}
COMMAND cmd_spi_end(RXIFRM *frm, void *ctx) {
	bcm2835_spi_end();
	return RXR_UNSET;
}
COMMAND cmd_spi_setBitOrder(RXIFRM *frm, void *ctx) {
	bcm2835_spi_setBitOrder(ARG_UINT8(1));
	return RXR_UNSET;
}
COMMAND cmd_spi_setClockDivider(RXIFRM *frm, void *ctx) {
	bcm2835_spi_setClockDivider(ARG_UINT16(1));
	return RXR_UNSET;
}
COMMAND cmd_spi_set_speed_hz(RXIFRM *frm, void *ctx) {
	bcm2835_spi_set_speed_hz(ARG_UINT32(1));
	return RXR_UNSET;
}
COMMAND cmd_spi_setDataMode(RXIFRM *frm, void *ctx) {
	bcm2835_spi_setDataMode(ARG_UINT8(1));
	return RXR_UNSET;
}
COMMAND cmd_spi_chipSelect(RXIFRM *frm, void *ctx) {
	bcm2835_spi_chipSelect(ARG_UINT8(1));
	return RXR_UNSET;
}
COMMAND cmd_spi_setChipSelectPolarity(RXIFRM *frm, void *ctx) {
	bcm2835_spi_setChipSelectPolarity(ARG_UINT8(1), ARG_UINT8(2));
	return RXR_UNSET;
}
COMMAND cmd_spi_transfer(RXIFRM *frm, void *ctx) {
	if (ARG_Is_Binary(1)) {
		REBSER *ser = (REBSER *)RXA_SERIES(frm, 1);
		REBINT index = RXA_INDEX(frm,1);
		bcm2835_spi_transfern((char *)SERIES_SKIP(ser, index), SERIES_TAIL(ser) - index);	
	} else {
		RXA_TYPE(frm,1) = RXT_INTEGER;
		RXA_ARG(frm,1).int64 = bcm2835_spi_transfer(ARG_UINT8(1));	
	}
	return RXR_VALUE;
}

COMMAND cmd_spi_write(RXIFRM *frm, void *ctx) {
	if (ARG_Is_Binary(1)) {
		REBSER *ser = (REBSER *)RXA_SERIES(frm, 1);
		REBINT index = RXA_INDEX(frm,1);
		bcm2835_spi_writenb((const char *)SERIES_SKIP(ser, index), SERIES_TAIL(ser) - index);	
	} else {
		bcm2835_spi_write(ARG_UINT16(1));	
	}
	return RXR_VALUE;
}

//===========================================================================

COMMAND cmd_delay(RXIFRM *frm, void *ctx) {
	bcm2835_delay(ARG_UINT32(1));
	return RXR_UNSET;
}
COMMAND cmd_delayMicroseconds(RXIFRM *frm, void *ctx) {
	bcm2835_delayMicroseconds(ARG_UINT64(1));
	return RXR_UNSET;
}


