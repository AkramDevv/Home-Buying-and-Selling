#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <algorithm>

const int MAX = 50;


int randNoArr[3];

long long int apartmentPricesArr[3];

bool truth = true;

int realIndex;

void print_list(char arrList[MAX][MAX], int arrCost[MAX][MAX], int size) {
	for (int i = 0;i < size;i++) {
		std::cout << i + 1 << ". " << arrList[i] << " -> Cost: " << arrCost[i][0] << " $ - " << arrCost[i][1] << " $" << std::endl;
	}
}

void print_apartments(int stateNum, int arrCost[MAX][MAX], int size) {


	for (int i = 0;i < size;i++) {
		int price = ((rand() * (RAND_MAX) % (arrCost[stateNum][1] - arrCost[stateNum][0] + 1) + arrCost[stateNum][0]) / 1000) * 1000;
		int randNo = rand() % (98 + 1) + 1;
		randNoArr[i] = randNo;
		apartmentPricesArr[i] = price;
		std::cout << "Apartment NO: " << randNo << " -> Cost: " << price << " $" << std::endl;
	}
}

void create_apartment_design(char*** apartmentDesigns, int designRow, int designCol, int designsListSize, int apartmentNum) {


	for (int i = 0;i < 3;i++) {
		if (randNoArr[i] == apartmentNum) {
			realIndex = i;
			truth = false;
			break;
		}
	}


	if (realIndex == 0) {
		for (int i = 0;i < designRow;i++) {
			for (int j = 0;j < designCol;j++) {
				if ((i == 0 || i == designRow - 1 || j == 0 || j == designCol - 1) || (i == 34 && j >= 1 && j <= 40) || (j == 40 && i >= 34) || (i == 41 && j >= 40 && j <= 70) || (i == 46 && j >= 40 && j <= 76) || (j == 70 && i <= 41 && i >= 36) ||
					(j == 76 && i <= 46 && i >= 36) || (i == 38 && j >= 76) || (j == 70 && i <= 36) || (j == 76 && i <= 36) || (j <= 70 && j >= 40 && i == 31) || (j == 40 && i >= 8 && i <= 31) || (i == 8 && j >= 45 && j <= 70)) {
					apartmentDesigns[0][i][j] = '#';
				}
				else {
					apartmentDesigns[0][i][j] = ' ';
				}
				if (((i == 42 || i == 43 || i == 44 || i == 45) && j == 0) || ((i == 42 || i == 43 || i == 44 || i == 45) && j == 40) || (j == 76 && i <= 41 && i >= 39) || (i == 38 && j >= 91 && j <= 95) || (j == 109 && i >= 25 && i <= 30) || (j == 76 && i >= 25 && i <= 30) ||
					(j == 70 && i >= 25 && i <= 30)) {
					apartmentDesigns[0][i][j] = ' ';
				}
			}
		}
	}


	else if (realIndex == 1) {
		for (int i = 0;i < designRow;i++) {
			for (int j = 0;j < designCol;j++) {
				if ((i == 0 || i == designRow - 1 || j == 0 || j == designCol - 1) || (i == 19 && j >= 1 && j <= 70) || (i == 31 && j >= 1 && j <= 70) || (j == 70 && i >= 20) || (j == 70 && i <= 31) || (i == 25 && j >= 70 && j <= 90) || (j == 90 && i <= 25) || (j == 85 && i >= 25) || (j == 17 && i >= 1 && i <= 19)) {
					apartmentDesigns[1][i][j] = '#';
				}
				else {
					apartmentDesigns[1][i][j] = ' ';
				}
				if ((j == 0 && i >= 20 && i <= 30) || (j == 17 && i >= 9 && i <= 13) || (j == 70 && i >= 11 && i <= 14) || (j == 70 && i >= 22 && i <= 24) || (j == 70 && i >= 39 && i <= 43) || (j == 90 && i >= 18 && i <= 22 || (j == 85 && i >= 29 && i <= 35))) {
					apartmentDesigns[1][i][j] = ' ';
				}
			}
		}
	}


	else if (realIndex == 2) {
		for (int i = 0;i < designRow;i++) {
			for (int j = 0;j < designCol;j++) {
				if ((i == 0 || i == designRow - 1 || j == 0 || j == designCol - 1) || (j == 55 && i <= 49 && i >= 38) || (j == 55 && i <= 34 && i >= 12) || (i == 12 && j <= 55 && j >= 25) || (i == 34 && j <= 55 && j >= 25) ||
					(j == 25 && i >= 19 && i <= 34) || (j == 30 && i <= 12) || (i == 15 && j <= 25) || (j == 27 && i >= 35) || (j == 61 && i <= 45 && i >= 5) || (i == 25 && j >= 61)) {
					apartmentDesigns[2][i][j] = '#';
				}
				else {
					apartmentDesigns[2][i][j] = ' ';
				}
				if ((i == 49 && j <= 60 && j >= 56) || (i == 34 && j >= 35 && j <= 39) || (j == 30 && i <= 8 && i >= 5) || (i == 25 && j <= 75 && j >= 71)) {
					apartmentDesigns[2][i][j] = ' ';
				}
			}
		}
	}


	if (truth) {
		std::cout << "Enter true number!";
	}
	else if (!truth) {
		for (int i = 0;i < designRow;i++) {
			for (int j = 0;j < designCol;j++) {
				std::cout << apartmentDesigns[realIndex][i][j];
			}
			std::cout << std::endl;
		}
	}
}

