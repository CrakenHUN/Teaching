#include <iostream>

using namespace std;

void PlusOne(int n);
void PlusOne_(int * n);
void PlusOne__(int &n);

int main() {
    //Deklaráljunk egy változót, és vizsgáljuk meg a függvény hívásokat
    int num = 0;
    cout << "main: num = " << num << endl;
    PlusOne(num);
    cout << "main: num = " << num << endl;    


    //mint látjuk, az n változót szabadon megnövelhetjük a függvényben, az eredeti nem változik
    //hagyományos ún. érték szerinti paraméter átadásban "belemásoljuk" a fv.-be a változónkat
    //így az eredeti érintetlen marad

    cout << endl << "-------" << endl << endl;

    PlusOne_(&num);
    cout << "main: num = " << num << endl;

    //Láthatjuk, hogy megváltozik az eredeti érték is
    //"konyhanyelven" úgy gondoljunk rá, hogy pointer-es paraméter átadásban a változó címét adjuk
    //át a memóriában.
    //Így értelemszerűen, ha azon a helyen átírom a biteket, megváltozik az eredeti változó értéke is

    //Mikor használjunk pointereket?
    //->Amikor nem lehet referencet használni
    //->Vagyis: amikor meg kell változtatni, hogy mire mutat. (pl. láncolt lista)


    cout << endl << "-------" << endl << endl;

    PlusOne__(num);
    cout << "main: num = " << num << endl;

    //Mint látjuk, a referencia hasonlóan működik a pointerhez. Valójában csak kettő különbség
    //van a kettő közt:
    //1) a referencia konstans, abban, hogy melyik változóra mutat. A változó -értéke- megváltozhat,
    //   de nem állíthatok át egy referenciát egy másik változóra, illetve muszáj inicializálni

    //int & numReference; //Hiba, okos IDE jelzi is compile előtt

    /*
    int & numReference = num;
    int tmp = 3;
    numReference = tmp; 
    //Ez csak átállítja num értékét 3-ra, nem tudok olyat, hogy numReference már tmp-re mutasson
    */

    //2) syntax sugar. a referenciát kényelmesebb használni mind a fv. megírásakor, és meghívásakor.


    //Szemlélet/konyhanyelv: a reference egy "álneve" a változónak. Ha ezen hívom, ugyanúgy hallgat rá
    //("alias"-nak is szokták nevezni)

    //Mikor használunk referencet?
    //->Amikor nem muszáj pointert használni, akkor jobban szeretjük
    //->Nagy objektumok érték szerinti átadásakor gazdaságosabb. (meg takarítunk plusz egy copy-t)
    return 0;
}

void PlusOne(int n) {
    n++;
    cout << "PlusOne: n = " << n << endl;
}

void PlusOne_(int * n) {
    *n += 1; //Ilyenkor nem *n++-ozunk, nem működik
    cout << "PlusOne_: n = " << *n << endl;
}

void PlusOne__(int & n) {
    n++;
    cout << "PlusOne__: n = " << n << endl;
}