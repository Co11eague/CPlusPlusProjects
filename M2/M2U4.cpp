#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
void NaujasPlotas(double ilgis, double aukstis, int sienuSkaicius, double &plotas);
void ArDidziausias(double dazuKiekis, double &didziausiasKiekis);
int main(){
    int n, s, lang, dur;
    double dazkof, ilg, aukst, S = 0, kiek = 0, did = 0;


    ifstream df ("dazai_data.txt");
    ofstream rf ("dazai_res.txt");

    df >> n >> dazkof;

    for(int i = 0; i < n; i++){
        df >> s >> dur >> lang;

        for(int i1 = 0; i1 < s; i1++){

            df >> ilg >> aukst;
            NaujasPlotas(ilg, aukst, s, S);

        }

        S = S - dur * 2 - lang * 1.5;
        kiek = S / dazkof;

        rf << fixed << setprecision(2) << kiek << endl;

        ArDidziausias(kiek, did);

        S = 0;

    }

    rf << "Didziausias kiekis: " << did;

    rf.close();
    df.close();


return 0;
}

void NaujasPlotas(double ilgis, double aukstis, int sienuSkaicius, double &plotas)
{
    if (sienuSkaicius == 1){
        plotas = plotas + 4 * ilgis * aukstis;
    }
    else if (sienuSkaicius == 2){
        plotas = plotas + 2 * ilgis * aukstis;
    }
    else{
        plotas = plotas + ilgis * aukstis;
    }
}
void ArDidziausias(double dazuKiekis, double &didziausiasKiekis)
{
    if (dazuKiekis > didziausiasKiekis)didziausiasKiekis = dazuKiekis;
}

