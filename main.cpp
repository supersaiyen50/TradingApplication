#include <utility>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Account {
	
		int dogecoin, bitcoin;
		int balance;
		int deposit, withdraw;
		int total_equity = 100;
		int predict;
		int dogecoin_value, bitcoin_value;
		int crypto_invest;
		int value_return;
		vector<pair<string, int> > transactions;
public:
	//deposit money
	bool Deposit(int money) {
		deposit += money;
		balance += money;
		transactions.push_back({ "Deposit:", money });
	}

	//get account information
	void GetAccountInfo() {
		cout << "Money Details:\n";
		cout << "Bank Balance:" << balance << endl;
		cout << "Dogecoin:" << dogecoin << endl;
		cout << "Bitcoin:" << bitcoin << endl;
	}
};

