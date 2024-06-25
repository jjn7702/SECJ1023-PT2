/*
!Group 10 Section 8
Group Member:
Chu Cheng Qing
Teow Zi Xian
Tan Zhen Li
Muhammad Fathurrahman Bin Ayub
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

class Supplier
{
    string name;
    string contact;

public:
    Supplier(string n = "", string c = "") : name(n), contact(c) {}
    string getName() const { return name; }
    string getContact() const { return contact; }
};

class Item
{
protected:
    string id;
    string name;
    int quantity;
    double price;
    Supplier sup;

public:
    Item(string i = "", string n = "", int q = 0, double p = 0, Supplier S = Supplier()) : id(i), name(n), quantity(q), price(p), sup(S) {}
    string getID() const { return id; }
    string getName() const { return name; }
    int getQuantity() const { return quantity; }
    double getPrice() const { return price; }
    Supplier getSupplier() const { return sup; }
    virtual string getDetails() const = 0; // Pure virtual function to get item-specific details
    virtual void LoadFile() const = 0; // Pure virtual Function to output file
    void setQuantity(int q) { quantity = q; }
};
class Expired
{
string expired;

public:
Expired(string ex="")
{
    expired = ex;
}
void setExpired(string ex){
    expired = ex;
}
string getExpired() const
{
    return expired;
}
};
class Food : public Item
{
    Expired expired;

public:
    Food(string ID, string N, int Q, double P, string exp, Supplier S = Supplier()) : Item(ID, N, Q, P, S) {expired.setExpired(exp);}
    string getExpired() const { return expired.getExpired(); }
    string getDetails() const override
    {
        return "Expiration Date: " + expired.getExpired();
    }
    void LoadFile() const override
    {
    ofstream outF("Foods.txt",ios::app);
    if (!outF)
    {cout<<"File not exist !";
    }
    outF<<id<<','<<name<<','<<quantity<<','<<price<<','<<expired.getExpired()<<','<<sup.getName()<<endl;
    outF.close();
    }
};
class Toy : public Item
{
    Expired expired;
    string material;

public:
    Toy(string ID, string N, int Q, double P, string exp, string mat, Supplier S = Supplier()) : Item(ID, N, Q, P, S), expired(exp), material(mat) {}
    string getExpired() const { return expired.getExpired(); }
    string getMaterial() const { return material; }
    string getDetails() const override
    {
        return "Expiration Date: " + expired.getExpired() + ", Material: " + material;
    }
    void LoadFile() const override
    {
    ofstream outT("Toys.txt",ios::app);
    if (!outT)
    {cout<<"File not exist !";
    }
    outT<<id<<','<<name<<','<<quantity<<','<<price<<','<<expired.getExpired()<<','<<material<<','<<sup.getName()<<endl;
    outT.close();
    }
};

class Medicine : public Item
{
    Expired expired;
    int dosePD;

public:
    Medicine(string ID, string N, int Q, double P, string exp, int Dose, Supplier S = Supplier()) : Item(ID, N, Q, P, S), expired(exp), dosePD(Dose) {}
    string getExpired() const { return expired.getExpired(); }
    int getDosePD() const { return dosePD; }
    string getDetails() const override
    {
        return "Expiration Date: " + expired.getExpired() + ", Dose Per Day: " + to_string(dosePD);
    }
    void LoadFile() const override
    {
    ofstream outM("Medicines.txt",ios::app);
    if (!outM)
    {cout<<"File not exist !";
    }
    outM<<id<<','<<name<<','<<quantity<<','<<price<<','<<expired.getExpired()<<','<<dosePD<<','<<sup.getName()<<endl;;
    outM.close();
    }

};

class Other : public Item
{
    Expired expired;
    string description;

public:
    Other(string ID, string N, int Q, double P, string exp, string des, Supplier S = Supplier()) : Item(ID, N, Q, P, S), expired(exp), description(des) {}
    string getExpired() const { return expired.getExpired(); }
    string getDescription() const { return description; }
    string getDetails()  const override
    {
        return "Expiration Date: " + expired.getExpired() + ", Description: " + description;
    }
    void LoadFile() const override
    {
    ofstream outO("Others.txt",ios::app);
    if (!outO)
    {cout<<"File not exist !";
    }
    outO<<id<<','<<name<<','<<quantity<<','<<price<<','<<expired.getExpired()<<','<<description<<','<<sup.getName()<<endl;;
    outO.close();
    }
};

class Sales
{
    Item *item;
    double totalPrice;

public:
    Sales(Item *x) : item(x), totalPrice(0) {}
    double T_Price(int q)
    {
        return item->getPrice() * q;
    }
};

class Inventory
{
    Item* item[400];
    int itemC;

public:
    Inventory() : itemC(0) {}

    void addFood(Food* newFood)
    {
        if (itemC < 100) {
            item[itemC++] = newFood;
        } else {
            cout << "Food inventory is full!" << endl;
        }
    }

    void addToy(Toy* newToy)
    {
        if (itemC < 100) {
            item[itemC++] = newToy;
        } else {
            cout << "Toy inventory is full!" << endl;
        }
    }

    void addMedicine(Medicine* newMedicine)
    {
        if (itemC < 100) {
            item[itemC++] = newMedicine;
        } else {
            cout << "Medicine inventory is full!" << endl;
        }
    }

    void addOther(Other* newOther)
    {
        if (itemC < 100) {
            item[itemC++] = newOther;
        } else {
            cout << "Other inventory is full!" << endl;
        }
    }

    void viewItems()
    {
        cout<<"\n----------------------------------------------------------\n";
        cout<<"                      Item List                           \n";
        cout<<"----------------------------------------------------------\n";
        for (int i = 0; i < itemC; i++)
        {
            cout << "ID: " << item[i]->getID() << ", Name: " << item[i]->getName() << ", Quantity: " << item[i]->getQuantity() << ", Price: RM" << item[i]->getPrice() << endl;
            cout << item[i]->getDetails() << endl;
            cout << "Supplier: " << item[i]->getSupplier().getName() << ", Contact: " << item[i]->getSupplier().getContact() << endl;
            cout << "----------------------------------------------------------" << endl;
        }
    }

    Item* findItemByID(string id)
    {
        for (int i = 0; i < itemC; i++)
        {
            if (item[i]->getID() == id)
            {
                return item[i];
            }
        }
        return nullptr;
    }

    void loadtofile()
    {
        ofstream F("Foods.txt",ios::trunc);
        ofstream T("Toys.txt",ios::trunc);
        ofstream M("Medicines.txt",ios::trunc);
        ofstream O("Others.txt",ios::trunc);//Purpose of here is to clear the file first before appending to the file
        for(int i=0; i<itemC; i++)
        item[i]->LoadFile();
    }
    
};

class SupplierManager
{
    Supplier* suppliers[100];
    int supplierCount;

public:
    SupplierManager() : supplierCount(0) {}

    void addSupplier(string name, string contact)
    {
        if (supplierCount < 100) {
            suppliers[supplierCount++] = new Supplier(name, contact);
        } else {
            cout << "Supplier list is full!" << endl;
        }
    }

    Supplier* findSupplierByName(string name)
    {
        for (int i = 0; i < supplierCount; i++)
        {
            if (suppliers[i]->getName() == name)
            {
                return suppliers[i];
            }
        }
        return nullptr;
    }

    void viewSuppliers()
    {
        cout<<endl;
        cout<<setw(11)<<""<<"Supplier List"<<setw(11)<<""<<endl;
        for(int i=0; i<35; i++)
        cout<<'-';
        cout<<endl;
        cout<<setw(10)<<left<<"Name"<<setw(20)<<left<<"Contact"<<endl;
        for(int i=0; i<35; i++)
        cout<<'-';
        cout<<endl;
        for (int i = 0; i < supplierCount; i++)
        {
            cout << setw(10)<<left << suppliers[i]->getName() << setw(20)<<left << suppliers[i]->getContact() << endl;
        }
        cout<<endl;
    }
    void loadtofile()
    {
    ofstream out("suppliers.txt");
    if (!out)
    {cout<<"File not exist !";
    }
    for(int i=0; i < supplierCount; i++)
    out<<suppliers[i]->getName()<<','<<suppliers[i]->getContact()<<endl;

    out.close();
    }
    void addFromFile()
    {
        ifstream inSup("suppliers.txt");
        if (!inSup)
        cout<<"File not existing !";

        string line;
        const int maxTOKEN = 10;
        string TOKEN[maxTOKEN];
        string Sname;
        string Scontact;
        while (getline(inSup,line))
        {
            stringstream ss(line);
            string item;
            int tokenCount = 0;

            while(getline(ss,item,',')&&tokenCount < maxTOKEN)
            TOKEN[tokenCount++] = item;

            for(int i=0; i<tokenCount ; i++)
            {
                if (i==0)
                Sname = TOKEN[i];
                else if (i==1)
                Scontact = TOKEN[i];

                
            }
            suppliers[supplierCount++] = new Supplier(Sname,Scontact);
        }
    }
};

void displayMenu()
{
    cout << "Pet Inventory System Menu" << endl;
    cout << "1. Add Supplier" << endl;
    cout << "2. Add Item" << endl;
    cout << "3. View Inventory" << endl;
    cout << "4. View Suppliers" << endl;
    cout << "5. Process Sale" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
}

Food* createFood(Supplier* supplier)
{
    string id, name, exp;
    int quantity;
    double price;

    cout << "Enter item ID: ";
    cin >> id;
    cout << "Enter item name: ";
    cin.ignore();
    getline(cin,name);
    cout << "Enter quantity: ";
    cin >> quantity;
    cout << "Enter price: ";
    cin >> price;
    cout << "Enter expiration date: ";
    cin >> exp;

    return new Food(id, name, quantity, price, exp, *supplier);
}

Toy* createToy(Supplier* supplier)
{
    string id, name, exp, mat;
    int quantity;
    double price;

    cout << "Enter item ID: ";
    cin >> id;
    cout << "Enter item name: ";
    cin.ignore();
    getline(cin,name);
    cout << "Enter quantity: ";
    cin >> quantity;
    cout << "Enter price: ";
    cin >> price;
    cout << "Enter expiration date: ";
    cin >> exp;
    cout << "Enter material: ";
    cin >> mat;

    return new Toy(id, name, quantity, price, exp, mat, *supplier);
}

Medicine* createMedicine(Supplier* supplier)
{
    string id, name, exp;
    int quantity, dose;
    double price;

    cout << "Enter item ID: ";
    cin >> id;
    cout << "Enter item name: ";
    cin.ignore();
    getline(cin,name);
    cout << "Enter quantity: ";
    cin >> quantity;
    cout << "Enter price: ";
    cin >> price;
    cout << "Enter expiration date: ";
    cin >> exp;
    cout << "Enter dose per day: ";
    cin >> dose;

    return new Medicine(id, name, quantity, price, exp, dose, *supplier);
}

Other* createOther(Supplier* supplier)
{
    string id, name, exp, desc;
    int quantity;
    double price;

    cout << "Enter item ID: ";
    cin >> id;
    cout << "Enter item name: ";
    cin.ignore();
    getline(cin,name);
    cout << "Enter quantity: ";
    cin >> quantity;
    cout << "Enter price: ";
    cin >> price;
    cout << "Enter expiration date: ";
    cin >> exp;
    cout << "Enter description: ";
    cin.ignore();
    getline(cin,desc);

    return new Other(id, name, quantity, price, exp, desc, *supplier);
}
void addFromFile(Inventory & inventory, SupplierManager supplierManager)
{
        ifstream inF("Foods.txt");
        if (!inF)
        cout<<"File not existing !";
        ifstream inT("Toys.txt");
        if (!inT)
        cout<<"File not existing !";
        ifstream inM("Medicines.txt");
        if (!inM)
        cout<<"File not existing !";
        ifstream inO("Others.txt");
        if (!inO)
        cout<<"File not existing !";

        string line;
        const int maxTOKEN = 10;
        string TOKEN[maxTOKEN];
        string ID,NAME,SUPPLIER,EXP,MAT,DES;
        int QUAN,PRICE,DOSE;
        //ADD TO FOOD
        while (getline(inF,line))
        {
            stringstream ss(line);
            string item;
            int tokenCount = 0;

            while(getline(ss,item,',')&&tokenCount < maxTOKEN)
            TOKEN[tokenCount++] = item;

            for(int i=0; i<tokenCount ; i++)
            {
                switch (i)
                {
                    case 0:
                    ID = TOKEN[i];
                    break;
                    case 1:
                    NAME = TOKEN[i];
                    break;
                    case 2:
                    QUAN = stoi(TOKEN[i]);
                    break;
                    case 3:
                    PRICE = stoi(TOKEN[i]);
                    break;
                    case 4:
                    EXP = TOKEN[i];
                    break;
                    case 5:
                    SUPPLIER = TOKEN[i];
                    break;
                }
                
            }
            Supplier* supplier = supplierManager.findSupplierByName(SUPPLIER);
            Food* newItem = new Food(ID, NAME, QUAN, PRICE, EXP, *supplier);
            inventory.addFood(newItem);
        }
        //ADD TO TOY
        while (getline(inT,line))
        {
            stringstream ss(line);
            string item;
            int tokenCount = 0;

            while(getline(ss,item,',')&&tokenCount < maxTOKEN)
            TOKEN[tokenCount++] = item;

            for(int i=0; i<tokenCount ; i++)
            {
                switch (i)
                {
                    case 0:
                    ID = TOKEN[i];
                    break;
                    case 1:
                    NAME = TOKEN[i];
                    break;
                    case 2:
                    QUAN = stoi(TOKEN[i]);
                    break;
                    case 3:
                    PRICE = stoi(TOKEN[i]);
                    break;
                    case 4:
                    EXP = TOKEN[i];
                    break;
                    case 5:
                    MAT = TOKEN[i];
                    break;
                    case 6:
                    SUPPLIER = TOKEN[i];
                    break;
                }
                
            }
            Supplier* supplier = supplierManager.findSupplierByName(SUPPLIER);
            Toy* newItem = new Toy(ID, NAME, QUAN, PRICE, EXP, MAT, *supplier);
            inventory.addToy(newItem);
        }
        //ADD TO MED
        while (getline(inM,line))
        {
            stringstream ss(line);
            string item;
            int tokenCount = 0;

            while(getline(ss,item,',')&&tokenCount < maxTOKEN)
            TOKEN[tokenCount++] = item;

            for(int i=0; i<tokenCount ; i++)
            {
                switch (i)
                {
                    case 0:
                    ID = TOKEN[i];
                    break;
                    case 1:
                    NAME = TOKEN[i];
                    break;
                    case 2:
                    QUAN = stoi(TOKEN[i]);
                    break;
                    case 3:
                    PRICE = stoi(TOKEN[i]);
                    break;
                    case 4:
                    EXP = TOKEN[i];
                    break;
                    case 5:
                    DOSE = stoi(TOKEN[i]);
                    break;
                    case 6:
                    SUPPLIER = TOKEN[i];
                    break;
                }
                
            }
            Supplier* supplier = supplierManager.findSupplierByName(SUPPLIER);
            Medicine* newItem = new Medicine(ID, NAME, QUAN, PRICE, EXP, DOSE, *supplier);
            inventory.addMedicine(newItem);
        }
        //ADD TO OTHERS
        while (getline(inO,line))
        {
            stringstream ss(line);
            string item;
            int tokenCount = 0;

            while(getline(ss,item,',')&&tokenCount < maxTOKEN)
            TOKEN[tokenCount++] = item;

            for(int i=0; i<tokenCount ; i++)
            {
                switch (i)
                {
                    case 0:
                    ID = TOKEN[i];
                    break;
                    case 1:
                    NAME = TOKEN[i];
                    break;
                    case 2:
                    QUAN = stoi(TOKEN[i]);
                    break;
                    case 3:
                    PRICE = stoi(TOKEN[i]);
                    break;
                    case 4:
                    EXP = TOKEN[i];
                    break;
                    case 5:
                    DES = TOKEN[i];
                    break;
                    case 6:
                    SUPPLIER = TOKEN[i];
                    break;
                }
                
            }
            Supplier* supplier = supplierManager.findSupplierByName(SUPPLIER);
            Other* newItem = new Other(ID, NAME, QUAN, PRICE, EXP, DES, *supplier);
            inventory.addOther(newItem);
        }
        inF.close();
        inT.close();
        inM.close();
        inO.close();
}
int main()
{
    SupplierManager supplierManager;
    Inventory inventory;
    int choice;
    supplierManager.addFromFile();
    addFromFile(inventory, supplierManager);
    while (true)
    {
        displayMenu();
        cin >> choice;

        if (choice == 1)
        {
            string name, contact;
            cout << "Enter supplier name: ";
            cin >> name;
            cout << "Enter supplier contact: ";
            cin >> contact;

            supplierManager.addSupplier(name, contact);
            cout << "Supplier added successfully!" << endl;

        }
        else if (choice == 2)
        {
            int type;
            string supplierName;
            cout << "Select item type: 1. Food, 2. Toy, 3. Medicine, 4. Other: ";
            cin >> type;

            cout << "Enter supplier name: ";
            cin >> supplierName;

            Supplier* supplier = supplierManager.findSupplierByName(supplierName);
            if (!supplier)
            {
                cout << "Supplier not found. Please add the supplier first." << endl;
                continue;
            }

            if (type == 1)
            {
                Food* newItem = createFood(supplier);
                inventory.addFood(newItem);
                cout << "Food item added successfully!" << endl;
            }
            else if (type == 2)
            {
                Toy* newItem = createToy(supplier);
                inventory.addToy(newItem);
                cout << "Toy item added successfully!" << endl;
            }
            else if (type == 3)
            {
                Medicine* newItem = createMedicine(supplier);
                inventory.addMedicine(newItem);
                cout << "Medicine item added successfully!" << endl;
            }
            else if (type == 4)
            {
                Other* newItem = createOther(supplier);
                inventory.addOther(newItem);
                cout << "Other item added successfully!" << endl;
            }
        }
        else if (choice == 3)
        {
            inventory.viewItems();
        }
        else if (choice == 4)
        {
            supplierManager.viewSuppliers();
        }
        else if (choice == 5)
        {
            string itemID;
            int quantity;
            cout << endl;
            cout << "-----------------------------------\n";
            cout << "         Sales Process             \n";
            cout << "-----------------------------------\n";
            cout << "Enter item ID to purchase: ";
            cin >> itemID;
            cout << "Enter quantity: ";
            cin >> quantity;

            Item* item = inventory.findItemByID(itemID);
            if (item)
            {
                if (item->getQuantity() >= quantity)
                {
                    Sales sale(item);
                    double total = sale.T_Price(quantity);
                    item->setQuantity(item->getQuantity() - quantity);
                    cout << "Total price: RM" << total << endl;
                    cout << "Sale processed successfully!" << endl;
                }
                else
                {
                    cout << "Insufficient quantity in stock." << endl;
                }
            }
            else
            {
                cout << "Item not found." << endl;
            }
        }
        else if (choice == 6)
        {
            break;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }

        cout<<endl;
    }
    supplierManager.loadtofile();
    inventory.loadtofile();
    return 0;
}