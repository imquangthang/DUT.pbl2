#include "Shift.h"

Shift::Shift()
{
	this->shift_number = SHIFT::Shift_1;
	this->status_change_shift = false;
	this->B_Change_Shift.SetButtonRect(650, 755);
	this->B_Current_Shift.SetButtonRect(650, 58);
	this->B_CloseChangeShift.SetButtonRect(960, 110);
	this->B_Shift1.SetButtonRect(556, 180);
	this->B_Shift2.SetButtonRect(723, 180);
	this->B_Shift3.SetButtonRect(890, 180);
}

Shift::~Shift()
{
	
}

void Shift::ShowShift(SDL_Renderer* des)
{
	if(this->shift_number == SHIFT::Shift_1)
		this->B_Current_Shift.LoadImg(Button_Shift1, des);
	else if(this->shift_number == SHIFT::Shift_2)
		this->B_Current_Shift.LoadImg(Button_Shift2, des);
	else this->B_Current_Shift.LoadImg(Button_Shift3, des);
	this->B_Current_Shift.Render(des);

	this->B_Change_Shift.LoadImg(Button_Shift_Change, des);
	this->B_Change_Shift.Render(des);
}

bool Shift::CheckChangeShift(SDL_Event events)
{
	if (this->B_Change_Shift.CheckMouse(events))
		this->status_change_shift = true;
	return this->status_change_shift;
}

bool Shift::CheckSelectShift(SDL_Event events)
{
	if (this->B_Shift1.CheckMouse(events))
		return this->shift_number = SHIFT::Shift_1;
	else if (this->B_Shift2.CheckMouse(events))
		return this->shift_number = SHIFT::Shift_2;
	else if (this->B_Shift3.CheckMouse(events))
		return this->shift_number = SHIFT::Shift_3;

	return false;
}

bool Shift::CheckCloseChangeShift(SDL_Event events)
{
	if (this->B_CloseChangeShift.CheckMouse(events) || CheckSelectShift(events))
		this->status_change_shift = false;

	return !this->status_change_shift;
}


void Shift::ShowBgChangeShift(BaseObject& CS_bg, SDL_Renderer* des)
{
	if (this->status_change_shift)
	{
		//show background
		CS_bg.Render(des, NULL);

		//show button close
		this->B_CloseChangeShift.LoadImg(Button_Remove, des);
		this->B_CloseChangeShift.Render(des);

		//show button Shift
		this->B_Shift1.LoadImg(Button_Shift1, des);
		this->B_Shift1.Render(des);

		this->B_Shift2.LoadImg(Button_Shift2, des);
		this->B_Shift2.Render(des);

		this->B_Shift3.LoadImg(Button_Shift3, des);
		this->B_Shift3.Render(des);
		
	}
}