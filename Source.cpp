#include<vector>
#include<unordered_map>

#include<NTL/ZZ.h>

NTL_CLIENT 
#define MAX_LENGTH_OF_SEQUENCE 500

void calcWithCharPoly() {}

int prePeriodLength(const std::vector<bool>& seq) {
	std::unordered_map<std::vector<bool>, int> seen;
	int n = seq.size();
	std::vector<bool> prefix;
	for (int i = 1; i < n; i++)
	{
		prefix.push_back(seq[i-1]);
		if (seen.count(prefix))
		{
			return i;
		}
		seen[prefix] = i;
	}
	return 0;
}

void calcWithSequenceMod2(const std::vector<bool>& seq) {
	int n = seq.size();
	int preperiodLen = prePeriodLength(seq);
	for (int period = 1; period <= n/2; period++)
	{
		bool isPeriod = true;
		for (int i = period; i < n; i++)
		{
			if (seq[i] != seq[i % period])
			{
				isPeriod = false;
				break;
			}
		}
		if (isPeriod)
		{
			cout << "Perioda je: " << period << endl;
			return;
		}	
	}
}

int main() {

	int choice = 0;
	int len = 0;
	std::string input;
	std::vector<bool> sequence;

	while (choice != 3)
	{
		cout << "Co chcete zadat?" << endl;
		cout << "Charakteristicky polynom   -> 1" << endl;
		cout << "Postupnost mod 2           -> 2" << endl;
		cout << "Zatvorit aplikaciu         -> 3" << endl;
		cout << "" << endl;
	
		cin >> choice;
		cout << "" << endl;

		switch (choice)
		{
		case 1:
			calcWithCharPoly();
			cout << "" << endl;
			break;
		case 2:
			sequence.clear();
			input.clear();
			cin >> input;
			for (char bit : input)
			{
				sequence.push_back(bit == '1');
			}
			std::reverse(sequence.begin(), sequence.end());
			calcWithSequenceMod2(sequence);
			cout << "" << endl;
			break;
		case 3:
			break;
		default:
			break;
		}
	}
	return 0;
}