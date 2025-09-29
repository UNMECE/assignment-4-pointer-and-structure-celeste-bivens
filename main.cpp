#include <iostream>
#include <cstring>
#include "item.h"
using namespace std;

void add_item(Item *list, int index, double price, const char *sku, const char *category, const char *name){

    list[index].sku = new char[strlen(sku)+1];//Allocating memory for each character in string up until null terminator, so therefore, we add 1 more byte.
    strcpy(list[index].sku, sku );//strcpy the location variable, source variable 

    list[index].name = new char[strlen(name)+1];//allocating memory for string name.
    strcpy(list[index].name, name);

    list[index].category = new char[strlen(category)+1];
    strcpy(list[index].category, category);

    list[index].price = price;
}

void print_item(Item &item)
{
    cout<<"##########"<<endl;
    cout << "Item name = " << item.name << endl; 
    cout << "Item SKU = " << item.sku << endl;
    cout << "Item Category = " << item.category << endl;
    cout << "Item price = " << item.price <<" dollars" << endl;

}

void print_items(Item *list, int size){


    for(int i=0; i<size; i++)
    {
        auto item = list[i];//Using auto function for compiler to recognize what data type a variable actually is. 
        print_item(item);
    }
  
    cout<<" "<<endl;   
}


void average_price(Item *list, int size)
{

    float avg;
    float sum = 0;

    for(int i=0; i<size; i++){
        sum += list[i].price;// Use of brackets de-references the pointer.
        avg = sum/(size);
    }
    cout<< "Price average for all items: "<< avg << " dollars" <<endl;
}

void free_item(Item *list, int size){
    delete[] list;
    list = nullptr;//Set pointer to null
}


int main(int argc, char *argv[]){


    cout<<"Number of arguments: "<< argc <<endl;
    if (argc != 2){
        cout<<"not enough arguments"<<endl;
        return 1;
    }

    const char *skuToFind;
    skuToFind = argv[1];
    cout<<"SKU to find is: "<< skuToFind << endl;


    const int size = 5;//const is unchanging.

    Item*list= new Item[size];//Dynamically allocating space for 5 item prices using new() function=>Step 2, 2


    int index = 0;
    add_item(list, index++, 5.670, "19282", "Breakfast", "Reese's cereal");//incrementing index.
    add_item(list, index++, 3.820, "15678", "Dairy", "Milk");
    add_item(list, index++, 4.400, "43679", "Dessert", "Custard");
    add_item(list, index++, 5.550, "89745", "Meat", "Chicken");
    add_item(list, index++, 2.600, "74537", "Fruit", "Blueberries");

  
    bool foundItem = false;//Initialize the boolean of foundItem to false 
    index = 0;
    while(!foundItem)
    {
        if (index < size)
        {
            auto item = list[index++];
            foundItem = strcmp(item.sku, skuToFind) == 0;//Using strcmp to compare item.sku and the skuToFind variable. 
            //Initializing found variable with bool data type to this comparison to see if it's value is true. 
            //learnt this strategy in https://en.cppreference.com/w/c/string/byte/strcmp 
            if (foundItem)
            {
                cout << "Found Item at Index: "<< index <<endl;
                print_item(item);
            }
        }
        else
        {
            break;
        }
    };
    if(!foundItem){
        cout<<"Unable to find item with SKU of " << skuToFind << endl;
    }
    cout<<" "<<endl;

    cout<<"Other available items: "<<endl;
    print_items(list,size);
    average_price(list, size);


    return 0;
}
