#include "studentas.h"

float vidurkis(std::vector<float> v) {
    float sum, vid;
    sum = std::accumulate(v.begin(), v.end(), 0.0);
    vid = sum / (float)v.size();
    return vid;
}

skaicius duomenuGeneravimas() {

    skaicius sk;

    std::mt19937 mt(1729);
    std::uniform_int_distribution<int> dist(1, 10);

    vector <duomuo> studentai;

    cout << "iveskite studentu skaiciu" << std::endl;
    cin >> sk.kiek;
    cout << "iveskite pazymiu skaiciu" << std::endl;
    cin >> sk.kiek_paz;

    string pav;
    pav = "studentai" + std::to_string(sk.kiek) + ".txt";

    std::ofstream naujas(pav);
    int temp;

    auto start = std::chrono::high_resolution_clock::now(); auto st = start;

    for (int i = 0; i < sk.kiek; i++) {
        naujas << "Vardas" << std::to_string(i + 1) << std::setw(20) << "Pavarde" << std::to_string(i + 1);
        for (int j = 0; j < sk.kiek_paz; j++) {
            temp = dist(mt);
            naujas << std::setw(15) << (float)temp;
        }
        temp = dist(mt);
        naujas << std::setw(15) << (float)temp << std::endl;
    }
    naujas.close();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Failo su " << sk.kiek << " eiluciu duomenu generavimas trunka : " << diff.count() << " s\n";

    return sk;

}

vector <duomuo> duomenuNuskaitymas(int kiek, int kiek_paz)
{

    string vardas, pav;
    float paz, egz;
    vector <float> paz2;
    vector <duomuo> studentai;

    pav = "studentai" + std::to_string(kiek) + ".txt";

    auto start = std::chrono::high_resolution_clock::now(); auto st = start;

    std::ifstream duomenys;
    duomenys.open(pav);

    while (duomenys.eof() != true) {
        duomenys >> vardas >> pav;
        paz2.clear();
        for (int j = 0; j < kiek_paz; j++) {
            duomenys >> paz;
            paz2.push_back(paz);
        }
        duomenys >> egz;

        duomuo naujas(vardas, pav, paz2, egz);
        studentai.push_back(naujas);
    }

    duomenys.close();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << kiek << " duomenu nuskaitymas is failo trunka : " << diff.count() << " s\n";

    return studentai;
}

void duomenuDalijimas(vector <duomuo>& studentai, vector <duomuo>& vargsiukai, int kiek)
{
    float gp;
    auto start = std::chrono::high_resolution_clock::now(); auto st = start;

    for (duomuo stud : studentai) {
        gp = stud.getGP();
        if (gp < 5.0) {
            vargsiukai.push_back(stud);
        }
    }
    studentai.erase(std::remove_if(studentai.begin(), studentai.end(), [](duomuo stud)
        {
            return stud.getGP() < 5.0;
        }), studentai.end());

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << kiek << " studentu dalijimas i vargsiukus ir kietiakius trunka : " << diff.count() << " s\n";
}

void isvedimasIFaila(vector <duomuo> studentai, int kiek)
{
    string pav, zodis;
    int ilgis = studentai.size();

    if (!studentai.empty()) {
        auto start = std::chrono::high_resolution_clock::now(); auto st = start;

        if (studentai.front().getGP() < 5.0) {
            pav = "vargsiukai" + std::to_string(kiek) + ".txt";
            zodis = "Vargsiuku";
        }
        else {
            pav = "kietiakiai" + std::to_string(kiek) + ".txt";
            zodis = "Kietiakiu";
        }
        std::ofstream failas(pav);

        for (duomuo stud : studentai) {
            failas << stud.getVardas() << std::setw(20) << stud.getPavarde() << std::setw(15) << stud.getGP() << endl;
        }
        failas.close();

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        std::cout << zodis << " isvedimas i faila trunka : " << diff.count() << " s\n";
    }
    else {
        return;
    }
}