//
//  rabbit.cpp
//  bunnis
//
//  Created by Nicholas on 17/09/2015.
//  Copyright (c) 2015 Nicholas. All rights reserved.
//

#include "rabbit.h"

rabbit& rabbit::set_sex(rabbit_sex new_sew){
    sex = new_sew;
    return *this;
}
rabbit& rabbit::set_colour(rabbit_colour new_colour){
    colour = new_colour;
    return *this;
}
rabbit& rabbit::set_age(int new_age){
    age = new_age;
    return *this;
}
rabbit& rabbit::set_name(std::string new_name){
    name = new_name;
    return *this;
}
rabbit& rabbit::set_radioactive_mutant_vampire_bunny(bool new_vampie){
    radioactive_mutant_vampire_bunny = new_vampie;
    return *this;
}

std::ostream& print_all(std::ostream& os, const rabbit& R){
    os << "Age: " << R.get_age() << "\n"
    << "Name: " << R.get_name() << "\n"
    << "Radioactive: " << R.get_radioactive_mutant_vampire_bunny() << "\n"
    << "Sex: " <<sex_string(R) << "\n"
    << "Colour: " << colour_string(R) << "\n";
    return os;
}
std::string sex_string(rabbit R)
{
    
    typedef rabbit_sex RS;
    
   
    switch (R.get_sex())
    {
        case RS::female:
            return "female";
            break;
        case RS::male:
            return "male";
            break;
        default:
            return "null";
            break;
    }
}
std::string colour_string(rabbit R)
{
    typedef rabbit_colour RC;
    switch (R.get_colour())
    {
        case RC::black:
            return "black";
            break;
        case RC::brown:
            return "brown";
            break;
        case RC::spotted:
            return "spotted";
            break;
        case RC::white:
            return "white";
            break;
        default:
            return "null";
            break;
            
    }
}