/*******************************************************************************
 * 
 * ------------------ AIRLINE MANAGEMENT SYSEM ------------------------
 * 
 *******************************************************************************/


// ====================== HEADER FILES =====================

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

// ================= FUNCTION DECLARATIONS =================
void color(int);


// ================= VALIDATION FUNCTIONS =====================


int safeInt();
bool validUsername(string);
bool validPassword(string);
bool validGmail(string);
bool validCNIC(string);
bool usernameExists(string);
void signup();
bool login(string &);


// =================== MAIN MENU ===================

void mainMenu();



// ========================== ADMIN FUNCTIONS ====================


void adminMenu();
void userMenu(string);

void viewFlights();
void searchFlights();
void addFlight();
void deleteFlight();
void updateFlight();
void addExpense();
void calculateProfit();


// ======================== USER UNCTIONS ============================


void bookTicket(string);
void cancelTicket(string);
void bookingHistory(string);


// ================= MAIN FUNCTION =================

int main() 
{
        color(14);
    cout << "  __________________________________________________________________________\n";
    cout << " |         AAAAA              M                  M       SSSSSSSSSSSS       |\n"; 
    cout << " |        AA    AA            MM                MM     SS                   |\n" ;
    cout << " |       AA      AA           MMM              MMM    SS                    |\n";
    cout << " |      AA        AA          MM MM          MM MM     SS                   |\n";
    cout << " |     AA          AA         MM   MM      MM   MM       SSSSSSSSSSSS       |\n";
    cout << " |    AAAAAAAAAAAAAAAA        MM     MM  MM     MM                   SS     |\n";
    cout << " |   AA              AA       MM       MM       MM                    SS    |\n";
    cout << " |  AA                AA      MM                MM                   SS     |\n";
    cout << " | AA                  AA     MM                MM      SSSSSSSSSSSSS       |\n";
    cout << " |__________________________________________________________________________|\n\n\n";

    color(6);

        cout << " \t\t ------------- WELCOME ----------------\n\n";
    color(7);
        mainMenu();
    return 0;
}

// ================= MAIN MENU =================
    
void mainMenu() 
    {
        int choice;
        string user;
        do {
            color(11);
            cout << " ____________________________________________________________________________" << endl;
            cout << "|                                                                            |" << endl;
            cout << "|                      --- AIRLINE MANAGEMENT SYSTEM ---                     |" << endl;
            cout << "|____________________________________________________________________________|" << endl;
            
            color(13);
            
            cout << " ____________________________________________________________________________  \n";
            cout << "|                                                                            | \n";
            cout << "|                            1. Admin Login                                  | \n";
            cout << "|                            2. User Signup                                  | \n";
            cout << "|                            3. User Login                                   | \n";
            cout << "|                            0. Exit                                         | \n";
            cout << "|____________________________________________________________________________| \n";
          
            color(7);
            cout << "Choice: ";
            choice = safeInt();
            color(6);
            if(choice == 1) 
            {
            string u, p;
                cout << "Admin Username: "; 
                cin >> u;
                cout << "Admin Password: "; 
                cin >> p;
                if(u == "admin" && p == "Admin@123") 
                {
                        adminMenu();
                    
                    } 
                   
                else 
                {
                    color(12); 
                    cout << "Invalid admin credentials!\n"; 
                    color(7);
                }
            }
            else if(choice == 2) 
                
                    signup();
                
            else if(choice == 3) 
            {
                if(login(user))
                
                    userMenu(user);
                   
                else 
                    { 
                        color(12); 
                        cout << "Login failed!\n"; 
                        color(7); 
                    }
            }

        } while(choice != 0);
            color(10); 
            cout << "\nThank you for using Airline Management System!\n"; 
            color(7);
        
        }

