//
//  Random_Number.cpp
//  bunnis
//
//  Created by Nicholas on 17/09/2015.
//  Copyright (c) 2015 Nicholas. All rights reserved.
//

#include "Random_Number.h"
#include <random>
int Random_Number(int min, int max){
    std::random_device rd;
    std::uniform_int_distribution<> distr(min, max);
    return distr(rd);
}