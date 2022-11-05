#include "PriorityQueue.h"
#include <iostream>

PriorityQueue::PriorityQueue(int kapacitet)
{
	this->niz = new int[kapacitet];
	this->kapacitet = kapacitet;
	this->broj_elemenata = 0;
	this->broj_skinutih_elemenata = 0;
	
	this->f = -1;
	this->r = 0;
	
}
PriorityQueue::~PriorityQueue()
{
	delete[] this->niz;
	this->niz = nullptr;
	this->broj_elemenata = 0;
	this->kapacitet = 0;
}

int PriorityQueue::PunRed(PriorityQueue* red)
{
	return red->r==red->kapacitet;
}

int PriorityQueue::PrazanRed(PriorityQueue* red)
{
	return red->f==-1 || red->f==red->r;
}

void PriorityQueue::dodaj(PriorityQueue *red,int value)
{
	if (PunRed(red))
	{
		int* Novi_Niz = new int[this->kapacitet*2];
		this->kapacitet *=2;
		for (int i = 0; i < this->broj_elemenata; i++)
		{
			Novi_Niz[i] = this->niz[i];
		}
		delete[] this->niz;
		this->niz = Novi_Niz;
	}
	if (red->f == -1)
		red->f = 0;
	red->niz[red->r++] = value;
	red->broj_elemenata++;
	sortiraj(red);
}

bool PriorityQueue::Obrisi_Najveci(PriorityQueue *red,int *value)
{
	if (PrazanRed(red))
		return false;
	
	*value = red->niz[red->f++];
	broj_skinutih_elemenata++;

	return true;
}

bool PriorityQueue::Obrisi_Na_Poz(int indeks)
{

	if (indeks <0 || indeks>this->broj_elemenata)
		return false;
	for (int i = indeks +broj_skinutih_elemenata; i < this->broj_elemenata-1; i++)
	{
		
		this->niz[i] = this->niz[i + 1];
		
		
	}
	this->broj_elemenata--;
	this->r--;
	if (this->shouldShrink())
	{

		int* Novi_Niz1 = new int[this->broj_elemenata]();
		this->kapacitet = this->broj_elemenata;
		this->broj_elemenata = this->kapacitet > this->broj_elemenata ? this->broj_elemenata : this->kapacitet;
		for (int i = 0; i < this->broj_elemenata; i++)
		{
			Novi_Niz1[i] = this->niz[i];
		}
		delete[]this->niz;
		this->niz = Novi_Niz1;
		
	}

	return true;
}

int PriorityQueue::Pretraga(int value)
{
	for (int i = 0; i < this->broj_elemenata; i++)
	{
		if (value == this->niz[i])
		{
			return i;
		}

	}
	return -1;

}

bool PriorityQueue::Obrisi_Po_Vrije(int value)
{
	return Obrisi_Na_Poz(Pretraga(value));
}

bool PriorityQueue::shouldShrink()
{
	return this->broj_elemenata <= this->kapacitet / 2;
}

void PriorityQueue::ispis(PriorityQueue *red)
{
	if (red->f != -1)
		for (int i = red->f; i <this->broj_elemenata; i++)
			std::cout << red->niz[i] << " ";
}
void PriorityQueue::sortiraj(PriorityQueue *red)
{
	for (int i = 0; i < red->broj_elemenata-1; i++)
	{
		
		for (int j = i + 1; j <red->broj_elemenata; j++)
		{
			if (red->niz[i] < red->niz[j])
			{
				int pom = niz[i];
				niz[i] = niz[j];
				niz[j] = pom;
			}
			
		}
	}

}

