//
//  rabbit.h
//  bunnis
//
//  Created by Nicholas on 17/09/2015.
//  Copyright (c) 2015 Nicholas. All rights reserved.
//

#ifndef __bunnis__rabbit__
#define __bunnis__rabbit__

#include <stdio.h>
#include <string>
#include <iostream>
#include "rabbit_attributes.h"
#include "Random_Number.h"
class rabbit{
    friend std::ostream& print_all(std::ostream& os, const rabbit& R);
    friend std::string sex_string(rabbit R);
    friend std::string colour_string(rabbit R);
    friend std::string random_name(std::string sex);

public:
    rabbit() = default;
    rabbit(rabbit_sex S, rabbit_colour C, int A, std::string N, bool V) :
    sex(S), colour(C), age(A), name(N), radioactive_mutant_vampire_bunny(V){};
    
    //generates a random rabbit
    rabbit& random_rabbit(rabbit &temp);
    
    rabbit& set_sex(rabbit_sex new_sew);
    rabbit& set_colour(rabbit_colour new_colour);
    rabbit& set_age(int new_age);
    rabbit& set_name(std::string name);
    rabbit& set_radioactive_mutant_vampire_bunny(bool new_vampie);
    
    rabbit_sex get_sex() const {return sex;};
    rabbit_colour get_colour() const {return colour;};
    int get_age() const {return age;};
    std::string get_name() const {return name;};
    bool get_radioactive_mutant_vampire_bunny() const {return radioactive_mutant_vampire_bunny;};

private:
    rabbit_sex sex = rabbit_sex::male;
    rabbit_colour colour = rabbit_colour::black;
    int age = 0;
    std::string name = "null";
    bool radioactive_mutant_vampire_bunny = true;
};

std::ostream& print_all(std::ostream& os, const rabbit& R);
std::string sex_string(rabbit R);
std::string colour_string(rabbit R);
std::string random_name(std::string sex);

#endif /* defined(__bunnis__rabbit__) */
