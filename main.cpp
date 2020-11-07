#include <stdio.h>   /* printf, scanf, puts, NULL */
#include <stdlib.h>   /* srand, rand */
#include <iostream>

class Gambler{
public:
    char Name;
    int aSize = 4;
    int account[4] = {1, 2, 3, 4};
   
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

void Gamble(Gambler*& per){
    Gambler *temp = new Gambler;        //Creates a new empty object
    int size = per->aSize + 1;          //Increase by one the array that holds the "money" of each gambler
    int  *aTemp = new int[size];        //Creates a new empty array to operate the "account" array
    int bet = 0;
    for (int i = 0; i < size; i++){
        aTemp[i] = per->account[i];
    }
    bet = aTemp[0]+aTemp[size - 2];     //charges the bet to the count, if the gamble is lost, it will be lost
    aTemp[size-1] = bet;
    temp->aSize = size;
    temp->Name = per->Name;
    for (int i = 0; i < size; i++){
        temp->account[i] = aTemp[i];    
    }
    delete[] aTemp;
    delete per;
    per = temp;
}



void main(){
    int rou;
    char result;

    for(int i = 0; i < 10000; i++){
        rou = rand() %37;
        result = RuletaRules(rou);
        switch (result)
        {
        case 0b0000:
            /* code */
            break;
        case 0b0001:
           /* code */
            break;
        case 0b0010:
            /* code */
            break;
        case 0b0011:
            /* code */
            break;
        case 0b0100:
            /* code */
            break;
        case 0b0101:
            /* code */
            break;
        case 0b0110:
            /* code */
            break;
        case 0b0111:
            /* code */
            break;
        case 0b1000:
            /* code */
            break;
        
    }
    
}


