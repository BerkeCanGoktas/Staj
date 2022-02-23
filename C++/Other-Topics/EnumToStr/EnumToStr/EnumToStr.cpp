// EnumToStr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

//enum Motorbikes
//{
//    Suzuki_Bandit = 0,
//    SHonda_TransAlp = 1,
//    BMW_F_650_GS = 2,
//    Kawasaki_ZZR1400 = 3
//};

enum Motorbikes {
#   define X(a) a,
#   include "Motorbikes.def"
#   undef X
    MotorbikesCount
};

static Motorbikes motorbike;

char const* const motorbikes_str[] = {
#   define X(a) #a,
#   include "Motorbikes.def"
#   undef X
    0
};

ostream& operator<<(ostream& os, enum Motorbikes c)
{
    if (c >= MotorbikesCount || c < 0) return os << "???";
    return os << motorbikes_str[c];
}


Motorbikes atamaOperatoru() {
    string x;
    cin >> x;
    for (int i = 0; i < sizeof(motorbikes_str); i++) {
        if (x == motorbikes_str[i]) {
            motorbike = Motorbikes(i);
            //cout << i;
            //cout << motorbike << endl;
            return motorbike;
        }
    }
}


//istream& operator >> (istream& in, const char* a) //
//{
//    //cout << "overload" << endl;
//    cout << a;
//    for (int i = 0; i < sizeof(motorbikes_str); i++) {
//        if (a == motorbikes_str[i]) {
//             motorbike = Motorbikes(i);
//             //cout << i;
//             //cout << motorbike << endl;
//             return in;
//        }
//        //else {
//        //    try {
//        //        if (i == sizeof(motorbikes_str)) { // girmiyor düzgün statement kurmak lazım
//        //            string e = "Invalid name";
//        //            throw(e);
//        //        }
//        //    }
//        //    catch (string e) {
//        //        cout << e << endl;
//        //    }
//        //}
//    }
//}

int main()
{
    cout << Suzuki_Bandit << endl;
    //const char* x = "SHonda_TransAlp"; // kullanıcıdan alamıyorum
    //string x;
    atamaOperatoru();
    cout <<  motorbike << endl;
    //cout << x;
    cout << (motorbike == 1) << endl;
    atamaOperatoru();
    cout << motorbike << endl;
    //cout << x;
    cout << (motorbike == 2) << endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
