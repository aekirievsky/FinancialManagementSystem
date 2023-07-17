#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Card.h"
#include<vector>
#include<ctime>
#include <fstream>
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
		int i{};
		for (auto& el : cards) {
			std::cout << "Card: " << i + 1 << std::endl
				<< el << std::endl;
			i++;
		}
	}

	void pushCard(Card card) {
		this->cards.push_back(card);
	}

	void deleteCard(int index) {
		this->cards.erase(cards.begin() + index);
	}

	std::string getDate() {
		/*std::time_t rawtime;
		std::tm* timeinfo;
		char buffer[80];

		std::time(&rawtime);
		timeinfo = std::localtime(&rawtime);

		std::strftime(buffer, 80, "%Y-%m-%d", timeinfo);
		std::puts(buffer);*/
		std::cout << "Enter date in format Y-M-D: ";
		std::string date;
		std::cin >> date;
		return date;
	}

	void pushDebetCards(int index) {
		int key{};
		double sum{};
		std::string date;
		std::cout << "Enter sum: ";
		std::cin >> sum;
		date = getDate();

		std::cout << "Categories: " << std::endl
			<< "1 - Products" << std::endl
			<< "2 - Gasoline" << std::endl
			<< "3 - Communal Services" << std::endl
			<< "Choice categories: ";
		std::cin >> key;
		Products products(sum, date);
		Gasoline gasoline(sum, date);
		CommunalServices comServ(sum, date);
		switch (key) {
		case 1:
			cards[index].pushDebet(products);
			break;
		case 2:
			cards[index].pushDebet(gasoline);
			break;
		case 3:
			cards[index].pushDebet(comServ);
			break;
		}
	}

	void pushCreditCards(int index) {
		double sum{};
		//std::string date;
		std::cout << "Enter sum: ";
		std::cin >> sum;
		//date = getDate();
		Debet deb(sum, "");
		cards[index].pushCredits(deb);
	}

	void getCostReport(int index, std::string startDate, std::string endDate) {
		cards[index].costRating(startDate, endDate);
	}

	void getCostRating(int index, std::string startDate, std::string endDate) {
		cards[index].costRating(startDate, endDate);
	}

	void getCardBalance(int index) {
		double bal = cards[index].getBalance();
		std::cout << "Balance = " << bal << std::endl;
	}

	void saveToFile() {
		/*std::string startDate{}, endDate{};
		showBankInformation();
		cout << "Enter start date in format Y-M-D: ";
		cin >> startDate;
		cout << "Enter end date in format Y-M-D: ";
		cin >> endDate;*/

		std::ofstream save;
		save.open("Report and Raiting.txt");
		if (save.is_open()) {
			save << bankName << std::endl;
			for (int i = 0; i < cards.size(); i++)
			{
				save << cards[i] << std::endl;
				//<< cards[i].costRating(startDate, endDate) << std::endl;
			}
		}
		save.close();
		std::cout << "File is save" << std::endl;
	}

	~Bank() {
		cards.clear();
		bankName.clear();
	}
};

