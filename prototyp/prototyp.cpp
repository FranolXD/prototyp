#include <algorithm> // dla max i min
#include <limits>    // dla std::numeric_limits
#include <string>// stringi
#include <iostream>// PODSTAWOWA BIBLIOTEKA 
#include <fstream>//odczyt pliku
#include <cstdlib>//zeby CLS DZIALAL
#include <vector>//wektory z tekstami
#include <stdlib.h>//dla exit
//#include <cctype>>>>> nie aktualne
#include <climits>//dla INT_MAX
#include <windows.h>//do czekania ----dalej nie chce działać----
#include <time.h>//dla exit


//wystarczylo napisac z duzej litery

char zak = 0;//zmienna do zakładu
char odpchar(std::string pyt) {
	char odp;
	std::cout << pyt << "\n";
	std::cin >> odp;
	return odp;
}


std::fstream plik;//do odczytu

std::vector<std::string> Wyniki;// olsnilo mnie pusty wektor do ktorego bede wrzudcal wyniki i potem to posortuje chyba sort() da rede
std::vector<std::string> ZaMalo{ {"\n			troche za malo\n"}, {"\n			dodaj jeszcze troszke\n"}, {"\n			to nawet nie jest wystarczajaco\n"}, {"\n			majsterek, daj muuu\n"}, {"\n			wincej\n"} };
std::vector<std::string> ZaDuzo{ {"\n			troche za duzo\n"}, {"\n			jeszcze troszke odejmij\n"}, {"\n			no bez przesady, za duzo\n"}, {"\n			majsterek, a zes duzo dal\n"}, {"\n			mnij\n"} };//wektory za duzo za malo


std::string lin;//zeby czytalo po całej linijce
std::string nick;
std::string f;// nick gracza
std::string b;//zmienna do poziomu trud
std::string start = "					Witaj Drogi Uzytkowniku \n				Oto jakze wymagajaca gra Zgadnij Liczbe"; //jakiś ekranik startowy
std::string odpTekst(std::string pytanie) // funkcja pyt o tekst
{
	std::string odpowiedz;
	std::cout << pytanie << "\n";
	std::cin >> odpowiedz;  
	return odpowiedz;
}

std::string ZM(std::vector<std::string> ZaMalo) {
	int indeks = rand() % ZaMalo.size();
	return ZaMalo[indeks];
}
std::string ZD(std::vector<std::string> ZaDuzo) {
	int indeks = rand() % ZaDuzo.size();
	return ZaDuzo[indeks];//funkcje losujace odp z wektorow
}


int odpLiczba(std::string pytanie)// funkcja pyt o liczb cał
{
	int odpowiedz;
	std::cout << pytanie << "\n";
	std::cin >> odpowiedz;  
	return odpowiedz;
}
int e; //zmienna zeby topka sie nie wykrzaczala
int q; // do petli z topka
int x;//liczba do zgadniecia
int y;//zmienna żeby pętla się nie wykrzaczyła
int z;//zakres liczby do zgadnięcia
int l;//liczba ktora poda gracz
int i;	//zmienna dla petli
int pkt;//do sprawdzenia czy jest plik
int a = 0;//żeby odczytywalo od samego poczatku xD
//int f = 0; //zmienna do obliczenia pkt (tylko pytanie jaki stobić mnożnik pktów np całość to jakieś 1k potem -s razy cos innego co będzie zalezne od poziomu trudniści idk)
	//nie aktualne

std::string odptekst(std::string pyt) {
	std::string odp;
	std::cout << pyt << "\n";
	std::cin >> odp;
	return odp;
}
int odpliczb(std::string pyt) {
	int odp;
	std::cout << pyt << "\n";	
	std::cin >> odp;
	return odp;

}

