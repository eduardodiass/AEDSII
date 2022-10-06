#include <iostream>

using namespace std;

//fatorial 4! * 3! * 2! *1!
int calcularFatorial(int num){
    if(num == 1|| num == 0)
    {
            return 1;
    }
    else{
        return num * calcularFatorial(num-1);

    }
}

int main(){

int num;
cout<<"Digite um numero: "<<endl;
cin>> num;

cout<< "Fatorial: "<< calcularFatorial(num);


return 0;
}

