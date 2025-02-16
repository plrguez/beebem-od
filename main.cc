/****************************************************************************/
/*              Beebem - (c) David Alan Gilbert 1994/1995                   */
/*              -----------------------------------------                   */
/* This program may be distributed freely within the following restrictions:*/
/*                                                                          */
/* 1) You may not charge for this program or for any part of it.            */
/* 2) This copyright message must be distributed with all copies.           */
/* 3) This program must be distributed complete with source code.  Binary   */
/*    only distribution is not permitted.                                   */
/* 4) The author offers no warrenties, or guarentees etc. - you use it at   */
/*    your own risk.  If it messes something up or destroys your computer   */
/*    thats YOUR problem.                                                   */
/* 5) You may use small sections of code from this program in your own      */
/*    applications - but you must acknowledge its use.  If you plan to use  */
/*    large sections then please ask the author.                            */
/*                                                                          */
/* If you do not agree with any of the above then please do not use this    */
/* program.                                                                 */
/* Please report any problems to the author at beebem@treblig.org           */
/****************************************************************************/
/* Beeb emulator - main file */

/*
0.1:
DONE	Get a build of BeebEm 0.9p1 with my SDL stuff from 0.0.14. working.
DONE	Add SDL keyboard support.
DONE	Install new graphics code.
DONE	Fix line drawing so it's always within bounds.
DONE	Test video code for out of bounds.
DONE	Restrict (but not fixed yet) buffer overrun in video context change - when wide/narrow resolutions change, the first line is rendered in the old width. So some resolutions/colour depths render twice their width. This is issue has not yet been fixed. Will investigate for 0.0.14 (as this is a video emulation issue in all versions of BeebEm).
DONE	Reduce screen size to target size.
DONE	Think of a way of reducing the frame rate to 25fps.
DONE	Add compiling support for GP2x.
DONE	Convert to faster rendering method.
DONE	Check that keyboard bug is not happening. (It was).
DONE	Hack shift loading. (just make sure for first emulated second shift is down).
DONE	Investigate regulating timing (via frame change - beeb do time).

0.2:
DONE	Port Critical's keyboard support from Critical-Beeb.
DONE	add temp command line parser (which can load discs and key-mappings).

0.3:
DONE	Sound support (from 0.0.14).
DONE	Sound stops after n amount of time? I think this may be the cycle count flip? It was.
DONE	Make volume buttons work.
DONE	Add SET option support to kbd files.
DONE	Add half horizontal size support for teletext and graphics.
DONE	Graphics and Teletext should be flipable (modify the line drawing routines).
DONE	Add SET option to change CPU speed.
DONE	Add SET option to change volume.
DONE	Add SET option to change how the screen is centred.
DONE	Extend Critical's code to support all buttons with the execption of START.
DONE	Volume buttons only work if the GP2x volume button entries are set to GP2X_USEASVOLUME ("VOLUME" in config file).
DONE	Have two mapping buffers, 0 = normal, 1 = reversed. Other mapped keys are the upside down ones.
DONE	Allow a vertical screen flip and alternative button mapping via SET option.
DONE	Can discs be writable? Yes. Add SET option to make disks writable.
DONE	Make keyboard.cc case insensitive.
DONE	Make sure volume buttons default to volume control.
DONE	Show free time (as a sum for the second) on the debug output.
DONE	Two new configuration files, 1 is loaded prior to the .kbd file, the other after. That way you can set default options and force some.

0.4:
DONE	Port GUI from 0.0.14
DONE	Allow font to draw upside down.
DONE	Make graphics functions draw upside down.
DONE	Add new smart focus movement to GUI.
DONE	Move SET option to global settings source file.
DONE	Use getcwd for all relative paths.
DONE	Load files from config rather than hardwiring.
DONE	Add SET options for font_loc, romimg_rc_loc, romimg_dir, forced_config_loc
DONE	Load default config file to initialize configuration.
DONE	Load keyboard config files from either the same dir as the disc image, or the keyboard mapping folder.
DONE	At least get the virtual keyboard working in some form.
DONE	If a button is mapped to blank A= etc, then map it to NOTHING.
DONE	Modify buttons so optionally can display without a border.
DONE	Modify scrollbar so optionally cannot get focus.
DONE	Add LEFT/RIGHT/UP/DOWN/CLICK focus movement commands to EG_Window.
DONE	Add simple stick control to beebem_pages.cc
DONE	Modify tabpages so when a tab page button gets focus, then focus switches immediately to this tab page.
DONE	Port some of the EG_DC stock graphics fuctions to SDL and use them for the widgets.
DONE	We need a key down and key up event for the select key.
DONE	Remove key support from within window.c, everything should go through the new method.
DONE	Make sure widgets are now absolute to the SDL Surface rather than relative to the window.
DONE	Remove TAB focus shifting support from GUI (may confuse smart focus).
DONE	Write stick control routines that receive joystick events and call callbacks based on the state of the stick + auto repeat.
DONE	When virtual keyboard displayed: A, B, Y and X; and in reverse mode VOL+, VOL- are the same as CLICK. This is for D-Pad conversions.
DONE	Finish virtual keyboard movement.
DONE	Disable old text printing function.
DONE	Fix for new drawing functions: togglebutton.c
DONE	Add volume control page (simple 0 - 100 volume)
DONE	Make reset button work.
DONE	When the menu is removed also remove the virtual keyboard.
DONE	Don't shift boot if no disc inserted.
DONE	Make game config page.
DONE	Make game config page work.
DONE	When a button is pressed you can still move. Lock movement when a button is down, only unlock on release.
DONE	Broken flipped mode button mapping.
DONE	Make game button config page.
DONE	Create the popup keyboard mapper.
DONE	Make game button config page work.
DONE	If cannot open default.kbd then try again with arg 0 from the executables path.
DONE	Make save game config button work.
DONE	Findout why Chuckie Egg wont go right? It was a keyboard mapping bug.

0.5:
DONE	Add a message box for feedback.
DONE	Port 8271 support from 3.5.
DONE	Make sure every disc write calls sync().
DONE 	Fixup+enable a basic hardware cursor + add SET option to disable it.
DONE	Add basic save state support.
DONE	Make sure failed disc loads result in an error message and no shift loading.
DONE	Make sure that if the disc image is illegal, then an error results.
DONE	Move kbd config loading code and disc loading to separate set of functions.
DONE	Make sure load state resets the beeb and loads the keyboard too.
DONE	Check which disc image a loaded state uses and load its config + reset to default config first.
DONE	Move SDL initialization to sdl.cc
DONE	Enable windows message boxes throughout beebem.
DONE	Make virtual keyboard LEDs work.
DONE	Reduce the cycle count in the 6502 loop. (now at 2048).
DONE	List box dialog: title + list of entries + user value for each one. SELECT / START cancels.
DONE	Change palette to something compatible with the Beebem frame buffer when showing the menu.
DONE	Modify scrollbar - should just be a troff for now.
DONE	Add progress bar dialog (for sorting and reading from sd card).
DONE	List files in a directory into a list box structure.
DONE	Enable run disc.
DONE	Make virtual keyboard keys release when the physical key is released (it's timed at the moment).
DONE	Enable insert disc in drive 0 or 1.
DONE	Add SET option for save/load states dir.
DONE	Use file selector for save/load states.
DONE	Make sure 8271 calls sync() when sectors are written.
DONE	Add progress bar to save states.
DONE	Add startup.cnf for stuff that should be set when beebem is first loaded. Move annoying stuff from default.kbd to this file.
DONE	Add message box to confirm that disc image configuration has been saved.
DONE	Clear all SDL_Surfaces prior to quiting so a mangled version of the virtual keyboard isn't displayed.
DONE	Add create blank formatted disc option.
DONE	Add are you sure to Quit and Reset. Check Reset *IS* Resetting everything.
DONE	Add frame-skip to teletext mode to speed it up - doesn't seem to make anything worse!
DONE	Overlay volume dialog.
DONE	Simple virtual keyboard for entering new names into the file selector.
DONE	Add "are you sure" message-box when overwriting an existing save state - too many accidents with the stick... :-(
DONE	Add an Image widget class to EG + add owl to menu (use my owl).
DONE	Swap flipped and normal modes on button mapper.
DONE	Add a disable cursor option to settings page + make sure state is saved to .kbd.
DONE	Move 'flipped' mode option to settings page.
DONE	Revise messages in message boxes. Centralise messages in one place as defines.

0.5-1:

DONE	Multi keys keyboard bug: when flying in Thrust, when you swing left and right, thrusting stops.
DONE	Add some additional stick code: MULTI, VERTICAL, HORIZONTAL.
DONE	Load state has shift held down like run, it shouldn't.
DONE	Make list boxes wrap around at the bottom.
DONE	New Owl image.
DONE	Long filenames on the selector and save-as dialogs crash beebem.
DONE	Old movement method doesn't support flipped mode.
DONE	Move stick mode selector to main menu.
DONE	Reloading sideways RAM fails on Exile.

0.6:

DONE	Remove code that blanks out areas
DONE	Change clear screen so that it draws a box around the rendering area
DONE	Add function key to clear screen
DONE	Fix overrun bug so graphics painting stays in bounds
DONE	Add left/right scanline blanking + blank scanlines.
DONE	Vertical scaling.
DONE	Fasttable for 320 width
DONE	Fix cursor.
DONE	Make sure font is loaded via beebconfig.cc
DONE	Add flipped mode support.
DONE	Make sure cursors work correctly.
DONE	Add in virtual keyboard code.
DONE	Add in LEDs code.
DONE	Support option to disable hardware cursor.
DONE	Harmonise sound code with latest BeebEm.
DONE	Add support to display different parts of the blanking gap - i.e.: offset display vertically by 8 scanlines (for some games).
DONE	Up MHZ from 150-240 to 170-260 :-(
DONE	Make sure old config files with Speed<170 are upped to 170MHZ... :-(
DONE	CRT shift, move screen 8 scanlines up for FireTrek etc. Add as a tickbox with other options.
DONE	Add basic skinning support to GUI.

0.6-1:

*	Allow filenames to be of any length.

+	One bottom scanline of graphics mode is not removed when switching to text mode.
+	Buttons aren't rendered properly on GP2X
+	Nudge doesn't seem to work correctly on GP2X

*/