// ================= ADMIN MENU =================
    void adminMenu() 
    {
        int c;
        do {
            color(11);  

            
            cout << " ____________________________________________________________________________" << endl;
            cout << "|                                                                            |" << endl;
            cout << "|                            --- ADMIN MENU ---                              |" << endl;
            cout << "|____________________________________________________________________________|" << endl;
            
            color(13);
            
            cout << " ____________________________________________________________________________  \n";
            cout << "|                                                                            | \n";
            cout << "|                            1. View Flights                                 | \n";
            cout << "|                            2. Add Flight                                   | \n";
            cout << "|                            3. Delete Flights                               | \n";
            cout << "|                            4. Update Flights                               | \n";
            cout << "|                            5. Search Flights                               | \n";
            cout << "|                            6. Add Expense                                  | \n";
            cout << "|                            7. Calculate Profit/Loss                        | \n";
            cout << "|                            0. Logout                                       | \n";
            cout << "|____________________________________________________________________________|" << endl;
            
            color(7);
            cout << "Choice: ";
            c = safeInt();

            if(c == 1) 
                viewFlights();
            else if(c == 2) 
                addFlight();
            else if(c == 3) 
                deleteFlight();
            else if(c == 4) 
                updateFlight();
            else if(c == 5) 
                searchFlights();
            else if(c == 6) 
                addExpense();
            else if(c == 7)     
                calculateProfit();

        } while(c != 0);
    }

// ================= USER MENU =================

void userMenu(string user) 
    {
        int c;
        do {
            color(11); 

            cout << " ____________________________________________________________________________" << endl;
            cout << "|                                                                            |" << endl;
            cout << "|                             --- USER MENU ---                              |" << endl;
            cout << "|____________________________________________________________________________|" << endl;
                                                                                                  
            color(13);                                                                             
                                                                                                  
            cout << " ____________________________________________________________________________  \n";
            cout << "|                                                                            | \n";
            cout << "|                            1. View Flights                                 | \n";
            cout << "|                            2. Book Ticket                                  | \n";
            cout << "|                            3. Cancel Tickets                               | \n";
            cout << "|                            4. Booking History                              | \n";
            cout << "|                            5. Search Flights                               | \n";
            cout << "|                            0. Logout                                       | \n";
            cout << "|____________________________________________________________________________|" << endl;
            
            color(7);

            cout << "Choice: ";
            c = safeInt();

            if(c == 1) 
                viewFlights();
            
            else if(c == 2) 
                bookTicket(user);
        
            else if(c == 3) 
                cancelTicket(user);
    
            else if(c == 4) 
                bookingHistory(user);
             
            else if(c == 5) 
                searchFlights();

            } while(c != 0);
    }

// ================= VALIDATIONS =================


void color(int c) 
    { 
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c); 
    }

int safeInt() 
    {
        int x;
        while(!(cin >> x)) 
        { 
            cin.clear(); 
            cin.ignore(1000, '\n'); 
            color(12);
            cout << "Invalid input! Enter number: "; 
            color(7); 
        }
        cin.ignore(); 
        return x;
    }

// --------------- USER NAME ---------------------
bool validUsername(string u) 
    {
        if(u.length()<3 || isdigit(u[0])) 
        return false;
    
         for(char c:u) 
        if(!isalnum(c)) 
        return false;
    
        return true;
    }


// --------------- PASSWORD ------------------    
bool validPassword(string p) 
    {
        if(p.length()!=8) 
            return false;
            bool special=false;
            for(char c:p)
            { 
                if(isspace(c)) 
                return false; 
                
                if(!isalnum(c)) 
                special=true; 
            }
        return special;
    }

// ------------------- GMAIL --------------------


bool validGmail(string g)

    { 
        return g.find("@gmail.com")!=string::npos; 
    }

bool validCNIC(string c)
    
    {
        if(c.length()!=13) 
        return false;
        
        for(char x:c) 
        if(!isdigit(x)) 
        return false;
        
        return true;
    }

bool usernameExists(string u)
    {
        ifstream file("users.txt");
        string user, pass, mail, cnic;
        while(file>>user>>pass>>mail>>cnic) 
        if(user==u) 
        return true;
            
        return false;
    }

