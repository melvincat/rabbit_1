//
//  writer.cpp
//  bunnis
//
//  Created by Nicholas on 20/09/2015.
//  Copyright (c) 2015 Nicholas. All rights reserved.
//

#include "writer.h"
#include <fstream>
#include <iostream>
/*
class writer{
    typedef std::vector<std::string> str_vec;
public:
    writer (std::ostream::open_mode mode) : file_mode(mode) {};
    
    
    void set_path();
    void stream(std::string &string_out);
    void stream(std::vector<std::string> &output_vec);

private:
    void set_variables();
    bool valid_path(std::string tempPath);
    std::ostream & write(std::string &output, std::ostream & out);
    std::string path = "null";
    std::ostream::open_mode file_mode;
    int is_set_up = 0;
};*/
void writer::set_variables()
{
    if (is_set_up == 0)
    {
        //set the path
        set_path();
        ++is_set_up;
    }
}
void writer::stream(std::string &string_out)
{
    set_variables();
    std::ofstream output(path, file_mode);
    write(string_out, output);
}
void writer::stream(std::vector<std::string> &output_vec)
{
    set_variables();
    std::ofstream output(path, file_mode);
    for (auto string_out: output_vec)
    {
        write(string_out, output);
    }
}
std::ostream & writer::write(std::string &output, std::ostream & out)
{
    out << output << std::endl;
    return out;
}
void writer::set_path()
{
    //create a tempory path
    std::string tempPath;
    std::cout << "Enter a path for the output:" << std::ends;
    //set the path
    do {
        //clear it if it hasn't already
        tempPath.clear();
        //get a path
        std::cout << std::flush;
        std::getline(std::cin, tempPath);
    
    } while (!valid_path(tempPath)); //loop till they enter a valid path
    //if it is valid set the path of the object
    path = tempPath;
}

bool writer::valid_path(std::string tempPath)
{
    //create a tempory stream to test if you can use the path
    std::ofstream output(tempPath);
    
    //if the path is valid
    if (output.is_open())
    {
        //close the stream
        output.close();
        //return true
        return true;
    } else
    {
        //close the stream
        output.close();
        //tell the user the path isn't valid
        std::cerr << "Not a valid path, try again." << std::endl;
        //return false
        return false;
    }
}
