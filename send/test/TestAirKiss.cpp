#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include "AirKiss.h"



void usage(char *app_name)
{
	printf("usage:\n");
    printf("\t%s -s ssid -p password\n", (char *)basename(app_name));

    return;
}

int main(int argc, char **argv)
{
	int res = 0;
	std::string ssid;
	std::string password;
	Slink::CAirKiss airKiss;

    if(argc < 5) {
        usage(argv[0]);
        return -1;
    }

    while((res = getopt(argc, argv, "?s:p:h")) != -1) {
        switch(res) {
        case 's':
            ssid = optarg;
            break;

        case 'p':
            password = optarg;
			break;

		case 'h':
		default:
			usage(argv[0]);
			return -1;
		}
	}

	printf("ssid(%s), password(%s)\n", ssid.c_str(), password.c_str());

	airKiss.SetRouteInfo(ssid, password);

	while(1) {
		sleep(10);
	}

	airKiss.Reset();

	return 0;
}
