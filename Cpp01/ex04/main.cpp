/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:35:05 by jjin              #+#    #+#             */
/*   Updated: 2023/03/15 22:05:33 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void valid_args(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Error: Wrong parameter" << std::endl;
        std::cout << "Usage : " << argv[0] << " <fileName> <string1> <string2>" << std::endl;
        exit(1);
    }
    for (int i = 0; i < 3; i++)
    {
        std::string arg(argv[i]);
        if (arg == "")
        {
            std::cout << "Error: Wrong parameter" << std::endl;
            exit(1);
        }
    }
}

void prepare_buffer(std::ifstream& file, std::string& buffer)
{
    char c;

    if (!file.is_open())
    {
        std::cout << "Error: File open failed" << std::endl;
        exit(1);
    }
    while (file.good() && file.is_open())
    {
        c = file.get();
        if (c < 0)
            break;
        buffer += c;
    }
    file.close();
}

void replace_buffer(std::string& buffer, std::string& s1, std::string& s2)
{
    size_t search_start_pos = 0;
    size_t coincide_start_pos;
    
    while (true)
    {
        coincide_start_pos = buffer.find(s1, search_start_pos);
        if (coincide_start_pos == std::string::npos)
            break;
        buffer.erase(coincide_start_pos, s1.length());
        buffer.insert(coincide_start_pos, s2);
        search_start_pos = coincide_start_pos + s2.length();
    }
}


int main (int argc, char **argv)
{
    valid_args(argc, argv);

    std::string fileName(argv[1]);
    std::string string1(argv[2]);
    std::string string2(argv[3]);
    std::ifstream file(fileName);
    std::string buffer("");

    prepare_buffer(file, buffer);
    replace_buffer(buffer, string1, string2);

    std::ofstream replaced_file(fileName + ".replace");
    replaced_file << buffer;
    replaced_file.close();

    return (0);
}