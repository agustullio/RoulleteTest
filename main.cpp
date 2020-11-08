#include <stdio.h>   /* printf, scanf, puts, NULL */
#include <stdlib.h>   /* srand, rand */
#include <iostream>

class Gambler{
public:
    char Name;
    int account = new[1, 2, 3, 4];
    int aSize = 4;
}



//Ruleta Function: simulates a Ruleta Game but with a normal distribution of probably by number
void Ruleta(rslt){
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
    int rslt;

    int val = 0;
    int rem = 0;

    val = rand() %37;
    
    if(val != 0){                   // non zero
        rem = val%2;
        if(val>18){                 // if max
            if(rem == 0){           // if pair
                if(val>29){
                    rslt = 0001;    // => max, pair, red
                }
                else{
                    rslt = 0010;    // => max, pair, black
                }
            }
            else{                   // if odd
               if(val>29){
                    rslt = 0100;    // => max, odd, black
                }
                else{
                    rslt = 0011;    // => max, odd, red
                }
            }
        }
        else{                       // if min
            if(rem == 0){           // if pair
                if(val>10){
                    rslt = 0101;    // => min, pair, red
                }
                else{
                    rslt = 0110;    // => min, pair, black
                }
            }
            else{ // if odd
               if(val>10){
                    rslt = 1000;    // => min, odd, black
                }
                else
                {
                    rslt = 0111;    // => min, odd, red
                }
            }
        }
    }
    else{
        rslt = 0000;                // => zero
    }
    cout << rslt;
}

// DyArray Function: Expand an array, making a new one.
void DyArray(int*& arr, int currentSize, int newSize){
    int *temp = new int[newSize];                       //Creates a new empty array at the stack
    for(int i = 0; i < currentSize; i++)                //Copies the data from the old pointer to the new one created
        temp[i] = arr[i];   
    delete[] arr;                                       //Erease the old array from the stack, doing these we are sure there is not memory leakage                             
    arr = temp;
}

void WinGamble(Gambler*& per){
    Gambler *temp = per;
    
    

}
void main(){
    
}


