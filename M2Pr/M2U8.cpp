#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
void Pazimys (int &paz, string nd);
int main(){
    int n, paz;
    string nd;

    ifstream df ("pazymiai.txt");
    ofstream rf ("rez.txt");

    df >> n;

    for (int i = 0; i < n; i++){
        df >> paz >> nd;

        Pazimys(paz, nd);

        rf << paz << endl;
    }

    df.close();
    rf.close();
return 0;
}
void Pazimys (int &paz, string nd)
{
    if (paz > 1 && nd == "neatliko")paz--;
    else if (paz < 9 && nd == "atliko")paz++;

}