int main() {

	std::srand(time(NULL));

	int size = 5;

	char apartmentLocations[MAX][MAX]{ "California","New York","Texas","Florida","Illinois","Washington","Massachusetts","Colorado","Arizona","Nevada" };
	int apartmentCosts[MAX][MAX]{ {500000,1500000},{400000,2000000},{200000,600000},{300000,800000},{150000,500000},{400000,900000},{350000,1000000},{300000,700000},{250000,600000},{250000,550000} };
	print_list(apartmentLocations, apartmentCosts, size);


	std::cout << "\nEnter apartment's location: ";
	int stateNum;
	std::cin >> stateNum;
	stateNum--;

	int aparmentAmountSize = 3;
	std::cout << "\nApartment prices in " << apartmentLocations[stateNum] << "\n\n";
	print_apartments(stateNum, apartmentCosts, aparmentAmountSize);


	std::cout << "\n\nEnter your budget: ";
	long long int userBudget;
	std::cin >> userBudget;


	if (userBudget < *std::min_element(apartmentPricesArr, apartmentPricesArr + 5)) {
		std::cout << "\nYou don't have enough money for buy house.";
		return 0;
	}


	int designsListSize = 5, designRow = 50, designCol = 110;
	char*** apartmentDesigns = new char** [designsListSize];

	for (int i = 0;i < designsListSize;i++) {
		apartmentDesigns[i] = new char* [designRow];

		for (int j = 0;j < designRow;j++) {
			apartmentDesigns[i][j] = new char[designCol];
		}
	}

	bool apartmentsLoop = true;

	while (apartmentsLoop) {
		while (truth) {
			int apartmentNum;
			std::cout << "Enter apartment's NO: ";
			std::cin >> apartmentNum;


			std::cout << "Apartment is showing...\n\n";


			create_apartment_design(apartmentDesigns, designRow, designCol, designsListSize, apartmentNum);

			std::cout << std::endl;
		}


		char visit;
		std::cout << "\nDo you want to vist apartment? - Yes(y) || No(n): ";
		std::cin >> visit;

		if (visit == 'y') {

			std::cout << "Controls W - Up\nS - Down\nA - Left\nD - Right\nFinish visit - F" << std::endl;

			int x = 44, y = 1;
			apartmentDesigns[realIndex][x][y] = 'X';

			bool check = true;
			while (check) {

				if (_kbhit()) {
					char move = _getch();

					std::cout << "Controls W - Up\nS - Down\nA - Left\nD - Right\nFinish visit - F" << std::endl;

					switch (move) {
					case 'w':
						if (x > 0 && apartmentDesigns[0][x - 1][y] != '#') {
							apartmentDesigns[realIndex][x][y] = ' ';
							--x;
							apartmentDesigns[realIndex][x][y] = 'X';
						}
						else {
							std::cout << "\nYou can't move up. Try again!\n\n";
						}
						break;

					case 's':
						if (x < designRow - 2 && apartmentDesigns[0][x + 1][y] != '#') {
							apartmentDesigns[realIndex][x][y] = ' ';
							++x;
							apartmentDesigns[realIndex][x][y] = 'X';
						}
						else {
							std::cout << "\nYou can't move down. Try again!\n\n";
						}
						break;

					case 'a':
						if (y > 0 && apartmentDesigns[0][x][y - 1] != '#') {
							apartmentDesigns[realIndex][x][y] = ' ';
							--y;
							apartmentDesigns[realIndex][x][y] = 'X';
						}
						else {
							std::cout << "\nYou can't move left. Try again!\n\n";
						}
						break;

					case 'd':
						if (y < designCol - 2 && apartmentDesigns[0][x][y + 1] != '#') {
							apartmentDesigns[realIndex][x][y] = ' ';
							++y;
							apartmentDesigns[realIndex][x][y] = 'X';
						}
						else {
							std::cout << "\nYou can't move right. Try again!\n\n";
						}
						break;

					case 'f':
						check = false;
						char buyChoice;
						std::cout << "Do you want to buy it? - Yes(y) || No(n): ";
						std::cin >> buyChoice;
						if (buyChoice == 'y') {
							userBudget -= apartmentPricesArr[realIndex];
							apartmentsLoop = false;
							std::cout << "\n User's budget: ";
							std::cout << userBudget;
						}
						else if (buyChoice == 'n') {
							apartmentsLoop = false;
						}
						break;
					default:
						std::cout << "Wrong input!";
					}

					system("cls");
					for (int i = 0;i < designRow;i++) {
						for (int j = 0;j < designCol;j++) {
							std::cout << apartmentDesigns[realIndex][i][j];
						}
						std::cout << std::endl;
					}
				}
			}
		}


		else if (visit == 'n') {
			char buyChoice;
			std::cout << "Do you want to buy it? - Yes(y) || No(n): ";
			std::cin >> buyChoice;
			if (buyChoice == 'y') {
				if (userBudget > apartmentPricesArr[realIndex]) {
					userBudget -= apartmentPricesArr[realIndex];
				}
				else {
					std::cout << "\nYou don't have enough money to buy this house.\n";
				}
				apartmentsLoop = false;
			}
			else if (buyChoice == 'n') {
				continue;
			}
		}
	}



	std::cout << std::endl;


	std::cout << "\nUser's budget: ";
	std::cout << userBudget;
	
	
	for (int i = 0;i < designRow;i++) {
		for (int j = 0;j < designCol;j++) {
			delete[] apartmentDesigns[i][j];
		}
		delete[] apartmentDesigns[i];
	}
	delete[] apartmentDesigns;



	return 0;
}
