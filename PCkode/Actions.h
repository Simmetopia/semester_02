#pragma once
class Actions
{
public:
	Actions(int& hour, int& minut);
	Actions();
	~Actions();
	void setTime(int& hour, int& minut);

private:
	int hour_, minute_;
};

