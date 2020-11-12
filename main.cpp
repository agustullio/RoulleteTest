
//####################################################################################################
//        Roullette Simulator by Agustin Tullio
//####################################################################################################

#include <stdio.h>   
#include <stdlib.h>   
#include <iostream>
#include <time.h>      
#include <fstream>

using namespace std;

class Gambler{   //The principal private variables in the class are *account, a pointer to an int array wich allocate the numbers obtained along the game, and the aSize which has the size of the array, with this parameter it would be more efficient when it's necesary get the last value of the array. 
private:
    int aSize, lValue, profit;
    int *account;
    char name;
public:
    
	Gambler(){                      //Constructor
        account = new int[4];       
        aSize = 4; 
        profit = 0;          
    };
    void newAccount(){
        int creator[4] = {1, 2, 3, 4};
        int *temp = new int[4];                         //Creates a new empty array at the stack
        for (int i = 0; i < 4; i++)                 //Copies the data from the old pointer to the new one created
            temp[i] =  creator[i];  
        delete[] account;                           //Erease the old array from the stack, doing these we are sure there is not memory leakage
        account = temp;    
        aSize = 4; 
    }
	
    void bet(){
        int stemp = aSize + 1;
        int *temp = new int[stemp];
        int bet;
        if(account[0] == account[aSize-1]){         //In the case the player has only one number at his array, he must played.
            bet = account[0];
        }
        else{
            bet = account[0] + account[aSize - 1];  //The other case is when you have many elements at the account array, so the bet consist in add the first element of the array with the last.
        }
        for (int i = 0; i < aSize; i++)             //Copies the data from the old pointer to the new one created
            temp[i] = account[i];  
        delete[] account;                           //Erease the old array from the stack, doing these we are sure there is not memory leakage
        temp[stemp - 1] = bet;
        account = temp;     
        aSize = stemp;
        cout << "Player '" << name << "' bet ";
		cout << account[aSize-1] << endl;
        lValue = account[aSize-1];
    }
	
    void betLost(){
        int stemp, vol;
        if(aSize <= 3){                         //If the looser player has an account array with 3 elements of less, it will loose all the money and the account will be reset.       
            newAccount();
            cout << "Player '" << name << "' lost all the money, went to the pawnshop" << endl; 
            profit -= 10;                       // 1+2+3+4 = 10, it's the lost off all your initial account, every time you have to get a new account. 
        }
        else
        {
            stemp = aSize - 3;                  //When the player bet, the account array is increased by 1, so when the player loose and must take the first and the last element form the array, i take out the bet elemento too.
            int *temp = new int[stemp]; 
            for (int i = 0; i < stemp; i++){    //Copies the data from the old pointer to the new one created
                vol = i + 1;
                temp[i] = account[vol];         //When the new array it's created, i begun to pass the elements from the second element.
            }
            delete[] account;
            account = temp;
            aSize = stemp;
            cout << "Player '" << name << "' lost, account remaining ";
            cout << account[aSize-1] << endl;
            lValue = account[aSize-1];
        } 
    }
    void betWon(){
        int condition = account[0] + account[aSize - 1];    //The next bet the person makes will be grater than the greatest bet, so the account must be reseted
        if(condition > 4000){
            for (int i = 0; i < aSize; i++)
                profit += account[i] -10;
            newAccount();
            cout << "Player '" << name << "' retires the money" << endl;
        }
        else{
            cout << "Player " << name << " won ";
            cout << account[aSize-1] << endl;
            lValue = account[aSize-1];
        }
    }
    char getName(){
        return name;
    }
    int& getAccount() const{
        return *account;
    }
    int getSize(){
        return aSize;
    }
    int getValue(){
        return lValue;
    }
    void setName(char Lname){
        name = Lname;
        cout << name ;
        cout << " was asigned as a name for the player" << endl;
    }
    int getProfit(){
        return profit;
    }

};


//Ruleta Function: simulates a Roullette Game 
char RuletaRules(int val){
    /*
    Description of posible results
    rslt = 0000 => zero
    rslt = 0001 => max, even, red 
    rslt = 0010 => max, even, black
    rslt = 0011 => max, odd, red
    rslt = 0100 => max, odd, black
    rslt = 0101 => min, even, red
    rslt = 0110 => min, even, black
    rslt = 1000 => min, odd, black
    */
    char rslt;
    int rem = 0;
    
    if(val != 0){                   // non zero
        rem = val%2;
        if(val>18){                 // if max
            if(rem == 0){           // if even
                if(val>29){
                    rslt = 0b0001;  // => max, even, red
                    cout << "The number fulfill the winning conditions: ";
					cout << "max, even, red" << endl;
                }
                else{
                    rslt = 0b0010;  // => max, even, black
                    cout << "The number fulfill the winning conditions: ";
					cout << "max, even, black" << endl;
                }
            }
            else{                   // if odd
               if(val>29){
                    rslt = 0b0100;  // => max, odd, black
                    cout << "The number fulfill the winning conditions: ";
					cout << "max, odd, black" << endl;
                }
                else{
                    rslt = 0b0011;  // => max, odd, red
                    cout << "The number fulfill the winning conditions: ";
					cout << "max, odd, red" << endl;
                }
            }
        }
        else{                       // if min
            if(rem == 0){           // if even
                if(val>10){
                    rslt = 0b0101;  // => min, even, red
                    cout << "The number fulfill the winning conditions: ";
					cout << "min, even, red" << endl;
                }
                else{
                    rslt = 0b0110;  // => min, even, black
                    cout << "The number fulfill the winning conditions: ";
					cout << "min, even, black" << endl;
                }
            }
            else{                   // if odd
               if(val>10){
                    rslt = 0b1000;  // => min, odd, black
                    cout << "The number fulfill the winning conditions: ";
					cout << "min, odd, black" << endl;
                }
                else
                {
                    rslt = 0b0111;  // => min, odd, red
                    cout << "The number fulfill the winning conditions: ";
					cout << "min, odd, red" << endl;
                }
            }
        }
    }
    else{
        rslt = 0b0000;              // => zero
        cout << "The number obtained is ";
		cout << "Zero" << endl;
    }
    return rslt;
}

