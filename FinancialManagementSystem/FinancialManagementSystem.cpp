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
	string bankName{};
	int countDebCards{}, countCredCards{};

	while (key) {
		cout << "MENU:" << endl
			<< "1 - bank information entry;" << endl
			<< "2 - add debit card;" << endl
			<< "3 - add credit card;" << endl
			<< "4 - delete card;" << endl
			<< "5 - show cost rating;" << endl
			<< "6 - show cost report;" << endl
			<< "7 - download to a file;" << endl
			<< "8 - show information;" << endl
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
			/*cout << "How many debit cards do you want to add?" << endl
				<< "Choice: ";
			cin >> countDebCards;
			for (int i = 0; i < countDebCards; i++)
			{
				cin >> debCard;
				banks.pushCard(debCard);

			}*/
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

			break;
		case 5:

			break;
		case 6:

			break;
		case 7:

			break;
		case 8:
			banks.showBankInformation();
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

	}

	return 0;
}

