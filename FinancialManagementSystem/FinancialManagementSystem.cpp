#include <iostream>
#include"Bank.h"
#include "DebitCard.h"
#include "CreditCard.h"
#include<string>
#include<Windows.h>

using namespace std;



int main()
{
	int key = -1;
	Bank banks;
	DebitCard debCard;
	CreditCard credCard;
	string bankName{}, startDate{}, endDate{};
	int index{};

	while (key) {
		cout << "MENU:" << endl
			<< "1 - bank information entry;" << endl
			<< "2 - add debit card;" << endl
			<< "3 - add credit card;" << endl
			<< "4 - delete card;" << endl
			<< "5 - add enrollment;" << endl // ЗАЧИСЛЕНИЕ
			<< "6 - add costs;" << endl // РАСХОДЫ
			<< "7 - show cost rating;" << endl
			<< "8 - show cost report;" << endl
			<< "9 - download to a file;" << endl
			<< "10 - show information;" << endl
			<< "11 - get balance" << endl
			<< "0 - exit" << endl
			<< "Your choice: ";
		cin >> key;

		switch (key) {
		case 1:
			cout << "Enter the name of the bank: ";
			cin.ignore();
			getline(cin, bankName);
			banks.setNameBank(bankName);
			banks.showBankInformation();
			break;
		case 2:
			cout << "Add card:" << endl;
			cin >> debCard;
			banks.pushCard(debCard);
			break;
		case 3:
			cout << "Add card:" << endl;
			cin >> credCard;
			banks.pushCard(credCard);
			break;
		case 4:
			banks.showBankInformation();
			cout << "Enter index for delete card: ";
			cin >> index;
			index--;
			banks.deleteCard(index);
			banks.showBankInformation();
			break;
		case 5:
			banks.showBankInformation();
			cout << "Enter index card for add enrollment: ";
			cin >> index;
			index--;
			banks.pushCreditCards(index);
			banks.getCardBalance(index);
			break;
		case 6:
			banks.showBankInformation();
			cout << "Enter index card for add costs: " << endl;
			cin >> index;
			index--;
			banks.pushDebetCards(index);
			banks.getCardBalance(index);
			break;
		case 7:
			banks.showBankInformation();
			cout << "Enter index card for show costs rating: ";
			cin >> index;
			index--;
			cout << "Enter start date in format Y-M-D: ";
			cin >> startDate;
			cout << "Enter end date in format Y-M-D: ";
			cin >> endDate;
			banks.getCostRating(index, startDate, endDate);
			break;
		case 8:
			banks.showBankInformation();
			cout << "Enter index card for show costs rating: ";
			cin >> index;
			index--;
			cout << "Enter start date in format Y-M-D: ";
			cin >> startDate;
			cout << "Enter end date in format Y-M-D: ";
			cin >> endDate;
			banks.getCostReport(index, startDate, endDate);
			break;
		case 9:
			banks.saveToFile();
			break;
		case 10:
			banks.showBankInformation();
			break;
		case 11:
			banks.showBankInformation();
			cout << "Choice card for show balance: ";
			cin >> index;
			index--;
			banks.getCardBalance(index);
			break;
		case 0:
			cout << "Goode bye!" << endl;
			return 0;
		default:
			cout << "Wrong choice! Try again!" << endl;
			break;
		}
		system("pause");
		system("cls");
		index = 0;
	}

	return 0;
}

