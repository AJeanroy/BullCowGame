// ConsoleApplication1.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"

using namespace std;
using FTEXT = string;
using int32 = int;

void AfficheIntro();
FTEXT VotreMot(BullCowGame joueur);
void Jouer(BullCowGame joueur);
bool JouerEncore();


int main(){
	
	BullCowGame joueur;

	do {
		AfficheIntro();
		Jouer(joueur);
	} while (JouerEncore());

	system("pause");
    return 0;
}

void AfficheIntro() {
	constexpr int32 WORLD_LENGTH = 9;

	cout << "Bienvenue dans le COW&BULL" << endl;
	cout << "Le nombre de possibilités est " << WORLD_LENGTH << endl;
}

FTEXT VotreMot(BullCowGame joueur) {
	FTEXT word = "";

	int32 essaiCourant = joueur.GetEssaiCourant();

	cout << "Saisissez votre mot: " << endl;
	getline(cin, word);

	return word;
}

void Jouer(BullCowGame joueur) {
	int32 maxEssai = joueur.GetMaxEssai();

	joueur.Reset();

	for (int32 i = 1; i <= maxEssai; i++) {
		FTEXT mot = VotreMot(joueur);
		EwordStatus status = joueur.TestMotValide(mot);

		BullCowCount count = joueur.ValideEssai(mot);
		cout << "Votre mot est :" << mot << endl;
		cout << "Bulls :" << count.bulls << endl;
		cout << "Cows :" << count.cows << endl;
		cout << endl;
	}
}

bool JouerEncore() {
	FTEXT reponse;

	cout << "Voulez vous rejouer? o ou O" << endl;
	getline(cin, reponse);

	return (reponse[0] == 'o') || (reponse[0] == 'O');
}