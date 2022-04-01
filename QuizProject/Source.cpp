#include<iostream>
#include<vector>
#include<windows.h>
#include<fstream>
#include<string>

using namespace std;

string name = "Player";

class Question {
private:

	string _sual;
	string _duzguncavab1;
	string _cavab2;
	string _cavab3;
	string _cavab4;
	int _id;

public:

	Question(string sual, string duzguncavab1, string cavab2, string cavab3, string cavab4, int id) {
		_sual = sual;
		_duzguncavab1 = duzguncavab1;
		_cavab2 = cavab2;
		_cavab3 = cavab3;
		_cavab4 = cavab4;
		_id = id;
	}

	////////////////////////////////////

	void sual() {
		cout << _sual << endl;
	}

	void randomsecimler(int n) {
		switch (n) {
		case 1:
			cout << _duzguncavab1;
			break;
		case 2:
			cout << _cavab2;
			break;
		case 3:
			cout << _cavab3;
			break;
		case 4:
			cout << _cavab4;
			break;
		}
	}

	int getID() {
		return _id;
	}
};

 ////////////////////////////////////////////////////////////////////////

void Questions(int& id, vector<Question>& suallar, string filename, vector<int>& ID) {

	string temp;
	string sual;
	string duzguncavab1;
	string cavab2;
	string cavab3;
	string cavab4;

	ifstream file;

	file.open(filename.c_str());

	int n = 1;

	while (getline(file, temp)) {

		switch (n) {
		case 1:
			sual = temp;
			break;

		case 2:
			duzguncavab1 = temp;
			break;

		case 3:
			cavab2 = temp;
			break;

		case 4:
			cavab3 = temp;
			break;

		case 5:
			cavab4 = temp;
			id++;
			Question newQuestion(sual, duzguncavab1, cavab2, cavab3, cavab4, id);
			ID.push_back(id);
			suallar.push_back(newQuestion);
			n = 0;
			break;
		}
		n++;
	}
	file.close();
}

	////////////////////////////////////////////////////////////////////////

char View_all_questions(int id, vector<Question> suallar, bool isokay) {
	bool done, choices[4];
	int num, character = 97;
	char answer;

	suallar[id].sual();
	done = false;
	for (int x = 0; x < 4; x++) {
		choices[x] = false;
	}
	while (done == false) {
		num = rand() % 4 + 1;
		if (choices[num - 1] == false) {
			if (num == 1) {
				if (isokay == false) { cout << "*"; }
				answer = (char)character;
			}
			cout << "[" << (char)character << "] ";
			suallar[id].randomsecimler(num);
			cout << "   ";
			choices[num - 1] = true;
			character++;
		}
		for (int j = 0; j < 4; j++) {
			done = true;
			if (choices[j] == false) {
				done = false;
				break;
			}
		}
	}
	cout << endl;
	return answer;
}

	////////////////////////////////////////////////////////////////////////

void questionElaveElemek(int& lastID, vector<Question>& allQuestions, string fileName, vector<int>& IDs) {
	string sual, cavab1, cavab2, cavab3, cavab4;
	char input;
	do {
		cout << endl << "Sualli Daxil Edin: ";
		cin.ignore();
		getline(cin, sual);
		cout << "1 ci cavabiniz: ";
		getline(cin, cavab1);

		cout << "2 ci cavabiniz: ";
		getline(cin, cavab2);

		cout << "3 ci cavabiniz: ";
		getline(cin, cavab3);

		cout << "4 ci cavabiniz: ";
		getline(cin, cavab4);

		lastID++;
		Question newQuestion(sual, cavab1, cavab2, cavab3, cavab4, lastID);
		IDs.push_back(lastID);
		allQuestions.push_back(newQuestion);
		ofstream questionFile;
		questionFile.open(fileName.c_str(), fstream::app);
		questionFile << endl << sual << endl;
		questionFile << cavab1 << endl;
		questionFile << cavab2 << endl;
		questionFile << cavab3 << endl;
		questionFile << cavab4;
		questionFile.close();
		cin >> input;
	} while (input == 'a');
}

	////////////////////////////////////////////////////////////////////////

