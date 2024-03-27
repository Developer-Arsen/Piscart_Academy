#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <unordered_map>
typedef std::map<std::string, std::string> FIELD;
typedef std::vector<FIELD> ObjectProto;
typedef std::vector<ObjectProto> ObjectsProto;
typedef std::vector<std::string> valueProto;

using DynamicObject = std::unordered_map<std::string, std::string>;

int main () {
    std::ifstream file("example.txt");
    FIELD prop;
    DynamicObject objtest;
    std::vector<DynamicObject> objects;
    if (!file.is_open()) {
        std::cerr << "error opening file" << std::endl;
        return 1;
    }
    std::string line;
    valueProto fields;
    valueProto values;
    int count = 0 ;
    int i = 0;
    int work_flag = 0;
    int key_get_flag = 0;
    while (std::getline(file,line)) {
        i = 0;
        key_get_flag = 0;
        std::string field = "";
        std::string value = "";
        while (line[i]) {
            if (line[i] == '{') {
                work_flag = 1;
                break;
            }
            if (work_flag) {
                if (line[i] == ':') {
                    fields.push_back(field);
                    key_get_flag = 1;
                    i++;
                }
                if (line[i] >= 'a' && line[i] <= 'z' || line[i] >= 'A' && line[i] <= 'Z' || line[i] >= '0' && line[i] <= '9' || line[i] == ' ' ) {
                    if (field.empty() && line[i] == ' ') {}
                    else {
                        field += line[i];
                        if (key_get_flag ) {
                            if (value.empty() && line[i] == ' ') {}
                            else value += line[i];
                        }
                    }
                }
                if (key_get_flag && line[i+1] == '\0') {
                    values.push_back(value);
                }
            }
            if (line[i] == '}') {
                work_flag = 0;
                objtest = {};
                for (int i = 0 ; i < fields.size(); i++) {
                    objtest[fields[i]] = values[i];
                }
                objects.push_back(objtest);
                values.clear();
                fields.clear();
                break;
            }
            ++i;
        }
    }
    for (auto& obj : objects) {
        std::cout << obj["Name"];
    }
    file.close();
}