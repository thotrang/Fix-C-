#include <iostream>
using namespace std;
#include <fstream>
#include <bits/stdc++.h>
int main()
{
    
    ifstream file;
    file.open("slthu.txt");
    cout << setprecision(7);
    float arrX[4500];
    float arrY[4500];
    float arrZ[4500];
    for (int i = 0; i < 4457; i++)
    {
        file >> arrX[i] >> arrY[i] >> arrZ[i];
    }
    for (int i = 0; i < 100; i++)
    {
        cout << arrX[i] << " " << arrY[i] << " " << arrZ[i] << endl;
    }
    file.close();
}