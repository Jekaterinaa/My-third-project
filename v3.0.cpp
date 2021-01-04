#include "studentas.h"

int main()
{
    vector<duomuo> studentai, vargsiukai;
    skaicius sk;
    int kiek_paz, kiek;
    int gp;
    string pav;

    sk = duomenuGeneravimas();
    kiek = sk.kiek;
    kiek_paz = sk.kiek_paz;

    studentai = duomenuNuskaitymas(kiek, kiek_paz);
    duomenuDalijimas(studentai, vargsiukai, kiek);

    isvedimasIFaila(studentai, kiek);
    isvedimasIFaila(vargsiukai, kiek);

}