#ifndef SIUVYKLA_H
#define SIUVYKLA_H
#include <string>
using namespace std;

class Siuvykla
{
    public:
        Siuvykla(string P, int D);
        Siuvykla();
        string GautiPavadinimas();
        int GautiDSk();
        int GautiDarboLaika();
        void PriskirtiDarboLaika(int d);
    protected:

    private:
        string Pavadinimas;
        int DarbuotojuSk;
        int DarboLaikas;
};

#endif // SIUVYKLA_H
