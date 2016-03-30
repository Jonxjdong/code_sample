#include <iostream>
#include <fstream>
#include <string>
using namespace std; 
// IOstream: read/write txt

int main() {
	ifstream src_file("data.txt"); 
	string line; 	
	ofstream dst_file("dst.txt"); 

	if (src_file)
	{
		while (getline(src_file, line))    // Read line by line
		{
			cout << line << endl;			 // DO SOMETHING
			dst_file << line << endl;      // Write to dst.txt
		}
	}
	else
	{
		cout << "No file found" << endl; 
	}


	src_file.close(); 
	dst_file.close(); 
	system("PAUSE"); 
}