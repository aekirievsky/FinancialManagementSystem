#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"Categories.h"
#include<map>
#include<algorithm>

using std::numeric_limits;
using std::streamsize;


class Card
{
protected:
	std::string cardHolder;
	unsigned short cardNumber[16];
	std::vector<Categories> credits; //ÇÀ×ÈÑËÅÍÈÅ
	std::vector<Categories> debets; //ÑÏÈÑÀÍÈÅ
public:
	Card() = default;
	Card(
		std::string cardHolder_p,
		unsigned short cardNumber_p[16]) :
		cardHolder{ cardHolder_p }, cardNumber{ cardNumber_p[16] } {}

	friend std::ostream& operator<<(std::ostream& out, const Card& other) {
		out << "Card holder: " << other.cardHolder << std::endl
			<< "Card number: ";
		for (int i = 0; i < 16; i++)
		{
			out << other.cardNumber[i];
			if ((i + 1) % 4 == 0 && i != 0) {
				out << " ";
			}
		}

		return out;
	}

	friend std::istream& operator>>(std::istream& input, Card& other) {
		std::cout << "Enter card holder: ";
		input.ignore();
		std::getline(input, other.cardHolder);
		std::cout << "Enter card number: ";

		for (int i = 0; i < 16; i++)
		{
			char number = std::cin.get();
			if (number != ' ')
			{
				other.cardNumber[i] = number - '0';
			}
			else {
				i--;
			}
		}

		std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

		return input;
	}

	/*void putCardInformation() {
		std::cout << "Enter card holder: ";
		std::cin.ignore();
		std::getline(std::cin, cardHolder);
		std::cout << "Enter card number: ";
		for (int i = 0; i < 16; i++)
		{
			std::cin >> cardNumber[i];
		}
	}*/

	double getBalance() {
		double credit{}, debet{};

		for (int i = 0; i < credits.size(); i++)
		{
			credit += credits[i].sum;
		}

		for (int i = 0; i < debets.size(); i++)
		{
			debet += debets[i].sum;
		}

		return credit - debet;
	}

	void pushCredits(Categories categories) {
		credits.push_back(categories);
	}

	void pushDebet(Categories categories) {
		debets.push_back(categories);
	}

	void costRating(std::string startDate, std::string endDate) {
		std::map<std::string, double> report;
		for (int i = 0; i < debets.size(); i++)
		{
			if (debets[i].getDate() >= startDate and debets[i].getDate() <= endDate) {
				if (report.find(debets[i].getName()) == report.end()) {
					report[debets[i].getName()] = debets[i].sum;
				}
				else
				{
					report[debets[i].getName()] += debets[i].sum;
				}
			}
		}

		std::vector<std::pair<std::string, double>> result;
		std::copy(report.begin(), report.end(), std::back_inserter < std::vector<std::pair<std::string, double>>>(result));

		std::sort(result.begin(), result.end(), [](const std::pair<std::string, double>& l, const std::pair < std::string, double>& r) {
			return l.second > r.second;
			});

		for (int i = 0; i < 3; i++)
		{
			std::cout << result[i].first << " " << result[i].second << std::endl;
		}

	}

	void costReport(std::string startDate, std::string endDate) {
		std::map<std::string, double> report;
		for (int i = 0; i < debets.size(); i++)
		{
			if (debets[i].getDate() >= startDate and debets[i].getDate() <= endDate) {
				if (report.find(debets[i].getName()) == report.end()) {
					report[debets[i].getName()] = debets[i].sum;
				}
				else
				{
					report[debets[i].getName()] += debets[i].sum;
				}
			}
		}

		std::vector<std::pair<std::string, double>> result;
		std::copy(report.begin(), report.end(), std::back_inserter < std::vector<std::pair<std::string, double>>>(result));

		std::sort(result.begin(), result.end(), [](const std::pair<std::string, double>& l, const std::pair < std::string, double>& r) {
			return l.second > r.second;
			});

		for (int i = 0; i < result.size(); i++)
		{
			std::cout << result[i].first << " " << result[i].second << std::endl;
		}
	}

	/*void clearCard() {
		cardHolder.clear();
		delete[] cardNumber;
	}*/

	~Card() = default;
};

