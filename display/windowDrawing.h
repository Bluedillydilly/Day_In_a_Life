/*
    Header file for prototypes and possible typedefs.
    File name: windowDrawing.h

    Related to creation and management of windows of curses.
*/

#ifndef wind_h
#define wind_h
#include <ncurses.h> // for windows

/////////////////////////////////
// WINDOW MANAGEMENT FUNCTIONS //
// IE WINDOW FUNCTIONS //////////
/////////////////////////////////

/*
 * 
 */
void borders(WINDOW* win, const char vsc, const char hsc, const char cc);

/*
 * 
 */
void borders_easy(WINDOW* win);

/*
 *  Clears a window.
 *  Sets every character in the window to a blank.
 */ 
void clear_win(WINDOW* win);

/*
 * Clears the center of a window.
 * Sets every character in the window, except the edges to blank.
 */
void clear_win_c(WINDOW* win);

/*
 * Clears the top window.
 * Redraws the border of the bottom window.
 */
void clear_redraw(WINDOW* btm, WINDOW* top);

/*
 *   Title screen. Waits for player to press any button.
 */
void title_screen(WINDOW* win);


/*
 *  Prints title to the upper left hand corner of a window.
 *  Prints title at 1,1 of window.
 *  @param win Window to set the title of.
 *  @param title String to set the window to.
 */
void title_window(WINDOW* win, const char* title);

/////////////////////////////
// END OF WINDOW FUNCTIONS //
/////////////////////////////

#endif