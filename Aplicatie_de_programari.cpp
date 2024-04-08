#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Package {
private:
    string name;
    float price;

public:
    Package(const string& name_, float price_) : name{name_}, price{price_} {

    }
    Package(){}

    ~Package() {
    }

    void setName(const string& newName) {
        name = newName;
    }

    void setPrice(float newPrice) {
        price = newPrice;
    }

    string getName() const {
        return name;
    }

    float getPrice() const {
        return price;
    }
};

class Barber {
private:
    string firstName;
    string lastName;
    vector<Package> packages;

public:
    Barber(){}
    void setFirstName(const string& newFirstName) {
        firstName = newFirstName;
    }

    void setLastName(const string& newLastName) {
        lastName = newLastName;
    }

    void addPackage(const Package& newPackage) {
        packages.push_back(newPackage);
    }

    string getFirstName() const {
        return firstName;
    }

    string getLastName() const {
        return lastName;
    }

    vector<Package> getPackages() const {
        return packages;
    }
    friend istream& operator>>(istream& in, Barber& barber);
};

class Appointment {
private:
    string firstName;
    string lastName;
    Barber barber;
    Package package;
    int hour;

public:
    Appointment(){}
    void setFirstName(const string& newFirstName) {
        firstName = newFirstName;
    }

    void setLastName(const string& newLastName) {
        lastName = newLastName;
    }

    void setBarber(const Barber& newBarber) {
        barber = newBarber;
    }

    void setPackage(const Package& newPackage) {
        package = newPackage;
    }

    void setHour(int newHour) {
        hour = newHour;
    }

    string getFirstName() const {
        return firstName;
    }

    string getLastName() const {
        return lastName;
    }

    Barber getBarber() const {
        return barber;
    }

    Package getPackage() const {
        return package;
    }

    int getHour() const {
        return hour;
    }
};

istream& operator>>(istream& in, Barber& barber){
    in>>barber.firstName;
    in>>barber.lastName;
    return in;
}

void addBarber(vector<Barber>& barbers) {
    Barber newBarber;
    cout<<"Numele Frizerului: ";
    cin>>newBarber;
    /*
    Barber newBarber;
    cout << "Numele Frizerului: ";
    string firstName, lastName;
    cin >> firstName;
    newBarber.setFirstName(firstName);
    cout << "Prenumele Frizerului: ";
    cin >> lastName;
    newBarber.setLastName(lastName);
    */
    int numPackages;
    cout << "Cate pachete de tuns stie frizerul?: ";
    cin >> numPackages;
    for (int i = 0; i < numPackages; ++i) {
        Package newPackage;
        cout << "Numele pachetului: ";
        string packageName;
        cin >> packageName;
        newPackage.setName(packageName);
        cout << "Pretul pachetului: ";
        float packagePrice;
        cin >> packagePrice;
        newPackage.setPrice(packagePrice);
        newBarber.addPackage(newPackage);
    }
    barbers.push_back(newBarber);
}

void displayBarbers(const vector<Barber>& barbers) {
    cout << "Frizeri:" << endl;
    for (const auto& barber : barbers) {
        cout << "Nume: " << barber.getFirstName() << " " << barber.getLastName() << endl;
        cout << "Pachete:" << endl;
        for (const auto& package : barber.getPackages()) {
            cout << "- " << package.getName() << " (" << package.getPrice() << " lei)" << endl;
        }
        cout << endl;
    }
}

void addAppointment(const vector<Barber>& barbers, vector<Appointment>& appointments) {
    Appointment newAppointment;
    cout << "Cum va numiti:"<< endl;
    cout << "Nume: ";
    string firstName, lastName;
    cin >> firstName;
    newAppointment.setFirstName(firstName);
    cout << "Prenume: ";
    cin >> lastName;
    newAppointment.setLastName(lastName);
    cout << "Selectati un frizer:" << endl;
    displayBarbers(barbers);
    int barberIndex;
    cout << "Selectati indexul frizerului dorit (indexarea se face de la 0): ";
    cin >> barberIndex;
    newAppointment.setBarber(barbers[barberIndex]);
    cout << "Selectati pachetul dorit:" << endl;

    //Afisez indexul pachetului oferit alaturi de pachetul in sine si pretul lui
    for (size_t i = 0; i < newAppointment.getBarber().getPackages().size(); ++i) {
        cout << i << ". " << newAppointment.getBarber().getPackages()[i].getName() << " ("
             << newAppointment.getBarber().getPackages()[i].getPrice() << " lei)" << endl;
    }


    int packageIndex;
    cout << "Selectati indexul pachetului dorit: ";
    cin >> packageIndex;
    newAppointment.setPackage(newAppointment.getBarber().getPackages()[packageIndex]);
    int hour;
    cout << "Selectati o ora de la 9 la 17: ";
    cin >> hour;
    newAppointment.setHour(hour);
    appointments.push_back(newAppointment);
}


void displayAppointments(const vector<Appointment>& appointments) {
    cout << "Programari:" << endl;
    for (const auto& appointment : appointments) {
        cout << "Nume: " << appointment.getFirstName()<< " " << appointment.getLastName() << endl;
        cout << "Frizer: " << appointment.getBarber().getFirstName() << " " << appointment.getBarber().getLastName() << endl;
        cout << "Pachet: " << appointment.getPackage().getName() << " ("
             << appointment.getPackage().getPrice() << " lei)" << endl;
        cout << "Ora programarii: " << appointment.getHour() << endl;
        cout << endl;
    }
}

int main() {
    vector<Barber> barbers;
    vector<Appointment> appointments;
    int choice;
    do {
        cout << "Bun venit la Atelierul de tuns!" << endl;
        cout << "Va rugam sa alegeti optiunea dorita" << endl;
        cout << "1. Adauga un frizer" << endl;
        cout << "2. Afiseaza frizerii si pachetele pe care acestia le ofera" << endl;
        cout << "3. Efectuati o programare" << endl;
        cout << "4. Afisati programarile" << endl;
        cout << "5. Iesiti" << endl;
        cout << "Selectati indexul optiunii dorite: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBarber(barbers);
                break;
            case 2:
                displayBarbers(barbers);
                break;
            case 3:
                addAppointment(barbers, appointments);
                break;
            case 4:
                displayAppointments(appointments);
                break;
            case 5:
                cout << "Va multumim, o zi frumoasa!" << endl;
                break;
            default:
                cout << "Optiune inexistenta" << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}