int esasmenu() {
	int secim = 0;
	system("cls"); 
		cout <<" ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ " << endl;
		cout <<" ^          Quiz Oynamaga Hazirmisin?          " << name << endl;
		cout <<" ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ " << endl;
		cout << endl;
		cout << endl;

		cout <<" ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ " << endl;
		cout <<" ^ 1 ^ " << "       Admin Menusunu Gormek Ucun          ^ " << endl;
		cout <<" ^ 2 ^ " << "       Adinizi Daxil Edin                  ^ " << endl;
		cout <<" ^ 3 ^ " << "         Oyuna Baslamaq                    ^ " << endl;
		cout <<" ^ 4 ^ " << "         Oyundan Cixmaq                    ^ " << endl;
		cout <<" ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ " << endl;

		cout << endl;
		cout << endl;
		cout << endl;

		cout << " ^^^ " << name << " ^^^ " << " ^ Seciminizi Daxil Edin ^: ";
		cin >> secim;
	system("cls");

	if (cin.fail()) {
		cout << "      ^ Menyu-ya Uygun Secim Eleyin ^      " << endl;
		cin.clear();
		cin.ignore();
		return esasmenu();
	}
	else return secim;
}

	////////////////////////////////////////////////////////////////////////

int AdminMenuDisplay() {
	int secimin = 0;
	system("cls");

	cout << " ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ " << endl;
	cout << " ^					   Admin Menyu                       ^ " << endl;
	cout << " ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ " << endl;
	cout << endl;
	cout << endl;


	cout << " ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ " << endl;
	cout << " ^ 1 ^ " << "         Sual Elave Elemek                 ^ " << endl;
	cout << " ^ 2 ^ " << "         Sualli File Yazmaq                ^ " << endl;
	cout << " ^ 3 ^ " << "         Menyu-ya Qayitmaq                 ^ " << endl;
	cout << " ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ " << endl;

	cout << " ^^^ " << name << " ^^^ " << " ^ Seciminizi Daxil Edin ^: ";
	cin >> secimin;
	system("cls");
	if (cin.fail()) {
		cout << "      ^ Admin Menyusuna Uygun Secim Eleyin ^      " << endl;
		cin.clear();
		cin.ignore();
		return AdminMenuDisplay();
	}
	else return secimin;
}

	////////////////////////////////////////////////////////////////////////

void menuAdminFile(int& id, vector<Question>& suallar, string& fileName, vector<int>& ID) {
	bool isokay = false;

	string fileadi;

	int choice = AdminMenuDisplay();
	switch (choice) {
	case 1:
		questionElaveElemek(id, suallar, fileName, ID);
		break;
	case 2:
		cout << "Txt File Adini DA: ";
		cin >> fileadi;
		fileName = fileadi + ".txt";
		suallar.clear();
		ID.clear();
		id = 0;
		Questions(id, suallar, fileName, ID);
		break;
	case 3:
		break;
	}
	system("cls");
}

	////////////////////////////////////////////////////////////////////////

void quizYaratmaq(vector<Question>& allQuestions, vector<int>& IDs) {
	bool game = true;
	int sehv = 0, dogru = 0;
	char answer, duzguncavab1;
	int randQ, num = (IDs.size()) - 1;
	randQ = rand() % num + 0;
	int takenQ[5] = { randQ ,randQ ,randQ ,randQ ,randQ };

	for (int i = 1; i <= IDs.size(); i++) {
		randQ = rand() % num + 0;
		for (int j = 0; j < 5; j++) {
			if (takenQ[j] == randQ) {
				randQ = rand() % num + 0;
				j = 0;
				goto label;
			}
		}
	label:
		cout << "Sual " << i << " :" << endl;
		duzguncavab1 = View_all_questions(IDs[randQ], allQuestions, game);
		takenQ[i] = randQ;
		
		cout << endl << "Suallin: ";
		cin >> answer;
		if (answer == duzguncavab1) {
			cout << endl << "Duzgun Cavabi Tapdiniz!" << endl << endl;
			dogru++;
		}
		else {
			cout << endl << "Sehv Cavab Verdiniz " << endl;
			sehv++;
		}
	}
	cout << endl << " =======================================" << endl;
	cout << "Suallardan Necesine Duzgun Cavab Verdiyinizin Sayi: " << dogru << endl;
	cout<< "Suallardan Necesine Sehv Cavab Verdiyinizin Sayi: " << sehv << endl;

	system("CLS");
}

	////////////////////////////////////////////////////////////////////////

void updateName() {
	string newName;
	cout << "Enter your name: ";
	cin.ignore();
	getline(cin, newName);
	name = newName;
	system("CLS");
}

	////////////////////////////////////////////////////////////////////////

int main()
{
	system("color 3");
	srand(time(0));
	vector<Question> que;
	vector<int> id;
	int i = 0;
	string fileName = "Quiz.txt";
	Questions(i, que, fileName, id);

	int input;
	do {
		input = esasmenu();
		switch (input) {
		case 1:
			menuAdminFile(i, que, fileName, id);
			break;
		case 2:
			updateName();
			break;
		case 3:
			quizYaratmaq(que, id);
			break;
		}

	} while (input != 4);

	system("pause");
}