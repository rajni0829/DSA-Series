#include <iostream>
using namespace std;
#include <math.h>


//DECIMAL TO BINARY CONVERTER
int main(){
int n ;
cout << "Enter Number :";
cin >> n;
int i = 0;
int ans = 0;
while(n!=0){
// cout<< "n1 "<< n<<endl;
int bit = n&1;
// cout<<"bit "<<bit<<endl;
ans = (bit* pow(10,i))+ans ;
n = n>>1;
// cout<< "n2 "<< n<<endl;
i++;
    }
cout << ans;


//Binary to Decimal
int n ;
cout<< "Enter Binary Number : ";
cin >> n;
int ans = 0;
int i = 0;

while(n!=0){
int digit = n% 10;
if(digit==1){
    ans = (pow(2,i)) +  ans ;
}
n = n/ 10;
i++;
}
cout << ans << endl;


}

