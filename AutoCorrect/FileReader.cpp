//
// Created by joseg on 3/23/2023.
//
#ifndef TEXTBOXPROJECT_FILEREADER_CPP
#define TEXTBOXPROJECT_FILEREADER_CPP

//#include "FileReader.h"
//
//template<typename T>
//void FileReader<T>::getData(std::ifstream fin)
//{
//    // read data from file
//    // store data in vector
//    while(!fin.eof())
//    {
//        Word word;
//        fin >> word;
//        words.push_back(word);
//    }
//}
//
//template<typename T>
//FileReader<T>::FileReader()
//{
//
//}
//
//template<typename T>
//FileReader<T>::FileReader(std::string fileName)
//{
//
//}
//
//template<typename T>
//FileReader::iterator FileReader<T>::begin()
//{
//    return FileReader::iterator();
//}
//
//template<typename T>
//FileReader::iterator FileReader<T>::end()
//{
//    return FileReader::iterator();
//}

#include "FileReader.h"


template<typename T>
FileReader<T>::FileReader()
{}

template<typename T>
FileReader<T>::FileReader(const std::string& filename)
{
    getData(filename);
}
template<typename T>
void FileReader<T>::getData(const std::string& filename)
{
    std::ifstream fin;
    fin.open(filename);
    if(fin.fail())
        exit(28);
    T next;
    while(fin >> next)
    {
        data.push_back(next);
    }
    fin.close();
}

template<typename T>
typename FileReader<T>::iterator FileReader<T>::end()
{
    return data.end();
}

template<typename T>
typename FileReader<T>::iterator FileReader<T>::begin()
{
    return data.begin();
}

template <typename T>
std::vector<T> FileReader<T>::getData() const{
    return data;
}


#endif //TEXTBOXPROJECT_FILEREADER_CPP