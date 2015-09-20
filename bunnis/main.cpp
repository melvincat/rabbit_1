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
#include "IO.h"
#include <fstream>
void kill_half(std::vector<rabbit> & rab, const int numberBunnies)
{
    try {
    //half the number of bunnies to kill
    int x = numberBunnies;
    x = x/2;
    //the number of bunnies
    int y = numberBunnies;
    //while the number of elements is greater than half the number of bunnies
    //after each run de increment y (to stop out of bound exceptions
    for (;rab.size() >= x; --y)
    {
       //delete elements randomly
        rab.erase(rab.begin() + Random_Number(0, y));
        throw std::runtime_error(__LINE__ + "Probaly out of bound exception");
    }
    }
    catch(std::exception err)
    {
        std::cerr << err.what();
    }
   
}
int main(int argc, const char * argv[]) {
    
    //create a vector, bunny_vec, holds rabbit objects
    std::vector<rabbit> bunny_vec;
    IO io;
    std::string message = "hello";
    io.set_message(message);
    io.write_string("/Users/nicholashilderson/Desktop/newone.txt");
    
    //create firve rabbit objects, from the class rabbit
    for (int i = 0; i < 5; i++){
        rabbit temp;
        //set these objects values
        temp.random_rabbit(temp);
        //store these objects in the vector
        bunny_vec.push_back(temp);
    }
    //while there are elements in bunny_vec and therefore alive bunnies
    while (bunny_vec.begin() != bunny_vec.end())
    {
    int male_count = 0;
    int female_count = 0;
    int radioactive_count = 0;
    for (auto x: bunny_vec)
    {
        (x.get_sex() == rabbit_sex::male) ? ++male_count : ++female_count;
        if (x.get_radioactive_mutant_vampire_bunny() == false) ++radioactive_count;
        x.set_age(x.get_age() +1);
        
    }
        int i = 0;
        //go through all the elements in bunny_vec or if the number of female
        //bunnies is higher than the original
        for (auto iter = bunny_vec.begin();
             iter != bunny_vec.end() && i <= female_count; ++iter)
        {
        
            //if the rabbit is a female and its age is above 2 and it is not a radioactive bunny
            //and there is a male
            
            if ((*iter).get_sex() == rabbit_sex::female && (*iter).get_age() >= 2
                && (*iter).get_radioactive_mutant_vampire_bunny() != false && male_count > 1)
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
                //if the ititeration is not a vampire bunny or the radio count is not equal to zero or
                //if the baby is not radioactive
                if ((*iter).get_radioactive_mutant_vampire_bunny() != false && radioactive_count > 0
                    &&baby.get_radioactive_mutant_vampire_bunny() != false)
                {
                    baby.set_radioactive_mutant_vampire_bunny(false);
                    --radioactive_count;
                }
            }
            //if the bunnies age is above 10 delete it and it is not a radioactive mutant vampire
            if ((*iter).get_age() > 10 && (*iter).get_radioactive_mutant_vampire_bunny() != false)
                bunny_vec.erase(iter);
            //if the bunny age is above 50 and it is a radioactive mutant vampire
            if ((*iter).get_age() > 50 && (*iter).get_radioactive_mutant_vampire_bunny() == false)
                bunny_vec.erase(iter);
        }
    
        //if the number of bunnies is above 1000
        if (bunny_vec.size() >= 1000) kill_half(bunny_vec, 1000);
    }
    
}
