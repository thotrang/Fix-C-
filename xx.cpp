
#include <bits/stdc++.h>                    //thư viện
using namespace std;

class Obj                                   // đối tượng    point       object
{
    float x;                                // khai báo 1 điểm có 3 thuộc tính x, y là tọa độ
    float y;                                // z là từ trường
    float z = 0;

public:
    Obj() {}

    void setX(float x)                      //hàm void để đưa giá trị vào               void x(18,32532456)
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
    float getX()                             //hàm return để t lấy giá trị ra           float x=18,32532456
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

    for (int i = 0; i < n; i++)
    {
        if (a[i] < min)                     // nếu 5<min            min=6
        {                                   // min=5
            min = a[i];                      //  4<min                     min=3 min=1
        }
    }

    return min;                                  //timMin=min    
}

float timMax(float a[], int n)
{
    float max = a[0];

    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }

    return max;                                 //timMax=max
}

void swap(float &a, float &b)
{
    float temp = a;
    a = b;
    b = temp;
}

int main()
{
    int n = 4457;                   // số lượng điểm ta có n=4457
    float x, y, z;                  // để nhận giá trị của x, ,y, z
    Obj point[4500];                // mảng đẻ chứa các điểm    có vị trí từ 0 đến 4456
    ofstream outfile;               // đọc file
    cout << setprecision(7);
    freopen("slthu.txt", "r", stdin);

    for (int i = 0; i < 4457; i++)      //83 đến 92 để đưa giá trị vào các điểm từ slthu.txt
    {
        cin >> x >> y >> z;             // đưa giá trị vào x,y,z trước

        point[i].setX(x);               //đưa giá trị từ x,y,z vào point
        point[i].setY(y);
        point[i].setZ(z);
    }
    float arrx[4500] = {};                              //cả đoạn này dùng để tìm min max
    float arry[4500] = {};
    float arrz[4500] = {};

    freopen("slthu.txt", "r", stdin);
    for (int i = 0; i < 4457; i++)
        cin >> arrx[i] >> arry[i] >> arrz[i];

    float minx = timMin(arrx, n), miny = timMin(arry, n);               // tìm min của x và y

    float maxx = timMax(arrx, n), maxy = timMax(arry, n);               // tìm max của x và y

    float newX[4500] = {};                                          // tạo ra bảng mới để chứa x và y mới
    float newY[4500] = {};

    for (int i = 0; i < 120; i++)
    {
        newX[i] = minx;                                             //đưa giá trị mới vào x và y
        minx += 0.00005;
        newY[i] = miny;
        miny += 0.00007;
    }

    Obj newPoint[150];
    for (int i = 0; i < 120; i++)
    {
        newPoint[i].setX(newX[i]);                                  // đưa giá trị của x và y vaò point mới
        newPoint[i].setY(newY[i]);
    }
    Obj Z[200][4];                                                  // tạo ra mảng 2 chiều để chứa 4 điểm gần nhất

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
                    swap(point[j4], point[t4]);                                 //point[] nó sẽ có điểm đàu tiên nhỏ nhất và điểm cuối cùng lớn nhât
                }
            }
        }

        Z[i][0] = point[0];             //tìm 4 điểm gần nhất                       Z với i là vị trí của newpoint 
                                                                                    //0 1 2 3
        for (int m = 1; m < 4457; m++)
        {
            if (point[m].getZ() != Z[i][0].getZ())
            {
                Z[i][1] = point[m];
                break;
            }
        }
        for (int m = 1; m < 4457; m++)
        {
            if (point[m].getZ() != Z[i][0].getZ() && point[m].getZ() != Z[i][1].getZ())
            {
                Z[i][2] = point[m];
                break;
            }
        }
        for (int m = 1; m < 4457; m++)
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

        cout<<newPoint[iz].getX()<<" "<<newPoint[iz].getY()<<" "<<newPoint[iz].getZ()<<endl;
    }


    system("pause");
    return 0;
}