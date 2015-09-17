//
//  main.cpp
//  bunnis
//
//  Created by Nicholas on 17/09/2015.
//  Copyright (c) 2015 Nicholas. All rights reserved.
//

#include <iostream>
#include <vector>
#include <random>
#include "rabbit.h"
#include "rabbit_attributes.h"
inline int Random_Number(int min, int max){
    std::random_device rd;
    std::uniform_int_distribution<> distr(min, max);
    return distr(rd);
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
int main(int argc, const char * argv[]) {
    
    //create a vector, bunny_vec, holds rabbit objects
    std::vector<rabbit> bunny_vec;
    
    //create firve rabbit objects, from the class rabbit
    for (int i = 0; i < 5; i++){
        rabbit temp;
        //set these objects values
        temp.set_age(Random_Number(0, 10));
        temp.set_colour(static_cast<rabbit_colour>(Random_Number(0, 4)));
        temp.set_radioactive_mutant_vampire_bunny(Random_Number(0, 50));
        temp.set_sex(static_cast<rabbit_sex>(Random_Number(0, 1)));
        temp.set_name(random_name(sex_string(temp)));
        
        //store these objects in the vector
        bunny_vec.push_back(temp);
    }
    for (auto x: bunny_vec)
    {
        print_all(std::cout, x);
    }
    //create a while loop
}
