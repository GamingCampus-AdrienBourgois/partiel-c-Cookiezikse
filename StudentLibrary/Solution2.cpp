#include "Solution2.h"

#include <ostream>
#include <fstream>
#include <sstream>
#include <iostream>
/*
 * Exercice 2 : Bank Account
 *
 * In the folder "BankAccount", you will find multiple documents "XXXXXX.txt" that represents the operations of a bank account.
 * You must provide a solution that will read the file and compute the balance of the account.
 * Two types of operations are available : DEPOSIT (+) and WITHDRAW (-).
 *
 * During compilation, each BankAccount.txt will be copied to the build folder inside the "BankAccount" folder, next to the .exe. To open the file, simply use the "BankAccount/XXXXXX.txt" file path.
 * If the file is not found, the program must throw an exception.
 */

// Don't forget to enable the exercise in the SudentConfiguration.h file !
#include "StudentConfiguration.h"
#ifdef COMPILE_EXERCICE_2

// "BankAccount/XXXXXX.txt"
// Exeption other

float Solution2::GetBalance(const std::string& accountName)
{
    std::string filename = "BankAccount/"+ accountName+".txt";
    std::ifstream file(filename);
	float MoneyInDaBank = 0.f;
    if (file.is_open()) {

		// Check chaque ligne, regarder si withdraw ou deposit et faire l'operation
		// Fichier : "TYPE FLOAT"
		std::string line;
		std::string W = "WITHDRAW";
		std::string D = "DEPOSIT";
    	while (std::getline(file, line)) {
    	    std::istringstream iss(line);
    	    std::string Type;
    	    float Money = 0.f;
            int MoneyInt = 0;
    	    char comma;
    	    if (iss >> Type >> Money) {
				if(Type == W){ MoneyInDaBank -= Money;}
				else if (Type == D){ MoneyInDaBank += Money;}
    	    }
            else if (iss >> Type >> MoneyInt) {
                if (Type == W) { MoneyInDaBank -= MoneyInt; }
                else if (Type == D) { MoneyInDaBank += MoneyInt; }
            }
    	    else {
    	        throw std::runtime_error("Pas possible de lire la ligne lo: " + filename);
    	    }

    	} 
        file.close();
	}
	else {
        throw std::runtime_error("Ouvre po: " + filename);
    }
	return MoneyInDaBank;
}


#endif
