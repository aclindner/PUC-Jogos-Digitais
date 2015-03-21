#pragma once
#include "ASubject.h"
class DummyProduct :
	public ASubject
{
public:
	DummyProduct(string name);
	~DummyProduct();
	void changePrice(float price);
};

