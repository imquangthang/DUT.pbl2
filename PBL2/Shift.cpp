#include "Shift.h"

Shift::Shift(std::string time_check_in) : CheckIn(time_check_in)
{
	this->shift_number = 0;
	this->B_Logout.SetButtonRect(650, 755);
	this->B_Current_Shift.SetButtonRect(650, 58);
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

	this->B_Logout.LoadImg(Button_Logout, des);
	this->B_Logout.Render(des);
}

bool Shift::CheckSelectShift(SDL_Event events, std::string time, std::string date)
{
	if (this->B_Shift1.CheckMouse(events))
	{
		MessageBox(NULL, L"Đã Chọn Ca 1", L"Thông Báo", MB_OK | MB_ICONSTOP);
		//set time check in
		this->CheckIn = time;

		return this->shift_number = SHIFT::Shift_1;	
	}
	else if (this->B_Shift2.CheckMouse(events))
	{
		MessageBox(NULL, L"Đã Chọn Ca 2", L"Thông Báo", MB_OK | MB_ICONSTOP);
		//set time check in
		this->CheckIn = time;

		return this->shift_number = SHIFT::Shift_2;
	}
	else if (this->B_Shift3.CheckMouse(events))
	{
		MessageBox(NULL, L"Đã Chọn Ca 3", L"Thông Báo", MB_OK | MB_ICONSTOP);
		//set time check in
		this->CheckIn = time;

		return this->shift_number = SHIFT::Shift_3;
	}

	return false;
}

bool Shift::CheckCloseSelectShift(SDL_Event events, std::string time, std::string date)
{
	if (CheckSelectShift(events, time, date))
		return true;

	return false;
}

bool Shift::CheckLogout(SDL_Event events, std::string time, std::string date, std::string MaNV)
{
	if (this->B_Logout.CheckMouse(events))
	{
		AddToFile(time, date, MaNV);
		MessageBox(NULL, L"Đăng Xuất Thành Công!!!", L"Thông Báo", MB_OK | MB_ICONSTOP);
		return true;
	}
	else return false;
}

void Shift::ShowBgSelectShift(BaseObject& CS_bg, SDL_Renderer* des)
{
	//show background
	CS_bg.Render(des, NULL);

	//show button Shift
	this->B_Shift1.LoadImg(Button_Shift1, des);
	this->B_Shift1.Render(des);

	this->B_Shift2.LoadImg(Button_Shift2, des);
	this->B_Shift2.Render(des);

	this->B_Shift3.LoadImg(Button_Shift3, des);
	this->B_Shift3.Render(des);
}

void Shift::AddPrice(const int& price)
{
	this->TotalPriceOfShift += price;
}

void Shift::AddToFile(std::string time, std::string date, std::string MaNV)
{	
	this->CheckOut = time;
	std::ofstream outFile;
	outFile.open(Payment_History + date + ".txt", std::ios::app);
	if (!outFile)
	{
		return;
	}

	outFile << "******************************************" << std::endl;
	outFile << "Ket Thuc CA: " << this->shift_number << std::endl;
	outFile << "Nhan Vien: " << MaNV << std::endl;
	outFile << "Gio Check In: " << this->CheckIn << std::endl;
	outFile << "Gio Check Out: " << this->CheckOut << std::endl;
	outFile << "Tong Tien: " << this->TotalPriceOfShift << std::endl;

	//reset
	this->TotalPriceOfShift = 0;
}