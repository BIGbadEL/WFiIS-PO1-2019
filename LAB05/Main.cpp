// Nazwa pliku wykonywalnego: mobile

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Celem zadania jest wykorzystanie metody wytwórczej typu fabryka.
// Fabryka służy do tworzenia nowych obiektów, nieokreślonych, 
// lecz związanych z jednym, wspólnym interfejsem. W naszym przypadku
// odpowiedzialność na tworzenie konkretnych modeli samochodów
// spoczywa na klasie Car

// Uwaga:Wymagania projektowe:
//       - klasa Car jest klasą abstrakcyjną, posiadająca interfejs dla klas pochodnych
//         tj. Mercedes, Ford;
//       - ma być wykorzystane override
//       - Należy zadbać o odpowiedni podział odpowiedzialności przechowywania (tnz. w której klasie) 
//         informacji na temat modelu GPS w danej modelu samochodu.

// W zadaniu mozna korzystac z elementow bilbioteki standardowej
// zwlaszcza klasy std::string oraz std::vector

// Pliku Main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod).

// Makefile (lub CMakeLists.txt) dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie mobile. Program nalezy kompilowac z flagami -Wall -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow (w tym wlasnych wczesniej
// przygotowanych plikow oprocz makefile)

// Rozwiazanie (archiwum mobile4.tar.gz zawierajace w folderze dodane pliki, makefile i Main.cpp)
// nalezy wgrac do UPEL.

#include "Main.h"

int main()
{

   Car* mercedes = Car::Create("Mercedes");
   std::cout<< *mercedes << std::endl;
   std::cout<< "Gps type info: " << mercedes->GpsInfo() << std::endl;

   Car* ford = Car::Create("Ford");
   std::cout<< *ford << std::endl;
   std::cout<< "Gps type info: " << ford->GpsInfo() << std::endl;
   
   delete mercedes;
   delete ford;

   return 0;
}

/* Wynik dzialania programu:
brachwal@vbox:[build]$ ./Mobile 
[INFO] Car:: Type Mercedes A
[INFO] Car:: Color Red
[INFO] Engine:: Fluel ON
[INFO] Engine:: Capacity 1598 [cm^3]
[INFO] Engine:: Power 65 [kW]
Gps type info: M/Garmin/No.000.000

[INFO] Car:: Type Ford Fiesta
[INFO] Car:: Color Red
[INFO] Engine:: Fluel Pb98
[INFO] Engine:: Capacity 1398 [cm^3]
[INFO] Engine:: Power 45 [kW]
Gps type info: F/Google/No.000.000
*/
