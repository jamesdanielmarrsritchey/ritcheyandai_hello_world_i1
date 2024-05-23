#include <iostream>
#include <unistd.h>
#include <getopt.h>

int main(int argc, char *argv[]) {
    std::string defaultString = "World";
    std::string delimiter = ""; // Changed default value
    int loops = 1;
    int opt;
    static struct option long_options[] = {
        {"string", required_argument, 0, 's'},
        {"loops", required_argument, 0, 'l'},
        {"delimiter", required_argument, 0, 'd'},
        {0, 0, 0, 0}
    };

    while ((opt = getopt_long(argc, argv, "s:l:d:", long_options, NULL)) != -1) {
        switch (opt) {
            case 's':
                defaultString = optarg;
                break;
            case 'l':
                loops = std::stoi(optarg);
                break;
            case 'd':
                if (std::string(optarg) == "\\n") {
                    delimiter = "\n";
                } else if (std::string(optarg) == "\\t") {
                    delimiter = "\t";
                } else {
                    delimiter = optarg;
                }
                break;
            default:
                std::cerr << "Usage: " << argv[0] << " [--string value] [--loops value] [--delimiter value]\n";
                return 1;
        }
    }

    for (int i = 0; i < loops; i++) {
        if (i != 0) {
            std::cout << delimiter;
        }
        std::cout << "Hello " << defaultString << "!";
    }

    std::cout << "\n";
    return 0;
}