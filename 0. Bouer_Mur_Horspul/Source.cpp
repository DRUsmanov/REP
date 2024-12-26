#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void smeshenia(string word) {
	vector<int> DATA;
	vector<char> prosmotreno;
	vector<int> smeshenia;
	vector<char> word_smeshenia;
	for (int i = 0; i <= word.size() - 1; i++) {
		DATA.push_back(0);
		prosmotreno.push_back('0');
	}
	int s = 0;
	for (int i = (word.size() - 2); i >= 0; i--) {
		s++;
		int chek = count(prosmotreno.begin(), prosmotreno.end(), word[i]);
		if (chek == 0) {
			DATA[i] = s;
			prosmotreno[i] = word[i];
		}
		else {
			for (int n = 0; n <= word.size(); n++) {
				if (word[i] == prosmotreno[n]) {
					DATA[i] = DATA[n];
					prosmotreno[i] = word[i];
					break;
				}
			}
		}
	}
	if (count(prosmotreno.begin(), prosmotreno.end(), word[word.size()-1]) == 0) {
		DATA[word.size()-1] = word.size();
	}
	else {
		for (int n = 0; n <= word.size(); n++) {
			if (word[word.size()-1] == prosmotreno[n]) {
				DATA[word.size()-1] = DATA[n];
				break;
			}
		}
	}
	DATA.push_back(word.size());
	word_smeshenia.push_back(word[0]);
	smeshenia.push_back(DATA[0]);
	for (int i = 1; i < DATA.size(); i++) {
		if (i == DATA. size() - 1) {
			word_smeshenia.push_back('*');
		}
		if (count(word_smeshenia.begin(), word_smeshenia.end(), word[i]) == 0) {
			word_smeshenia.push_back(word[i]);
			smeshenia.push_back(DATA[i]);
		}
	}
	for (int i = 0; i < DATA.size(); i++) {
		cout << DATA[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < word_smeshenia.size(); i++) {
		cout << word_smeshenia[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < smeshenia.size(); i++) {
		cout << smeshenia[i] << " ";
	}
	cout << endl;
};

int main() {
	setlocale(LC_ALL, "ru");
	smeshenia("ÈÑÏÎËÍÅÍÈÅ");
	
	return 0;
}