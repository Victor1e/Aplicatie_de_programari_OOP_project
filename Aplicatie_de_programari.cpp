#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <exception>

using namespace std;


class PositiveComment {
private:
    string commentText;

public:
    PositiveComment(const string& text) : commentText(text) {}

    void displayComment() const {
        cout << "Comentariu pozitiv: " << commentText << endl;
    }

    string getComment() const {
        return commentText;
    }
};
class NegativeComment {
private:
    string commentText;

public:
    NegativeComment(const string& text) : commentText(text) {}

    void displayComment() const {
        cout << "Comentariu negativ: " << commentText << endl;
    }

    string getComment() const {
        return commentText;
    }
};
class CommentSystem {
private:
    vector<PositiveComment> positiveComments;
    vector<NegativeComment> negativeComments;

public:
    void addPositiveComment(const PositiveComment& comment) {
        positiveComments.push_back(comment);
    }

    void addNegativeComment(const NegativeComment& comment) {
        negativeComments.push_back(comment);
    }

    void displayAllComments() const {
        cout << "Toate comentarile:" << endl;

        cout << "\nComentarii pozitive:" << endl;
        for (const auto& comment : positiveComments) {
            comment.displayComment();
        }

        cout << "\nComentarii negative:" << endl;
        for (const auto& comment : negativeComments) {
            comment.displayComment();
        }
    }
};


class Produse_curatenie{
private:
    string nume;
    int pret;
    int cantitate;
public:
    Produse_curatenie(){}
    Produse_curatenie(const string nume_, int pret_, int cantitate_): nume{nume_}, pret{pret_},cantitate{cantitate_}{}
    void setName(const string& newName) {
        nume = newName;
    }

    void setPrice(float newPrice) {
        pret = newPrice;
    }
    void setCantitate(int newCantitate){
        cantitate=newCantitate;
    }

    string getName() const {
        return nume;
    }

    int getPrice() const {
        return pret;
    }
    int getCantitate() const{
        return cantitate;
    }



};
class Produse_par{
private:
    string nume;
    int pret;
    int cantitate;
public:
    Produse_par(){}
    Produse_par(const string nume_, int pret_, int cantitate_): nume{nume_}, pret{pret_},cantitate{cantitate_}{}
    void setName(const string& newName) {
        nume = newName;
    }

    void setPrice(float newPrice) {
        pret = newPrice;
    }
    void setCantitate(int newCantitate){
        cantitate=newCantitate;
    }

    string getName() const {
        return nume;
    }

    int getPrice() const {
        return pret;
    }
    int getCantitate() const{
        return cantitate;
    }
};
class Produse{
private:
    vector <Produse_curatenie> produse_curatenie;
    vector <Produse_par> produse_par;
public:
    void add_poduuse_curatenie(vector<Produse_curatenie>& produse_curatenie){
        cout<<"Doriti sa adaugati un produs de curatenie:"<<endl;
        cout<<"Cum se numeste produsul?"<<endl;
        string produs;
        cin>>produs;
        cout<<"Care este pretul produsului?"<<endl;
        int pretul;
        cin>>pretul;
        cout<<"Care este cantitatea de produs dorita?"<<endl;
        int cantitate;
        cin>>cantitate;
        Produse_curatenie new_produse_curatenie(produs,pretul,cantitate);
        produse_curatenie.push_back(new_produse_curatenie);

    }
    void add_poduuse_par(vector<Produse_par>& produse_par){
        cout<<"Doriti sa adaugati un produs de par:"<<endl;
        cout<<"Cum se numeste produsul?"<<endl;
        string produs;
        cin>>produs;
        cout<<"Care este pretul produsului?"<<endl;
        int pretul;
        cin>>pretul;
        cout<<"Care este cantitatea de produs dorita?"<<endl;
        int cantitate;
        cin>>cantitate;
        Produse_par new_produse_par(produs,pretul,cantitate);
        produse_par.push_back(new_produse_par);

    }
    void calcul_pret_produs(vector<Produse_curatenie>& produse_curatenie, vector<Produse_par>& produse_par){
        cout<<"Ce tip de produs doresti sa cauti?"<<endl;
        cout<<"1.Produs de curatenie"<<endl;
        cout<<"2.Produs de par"<<endl;
        cout<<"Alege indexul"<<endl;
        int choice;
        cin>>choice;
        if(choice==1)
        {
            cout<<"Alege produsul dupa index:"<<endl;
            int cnt=0;
            for (const auto& produs_curatenie : produse_curatenie)
            {
                cout<<cnt++<<endl;
                cout<<"Nume: "<<produs_curatenie.getName()<<endl;
            }
            cout<<"Alegerea ta este?"<<endl;
            int alegere;
            cin>>alegere;
            int pret=produse_curatenie[alegere].getPrice()*produse_curatenie[alegere].getCantitate();
            cout<<"Pretul total este: "<<pret<<"lei"<<endl;

        }
        else{
            cout<<"Alege produsul dupa index:"<<endl;
            int cnt=0;
            for (const auto& produs_par : produse_par)
            {
                cout<<cnt<<endl;
                cout<<"Nume: "<<produs_par.getName()<<endl;
            }
            cout<<"Alegerea ta este?"<<endl;
            int alegere;
            cin>>alegere;
            int pret=produse_par[alegere].getPrice()*produse_par[alegere].getCantitate();
            cout<<"Pretul total este: "<<pret<<"lei"<<endl;
        }
    }


};

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
class Barber_Shop{
private:
    vector<Barber*> barbers;
    vector<Appointment> appointments;
public:
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

};


