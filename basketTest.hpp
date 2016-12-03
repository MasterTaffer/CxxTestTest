#include <cxxtest/TestSuite.h>
#include "basket.hpp"

class BasketTestSuite : public CxxTest::TestSuite
{
public:
    void testBasketAdd()
    {
        Basket basket;
        Item sausage = Item("makkara",79);
        Item banana = Item("banaani",51);
        basket.addItem(sausage,7);
        TSM_ASSERT("Basket doesn't contain an added item", basket.hasItem("makkara"));
        TSM_ASSERT_EQUALS("Basket doesn't add the correct amount of items", basket.getItemCount("makkara"),7);


        basket.addItem(banana,2);
        TSM_ASSERT("Basket doesn't contain an added item", basket.hasItem("banaani"));
        TSM_ASSERT_EQUALS("Basket doesn't add the correct amount of items", basket.getItemCount("banaani"),2);
        basket.addItem(banana,1);
        TSM_ASSERT_EQUALS("Basket doesn't add the correct amount of items", basket.getItemCount("banaani"),3);

        
        TSM_ASSERT("Basket doesn't contain an added item after adding another item", basket.hasItem("makkara"));
        TSM_ASSERT_EQUALS("Basket doesn't add the correct amount of items after adding another item", basket.getItemCount("makkara"),7);
    }

    void testBasketRemove()
    {
        Basket basket;
        Item sausage = Item("makkara",79);
        Item banana = Item("banaani",51);
        Item milk = Item("maito",140);

        basket.addItem(sausage,4);
        basket.addItem(banana,6);
        basket.addItem(milk,7);

        basket.removeItem("makkara");
        TSM_ASSERT_EQUALS("Basket doesn't remove items correctly", basket.getItemCount("makkara"),4 - 1);

        basket.removeItem("makkara",2);
        TSM_ASSERT_EQUALS("Basket doesn't remove items correctly", basket.getItemCount("makkara"),4 - 1 - 2);

        basket.removeItem("makkara",2);
        TSM_ASSERT_EQUALS("Basket doesn't remove items correctly", basket.hasItem("makkara"), false);

        TSM_ASSERT_EQUALS("Basket doesn't remove items correctly", basket.getItemCount("maito"), 7);
        TSM_ASSERT_EQUALS("Basket doesn't remove items correctly", basket.getItemCount("banaani"), 6);
        
        TSM_ASSERT_THROWS("Basket removeItem doesn't throw when item doesn't exist", basket.removeItem("makkara",4), std::logic_error);
    }

    void testBasketGetItem()
    {
        Basket basket;
        Item milk = Item("maito",140);
        Item sausage = Item("makkara",140);
        
        basket.addItem(milk,4);
        basket.addItem(sausage,2);
        
        TSM_ASSERT_EQUALS("Basket getItem returns wrong item", basket.getItem("maito").getName(), "maito");

        TSM_ASSERT_THROWS("Basket getItem doesn't throw when item doesn't exist", basket.getItem("banaani"), std::logic_error);

    }



    void testBasketRemoveAll()
    {
        Basket basket;
        Item sausage = Item("makkara",79);

        basket.addItem(sausage,4);
        TSM_ASSERT_EQUALS("Basket doesn't add items correctly", basket.getItemCount("makkara"),4);

        basket.removeAllOfItem("makkara");
        TSM_ASSERT_EQUALS("Basket doesn't remove all items correctly", basket.hasItem("makkara"), false);

    }

    void testBasketCalculatePrice()
    {
        Basket basket;
        
        Item sausage = Item("makkara",79);
        Item banana = Item("banaani",51);
        Item milk = Item("maito",140);
        
        basket.addItem(sausage,2);
        basket.addItem(banana,3);

        TSM_ASSERT_EQUALS("Basket getTotalPrice returns wrong price", basket.getTotalPrice(), 2 * 79 + 3 * 51);

        basket.addItem(banana,1);
        TSM_ASSERT_EQUALS("Basket getTotalPrice returns wrong price", basket.getTotalPrice(), 2 * 79 + 4 * 51);

        basket.removeItem("makkara",1);
        TSM_ASSERT_EQUALS("Basket getTotalPrice returns wrong price", basket.getTotalPrice(), 1 * 79 + 4 * 51);
        
        basket.removeItem("makkara",2);
        TSM_ASSERT_EQUALS("Basket getTotalPrice returns wrong price", basket.getTotalPrice(), 4 * 51);
    }

    void testBasketAllContents()
    {
        Basket basket;
        
        Item sausage = Item("makkara",79);
        Item banana = Item("banaani",51);
        Item milk = Item("maito",140);

        basket.addItem(sausage,4);
        basket.addItem(banana,7);
        basket.addItem(milk,2);

        std::vector<std::pair<int, Item>> items = basket.getAllItems();

        TSM_ASSERT_EQUALS("Basket getAllItems doesn't return full list", items.size(), 3);
        
        //Returned items are in alphabetical order
        TSM_ASSERT_EQUALS("Basket getAllItems list malformed", items[0].first, 7);
        TSM_ASSERT_EQUALS("Basket getAllItems list malformed", items[1].first, 2);
        TSM_ASSERT_EQUALS("Basket getAllItems list malformed", items[2].first, 4);

        TSM_ASSERT_EQUALS("Basket getAllItems list malformed", items[0].second.getName(), "banaani");
        TSM_ASSERT_EQUALS("Basket getAllItems list malformed", items[1].second.getName(), "maito");
        TSM_ASSERT_EQUALS("Basket getAllItems list malformed", items[2].second.getName(), "makkara");


        basket.removeAllOfItem("makkara");
        basket.removeItem("banaani",5);
        basket.removeItem("maito",2);

        items = basket.getAllItems();

        TSM_ASSERT_EQUALS("Basket getAllItems doesn't correct list", items.size(), 1);
        
        TSM_ASSERT_EQUALS("Basket getAllItems list malformed", items[0].first, 2);

        TSM_ASSERT_EQUALS("Basket getAllItems list malformed", items[0].second.getName(), "banaani");
    }
};


