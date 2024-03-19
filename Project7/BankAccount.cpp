#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <iomanip>
#include "BankAccount.h"
using namespace std;

namespace seneca {


	//implementation of protected members
	double BankAccount::getBalance() const {
		return m_balance;

	}

	void BankAccount::setBalance(double balance) {
		m_balance = balance;
	}

	void BankAccount::writeCurrency(std::ostream& out, double amount) const {
		out << std::fixed << std::setprecision(2) << "$" << amount;
	}

	//implementation od public members
	BankAccount::BankAccount(const char* name, Date openDate, DepositInfo depInfo, double balance): m_openDate(openDate), m_depInfo(depInfo), m_balance(balance) {
		strncpy(m_name, name, 50); //ensure null termination
		m_name[50] = '\0';

	}

	ostream& BankAccount::write(ostream& out)  {
		out << m_name << " | " << m_balance << " | " << m_openDate << " | " << m_depInfo << endl;
		return out;
	}

	istream& BankAccount::read(istream& in) {
		cout << "Name: ";
		in.getline(m_name, 51);

		cout << "Opening Balance: ";
		in >> m_balance;
		in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		cout << "Date Opened (year month day): ";
		in >> m_openDate;

		cout << "Transit #: ";
		in >> m_depInfo.m_transit;

		cout << "Institution #: ";
		in >> m_depInfo.m_institution;

		cout << "Account #: ";
		in >> m_depInfo.m_account;

		return in;
	}

	//implementing helper functions
	std::istream& operator>>(istream& in, BankAccount& acct) {
		return acct.read(in);
	}

	std::ostream& operator<<(ostream& out, const BankAccount& acct) {
		return acct.write(out);
	}
}