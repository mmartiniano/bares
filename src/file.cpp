#include "../include/file.h"

//constructor
File::File(std::string input_file_path, std::string output_file_path){
	this->input_file.open(input_file_path);
	
	//avoids failures to open file
	if (!(this->input_file.good() && this->input_file.is_open())){
		std::cout << "\nERROR: failed to open input file \"" << input_file_path << "\"\n";
		std::cout << "\nAborting...\n" << std::endl;
		exit(-1);
	}

	this->output_file.open(output_file_path, std::ofstream::out | std::ofstream::app);

	if (!(this->output_file.good() && this->output_file.is_open())){
		std::cout << "\nERROR: failed to open output file \"" << output_file_path << "\"\n";
		std::cout << "\nAborting...\n" << std::endl;
		exit(-1);
	}
}

//destructor
File::~File(){
	if (this->input_file.is_open()) this->input_file.close();
	if (this->output_file.is_open()) this->output_file.close();
}

//support methods
bool File::is_eof(){
	return this->input_file.good()  == false || this->input_file.is_open() == false;
}

//input and output methods
std::string File::read_line(){
	std::string line;

	std::getline(this->input_file, line);

	return line;
}

void File::write_line(std::string output){
	try{
		this->output_file << output << "\n";
	}catch(int & e){
		std::cout << "\nERROR: could not save data on output file\n";
		std::cout << "\nAborting..." << std::endl;
		exit(-1);
	}
}