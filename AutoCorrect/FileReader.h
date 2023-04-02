//
// Created by joseg on 3/23/2023.
//

#ifndef TEXTBOXPROJECT_FILEREADER_H
#define TEXTBOXPROJECT_FILEREADER_H

#include <vector>
#include <fstream>
#include <string>
#include <iterator>

template<typename T>
class FileReader : public std::iterator<std::random_access_iterator_tag, T>
{
private:
    void getData(const std::string& filename);
    std::vector<T> data;
public:
    typedef typename std::vector<T>::iterator iterator;
    FileReader();
    FileReader(const std::string& filename);
    iterator begin();
    iterator end();

    //getter for data
    std::vector<T> getData() const;

};
#include "FileReader.cpp"
#endif //TEXTBOXPROJECT_FILEREADER_H
