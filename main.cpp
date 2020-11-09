#include <stdio.h>   /* printf, scanf, puts, NULL */
#include <stdlib.h>   /* srand, rand */
#include <iostream>

class Gambler{
    int aSize;
    int *account;
    char name;
public:
    void newAccount(){
        int *temp = new int[4];     //Creates a new empty array at the stack
        for (int i = 0; i < 4; i++) //Copies the data from the old pointer to the new one created
            temp[i] = ++i;  
        delete[] account;           //Erease the old array from the stack, doing these we are sure there is not memory leakage
        account = temp;     
        aSize = 4;
    }
    void bet(){
        int stemp = aSize + 1;
        int *temp = new int[stemp];
        int bet = account[0] + account[aSize - 1];
        for (int i = 0; i < stemp; i++) //Copies the data from the old pointer to the new one created
            temp[i] = account[i];  
        delete[] account;           //Erease the old array from the stack, doing these we are sure there is not memory leakage
        temp[stemp - 1] = bet;
        account = temp;     
        aSize = stemp;
    }
    void betLost(){
        if(account[0] == 2){
            newAccount();
            continue;
        }
        int stemp = aSize -3;
        int *temp = new int[stemp]; 
        for (int i = 0; i < stemp; i++) //Copies the data from the old pointer to the new one created
            temp[i] = account[i + 1];
        delete[] account;
        account = temp;
        aSize = stemp;
    }
    void betWon(){
        if(account[aSize-1] == 4000){
            newAccount();
        }
    }
    char getName(){
        return name;
    }
    void setName(Lname){
        name = Lname;
    }
};



//Ruleta Function: simulates a Ruleta Game but with a normal distribution of probably by number
char RuletaRules(int val){
    /*
    Description of posible results
    rslt = 0000 => zero
    rslt = 0001 => max, pair, red 
    rslt = 0010 => max, pair, black
    rslt = 0011 => max, odd, red
    rslt = 0100 => max, odd, black
    rslt = 0101 => min, pair, red
    rslt = 0110 => min, pair, black
    rslt = 1000 => min, odd, black
    */
    char rslt;

    //int val = 0;
    int rem = 0;

    //val = rand() %37;
    
    if(val != 0){                   // non zero
        rem = val%2;
        if(val>18){                 // if max
            if(rem == 0){           // if pair
                if(val>29){
                    rslt = 0b0001;  // => max, pair, red
                }
                else{
                    rslt = 0b0010;  // => max, pair, black
                }
            }
            else{                   // if odd
               if(val>29){
                    rslt = 0b0100;  // => max, odd, black
                }
                else{
                    rslt = 0b0011;  // => max, odd, red
                }
            }
        }
        else{                       // if min
            if(rem == 0){           // if pair
                if(val>10){
                    rslt = 0b0101;  // => min, pair, red
                }
                else{
                    rslt = 0b0110;  // => min, pair, black
                }
            }
            else{                   // if odd
               if(val>10){
                    rslt = 0b1000;  // => min, odd, black
                }
                else
                {
                    rslt = 0b0111;  // => min, odd, red
                }
            }
        }
    }
    else{
        rslt = 0b0000;              // => zero
    }
    return rslt;
}

// DyArray Function: Expand an array, making a new one.
void DyArray(int*& arr, int currentSize, int newSize){
    int *temp = new int[newSize];                       //Creates a new empty array at the stack
    for(int i = 0; i < currentSize; i++)                //Copies the data from the old pointer to the new one created
        temp[i] = arr[i];   
    delete[] arr;                                       //Erease the old array from the stack, doing these we are sure there is not memory leakage                             
    arr = temp;
}

void main(){
    int rou;
    char result;
    char gName[6] = {'A', 'B','C', 'D', 'E', 'F'};
    Gambler Gamblers[6];

    for(int i = 0; int < 6; i++)
        Gamblers[i].newAccount;

    for(int i = 0; i < 10000; i++){
        rou = rand() %37;
        result = RuletaRules(rou);

        for(int i = 0; int < 6; i++)        //All the players make their bets
            Gamblers[i].bet;
            Gamblers[i].setName(gName[i]);

        switch (result)
        {
        case 0b0000:                        //The roullete returns a Zero, all the player loose.
            for(int i = 0; int < 6; i++)
                Gamblers[i].betLost;
            break;
        case 0b0001:
            Gamblers[0].betWon;
            Gamblers[2].betWon;
            Gamblers[4].betWon;
            Gamblers[1].betLost;
            Gamblers[2].betLost;
            Gamblers[3].betLost;
            break;
        case 0b0010:
            Gamblers[0].betWon;
            Gamblers[2].betWon;
            Gamblers[4].betWon;
            Gamblers[1].betLost;
            Gamblers[2].betLost;
            Gamblers[3].betLost;
            break;
        case 0b0011:
            Gamblers[0].betWon;
            Gamblers[2].betWon;
            Gamblers[4].betWon;
            Gamblers[1].betLost;
            Gamblers[2].betLost;
            Gamblers[3].betLost;
            break;
        case 0b0100:
            Gamblers[0].betWon;
            Gamblers[2].betWon;
            Gamblers[4].betWon;
            Gamblers[1].betLost;
            Gamblers[2].betLost;
            Gamblers[3].betLost;
            break;
        case 0b0101:
            Gamblers[0].betWon;
            Gamblers[2].betWon;
            Gamblers[4].betWon;
            Gamblers[1].betLost;
            Gamblers[2].betLost;
            Gamblers[3].betLost;
            break;
        case 0b0110:
            Gamblers[0].betWon;
            Gamblers[2].betWon;
            Gamblers[4].betWon;
            Gamblers[1].betLost;
            Gamblers[2].betLost;
            Gamblers[3].betLost;
            break;
        case 0b0111:
            Gamblers[0].betWon;
            Gamblers[2].betWon;
            Gamblers[4].betWon;
            Gamblers[1].betLost;
            Gamblers[2].betLost;
            Gamblers[3].betLost;
            break;
        case 0b1000:
            Gamblers[0].betWon;
            Gamblers[2].betWon;
            Gamblers[4].betWon;
            Gamblers[1].betLost;
            Gamblers[2].betLost;
            Gamblers[3].betLost;
            break;
        
    }
    
}


// An improvement to the program would be that the Gambler Class containe the game's winning conditions for every player.