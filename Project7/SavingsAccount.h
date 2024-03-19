#define _CRT_SECURE_NO_WARNINGS
#ifndef SENECA_SAVINGSACCOUNT_H
#define SENECA_SAVINGSACCOUNT_H
#include "BankAccount.h"
#include <istream>
#include <iostream>
#include <iostream>

namespace seneca {
	class SavingsAccount : public BankAccount{
	private:
		double m_interest;
		Date m_interestDate;
		void writeInterest(std::ostream& out) const;
	public:
		SavingsAccount(const char* name, Date openDate, DepositInfo depInfo, double balance, double interest, Date interestDate);
		void applyInterest(Date& dt);
		std::ostream& write(std::ostream& out);
		std::istream & read(std::istream & in);

		//helper functions
		 friend std::istream& operator>>(std::istream& in, SavingsAccount& acct);
		  friend std::ostream& operator<<(std::ostream& out, const SavingsAccount& acct);


	};
}
#endif // !SENECA_SAVINGSACCOUNT_H

