

int main(){
    int ans = 1;
    int n;
    cin >> n;
    bool bol;
     for(int i = 0; i <= 30; i++){
         if(ans == n){
             bol =  true;
         }
         if (ans < (INT_MAX/2)){

          ans = ans*2;
         }

     }
        bol = false;
        
}