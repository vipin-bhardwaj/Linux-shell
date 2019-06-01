#include <iostream>
#include <unistd.h> 
#include <vector>
#include <cstring>
#include <string>

using namespace std;

int main() {
	//chdir, getcwd
	char inputCommand[1100];
	vector<string> previousCommand;
	char temp[1000];
	char *curDir = getcwd(temp, 100);
	cout << curDir << " \n";

	while(1) {
		
		curDir = getcwd(temp, 100);
		cout << ">>>> ";
		// cout << curDir << " $";
		cin.getline(inputCommand, 1099, '\n');
		if(strlen(inputCommand) > 0) {
			previousCommand.push_back(string(inputCommand));
		}
		if(system(inputCommand)) {

			cout << "command not found.\n";
		} else {
			char *cmd =  strtok(inputCommand, " ");
			if(!strcmp(cmd, "cd")) {
				char *path = strtok(NULL, " ");

				if(path == NULL) {
					// take me home;
					chdir(getenv("HOME"));
				} else {
					chdir(path);
				}
			}
		}	

	}

	return 0;
}
