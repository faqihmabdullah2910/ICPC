#include <stdio.h>
#include <bitset>

using namespace std;

char Operan[200010] = {};
bitset<200010> bitArr(0);

void BitLoc(int Index){
    if(bitArr[Index] == false){
        bitArr[Index] = true;
        Operan[Index] = '+';
    }
    else{
        if(Operan[Index] == '+'){
            BitLoc(Index+1);
            bitArr[Index] = false;
            Operan[Index] = ' ';
        }
        else if(Operan[Index] == '-'){
            bitArr[Index] = false;
            Operan[Index] = ' ';
        }
    }
}

void DeleteBit(int Index){
    if(bitArr[Index] == false){
        bitArr[Index] = true;
        Operan[Index] = '-';
    }
    else{
        if(Operan[Index] == '-'){
            DeleteBit(Index+1);
            bitArr[Index] = false;
            Operan[Index] = ' ';
        }
        else if(Operan[Index] == '+'){
            bitArr[Index] = false;
            Operan[Index] = ' ';
        }
    }
}


int main(){
    int MaxNum = 0;
    char MinOperand;
    int Q;
//    int bitArr[200010] = {0};
    scanf("%d", &Q);
    
    int Temp;
    char Operans;
    for(int i = 0; i<Q; i++){
        getchar();
        scanf("%c %d", &Operans, &Temp);
                
        if(Operans == '+')    
            BitLoc(Temp);
        else
            DeleteBit(Temp);
            

        if(!bitArr.any()){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    
    
    return 0;
}
