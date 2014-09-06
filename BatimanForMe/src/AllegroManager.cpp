#include"AllegroManager.h"


AllegroManager::AllegroManager()
{
    init();
}

AllegroManager::~AllegroManager()
{
    deinit();
}

void AllegroManager::init()
{
    set_uformat(U_ASCII);
	allegro_init();
	depth = desktop_color_depth();
	if (depth == 0) depth = 32;
	set_color_depth(depth);
	res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 900, 444, 0, 0);
	if (res != 0) {
		allegro_message(allegro_error);
		exit(-1);
	}
	install_timer();
	install_keyboard();
	install_mouse();
	install_sound(DIGI_AUTODETECT , MIDI_AUTODETECT ,0);

	set_window_title("Batiman For Me");
}

void AllegroManager::deinit()
{
    clear_keybuf();
	remove_keyboard();
	allegro_exit();
}

