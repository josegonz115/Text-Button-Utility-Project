//
// Created by joseg on 3/23/2023.
//

#ifndef TEXTBOXPROJECT_FILEREADER_H
#define TEXTBOXPROJECT_FILEREADER_H
//// reads data from a file, and stores it in a vector
//template <typename T>
//class FileReader // is also a member var of Suggestion
//{
//private:
//    std::string fileName;
//    std::vector<Word> words;
//    std::ifstream fin;
//
//    void getData(std::ifstream fin);
//
//
//public:
//    FileReader();
//    FileReader(std::string fileName);
//
//    typedef std::iterator<std::input_iterator_tag, T> iterator;
//    typedef const std::iterator<std::input_iterator_tag, T> const_iterator;
//
//    iterator begin();
//    iterator end();
//
//};
//

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
