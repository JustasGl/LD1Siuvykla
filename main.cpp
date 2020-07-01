#include <iostream>
#include <Kostiumas.h>
#include <Siuvykla.h>
#include <fstream>
#include <string>
#include <map>

using namespace std;
Siuvykla skaito(string FailPav, Kostiumas K[],int & KKiekis);
map<string, int> Skaiciavimas(Kostiumas k[],int & KKiekis);
double AtraizuKiekis(Kostiumas k[],int KKiekis);
void spausdina(Kostiumas k[], Siuvykla s,int KKiekis);
int main()
{
    cout<<"Kiek val dirba siuvykla?"<<endl;
    int val;
    cin>>val;
    int KKiekis=0;
    Siuvykla S;
    Kostiumas K[50];
    S=skaito("Duom.txt",K,KKiekis);
    S.PriskirtiDarboLaika(val);
    spausdina(K,S,KKiekis);
    return 0;
}
Siuvykla skaito(string FailPav,Kostiumas K[],int & KKiekis)
{
    string SPavadinimas;
    ifstream dataIn(FailPav.c_str());
    dataIn>>SPavadinimas;
    int DarbuotojuSk,Min;
    dataIn>>DarbuotojuSk;
    Siuvykla S(SPavadinimas,DarbuotojuSk);
    double Ilgis,Plotis,Proc;

    string KPavadinimas,Mpavadinimas;

    while(!dataIn.eof())
    {
        dataIn>>KPavadinimas>>Mpavadinimas>>Ilgis>>Plotis>>Proc>>Min;
        Kostiumas k(KPavadinimas,Mpavadinimas,Ilgis,Plotis,Proc,Min);
        K[KKiekis]=k;
        KKiekis++;
    }
    return S;
    dataIn.close();
}
map<string, int> Skaiciavimas(Kostiumas k[],int & KKiekis)//funkcija butu naudojama jei reiketu išgauti unikalios medziagos kostiumu plotus
{
    bool Rasti;
    map<string, int> Medz;
    for(int i=0; i<KKiekis; i++)
    {
       std::map<string, int>::iterator it = Medz.find(k[i].GautiMedziagosP());
        if (it != Medz.end()){
        it->second = it->second+k[i].GautiPlota();
        }
        else
        {
            Medz.insert(pair<string, int>(k[i].GautiMedziagosP(),k[i].GautiPlota()));
        }
    }
    return Medz;
}
double AtraizuKiekis(Kostiumas k[],int KKiekis)
{
    double rez = 0;
    for(int i=0;i<KKiekis; i++)
    {
        rez +=k[i].GautiAtraizas();
    }
    return rez;
}
void spausdina(Kostiumas k[], Siuvykla s,int KKiekis)
{
    for(int i=0; i<KKiekis; i++)
    {
        cout<<k[i].GautiModelioP()<<" kostiumu per savaite pasiutu "<<s.GautiDSk()*s.GautiDarboLaika()*60/k[i].GautiMin()<<endl;

    }
    cout<<"Viso atraizu reikes "<<endl<<AtraizuKiekis(k,KKiekis);

}
