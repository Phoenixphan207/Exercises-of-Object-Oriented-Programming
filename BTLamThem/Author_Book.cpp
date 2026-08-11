#include <iostream>
#include <vector>

using namespace std;

class Author{
private:
    string name;
    string email;
public:
    Author(string name, string email) : name(name) , email(email) {};
    void setName(string name) {
        name = name;
    }
    string getName(){ 
        return name;
    }
    void setEmail(string email) {
        email = email;
    }
    string getEmail() {
        return email;
    }
};

class Book {
private:
    string name;
    vector<Author> authors;
    double price;
public:
    Book(string name, vector<Author> authors , double price): name(name) , authors(authors) , price(price) {};

    void setName(string name) {
        name = name;
    }
    string getName() {
        return name;
    }
    void setPrice(double price) {
        price = price;
    }
    double getPrice() {
        return price;
    }

    string getAuthorNames() {
        string getAuthor = "";
        for (int i = 0 ; i < authors.size() - 1; i++) {
            getAuthor += authors[i].getName() + ",";
        }
        getAuthor += authors[authors.size() - 1].getName();
        return getAuthor;
    }
};

int main() {
	vector<Author> authors;
	authors.push_back(Author("Viet", "VietCV@codelearn.io"));
	authors.push_back(Author("Tuan", "TuanLQ7@codelearn.io"));
	authors.push_back(Author("KienNT", "KienNT@codelearn.io"));

	Book book1("C++ for Beginners", authors, 210000);
	cout << book1.getAuthorNames();	
	return 0;
}
