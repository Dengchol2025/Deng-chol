class Student
{
public:
    string name;
    int age;
};




class Car
{
public:
    string brand;

    void display()
    {
        cout << "Car brand: " << brand << endl;
    }
};







Car car1;
car1.brand = "Toyota";
car1.display();






class Student
{
public:
    string name;
    int age;
};




class BankAccount
{
private:
    double balance;

public:
    void setBalance(double b)
    {
        balance = b;
    }

    double getBalance()
    {
        return balance;
    }
};





class Animal
{
public:
    void sound()
    {
        cout << "Animal makes a sound" << endl;
    }
};

class Dog : public Animal
{
public:
    void sound()
    {
        cout << "Dog barks" << endl;
    }
};