void signup() 
    {
        string user, pass, mail, cnic;
        color(11); 
            cout << "\n--- USER SIGNUP ---\n"; 
            color(6);
        
            do { 
                cout << "Username: "; 
                cin >> user; 
            } while(!validUsername(user)||usernameExists(user));
            
            do {
                cout << "Password (8 chars,1 special): ";
                cin >> pass; 
                } while(!validPassword(pass));
            
                do { 
                    cout << "Gmail: ";
                    cin >> mail; 
                    } while(!validGmail(mail));
    
                do { 
                    cout << "CNIC (13 digits): ";
                    cin >> cnic;
                } while(!validCNIC(cnic));
   
        ofstream file("users.txt", ios::app);
        file<<user<<" "<<pass<<" "<<mail<<" "<<cnic<<endl;
        file.close();
        color(10); 
        cout << "Signup successful!\n";
        color(7);
    }

bool login(string &u)
    {
        color(6);
        string user, pass, fu, fp, fm, fc;
        cout << "Username: "; 
        cin >> user; 
        cout << "Password: "; 
        cin >> pass;
        
        color(6);

        ifstream file("users.txt");
        
        while(file>>fu>>fp>>fm>>fc)     
        
        if(fu==user && fp==pass)
        
        {
             u=user; 
             return true; 
        }
        return false;
    }

// ================= FLIGHTS =================

void viewFlights()
    {

ifstream file("flights.txt");
if (!file.is_open()) {
    color(12);
    cout << "Error: flights.txt not found!\n";
    color(7);
    return;
}

// Debug: check file content
string line;
cout << "\n--- flights.txt content ---\n";
while(getline(file, line)) cout << line << endl;
file.clear();
file.seekg(0);


string id, from, to, status;
int ecoSeats, busSeats;
    double ecoPrice, busPrice;

    color(14); // Yellow
    cout << "\nID   From   To   EcoS  EcoP   BusS  BusP   Status\n";
    color(7);

        bool found = false;

        while (file >> id >> from >> to >> ecoSeats >> ecoPrice >> busSeats >> busPrice >> status) 
        {
        found = true;

        if (status == "active")
            color(10);   
        else
            color(8);    

        cout << id << "  " << from << "  "<< to << "  " << ecoSeats << "  " << ecoPrice << "  "<< busSeats << "  "<< busPrice << "  "<< status << endl;

            color(7);
        }

        if (!found) 
        {
        color(12);
        cout << "No flights available.\n";
            color(7);
        }

        file.close();

    }


// ------------ SEARCH FLIGHTS ------------------


void searchFlights()
    {
        string sFrom,sTo,id,from,to,status;
        double ecoPrice,busPrice;
        int ecoSeats,busSeats;
        color(6);

        cout<<"Enter From city: "; 
        cin>>sFrom; 
        cout<<"Enter To city: ";
        cin>>sTo;
        
        ifstream file("flights.txt"); 
        
        bool found=false;
        
        color(11); 
        cout<<"\nID  From  To  Seats  Price\n"; 
        color(7);
 
        while(file >> id >> from >> to >> ecoSeats >> ecoPrice >> busSeats >> busPrice >> status)
        {
        if(from == sFrom && to == sTo)
        {
            cout << id << "  " << from << "  " << to << "  " << ecoSeats << "/" << busSeats << "  "  << ecoPrice << "/" << busPrice << "  " << status << endl;
            found = true;
        }
        }
        if(!found)
        { 
            color(12); 
            cout<<"No flights found!\n"; 
            color(7); 
        }
    }


// ----------------- ADD FLIGHT ----------------------

void addFlight()
    {
        string id, from, to, status;
        int ecoSeats, busSeats;
        double ecoPrice, busPrice;

        color(6);

        cout << "Enter Flight ID: ";
        cin >> id;
        cout << "From: ";
        cin>> from;
        cout << "To: ";
        cin>> to;

        cout << "Economy Seats: ";
        ecoSeats = safeInt();
        cout << "Economy Price: ";
        cin >> ecoPrice;

        cout << "Business Seats: ";
        busSeats = safeInt();
        cout << "Business Price: ";
        cin >> busPrice;

        cout << "Status (active/inactive): ";
        cin >> status;

        ofstream file("flights.txt", ios::app);

        file << id << " " << from << " " << to << " " << ecoSeats << " " << ecoPrice << " " << busSeats << " " << busPrice << " " << status << endl;
        
         file.close();

        color(10);
        cout << "Flight added successfully!\n";
        color(7);

    }

