#include<iostream>
#include <cstdlib> 
#include<cstring>
#include<string>
#include <time.h>
#include<stdlib.h>
#include <fstream>
#include<map>
#include<iterator>
#include <bits/stdc++.h> 

using namespace std;

struct product {

    string invoice_no;
    string stock_code;
    string description;
    string quantity;
    string invoice_date;
    string unit_price;
    string costomer_id;
    string country;

    product(string f_invoice_no,
    string f_stock_code,
    string f_description,
    string f_quantity,
    string f_invoice_date,
    string f_unit_price,
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




map<int, product> read_csv_file(map<int, product> data);

int main()
{
    
    map<int, product> data;

        data.insert({10,product("sdf","sdfsdf","sdfs","1","sdf","2","dfs","df") });
        data.insert({12,product("sdf","sdfsdf","sdfs","1","sdf","2","dfs","df") });
        data.insert({11,product("sdf","sdfsdf","sdfs","1","sdf","2","dfs","df") });


   
    
    //data.insert_or_assign = read_csv_file(data);

    map<int, product>::iterator it;
 
    if (it != data.end())
    {
        cout << "The product with id of 1 has " << it->second.description << " cylinders\n";
    }

    for(auto it = data.cbegin(); it != data.cend(); ++it)
    {
        std::cout << it->first << " " << it->second.costomer_id << " df" << it->second.description << "\n";
    }
}

map<int, product> read_csv_file(map<int, product> data){
    data = {

        {10,product("sdf","sdfsdf","sdfs","1","sdf","2","dfs","df") }
    };

  string str = "storage.csv";
  //printf("Please input xls file name : ");
  //cin>>str;  
  ifstream file(str);

	if (file.is_open()) {

		string line;
    int row = 0;
		while (getline(file, line)) {
			
			if(row == 0){

            }else{
                string invoice_no;
                string stock_code;
                string description;
                string quantity;
                string invoice_date;
                string unit_price;
                string costomer_id;
                string country; 
                
                string s = line.c_str();
                std::string delimiter = ",";
                size_t pos = 0;
                std::string token;
                int coloum = 0;

                while ((pos = s.find(delimiter)) != std::string::npos) {
                    coloum ++;
                                
                    switch (coloum)
                    {
                    case 1:
                    invoice_no = token;
                    break;
                    case 2:
                    stock_code = token;
                    break;
                    case 3:
                    description = token;
                    break;
                    case 4:
                    quantity = token;
                    break;
                    case 5:
                    invoice_date = token;
                    break;
                    case 6:
                    unit_price = token;
                    break;
                    case 7:
                    costomer_id = token;
                    break;
                    case 8:
                    country = token;
                    break;
                    
                    default:
                    break;
                    }
                    token = s.substr(0, pos);
                    //cout << token << "\t";
                    s.erase(0, pos + delimiter.length());
                }
                //cout << endl;


                
                data = {

                    {row,product("sdf","sdfsdf","sdfs","1","sdf","2","dfs","df") }
                };

        
        
            }
			row++;
		}
		file.close();
	}      
    return data;
}
