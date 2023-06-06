#include<bits/stdc++.h>
#include<time.h>
#include <unistd.h>
#include <iostream>
#include <fstream>

using namespace std;

int dkey;

bool inline comparator(pair<int,string> a,pair<int,string> b){
return a.first < b.first;}

bool inline matcher(pair<int,string> a){
return a.first == dkey;}

pair<string,long long> encrypter(string msg)
{
	string coded_msg;
	vector<pair <int,string>> v_plain;
	vector<pair <int,string>> v_cipher;
	vector<pair <int,string>> trans_cipher;
	int len = msg.size();
	int row = ceil(sqrt(len));
	
	//Padding extra bits in message
	int temp = (row*row)-len;
	for(int i=0;i<temp;i++){
	msg+=" ";}
	
	cout<<msg;
	
	len = msg.size(); //Update the new size after padding
	
	vector<int> key_arr;
	int tmp = row;
	srand(time(NULL));
	while(tmp>0){ //Generating a random key of size equals to number of rows in plaintext matrix
	    int a = rand()%99;
	    if(a > 9){ 
	     if(find(key_arr.begin(),key_arr.end(),a)==key_arr.end()){
	     key_arr.push_back(a);
	     tmp--;
	     }
	    }
	   }
	   
	for(int i=0;i<row;i++){
	v_plain.push_back(make_pair(key_arr[i],msg.substr(i*row,row)));}
	
	cout<<endl;
	
	v_cipher = v_plain;

	sort(v_cipher.begin(),v_cipher.end(),comparator);

	trans_cipher = v_cipher;
	
	for(int i=0;i<row;i++){
	 for(int j=0;j<row;j++){
	  trans_cipher[i].second[j] = v_cipher[j].second[i];
	 }
	}
	
	for(int i=0;i<trans_cipher.size();i++){    //Make cipher from cipher matrix
	coded_msg+=trans_cipher[i].second;}
	
	long long key = 0;
	
	for(int i=0;i<row;i++)
	key = (key*100)+key_arr[i];


	return make_pair(coded_msg,key);
}

string decrypter(string cipher,long long key)
{
        string msg;
	vector<pair <int,string>> v_plain;
	vector<pair <int,string>> v_cipher;
	vector<pair <int,string>> trans_cipher;
	int len = cipher.size();
	int row = ceil(sqrt(len));
        vector<int> key_arr;
	   
	   for(int i=0;i<row;i++){
	   key_arr.push_back(key%100);
	   key = key/100;
	   }
	   
	   reverse(key_arr.begin(),key_arr.end());
	  
	   vector<int>sorted_key_arr = key_arr;
	   sort(sorted_key_arr.begin(),sorted_key_arr.end());
	   
	for(int i=0;i<row;i++){
	v_cipher.push_back(make_pair(sorted_key_arr[i],cipher.substr(i*row,row)));}
	
     trans_cipher = v_cipher;
	
	for(int i=0;i<row;i++){
	 for(int j=0;j<row;j++){
	  trans_cipher[i].second[j] = v_cipher[j].second[i];
	 }
	}
	
	for(int i=0;i<row;i++){
	dkey = key_arr[i];
	v_plain.push_back(*find_if(trans_cipher.begin(),trans_cipher.end(),matcher));}
	
	
	for(int i=0;i<trans_cipher.size();i++){    //Make cipher from cipher matrix
	msg+=v_plain[i].second;}
	
	return msg;
}

int main(void)
{
    int choice;
    string line,msg,decodedmsg;
    pair<string,long long> codedmsg;
    cout<<"Select The Operation :\n1 - Encryption\n2 - Decryption\n";
    cin>>choice;
    ifstream fin;
    ofstream fout;
    
    if(choice==1){                  //ENCRYPTION
    fin.open("encryp_input.txt");
    getline(fin, line);
    msg=line;
    fin.close();
    cout<<"Starting Encryption"<<endl;
    sleep(1);

    codedmsg = encrypter(msg);
    
    cout<<"Encryption Started"<<endl;
    sleep(2);
	
    cout<<"Encryption Done! Getting Results"<<endl;
    
    fout.open("encryp_output.txt");
    fout<<codedmsg.first<<endl;
    fout<<codedmsg.second;
    fout.close();}
 
    
    else if(choice==2){
    fin.open("decryp_input.txt");
    getline(fin, line);
    codedmsg.first=line;
    line.clear();
    getline(fin, line);
    codedmsg.second=stoll(line);
    fin.close();
    
    cout<<"\nDecryption Started"<<endl<<endl;
    sleep(2);
    
    fout.open("decryp_output.txt");
    fout<<decrypter(codedmsg.first,codedmsg.second);
    fout.close();}
  	
    return 0;
}
