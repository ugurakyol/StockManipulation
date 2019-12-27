#include<iostream>
#include <cstdlib> 
#include<cstring>
#include<string>
#include <time.h>
#include<stdlib.h>
#include <fstream>
#include<map>
#include<iterator>

using namespace std;

struct product {

    string invoice_no;
    string stock_code;
    string description;
    int quantity;
    string invoice_date;
    int unit_price;
    string costomer_id;
    string country;

    product(string f_invoice_no,
    string f_stock_code,
    string f_description,
    int f_quantity,
    string f_invoice_date,
    int f_unit_price,
    string f_costomer_id,
    string f_country)
    {
      invoice_no =f_invoice_no;
      stock_code = f_stock_code;
      description = f_description;
      quantity = f_quantity;
      invoice_date = f_invoice_no;
      unit_price = f_unit_price;
      costomer_id = f_costomer_id;
      country = f_country;
    }
};

int main()
{

    map<int, product> data ={

        {1,product("sdf","sdfsdf","sdfs",1,"sdf",2,"dfs","df") }
    };
        
    // Populate the dictionary
    

    map<int, product>::iterator it;

    it = data.find(1);

    if (it != data.end())
    {
        cout << "The vehicle with key of I has " << it->second.description << " cylinders\n";
    }
}