#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <stdio.h>

#include "6502core.h"
#include "beebmem.h"
#include "beebsound.h"
#include "sysvia.h"
#include "uservia.h"
#include "beebwin.h"
#include "disc8271.h"
#include "video.h"
#include "keyboard.h"
#include "beebconfig.h"
#include "beebconfig_data.h"
#include "virtualkeyboard.h"
#include "button.h"

#include "messagebox.h"

#include <SDL.h>
#include <gui/gui.h>

#include "beebem_pages.h"
#include "keyboardmapper.h"

#include "uefstate.h"

#include "listbox.h"
#include "fileselector.h"

#include "stick.h"

#include "via.h"

#ifdef USE_DMA
#include "dma.h"
#endif


extern VIAState SysVIAState;



/* BeebEm GP2X is really badly tied in to this. So must be NULL at startup for now...
 * (don't worry this class is going...)
 */
BeebWin *mainWin = NULL;

static char *Banner=
#include "header"
;

static char *Version="BeebEm " VERSION " for GP2X";

/* Terminates BeebEm when 1.
 */
static int done=0;


void QuitEmulator(void)
{
	done=1;
}

void at_exit(void)
{

	printf("running at_exit.\n");

	StickManager_Quit();

	SDL_FillRect(frame_buffer_p, NULL, 0);
	//SDL_UpdateRect(frame_buffer_p, 0,0,0,0);
	rgb_blit();

	FileSelector_Quit();

	VirtualKeyboard_FreeResources();
	Config_FreeResources();
#ifdef GP2X
	GP2x_FreeResources();
#endif
	BeebEmPages_Destroy();
	BBCKeyboard_Destroy();

	EG_Quit();
	SDL_Quit();

#ifdef USE_DMA
	close_dma();
#endif

#ifdef GP2X
	OSS_Mixer_Quit();
#endif

#ifdef GP2X
#	ifdef PRODUCTION
		printf("loading GP2X menu.\n");
		chdir("/usr/gp2x");
		execl("/usr/gp2x/gp2xmenu", "/usr/gp2x/gp2xmenu", NULL);
#	endif
#endif
}

