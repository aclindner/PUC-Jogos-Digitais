#pragma once
class IObserver
{
public:
	virtual void UpdatePrice(float price) = 0;
};