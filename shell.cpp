#include <iostream>
#include <unistd.h> 
#include <vector>
#include <cstring>

using namespace std;

int main() {
	//chdir, getcwd
	char inputCommand[1100];
	vector<int> previousCommand;
	while(1) {
		char temp[1000];
		char *curDir = getcwd(temp, 100);
		cout << curDir << " $";
		cin.getline(inputCommand, 1099, '\n');
		if(system(inputCommand)) {
			cout << "command not found.\n";
		} else {
			char *cmd =  strtok(inputCommand, " ");
			if(!strcmp(cmd, "cd")) {
				char *path = strtok(NULL, " ");
				if(path == NULL) {
					// take me home;
				} else {
					chdir(path);
				}
			}
		}	

	}

	return 0;
}
