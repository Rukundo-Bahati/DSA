#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool isNumber(const string &input) {
    for (char c : input) {
        if (!isdigit(c))
            return false;
    }
    return !input.empty();
}

struct MemberLL {
    int member_id;
    string name;
    int phone;
    string moto_no;
    string join_date;
    MemberLL *next;

    MemberLL(int member_id, string name, int phone, string moto_no, string join_date) {
        this->member_id = member_id;
        this->name = name;
        this->phone = phone;
        this->moto_no = moto_no;
        this->join_date = join_date;
        next = nullptr;
    }
};

void saveMembersToFile(MemberLL *head) {
    ofstream file("cooperative.txt");
    MemberLL *current = head;

    while (current != nullptr) {
        file << current->member_id << " "
             << current->name << " "
             << current->phone << " "
             << current->moto_no << " "
             << current->join_date << endl;
        current = current->next;
    }

    file.close();
}

MemberLL *addMember(MemberLL *head) {
    string input;
    int id, phone;
    string name, moto_no, join_date;

    cout << "ID: ";
    cin >> input;

    if (!isNumber(input)) {
        cout << "Invalid input. ID must be a number." << endl;
        return head;
    }
    id = stoi(input);

    MemberLL *temp = head;
    while (temp != nullptr) {
        if (temp->member_id == id) {
            cout << "Member with ID " << id << " already exists." << endl;
            return head;
        }
        temp = temp->next;
    }

    cout << "Name: ";
    cin >> name;
    cout << "Phone: ";
    cin >> phone;
    cout << "Motorcycle No: ";
    cin >> moto_no;
    cout << "Date Joined (DD-MM-YY): ";
    cin >> join_date;

    MemberLL *member = new MemberLL(id, name, phone, moto_no, join_date);
    member->next = head;
    head = member;

    saveMembersToFile(head);

    cout << "Member added Successfully!" << endl;
    return head;
}

MemberLL *updateMember(MemberLL *head) {
    if (!head) {
        cout << "The list is empty." << endl;
        return head;
    }

    string input;
    int id, phone;
    string name, moto_no, join_date;

    cout << "Enter member ID to update: ";
    cin >> input;

    if (!isNumber(input)) {
        cout << "Invalid input. ID must be a number." << endl;
        return head;
    }
    id = stoi(input);

    MemberLL *current = head;
    while (current != nullptr) {
        if (current->member_id == id) {
            cout << "Member found. Enter new details:" << endl;
            cout << "Name: ";
            cin >> name;
            cout << "Phone: ";
            cin >> phone;
            cout << "Motorcycle No: ";
            cin >> moto_no;
            cout << "Date Joined (DD-MM-YY): ";
            cin >> join_date;

            current->name = name;
            current->phone = phone;
            current->moto_no = moto_no;
            current->join_date = join_date;

            saveMembersToFile(head);

            cout << "Member updated successfully!" << endl;
            return head;
        }
        current = current->next;
    }

    cout << "Member ID not found." << endl;
    return head;
}

MemberLL *deleteMember(MemberLL *head) {
    if (!head) {
        cout << "The list is empty." << endl;
        return head;
    }

    string input;
    int id;

    cout << "Enter member ID to delete: ";
    cin >> input;

    if (!isNumber(input)) {
        cout << "Invalid input. ID must be a number." << endl;
        return head;
    }
    id = stoi(input);

    MemberLL *current = head;
    MemberLL *previous = nullptr;

    while (current != nullptr && current->member_id != id) {
        previous = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Member ID not found." << endl;
        return head;
    }

    if (previous == nullptr) {
        head = current->next;
    } else {
        previous->next = current->next;
    }

    delete current;

    saveMembersToFile(head);

    cout << "Member deleted successfully!" << endl;
    return head;
}

void displayAllMembers(MemberLL *head) {
    if (!head) {
        cout << "No members available." << endl;
        return;
    }

    cout << "\n| ID | Name         | Phone      | Motorcycle No | Join Date  |\n";
    cout << "-------------------------------------------------------------\n";

    MemberLL *current = head;
    while (current != nullptr) {
        cout << "| " << current->member_id << "  | "
             << current->name << " | "
             << current->phone << " | "
             << current->moto_no << " | "
             << current->join_date << " |\n";
        current = current->next;
    }
    cout << endl;
}

int main() {
    MemberLL *member = nullptr;

    string input;
    int choice;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add A New Member\n";
        cout << "2. Display All Members\n";
        cout << "3. Update A Member\n";
        cout << "4. Delete A Member\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> input;

        if (!isNumber(input)) {
            cout << "Invalid choice. Please enter a number." << endl;
            continue;
        }
        choice = stoi(input);

        switch (choice) {
            case 1:
                member = addMember(member);
                break;
            case 2:
                displayAllMembers(member);
                break;
            case 3:
                member = updateMember(member);
                break;
            case 4:
                member = deleteMember(member);
                break;
            case 5:
                cout << "Thank you for using the system." << endl;
                return 0;
            default:
                cout << "Invalid option chosen." << endl;
        }
    }

    return 0;
}
