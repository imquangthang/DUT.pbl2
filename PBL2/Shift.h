#ifndef SHIFT_H_
#define SHIFT_H_

#include "CommonFunc.h"
#include "Button.h"
#include "FoodAndDrink.h"

class Shift
{
private:
	int shift_number;
	bool status_change_shift;
	std::string CheckIn;
	std::string CheckOut;
	int TotalPriceOfShift;
	Button B_Change_Shift;
	Button B_Current_Shift;
	Button B_Shift1;
	Button B_Shift2;
	Button B_Shift3;
	Button B_CloseChangeShift;

public:

	enum SHIFT
	{
		Shift_1 = 1,
		Shift_2 = 2,
		Shift_3 = 3,
	};
	Shift(std::string = "");
	~Shift();

	void ShowShift(SDL_Renderer*);
	void ShowBgChangeShift(BaseObject&, SDL_Renderer*);
	bool CheckChangeShift(SDL_Event);
	bool CheckSelectShift(SDL_Event, std::string);
	bool CheckCloseChangeShift(SDL_Event, std::string);
	
	int GetShiftNumber() const { return this->shift_number; }

	void AddPrice(const int&);
	void AddToFile();
};



#endif
