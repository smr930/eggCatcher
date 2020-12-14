#include "./include/callbacks.h"
#include "./include/Game.h"

PSP_MODULE_INFO("App",0,1,1);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER | THREAD_ATTR_VFPU);
PSP_HEAP_SIZE_KB(-128);

int main()
{
	callbacks_setup();
	Game game;
	game.init();
	game.run();
	sceKernelExitGame();
	return 0;
}

