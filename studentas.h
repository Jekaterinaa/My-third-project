#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <numeric>
#include <random>
#include <chrono>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;

float vidurkis(vector <float>);

struct skaicius {
    int kiek;
    int kiek_paz;
};

class zmogus {

public:
    string vardas;
    string pavarde;

    virtual void spausdinti() = 0;

    string getVardas() const
    {
        return vardas;
    }

    string getPavarde() const
    {
        return pavarde;
    }

};

class duomuo : public zmogus{
private:
    //string vardas;
    //string pavarde;
    vector <float> paz;
    float egz;
    float gp;

public:
    duomuo(string vardas, string pavarde, vector <float> paz, float egz)
    {
        this->vardas = vardas;
        this->pavarde = pavarde;
        this->paz = paz;
        this->egz = egz;
        this->gp = vidurkis(paz) * 0.4 + 0.6 * egz;
    }

    ~duomuo() {

    }

    duomuo(const duomuo& objektas) {
        vardas = objektas.vardas;
        pavarde = objektas.pavarde;
        paz = objektas.paz;
        egz = objektas.egz;
        gp = objektas.gp;
    }

    duomuo& operator = (const duomuo& objektas) {
        vardas = objektas.vardas;
        pavarde = objektas.pavarde;
        paz = objektas.paz;
        egz = objektas.egz;
        gp = objektas.gp;
        return *this;
    }

    void spausdinti() {
        cout << vardas << " " << pavarde << endl;
    }

    void spausdintiStudenta(int kiek_paz) {
        cout << vardas << " " << pavarde << " ";
        for (int i = 0; i < kiek_paz; i++) {
            cout << paz.at(i) << " ";
        }
        cout << egz << endl;
    }

    void spausdintiSuGP() {
        cout << vardas << " " << pavarde << " " << gp << endl;
    }


    float getGP() const
    {
        return gp;
    }

};

skaicius duomenuGeneravimas();
vector <duomuo> duomenuNuskaitymas(int, int);
void duomenuDalijimas(vector <duomuo>&, vector <duomuo>&, int);
void isvedimasIFaila(vector <duomuo>, int);
