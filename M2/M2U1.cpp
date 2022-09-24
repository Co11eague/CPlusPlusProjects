#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
void Atmintukai(int atmintukoTalpa, double &gibibaitai, double &tebibaitai);
int main(){
    int n, talp;
    double gig, ter;

    ifstream df ("informacija_data.txt");
    ofstream rf ("informacija_res.txt");

    df >> n;

    for(int i = 0; i < n; i++){
        df >> talp;
        Atmintukai(talp, gig, ter);
        rf << fixed << setprecision(1) << gig << " " << fixed << setprecision(2) << ter << endl;
    }

    df.close();
    rf.close();



return 0;
}
void Atmintukai(int atmintukoTalpa, double &gibibaitai, double &tebibaitai)
{
    gibibaitai = atmintukoTalpa * (pow(10, 9) / pow(2, 30));
    tebibaitai = atmintukoTalpa / (pow(2, 40) / pow(10, 9));
}
