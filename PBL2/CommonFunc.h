#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_

#include <iostream>
#include <windows.h>
#include <cstring>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <fstream>
#include <sstream>
#include <chrono>
#include <ctime>
#include "List.cpp"

static SDL_Window* g_window = NULL;
static SDL_Renderer* g_screen;
static SDL_Event g_event;

//SCREEN
const int SCREEN_WIDTH = 1422;
const int SCREEN_HEIGHT = 800;

const int COLOR_KEY_R = 167;
const int COLOR_KEY_G = 175;
const int COLOR_KEY_B = 180;

const int RENDER_DRAW_COLOR = 0Xff;


const int FRAME_DELAY = 1000 / 60;

//MENU
const int ROW_OF_MENU = 4;
const int COLLUM_OF_MENU = 3;
const int NUMBER_OF_MENU_ON_SCREEN = 12;
const int SPACE_FOR_COLLUM = 250;
const int SPACE_FOR_ROW = 160;
const int FIRST_COLLUM = 650;
const int FIRST_ROW = 100;
const int X_MENU_PAGE = 1020;
const int Y_MENU_PAGE = 760;
const int X_MENU_Add_Food = 1258;
const int Y_MENU_Add_Food = 58;
enum PAUSE
{
	not_pause = 0, 
	pause_payment = 1,
	pause_add_food = 2,
	pause_change_shift = 3,
};

//ORDER
const int NUMBER_OF_ORDER_ON_SCREEN = 12;
const int NUMBER_OF_BILL_ON_SCREEN = 20;

//BUTTON
const int MENU_X_BUTTON_LEFT = 960;
const int MENU_Y_BUTTON_LEFT = 755;
const int MENU_X_BUTTON_RIGHT = 1065;
const int MENU_Y_BUTTON_RIGHT = 755;

const int ORDER_X_BUTTON_LEFT = 230;
const int ORDER_Y_BUTTON_LEFT = 695;
const int ORDER_X_BUTTON_RIGHT = 335;
const int ORDER_Y_BUTTON_RIGHT = 695;
const int ORDER_X_BUTTON_CLOSE_BILL = 960;
const int ORDER_Y_BUTTON_CLOSE_BILL = 50;

const int BILL_X_BUTTON_LEFT = 715;
const int BILL_Y_BUTTON_LEFT = 635;
const int BILL_X_BUTTON_RIGHT = 780;
const int BILL_Y_BUTTON_RIGHT = 635;

//FILE
static char Background_name[] = { "Img//background.png" }; 
static char Background_Bill[] = { "Img//Bill_background.png" };
static char Background_AddFood[] = { "Img//AddFood_background.png" };
static char Background_ChangeShift[] = { "Img//ChangeShift_background.png" };
static char CSDL[] = { "File//CSDL_PBL2.txt" };
static char Payment_History[] = { "File//Payment_History.txt" };
static char Text_Font[] = { "Text Font//times-new-roman.ttf " };
static char Button_Left[] = { "Img//button_left.png" };
static char Button_Right[] = { "Img//button_right.png" };
static char Button_Left_Of_Bill[] = { "Img//button_left_of_bill.png" };
static char Button_Right_Of_Bill[] = { "Img//button_right_of_bill.png" };
static char Button_Remove[] = { "Img//button_remove.png" };
static char Button_Change[] = { "Img//button_change.png" };
static char Button_Payment[] = { "Img//button_payment.png" };
static char Button_In_Bill[] = { "Img//button_in_bill.png" };
static char Button_Freeze[] = { "Img//freeze.png" };
static char Button_Unfreeze[] = { "Img//unfreeze.png" }; 
static char Button_Add_Food[] = { "Img//button_add_food.png" };
static char Button_Poiter[] = { "Img//poiter.png" };

static char Button_Shift1[] = { "Img//SHIFT//shift_1_on.png" };
static char Button_Shift2[] = { "Img//SHIFT//shift_2_on.png" };
static char Button_Shift3[] = { "Img//SHIFT//shift_3_on.png" };
static char Button_Shift_Change[] = { "Img//SHIFT//shift_change.png" };


#endif