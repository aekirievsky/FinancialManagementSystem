#pragma once
#include<iostream>
#include"Card.h"

class CreditCard :public Card
{
public:
	CreditCard() = default;
	CreditCard(
		std::string cardHolder_p,
		unsigned short cardNumber_p[16]
) : Card(cardHolder_p, cardNumber_p) {}



	~CreditCard() = default;
};

