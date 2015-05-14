#pragma once
#include <iostream>

class RandomGene
{
public:
	const int random(int k, int c)
	{
		srand(rand() % k + c);
	}
private:
	int k, c;

};