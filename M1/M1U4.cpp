#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;
string Sesioliktainis(long desimtainis);
int main(){
    int sk;

    ifstream df ("data.txt");
    ofstream rf ("res.txt");

    df >> sk;

    rf << Sesioliktainis(sk);

    df.close();
    rf.close();


return 0;
}
string Sesioliktainis(long desimtainis)
{
    int liek;
    string ats;

    while (desimtainis > 0){

        liek = desimtainis % 16;
        desimtainis = desimtainis / 16;

        if (liek == 15) ats = "F" + ats;
        else if (liek == 14)ats = "E" + ats;
        else if (liek == 13)ats = "D" + ats;
        else if (liek == 12)ats = "C" + ats;
        else if (liek == 11)ats = "B" + ats;
        else if (liek == 10)ats = "A" + ats;
        else if (liek == 9)ats = "9" + ats;
        else if (liek == 8)ats = "8" + ats;
        else if (liek == 7)ats = "7" + ats;
        else if (liek == 6)ats = "6" + ats;
        else if (liek == 5)ats = "5" + ats;
        else if (liek == 4)ats = "4" + ats;
        else if (liek == 3)ats = "3" + ats;
        else if (liek == 2)ats = "2" + ats;
        else if (liek == 1)ats = "1" + ats;
        else ats = "0" + ats;
    }

    return ats;

}
