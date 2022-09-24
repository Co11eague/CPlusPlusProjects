#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
void Santykis(double pt, double gt, double &SE);
int main(){
    double P, La, Le, B, C, P1, La1, Le1, B1, C1, pt, gt;
    double SE;

    ifstream df ("data_input.txt");
    ofstream rf ("data_output.txt");

    df >> P >> Le >> La >> B >> C >> P1 >> Le1 >> La1 >> B1 >> C1;

    pt = P * 20 + Le * 54 + La * 44 + B * 82 + C * 137;
    gt = P1 * 64 + Le1 * 54 + La1 * 64 + B1 * 12 + C1 * 62;

    Santykis(pt, gt, SE);

    if (pt >= gt){
        rf << "false" << endl;
        SE = 1 - SE;
    }
    else{
        rf << "true" << endl;
    }

    P1 = P1 * SE;
    Le1 = Le1 * SE;
    La1 = La1 * SE;
    B1 = B1 * SE;
    C1 = C1 * SE;

    rf << floor(P1) << endl << floor(Le1) << endl << floor(La1) << endl << floor(B1) << endl << floor(C1) << endl;
    df.close();
    rf.close();
return 0;
}
void Santykis(double pt, double gt, double &SE)
{
    if (pt >= gt)SE = gt / pt;
    else SE = pt / gt;

    SE = round(SE * 10000) / 10000;
}
