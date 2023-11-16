#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<ctime>
#include<list>
using namespace std;

class Karta
{
public:
int broj;
string zog;
};
class Mac
{
public:
vector<Karta> deck;

void stvori_deck()
{
string stringovi[4] = { "Kupe", "Bate", "Dinari", "Spade" };
for (int i = 0; i < 4; i++)
{
for (int j = 1; j <= 13; j++)
{
if (j == 8 || j == 9 || j == 10)
continue;
else
{
Karta nova_karta;
nova_karta.broj = j;
nova_karta.zog = stringovi[i];
deck.push_back(nova_karta);
}
}
}
}

void promijesaj_karte()
{
srand(static_cast<unsigned int>(time(0)));
random_shuffle(deck.begin(), deck.end());
}
};

class Igrac
{
public:
string ime;
vector<Karta> ruka;
int broj_bodova;

void akuziraj()
{
int akuzaj = 0;
int br1 = 0, br2 = 0, br3 = 0, brk = 0, brb = 0, brs = 0, brd = 0;

for (int i = 0; i < ruka.size(); i++)
{
if (ruka[i].broj == 1)
{
br1++;
if (ruka[i].zog == "Kupe")
brk++;
if (ruka[i].zog == "Bate")
brb++;
if (ruka[i].zog == "Spade")
brs++;
if (ruka[i].zog == "Dinari")
brd++;
}
if (ruka[i].broj == 2)
{
br2++;
if (ruka[i].zog == "Kupe")
brk++;
if (ruka[i].zog == "Bate")
brb++;
if (ruka[i].zog == "Spade")
brs++;
if (ruka[i].zog == "Dinari")
brd++;
}
if (ruka[i].broj == 3)
{
br3++;
if (ruka[i].zog == "Kupe")
brk++;
if (ruka[i].zog == "Bate")
brb++;
if (ruka[i].zog == "Spade")
brs++;
if (ruka[i].zog == "Dinari")
brd++;
}
}

if (br1 >= 1 && br2 >= 1 && br3 >= 1 && (brs >= 3 || brb >= 3 || brk >= 3 || brd >= 3))
akuzaj += 3;

if (br1 >= 3)
akuzaj += 3;
if (br2 >= 3)
akuzaj += 3;
if (br3 >= 3)
akuzaj += 3;
if (br1 >= 4 || br2 >= 4 || br3 >= 4)
akuzaj += 1;

broj_bodova += akuzaj;
}
};

void podijeli_karte(Mac& mac, vector<Igrac>& igraci)
{
for (int i = 0; i < igraci.size(); i++)
{
for (int j = 0; j < 10; j++)
{
igraci[i].ruka.push_back(mac.deck.back());
mac.deck.pop_back();
}
}
}

int main()
{
int brojIgraca;
cout << "Unesite koliko zelite imati igraca? (2 ili 4)";
cin >> brojIgraca;

if (brojIgraca != 2 && brojIgraca != 4)
{
cout << "\nMolimo unesite pravilan broj igraca. (2 ili 4)";
cin >> brojIgraca;
}

vector<Igrac> igraci;
igraci.resize(brojIgraca);

for (int i = 0; i < brojIgraca; i++)
{
cout << "Unesite ime igraca: ";
cin >> igraci[i].ime;
}

Mac deck;
deck.stvori_deck();
deck.promijesaj_karte();

podijeli_karte(deck, igraci);

for (int i = 0; i < brojIgraca; i++)
{
cout << "Ruka igraca " << igraci[i].ime << ": ";
for (const auto& karta : igraci[i].ruka)
{
cout << karta.broj << " " << karta.zog << " | ";
}
cout << endl;
}

return 0;
}


