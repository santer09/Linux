#include <sys/wait.h>
#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


int main()
{
  ifstream urls;
  char name[256];//creates an array if charaters
  int number = 0;//keeps count of the number of urls
  string file = "urls.txt";//automatically adds file 
  pid_t pid = -1;//sets initial pid to null

  cout << "Opening file -- <" << file <<">"<< endl << endl;//displays the file from which is getting urls
  urls.open(file.c_str());//opens file containing urls
	if (urls.fail()){//checks if the file was found or opened
		cerr << "ERROR -- FILE NOT FOUND!" << endl;
		exit(1);//if the file wasn't found exit process
	}
	else{
		while (urls.getline(name, sizeof(name))){//gets every url and puts it into an array of strings
			number++;//keeps counts of urls processed

  			pid = fork();//creates another fork process

  			if (pid < 0){//checks for fork's failure
				cerr << "Fork Failed";
				exit(1);//exit if the fork failed
  			}
  			else if (pid == 0){//creates a child to download files
				cout << "**URL " << name << " is currently downloading...**\n";
				execlp("/usr/bin/wget", "wget", name, NULL);//the command to downlad the files
			}
		}
                while(number > 0){//parent process will wait for child process to complete
    			wait(NULL);
			cout << "**URL #" << number << " has been downloaded!**\n\n";
			--number;
		}
	}
  urls.close();//close the file 
  return 0;//exit program
}