int zgadnij(int x) {
	int p = 1;//resetowanie prób przy ponownym graniu

	do {
		
		while (!(l = odpliczb("\n					odgadnij liczbe"))) {
			std::cin.clear(); // czyści flagę błędu strumienia
			std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n'); // ignoruje niepoprawne dane wejściowe
			std::cout << "to nie jest liczba :\n";
		}
		if (l < x) {	
			std::cout <<"						"<< ZM(ZaMalo) << "					proba nr " << p << "\n\n";
			p++;
		}
		else if (l > x) {
			std::cout << "						" << ZD(ZaDuzo) << "					proba nr " << p << "\n\n";
			p++;
		}
	} while (l != x);
	std::cout << "\n\n		Gratulacje Uzytkowniku, udalo ci sie odgadnac liczbe " << x << " na poziomie " << b << " w " << p << " podejsciach \n\n";
	Sleep(1000);
	f = odpTekst("\n						podaj swoj nick bambusie : \n");
	if (b == "latwy") {
		plik.open("top5GraczyLatwy.txt", std::ios::out | std::ios::app);//zeby dopisywao wyniki
		plik << p << " razy  gracz " << f << " probowal odgadnac liczbe na poziomie " << b << "\n";
		plik.close();
		Sleep(3000);
		system("cls");
	}
	else if (b == "sredni") {
		plik.open("top5GraczySredni.txt", std::ios::out | std::ios::app);//zeby dopisywao wyniki
		plik << p << " razy  gracz " << f << " probowal odgadnac liczbe na poziomie " << b << "\n";
		plik.close();
		Sleep(3000);
		system("cls");
	}
	else if (b == "trudny") {
		plik.open("top5GraczyTrudny.txt", std::ios::out | std::ios::app);//zeby dopisywao wyniki
		plik << p << " razy  gracz " << f << " probowal odgadnac liczbe na poziomie " << b << "\n";
		plik.close();
		Sleep(3000);
		system("cls");
	}
	else if (b == "custom") {
		std::fstream plik;
		plik.open("top5SuperGraczyWZgadnijLiczbeXD.txt", std::ios::out | std::ios::app);//zeby dopisywao wyniki
		plik << p << " razy  gracz " << f << " probowal odgadnac liczbe na poziomie " << b << "\n";
		plik.close();
		Sleep(3000);
		system("cls");
	}
	return x;
}
int main()
{
	std::cout << start;
	for (i = 1; i <= 1;) { //tu będzie pętla 
		std::cout << "\n\n					Ponizej sa dostepne opjce\n\n			[graj]			[top 5]			[wyjscie]\n\n";
		std::string wybor = odpTekst("\n			  		  Wpisz swoj wybor: "); //co dalej?
		system("cls");
		if (wybor == "graj" || wybor == "play" || wybor == "p" || wybor == "g") {
			/*char zak = odpchar("\n	Psst \nMoze jakis zakladzik :3 ?\n			[ t / n ]");//bo switch daiala tylko z intem i charem
			switch (zak)
			{
			case 't': {
				int zaklad = odpliczb("\n			podaj liczbe prob hazardzisto:");
			}
				break;
			default: "\n			No to do zobaczenia innym razem\n";
				break;
			}*/
			std::string poziom = odptekst("\n				Wybierz poziom trudnosci:\n [latwy (1-10)]		[sredni (1-250)]		[trudny (1-500]		[custom ???]");

			if (poziom == "latwy" || poziom == "łatwy" || poziom == "lat" || poziom == "l") {
				b = "latwy";
				x = rand() % 10 + 1;//tu kurde trzeba dodać jedynkę bo inaczej scamuje i liczy od zera

			}
			else if (poziom == "sredni" || poziom == "średni" || poziom == "sre" || poziom == "s") {
				b = "sredni";
				x = rand() % 250 + 1;

			}
			else if (poziom == "trudny" || poziom == "tru" || poziom == "t") {
				b = "trudny";
				x = rand() % 500 + 1;

			}
			else if (poziom == "custom" || poziom == "cus" || poziom == "c") {
				while (!(z = odpliczb("					podaj zakres"))) {
					std::cin.clear(); // czyści flagę błędu strumienia
					std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n'); // ignoruje niepoprawne dane wejściowe
					std::cout << "to nie jest liczba :\n";
				}
				b = "custom";
				if (z > 1 && z < INT_MAX) {
					std::cout << "					Dobra to lecimy";
					Sleep(2000);
					x = rand() % z + 1;
				}
				else
				{ 
				z = INT_MAX; // jeśli bedzie minus albo wieksz od max
					std::cout << "						zła odpowiedź \n					<{ WŁĄCZAM TRYB ULTIMATE }>\n";
					x = rand() % z + 1;
				}
			}
			system("cls");
			do {
				y = zgadnij(x);
			} while (y != x);



		}
		else if (wybor == "top 5" || wybor == "top" || wybor == "topka" || wybor == "top5" || wybor == "t") {
			for (q = 1; q <= 1;) {
				std::string wybor = odpTekst("\n				   Wpisz jaka topke chcesz zobaczyc:\n	\n	[latwy]			[sredni]		[trudny]		[custom]");//to bedzie wybieralo jaka topke
				e = 0;//zerowanie zeby topka sie nie wykrzaczala
				if (wybor == "latwy" || wybor == "łatwy" || wybor == "l") {
					plik.open("top5GraczyLatwy.txt", std::ios::in); //to bedzie otwieralo plik
					if (plik.good() == false) {// a to bedzie sprawdzalo czy plik istnieje a jakl nie to notka
						std::cout << "\n\n			Najpierw wykrec jakis dobry wynik mlody padawanie :P\n\n";

					}
					else {
						Wyniki.clear();//czyszcenie wektora zeby wszystko bylo ladnie pieknie
						while (getline(plik, lin)) {
							Wyniki.push_back(lin);
						}
						std::sort(Wyniki.begin(), Wyniki.end());//sortowanie wektora
						if (Wyniki.size() < 6) {
						e = Wyniki.size();
						}
						else {
							e = 6;
						}
						for (i = 0; i < e; i++) {
							std::cout << "\n" << Wyniki[i];
						}
						plik.close();
						q++;
					}
				}
				else if (wybor == "sredni" || wybor == "średni" || wybor == "s") {
					plik.open("top5GraczySredni.txt", std::ios::in); //to bedzie otwieralo plik
					if (plik.good() == false) {// a to bedzie sprawdzalo czy plik istnieje a jakl nie to notka
						std::cout << "\n\n			Najpierw wykrec jakis dobry wynik mlody padawanie ;)\n\n";

					}
					else {
						Wyniki.clear();//czyszcenie wektora zeby wszystko bylo ladnie pieknie
						while (getline(plik, lin)) {
							Wyniki.push_back(lin);
						}
						std::sort(Wyniki.begin(), Wyniki.end());//sortowanie wektora
						if (Wyniki.size() < 6) {
							e = Wyniki.size();
						}
						else {
							e = 6;
						}
						for (i = 0; i < e; i++) {
							std::cout << "\n" << Wyniki[i];
						}
						plik.close();
						q++;
					}
				}
				else if (wybor == "trudny" || wybor == "t") {
					plik.open("top5GraczyTrudny.txt", std::ios::in); //to bedzie otwieralo plik
					if (plik.good() == false) {// a to bedzie sprawdzalo czy plik istnieje a jakl nie to notka
						std::cout << "\n\n			Najpierw wykrec jakis dobry wynik mlody padawanie ;)\n\n";

					}
					else {
						Wyniki.clear();//czyszcenie wektora zeby wszystko bylo ladnie pieknie
						while (getline(plik, lin)) {
							Wyniki.push_back(lin);
						}
						std::sort(Wyniki.begin(), Wyniki.end());//sortowanie wektora
						if (Wyniki.size() < 6) {
							e = Wyniki.size();
						}
						else {
							e = 6;
						}
						for (i = 0; i < e; i++) {
							std::cout << "\n" << Wyniki[i];
						}
						plik.close();
						q++;
					}
				}
				else if (wybor == "custom" || wybor == "c") {
					plik.open("top5SuperGraczyWZgadnijLiczbeXD.txt", std::ios::in); //to bedzie otwieralo plik
					if (plik.good() == false) {// a to bedzie sprawdzalo czy plik istnieje a jakl nie to notka
						std::cout << "			Najpierw wykrec jakis dobry wynik mlody padawanie ;)\n\n";

					}
					else {
						Wyniki.clear();//czyszcenie wektora zeby wszystko bylo ladnie pieknie
						while (getline(plik, lin)) {
							Wyniki.push_back(lin);
						}
						std::sort(Wyniki.begin(), Wyniki.end());//sortowanie wektora
						if (Wyniki.size() < 6) {
							e = Wyniki.size();
						}
						else {
							e = 6;
						}
						for (i = 0; i < e; i++) {
							std::cout << "\n" << Wyniki[i];
						}
						plik.close();
						q++;
					}
				}
				else {
					std::cout << "\n				nie ma takiego poziomu mordeczko	'o' \n\n";
				}
				Sleep(5000); 
				a = 0;//resetowanie zeby przy ponownym wyswietleniu topki dzialalo
				system("cls");
			}
		}
		else if (wybor == "wyjscie" || wybor == "w" || wybor == "exit" || wybor == "e") {
			std::cout << "\n						No to Siema Byczq\n\n";
			Sleep(2000);
			exit(0);//zamykanie programu
		}
		else if (wybor == "napoj" || wybor == "n") {
			i++;
		}
		else if (wybor == "misiu" || wybor == "m") {
			std::cout << "\n		Misiu cie pozdrawia\n		Takze czuj sie wyjatkowy";
			Sleep(3000);
		}
		else if (wybor == "2137") {
			std::cout << "oj nie ladnie\a  \a  \a  \a  \a  \a  \a  \a  \a  \a  \a  \a\n";
			for ( e = 0; e < 10; e++)
			{
				Sleep(500);
				std::cout << "\a papiez cie obserwuje \a\n";
		}
		//R po to by dalo sie nie bawic z zwyklym stringiem bo on papieza nie lubi
			std::cout << R"(
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡠⠤⠲⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡴⢛⣁⣤⣤⣤⡤⠤⠤⠄⠤⢄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⠿⡿⡿⠉⠀⠈⠀⠙⡀⠀⠀⠀⠀⠈⠙⠲⢄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⣧⠀⡟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡕⢄⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⣿⣿⢸⣿⠀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣌⢆⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⣧⣼⣿⡆⠙⠓⠀⠘⡢⣄⡀⠀⢀⡀⠀⠀⠀⠀⠀⢻⡿⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣤⣹⣿⣿⣿⣿⣿⠁⠚⢥⣑⡒⠊⠑⠒⠒⠂⠬⢍⡂⠀⠀⣠⣼⠃⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣿⣿⣿⣼⣿⣿⣿⣿⣿⣷⣦⣽⣦⠐⢪⠒⠤⠀⠀⠉⠀⠀⣹⢻⡀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀    ⠀⠀⠀⠀⠀⠀⠀⠘⣿⣿⣿⣿⣿⡟⠻⣿⣟CENZURA⣿⣿⣷⡆ ⠀⢃⢰⠃⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⣿⣿⡇⠀⠈⠉⠉⢩⣾⣯⠀⠀⠙⠿⢷⠌⠙⠃⠀⢻⡾⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣿⣿⣿⣿⣷⡆⠀⠀⣠⣾⣿⠁⠀⠀⣄⠑⢀⠀⠀⠀⢰⣻⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼⣿⣿⣿⡿⣶⠞⣱⣿⣿⣦⣢⡠⠙⢷⣄⠢⠄⢀⡼⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣤⣴⣶⣿⣿⣿⣿⣿⡄⢹⣿⣿⣽⣟⠛⠁⠀⢀⣈⣿⠂⠀⡞⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⣠⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣏⢀⣿⣿⣿⣿⣿⣦⠀⣴⣿⣿⣿⡆⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣾⣿⣿⣿⣿⣿⣿⣧⣿⣿⣿⣿⣿⡄⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣿⣿⣿⣿⣿⣿⡿⠏⣿⣿⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠞⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣿⣿⣿⣿⣿⣿⣿⡀⢹⣿⣄⠻⢿⣿⣿⣿⣿⣿⣿⡿⠖⠛⣻⣆⠀⠀⠀⣀⣠⠴⠒⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣿⣿⣿⣿⣿⣿⣿⣿⣶⣽⣷⣦⣄⡉⠛⢿⣿⣿⣿⣿⡀⠀⣿⣿⣿⡿⠿⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⡀⠙⢿⣿⣿⣿⣶⣄⡈⠙⢿⣦⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⣄⡈⠙⣿⣿⣿⣿⡆⠀⠙⣿⣿⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠁⠀⠀⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀

				ja nie wieze papiez polak w komputerze  <3  <3 <3)";// do poprawki bo sie drukowac nie chce"""""""""""""""""""""""""""""""""""""""""'
			Sleep(3000);
}

	
		else {
			std::cout << "\n				Czlowieku zastanow sie, badz soba, LUDZIU!\n";
			Sleep(3000);
			system("cls");
		}
	}
	std::cout << "\n				Dziekuje za uwage\n";
	std::cout << "\n		I prosze misia zostawic w spokoju\n";
	std::cout << "\n			Bo misiu idzie sie teraz napic\n";
	Sleep(2000);
	exit(0);//zamykanie programu

}
