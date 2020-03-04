#include <iostream>
#include <fstream>

using namespace std;

struct Kaktusz{
    string nev;
    string os;
    string szin;
};

void nyit(const string &fnev, const string &gnev, ifstream &f, ofstream &g);
void valogat(ifstream &f, ofstream &g);

void nyit(const string &fnev, const string &gnev, ifstream &f, ofstream &g)
{
    f.open(fnev.c_str());
    if(f.fail()) cout << "Rossz fajlnev!\n";

    g.open(gnev.c_str());
    if(g.fail()) cout << "Rossz fajlnev!\n";
}

void valogat(ifstream &x, ofstream &y)
{
    Kaktusz e;
    x >> e.nev >> e.os >> e.szin;
    while(!x.fail()){
        if( "piros"==e.szin)  y << e.nev << endl;
        x >> e.nev >> e.os >> e.szin;
    }
}

#define NORMAL_MODE
#ifdef NORMAL_MODE

using namespace std;

int main()
{
    ifstream x;
    ofstream y;
    nyit("inp.txt", "out.txt", x,y);
    valogat(x,y);

    return 0;
}


#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"


TEST_CASE("empty", "inp0.txt")
{
    ifstream x;
    ofstream y;
    nyit("inp0.txt", "out0.txt", x, y);
    valogat(x,y);

    ifstream h("out0.txt");
    int c = 0;
    string str;
    while(getline(h,str)) ++c;

    CHECK(0==c);
}

TEST_CASE("one", "inp1.txt")
{
    ifstream x;
    ofstream y;
    nyit("inp1.txt", "out1.txt", x, y);
    valogat(x,y);

    ifstream h("out1.txt");
    int c = 0;
    string str;
    while(getline(h,str)) ++c;

    CHECK(1==c);
}

TEST_CASE("two", "inp2.txt")
{
    ifstream x;
    ofstream y;
    nyit("inp2.txt", "out2.txt", x, y);
    valogat(x,y);

    ifstream h("out2.txt");
    int c = 0;
    string str;
    while(getline(h,str)) ++c;

    CHECK(2==c);
}

TEST_CASE("first", "inp3.txt")
{
    ifstream x;
    ofstream y;
    nyit("inp3.txt", "out3.txt", x, y);
    valogat(x,y);

    ifstream h("out3.txt");
    int c = 0;
    string str;
    while(getline(h,str)) ++c;

    CHECK(1==c);
}

TEST_CASE("last", "inp4.txt")
{
    ifstream x;
    ofstream y;
    nyit("inp4.txt", "out4.txt", x, y);
    valogat(x,y);

    ifstream h("out4.txt");
    int c = 0;
    string str;
    while(getline(h,str)) ++c;

    CHECK(1==c);
}

#endif
