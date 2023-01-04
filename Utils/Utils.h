//
// Created by admpaw on 04.01.2023.
//

#ifndef AICAPROJECT_UTILS_H
#define AICAPROJECT_UTILS_H

#include <map>
#include <string>

class Utils {
public:
    enum Cause {
        METHOD_NOT_IMPLEMENTED
    };

    static const std::map<int, std::string> causeNames;

    static void error(const std::string &reason, Cause cause);
};


#endif //AICAPROJECT_UTILS_H
