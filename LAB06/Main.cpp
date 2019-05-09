// Nazwa pliku wykonywalnego: mobile

// ** ZADANIE WYKONYWANE W PARACH ***
// Zespół:
// 1. Grzegorz Litarowicz
// 2. Bartlomiej Dlugosz

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Celem zadania jest rozszerzenie funkcjonalności dotychczas zaimplementowanego projektu.
// Tym razem rozszerzenie dotyczy operacji na współrzędnych geograficznych, czyli implementacje
// związane z wcześniej zdefiniowaną (lub nie) klasą GPS

// ZADANIE: Otrzymujecie Państwo implementacje klas typu Haversine niezbędnych do operacji 
// na współrzędnych geograficznych. Rzecz w tym, że nie implementacja ta nie jest kompletna,
// należy więc je uzupełnić, tak aby możliwy był do uruchomienia interfejs wykorzystany w poniższej
// funkcji main. Lista to do:
// - brakuje klasy Distance
// - klasa Coordinate powinna posiadać przeciążony odpowiedni operator
// - klasy Car, Gps należy wyposażyć w niezbędny interfejs

// Uwaga:Wymagania projektowe:
//      - Należy zadbać o zasadność zawieranie/dziedziczenia odpowiednich cech/informacji
//		- definicja klasy Distance ma wykorzystywać ideę delegowania konstruktorów;
// 		- Informacje o współrzednych (klasa Coordinate) zawarte są w klasie Gps
// 		- do policzenia dystansu w km pomiędzy dwoma wspolrzednymi wykorzystac 
//    	  funkcje Haversine(...) juz zdefiniowaną;

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

// Rozwiazanie (archiwum mobile_pairs.tar.gz zawierajace w folderze dodane pliki, makefile i Main.cpp)
// nalezy wgrac do UPEL.

#include "Main.h"

int main(){

	Car* mercedes = Car::Create("Mercedes");
	Car* ford = Car::Create("Ford");

	// Update location parameters stored in GPS Coordinate instance:
	Coordinate MercCoordinate ( mercedes->UpdateLocation(19.9449799,50.0646501) ); 	  // Longitude, Latitude; Krakow :)
	Coordinate FordCoordinate ( ford->UpdateLocation(21.012229,52.229676) );		  // Longitude, Latitude; Warszawa;

	MercCoordinate+=PointedDistance(2,"South"); // move 2 meters into South;
	MercCoordinate+=PointedDistance(5,"West"); 	// move 5 meters into West;
	FordCoordinate+=PointedDistance(1,"North"); // move 1 meters into South;
	FordCoordinate+=PointedDistance(3,"East"); 	// move 1 meters into East;

	Distance distanceBetweenCars(MercCoordinate,FordCoordinate);
	std::cout<<"[INFO]:: Mercedes location " << mercedes->GpsLocationInfo()<<"\n";
	std::cout<<"[INFO]:: Ford location     " << ford->GpsLocationInfo()<<"\n";
	std::cout<<"[INFO]:: M-F distance      " << distanceBetweenCars.Value() << " [km]\n";

	//// simple check:
	Distance distance(MercCoordinate.Longitude(),
						 MercCoordinate.Latitude(),
						 FordCoordinate.Longitude(),
						 FordCoordinate.Latitude());

	std::cout<<"[INFO]:: Distance check    " << distance.Value() << " [km]" <<std::endl;

	delete mercedes;
	delete ford;

	return 0;
}

/* Wynik dzialania programu:
brachwal@vbox:[build]$ ./Mobile 
[INFO]:: Mercedes location Longitude: 19.944981 Latitude: 50.064651
[INFO]:: Ford location     Longitude: 21.012230 Latitude: 52.229675
[INFO]:: M-F distance      252.013 [km]
[INFO]:: Distance check    252.013 [km]
*/
