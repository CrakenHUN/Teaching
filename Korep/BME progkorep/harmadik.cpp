#include <iostream>
#include <conio.h>  // C-b�l k�lcs�nvessz�k a getch_ 

using namespace std;

class kave_automata {
private:
	bool kave_gomb;
	bool megszakit_gomb;
	int penz; // felhaszn�l� �ltal bedobott p�nz
	int kave_ara;
	int bevetel; // a kav�automat�b�l sz�rmaz� p�nz
public:

	kave_automata() {
		kave_gomb = false;
		megszakit_gomb = false;
		penz = 0;
		bevetel = 0;
		kave_ara = 50;
	}

	kave_automata(int kave_ara) {
		kave_gomb = false;
		megszakit_gomb = false;
		penz = 0;
		bevetel = 0;
		this->kave_ara = kave_ara;
	}

	void penz_bedob(int p) {
		penz += p;
		frissit();

	}
	void kave_gomb_megnyom() {
		kave_gomb = true;
		frissit();
	}
	void megszakit_gomb_megnyomasa() {
		megszakit_gomb = true;
		frissit();
	}

	int get_penz() {
		return penz;
	}
	int get_bevetel() {
		return bevetel;
	}
	void frissit() {
		//egyszerre nem lehet mind a k�t gomb megnyomva (els� �s m�sodik)
		if (kave_gomb && megszakit_gomb) {
			kave_gomb = false;
			megszakit_gomb = false;
		}
		if (kave_gomb && !megszakit_gomb && penz < kave_ara) {
			cout << "Nincs eleg penz a kavera!" << endl;
			kave_gomb = false;
		}
		if (kave_gomb && !megszakit_gomb && penz >= kave_ara) {
			int kave_db = penz / kave_ara;
			int visszajaro = penz % kave_ara;

			penz = 0;
			bevetel += kave_db * kave_ara;
			kave_gomb = false;

			cout << kave_db << " db kave kiadva. A visszajaro: " << visszajaro << " FT" << endl;
		}
		if (!kave_gomb && megszakit_gomb && penz) {
			cout << "Megszakitas. Penz visszaadva: " << penz << " Ft" << endl;
			penz = 0;
			megszakit_gomb = false;
		}

		if (!kave_gomb && !megszakit_gomb && penz < kave_ara) {
			// nem tortenik semmi
		}

	}

};

int main() {

	// deklar�ljunk egy kaveautomata tipusu valtozot
	kave_automata automata;
	int ar;

	cout << "KAVE AUTOMATA" << endl;
	cout << "_____________" << endl;
	cout << "A kave ara: ";


	cin >> ar;

	automata = kave_automata(ar);

	cout << "Az automata keszen all!" << endl;

	char c; // felhaszn�l� bemenete
	int p;


	while ((c = _getch()) != 27) {
		switch (c) {
		case 'b': // p�nzt szeretn�nk bedobni
			cout << "penz: ";
			cin >> p;

			// megh�vjuk az automata t�rgyf�ggv�ny�t
			automata.penz_bedob(p);
			p = 0;
			cout << "Bedobott osszeg: " << automata.get_penz() << endl;
			break;
		case 'k': // k�v� gomb
			automata.kave_gomb_megnyom();
			break;
		case 'm': //megszakit gomb
			automata.megszakit_gomb_megnyomasa();
			break;
		default: //nem csin�lunk semmit
			break;
		}
	}

	cout << "A kave automatat felszamoltak." << "Az automatrabol szarmazo bevetel: " << automata.get_bevetel() << endl;


	cin.get();
	return 0;
}