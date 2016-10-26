#include "stdafx.h"
#include "BullCowGame.h"
#include <map>

#define TMAP std::map


BullCowGame::BullCowGame() {
	this->essaiCourant = 0;
	this->maxEssai = 0;
}

BullCowGame::BullCowGame(int32 newEssaiCourant, int32 newMaxEssai) {
	this->essaiCourant = newEssaiCourant;
	this->maxEssai = newMaxEssai;
}

BullCowGame::~BullCowGame() {
}


void BullCowGame::SetEssaiCourant(int32 newEssaiCourant) {
	essaiCourant = newEssaiCourant;
}

void BullCowGame::SetMaxEssai(int32 newMaxEssai) {
	maxEssai = newMaxEssai;
}

int32 BullCowGame::GetEssaiCourant() {
	return essaiCourant;
}

int32 BullCowGame::GetMaxEssai() {
	TMAP<int32, int32>LongMotEssaiMax{ {3,4},{4,7},{5,10},{6,16},{7,20} };
	return LongMotEssaiMax[hWord.length];
}

void BullCowGame::Reset() {
	constexpr int32 MAX_ESSAI = 8;
	this->maxEssai = MAX_ESSAI;
	const FString MOTCACHE = "coucou";
	hWord = MOTCACHE;
	this->essaiCourant = 1;
}

bool BullCowGame::Gagne()const {
	return false;
}

EwordStatus BullCowGame::TestMotValide(FString word)const {
	
	if (false)
		return EwordStatus::Not_Isogram;
	else if(false)
		return EwordStatus::Not_Lowercase;
	else if (word.length() != GetLongMotCache())
		return EwordStatus::Wrong_Length;
	else
		EwordStatus::Ok;	
}

BullCowCount BullCowGame::ValideEssai(FString word) {
	essaiCourant++;
	BullCowCount count;
	int32 lWord = word.length();

	for (int32 i = 0; i < lWord; i++) {
		for (int32 j = 0; j < lWord; j++) {
			if (word[i] == hWord[j]) {
				if (i == j)
					count.bulls++;
				else
					count.cows++;
			}
		}
	}

	if (count.bulls == GetLongMotCache())
		gagne = true;
	else
		gagne = false;

	return count;
}

bool BullCowGame::isIsograd(FString mot) const {
	if (mot.length() <= 1) {
		return true;
	}
	TMAP <char, bool> lettreMot;
	for (auto lettre : mot) {
		lettre = tolower(lettre);
		if (lettreMot[lettre]) {
			return false;
		}
		else {
			lettreMot[lettre] = true;
		}
	}
	return true;
}

bool BullCowGame::isLower(FString mot) const {
	return false;
}

int32 BullCowGame::GetLongMotCache()const {
	return hWord.length();
}