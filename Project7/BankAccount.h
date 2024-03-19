
#define _CRT_SECURE_NO_WARNINGS
#ifndef SENECA_BANKACCOUNT_H
#define SENECA_BANKACCOUNT_H
#include "DepositUtility.h"
#include <iostream>

namespace seneca {

	class BankAccount : public Date{
	private:
		char m_name[51]; //50 characters + 1 for the null character
		Date m_openDate; //instance of date class 
		DepositInfo m_depInfo; //instance of depositInfo
		double m_balance;
	protected:
		double getBalance() const;
		void setBalance(double balance);
		void writeCurrency(std::ostream& out, double amount)  const;
	public:
		BankAccount(const char* name, Date openDate, DepositInfo depInfo, double balance);
		std::ostream& write(std::ostream& out);
		std::istream& read(std::istream& in);

		//helper functions
		friend std::istream& operator>>(std::istream& in, BankAccount& acct);
		 friend std::ostream& operator<<(std::ostream& out, const BankAccount& acct);
	};
}











#endif
