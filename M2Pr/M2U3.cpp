#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
void Monetos(int vien, int du, int penk, int &dueur, int &eur, int &penkdc, int &dvidc, int &desc, int &auk);
int main(){
    int vien, du, penk, dueur, eur, penkdc, dvidc, desc, auk, n;

    ifstream df ("santaupos.txt");
    ofstream rf ("santauposrez.txt");

    df >> n;

    for (int i = 0; i < n; i++){
        df >> vien >> du >> penk;
        Monetos(vien, du, penk, dueur, eur, penkdc, dvidc, desc, auk);

        rf << dueur << " " << eur << " " << penkdc << " " << dvidc << " " << desc << " " << auk << endl;

        }
    df.close();
    rf.close();
    return 0;
}
void Monetos(int vien, int du, int penk, int &dueur, int &eur, int &penkdc, int &dvidc, int &desc, int &auk)
{
    int vis = 0;

    vis = vien + du * 2 + penk * 5;
    dueur = vis / 200;
    vis = vis % 200;
    eur = vis / 100;
    vis = vis % 100;
    penkdc = vis / 50;
    vis = vis % 50;
    dvidc = vis / 20;
    vis = vis % 20;
    desc = vis / 10;
    auk = vis % 10;
}
