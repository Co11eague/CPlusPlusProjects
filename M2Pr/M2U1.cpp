#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
void Komanda(int sk, int sk1, int sk2, int &maz, int &did, string &priklausymas);
int main(){
    int n, maz, did, sk, sk1, sk2;
    string priklausymas;

    ifstream df ("komanda.txt");
    ofstream rf ("komandarez.txt");

    df >> n;


    for (int i = 0; i < n; i++){
        df >> sk >> sk1 >> sk2;

        Komanda(sk, sk1, sk2, maz, did, priklausymas);
        rf << maz << " " << did << " " << priklausymas << endl;
    }

    df.close();
    rf.close();

return 0;
}
void Komanda(int sk, int sk1, int sk2, int &maz, int &did, string &priklausymas)
{
    maz = sk;
    did = sk;

    if (maz > sk1) maz = sk1;
    if (maz > sk2) maz = sk2;
    if (did < sk1) did = sk1;
    if (did < sk2) did = sk2;

    if ((maz + did)%2 == 0)priklausymas = "pirma";
    else priklausymas = "antra";

}
