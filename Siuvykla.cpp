#include "Siuvykla.h"

Siuvykla::Siuvykla(string P, int D)
{
      Pavadinimas = P;
      DarbuotojuSk = D;
}
Siuvykla::Siuvykla()
{
}
 string Pavadinimas;
 int DarbuotojuSk;
 int DarboLaikas;

 string Siuvykla::GautiPavadinimas(){
    return Pavadinimas;
 }
 int Siuvykla::GautiDSk(){
    return DarbuotojuSk;
 }
 int Siuvykla::GautiDarboLaika()
 {
     return DarboLaikas;
 }
 void Siuvykla::PriskirtiDarboLaika(int d)
 {
    DarboLaikas=d;
 }