// --------------- DELETE FLIGHT -----------------

void deleteFlight()
    {
        string id,fid,from,to ,status; 
        int ecoSeats,busSeats;
        double ecoPrice ,busPrice; 
        bool found=false;
        
        color(6);

        cout<<"Enter Flight ID to delete: "; 
        cin>>id;

        ifstream in("flights.txt"); 
        ofstream out("temp.txt");
        while(in >> fid >> from >> to >> ecoSeats >> ecoPrice >> busSeats >> busPrice >> status)
    {
        if(fid != id) 
            out << fid << " " << from << " " << to << " " << ecoSeats << " " << ecoPrice << " " << busSeats << " " << busPrice << " " << status << endl;
            else 
            found = true;
        }
        in.close(); 
        out.close(); 
        
        remove("flights.txt"); 
        rename("temp.txt","flights.txt");
    
        color(found?10:12); 
        cout<<(found?"Flight deleted successfully!\n":"Flight not found!\n"); 
        color(7);
    
    }


// ------------------ UPDATE FLIGHT ----------------------


void updateFlight()
    {
        
        string id,fid,from,to ,status; 
        double ecoPrice ,busPrice; 
        int ecoSeats,busSeats;
        bool found=false;
        color(6);
        cout<<"Enter Flight ID to update: "; 
        cin>>fid;
        
        ifstream in("flights.txt"); 
        ofstream out("temp.txt");
        while(in >> id >> from >> to >> ecoSeats >> ecoPrice >> busSeats >> busPrice >> status)
{
    if(id == fid)
    {
        found = true;
        cout << "From: "; cin >> from;
        cout << "To: "; 
        cin >> to;
        cout << "Economy Seats: "; 
        ecoSeats = safeInt();
        cout << "Economy Price: "; 
        cin >> ecoPrice;
        cout << "Business Seats: "; 
        busSeats = safeInt();
        cout << "Business Price: "; 
        cin >> busPrice;
        cout << "Status (active/inactive): "; 
        cin >> status;
        }

        out << id << " " << from << " " << to << " " << ecoSeats << " " << ecoPrice << " " << busSeats << " " << busPrice << " " << status << endl;
        }       
        in.close(); 
        out.close(); 
        
        remove("flights.txt"); 
        rename("temp.txt","flights.txt");
        
        color(found?10:12); 
        cout<<(found?"Flight updated successfully!\n":"Flight ID not found!\n"); 
        
        color(7);
    
    }

// ================= BOOKING =================


void bookTicket(string user) 
        {
        string fid, type;
        string id, from, to, status;
        int ecoSeats, busSeats, qty;
        double ecoPrice, busPrice;
        bool booked = false;

        viewFlights();

        color(6);
        
        cout << "\nEnter Flight ID: ";
        cin >> fid;

        cout << "Ticket Type (economy/business): ";
        cin >> type;

        cout << "Number of seats: ";
        qty = safeInt();
        color(7);
        ifstream in("flights.txt");
        ofstream out("temp.txt");
        ofstream book("bookings.txt", ios::app);

        while (in >> id >> from >> to >> ecoSeats >> ecoPrice >> busSeats >> busPrice >> status) 
              
        {

        

        if (id == fid && !booked) 
            {
                 if (status != "active") 
                {
                    color(12);
                    cout << "This flight is inactive and cannot be booked!\n";
                    color(7);
                }
            else if (type == "economy") 
            {
                    
                if (ecoSeats >= qty) 
                    {
                        ecoSeats -= qty;
                        book << user << " " << id << " economy " << qty << " " << ecoPrice * qty << endl;
                        booked = true;
                    } 
                else 
                    {
                        color(12);
                        cout << "Not enough economy seats!\n";
                        color(7);
                    }
                }
                else if (type == "business") 
                {
                    if (busSeats >= qty) 
                    {
                        busSeats -= qty;
                        book << user << " " << id << " business " << qty << " " << busPrice * qty << endl;
                        booked = true;
                    } 
                else 
                    {
                        color(12);
                        cout << "Not enough business seats!\n";
                        color(7);
                    }
                }
                else    
                {
                    color(12);
                    cout << "Invalid ticket type!\n";
                    color(7);
                }
            }

        
        out << id << " " << from << " " << to << " " << ecoSeats << " " << ecoPrice << " " << busSeats << " " << busPrice << " " << status << endl;
        }

        in.close();
        out.close();
        book.close();

        remove("flights.txt");
        rename("temp.txt", "flights.txt");

        if (booked) 
        {
            color(10);
            cout << "Ticket booked successfully!\n";
            color(7);
        }
        if (booked) 
{
    color(10);
    cout << "\n--- Booking Receipt ---\n";
    cout << "User: " << user << endl;
    cout << "Flight ID: " << fid << endl;
    cout << "From: " << from << endl;
    cout << "To: " << to << endl;
    cout << "Ticket Type: " << type << endl;
    cout << "Seats Booked: " << qty << endl;
    double total = (type == "economy") ? qty * ecoPrice : qty * busPrice;
    cout << "Total Price: " << total << endl;
    cout << "Status: Confirmed\n";
    color(7);
}

    }

    
