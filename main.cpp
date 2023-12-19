#include <utility>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Account {

	int dogecoin, bitcoin, ethereum, litecoin, solana;
	int balance;
	int deposit, withdraw;
	int total_equity = 100;
	int predict;
	int dogecoin_value, bitcoin_value, ethereum_value, litecoin_value, solana_value;
	int crypto_invest;
	int value_return;
	vector<pair<string, int> > transactions;
public:
	//deposit money
	bool Deposit(int money)
	{
		deposit += money;
		balance += money;
		transactions.push_back({ "Deposit:", money });
		return true;
	}

	//get account information
	void GetAccountInfo() {
		cout << "Money Details:\n";
		cout << "Bank Balance:	" << balance << endl;
		cout << "Dogecoin:	" << dogecoin << endl;
		cout << "Bitcoin:	" << bitcoin << endl;
		cout << "Ethereum:	" << ethereum << endl;
		cout << "Litecoin:	" << litecoin << endl;
		cout << "Solana:	" << solana << endl;
	}

	//withdraw money
	bool Withdraw(int money) {
		if (money > balance) {
			return false;
		}
		withdraw += money;
		balance -= money;
		transactions.push_back({ "Withdraw:", money });
		return true;
	}

	bool buy_asset() {
		int option;
		int amount;
		cout << "Enter id of asset you want to purchase:\n"
			"dogecoin:	1\n"
			"bitcoin:	2\n"
			"ethereum:	3\n"
			"litecoin:	4\n"
			"solana:	5\n";
		cin >> option;

		cout << "How much do you want to purchase?:\n";

		cin >> amount;

		if (total_equity != 0) {
				switch (option) {
				case 1:
					dogecoin += amount;
					balance -= dogecoin_value * amount;
					crypto_invest += (dogecoin)*dogecoin_value;
					transactions.push_back({ "Dogecoin Bought: ", dogecoin_value * amount });
					break;
				case 2:
					bitcoin += amount;
					balance -= bitcoin_value * amount;
					crypto_invest += (bitcoin)*bitcoin_value;
					transactions.push_back({ "Bitcoin Bought: ", dogecoin_value * amount });
					break;
				case 3:
					ethereum += amount;
					balance -= ethereum_value * amount;
					crypto_invest += (ethereum)*ethereum_value;
					transactions.push_back({ "Ethereum Bought: ", dogecoin_value * amount });
					break;
				case 4:
					litecoin += amount;
					balance -= litecoin_value * amount;
					crypto_invest += (litecoin)*litecoin_value;
					transactions.push_back({ "Litecoin Bought: ", dogecoin_value * amount });
					break;
				case 5:
					solana += amount;
					balance -= solana_value * amount;
					crypto_invest += (solana)*solana_value;
					transactions.push_back({ "Solana Bought: ", dogecoin_value * amount });
					break;
				default:
					break;
				}
			}
			else {
				return false;
			}
			return true;
		}

	//sell function
	bool sell_asset() {
		int option;
		int amount;
		cout << "Enter id of asset you want to sell:\n"
			"dogecoin:	1\n"
			"bitcoin:	2\n"
			"ethereum:	3\n"
			"litecoin:	4\n"
			"solana:	5\n";
		cin >> option;

		cout << "How much do you want to purchase?:\n";

		cin >> amount;

		switch (option) {
		case 1:
			if (dogecoin == 0)
				return false;
			value_return += dogecoin_value*amount;
			balance += dogecoin_value*amount;
			transactions.push_back({ "Dogecoin Sold: ", dogecoin_value*amount });
			dogecoin -= amount;
			break;
		case 2:
			if (bitcoin == 0) 
				return false;
			value_return += bitcoin_value * amount;
			balance += bitcoin_value * amount;
			transactions.push_back({ "Bitcoin Sold: ", bitcoin_value * amount });
			bitcoin -= amount;
			break;
		case 3:
			if (ethereum == 0)
				return false;
			value_return += ethereum_value * amount;
			balance += ethereum_value * amount;
			transactions.push_back({ "Ethereum Sold: ", ethereum_value * amount });
			ethereum -= amount;
			break;
		case 4:
			if (litecoin == 0)
				return false;
			value_return += litecoin_value * amount;
			balance += litecoin_value * amount;
			transactions.push_back({ "Litecoin Sold: ", litecoin_value * amount });
			litecoin -= amount;
			break;
		case 5:
			if (solana == 0)
				return false;
			value_return += solana_value * amount;
			balance += solana_value * amount;
			transactions.push_back({ "Solana Sold: ", solana_value * amount });
			solana -= amount;
			break;
		default:
			cout << "Input not recognized\n ";
			return false;
			break;
		}
		return true;
	}

	void History() {
		cout << "Displaying All transactions\n";
		for (auto it : transactions) {
			cout << it.first << " " << it.second << endl;
		}

		char temp;
		cout << "Do you want to clear all transactions:";
		cin >> temp;

		int no = transactions.size();

		// Clearing All transactions
		if (temp == 'Y') {
			transactions.clear();
			cout << "Total transactions cleared:" << no
				<< endl;
		}
		else {
			cout << "Total transaction:" << no << endl;
		}
	}

	Account() {
		crypto_invest = 0;
		value_return = 0;
		total_equity = 100;

		balance = 50000;
		dogecoin = 0;
		bitcoin = 0;
		withdraw = 0;
		deposit = 0;
		dogecoin_value = 100;
		bitcoin_value = 500;
		litecoin_value = 200;
		ethereum_value = 400;
		solana_value = 600;
	}
};


int main()
{
	Account person;
	int amount, choice;
	bool check;
	while (1) {

		cout << "  "
			"******************************************"
			"*****************************  \n";

		cout << endl;
		cout << "Press 1 if want to have your Account Info "
			<< endl;
		cout << "Press 2 if want to Deposit your money "
			<< endl;
		cout << "Press 3 if want to withdraw your money "
			<< endl;
		cout << "Press 4 if want to know your history "
			<< endl;
		cout << "Press 5 if want to know your Buy Crypto "
			<< endl;
		cout << "Press 6 if want to know your Sell Crypto "
			<< endl;
		cout << "Else press any invalid key for exit \n"
			<< endl;

		cout << "  "
			"******************************************"
			"*****************************  \n";

		cin >> choice;
		int ans;

		switch (choice) {
		case 1:
			person.GetAccountInfo();
			break;

		case 2:
			cout << "Enter amount to deposit : ";
			cin >> amount;
			ans = person.Deposit(amount);
			if (ans)
				cout << "Successfully deposited money"
				<< endl;
			else
				cout << "Failed\n";

			break;

		case 3:
			cout << "Enter amount to withdrawn : ";
			cin >> amount;
			ans = person.Withdraw(amount);

			if (ans)
				cout << "Successfully withdrawn Amount"
				<< endl;
			else
				cout << "Not Enough Balance\n";

break;

		case 4:
			person.History();
			break;

		case 5:
			ans = person.buy_asset();
			if (ans)
				cout << "Successful Transaction" << endl;
			else
				cout << "Better Luck next time\n";
			break;

		case 6:
			ans = person.sell_asset();
			if (ans)
				cout << "Successful Transaction" << endl;
			else
				cout << "Not Enough Cryptocoins\n";
			break;

		default:
			exit(0);
			break;
		}
	}
}
