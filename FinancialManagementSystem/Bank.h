#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Card.h"
#include<vector>
#include<ctime>
#pragma warning(disable:4996)

class Bank
{
private:
	std::vector<Card> cards;
	std::string bankName;
public:
	Bank() = default;
	Bank(std::vector<Card>cards_p, std::string bankName_p) :cards{ cards_p }, bankName{ bankName_p } {}

	std::string getNameBank() {
		return bankName;
	}
	void setNameBank(std::string bankName_p) {
		this->bankName = bankName_p;
	}

	void showBankInformation() {
		std::cout << "Bank name: " << this->bankName << std::endl
			<< "Information about cards:" << std::endl;
		for (auto& el : cards) {
			std::cout << el << std::endl;
		}
	}

	void pushCard(Card card) {
		this->cards.push_back(card);
	}

	void deleteCard(int index) {
		this->cards.erase(cards.begin() + index);
	}

	char* getDate() {
		std::time_t rawtime;
		std::tm* timeinfo;
		char buffer[80];

		std::time(&rawtime);
		timeinfo = std::localtime(&rawtime);

		std::strftime(buffer, 80, "%Y-%m-%d", timeinfo);
		return buffer;
	}

	void pushDebetCards(int index) {
		int key{};
		double sum{};
		char* date;
		std::cout << "Enter sum: ";
		std::cin >> sum;
		date = getDate();

		std::cout << "Categories: " << std::endl
			<< "1 - Products" << std::endl
			<< "2 - Gasoline" << std::endl
			<< "3 - Communal Services" << std::endl
			<< "Choice categories: ";
		std::cin >> key;

		switch (key) {
		case 1:
			cards[index].pushDebet(Products(sum, date));
			break;
		case 2:
			cards[index].pushDebet(Gasoline(sum, date));
			break;
		case 3:
			cards[index].pushDebet(CommunalServices(sum, date));
			break;
		}
	}

	void pushCreditCards(int index) {
		double sum{};
		char* date;
		std::cout << "Enter sum: ";
		std::cin >> sum;
		date = getDate();
		cards[index].pushCredits(Debet(sum, date));
	}

	void getCostReport(int index, std::string startDate, std::string endDate) {
		cards[index].costRating(startDate, endDate);
	}

	void getCostRating(int index, std::string startDate, std::string endDate) {
		cards[index].costRating(startDate, endDate);
	}


	~Bank() {
		cards.clear();
		bankName.clear();
	}
};

