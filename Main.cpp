#include<iostream>
#include<allegro5\allegro.h>
#include<allegro5\allegro_primitives.h>
using namespace std;

//const and enums
const float FPS = 60;
const int player1_SIZE = 20;
enum MKEYS {
	KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
};
enum DIRECTIONS {RIGHT, LEFT, UP, DOWN};

int main() {

	//matrix
	int grid[50][50];
	for(int i = 0; i < 50; i++)
		for (int j = 0; j < 50; j++) {
			//set all to 0s except edges
			grid[i][j] = 0;
			if (i == 0 || i == 49 || j == 0 || j == 49)
				grid[i][j] = 1;
		}

	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++)
			cout << grid[i][j];
		cout << endl;
	}


	//set up variable
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *player1 = NULL;
	int player1_x = 300;
	int player1_y = 400;
	bool key[4] = { false, false, false, false };
	bool redraw = true;
	bool doexit = false;
	int dx1 = 0;
	int dy1 = 0;
	int dir = 0;

	//allegro stuff
	al_init();
	al_init_primitives_addon();

	al_install_keyboard();

	timer = al_create_timer(1.0 / FPS);
}