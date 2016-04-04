// Kontenery
#include <vector>	// Tablica
#include <set>		// Zbiór
#include <map>		// Słownik

// Adaptery
#include <queue>	// Kolejka
#include <stack>	// Stos
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Slav.h"

#define REPORT_ADAPTERS showMeAdapterSizes(queueOfSlavs,stackOfSlavs)
#define REPORT_CONTAINERS showMeContainerSizes(vectorOfSlavs,setOfSlavs,mapOfSlavs)

using namespace std;

void showMeContainerSizes(vector <Slav *>, set <Slav *>, map <Slav *, Slav*>);
void showMeAdapterSizes(queue <Slav *>, stack <Slav *>);

void containers(Slav *, int);
void adapters(Slav *, int);

int main(int argc, char const *argv[])
{
	int n = 2 * atoi(argv[1]);
	Slav *slavs = new Slav[n];
	cout << "# Generated Slavs" << endl;
	for (int i = 0; i < n; ++i)
		cout << slavs[i].description() << endl;

	containers(slavs, n);
	adapters(slavs, n);

	delete [] slavs;
}

void containers(Slav * slavs, int n)
{
	vector <Slav *> vectorOfSlavs;
	set <Slav *> setOfSlavs;
	map <Slav *, Slav *> mapOfSlavs;
	
	printf("# Containers\n");
	REPORT_CONTAINERS;
	printf("## vector\n");
	vectorOfSlavs.push_back(NULL);
	// Umieść Słowian w losowej kolejności w wektorze.
	srand(time(NULL));
	for(int i=0;i<n;i++)	
	{
		int position=rand()%vectorOfSlavs.size();
		vectorOfSlavs.insert(vectorOfSlavs.begin()+position,slavs+i);
	}
	vectorOfSlavs.pop_back();
	// Wykorzystując iterator i funkcję description(), wyświetl wszystkich Słowian w wektorze
	vector<Slav*>::iterator it_vec;
	for(it_vec=vectorOfSlavs.begin();it_vec!=vectorOfSlavs.end();it_vec++)
		cout<<(*it_vec)->description()<<endl;
	REPORT_CONTAINERS;
	printf("## set\n");
	for(int i=0;i<n;i++)
		{
			setOfSlavs.insert(vectorOfSlavs[i]);
			vectorOfSlavs.pop_back();
		}
	// Przenieś wszystkich Słowian z wektoru do zbioru.
	
	REPORT_CONTAINERS;
	printf("## map\n");

	// Stwórz słownik tworzący pary Słowian, z tych znajdujących się w zbiorze, czyszcząc zbiór
	
	// Wykorzystując iterator, wyświetl wszystkie pary Słowian
	
	REPORT_CONTAINERS;
}

void adapters(Slav * slavs, int n)
{
	queue <Slav *> queueOfSlavs;
	stack <Slav *> stackOfSlavs;

	printf("# Adapters\n");
	REPORT_ADAPTERS;
	printf("## queue\n");

	// Umieść Słowian w kolejce.
	
	REPORT_ADAPTERS;

	printf("## stack\n");
	// Przenieś Słowian z kolejki do stosu.

	REPORT_ADAPTERS;

	// Wyświetl Słowian zdejmowanych ze stosu.

	REPORT_ADAPTERS;
}

void showMeContainerSizes(vector <Slav *> vector, set <Slav *> set, map <Slav *, Slav*> map)
{
	printf("[vector_size = %lu, set_size = %lu, map_size = %lu, existingSlavs = %i]\n",
		vector.size(),
		set.size(),
		map.size(),
		Slav::counter());
}

void showMeAdapterSizes(queue <Slav *> queue, stack <Slav *> stack)
{
	printf("[queue_size = %lu, stack_size = %lu, existingSlavs = %i]\n",
		queue.size(),
		stack.size(),
		Slav::counter());

}
