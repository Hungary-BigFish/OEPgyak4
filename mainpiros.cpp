#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("inp.txt");
    ofstream g("out.txt");

    string nev, os, szin;
    f >> nev >> os >> szin;
    while(!f.fail()){
        if ("piros"==szin) g << nev << endl;
        f >> nev >> os >> szin;
    }
    return 0;
}
