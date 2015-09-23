//
//  writer.h
//  bunnis
//
//  Created by Nicholas on 20/09/2015.
//  Copyright (c) 2015 Nicholas. All rights reserved.
//

#ifndef __bunnis__writer__
#define __bunnis__writer__

#include <stdio.h>
#include <vector>
#include <fstream>
#include <string>
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
};

#endif /* defined(__bunnis__writer__) */
