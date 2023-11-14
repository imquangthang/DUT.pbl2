#include "Shift.h"

Shift::Shift(std::string time_check_in) : CheckIn(time_check_in)
{
	this->shift_number = SHIFT::Shift_1;
	this->status_change_shift = false;
	this->B_Change_Shift.SetButtonRect(650, 755);
	this->B_Current_Shift.SetButtonRect(650, 58);
	this->B_CloseChangeShift.SetButtonRect(960, 110);
	this->B_Shift1.SetButtonRect(556, 180);
	this->B_Shift2.SetButtonRect(723, 180);
	this->B_Shift3.SetButtonRect(890, 180);
	this->CheckOut = "";
	this->TotalPriceOfShift = 0;
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

bool Shift::CheckSelectShift(SDL_Event events, std::string time)
{
	int tmp = this->shift_number;
	if (this->B_Shift1.CheckMouse(events))
	{
		if (tmp == SHIFT::Shift_1)
		{
			MessageBox(NULL, L"Đây là Ca làm việc hiện tại!!!", L"Thông Báo", MB_OK | MB_ICONSTOP);
			return false;
		}
		else
		{
			MessageBox(NULL, L"Đã đổi sang Ca 1", L"Thông Báo", MB_OK | MB_ICONSTOP);
			//set time and add to file
			this->CheckOut = time;
			AddToFile();
			this->CheckIn = time;

			return this->shift_number = SHIFT::Shift_1;
		}
	}
	else if (this->B_Shift2.CheckMouse(events))
	{
		if (tmp == SHIFT::Shift_2)
		{
			MessageBox(NULL, L"Đây là Ca làm việc hiện tại!!!", L"Thông Báo", MB_OK | MB_ICONSTOP);
			return false;
		}
		else
		{
			MessageBox(NULL, L"Đã đổi sang Ca 2", L"Thông Báo", MB_OK | MB_ICONSTOP);
			//set time and add to file
			this->CheckOut = time;
			AddToFile();
			this->CheckIn = time;

			return this->shift_number = SHIFT::Shift_2;
		}
	}
	else if (this->B_Shift3.CheckMouse(events))
	{
		if (tmp == SHIFT::Shift_3)
		{
			MessageBox(NULL, L"Đây là Ca làm việc hiện tại!!!", L"Thông Báo", MB_OK | MB_ICONSTOP);
			return false;
		}
		else
		{
			MessageBox(NULL, L"Đã đổi sang Ca 3", L"Thông Báo", MB_OK | MB_ICONSTOP);
			//set time and add to file
			this->CheckOut = time;
			AddToFile();
			this->CheckIn = time;

			return this->shift_number = SHIFT::Shift_3;
		}
	}

	return false;
}

bool Shift::CheckCloseChangeShift(SDL_Event events, std::string time)
{
	if (this->B_CloseChangeShift.CheckMouse(events) || CheckSelectShift(events, time))
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

void Shift::AddPrice(const int& price)
{
	this->TotalPriceOfShift += price;
}

void Shift::AddToFile()
{
	std::ofstream outFile;
	outFile.open(Shift_History, std::ios::app);
	if (!outFile)
	{
		return;
	}

	outFile << "******************************************" << std::endl;
	outFile << "CA: " << this->shift_number << std::endl;
	outFile << "Gio Check In: " << this->CheckIn << std::endl;
	outFile << "Gio Check Out: " << this->CheckOut << std::endl;
	outFile << "Tong Tien: " << this->TotalPriceOfShift << std::endl;

	//reset
	this->TotalPriceOfShift = 0;
}