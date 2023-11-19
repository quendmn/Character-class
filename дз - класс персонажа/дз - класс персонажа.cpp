#include <iostream>
#include <windows.h>
#include <vector>
#include <string>

class Objects {
public:
    Objects() = default;
    Objects(std::string name) :name_(name) {};
    std::string name_;
};

class Equipment
{
public:
    Equipment() = default;
    Equipment(std::string name) :name_(name) {}
    std::string name_;
};

class Boots : public Equipment
{
public:
    Boots() = default;
    Boots(std::string name) :Equipment(name) {}
    Boots(Boots& other) {
        this->name_ = other.name_;
    }
};

class Greaves : public Equipment
{
public:
    Greaves() = default;
    Greaves(std::string name) :Equipment(name) {}
};

class Breastplate : public Equipment
{
public:
    Breastplate() = default;
    Breastplate(std::string name) :Equipment(name) {}
};

class Helmet : public Equipment
{
public:
    Helmet() = default;
    Helmet(std::string name) :Equipment(name) {}
};




class Character
{
public:
    Character() = default;
    Character(int hp, int age, std::string name, std::string gender) :hp_(hp), age_(age), name_(name), gender_(gender) {}
    
    void Move()
    {
        std::cout << "stomp-stomp\n";
    }

    void AddInBackpack(Objects *obj)
    {
        backpack_.push_back(obj);
    }

    void OpenBackpack()
    {
        std::cout << "Backpack:\n";
        for (auto& el : backpack_)
        {
            std::cout << el->name_ << "\n";
        }
    }

    void PutOnHelmet(Helmet obj)
    {
        helmet_.name_ = obj.name_;
    }
    void PutOnBreastplate(Breastplate obj)
    {
        breastplate_.name_ = obj.name_;
    }
    void PutOnGreaves(Greaves obj)
    {
        greaves_.name_ = obj.name_;
    }
    void PutOnBoots(Boots obj)
    {
        boots_.name_ = obj.name_;
    }

    void CurrentEquipment()
    {
        std::cout << "Current Equipment:\n";
        std::cout << helmet_.name_ << "\n";
        std::cout << breastplate_.name_ << "\n";
        std::cout << greaves_.name_ << "\n";
        std::cout << boots_.name_ << "\n";
    }

private:

    int hp_;
    int age_;
    std::string name_;
    std::string gender_;

    std::vector <Objects*> backpack_; 

    Helmet helmet_;
    Breastplate breastplate_;
    Greaves greaves_;
    Boots boots_;
    

};

std::ostream& operator << (std::ostream& s, Objects obj) {
    s << obj.name_;
    return s;
}


int main()
{
    Character me;

    std::string h = "helmet";
    std::string b = "breastplate";
    std::string g = "greaves";
    std::string bt = "boots";
    std::string obj1 = "diamond";
    std::string obj2 = "wood";
    std::string obj3 = "food";

    Helmet helmet(h);
    Breastplate breastplate(b);
    Greaves greaves(g);
    Boots boots(bt);
    
    Objects diamond(obj1);
    Objects wood(obj2);
    Objects food(obj3);

    me.AddInBackpack(&diamond);
    me.AddInBackpack(&wood);
    me.AddInBackpack(&food);

    me.PutOnBoots(boots);
    me.PutOnGreaves(greaves);
    me.PutOnBreastplate(breastplate);
    me.PutOnHelmet(helmet);

    me.Move();
    me.OpenBackpack();
    me.CurrentEquipment();

    

    return 0;
}

