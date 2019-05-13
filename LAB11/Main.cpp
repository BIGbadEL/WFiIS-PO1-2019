// Nazwa pliku wykonywalnego: Mobile

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal sie, 
// a wynik jego dzialania byl taki sam jak podany na końcu tego pliku.

// Celem zadania jest rozszerzenie funkcjonalności wcześniej zaimplementowanego projektu 
// (w tym przypadku można wyorzystać kod z Lab06)
// Tym razem rozszerzenie dotyczy funkcji szablonowych, w dość nietypowym zastosowaniu.
// Mianowicie, chcemy aby jakims wiekszym programie wystepowala klasa Factory, ktora gwarantuje 
// ze mamy mozliwosc wytworzenia identycznych obiektow.
// Prosze zwrocic uwage ze same Factory nie jest szablonowa a tylko funkcje sa szablonowe.
// W rozwiazaniu nalezy skozystac ze statycznych skladnikow funkcji i tego ze kazda instancjacja 
// szablonu to jest odrebna funkcja.

// Pliku Main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec czytelny i dobrze napisany kod).

// Makefile (lub CMakeLists.txt) dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie mobile. Program nalezy kompilowac z flagami -Wall -g.
// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki obiektowe i plik wykonywalny.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow (w tym wlasnych wczesniej
// przygotowanych plikow oprocz makefile)

// Rozwiazanie (archiwum mobile12.tar.gz zawierajace w folderze dodane pliki, makefile i Main.cpp)
// nalezy wgrac do UPEL.

#include "Main.h"

int main(){

	Factory factory1;
	factory1.prototype<Mercedes>(Mercedes("ON",65,1598)); // paliwo, moc [kW], pojemnosc [cm^3]
	factory1.prototype<Ford>(Ford("Pb98",45,1398));  	  // paliwo, moc [kW], pojemnosc [cm^3]

	Mercedes merc1 = factory1.produce<Mercedes>();
	std::cout<< merc1 <<"\n";

	std::cout << "[****] Wymiana fabryki ***" << std::endl;
	Factory factory2;
	Mercedes merc2 = factory2.produce<Mercedes>();
	std::cout<< merc2 <<"\n";

	std::cout << "[****] Wymiana prototypu ***" << std::endl;
	factory2.prototype<Mercedes>(Mercedes("Pb98",75,1098)); // paliwo, moc [kW], pojemnosc [cm^3]
	Mercedes merc3 = factory2.produce<Mercedes>();
	std::cout<< merc3 <<"\n";

	return 0;
}

/* Wynik dzialania programu:
brachwal@vbox:[build]$ ./Mobile 
[INFO] Car:: Type Mercedes
[INFO] Car:: Color Red
[INFO] Engine:: Fluel ON
[INFO] Engine:: Capacity 1598 [cm^3]
[INFO] Engine:: Power 65 [kW]
[****] Wymiana fabryki ***
[INFO] Car:: Type Mercedes
[INFO] Car:: Color Red
[INFO] Engine:: Fluel ON
[INFO] Engine:: Capacity 1598 [cm^3]
[INFO] Engine:: Power 65 [kW]
[****] Wymiana prototypu ***
[INFO] Car:: Type Mercedes
[INFO] Car:: Color Red
[INFO] Engine:: Fluel Pb98
[INFO] Engine:: Capacity 1098 [cm^3]
[INFO] Engine:: Power 75 [kW]
*/
