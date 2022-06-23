
#include <bits/stdc++.h> //thư viện
#include <fstream>
using namespace std;

class Obj // đối tượng    point       object
{
    float x; // khai báo 1 điểm có 3 thuộc tính x, y là tọa độ
    float y; // z là từ trường
    float z = 0;

public:
    Obj() {}

    void setX(float x) // hàm void để đưa giá trị vào               void x(18,32532456)
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
    float getX() // hàm return để t lấy giá trị ra           float x=18,32532456
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
        if (a[i] < min) // nếu 5<min            min=6
        {               // min=5
            min = a[i]; //  4<min                     min=3 min=1
        }
    }

    return min; // timMin=min
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

    return max; // timMax=max
}

void swap(float &a, float &b)
{
    float temp = a;
    a = b;
    b = temp;
}

int main()
{
    int n = 4457;    // số lượng điểm ta có n=4457
    float x, y, z;   // để nhận giá trị của x, ,y, z
    Obj point[4500]; // mảng đẻ chứa các điểm    có vị trí từ 0 đến 4456
    // cout << setprecision(7);
    ifstream file;
    file.open("slthu.txt");

    for (int i = 0; i < 4457; i++) // 83 đến 92 để đưa giá trị vào các điểm từ slthu.txt
    {
        file >> x >> y >> z; // đưa giá trị vào x,y,z trước

        point[i].setX(x); //đưa giá trị từ x,y,z vào point
        point[i].setY(y);
        point[i].setZ(z);
    }
    file.close();
    float arrx[4500] = {}; // cả đoạn này dùng để tìm min max
    float arry[4500] = {};
    float arrz[4500] = {};

    file.open("slthu.txt");
    for (int i = 0; i < 4457; i++)
        file >> arrx[i] >> arry[i] >> arrz[i];
    file.close();
    float minx = timMin(arrx, n), miny = timMin(arry, n); // tìm min của x và y

    float maxx = timMax(arrx, n), maxy = timMax(arry, n); // tìm max của x và y

    float newX[4500] = {}; // tạo ra bảng mới để chứa x và y mới
    float newY[4500] = {};

    for (int i = 0; i < 500; i++)
    {
        newX[i] = minx; //đưa giá trị mới vào x và y
        minx += 0.00002;
        newY[i] = miny;
        miny += 0.00003;
    }

    Obj newPoint[600];
    for (int i = 0; i < 500; i++)
    {
        newPoint[i].setX(newX[i]); // đưa giá trị của x và y vaò point mới
        newPoint[i].setY(newY[i]);
    }

    Obj Z[600][4]; // tạo ra mảng 2 chiều để chứa 4 điểm gần nhất

    float KhoangCach[4500] = {};
    for (int i = 0; i < 500; i++)
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
                    swap(point[j4], point[t4]); // point[] nó sẽ có điểm đàu tiên nhỏ nhất và điểm cuối cùng lớn nhât
                }
            }
        }

        Z[i][0] = point[0]; // tìm 4 điểm gần nhất                       Z với i là vị trí của newpoint
                            // 0 1 2 3
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
    for (int iz = 0; iz < 500; iz++) // tìm z
    {
        float x_i = newPoint[iz].getX(), y_i = newPoint[iz].getY();
        float x_1 = Z[iz][0].getX(), x_2 = Z[iz][1].getX(), x_3 = Z[iz][2].getX(), x_4 = Z[iz][3].getX();
        float y_1 = Z[iz][0].getY(), y_2 = Z[iz][1].getY(), y_3 = Z[iz][2].getY(), y_4 = Z[iz][3].getY();
        float z_1 = Z[iz][0].getZ(), z_2 = Z[iz][1].getZ(), z_3 = Z[iz][2].getZ(), z_4 = Z[iz][3].getZ();

        float a_1 = (x_i * (z_2 - z_1) - z_2 * x_1 + z_1 * x_2) / (x_2 - x_1);

        float a_2 = (y_i * (z_3 - z_2) - z_3 * y_2 + z_2 * y_3) / (y_3 - y_2);

        float a_3 = (x_i * (z_3 - z_4) - z_3 * x_4 + z_4 * x_3) / (x_3 - x_4);

        float a_4 = (y_i * (z_4 - z_1) - z_4 * y_1 + z_1 * y_4) / (y_4 - y_1);

        float a_5 = (a_1 + a_2 + a_3 + a_4) / 4;

        newPoint[iz].setZ(a_5);

        //  cout << newPoint[iz].getX() << " " << newPoint[iz].getY() << " " << newPoint[iz].getZ() << endl;                //Xuất file số liệu kết quả ra ý
    }

    ofstream file_2;                                        //ghi dữ liệu vào file.txt
    file_2.open("write-File.txt", ios::out);
    cout << setprecision(10);
    for (int i = 0; i < 500; i++)
    {
        file_2 << newPoint[i].getX() << "  " << newPoint[i].getY() << "  " << newPoint[i].getZ() << endl;
    }

    file_2.close();

    system("pause");
    return 0;
}