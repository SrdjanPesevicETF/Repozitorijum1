#pragma once
class PriorityQueue
{
private:
	int* niz;
	int kapacitet;
	int broj_elemenata;
	int broj_skinutih_elemenata;
	int f, r;
public:
	PriorityQueue(int kapacitet = 1);
	~PriorityQueue();
	int PunRed(PriorityQueue* red);
	int PrazanRed(PriorityQueue* red);
	void dodaj(PriorityQueue *red,int value);
	bool Obrisi_Najveci(PriorityQueue *red,int *value);
	bool Obrisi_Na_Poz(int indeks);
	int Pretraga(int value);
	bool Obrisi_Po_Vrije(int value);
	bool shouldShrink();
	void ispis(PriorityQueue *red);
	void sortiraj(PriorityQueue *red);
};