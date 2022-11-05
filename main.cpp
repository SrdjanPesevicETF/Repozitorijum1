#include "PriorityQueue.h"
#include <iostream>
int main()
{
	int value;
	int value2;
	PriorityQueue red(5);
	red.dodaj(&red,8);
	red.dodaj(&red,11);
	red.dodaj(&red,3);
	red.dodaj(&red, 5);
	red.dodaj(&red, 12);
	red.dodaj(&red, 18);
	red.dodaj(&red, 22);
	
	red.ispis(&red);

	std::cout << "\n";




	if (red.Obrisi_Najveci(&red, &value))
	{
		std::cout << "\nObrisan broj:" << value;
		std::cout << "\nPrikaz reda nakon brisanja:";
		red.ispis(&red);
	}
	else
		std::cout << "Red je prazan!";
	
	
	
	





	std::cout << "\n";
	red.Obrisi_Na_Poz(3);
	red.ispis(&red);


	if (red.Obrisi_Najveci(&red, &value2))
	{
		std::cout << "\nObrisan broj:" << value2;
		std::cout << "\nPrikaz reda nakon brisanja:";
		red.ispis(&red);
	}
	else
		std::cout << "Red je prazan!";
		

	
	std::cout << "\n";
	red.Obrisi_Na_Poz(2);
	red.ispis(&red);
	std::cout << "\n";
	red.Obrisi_Na_Poz(1);
	red.ispis(&red);

	if (red.Obrisi_Najveci(&red, &value2))
	{
		std::cout << "\nObrisan broj:" << value2;
		std::cout << "\nPrikaz reda nakon brisanja:";
		red.ispis(&red);
	}
	else
		std::cout << "Red je prazan!";

	
	red.dodaj(&red, 56);
	red.dodaj(&red, 58);
	red.dodaj(&red, 60);
	red.dodaj(&red, 42); 
	red.dodaj(&red, 9);
	//red.sortiraj(&red);
	std::cout << "\n";
	red.ispis(&red);

}