//
// Created by admpaw on 04.01.2023.
//

#include "Utils.h"

const std::map<int, std::string> Utils::causeNames = {
        {Utils::Cause::METHOD_NOT_IMPLEMENTED, "Method not implemented"}
};

void Utils::error(const std::string &reason, Cause cause) {
    printf("\n[%s]: %s", reason.c_str(), causeNames.find(cause)->second.c_str());
    exit(1);
}
