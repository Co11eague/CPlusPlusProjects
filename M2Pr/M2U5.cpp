#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
void Suma(int sv, int st, int p, int sv1, int st1, int p1, int &ssv, int &sst, int &sp);
void Skirtumas(int sv, int st, int p, int sv1, int st1, int p1, int &ssv, int &sst, int &sp);

int main(){
    int sv, st, p, sv1, st1, p1, ssv, sst, sp, sksv, skst, skp, n;

    ifstream df ("pinigai.txt");
    ofstream rf ("pinigairez.txt");

    df >> n;

    for (int i = 0; i < n; i++){
        df >> sv >> st >> p >> sv1 >> st1 >> p1;

        Suma(sv, st, p, sv1, st1, p1, ssv, sst, sp);
        Skirtumas(sv, st, p, sv1, st1, p1, sksv, skst, skp);

        rf << ssv << " " << sst << " " << sp << " " << sksv << " " << skst << " " << skp << endl;
        df.close();
        rf.close();
    }


return 0;
}
void Suma(int sv, int st, int p, int sv1, int st1, int p1, int &ssv, int &sst, int &sp)
{

    sp = (p + p1) % 12;
    sst = (st + st1 + (p + p1) / 12) % 20;
    ssv = sv + sv1 + (st + st1 + (p + p1) / 12)  / 20;
}
void Skirtumas(int sv, int st, int p, int sv1, int st1, int p1, int &ssv, int &sst, int &sp)
{
    int s, s1, sk = 0;

    s = sv * 12 * 20 + st * 12 + p;
    s1 = sv1 * 20 * 12 + st1 * 12 + p1;
    sk = s - s1;

    sp = sk % 12;
    ssv = sk / 12 / 20 ;
    sst = sk / 12 % 20;

    //Uzduotyje blogai nurodyti atsakymai

}
