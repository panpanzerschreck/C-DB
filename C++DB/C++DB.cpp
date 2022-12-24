
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
using namespace std;

class author
{

public:
	size_t ID;
	size_t get_ID() {
		return ID;
	}
	string country;
	string dovidka;
	string authName;
};
class contract
{
	
public:
	size_t ID;
	size_t get_ID() {
		return ID;
	}
	string edition;
	string bookName;
	size_t PubH;
	size_t Author;
};
class pubH {
	
public:
	size_t ID;
	size_t get_ID() {
		return ID;
	}
	string country;
	string ISBN;
	string Name;
	string language;
};
vector<author> authors;
vector<contract> contracts;
vector<pubH> PubHs;

//contract get_contract_of_author(size_t id) {
//	for (size_t i = 0; i < contracts.size(); i++)
//	{
//		if (contracts[i].get_ID() == authors[id].Contract)
//		{
//			return contracts[i];
//		}
//	}
//	cout << "contract not found";
//	return contracts[0];
//}
//contract get_contract_of_pubH(size_t id) {
//	for (size_t i = 0; i < contracts.size(); i++)
//	{
//		if (contracts[i].get_ID() == PubHs[id].Contract)
//		{
//			return contracts[i];
//		}
//	}
//	cout << "contract not found";
//	return contracts[0];
//}
//
//author get_author(size_t id) {
//	for (size_t i = 0; i < authors.size(); i++)
//	{
//		if (authors[i].get_ID() == contracts[id].Author)
//		{
//			return authors[i];
//		}
//	}
//	cout << "author not found";
//	return authors[0];
//}
//pubH get_pubH(size_t id) {
//	for (size_t i = 0; i < PubHs.size(); i++)
//	{
//		if (PubHs[i].get_ID() == contracts[id].PubH)
//		{
//			return PubHs[i];
//		}
//	}
//	cout << "Publishing house not found";
//	return PubHs[0];
//}


void main_menu() {

	cout << "\t*********************" << endl;
	cout << "\tWhat to do?" << endl;
	cout << "\t1. Check all authors" << endl;
	cout << "\t2. Check all publishing houses" << endl;
	cout << "\t3. Add contract" << endl;
	cout << "\t4. Modify contract" << endl;
	cout << "\t5. Delete contract" << endl;
	cout << "\t6. Check all contracts" << endl;
	cout << "\t7. Exit" << endl;
	cout << "\t8. Author menu" << endl;
	cout << "\t9. Publishing house menu" << endl;
}
void author_menu(){
	cout << "\t*********************" << endl;
	cout << "\tWhat to do?" << endl;
	cout << "\t1. Add an author" << endl;
	cout << "\t2. Delete an author" << endl;
	cout << "\t3. Return" << endl;
}
void pH_menu() {

	cout << "\t*********************" << endl;
	cout << "\tWhat to do?" << endl;
	cout << "\t1. Add a publishing house" << endl;
	cout << "\t2. Delete a publishing house" << endl;
	cout << "\t3. Return" << endl;

}


void reading() {

	PubHs.clear();
	authors.clear();
	contracts.clear();
	ifstream Pfile;
	Pfile.open("pubHs.txt");
	if (Pfile.is_open())
	{
		pubH temp;
		while (!Pfile.eof()) {
			Pfile >> temp.ID
				>> temp.country
				>> temp.ISBN
				>> temp.language
				>> temp.Name;
			PubHs.push_back(temp);
		}
	}

	ifstream cfile;
	cfile.open("contracts.txt");
	if (cfile.is_open() )
	{
		contract temp;
		while (!cfile.eof()) {
			cfile >> temp.ID
				>> temp.Author
				>> temp.PubH
				>> temp.bookName
				>> temp.edition;
			contracts.push_back(temp);
		}
	}
	ifstream afile;
	afile.open("authors.txt");
	if (afile.is_open())
	{
		author temp;
		while (!afile.eof()) {
			afile >> temp.ID
				>> temp.authName
				>> temp.country
				>> temp.dovidka;
			authors.push_back(temp);
		}
	}
}
void check_c() {
	for (size_t i = 0; i < contracts.size(); i++)
	{
		cout << i + 1 << "\t" << contracts[i].bookName << "\t"
			<< contracts[i].edition << "\t"
			<< contracts[i].get_ID()<< endl;
	}
}
void check_a() {
	for (size_t i = 0; i < authors.size(); i++)
	{
		cout << i + 1 << "\t" << authors[i].authName << "\t"
			<< authors[i].country << endl
			<< authors[i].dovidka << endl;
	}
}
void check_pH() {
	for (size_t i = 0; i < PubHs.size(); i++)
	{
		cout << i + 1 << "\t" << PubHs[i].Name << "\t"
			<< PubHs[i].country << "\t"
			<< PubHs[i].language << "\t"
			<< PubHs[i].ISBN << endl;
	}

}

