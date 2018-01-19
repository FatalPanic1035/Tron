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

	display = al_create_display(500, 500);

	player1 = al_create_bitmap(player1_SIZE, player1_SIZE);

	al_set_target_bitmap(player1);

	al_clear_to_color(al_map_rgb(255, 0, 255));

	al_set_target_bitmap(al_get_backbuffer(display));

	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();

	al_start_timer(timer);

	//game loop
	while (!doexit)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) { //Beginning of event timer
			if (key[KEY_UP]) {
				dy1 = -1;
				dx1 = 0;
				dir = UP;
			}

			if (key[KEY_DOWN]) {
				dy1 = 1;
				dx1 = 0;
				dir = DOWN;
			}

			if (key[KEY_LEFT]) {
				dx1 = -1;
				dy1 = 0;
				dir = LEFT;
			}

			if (key[KEY_RIGHT]) {
				dx1 = 1;
				dy1 = 0;
				dir = RIGHT;
			}

			//player 1 moves
			player1_x += dx1;
			player1_y += dy1;

			//line drawn behind the player 1
			grid[(player1_x) / 10][(player1_y) / 10] = 2;

			//Right collision for player 1
			if (dir == RIGHT && grid[(player1_x + 10) / 10][player1_y / 10] != 0)
				cout << "LOOOOOOOL" << endl; // add more stuff here lololol

			redraw = true;
		} //End of event timer
		//Program is ded wen X is pressed
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}






	}//end of game loop
}