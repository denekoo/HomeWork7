#pragma once
#include <exception>
#include <string>
class bad_range : public std::exception
{
private: 
    std::string m_error;
public:
    bad_range(std::string error): m_error(error) {}

    virtual const char* what() const noexcept
    {
        return m_error.c_str();
    }
};

class bad_length : public std::exception
{
private:
    std::string m_error;
public:
    bad_length(std::string error) : m_error(error) {}

    virtual const char* what() const noexcept
    {
        return m_error.c_str();
    }
};
class LengthCorrector //Класс для изменения длины массива вручную
{
private:
    int m_newInt;

public:

    int ManualIndex() //Просим пользователя поправить длину индекса вручную
    {
        std::cout << "To fix this problem enter a new index: \n";
        std::cin >> m_newInt;
        return m_newInt;
    }
};