void update_a(){
	ofstream file;
	file.open("authors.txt");
	if (file.is_open()) {
		for (size_t i = 1; i < authors.size(); i++)
		{
			file << authors[i].get_ID()<<"\t"<<
				authors[i].authName<<"\t"<<
				authors[i].country<<"\t"<<
				authors[i].dovidka<<
				endl;
		}
		cout << "updated authors" << endl;
	}
	else {
		cout << "Couldn't open the file!" << endl << endl;
	}
}
void update_c() {
	ofstream file;
	file.open("contracts.txt");
	if (file.is_open()) {
		for (size_t i = 0; i < contracts.size(); i++)
		{
			file << contracts[i].get_ID() << "\t" <<
				contracts[i].Author << "\t" <<
				contracts[i].PubH << "\t" <<
				contracts[i].bookName << "\t" <<
				contracts[i].edition <<
				endl;

		}
	}
	else {
		cout << "Couldn't open the file!" << endl << endl;
	}
}
void update_pH(){
	ofstream file;
	file.open("pubHs.txt");
	if (file.is_open()) {
		for (size_t i = 0; i < PubHs.size(); i++)
		{
			file << PubHs[i].get_ID() << "\t" <<
				PubHs[i].country << "\t" <<
				PubHs[i].ISBN << "\t" <<
				PubHs[i].language << "\t" <<
				PubHs[i].Name <<
				 endl;
		}
	}
	else {
		cout << "Couldn't open the file!" << endl << endl;
	}
}

void on_start() {
	fstream cfile;
	fstream afile;
	fstream pfile;
	contract temp_c;
	pubH temp_p;
	author temp_a;
	int inp, j;
	afile.open("authors.txt");
	pfile.open("pubHs.txt");
	cfile.open("contracts.txt");
	if (cfile.is_open())
	{
		reading();
		while (true)
		{
			main_menu();
			cin >> inp;
			cout << "\tReady to work." << endl;
			switch (inp)
			{
			case 1:
				check_a();
				break;
			case 2:
				check_pH();
				break;
			case 3:
				cout << "\tEnter book's name: " << endl;
				cin >> temp_c.bookName;
				cout << "\tEnter edition" << endl;
				cin >> temp_c.edition;
				cout << "\t Authors:" << endl;
				for (size_t i = 0; i < authors.size(); i++)
				{
					cout << i + 1 << "\t" << authors[i].authName << "\t"
						<< authors[i].country << endl
						<< authors[i].dovidka << endl;
				}
				cout << "Enter author\'s ID:"<< endl;
				cin >> inp;
				temp_c.Author = authors[--inp].get_ID();
				cout << "Publishing houses:"<< endl;
				for (size_t i = 0; i < PubHs.size(); i++)
				{
					cout << i + 1 << "\t" << PubHs[i].Name<<"\t" << PubHs[i].ISBN << endl;
				}
				cout << "Enter publishing house\'s ID:" << endl;
				cin >> inp;
				temp_c.PubH = PubHs[--inp].get_ID();
				j = contracts.size();
				cout << j;
				if (j == 1)
				{
					temp_c.ID = 0;
				}
				else
				{
					temp_c.ID = contracts[j--].ID++;
				}
				cout << j;
				contracts.push_back(temp_c);
				update_c();
				break;
			case 4:
				cout << "Enter contract ID to modify: " << endl; cin >> inp;
				cout << "Enter new book name : " << endl; cin >> temp_c.bookName;
				cout << "Enter author ID: " << endl; cin >> inp;
				temp_c.Author = authors[--inp].get_ID();
				cout << "Enter publishing house ID: " << endl;
				cin >> inp;
				temp_c.PubH = PubHs[--inp].get_ID();
				update_c();
				break;
			case 5: cout << "Enter ID of contract to delete" << endl;
				cin >> inp;
				inp--;
				contracts.erase(contracts.begin() + inp);
				cout << "Contract deleted" << endl;
				break;
			case 6:
				check_c();
				break;
			case 7: return;
			case 8: author_menu();
				cin >> inp;
				if (inp == 1)
				{
					cout << "Enter name" << endl;
					cin >> temp_a.authName;
					cout << "Enter country" << endl;
					cin >> temp_a.country;
					cout << "Enter some details"<< endl;
					cin >> temp_a.dovidka;
					j = authors.size();
					cout << j;
					if (j==0)
					{
						temp_a.ID = 0;
					}
					else
					{
						temp_a.ID = authors[j--].ID++;
					}
					authors.push_back(temp_a);
					update_a();
					break;
				}
				else if (inp == 2)
				{
					cin >> inp;
					inp--;
					authors.erase(authors.begin() + inp);
					cout << "Author deleted" << endl;
					update_a();
					break;
				}
				else break;
				break;
			case 9: pH_menu();
				cin >> inp;
				if (inp == 1)
				{
					cout << "Enter name" << endl;
					cin>>temp_p.Name;
					cout << "Enter country" << endl;
					cin >> temp_p.country;
					cout << "Enter ISBN" << endl;
					cin >> temp_p.ISBN;
					cout << "Enter language" << endl;
					cin >> temp_p.language;
					j = PubHs.size();
					if (j==0)
					{
						temp_p.ID = 0;
					}
					else
					{
						temp_p.ID = PubHs[j--].ID++;
					}
					PubHs.push_back(temp_p);
					update_pH();
					break;
				}
				else if (inp == 2)
				{
					cin >> inp;
					inp--;
					PubHs.erase(PubHs.begin() + inp);
					cout << "Publishing house deleted" << endl;
					update_pH();
					break;
				}
				else break;
				break;
			default:
				cout << "Wrong input" << endl;
			}
		}
	}
	else
	{
		cout << "file is not read" << endl << endl;
	}
}
int main()
{
	on_start();
	return 0;
}






