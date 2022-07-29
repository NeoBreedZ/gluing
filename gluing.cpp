#include <filesystem>
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
namespace fs = std::filesystem;

int main() 
{
    setlocale(LC_ALL, "Russian");
    auto start = chrono::high_resolution_clock::now();

    string pathIn = "in";
    string pathOut = "out\\gotovo.txt";
    ofstream fout;
    ifstream fin;

    for (auto& p : fs::directory_iterator(pathIn))
    {

        if (p.path().extension() == ".txt" || p.path().extension() == ".dic") {
            string allPath = p.path().string();
            cout << allPath << endl;
            fin.open(allPath, ios::binary);
            fout.open(pathOut, ios::binary | ios::app);

            fin.seekg(0, ios::end);
            size_t sz = fin.tellg();
            char* buf = new char[sz];
            fin.seekg(0);
            fin.read(buf, sz);
            fout.write(buf, sz);
            fout << "\n";
            delete[] buf;

            fin.close();
            fout.close();
        }
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<float> duration = end - start;
    cout << "Duration " << duration.count() << " sec" << endl;

    system("PAUSE");
    return 0;
}