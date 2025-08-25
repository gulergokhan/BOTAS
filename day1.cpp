#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Team {
private:

	string memberName;
	int memberNo;
	string type;
	string depart;

public:

	Team(string _memberName, int _memberNo, string _type, string _depart) {

		this->memberName = _memberName;
		this->memberNo = _memberNo;
		this->type = _type;
		this->depart = _depart;
	}

	~Team() {

	}

	string getMemberName()const { return memberName; }
	int getMemberNo()const { return memberNo; }
	string getMemberType()const { return type; }
	string getDepart()const { return depart; }

	void printAllInfo()const {

		cout << "||Team Member Name ||: " << memberName << endl;
		cout << "|| Team Member No  || : " << memberNo << endl;
		cout << "|| Team Member Type || : " << type << endl;
		cout << "|| Team Member Department || : " << depart << endl;


		cout << endl << endl;
	}


};

void addMember(vector<Team>& hTeams) {

	string _memberName;
	int _memberNo;
	string _type;
	string _depart;

	cout << "Enter the number :";
	cin >> _memberNo;

	cin.ignore();

	cout << "Enter the member name : ";
	getline(cin, _memberName);

	cout << "Enter the member profession : ";
	getline(cin, _type);

	cout << "Enter the member department : ";
	getline(cin, _depart);


	hTeams.push_back(Team(_memberName, _memberNo, _type, _depart));

	cout << "\nMember has added successfully." << endl << endl;

}

void printList(vector<Team>& hTeams) {

	if (hTeams.empty()) {
		cout << "There is no member in the list.\n\n";
		return;
	}

	cout << "######## M E M B E R   L I S T ########" << endl;

	for (const auto& person : hTeams) {

		person.printAllInfo();
		cout << endl;
	}

	cout << endl;
 
}

void searchMember(const vector<Team>& hTeams) {

	int no;

	cout << "Enter the member no : ";
	cin >> no;

	bool flag = false;

	for (const auto& person : hTeams) {

		if (no == person.getMemberNo()) {

			person.printAllInfo();
			flag = true;
			break;


		}
	}

	if (!flag)
		cout << "Invalid number." << endl;


}


void deleteMember(vector<Team>& hTeams) {

	int no;

	cout << "Enter the member num to delete all infos about h/er/im : ";
	cin >> no;

	bool flag = false;

	for (auto it = hTeams.begin(); it != hTeams.end(); it++) {

		if (it->getMemberNo() == no) {

			hTeams.erase(it);
			cout << "Member has successfully deleted." << endl << endl;
		    flag = true;
			break;
		}

	}

	if (!flag)
		cout << "Invalid number." << endl;
}

void main() {


	vector<Team> hTeam;

	int choice;

	do {

		cout << "-----------M E M B E R    M A N A G E M E N T    S Y S T E M ---------\n\n";
		cout << "1.Add Members\n";
		cout << "2.List Team\n";
		cout << "3.Search Team Member\n";
		cout << "4.Delete Member\n";
		cout << "5.Exit from Program\n\n";
		cout << "Input the your choice :";
		cin >> choice;

		cout << endl;


		switch (choice) {

		case 1:

			addMember(hTeam);
			break;

		case 2:

			printList(hTeam);
			break;

		case 3:

			searchMember(hTeam);
			break;

		case 4:

			deleteMember(hTeam);
			break;

		case 5:

			cout << "Program is closing...\n";
			break;

		default:

			cout << "Invalid choice...(Try between 1-5)\n";
		}

	} while (choice != 5);




}
	
