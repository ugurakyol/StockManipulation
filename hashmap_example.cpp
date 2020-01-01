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
    int quantity;
    string invoice_date;
    string unit_price;
    string costomer_id;
    string country;

    product(string f_invoice_no,
    string f_stock_code,
    string f_description,
    int f_quantity,
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

void read_csv_file(map<string, product> *data);
void search(map<string, product> *data );
void display(map<string, product> *data,int row);

int main()
{
    
    map<string, product> data;   
     
    data.insert(std::make_pair("150",product("10","150","pen",1,"1.12.2010 08:26","unit_price","costomer_id","Turkey") ));
    display(&data,1);
    read_csv_file(&data);
    display(&data,1);
    search(&data);

    

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

void read_csv_file(map<string, product> *data){

    map<string, product>::iterator find;
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
                int quantity = 0;
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
                        
                        break;
                        case 2:
                        invoice_no = token.c_str();
                        break;
                        case 3:
                        stock_code = token.c_str();
                        break;
                        case 4:
                        description = token.c_str();
                        break;
                        case 5:
                        quantity = std::atoi(token.c_str());
                        break;
                        case 6:
                        invoice_date = token.c_str();
                        break;
                        case 7:
                        unit_price = token.c_str();
                        break;
                        case 8:
                        costomer_id = token.c_str();
                        break;
                        case 9:
                        country = token.c_str();
                        break;                         
                        default:
                        break;
                    }

                    token = s.substr(0, pos);
                    s.erase(0, pos + delimiter.length());
                }

                cout <<"read line: " <<invoice_no <<" \t "<< stock_code <<" \t "<< description <<" \t "<< quantity <<" \t "<< invoice_date <<" \t "<< unit_price <<" \t "<< costomer_id <<" \t "<< country<<endl;
        
          

        
                    find = data->find(stock_code);

                    if(find != data->end()){

                        find->second.quantity += quantity; 
                        cout<<" new quantive of "<< find->second.description<<" is: "<< find->second.quantity<<endl; 

                    }else{                        

                        data->insert(std::make_pair(stock_code,product(invoice_no,stock_code,description,quantity,invoice_date,unit_price,costomer_id,country) ));

                    }
               
                
                //find=data->end();
                //data->insert(std::make_pair(find->first,product(invoice_no,stock_code,description,quantity,invoice_date,unit_price,costomer_id,country) ));


                              
            }
			row++;
            //display(data,2) ;  
		}
		file.close();
	}     
}

void display(map<string, product> *data,int row){

    cout << " ~~~~~~~~~~~~~~PRODUCT LIST~~~~~~~~~~~~~~~~~~~"<<endl;

    map<string, product>::iterator it;

    for(it=data->begin();it!=data->end();it++)

     cout << it->first <<" " << it->second.invoice_no <<" \t "<<it->second.stock_code <<" \t "<<it->second.description <<
        " "<<it->second.quantity <<" \t "<< it->second.invoice_no <<" \t "<< it->second.unit_price <<" \t "<<it->second.costomer_id <<
        " "<< it->second.country << " \n";
    cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
}

void search(map<string, product> *data ){

    int f_stock_code;
    cout << "Please, enter stock code : ";
    cin>>f_stock_code;
   
    map<string, product>::iterator it;
 
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
     search(data);
}

