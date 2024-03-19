#define _CRT_SECURE_NO_WARNINGS
#include "SavingsAccount.h"
#include <iostream>
#include <iomanip>
using namespace std;

using namespace std;

namespace seneca {

	//IMPLEMENTING PRIVATE-MEMBER-FUNCTION
	void SavingsAccount::writeInterest(ostream& out) const {
		//out << std::fixed << std::setprecision(2) << "$" << amount;
		out << std::fixed << std::setprecision(3) << m_interest * 100 << "%";
	}

	//IMPLEMENTING PUBLIC-MEMBER-FUNCTIONS
	SavingsAccount::SavingsAccount(const char* name, Date openDate, DepositInfo depInfo, double balance, double interest, Date interestDate):BankAccount(name, openDate, depInfo, balance), m_interest(interest), m_interestDate(interestDate) {}

	void SavingsAccount::applyInterest(Date& dt) {
		//calculate interest amount
		double balance = getBalance();
		double interestAmount = balance * m_interest;

		setBalance(balance + interestAmount);
		m_interestDate = dt;

		cout << " " << balance << " + " << interestAmount << " (";
		writeInterest(cout);
		cout << ")= " << getBalance() << " | " << dt << " => " << m_interestDate << endl;
	}

	ostream& SavingsAccount::write(ostream& out) {
		BankAccount::write(out); //calling the base class write funtion
		out << " | ";
		writeInterest(out);
		out << " | " << m_interestDate;
		return out;
	}

	istream& SavingsAccount::read(istream& in) {
		BankAccount::read(in); //calling the base class read function
		cout << "Interest Date (year month day): ";
		in >> m_interestDate;
		cout << "Interest Rate: ";
		in >> m_interest;
		return in;
	}

	istream& operator>>(std::istream& in, SavingsAccount& acct) {
		return acct.read(in);
	}

	ostream& operator<<(std::ostream& out, const SavingsAccount& acct) {
		return acct.write(out);
	}
}