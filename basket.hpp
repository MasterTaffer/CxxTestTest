#pragma once
#include <map>
#include <string>
#include <stdexcept>
#include <vector>
class Item
{
    std::string name;
    int costInCents;
public:
    Item()
    {
    }

    Item(std::string name, int costInCents) : name(name), costInCents(costInCents)
    {
    }

    const std::string& getName() const
    {
        return name;
    }

    void setName(const std::string& newName)
    {
        name = newName;
    }
    
    int getCostInCents() const
    {
        return costInCents;
    }

    void setCostInCents(int newCost)
    {
        costInCents = newCost;
    }
};


class Basket
{
    std::map<std::string, std::pair<int, Item>> items;
public:
    void addItem(const Item& newItem, int count = 1)
    {
        auto it = items.find(newItem.getName());
        if (it == items.end())
            items[newItem.getName()] = {count, newItem};
        else
            it->second.first += count;
    }
    void clear()
    {
        items.clear();
    }

    std::vector<std::pair<int,Item>> getAllItems() const 
    {
        std::vector<std::pair<int,Item>> ret;
        for (auto &f : items)
            ret.push_back(f.second);
        return ret;
    }

    const Item& getItem(const std::string& name) const
    {
        using namespace std::literals::string_literals;

        auto it = items.find(name);
        if (it == items.end())
            throw std::logic_error("No item named '"s+name+" in basket");
        return it->second.second;
    }

    int getItemCount(const std::string& name) const
    {
        using namespace std::literals::string_literals;

        auto it = items.find(name);
        if (it == items.end())
            throw std::logic_error("No item named '"s+name+" in basket");
        return it->second.first;
    }

    bool hasItem(const std::string& name) const
    {
        auto it = items.find(name);
        return (it != items.end());
    }

    void removeAllOfItem(const std::string& name)
    {
        using namespace std::literals::string_literals;

        auto it = items.find(name);
        if (it == items.end())
            throw std::logic_error("No item named '"s+name+" in basket");

        items.erase(it);
    }

    void removeItem(const std::string& name, int count = 1)
    {
        using namespace std::literals::string_literals;

        auto it = items.find(name);
        if (it == items.end())
            throw std::logic_error("No item named '"s+name+" in basket");
        it->second.first -= count;
        if (it->second.first <= 0)
            items.erase(it);
    }

    int getTotalPrice() const
    {
        int total = 0;
        for (auto& p : items)
        {
            total += p.second.first * p.second.second.getCostInCents();
        }
        return total;
    }
};
