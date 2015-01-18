#pragma once

/*
* DEBUGGING
*/
#define SHOW_HIT_BOXES 0

/*
* GAME CONSTANTS
*/

#define GAME_NAME "Block Battle"
#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 500
#define DEAD_ZONE 40

#define FRAME_RATE 60 //frames per second
#define FRAME_PERIOD (1000000 / FRAME_RATE) //microseconds per frame

/*
 * PLAYER CONSTANTS
 */

#define PLAYER_ANIMATION_DELAY 10;

#define PLAYER_STUN_TIME 10
#define PLAYER_BUMP_SPEED 4

#define PLAYER_WIDTH 24
#define PLAYER_HEIGHT 24

#define P1_FACE_D1 "../images/p1_fr1.gif"
#define P1_FACE_D2 "../images/p1_fr2.gif"
#define P1_FACE_U1 "../images/p1_bk1.gif"
#define P1_FACE_U2 "../images/p1_bk2.gif"
#define P1_FACE_R1 "../images/p1_rt1.gif"
#define P1_FACE_R2 "../images/p1_rt2.gif"
#define P1_FACE_L1 "../images/p1_lf1.gif"
#define P1_FACE_L2 "../images/p1_lf2.gif"

#define P2_FACE_D1 "../images/p2_fr1.gif"
#define P2_FACE_D2 "../images/p2_fr2.gif"
#define P2_FACE_U1 "../images/p2_bk1.gif"
#define P2_FACE_U2 "../images/p2_bk2.gif"
#define P2_FACE_R1 "../images/p2_rt1.gif"
#define P2_FACE_R2 "../images/p2_rt2.gif"
#define P2_FACE_L1 "../images/p2_lf1.gif"
#define P2_FACE_L2 "../images/p2_lf2.gif"

//start players in different sides of screen
#define START_PADDING 20
#define P2_START_X ((WINDOW_WIDTH / 3) - (PLAYER_WIDTH / 2) - START_PADDING)
#define P1_START_X ((2 * WINDOW_WIDTH / 3) - (PLAYER_WIDTH / 2) + START_PADDING)

//start players in vertical middle of screen
#define P1_START_Y ((WINDOW_HEIGHT / 2) - (PLAYER_HEIGHT / 2))
#define P2_START_Y P1_START_Y

#define MOVE_SPEED 3.0

/*
* OTHER CONSTANTS
*/

#define P1_BULLET_COLOR 0, 51, 255
#define P2_BULLET_COLOR 255, 102, 0
#define BULLET_SPEED	3.2
#define BULLET_WIDTH	20
#define BULLET_HEIGHT	20
#define BULLET_SPAWN_DISTANCE	2
