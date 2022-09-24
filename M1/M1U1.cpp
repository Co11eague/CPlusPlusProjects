#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
int Amzius (int m);
int main(){
    int m;

    ifstream df ("amzius_data.txt");
    ofstream rf ("amzius_res.txt");

    df >> m;
    rf << Amzius(m);


    df.close();
    rf.close();

return 0;
}
int Amzius (int m){

m = m / 1000  * 10 + m / 100 % 10 + 1;

return m;
    }