void cancelTicket(string user)
    {
        ifstream inBookings("bookings.txt"); 
        ofstream outBookings("temp.txt");
    
        string u, fid, type;
        int qty;
        double price;
        bool found = false;

        while (inBookings >> u >> fid >> type >> qty >> price)
        {
            if (u == user && !found)
            {
                found = true;

                string id, from, to, status;
                int ecoSeats, busSeats;
                double ecoPrice, busPrice;

                ifstream inFlights("flights.txt");
                ofstream outFlights("tempFlights.txt");

                while (inFlights >> id >> from >> to >> ecoSeats >> ecoPrice >> busSeats >> busPrice >> status)
                 {
                    if (id == fid)
                    {
                        if (type == "economy")
                            ecoSeats += qty;
                        else if (type == "business")
                            busSeats += qty;
                    }
                    outFlights << id << " " << from << " " << to << " " << ecoSeats << " " << ecoPrice 
                           << " " << busSeats << " " << busPrice << " " << status << endl;
                }
                inFlights.close();
                outFlights.close();
            
                remove("flights.txt");
                rename("tempFlights.txt", "flights.txt");

            continue; 
            }

            outBookings << u << " " << fid << " " << type << " " << qty << " " << price << endl;
        }

        inBookings.close();
        outBookings.close();
        
        remove("bookings.txt");
        rename("temp.txt", "bookings.txt");

        color(found ? 10 : 12);
        cout << (found ? "Ticket cancelled and seats restored!\n" : "No booking found!\n");
        color(7);
    }


void bookingHistory(string user)
    {
        ifstream in("bookings.txt"); 
        string u,type,
        fid; 
        int qty; 
        double price;
        bool found=false;
        
        color(11); 
        cout<<"\n--- Booking History ---\n"; 
        color(7);
        
        while(in>>u>>fid>>type>>qty>>price)
            
            {    
            if(u==user)
            { 
                cout<<"Flight: "<<fid<<" Type:"<<type<<"  Seats: "<<qty<<"  Total: "<<price<<endl; 
                found=true; 
            } 
            }
        if(!found)
        { 
            color(12); 
            cout<<"No bookings found!\n"; 
            color(7); 
        }
    }

// ================= FINANCE =================

//----------------- ADD EXPENSES -------------

void addExpense()
    
    {
    double e; 
    cout<<"Enter expense amount: "; 
    cin>>e;
    
    ofstream file("expenses.txt", ios::app); 
        
        file<<e<<endl; 
        file.close();
    
        color(10); 
        cout<<"Expense added!\n"; 
        color(7);
    }


// --------------- CALCULATE PROFIT -----------------


void calculateProfit()
    {
    double income=0, expense=0, x; 
    string u,fid; 
    int qty;
        ifstream i("bookings.txt"); 
            
        while(i>>u>>fid>>qty>>x) income+=x; 
        i.close();
    
        ifstream e("expenses.txt"); 
    
        while(e>>x) expense+=x; 
        e.close();
        color(11); 
    
        cout<<"\nIncome: "<<income<<"\nExpense: "<<expense<<"\nProfit/Loss: "<<income-expense<<endl; 
    
        color(7);
    }
