#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
 int Sekundes (int s);
int main(){
    int m;

    ifstream df ("laikas_data.txt");
    ofstream rf ("laikas_res.txt");

    df >> m;

    rf << Sekundes(m);

    df.close();
    rf.close();

return 0;
}
 int Sekundes (int s){

     s = s % 60;

     return s;
 }
