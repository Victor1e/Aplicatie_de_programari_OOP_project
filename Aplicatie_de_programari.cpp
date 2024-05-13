#include <iostream>
#include <vector>
#include <string>
#include <exception>

using namespace std;

class exceptie: public exception{
public:
    const char* what() const throw() {
        return "Optiune inexistenta";
    }

};



class Package {
protected:
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

    virtual float getPrice() const {
        return price;
    }



protected:
    void afisareDetalii(){
        cout<<"Nume "<< name<<endl;
        cout<<"Price "<< price<<endl;
    }

};

class PackageRedus: public Package{
private:
    int reducere;
public:
    PackageRedus(): reducere(0) {}
    PackageRedus(const string& nume, float price, int reducere) : Package(nume,price), reducere{reducere} {}
    int getReducere() const {
        return reducere;
    }

    void setReducere(int newreducere) {
        reducere = newreducere;
    }
    void afisareSalariu() {
        afisareDetalii();
        cout << "Reducere: " << reducere << endl;
    }
    float getPrice() const{
        return price-reducere;
    }

};

class Barber{
private:
    static string NumeFirma;
protected:
    string firstName;
    string lastName;
    vector<Package*> packages;
    virtual void AskForPromotion()=0;



public:

    Barber(){}
    Barber(const string& first, const string& last, const vector<Package*>& p)
            : firstName(first), lastName(last), packages(p) {}
    void setFirstName(const string& newFirstName) {
        firstName = newFirstName;
    }

    void setLastName(const string& newLastName) {
        lastName = newLastName;
    }

    void addPackage( Package* newPackage) {
        packages.push_back(newPackage);
    }

    string getFirstName() const {
        return firstName;
    }

    string getLastName() const {
        return lastName;
    }

    vector<Package*> getPackages() const {
        return packages;
    }
    friend istream& operator>>(istream& in, Barber& barber);

    static void setNumeFirma(string &nume){
        NumeFirma=nume;
    }
    static string getNumeFirma() {
        return NumeFirma;
    }


};

string Barber::NumeFirma="";

class BarberAvansat : public Barber {
public:
    BarberAvansat() {};

    BarberAvansat(const string& first, const string& last, const vector<Package*>& p): Barber(first,last,p) {}

    void AskForPromotion(){
        if(packages.size()>3)
            cout<<"Primesti o promovare"<<endl;
        else
            cout<<"Nu primesti o promovare"<<endl;
    }

};

class BarberIncepator : public Barber {

public:
    BarberIncepator(){}

    BarberIncepator(const string& first, const string& last, const vector<Package*>& p)
            : Barber(first, last, p) {}

    void AskForPromotion(){
        cout<<"Nu primesti o promovare"<<endl;
    }
};


class Appointment {
private:
    string firstName;
    string lastName;
    Barber *barber= nullptr;
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

