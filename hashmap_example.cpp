#include<iostream>
#include <cstdlib> 
#include<cstring>
#include<string>
#include<string.h>
#include <time.h>
#include<stdlib.h>
#include <fstream>
#include<map>
#include<iterator>
#include <sstream> 
//#include <bits/stdc++.h> 

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

void read_csv_file(map<int, product> *data);
void search(map<int, product> *data );
void add_to_stock(map<int, product> *data,int row);

int main()
{
    
    map<int, product> data;
    map<int, product> data2;
     
    //data.insert({0,product("invoice_no","stock_code","description","quantity","invoice_date","unit_price","costomer_id","country") });
   
    read_csv_file(&data);

    search(&data);

   // add_to_stock(&data,1);
 




/*
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
*/
}

void read_csv_file(map<int, product> *data){

  string str = "storage.csv";
  ifstream file(str);

	if (file.is_open()) {

		string line;
        int row = 0;

		while (getline(file, line)) {
			
			if(row == 0){
                cout << line <<endl;
            }else{
                
                string invoice_no = "";
                string stock_code = "";
                string description = "";
                string quantity = "";
                string invoice_date = "";
                string unit_price = "";
                string costomer_id = "";
                string country = "";

                
                string s = line.c_str();
                std::string delimiter = ";";
                size_t pos = 0;
                std::string token;

                int coloum = 0;

                while ((pos = s.find(delimiter)) != std::string::npos) {
                    
                    coloum ++;                                
                    switch (coloum)
                    {
                        case 1:                
                        invoice_no = token.c_str();
                        break;
                        case 2:
                        stock_code = token.c_str();
                        break;
                        case 3:
                        description = token.c_str();
                        break;
                        case 4:
                        quantity = token.c_str();
                        break;
                        case 5:
                        invoice_date = token.c_str();
                        break;
                        case 6:
                        unit_price = token.c_str();
                        break;
                        case 7:
                        costomer_id = token.c_str();
                        break;
                        case 8:
                        country = token.c_str();
                        break;                        
                        default:
                        break;
                    }

                    token = s.substr(0, pos);
                    s.erase(0, pos + delimiter.length());
                }
                cout << invoice_no <<" \t "<< stock_code <<" \t "<< description <<" \t "<< quantity <<" \t "<< invoice_date <<" \t "<< unit_price <<" \t "<< costomer_id <<" \t "<< country<<endl;
                
                data->insert({                    
                    row,product(invoice_no,stock_code,description,quantity,invoice_date,unit_price,costomer_id,country) 
                });

                map<int, product>::iterator it;

                for(it=data->begin();it!=data->end();it++)

                        cout << it->first <<" " << it->second.invoice_no <<" \t "<<it->second.stock_code <<" \t "<<it->second.description <<
                            " "<<it->second.quantity <<" \t "<< it->second.invoice_no <<" \t "<< it->second.unit_price <<" \t "<<it->second.costomer_id <<
                            " "<< it->second.country << " \n";

/*
                map<int, product>::iterator it;
                for(it=data->begin();it!=data->end();it++){

                    cout<< it->second.stock_code<<endl;
                    int x = 0; 
                    std::string s = it->second.stock_code;  
                    stringstream geek(s);

                    if(it->second.stock_code == "stock_code"){

                    }else{

                        geek >> x; 

                        if(x == stoi(stock_code)){
                            cout<<it->second.stock_code <<"=="<<stock_code<<endl;
                            cout << it->second.description << " is inside stock " << it->second.quantity<< "+"<<quantity<<endl; 
                        
                        }else{
                            data->insert({                    
                                row,product(invoice_no,stock_code,description,quantity,invoice_date,unit_price,costomer_id,country) 
                            });
                        }


                    }
               
                }  */                
            }
			row++;
		}
		file.close();
	}     
}

void add_to_stock(map<int, product> *data,int row){

    map<int, product>::iterator it;

    for(it=data->begin();it!=data->end();it++)

     cout << it->first <<" " << it->second.invoice_no <<" \t "<<it->second.stock_code <<" \t "<<it->second.description <<
        " "<<it->second.quantity <<" \t "<< it->second.invoice_no <<" \t "<< it->second.unit_price <<" \t "<<it->second.costomer_id <<
        " "<< it->second.country << " \n";


    int id;
    cout << "Please, enter row id : ";
    cin>>id;

    it = data->find(id);
    if (it != data->end())
    {
        cout << it->first <<" " << it->second.invoice_no <<" \t "<<it->second.stock_code <<" \t "<<it->second.description <<
        " "<<it->second.quantity <<" \t "<< it->second.invoice_no <<" \t "<< it->second.unit_price <<" "<<it->second.costomer_id <<
        " "<< it->second.country << " \n";
    }
}

void search(map<int, product> *data ){

    int f_stock_code;
    cout << "Please, enter stock code : ";
    cin>>f_stock_code;
   
    map<int, product>::iterator it;
 
    for(it=data->begin();it!=data->end();it++){               
      
        int x = 0; 
        std::string s = it->second.stock_code;  
        stringstream geek(s);
        if(it->second.stock_code == "stock_code"){

        }else{

            geek >> x; 

            if(x == f_stock_code){
                cout<<"invoice_no\tstock_code\tdescription\tquantity\tinvoice_date\tunit_price\tcostomer_id\tcountry"<<endl;
                cout<< it->second.invoice_no <<" \t "<< it->second.stock_code <<" \t "<< it->second.description 
                <<" \t "<< it->second.quantity <<" \t "<< it->second.invoice_date <<" \t "<< it->second.unit_price 
                <<" \t "<< it->second.costomer_id <<" \t "<< it->second.country << " \n";

            }

        } 


    }
        
     

}

