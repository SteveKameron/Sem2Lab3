#include <iostream>

class Bank_Account {
protected:
	std::string FIO;
	int Balance, Deposit_Lifetime;
	double Deposit_Rate;
public:

	Bank_Account(std::string Name, int Bal, int Depo_Rate, int Depo_Lifetime) {
		FIO = Name;
		Balance = Bal;
		Deposit_Rate = Depo_Rate;
		Deposit_Lifetime = Depo_Lifetime;
	}

	virtual int Balance_Counter() {
		double Sum = Balance;
		for (int i = 0; i < Deposit_Lifetime; i++) {
			Sum += Sum * (Deposit_Rate / 100);
		}
		return Sum;
	}

	virtual void Print() {
		std::cout << "Balance: " << Balance << std::endl;
		std::cout << "Deposit rate: " << Deposit_Rate << std::endl;
		std::cout << "Deposit lifetime: " << Deposit_Lifetime << std::endl;
	}

	~Bank_Account() {
		std::cout << "Bank_Account Destructor" << std::endl;
	}

};

class Vip_Account : public Bank_Account {
public:
	double Loan_Percentage;
	
	Vip_Account(std::string Name, int Bal, int Depo_Rate, int Depo_Lifetime, double Loan_Perc) : Bank_Account(Name, Bal, Depo_Rate, Depo_Lifetime) {
		FIO = Name;
		Balance = Bal;
		Deposit_Rate = Depo_Rate;
		Deposit_Lifetime = Depo_Lifetime;
		Loan_Percentage = Loan_Perc;
	}

	int Balance_Counter() override {
		int Sum = Balance;
		for (int i = 0; i < Deposit_Lifetime; i++) {
			Sum += Sum * (Deposit_Rate/100) + Sum * (Loan_Percentage/100);
		}
		return Sum;
	}

	void Print() {
		std::cout << "Balance: " << Balance << std::endl;
		std::cout << "Deposit rate: " << Deposit_Rate << std::endl;
		std::cout << "Deposit lifetime: " << Deposit_Lifetime << std::endl;
		std::cout << "Loan percentage: " << Loan_Percentage << std::endl;
	}

	~Vip_Account() {
		std::cout << "Vip_Account Destructor" << std::endl;
	}

};

int main() {
	setlocale(LC_ALL, "RU");
	
	Bank_Account Main_Account("Ivanov Ivan Ivanovich", 10000, 5, 10);
	
	Vip_Account Another_Account("Sergeev Sergey Sergeevich",10000,5,10,10);

	std::cout << "Main_Account Balance:  " << Main_Account.Balance_Counter() << std::endl;

	std::cout << "Another_Account Balance: " << Another_Account.Balance_Counter() << std::endl;

	Bank_Account* Third_Account = &Another_Account;
	std::cout << '\n';
	std::cout << "Third_Account" << std::endl;
	Third_Account->Print();
	std::cout << '\n';
	std::cout << '\n';
	std::cout << "Fourth_Account" << std::endl;
	Bank_Account Fourth_Account = Another_Account;
	Fourth_Account.Print();
	std::cout << '\n';


	return 0;
}