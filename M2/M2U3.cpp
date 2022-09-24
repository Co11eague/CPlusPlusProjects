#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
void Kiekis(int &kiek, int talpa, int &deziuSkaicius);
using namespace std;
int main(){
    int n, k, k1, k2, ds, var, rod = 0;

    ifstream df ("varikliukai_data.txt");
    ofstream rf ("varikliukai_res.txt");

    df >> n >> k >> k1 >> k2;

    for (int i = 0; i < n; i++){
        df >> var;

        Kiekis(var, k, ds);
        rf << ds << " ";

        Kiekis(var, k1, ds);
        rf << ds << " ";

        Kiekis(var, k2, ds);
        if (var > 0)ds = ds + 1;
        rf << ds << " " << endl;
    }

    df.close();
    rf.close();

return 0;
}
void Kiekis(int &kiek, int talpa, int &deziuSkaicius)
{
    deziuSkaicius = kiek / talpa;
    kiek = kiek % talpa;
}
