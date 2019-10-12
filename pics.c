/*
 *
 */

#include <ncurses.h>

int main()
{
    initscr();
    // start_color();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    int maxx; int maxy;
    getmaxyx(stdscr, maxy, maxx);

    WINDOW* win = newwin(maxy, maxx, 0, 0);
    wrefresh(win);

    delwin(win);
    endwin();
    return 1;
}
