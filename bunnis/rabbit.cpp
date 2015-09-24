//
//  rabbit.cpp
//  bunnis
//
//  Created by Nicholas on 17/09/2015.
//  Copyright (c) 2015 Nicholas. All rights reserved.
//

#include "rabbit.h"
#include "Random_Number.h"
#include <vector>
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
//generates a random rabit
rabbit& rabbit::random_rabbit(rabbit &temp)
{
    temp.set_age(Random_Number(0, 10));
    temp.set_colour(static_cast<rabbit_colour>(Random_Number(0, 4)));
    temp.set_radioactive_mutant_vampire_bunny(Random_Number(0, 50));
    temp.set_sex(static_cast<rabbit_sex>(Random_Number(0, 1)));
    temp.set_name(random_name(sex_string(temp)));
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
std::vector<std::string> rabbit::rabbit_vector()
{
    std::vector<std::string> temp_vec;
    
    temp_vec.push_back("Name: " + name);
    temp_vec.push_back("Colour: " + colour_string(*this));
    temp_vec.push_back("Radioactive: " + std::to_string(radioactive_mutant_vampire_bunny));
    temp_vec.push_back("Sex: " + sex_string(*this));
    temp_vec.push_back("Age: " + std::to_string(age));
    
    return temp_vec;

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
std::string random_name(std::string sex){
    if (sex=="male")
    {
        switch (Random_Number(0, 5))
        {
            case 0:
                return "Sam";
                break;
            case 1:
                return "john";
                break;
            case 2:
                return "bob";
                break;
                
            case 3:
                return "Tim";
                break;
                
            case 4:
                return "Nicholas";
                break;
                
            case 5:
                return "Josh";
                break;
            default:
                return "null";
                break;
        }
    }
    else
    {
        switch (Random_Number(0, 5))
        {
            case 0:
                return "Emilly";
                break;
            case 1:
                return "Georgia";
                break;
            case 2:
                return "Alice";
                break;
            case 3:
                return "Paige";
                break;
            case 4:
                return "Sally";
                break;
            case 5:
                return "Meg";
                break;
            default:
                return "null";
                break;
        }
    }
    
}