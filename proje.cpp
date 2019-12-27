#include<iostream>
#include <cstdlib> 
#include<cstring>
#include<string>
#include <time.h>
#include<stdlib.h>
#include <fstream>

using namespace std;

//this structure node is defined for store taken data from the csv file

 struct  node {
	int row;
  string invoice_no;
  string stock_code;
  string description;
  string quantity;
  string invoice_date;
  string unit_price;
  string costomer_id;
  string country;
	struct node *next;
};
struct node *data;


//this stack is defined for duplicated stock
struct listed_id
{
    char *stock_code;    
    struct listed_id *next;
};

// structure functions
bool is_empty(struct node *data);

struct node * createList(
  int row,
  string invoice_no,
  string stock_code,
  string description,
  string quantity,
  string invoice_date,
  string unit_price,
  string costomer_id,
  string country);

struct node * insertBack(
  struct node data,
  int row,
  string invoice_no,
  string stock_code,
  string description,
  string quantity,
  string invoice_date,
  string unit_price,
  string costomer_id,
  string country);

struct node * deleteFront(struct node *data);

int sizeofdata (struct node *data);

void display (struct node *data);



// Ugur AKYOL sorting  functions of linked list
void sortarrival(struct node *data);
void sortburst(struct node *data);
void sortpriority(struct node *data);
void sortpid(struct result *times);
void swap();
void swaptimes();




// nodes functions
struct nodes * createNodes(char title,int weight);

struct nodes * pushtonodes(struct nodes *header, char title, int weight);

struct nodes * pushendofnodes(struct nodes *header, char title, int weight);

struct nodes *deleteFrontofnodes(struct nodec *header);

struct nodes *popfromnodes(struct nodes *header);

void displaystacknodes(struct nodes *header);

void swap(struct nodes * x, struct nodes * y);

void sortstack(struct nodes *data);



void read_csv_file();

int main() 
{ 
    //Csvtoxls(); // this function is called for converting given CVS file to XLS file.
    
    read_csv_file();
   // display(data);
    return 0; 
}

void read_csv_file(){

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
            cout << token << "\t";
            s.erase(0, pos + delimiter.length());
        }
        cout << endl;


        struct node *data;         
        data = createList(row,invoice_no,stock_code,description,quantity,invoice_date,unit_price,costomer_id,country);

        {
          /* data */
        };
        
      }
			row++;
		}
		file.close();
	}      
    
}



//there are some function about linked list below of this line
bool isempty(struct node *data){
    if(data==NULL)
        return true;
    else
        return false;
}

struct node * createList(  
  int row,
  string invoice_no,
  string stock_code,
  string description,
  string quantity,
  string invoice_date,
  string unit_price,
  string costomer_id,
  string country)
{
    struct node * temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->invoice_no = invoice_no;
    temp->stock_code = stock_code;
    temp->description = description;
    temp->quantity = quantity;
    temp->invoice_date = invoice_date;
    temp->unit_price = unit_price;
    temp->costomer_id = costomer_id;
    temp->country = country;
    temp->next=NULL;
    return temp;
}
// Ugur AKYOL

struct node *insertBack(
  struct node *data,
  int row,
  string invoice_no,
  string stock_code,
  string description,
  string quantity,
  string invoice_date,
  string unit_price,
  string costomer_id,
  string country){

    struct node * temp = createList(row,invoice_no,stock_code,description,quantity,invoice_date,unit_price,costomer_id,country);
    struct node * datatemp;
    if (data == NULL)
    {
        data = temp;
        return data;
    }
    datatemp=data;
    while(datatemp->next != NULL)
        datatemp=datatemp->next;
    datatemp->next = temp;
    return data;
}

// Ugur AKYOL
struct node *deleteFront(struct node *data)
{
    struct node *temp;
    if(data==NULL)
        return data;
    temp=data;
    data=data->next;
    free(temp);
    return data;
}

// Ugur AKYOL
void display(struct node *data)
{
    int cnt=1;
    if (data == NULL)
        printf("List is empty\n");

    struct node *temp = data;
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("  Invoice No ~ Stock Code ~ Description ~ Quantity ~ Invoice Date ~ Unit Price ~ Costomer ID ~ Country\n");
    

    while (temp != NULL)
    {   printf("P%u:    %u             %u           %u          %u            %u           %u           %u           %u\n",
    temp->row,
    temp->invoice_no,
    temp->stock_code,
    temp->description,
    temp->quantity,
    temp->invoice_date,
    temp->unit_price,
    temp->costomer_id,
    temp->country);

        cnt++;
        temp=temp->next;
    }
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

}


int sizeofdata(struct node *data)
{
    struct node *temp=data;
    int line=0;
    if(temp!=NULL)
        while(temp!=NULL){
            temp=temp->next;
            line++;
        }
    free(temp);
    return line;

}
