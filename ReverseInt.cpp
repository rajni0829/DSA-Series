#include <iostream>
using namespace std;
#include <math.h>
int INT_MAX;
int INT_MIN;
int main(){
int ans = 0;
int x = 1234;
        while(x!=0){
            int digit = x%10;
            if ((ans > INT_MAX/10) || (ans < INT_MIN/10)){
                return 0;
            }
            ans = ans*10 + digit;
            x=x/10;
        }
        return ans;
}