int main() {
    vector<Barber*> barbers;
    vector<Appointment> appointments;
    vector<Produse_curatenie> produse_curatenie;
    vector<Produse_par> produse_par;
    Barber_Shop barber_shop;
    CommentSystem commentSystem;
    Produse produse;
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
            cout << "5. Adaugati un produs de curatenie" << endl;
            cout << "6. Adaugati un produs de par" << endl;
            cout << "7. Calculati pretul unui produs" << endl;
            cout << "8. Comentarii" << endl;
            cout << "9. Iesiti" << endl;
            cout << "Selectati indexul optiunii dorite: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    barber_shop.addBarber(barbers);
                    break;
                case 2:
                    displayBarbers(barbers);
                    break;
                case 3:
                    try {
                        barber_shop.addAppointment(barbers, appointments);
                    }
                    catch(...){
                        cout<<"Index invalid, incercati din nou..."<<endl;
                    }
                    break;
                case 4:
                    displayAppointments(appointments);
                    break;
                case 5:
                    produse.add_poduuse_curatenie(produse_curatenie);
                    break;
                case 6:
                    produse.add_poduuse_par(produse_par);
                    break;
                case 7:
                    produse.calcul_pret_produs(produse_curatenie,produse_par);
                    break;
                case 8:
                    cout<<"1.Scrie un comentariu:"<<endl;
                    cout<<"2.Vizualizeaza comentariile"<<endl;
                    int rasp;
                    cout<<"Alege indexul:"<<endl;
                    cin>>rasp;
                    cin.ignore();
                    if(rasp==1)
                    {
                        cout<<"1.Comentariu negativ:"<<endl;
                        cout<<"2.Comentariu pozitiv:"<<endl;
                        cout<<"Alege indexul"<<endl;
                        int rasp2;
                        cin>>rasp2;
                        cin.ignore();
                        if(rasp2==1)
                        {
                            cout<<"Scrie comentariul "<<endl;
                            string comentariu;
                            getline(cin,comentariu);
                            NegativeComment negativecomment(comentariu);
                            commentSystem.addNegativeComment(negativecomment);

                        }else{
                            cout<<"Scrie comentariul "<<endl;
                            string comentariu;
                            getline(cin,comentariu);
                            PositiveComment positivecomment (comentariu);
                            commentSystem.addPositiveComment(positivecomment);
                        }
                        cout<<"Ati scris comentariul"<<endl;
                    }else{
                        cout<<"Acestea sunt comentariile"<<endl;
                        commentSystem.displayAllComments();
                    }
                    break;
                case 9:
                    cout << "Va multumim, o zi frumoasa!" << endl;
                    break;
                default:
                    throw *(new exceptie);
            }
        }
        catch (const exceptie& e){
            cout<<e.what()<<endl;
        }

    } while (choice != 9);

    return 0;
}
