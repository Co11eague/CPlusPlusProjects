#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
int Data(int data, int kas);
bool ArTinkama(int metai, int menuo, int diena);
string Menuo(int menuo);
int main(){
    int n, i, met, men, dien, data;

    ifstream df ("datos_data.txt");
    ofstream rf ("datos_res.txt");

    df >> n;

    for (i = 1; i <= n; i++){
            df >> data;

            met = Data(data,1);
            men = Data(data,2);
            dien = Data(data,3);

            if (ArTinkama(met, men, dien))rf << met << " m. " << Menuo(men) << " " << dien << " d." << endl;
            else rf << "KLAIDA" << endl;

    }

    rf.close();
    df.close();

return 0;
}
int Data(int data, int kas){

    if (kas == 1){
        data = data / 10000;
        }
    else if (kas == 2){
        data = data / 100 % 100;
    }
    else data = data % 100;

    return data;

    }
bool ArTinkama(int metai, int menuo, int diena)
{
    if (metai < 0 || menuo <= 0 || diena <= 0 || menuo > 12 || diena > 31) return false;
    else if (menuo == 2 && metai % 4 != 0 && diena > 28) return false;
    else if (metai % 4 == 0 && menuo == 2 && diena > 29) return false;
    else if (menuo == 4 && diena > 30 || menuo == 6 && diena > 30 || menuo == 9 && diena > 30 || menuo == 11 && diena > 30)return false;
    else return true;
}
string Menuo(int menuo)
{
    if (menuo == 1)return "sausio";
    else if (menuo == 2)return "vasario";
    else if (menuo == 3)return "kovo";
    else if (menuo == 4)return "balandzio";
    else if (menuo == 5)return "geguzes";
    else if (menuo == 6)return "birzelio";
    else if (menuo == 7)return "liepos";
    else if (menuo == 8)return "rugpjucio";
    else if (menuo == 9)return "rugsejo";
    else if (menuo == 10)return "spalio";
    else if (menuo == 11)return "lapkricio";
    else return "gruodzio";

}