int main(){
	srand (time(NULL)); //Initialize Random
	int i = 0;
    int *tempA;
    int rou, indice;
    double totalProf;
    char result;
    char gName[6] = {'A', 'B','C', 'D', 'E', 'F'};
    Gambler Gamblers[6] {};                         //Gambler class constructor

    ofstream file;

    file.open("RoulleteLog.txt");

    for(int l = 0; l < 6; l++){
        Gamblers[l].newAccount();
        Gamblers[l].setName(gName[l]);
        file << Gamblers[l].getName() << " was asigned as a name for the player" << endl;
    }

    while(i < 10000){
        cout<< endl;
        cout << "Game number " << i+1 << endl << endl;
        file << endl << "Game number " << i+1 << endl << endl;
        rou = rand() %37;
        cout << "Roullette number obteined ";
		cout << rou << endl << endl;
        file  << "Roullette number obteined "<< rou << endl << endl;
        result = RuletaRules(rou);
		
        for(int j = 0; j < 6; j++){        //All the players make their bets
            Gamblers[j].bet();  
            file << "The player " << Gamblers[j].getName() << " bet " << Gamblers[j].getValue() << endl;
        }
        cout << endl;
        switch (result)
        {
        case 0b0000:                        //The roullete returns a Zero, all the players loose.
            for(int k = 0; k < 6; k++){
                Gamblers[k].betLost();    
			}
            break;       
        case 0b0001:                        //max, even, red
            Gamblers[0].betWon();
            Gamblers[2].betWon();
            Gamblers[4].betWon();
            Gamblers[1].betLost();
            Gamblers[3].betLost();
            Gamblers[5].betLost();
            break;
        case 0b0010:                        //max, even, black
            Gamblers[1].betWon();
            Gamblers[2].betWon();
            Gamblers[4].betWon();
            Gamblers[0].betLost();
            Gamblers[3].betLost();
            Gamblers[5].betLost();
            break;
        case 0b0011:                        //max, odd, red
            Gamblers[0].betWon();
            Gamblers[2].betWon();
            Gamblers[5].betWon();
            Gamblers[1].betLost();
            Gamblers[3].betLost();
            Gamblers[4].betLost();
            break;
        case 0b0100:                        //max, odd, black
            Gamblers[1].betWon();
            Gamblers[2].betWon();
            Gamblers[5].betWon();
            Gamblers[0].betLost();
            Gamblers[3].betLost();
            Gamblers[4].betLost();
            break;
        case 0b0101:                        //min, even, red
            Gamblers[0].betWon();
            Gamblers[3].betWon();
            Gamblers[4].betWon();
            Gamblers[1].betLost();
            Gamblers[2].betLost();
            Gamblers[5].betLost();
            break;
        case 0b0110:                        //min, even, black
            Gamblers[1].betWon();
            Gamblers[3].betWon();
            Gamblers[4].betWon();
            Gamblers[0].betLost();
            Gamblers[2].betLost();
            Gamblers[5].betLost();
            break;
        case 0b0111:                        //min, odd, red
            Gamblers[0].betWon();
            Gamblers[3].betWon();
            Gamblers[5].betWon();
            Gamblers[1].betLost();
            Gamblers[2].betLost();
            Gamblers[4].betLost();
            break;
        case 0b1000:                        //min, odd, black
            Gamblers[1].betWon();
            Gamblers[3].betWon();
            Gamblers[5].betWon();
            Gamblers[0].betLost();
            Gamblers[2].betLost();
            Gamblers[4].betLost();
            break;
        }

            for(int k = 0; k < 6; k++){
                file << "The player " << Gamblers[k].getName() << " get at the game: " << Gamblers[k].getValue() << endl;
			}
		++i;
    }

    for (int i = 0; i < 6; i++)
    {   
        cout << endl;
        cout << "Player " << Gamblers[i].getName() << " reach: " << Gamblers[i].getProfit() << endl ;
        file << "Player " << Gamblers[i].getName() << " reach: " << Gamblers[i].getProfit() << endl ;
        
        totalProf += Gamblers[i].getProfit();
    }

    cout << endl << "The total profit obtained is: " << totalProf << endl << endl;
    file << endl << "The total profit obtained is: " << totalProf << endl << endl;

    if (totalProf > 60)
    {
        cout << "The players obteined a profit off " << totalProf - 60;
        file << "The players obteined a profit off " << totalProf - 60;
    }
    else if (totalProf == 60)
    {
        cout << "They didn´t obtained any profit";
        file << "They didn´t obtained any profit";
    }
    else
    {
        cout << "They loose money";
        file << "They loose money";
    }
    file.close();
}


// An improvement to the program would be that the Gambler Class containe the game's winning conditions for every player.