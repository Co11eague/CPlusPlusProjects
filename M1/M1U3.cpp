#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
double Lieka (double suma, double knygos_kaina);
string ArGali(double suma, double knygos_kaina);
int main(){
    int kiek, i, nr;
    double pin, kain;

    ifstream df ("knygos_data.txt");
    ofstream rf ("knygos_res.txt");

    df >> pin >> kiek;

    for (i = 1; i <= kiek; i++){
        df >> nr >> kain;


        rf << nr << " " << kain << " " << fixed << setprecision(2) << Lieka(pin, kain) << " " << ArGali(pin, kain) << endl;

        pin = Lieka(pin, kain);


    }
        rf.close();
        df.close();

return 0;
}
double Lieka (double suma, double knygos_kaina)
{
    if (ArGali(suma, knygos_kaina) == "GALI"){

        return suma - knygos_kaina;

    }
    else return suma;

}
string ArGali(double suma, double knygos_kaina)
{

    if (suma - knygos_kaina >= 0) return "GALI";
    else return "NEGALI";

}
