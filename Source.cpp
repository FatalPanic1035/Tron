#include<iostream>
#include<allegro5\allegro.h>
#include<allegro5\allegro_primitives.h>
using namespace std;

//const and enums
const float FPS = 60;
const int player1_SIZE = 20;
const int player2_SIZE = 20;
enum MKEYS {
	KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
};
enum LKEYS {
	KEY_W, KEY_S, KEY_A, KEY_D
};
enum DIRECTIONS { RIGHT, LEFT, UP, DOWN };
enum LDIRECTIONS { D, A, W, S };

int main() {

	//matrix
	int grid[50][50];
	for (int i = 0; i < 50; i++)
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
	ALLEGRO_BITMAP *player2 = NULL;

	int player1_x = 300;
	int player1_y = 400;

	int player2_x = 150;
	int player2_y = 200;

	bool key[4] = { false, false, false, false };
	bool key2[4] = { false, false, false, false };
	bool redraw = true;
	bool doexit = false;
	int dx1 = 0;
	int dy1 = 0;
	int dx2 = 0;
	int dy2 = 0;
	int dir = 0;
	int dir2 = 0;

	//allegro stuff
	al_init();
	al_init_primitives_addon();

	al_install_keyboard();

	timer = al_create_timer(1.0 / FPS);

	display = al_create_display(500, 550);

	player1 = al_create_bitmap(player1_SIZE, player1_SIZE);
	al_set_target_bitmap(player1);
	al_clear_to_color(al_map_rgb(255, 0, 255));

	player2 = al_create_bitmap(player2_SIZE, player2_SIZE);
	al_set_target_bitmap(player2);
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
				dy1 = -3;
				dx1 = 0;
				dir = UP;
			}

			if (key[KEY_DOWN]) {
				dy1 = 3;
				dx1 = 0;
				dir = DOWN;
			}

			if (key[KEY_LEFT]) {
				dx1 = -3;
				dy1 = 0;
				dir = LEFT;
			}

			if (key[KEY_RIGHT]) {
				dx1 = 3;
				dy1 = 0;
				dir = RIGHT;
			}

			if (key2[KEY_W]) {
				dy2 = -3;
				dx2 = 0;
				dir2 = W;
			}

			if (key2[KEY_S]) {
				dy2 = 3;
				dx2 = 0;
				dir2 = S;
			}

			if (key2[KEY_A]) {
				dx2 = -3;
				dy2 = 0;
				dir2 = A;
			}

			if (key2[KEY_D]) {
				dx2 = 3;
				dy2 = 0;
				dir2 = D;
			}

			//player 1 moves
			player1_x += dx1;
			player1_y += dy1;

			//line drawn behind the player 1
			grid[(player1_x) / 10][(player1_y) / 10] = 2;

			//Right collision for player 1
			if (dir == RIGHT && grid[(player1_x + 10) / 10][player1_y / 10] != 0) {
				grid[(player1_x) / 10][(player1_y) / 10] = 0;
				if (grid[(player1_x) / 10][(player1_y) / 10] == 0) {
				for (int i = 0; i < 50; i++) {
					for (int j = 0; j < 50; j++) {
						grid[i][j] = 0;
					}
				}
			}
				player1_x = 300;
				player1_y = 400;

				cout << "Crash" << endl;
			}

			if (dir == LEFT && grid[(player1_x - 10) / 10][player1_y / 10] != 0) {
				grid[(player1_x) / 10][(player1_y) / 10] = 0;
				if (grid[(player1_x) / 10][(player1_y) / 10] == 0) {
					for (int i = 0; i < 50; i++) {
						for (int j = 0; j < 50; j++) {
							grid[i][j] = 0;
						}
					}
				}
				player1_x = 300;
				player1_y = 400;
				cout << "Crash" << endl;
			}

			if (dir == UP && grid[player1_x / 10][(player1_y - 10) / 10] != 0) {
				grid[(player1_x) / 10][(player1_y) / 10] = 0;
				if (grid[(player1_x) / 10][(player1_y) / 10] == 0) {
					for (int i = 0; i < 50; i++) {
						for (int j = 0; j < 50; j++) {
							grid[i][j] = 0;
						}
					}
				}
				player1_x = 300;
				player1_y = 400;
				cout << "Crash" << endl;
			}

			if (dir == DOWN && grid[player1_x / 10][(player1_y + 10) / 10] != 0) {
				grid[(player1_x) / 10][(player1_y) / 10] = 0;
				if (grid[(player1_x) / 10][(player1_y) / 10] == 0) {
					for (int i = 0; i < 50; i++) {
						for (int j = 0; j < 50; j++) {
							grid[i][j] = 0;
						}
					}
				}
				player1_x = 300;
				player1_y = 400;
				cout << "Crash" << endl;
			}


			player2_x += dx2;
			player2_y += dy2;

			//line drawn behind the player 2
			grid[(player2_x) / 10][(player2_y) / 10] = 2;

			//Right collision for player 2
			if (dir2 == D && grid[(player2_x + 10) / 10][player2_y / 10] != 0) {
				grid[(player2_x) / 10][(player2_y) / 10] = 0;
				if (grid[(player2_x) / 10][(player2_y) / 10] == 0) {
					for (int i = 0; i < 50; i++) {
						for (int j = 0; j < 50; j++) {
							grid[i][j] = 0;
						}
					}
				}
				 player2_x = 150;
				 player2_y = 200;
				cout << "Crash" << endl;
			}

			if (dir2 == A && grid[(player2_x - 10) / 10][player2_y / 10] != 0) {
				grid[(player2_x) / 10][(player2_y) / 10] = 0;
				if (grid[(player2_x) / 10][(player2_y) / 10] == 0) {
					for (int i = 0; i < 50; i++) {
						for (int j = 0; j < 50; j++) {
							grid[i][j] = 0;
						}
					}
				}
				 player2_x = 150;
				 player2_y = 200;
				cout << "Crash" << endl;
			}

			if (dir2 == W && grid[player2_x / 10][(player2_y - 10) / 10] != 0) {
				grid[(player2_x) / 10][(player2_y) / 10] = 0;
				if (grid[(player2_x) / 10][(player2_y) / 10] == 0) {
					for (int i = 0; i < 50; i++) {
						for (int j = 0; j < 50; j++) {
							grid[i][j] = 0;
						}
					}
				}
				player2_x = 150;
				 player2_y = 200;
				cout << "Crash" << endl;
			}

			if (dir2 == S && grid[player2_x / 10][(player2_y + 10) / 10] != 0) {
				grid[(player2_x) / 10][(player2_y) / 10] = 0;
				if (grid[(player2_x) / 10][(player2_y) / 10] == 0) {
					for (int i = 0; i < 50; i++) {
						for (int j = 0; j < 50; j++) {
							grid[i][j] = 0;
						}
					}
				}
				player2_x = 150;
				 player2_y = 200;
				cout << "Crash" << endl;
			}


			redraw = true;
		} //End of event timer
		  //Program is ded wen X is pressed
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		//this is if the key is pressed down
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				if(dir != DOWN)
					key[KEY_UP] = true;
						break;

			case ALLEGRO_KEY_DOWN:
				if(dir != UP)
					key[KEY_DOWN] = true;
						break;

			case ALLEGRO_KEY_LEFT:
				if(dir != RIGHT)
					key[KEY_LEFT] = true;
						break;

			case ALLEGRO_KEY_RIGHT:
				if(dir != LEFT)
					key[KEY_RIGHT] = true;
						break;

			case ALLEGRO_KEY_W:
				if (dir2 != S)
					key2[KEY_W] = true;
						break;

			case ALLEGRO_KEY_S:
				if (dir2 != W)
					key2[KEY_S] = true;
						break;

			case ALLEGRO_KEY_A:
				if (dir2 != D)
					key2[KEY_A] = true;
						break;

			case ALLEGRO_KEY_D:
				if (dir2 != A)
					key2[KEY_D] = true;
						break;

			case ALLEGRO_KEY_ESCAPE:
				doexit = true;
				break;
			}
		}// end of the key down
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key[KEY_UP] = false;
				break;

			case ALLEGRO_KEY_DOWN:
				key[KEY_DOWN] = false;
				break;

			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = false;
				break;

			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = false;
				break;

			case ALLEGRO_KEY_W:
				key2[KEY_W] = false;
				break;

			case ALLEGRO_KEY_S:
				key2[KEY_S] = false;
				break;

			case ALLEGRO_KEY_A:
				key2[KEY_A] = false;
				break;

			case ALLEGRO_KEY_D:
				key2[KEY_D] = false;
				break;

			case ALLEGRO_KEY_ESCAPE:
				doexit = false;
				break;
			}
		}

		//RENDER SECTION
		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			//screen turn black
			al_clear_to_color(al_map_rgb(0, 0, 0));


			//the map, #a is white and #2 is blue
			for (int i = 0; i < 50; i++) {
				for (int j = 0; j < 50; j++) {
					if (grid[i][j] == 1)
						al_draw_filled_rectangle(i * 10, j * 10, i * 10 + 10, j * 10 + 10, al_map_rgb(255, 255, 255));
					if (grid[i][j] == 2)
						al_draw_filled_rectangle(i * 10, j * 10, i * 10 + 10, j * 10 + 10, al_map_rgb(0, 255, 255));
				}
			}

			//draw player
			al_draw_bitmap(player1, player1_x - 10, player1_y - 10, 0);
			al_draw_bitmap(player2, player2_x - 10, player2_y - 10, 0);

			al_flip_display();

		}//end of render section
	}//end of game loop

	al_destroy_bitmap(player1);
	al_destroy_bitmap(player2);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}