
#include <bits/stdc++.h>
using namespace std;

class Obj
{
    float x;
    float y;
    float z = 0;

public:
    Obj() {}

    void setX(float x)
    {
        this->x = x;
    }
    void setY(float y)
    {
        this->y = y;
    }
    void setZ(float z)
    {
        this->z = z;
    }
    float getX()
    {
        return this->x;
    }
    float getY()
    {
        return this->y;
    }
    float getZ()
    {
        return this->z;
    }
};
float timMin(float a[], int n)
{
    float min = a[0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
        }
    }

    return min;
}

float timMax(float a[], int n)
{
    float max = a[0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }

    return max;
}

void swap(float &a, float &b)
{
    float temp = a;
    a = b;
    b = temp;
}

int main()
{
    int n = 4457;
    float x, y, z;
    Obj point[4500];
    ofstream outfile;
    cout << setprecision(7);
    freopen("slthu.txt", "r", stdin);

    for (int i = 0; i < 4457; i++)
    {
        cin >> x >> y >> z;

        point[i].setX(x);
        point[i].setY(y);
        point[i].setZ(z);
    }
    float arrx[4500] = {};
    float arry[4500] = {};
    float arrz[4500] = {};

    freopen("slthu.txt", "r", stdin);
    for (int i = 0; i < 4457; i++)
        cin >> arrx[i] >> arry[i] >> arrz[i];

    float minx = timMin(arrx, n), miny = timMin(arry, n);
    float maxx = timMax(arrx, n), maxy = timMax(arry, n);

    float newX[4500] = {};
    float newY[4500] = {};

    for (int i = 0; i < 120; i++)
    {
        newX[i] = minx;
        minx += 0.00005;
        newY[i] = miny;
        miny += 0.00007;
    }

    Obj newPoint[150];
    for (int i = 0; i < 120; i++)
    {
        newPoint[i].setX(newX[i]);
        newPoint[i].setY(newY[i]);
    }
    Obj Z[200][4];

    float KhoangCach[4500] = {};
    for (int i = 0; i < 120; i++)
    {
        for (int kc = 0; kc < 4457; kc++) // tính khoảng cách newpoint với point
        {
            KhoangCach[kc] = sqrt((point[kc].getX() - newPoint[i].getX()) * (point[kc].getX() - newPoint[i].getX()) + (point[kc].getY() - newPoint[i].getY()) * (point[kc].getY() - newPoint[i].getY()));
        }

        for (int j4 = 0; j4 < 4456; j4++) // sắp xếp lại vị trí khoảng cách và point từ bé đến lớn
        {
            for (int t4 = j4 + 1; t4 < 4457; t4++)
            {
                if (KhoangCach[j4] > KhoangCach[t4])
                {
                    swap(KhoangCach[j4], KhoangCach[t4]);
                    swap(point[j4], point[t4]);
                }
            }
        }

        Z[i][0] = point[0];             //tìm 4 điểm gần nhất

        for (int m = 1; m < 4457; m++)
        {
            if (point[m].getZ() != Z[i][0].getZ())
            {
                Z[i][1] = point[m];
                break;
            }
        }
        for (int m = 2; m < 4457; m++)
        {
            if (point[m].getZ() != Z[i][0].getZ() && point[m].getZ() != Z[i][1].getZ())
            {
                Z[i][2] = point[m];
                break;
            }
        }
        for (int m = 3; m < 4457; m++)
        {
            if (point[m].getZ() != Z[i][0].getZ() && point[m].getZ() != Z[i][1].getZ() && point[m].getZ() != Z[i][2].getZ())
            {
                Z[i][3] = point[m];
                break;
            }
        }
    }
    for (int iz = 0; iz < 120; iz++) // tìm z
    {
        float a1 = (newPoint[iz].getX() * (Z[iz][1].getZ() - Z[iz][0].getZ()) - Z[iz][1].getZ() * Z[iz][0].getX() + Z[iz][0].getZ() * Z[iz][1].getX()) / (Z[iz][1].getX() - Z[iz][0].getX());
        float a3 = (newPoint[iz].getX() * (Z[iz][2].getZ() - Z[iz][3].getZ()) - Z[iz][2].getZ() * Z[iz][3].getX() + Z[iz][3].getZ() * Z[iz][2].getX()) / (Z[iz][2].getX() - Z[iz][3].getX());
        float a2 = (newPoint[iz].getY() * (Z[iz][2].getZ() - Z[iz][1].getZ()) - Z[iz][2].getZ() * Z[iz][1].getY() + Z[iz][1].getZ() * Z[iz][2].getY()) / (Z[iz][2].getY() - Z[iz][1].getY());
        float a4 = (newPoint[iz].getY() * (Z[iz][3].getY() - Z[iz][0].getY()) - Z[iz][3].getZ() * Z[iz][0].getY() + Z[iz][0].getZ() * Z[iz][3].getY()) / (Z[iz][3].getY() - Z[iz][0].getY());

        float a5 = (a1 + a2 + a3 + a4) / 4;
        newPoint[iz].setZ(a5);
    }

    system("pause");
    return 0;
}