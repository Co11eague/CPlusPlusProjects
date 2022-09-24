#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
int Koordinate (char komanda);
double Atstumas (int x, int y);
int main(){

    int n, i, x = 0, y = 0;
    char nurod;

    ifstream df ("robotas_data.txt");
    ofstream rf ("robotas_res.txt");



    df >> n;

    for (i = 1; i <= n; i++){
        df >> nurod;
        if (nurod == 'A' || nurod == 'D')x = x + Koordinate(nurod);
        else y = y + Koordinate(nurod);

    }

    rf << fixed << setprecision(2) << Atstumas(x, y);

    df.close();
    rf.close();

return 0;
}
int Koordinate (char komanda)
{
    if (komanda == 'D' || komanda == 'A') return 1;
    else return -1;
}
double Atstumas (int x, int y)
{
    return sqrt(pow(x, 2) + pow(y, 2));
}
