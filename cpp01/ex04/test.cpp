#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[]) {
    // Check number of arguments
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    // s1 cannot be empty
    if (s1.empty()) {
        std::cerr << "Error: s1 cannot be empty." << std::endl;
        return 1;
    }

    // Open input file
    std::ifstream infile(filename.c_str());
    if (!infile) {
        std::cerr << "Error: cannot open file '" << filename << "'" << std::endl;
        return 1;
    }

    // Read whole file into a string
    std::string content;
    std::string line;

    while (std::getline(infile, line)) {
        content += line;
        if (!infile.eof())
            content += "\n";  // keep newlines
    }
    infile.close();

    // Replace occurrences of s1 with s2 manually
    std::string result;
    size_t pos = 0;

    while (true) {
        size_t found = content.find(s1, pos);

        if (found == std::string::npos) {
            // Copy the rest of the text
            result += content.substr(pos);
            break;
        }

        // Copy everything before the found s1
        result += content.substr(pos, found - pos);

        // Insert s2 instead of s1
        result += s2;

        // Move past the s1 we just replaced
        pos = found + s1.length();
    }

    // Create output file
    std::ofstream outfile((filename + ".replace").c_str());
    if (!outfile) {
        std::cerr << "Error: cannot create file '" << filename << ".replace'" << std::endl;
        return 1;
    }

    outfile << result;
    outfile.close();

    return 0;
}
