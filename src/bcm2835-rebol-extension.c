//
// BCM2835 Rebol extension
// ====================================
// Use on your own risc!

#include "bcm2835-rebol-extension.h"
#include "bcm2835.h"


RL_LIB *RL; // Link back to reb-lib from embedded extensions

//==== Globals ===============================//
u32*   ext_cmd_words;
u32*   ext_arg_words;

extern MyCommandPointer Command[];
//============================================//

static const char* init_block = BCM2835_EXT_INIT_CODE;

int cmd_init_words(RXIFRM *frm, void *ctx) {
	ext_cmd_words = RL_MAP_WORDS(RXA_SERIES(frm,1));
	ext_arg_words = RL_MAP_WORDS(RXA_SERIES(frm,2));
	return RXR_NONE;
}


RXIEXT const char *RX_Init(int opts, RL_LIB *lib) {
	RL = lib;
	REBYTE ver[8];
	RL_VERSION(ver);
	debug_print("RXinit bcm2835-extension; Rebol v%i.%i.%i\n", ver[1], ver[2], ver[3]);

	if (MIN_REBOL_VERSION > VERSION(ver[1], ver[2], ver[3])) {
		debug_print("Needs at least Rebol v%i.%i.%i!\n", MIN_REBOL_VER, MIN_REBOL_REV, MIN_REBOL_UPD);
		return 0;
	}
	if (!CHECK_STRUCT_ALIGN) {
		trace("CHECK_STRUCT_ALIGN failed!");
		return 0;
	}
	if (!bcm2835_init()) return 0;
	
	return init_block;
}


RXIEXT int RX_Call(int cmd, RXIFRM *frm, void *ctx) {
	return Command[cmd](frm, ctx);
}
