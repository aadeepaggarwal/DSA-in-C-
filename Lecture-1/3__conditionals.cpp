  #include<iostream>
using namespace std;

int main(){

	int a;
    cout<<"enter the points of RCB:";
    cin>>a;
// note the if else ladder... we never write conditon after else and for multiple conditions we use else if 
    if(a<=10){
        cout<<"will not qualify";    
    }
    else if (a>10 && a<16){
        cout<<"Might Qualify";

    }
    else if (a>=16){
        cout<< "Qualified";
    }

    else { cout<<"invalid input";}
    
	return 0;
}
