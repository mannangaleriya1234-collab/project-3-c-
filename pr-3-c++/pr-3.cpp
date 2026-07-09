#include<iostream>
#include<string>
using namespace std;

//================ BASE CLASS ===================
class Vehicle
{
private:
    int vehicleID;
    string manufacturer;
    string model;
    int year;

public:
    static int totalVehicles;

    Vehicle()
    {
        vehicleID = 0;
        manufacturer = "";
        model = "";
        year = 0;
    }

    Vehicle(int id, string man, string mod, int y)
    {
        vehicleID = id;
        manufacturer = man;
        model = mod;
        year = y;
        totalVehicles++;
    }

    ~Vehicle()
    {
    }

    void setData(int id, string man, string mod, int y)
    {
        vehicleID = id;
        manufacturer = man;
        model = mod;
        year = y;
    }

    int getID()
    {
        return vehicleID;
    }

    string getManufacturer()
    {
        return manufacturer;
    }

    string getModel()
    {
        return model;
    }

    int getYear()
    {
        return year;
    }

    void display()
    {
        cout<<"Vehicle ID : "<<vehicleID<<endl;
        cout<<"Manufacturer : "<<manufacturer<<endl;
        cout<<"Model : "<<model<<endl;
        cout<<"Year : "<<year<<endl;
    }
};

int Vehicle::totalVehicles = 0;

//================ SINGLE INHERITANCE ===================
class Car : public Vehicle
{
protected:
    string fuelType;

public:
    void setCar(string fuel)
    {
        fuelType = fuel;
    }

    void displayCar()
    {
        display();
        cout<<"Fuel Type : "<<fuelType<<endl;
    }
};

//================ MULTILEVEL ===================
class ElectricCar : public Car
{
protected:
    int batteryCapacity;

public:
    void setElectric(int battery)
    {
        batteryCapacity = battery;
    }

    void displayElectric()
    {
        displayCar();
        cout<<"Battery Capacity : "<<batteryCapacity<<" kWh"<<endl;
    }
};

//================ MULTILEVEL ===================
class SportsCar : public ElectricCar
{
private:
    int topSpeed;

public:
    void setSports(int speed)
    {
        topSpeed = speed;
    }

    void displaySports()
    {
        displayElectric();
        cout<<"Top Speed : "<<topSpeed<<" km/h"<<endl;
    }
};

//================ SECOND BASE CLASS ===================
class Aircraft
{
protected:
    int flightRange;

public:
    void setAircraft(int range)
    {
        flightRange = range;
    }

    void displayAircraft()
    {
        cout<<"Flight Range : "<<flightRange<<" km"<<endl;
    }
};

//================ MULTIPLE INHERITANCE ===================
class FlyingCar : public Car, public Aircraft
{
public:
    void displayFlying()
    {
        displayCar();
        displayAircraft();
    }
};

//================ HIERARCHICAL ===================
class Sedan : public Car
{
public:
    void showSedan()
    {
        cout<<"\nSedan Details\n";
        displayCar();
    }
};

class SUV : public Car
{
public:
    void showSUV()
    {
        cout<<"\nSUV Details\n";
        displayCar();
    }
};

//================ VEHICLE REGISTRY ===================
class VehicleRegistry
{
private:
    Vehicle vehicles[50];
    int count;

public:
    VehicleRegistry()
    {
        count = 0;
    }

    void addVehicle()
    {
        int id, year;
        string man, model;

        cout<<"Enter Vehicle ID : ";
        cin>>id;

        cout<<"Enter Manufacturer : ";
        cin>>man;

        cout<<"Enter Model : ";
        cin>>model;

        cout<<"Enter Year : ";
        cin>>year;

        vehicles[count].setData(id, man, model, year);

        count++;

        Vehicle::totalVehicles++;

        cout<<"\nVehicle Added Successfully\n";
    }

    void displayVehicles()
    {
        if(count==0)
        {
            cout<<"No Vehicles Found\n";
            return;
        }

        for(int i=0;i<count;i++)
        {
            cout<<"\nVehicle "<<i+1<<endl;
            vehicles[i].display();
        }

        cout<<"\nTotal Vehicles : "<<Vehicle::totalVehicles<<endl;
    }

    void searchVehicle()
    {
        int id;
        cout<<"Enter Vehicle ID : ";
        cin>>id;

        for(int i=0;i<count;i++)
        {
            if(vehicles[i].getID()==id)
            {
                cout<<"\nVehicle Found\n";
                vehicles[i].display();
                return;
            }
        }

        cout<<"Vehicle Not Found\n";
    }
};

//================ MAIN ===================
int main()
{
    VehicleRegistry vr;

    int choice;

    do
    {
        cout<<"\n====== VEHICLE REGISTRY SYSTEM ======\n";
        cout<<"1. Add Vehicle\n";
        cout<<"2. View All Vehicles\n";
        cout<<"3. Search Vehicle By ID\n";
        cout<<"4. Demonstrate Inheritance\n";
        cout<<"5. Exit\n";
        cout<<"Enter Choice : ";
        cin>>choice;

        switch(choice)
        {
        case 1:
            vr.addVehicle();
            break;

        case 2:
            vr.displayVehicles();
            break;

        case 3:
            vr.searchVehicle();
            break;

        case 4:
        {
            SportsCar s;
            s.setData(101,"Tesla","Roadster",2025);
            s.setCar("Electric");
            s.setElectric(100);
            s.setSports(350);

            cout<<"\nSports Car\n";
            s.displaySports();

            FlyingCar f;
            f.setData(201,"SkyDrive","X1",2026);
            f.setCar("Hybrid");
            f.setAircraft(500);

            cout<<"\nFlying Car\n";
            f.displayFlying();

            Sedan sd;
            sd.setData(301,"Honda","City",2024);
            sd.setCar("Petrol");
            sd.showSedan();

            SUV su;
            su.setData(401,"Toyota","Fortuner",2024);
            su.setCar("Diesel");
            su.showSUV();

            break;
        }

        case 5:
            cout<<"Thank You\n";
            break;

        default:
            cout<<"Invalid Choice\n";
        }

    }while(choice!=5);

    return 0;
}