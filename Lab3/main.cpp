#include <stdio.h>
#include <unistd.h>
#include <map>
#include <string>
#include <getopt.h>

using namespace std;

int main(int argc, char *argv[]){
    int a=0;
	map <string, bool> used;

	int option_index = -1; 
	//h-help;l-list;v-version;V-value
	const char* short_options = "hlvV::?"; 
	
	const struct option long_options[] = {
        {"help",0,NULL,'h'},
        {"list",0,NULL,'l'},
        {"version",0,NULL,'v'},
		{"value",2,NULL,'V'},
        {NULL,0,NULL,0},
    };

	while ((a = getopt_long(argc,argv,short_options,long_options, &option_index)) != -1){
		switch (a){
		case 'h': {
			if (used["h"] == false) {
				printf("Arg: Help\n"); 
				used["h"] = true;
				break;
			} 
			break;
		}
		case 'l': {
			if (used["l"] == false) {
				printf("Arg: List\n"); 
				used["l"] = true;
				break;
			}
			break;
		}
		case 'v': {
			if (used["v"] == false) {
				printf("Arg: version\n"); 
				used["v"] = true;
				break;
			}
			break;
		}
		case 'V': {
			if (used["V"] == false) {
				if (optarg == NULL) {
					printf("Arg: value\n"); 
					used["V"] = true;
				} else {
					printf("Arg: %s value\n", optarg); 
					used["V"] = true;
				}
				
				break;
			}
			break;
		}
		case '?': default: {
			printf("Key %c is not found\n", a);
			break;
			}
        };
		option_index = -1;
	};
};
