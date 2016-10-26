#pragma once
#include <string>

using namespace std;

using FString = string;
using int32 = int;

typedef struct BullCowCount {
	int32 bulls;
	int32 cows;
};

enum class EwordStatus {
	Ok,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

class BullCowGame
{
public:
	BullCowGame();
	BullCowGame(int32 newEssaiCourant, int32 newMaxEssai);
	~BullCowGame();

	//assesseurs
	void SetEssaiCourant(int32 newEssaiCourant);
	void SetMaxEssai(int32 newMaxEssai);
	int32 GetEssaiCourant();
	int32 GetMaxEssai();

	void Reset();
	bool Gagne()const;
	EwordStatus TestMotValide(FString) const;
	BullCowCount ValideEssai(FString word);
	bool isIsograd(FString mot)const;
	bool isLower(FString mot)const;
	int32 GetLongMotCache() const;

private:
	int32 essaiCourant;
	int32 maxEssai;
	FString hWord;
	BullCowCount status;
	bool gagne;
};
