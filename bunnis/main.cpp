//
//  main.cpp
//  bunnis
//
//  Created by Nicholas on 17/09/2015.
//  Copyright (c) 2015 Nicholas. All rights reserved.
//

#include <iostream>
#include <vector>

#include "rabbit.h"
#include "rabbit_attributes.h"
#include "Random_Number.h"

int main(int argc, const char * argv[]) {
    
    //create a vector, bunny_vec, holds rabbit objects
    std::vector<rabbit> bunny_vec;
    
    //create firve rabbit objects, from the class rabbit
    for (int i = 0; i < 5; i++){
        rabbit temp;
        //set these objects values
        temp.random_rabbit(temp);
        //store these objects in the vector
        bunny_vec.push_back(temp);
    }
    
    int male_count = 0;
    int female_count = 0;
    
    for (auto x: bunny_vec)
    {
        (x.get_sex() == rabbit_sex::male) ? ++male_count : ++female_count;
        
        x.set_age(x.get_age() +1);
    }
    //if their is a male bunny
    if (male_count > 1)
    {
        int i = 0;
        //go through all the elements in bunny_vec or if the number of female
        //bunnies is higher than the original
        for (auto iter = bunny_vec.begin();
             iter != bunny_vec.end() && i <= female_count; ++iter)
        {
        
            //if the rabbit is a female and its age is above 2
            if ((*iter).get_sex() == rabbit_sex::female && (*iter).get_age() >= 2)
            {
                //create a new "baby" rabbit
                rabbit baby;
                //set the rabbit with random names etc.
                baby.random_rabbit(baby);
                
                //set age to zero and set its colour to the colour of the mother
                baby.set_age(0);
                baby.set_colour((*iter).get_colour());
                //add one to the mother count
                ++i;
            }
        }
    }
    
    //create a while loop
}
