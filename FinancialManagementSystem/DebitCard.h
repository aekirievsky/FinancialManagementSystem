#pragma once
#include<iostream>
#include"Card.h"

class DebitCard :public Card
{
public:
	DebitCard() = default;
	DebitCard(
		std::string cardHolder_p,
		unsigned short cardNumber_p[16]
	) : Card(cardHolder_p, cardNumber_p) {}

	friend std::ostream& operator<<(std::ostream& out, const DebitCard& other) {
		out << (Card)other;
		return out;
	}

	friend std::istream& operator>>(std::istream& input, DebitCard& other) {
		std::cout << "Enter card holder: ";
		input.ignore();
		std::getline(input, other.cardHolder);
		std::cout << "Enter card number: ";
		for (int i = 0; i < 16; i++)
		{
			input >> other.cardNumber[i];
		}
		return input;
	}

	~DebitCard() = default;
};

