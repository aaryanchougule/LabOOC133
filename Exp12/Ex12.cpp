#include <iostream>
#include <string>
using namespace std;

// Abstract class
class Record {
public:
    virtual void display() const = 0;

    virtual ~Record() {}
};

// Book class
class Book : public Record {
private:
    int id;
    string name;
    double price;
    int quantity;

    static int count;
    static int nextId;

public:
    // Nested class
    class Details {
    public:
        string author;
        int year;

        Details(string a = "", int y = 0)
            : author(a), year(y) {}
    };

    Details details;

    // Constructor
    Book(string n, string a, int y, double p, int q)
        : id(nextId++), name(n), price(p),
          quantity(q), details(a, y) {
        count++;
        cout << "Book constructor called.\n";
    }

    // Destructor
    ~Book() override {
        count--;
        cout << "Book destructor called: " << name << endl;
    }

    // Function overloading
    void add(string n, double p) {
        name = n;
        price = p;
    }

    void add(string n, string a, int y, double p, int q) {
        name = n;
        details.author = a;
        details.year = y;
        price = p;
        quantity = q;
    }

    int getId() const { return id; }
    string getName() const { return name; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }

    static int getCount() {
        return count;
    }

    void display() const override {
        cout << "\nBook ID: " << id
             << "\nName: " << name
             << "\nAuthor: " << details.author
             << "\nYear: " << details.year
             << "\nPrice: Rs. " << price
             << "\nQuantity: " << quantity << endl;
    }

    // Friend function
    friend void showBook(const Book& b);
};

int Book::count = 0;
int Book::nextId = 1;

// Friend function implemented internally
void showBook(const Book& b) {
    cout << "\nBook details accessed by friend function:"
         << "\nID: " << b.id
         << "\nName: " << b.name
         << "\nPrice: Rs. " << b.price << endl;
}

// User class
class User : public Record {
private:
    int id;
    string name;
    string phone;

    static int nextId;

public:
    User(string n, string p)
        : id(nextId++), name(n), phone(p) {
        cout << "User constructor called.\n";
    }

    ~User() override {
        cout << "User destructor called: " << name << endl;
    }

    int getId() const { return id; }

    void display() const override {
        cout << "\nUser ID: " << id
             << "\nName: " << name
             << "\nPhone: " << phone << endl;
    }
};

int User::nextId = 1;

int main() {
    const int MAX = 100;

    
    Book* books[MAX];
    User* users[MAX];

    int bookCount = 0;
    int userCount = 0;
    int choice;

    do {
        cout << "\n===== BOOKSHOP MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book\n";
        cout << "4. Update Book Price\n";
        cout << "5. Show Total Books\n";
        cout << "6. Add User\n";
        cout << "7. Display Users\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            if (bookCount >= MAX) {
                cout << "Book storage is full.\n";
                break;
            }

            string name, author;
            int year, qty;
            double price;

            cin.ignore(10000, '\n');
            cout << "Enter book name: ";
            getline(cin, name);
            cout << "Enter author: ";
            getline(cin, author);
            cout << "Enter publication year: ";
            cin >> year;
            cout << "Enter price: ";
            cin >> price;
            cout << "Enter quantity: ";
            cin >> qty;

            if (price < 0 || qty < 0) {
                cout << "Invalid price or quantity.\n";
                break;
            }

            books[bookCount] =
                new Book(name, author, year, price, qty);

            cout << "Book added. ID: "
                 << books[bookCount]->getId() << endl;
            bookCount++;
            break;
        }

        case 2:
            if (bookCount == 0)
                cout << "No books available.\n";

            for (int i = 0; i < bookCount; i++)
                books[i]->display();
            break;

        case 3: {
            int id;
            bool found = false;

            cout << "Enter book ID: ";
            cin >> id;

            for (int i = 0; i < bookCount; i++) {
                if (books[i]->getId() == id) {
                    books[i]->display();
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Book not found.\n";
            break;
        }

        case 4: {
            int id;
            double price;
            bool found = false;

            cout << "Enter book ID: ";
            cin >> id;
            cout << "Enter new price: ";
            cin >> price;

            if (price < 0) {
                cout << "Price cannot be negative.\n";
                break;
            }

            for (int i = 0; i < bookCount; i++) {
                if (books[i]->getId() == id) {
                    books[i]->add(books[i]->getName(), price);
                    cout << "Price updated successfully.\n";
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Book not found.\n";
            break;
        }

        case 5:
            cout << "Total books: " << Book::getCount() << endl;
            break;

        case 6: {
            if (userCount >= MAX) {
                cout << "User storage is full.\n";
                break;
            }

            string name, phone;

            cin.ignore(10000, '\n');
            cout << "Enter user name: ";
            getline(cin, name);
            cout << "Enter phone number: ";
            getline(cin, phone);

            users[userCount] = new User(name, phone);

            cout << "User added. ID: "
                 << users[userCount]->getId() << endl;
            userCount++;
            break;
        }

        case 7:
            if (userCount == 0)
                cout << "No users available.\n";

            for (int i = 0; i < userCount; i++)
                users[i]->display();
            break;

        case 0:
            cout << "Exiting Bookshop Management System.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    // Friend function demonstration (no separate menu option)
    if (bookCount > 0)
        showBook(*books[0]);

    // Polymorphism demonstration using base-class pointers
    cout << "\nPolymorphism demonstration:\n";

    for (int i = 0; i < bookCount; i++) {
        Record* record = books[i];
        record->display();
    }

    for (int i = 0; i < userCount; i++) {
        Record* record = users[i];
        record->display();
    }

    // Release dynamically allocated memory
    for (int i = 0; i < bookCount; i++)
        delete books[i];

    for (int i = 0; i < userCount; i++)
        delete users[i];

    return 0;
}