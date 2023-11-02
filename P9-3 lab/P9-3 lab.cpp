// P9-3 dice roll runs
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int rolldie(void);
void displayRun(int values[], int size);
bool hasRun(int values[], int size);

int main() {
	srand(time(0));
	int values[20];

	if (hasRun(values, 20) == true) {
		cout << "has run: ";
		displayRun(values, 20);
	}
	else {
		cout << "no run: ";
		displayRun(values, 20);
	}

	//displayRun(values, 20);

}


bool hasRun(int values[], int size) {
	int prev = values[0];
	int dupeCount = 0;
	for (int i = 1; i < 6; i++) {
		if (values[i] == prev) {
			dupeCount++;
		}
		else {
			prev = values[i];
		}
	}

	if (dupeCount > 0) {
		return true;
	}
	else { return false;  }
}

void displayRun(int values[], int size) {
	for (int roll = 0; roll < 20; roll++) {
		values[roll] = rolldie();
	}
	int prev = values[0];

	for (int i = 1; i < 20; i++) {
		//cout << values[i] << " ";
	
		for (int i = 1; i < 20; i++) {
			if (values[i] == prev) {
				cout << "(" << prev << " " << values[i] << ") ";
			}
			else {
				cout << prev << " ";
				prev = values[i];
			}
		}
		return;
	}
}

/* gutted display
for (int i = 1; i < 20; i++) {
	//cout << values[i] << " ";

	for (int i = 1; i < 20; i++) {
		if (values[i] == prev) {
			cout << "(" << prev << " " << values[i];
			int x = values[i + 1];
			for (x == values[i]; values[x] < values[20]; x++) {
				cout << " " << values[x];
			}
			cout << ") ";
		}
		else {
			cout << prev << " ";
			prev = values[i];
		}
	}
	return;
}
*/

/* old display run
		if (values[i] == prev) {
			dupe = true;
			if (values[i] == values[i + 1]) {
				if (values[i] == values[i + 2]) {
					if (values[i] == values[i + 3]) {
						if (values[i] == values[i + 4]) {
							if (values[i] == values[i + 5]) {
								cout << "(" << prev << " " << values[i] << " " << values[i + 1] << " " << values[i + 2] << " " << values[i + 3] << ") ";
							}
						}
						else { cout << "(" << prev << " " << values[i] << " " << values[i + 1] << " " << values[i + 2] << " " << values[i + 3] << ") "; }
					}
					else { cout << "(" << prev << " " << values[i] << " " << values[i + 1] << " " << values[i + 2] << ") "; }
				}
				else { cout << "(" << prev << " " << values[i] << " " << values[i + 1] << ") "; }
			}
			else { cout << "(" << prev << " " << values[i] << ") "; }
		}
		else {
			cout << prev << " ";
			prev = values[i];
		}
		*/


int rolldie(void) {
	const int NUMBER_OF_DIE_SIDES = 6;
	const int LOWEST_DIE_VALUE = 1;

	return rand() % NUMBER_OF_DIE_SIDES + LOWEST_DIE_VALUE;
}