    void setBarber( Barber& newBarber) {
        barber = &newBarber;
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

    Barber* getBarber() const {
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

void addBarber(vector<Barber*>& barbers) {
    int choice;
    cout << "Selectati tipul de frizer:" << endl;
    cout << "1. AVANSAT " << endl;
    cout << "2. INCEPATOR " << endl;
    cout << "Selectati indexul tipului de frizer dorit: ";
    cin >> choice;
    if (choice==1)
    {
        //upcasting!!!
        Barber*newBarber=new BarberAvansat;
        cout<<"Numele Frizerului: ";
        cin>>*newBarber;
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
        for (int i = 0; i < numPackages; ++i)
        {
            cout<<"Are o reducere pachetul?... 1.Da/ 2.NU"<< endl;
            int numar;
            cin>>numar;
            //upcasting!!!!
            Package* newPackage = nullptr;
            if(numar==1)
            {

                PackageRedus* temp = new PackageRedus;
                cout<<"Spuneti-mi reducerea: ";
                int reducere;
                cin>>reducere;
                temp->setReducere(reducere);
                newPackage = temp;
                cout << "Numele pachetului: "<<endl;
                string packageName;
                cin >> packageName;
                newPackage->setName(packageName);
                cout << "Pretul pachetului: "<<endl;
                float packagePrice;
                cin >> packagePrice;
                newPackage->setPrice(packagePrice);
                newBarber->addPackage(newPackage);
            }
            else{
                newPackage = new Package;
                cout << "Numele pachetului: "<<endl;
                string packageName;
                cin >> packageName;
                newPackage->setName(packageName);
                cout << "Pretul pachetului: "<<endl;
                float packagePrice;
                cin >> packagePrice;
                newPackage->setPrice(packagePrice);
                newBarber->addPackage(newPackage);
            }

        }
        barbers.push_back(newBarber);
    }else{
        Barber*newBarber= new BarberIncepator;
        cout<<"Numele Frizerului: ";
        cin>>*newBarber;
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
        for (int i = 0; i < numPackages; ++i)
        {
            Package newPackage;
            cout << "Numele pachetului: ";
            string packageName;
            cin >> packageName;
            newPackage.setName(packageName);
            cout << "Pretul pachetului: ";
            float packagePrice;
            cin >> packagePrice;
            newPackage.setPrice(packagePrice);
            newBarber->addPackage(&newPackage);
        }
        barbers.push_back(newBarber);
    }



}

void displayBarbers(const vector<Barber*>& barbers) {
    cout << "Frizeri:" << endl;
    for (const auto& barber : barbers) {
        cout << "Nume: " << barber->getFirstName() << " " << barber->getLastName() << endl;
        cout << "Pachete:" << endl;
        for (const auto& package : barber->getPackages()) {
            cout << "- " << package->getName() << " (" << package->getPrice() << " lei)" << endl;
        }
        cout << endl;
    }
}

void addAppointment(const vector<Barber*>& barbers, vector<Appointment>& appointments) {
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
    if( barberIndex> barbers.size())
        throw "Index invalid";
    newAppointment.setBarber(*barbers[barberIndex]);
    cout << "Selectati pachetul dorit:" << endl;

    //Afisez indexul pachetului oferit alaturi de pachetul in sine si pretul lui
    for (size_t i = 0; i < newAppointment.getBarber()->getPackages().size(); ++i) {
        cout << i << ". " << newAppointment.getBarber()->getPackages()[i]->getName() << " ("
             << newAppointment.getBarber()->getPackages()[i]->getPrice() << " lei)" << endl;
    }


    int packageIndex;
    cout << "Selectati indexul pachetului dorit: ";
    cin >> packageIndex;
    newAppointment.setPackage(*newAppointment.getBarber()->getPackages()[packageIndex]);
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
        cout << "Frizer: " << appointment.getBarber()->getFirstName() << " " << appointment.getBarber()->getLastName() << endl;
        cout << "Pachet: " << appointment.getPackage().getName() << " ("
             << appointment.getPackage().getPrice() << " lei)" << endl;
        cout << "Ora programarii: " << appointment.getHour() << endl;
        cout << endl;
    }
}

int main() {
    vector<Barber*> barbers;
    vector<Appointment> appointments;
    string frizerie;
    cout<<"Cum se numeste Frizeria?";
    getline(cin,frizerie);
    Barber::setNumeFirma(frizerie);
    int choice;
    do
    {
        try{
            cout << "Bun venit la "<<Barber::getNumeFirma()<<"!" << endl;
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
                    try {
                        addAppointment(barbers, appointments);
                    }
                    catch(...){
                        cout<<"Index invalid, incercati din nou..."<<endl;
                    }
                    break;
                case 4:
                    displayAppointments(appointments);
                    break;
                case 5:
                    cout << "Va multumim, o zi frumoasa!" << endl;
                    break;
                default:
                    throw *(new exceptie);
            }
        }
        catch (const exceptie& e){
            cout<<e.what()<<endl;
        }

    } while (choice != 5);

    return 0;
}


