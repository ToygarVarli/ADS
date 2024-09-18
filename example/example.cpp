// SPDX-License-Identifier: MIT
/**
   Copyright (c) 2015 - 2021 Beckhoff Automation GmbH & Co. KG
 */

#include "AdsWrapper.h"
#include <array>
#include <cstring>
#include <iostream>
#include <iomanip>
#include "AdsLib.h"
#include "AdsNotificationOOI.h"
#include "AdsVariable.h"


int main()
{
    try {

AdsWrapper wrapper;
  wrapper.writeValue(std::cout,1);


    } catch (const AdsException& ex) {
        std::cout << "Error: " << ex.errorCode << "\n";
        std::cout << "AdsException message: " << ex.what() << "\n";
    } catch (const std::runtime_error& ex) {
        std::cout << ex.what() << '\n';
    }
    std::cout << "Hit ENTER to continue\n";
    std::cin.ignore();
}