/* The GP2x doesn't seem to call atexit after calling exit()?
 *
 * I'll just fudge it for now...
 */
#ifdef GP2X
	void do_exit(int r) { at_exit(); exit(r); }
#       define EXIT do_exit
#else
#       define EXIT exit
#endif

void cls(void)
{
	SDL_FillRect(frame_buffer_p, NULL, 0);
}

int main(int argc,char *argv[]) {
	char filename[256+1], mapping[256+1], *file_type_p, *filename_p;
	int flags; //, key_pressed_delay;


	//printf("[%lx]\n", EG_MakeStringHash("EG_Widget_Type_Image"));




	/* Print start message on console:
	 */
	std::cout << Banner << "\n" << "Version: " << Version << "\n";


	/* Initialize SDL (not sound):
	 */
	if (! InitializeSDL(argc, argv))
		return false;


	/* Set GP2X speed to 200Mhz initially.
	 */
#ifdef GP2X
        GP2x_SetCPUSpeed(200);
#endif


#ifdef GP2X
	/* Setup volume on GP2X:
	 */
	OSS_Mixer_Init();
	OSS_Mixer_SetVolume(0);
	printf("Volume set to %d.\n", OSS_Mixer_GetVolume());

	/* Initialize the GP2x hardware:
	 */
	GP2x_Initialize();
#endif


	/* 'Initialize global configuration` (Sounds KuNu-Labour doesn't it!?):
	 */
	Config_Initialize(argv[0]);
        

#ifdef OPENDINGUX
        SetVideoMode();
#endif

	/* Initialize Economy GUI API:
	 */
	if (EG_Initialize(config.files.font_loc) == EG_TRUE){
		fprintf(stderr, "EG initialized.\n");
        }else{
		fprintf(stderr, "EG failed to initialize! Quiting.\n");
                EXIT(1);
        }


	/* Create GUI pages:
	 */
	if (BeebEmPages_Create(frame_buffer_p) != EG_TRUE) {
		fprintf(stderr, "Couldn't create the GUI.\n");
		EXIT(1);
	}


	/* Initialize button navigation:
	 */
	Button_Init();


	/* Initialize the virtual keyboard:
	 */
#ifdef OPENDINGUX
	if (! VirtualKeyboard_Initialize(mix_surface) ) {
#else
	if (! VirtualKeyboard_Initialize(frame_buffer_p) ) {
#endif
		fprintf(stderr, "Couldn't initialize the virtual keyboard.\n");
		EXIT(1);
	}


	/* Initialize mainWin (mainWin is going).
	 */
	mainWin=new BeebWin();



	/* Initialize emulator core:
	 */
	BeebMemInit();
  	Init6502core();
 	SysVIAReset();
#ifdef SOUNDSUPPORT
  	SoundInit();
#endif
  	UserVIAReset();
  	VideoInit();
  	Disc8271_reset();


	/* Make sure the emulator core knows which colors to use on the frame buffer:
	 */
	mainWin->FindPaletteColors();


	/* Initialize the file selectors:
  	 */
	FileSelector_Initialize();


	/* Load disc image (if one specified)
	 */
	if (argc>1) Config_LoadDiscConfig(argv[1]);



	/* Set button repeat rate for virtual keyboard
  	 */
	Button_SetAutoRepeatDelay(50);

	/* Main loop (this is only called every n cycles so doesn't need to be fast):
	 */
	StickManager_Initialize();




//	SkinTest(frame_buffer_p);


        int pressed=0, ordinalHit=0;
        int keysym = 0;


	//EG_MessageBox(frame_buffer_p, EG_MESSAGEBOX_STOP, "Not implemented:", "Create blank: /mnt/sd/beebem05_1/discs/", "Exit BeebEm", NULL, NULL, NULL, 0);

	int caps_flash=0;
	int beeb_key_column, beeb_key_row, col, row;
	done = beeb_key_column = beeb_key_row = col = row = 0;
//	key_pressed_delay = 0;
	do {

		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
				
				case SDL_QUIT:
					done=1;
					break;

			/* Handle SDL Keyboard:
			 */
				case SDL_KEYDOWN:

					/* Debugging hacks: -----------------------------------------------
					 */

//					if (event.key.keysym.sym == SDLK_F6) {
//						printf("Loading state...\n");
//						LoadUEFState("test.uef");

//						RepaintShiftLED();
//						SDL_Sleep(1000);
//						break;
//					}
//
//					if (event.key.keysym.sym == SDLK_F5) {
//						printf("Saving state...\n");
//						SaveUEFState("test.uef");
//						break;
//					}

					if (event.key.keysym.sym == SDLK_BACKSPACE) {
						if (mainWin->OnScreenKeyboardShown()) {
							mainWin->HideOnScreenKeyboard();
							cls();
						} else {
							Button_Reset();
							AllButtonsUp();
							mainWin->ShowOnScreenKeyboard();
#ifndef OPENDINGUX
							VirtualKeyboard_Render();
#endif
						}
						break;
					}

					if(!mainWin->OnScreenKeyboardShown())
						{
						if (event.key.keysym.sym == SDLK_UP)
							{
							keysym = gp2xButtonToSDLK(GP2X_BUTTON_UP);
							HandleButtonPressForKeysym(event.type == SDL_KEYDOWN, keysym);
							}
						if (event.key.keysym.sym == SDLK_DOWN)
							{
							keysym = gp2xButtonToSDLK(GP2X_BUTTON_DOWN);
							HandleButtonPressForKeysym(event.type == SDL_KEYDOWN, keysym);
							}
						if (event.key.keysym.sym == SDLK_LEFT)
							{
							keysym = gp2xButtonToSDLK(GP2X_BUTTON_LEFT);
							HandleButtonPressForKeysym(event.type == SDL_KEYDOWN, keysym);
							}
						if (event.key.keysym.sym == SDLK_RIGHT)
							{
							keysym = gp2xButtonToSDLK(GP2X_BUTTON_RIGHT);
							HandleButtonPressForKeysym(event.type == SDL_KEYDOWN, keysym);
							}
						if (event.key.keysym.sym == SDLK_LCTRL)
							{
							keysym = gp2xButtonToSDLK(GP2X_BUTTON_A);
							HandleButtonPressForKeysym(event.type == SDL_KEYDOWN, keysym);
							}
						if (event.key.keysym.sym == SDLK_LALT)
							{
							keysym = gp2xButtonToSDLK(GP2X_BUTTON_B);
							HandleButtonPressForKeysym(event.type == SDL_KEYDOWN, keysym);
							}
						if (event.key.keysym.sym == SDLK_SPACE)
							{
							keysym = gp2xButtonToSDLK(GP2X_BUTTON_X);
							HandleButtonPressForKeysym(event.type == SDL_KEYDOWN, keysym);
							}
						if (event.key.keysym.sym == SDLK_LSHIFT)
							{
							keysym = gp2xButtonToSDLK(GP2X_BUTTON_Y);
							HandleButtonPressForKeysym(event.type == SDL_KEYDOWN, keysym);
							}
						if (event.key.keysym.sym == SDLK_RETURN)
							{
							keysym = gp2xButtonToSDLK(GP2X_BUTTON_START);
							HandleButtonPressForKeysym(event.type == SDL_KEYDOWN, keysym);
							}
						if (event.key.keysym.sym == SDLK_ESCAPE)
							{
							keysym = gp2xButtonToSDLK(GP2X_BUTTON_SELECT);
							HandleButtonPressForKeysym(event.type == SDL_KEYDOWN, keysym);
							}
						}
/*
					if (event.key.keysym.sym == SDLK_F2) {
						if (mainWin->ScreenIsReversed()) {
							mainWin->NormaliseScreenOrientation();
							EG_FlipNormalSideUp();

							if (mainWin->OnScreenKeyboardShown())
								VirtualKeyboard_Render();
							else
								cls();
						} else {
							mainWin->ReverseScreenOrientation();
							EG_FlipUpsideDown();

							if (mainWin->OnScreenKeyboardShown())
								VirtualKeyboard_Render();
							else
								cls();
						}
						break;
					}
*/
					if (event.key.keysym.sym == SDLK_TAB) {
						mainWin->ShiftBooted = false;
						BeebKeyUp(0, 0);

#ifdef OPENDINGUX
                                                if (mainWin->OnScreenKeyboardShown())
                                                        mainWin->HideOnScreenKeyboard();
#endif
						BeebEmPages_ShowMenu();
                                                cls();
#ifndef OPENDINGUX
                                                if (mainWin->OnScreenKeyboardShown())
                                                        mainWin->HideOnScreenKeyboard();
                                                        //VirtualKeyboard_Render();
#endif

						break;
					}

					/* ----------------------------------------------------------------
					 */
					if (! mainWin->OnScreenKeyboardShown()) {

						/* Handle shift booting:
						 */
						if (mainWin->ShiftBooted) {
							mainWin->ShiftBooted = false;
							BeebKeyUp(0, 0);
						}

						if ( ConvertSDLKeyToBBCKey( event.key.keysym.sym, &beeb_key_column, &beeb_key_row) ) {
							//BeebKeyDown(beeb_key_row, beeb_key_column);
						} else if (beeb_key_row == -2) {
							/* Handle reset */
							Init6502core();
							Disc8271_reset();
						}
					}
					break;

				case SDL_KEYUP:
					
					if (! mainWin->OnScreenKeyboardShown()) {
						if (event.key.keysym.sym == SDLK_UP)
							{
							keysym = gp2xButtonToSDLK(GP2X_BUTTON_UP);
							HandleButtonPressForKeysym(event.type == SDL_KEYDOWN, keysym);
							}
						if (event.key.keysym.sym == SDLK_DOWN)
							{
							keysym = gp2xButtonToSDLK(GP2X_BUTTON_DOWN);
							HandleButtonPressForKeysym(event.type == SDL_KEYDOWN, keysym);
							}
						if (event.key.keysym.sym == SDLK_LEFT)
							{
							keysym = gp2xButtonToSDLK(GP2X_BUTTON_LEFT);
							HandleButtonPressForKeysym(event.type == SDL_KEYDOWN, keysym);
							}
						if (event.key.keysym.sym == SDLK_RIGHT)
							{
							keysym = gp2xButtonToSDLK(GP2X_BUTTON_RIGHT);
							HandleButtonPressForKeysym(event.type == SDL_KEYDOWN, keysym);
							}
						if (event.key.keysym.sym == SDLK_LCTRL)
							{
							keysym = gp2xButtonToSDLK(GP2X_BUTTON_A);
							HandleButtonPressForKeysym(event.type == SDL_KEYDOWN, keysym);
							}
						if (event.key.keysym.sym == SDLK_LALT)
							{
							keysym = gp2xButtonToSDLK(GP2X_BUTTON_B);
							HandleButtonPressForKeysym(event.type == SDL_KEYDOWN, keysym);
							}
						if (event.key.keysym.sym == SDLK_SPACE)
							{
							keysym = gp2xButtonToSDLK(GP2X_BUTTON_X);
							HandleButtonPressForKeysym(event.type == SDL_KEYDOWN, keysym);
							}
						if (event.key.keysym.sym == SDLK_LSHIFT)
							{
							keysym = gp2xButtonToSDLK(GP2X_BUTTON_Y);
							HandleButtonPressForKeysym(event.type == SDL_KEYDOWN, keysym);
							}
						if (event.key.keysym.sym == SDLK_RETURN)
							{
							keysym = gp2xButtonToSDLK(GP2X_BUTTON_START);
							HandleButtonPressForKeysym(event.type == SDL_KEYDOWN, keysym);
							}
						if (event.key.keysym.sym == SDLK_ESCAPE)
							{
							keysym = gp2xButtonToSDLK(GP2X_BUTTON_SELECT);
							HandleButtonPressForKeysym(event.type == SDL_KEYDOWN, keysym);
							}
//						if ( ConvertSDLKeyToBBCKey(event.key.keysym.sym, &beeb_key_column, &beeb_key_row) )
//							BeebKeyUp(beeb_key_row, beeb_key_column);
					}

					break;

			/* Handle GP2x buttons:
	 	 	 */
#ifdef GP2X
                        case SDL_JOYBUTTONDOWN:


/* Handle UP:
 */


				/* Volume:
				 */
				if (event.jbutton.button == GP2X_BUTTON_VOLUP) {
					if (gp2xButtonToSDLK(event.jbutton.button) == KEY_USEASVOLUME) 
						if (OSS_Mixer_GetVolume()<100)
							OSS_Mixer_SetVolume(OSS_Mixer_GetVolume()+10);
				} else if (event.jbutton.button == GP2X_BUTTON_VOLDOWN) {
					if (gp2xButtonToSDLK(event.jbutton.button) == KEY_USEASVOLUME)
						if (OSS_Mixer_GetVolume()>0)
							OSS_Mixer_SetVolume(OSS_Mixer_GetVolume()-10);
				}

				// There should be no 'break;' here, I want it to drop through.
                        case SDL_JOYBUTTONUP:


///////////////////////////////////////////////////////////////////////////////
					if (event.jbutton.button == GP2X_BUTTON_START && event.type == SDL_JOYBUTTONUP) {
						if (mainWin->OnScreenKeyboardShown()) {
							mainWin->HideOnScreenKeyboard();
							cls();
						} else {
							AllButtonsUp();
							Button_Reset();
							mainWin->ShowOnScreenKeyboard();
							VirtualKeyboard_Render();
						}
					}
//////////////////////////////////////////////////////////////////////////////

				if (! mainWin->OnScreenKeyboardShown()) {

                                        // Reset shift state if it was set by Run Disc
					// [TODO] Make this timer based.
                                        if (mainWin->ShiftBooted)
                                        {
                                                mainWin->ShiftBooted = false;
                                                BeebKeyUp(0, 0);
                                        }


				if (StickManager_GetMode()!=STICKMODE_CRITICAL) {



					/* Handle none stick buttons the old way:
 					 */
					if (event.jbutton.button == GP2X_BUTTON_A ||
                                                        event.jbutton.button == GP2X_BUTTON_B ||
                                                        event.jbutton.button == GP2X_BUTTON_X ||
                                                        event.jbutton.button == GP2X_BUTTON_Y ||

							event.jbutton.button == GP2X_BUTTON_CLICK ||
							event.jbutton.button == GP2X_BUTTON_L ||
							event.jbutton.button == GP2X_BUTTON_R ||
							event.jbutton.button == GP2X_BUTTON_VOLUP ||
							event.jbutton.button == GP2X_BUTTON_VOLDOWN ||

                                                        event.jbutton.button == GP2X_BUTTON_SELECT)
                                                {
                                                        keysym = gp2xButtonToSDLK(event.jbutton.button);
                                                        HandleButtonPressForKeysym(event.type == SDL_JOYBUTTONDOWN, keysym);
                                                }

 

				// [TODO] This does not take into account 'flipped mode'
					if (event.type == SDL_JOYBUTTONDOWN) {
						switch (event.jbutton.button) {
						case GP2X_BUTTON_LEFT:
							printf("-----------------> up LEFT\n");
							if (! mainWin->ScreenIsReversed()) StickManager_Left(0); else StickManager_Right(0);
							break;
						case GP2X_BUTTON_RIGHT:
							printf("-----------------> up RIGHT\n");
							if (! mainWin->ScreenIsReversed()) StickManager_Right(0); else StickManager_Left(0);
							break;
						case GP2X_BUTTON_UP:
							printf("-----------------> up UP\n");
							if (! mainWin->ScreenIsReversed()) StickManager_Up(0); else StickManager_Down(0);
							break;
						case GP2X_BUTTON_DOWN:
							printf("-----------------> up DOWN\n");
							if (! mainWin->ScreenIsReversed()) StickManager_Down(0); else StickManager_Up(0);
							break;

						case GP2X_BUTTON_UPLEFT:
							printf("-----------------> up UPLEFT\n");
							if (! mainWin->ScreenIsReversed()) StickManager_UpLeft(0); else StickManager_DownRight(0);
							break;
						case GP2X_BUTTON_UPRIGHT:
							printf("-----------------> up UPRIGHT\n");
							if (! mainWin->ScreenIsReversed()) StickManager_UpRight(0); else StickManager_DownLeft(0);
							break;
						case GP2X_BUTTON_DOWNLEFT:
							printf("-----------------> up DOWNLEFT\n");
							if (! mainWin->ScreenIsReversed()) StickManager_DownLeft(0); else StickManager_UpRight(0);
							break;
						case GP2X_BUTTON_DOWNRIGHT:
							printf("-----------------> up DOWNRIGHT\n");
							if (! mainWin->ScreenIsReversed()) StickManager_DownRight(0); else StickManager_UpLeft(0);
							break;

						default:
							break;

						}
					}

					if (event.type == SDL_JOYBUTTONUP) {
	
						switch (event.jbutton.button) {
						case GP2X_BUTTON_LEFT:
							printf("-----------------> down LEFT\n");
							if (! mainWin->ScreenIsReversed()) StickManager_Left(1); else StickManager_Right(1);
							break;
						case GP2X_BUTTON_RIGHT:
							printf("-----------------> down RIGHT\n");
							if (! mainWin->ScreenIsReversed()) StickManager_Right(1); else StickManager_Left(1);
							break;
						case GP2X_BUTTON_UP:
							printf("-----------------> down UP\n");
							if (! mainWin->ScreenIsReversed()) StickManager_Up(1); else StickManager_Down(1);
							break;
						case GP2X_BUTTON_DOWN:
							printf("-----------------> down DOWN\n");
							if (! mainWin->ScreenIsReversed()) StickManager_Down(1); else StickManager_Up(1);
							break;
	
						case GP2X_BUTTON_UPLEFT:
							printf("-----------------> down UPLEFT\n");
							if (! mainWin->ScreenIsReversed()) StickManager_UpLeft(1); else StickManager_DownRight(1);
							break;
						case GP2X_BUTTON_UPRIGHT:
							printf("-----------------> down UPRIGHT\n");
							if (! mainWin->ScreenIsReversed()) StickManager_UpRight(1); else StickManager_DownLeft(1);
							break;
						case GP2X_BUTTON_DOWNLEFT:
							printf("-----------------> down DOWNLEFT\n");
							if (! mainWin->ScreenIsReversed()) StickManager_DownLeft(1); else StickManager_UpRight(1);
							break;
						case GP2X_BUTTON_DOWNRIGHT:
							printf("-----------------> down DOWNRIGHT\n");
							if (! mainWin->ScreenIsReversed()) StickManager_DownRight(1); else StickManager_UpLeft(1);
							break;
	
						default:
							break;
	
						}
					}

		

				} else {


                                        if (event.jbutton.button == GP2X_BUTTON_START)
                                        {
						break;
                                        }
                                        else
                                        {
                         //                       if (	event.jbutton.button == GP2X_BUTTON_LEFT ||
                         //                               event.jbutton.button == GP2X_BUTTON_RIGHT ||
                         //                               event.jbutton.button == GP2X_BUTTON_UP ||
                         //                               event.jbutton.button == GP2X_BUTTON_DOWN)
                         //                       {
                         //                               //printf("hit ordinal\n");
                         //                               keysym = gp2xButtonToSDLK(event.jbutton.button);
                         //                               //AllDirectionButtonsUp();
                         //                               ordinalHit = 1;
                         //                               HandleButtonPressForKeysym(event.type == SDL_JOYBUTTONDOWN, keysym);
                         //                       }

						if ( event.jbutton.button == GP2X_BUTTON_LEFT ) {
							if (! mainWin->ScreenIsReversed())
								keysym = gp2xButtonToSDLK(GP2X_BUTTON_LEFT);
							else
								keysym = gp2xButtonToSDLK(GP2X_BUTTON_RIGHT);
							ordinalHit = 1;
							HandleButtonPressForKeysym(event.type == SDL_JOYBUTTONDOWN, keysym);
						} else if ( event.jbutton.button == GP2X_BUTTON_RIGHT ) {
							if (! mainWin->ScreenIsReversed())
								keysym = gp2xButtonToSDLK(GP2X_BUTTON_RIGHT);
							else
								keysym = gp2xButtonToSDLK(GP2X_BUTTON_LEFT);
							ordinalHit = 1;
							HandleButtonPressForKeysym(event.type == SDL_JOYBUTTONDOWN, keysym);
						} else if ( event.jbutton.button == GP2X_BUTTON_UP ) {
							if (! mainWin->ScreenIsReversed())
								keysym = gp2xButtonToSDLK(GP2X_BUTTON_UP);
							else
								keysym = gp2xButtonToSDLK(GP2X_BUTTON_DOWN);
							ordinalHit = 1;
							HandleButtonPressForKeysym(event.type == SDL_JOYBUTTONDOWN, keysym);
						} else if ( event.jbutton.button == GP2X_BUTTON_DOWN ) {
							if (! mainWin->ScreenIsReversed())
								keysym = gp2xButtonToSDLK(GP2X_BUTTON_DOWN);
							else
								keysym = gp2xButtonToSDLK(GP2X_BUTTON_UP);
							ordinalHit = 1;
							HandleButtonPressForKeysym(event.type == SDL_JOYBUTTONDOWN, keysym);
						}

                                                else if (event.jbutton.button == GP2X_BUTTON_A ||
                                                        event.jbutton.button == GP2X_BUTTON_B ||
                                                        event.jbutton.button == GP2X_BUTTON_X ||
                                                        event.jbutton.button == GP2X_BUTTON_Y ||

							event.jbutton.button == GP2X_BUTTON_CLICK ||
							event.jbutton.button == GP2X_BUTTON_L ||
							event.jbutton.button == GP2X_BUTTON_R ||
							event.jbutton.button == GP2X_BUTTON_VOLUP ||
							event.jbutton.button == GP2X_BUTTON_VOLDOWN ||

                                                        event.jbutton.button == GP2X_BUTTON_SELECT)
                                                {
                                                        keysym = gp2xButtonToSDLK(event.jbutton.button);
                                                        HandleButtonPressForKeysym(event.type == SDL_JOYBUTTONDOWN, keysym);
                                                }

                                                if (event.jbutton.button == GP2X_BUTTON_UPLEFT)
                                                {
                                                        //printf("hit upleft\n");

                                                        if (!ordinalHit)
                                                                AllDirectionButtonsUp();

                                                        if (SDL_JoystickGetButton(joystick_p, GP2X_BUTTON_LEFT))
                                                        {
                                                                // weight it towards left
								if (! mainWin->ScreenIsReversed()) {
                                                                	HandleButtonPress(1, JOY_LEFT);
                                                                	HandleButtonPress(0, JOY_UP);
								} else {
									HandleButtonPress(1, R_JOY_RIGHT);
									HandleButtonPress(0, R_JOY_DOWN);
								}
                                                                //printf("weighted left\n");
                                                        }
                                                        else if (SDL_JoystickGetButton(joystick_p, GP2X_BUTTON_UP))
                                                        {
                                                                // weight it towards up
								if (! mainWin->ScreenIsReversed()) {
                                                                	HandleButtonPress(1, JOY_UP);
                                                                	HandleButtonPress(0, JOY_LEFT);
								} else {
									HandleButtonPress(1, R_JOY_DOWN);
									HandleButtonPress(0, R_JOY_RIGHT);
								}
                                                                //printf("weighted up\n");
                                                        }
                                                        else
                                                        {
                                                                // do both
								if (! mainWin->ScreenIsReversed()) {
                                                                	HandleButtonPress(event.type == SDL_JOYBUTTONDOWN, JOY_UP);
                                                                	HandleButtonPress(event.type == SDL_JOYBUTTONDOWN, JOY_LEFT);
								} else {
									HandleButtonPress(event.type == SDL_JOYBUTTONDOWN, R_JOY_DOWN);
									HandleButtonPress(event.type == SDL_JOYBUTTONDOWN, R_JOY_RIGHT);
								}
                                                        }
                                                }
                                                else if (event.jbutton.button == GP2X_BUTTON_UPRIGHT)
                                                {
                                                        //printf("hit upright\n");
                                                        if (!ordinalHit)
                                                                AllDirectionButtonsUp();

                                                        if (SDL_JoystickGetButton(joystick_p, GP2X_BUTTON_RIGHT))
                                                        {
                                                                // weight it towards right
								if (! mainWin->ScreenIsReversed()) {
									HandleButtonPress(1, JOY_RIGHT);
                                                                	HandleButtonPress(0, JOY_UP);
								} else {
									HandleButtonPress(1, R_JOY_LEFT);
									HandleButtonPress(0, R_JOY_DOWN);
								}
                                                                //printf("weighted right\n");
                                                        }
                                                        else if (SDL_JoystickGetButton(joystick_p, GP2X_BUTTON_UP))
                                                        {
                                                                // weight it towards up
								if (! mainWin->ScreenIsReversed()) {
                                                                	HandleButtonPress(1, JOY_UP);
                                                                	HandleButtonPress(0, JOY_RIGHT);
								} else {
									HandleButtonPress(1, R_JOY_DOWN);
									HandleButtonPress(0, R_JOY_LEFT);
								}
                                                                //printf("weighted up\n");
                                                        }
                                                        else
                                                        {
								if (! mainWin->ScreenIsReversed()) {
                                                                	HandleButtonPress(event.type == SDL_JOYBUTTONDOWN, JOY_UP);
                                                                	HandleButtonPress(event.type == SDL_JOYBUTTONDOWN, JOY_RIGHT);
								} else {
									HandleButtonPress(event.type == SDL_JOYBUTTONDOWN, R_JOY_DOWN);
									HandleButtonPress(event.type == SDL_JOYBUTTONDOWN, R_JOY_LEFT);
								}
                                                        }
                                                }
                                                else if (event.jbutton.button == GP2X_BUTTON_DOWNLEFT)
                                                {
                                                        //printf("hit downleft\n");
                                                        if (!ordinalHit)
                                                                AllDirectionButtonsUp();

                                                        if (SDL_JoystickGetButton(joystick_p, GP2X_BUTTON_LEFT))
                                                        {
                                                                // weight it towards left
								if (! mainWin->ScreenIsReversed()) {
                                                                	HandleButtonPress(1, JOY_LEFT);
                                                                	HandleButtonPress(0, JOY_DOWN);
								} else {
									HandleButtonPress(1, R_JOY_RIGHT);
									HandleButtonPress(0, R_JOY_UP);
								}
                                                                //printf("weighted left\n");
                                                        }
                                                        else if (SDL_JoystickGetButton(joystick_p, GP2X_BUTTON_DOWN))
                                                        {
                                                                // weight it towards down
								if (! mainWin->ScreenIsReversed()) {
                                                                	HandleButtonPress(1, JOY_DOWN);
                                                                	HandleButtonPress(0, JOY_LEFT);
								} else {
									HandleButtonPress(1, R_JOY_UP);
									HandleButtonPress(0, R_JOY_RIGHT);
								}
                                                                //printf("weighted down\n");
                                                        }
                                                        else
                                                        {
								if (! mainWin->ScreenIsReversed()) {
                                                                	HandleButtonPress(event.type == SDL_JOYBUTTONDOWN, JOY_DOWN);
                                                                	HandleButtonPress(event.type == SDL_JOYBUTTONDOWN, JOY_LEFT);
								} else {
									HandleButtonPress(event.type == SDL_JOYBUTTONDOWN, R_JOY_UP);
									HandleButtonPress(event.type == SDL_JOYBUTTONDOWN, R_JOY_RIGHT);
								}
                                                        }

                                                }
                                                else if (event.jbutton.button == GP2X_BUTTON_DOWNRIGHT)
                                                {
                                                        //printf("hit downright\n");

                                                        if (!ordinalHit)
                                                                AllDirectionButtonsUp();

                                                        if (SDL_JoystickGetButton(joystick_p, GP2X_BUTTON_RIGHT))
                                                        {
                                                                // weight it towards right
								if (! mainWin->ScreenIsReversed()) {
                                                                	HandleButtonPress(event.type == SDL_JOYBUTTONDOWN, JOY_RIGHT);
                                                                	HandleButtonPress(0, JOY_DOWN);
								} else {
									HandleButtonPress(event.type == SDL_JOYBUTTONDOWN, R_JOY_LEFT);
									HandleButtonPress(0, R_JOY_UP);
								}
                                                                //printf("weighted right\n");
                                                        }
                                                        else if (SDL_JoystickGetButton(joystick_p, GP2X_BUTTON_DOWN))
                                                        {
                                                                // weight it towards down
								if (! mainWin->ScreenIsReversed()) {
                                                                	HandleButtonPress(event.type == SDL_JOYBUTTONDOWN, JOY_DOWN);
                                                                	HandleButtonPress(0, JOY_RIGHT);
								} else {
									HandleButtonPress(event.type == SDL_JOYBUTTONDOWN, R_JOY_UP);
									HandleButtonPress(0, R_JOY_LEFT);
								}
                                                                //printf("weighted down\n");
                                                        }
                                                        else
                                                        {
								if (! mainWin->ScreenIsReversed()) {
                                                                	HandleButtonPress(event.type == SDL_JOYBUTTONDOWN, JOY_DOWN);
                                                                	HandleButtonPress(event.type == SDL_JOYBUTTONDOWN, JOY_RIGHT);
								} else {
									HandleButtonPress(event.type == SDL_JOYBUTTONDOWN, R_JOY_UP);
									HandleButtonPress(event.type == SDL_JOYBUTTONDOWN, R_JOY_LEFT);
								}
                                                        }
                                                }

                                        }

				}


//======================================================================================================


			


//======================================================================================================



                                        if (keysym != 0)
                                        {
                                                if(row==-2)
                                                {
	                                              Init6502core();
        	                                      Disc8271_reset();
                                                }


                                        }
                                }
                                break;
#endif

			}

			// Virtual keyboard:
			if (mainWin->OnScreenKeyboardShown()) {

				printf("got here\n");

				/* If it's not a user event, process it. If it is a user event then check for navigation:
				 */
				if (event.type != SDL_USEREVENT) {
					printf("calling button_translateevent\n");
					Button_TranslateEvent(&event, mainWin->ScreenIsReversed());
				} else {
					printf("user event %d\n", (int) ((intptr_t) event.user.data1));

					switch ( (int) ((intptr_t) event.user.data1) ) {

					case SDL_USEREVENT_BUTTON_QUIT:
//						done=1;

                                                mainWin->ShiftBooted = false;
                                                BeebKeyUp(0, 0);





                                                BeebEmPages_ShowMenu();
						cls();

						if (mainWin->OnScreenKeyboardShown())
							mainWin->HideOnScreenKeyboard();
							//VirtualKeyboard_Render();

						break;

					case SDL_USEREVENT_BUTTON_LEFT:
						printf("left\n");
						VirtualKeyboard_MoveLeft();
						break;

					case SDL_USEREVENT_BUTTON_RIGHT:
						printf("right\n");
						VirtualKeyboard_MoveRight();
						break;

					case SDL_USEREVENT_BUTTON_UP:
						printf("up\n");
						VirtualKeyboard_MoveUp();
						break;

					case SDL_USEREVENT_BUTTON_DOWN:
						printf("down\n");
						VirtualKeyboard_MoveDown();
						break;

//					case SDL_USEREVENT_BUTTON_CLICK:
//						key_pressed_delay = 10*4;
//						VirtualKeyboard_KeyDown();
//						break;


					case SDL_USEREVENT_BUTTON_CLICK_DOWN:
						VirtualKeyboard_KeyDown();
						break;

					case SDL_USEREVENT_BUTTON_CLICK_UP:
						VirtualKeyboard_KeyUp();
						break;
					}
				}
			}




		}

		/* Actually will exec. approx. half a frame of cycles (good
		 * enough hack for now).
		 */
		Exec6502Instruction();

		/* Handle autorepeat for virtual keyboard:
	 	 */
		if (mainWin->OnScreenKeyboardShown())
			Button_RaiseAutoRepeatEvents();

//		/* Handle release of virtual key:
//		 */
//		if (key_pressed_delay > 0) {
//			if (--key_pressed_delay == 0) {
//				VirtualKeyboard_KeyUp();
//			}
//		}

		if (mainWin->OnScreenKeyboardShown()) {
			if (--caps_flash < 0) {
	                	VirtualKeyboard_UpdateLEDs();
				caps_flash=5;
			}
		}

	} while (! done);





	EXIT(0);
}
