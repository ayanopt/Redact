
using namespace std;
#include <fstream>
#include <iostream>
#include <string>
/*read in as . / redact.exe in_file out_format word
 example: ./redact.exe bee_movie_script.txt txt bee
 gives bee_movie_script_REDACTED_bee.txt, without the word bee

 example: ./redact.exe wolf_of_wall_street_2013.pdf doc Naomi
 gives wolf_of_wall_street_2013.pdf_REDACTED_Naomi.doc, without Naomi
 */
int main(int argc, char* argv[]) {
	if (argc != 4) {
		cout << "Error: Must be in format " <<
			"./redact.exe in_file out_format word" << endl;
		return 1; //check if input is in correct format
	}
	string in = argv[1];
	ifstream fin(in);
	if(!fin.good()) {cout<<"Error: No such file"<<endl; return 1;}
	//ensure that file exists
	string type = argv[2];
	string target_word = argv[3];
	ofstream fout(in + "_REDACTED_" + target_word+"."+type);
	size_t size = target_word.length();
	string num_asterix(size, '*'); //parse word length into number of asterices
	string words;
	while (fin >> words) {
		if (words == target_word) fout << num_asterix << " ";
		else fout << words<<" "; //only read in words that are not the redacted word
	}
	fin.close();
	fout.close();
	return 0;
}
