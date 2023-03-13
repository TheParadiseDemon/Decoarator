#include <bits/stdc++.h>
#include <utility>

class Spell{
public:
    Spell(){
        name = "Standart spell";
    }
    explicit Spell(std::string name){
        this->name = std::move(name);
    }

    std::string name;

    virtual int GetCost() = 0;
};

class DarkSpell : public Spell{
public:
    explicit DarkSpell(const std::string& name){
        this->name = "Dark " + name;
    }

    int GetCost() override{
        return 10;
    }
};

class LightSpell : public Spell{
public:
    explicit LightSpell(const std::string& name){
            this->name = "Light " + name;
    }

    int GetCost() override{
        return 15;
    }
};

class SpellUpgrade : public Spell{
protected:
    Spell* spell;
public:
    SpellUpgrade(Spell *spell){
        this->spell = spell;
    }
};

class CheapSpell : public SpellUpgrade{
public:
    CheapSpell(Spell *spell) : SpellUpgrade(spell) {
        this->name = "Cheap " + spell->name;
    }

    int GetCost() override{
        return spell->GetCost() - 5;
    }
};

class ExpensiveSpell : public SpellUpgrade{
public:
    ExpensiveSpell(Spell *spell) : SpellUpgrade(spell) {
        this->name = "Expensive " + spell->name;
    }

    int GetCost() override{
        return spell->GetCost() + 5;
    }
};

int main(){
    Spell* spell1 = new LightSpell("omg");
    spell1 = new ExpensiveSpell(spell1);
    std::cout << spell1->GetCost() << " " << spell1->name;

    return 1;
}
