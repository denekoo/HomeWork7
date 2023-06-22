#ifndef ARRAYINT_H
#define ARRAYINT_H
#include <cassert> // для assert()
#include <iostream>
#include<string>
#include "Exceptions.h"

class ArrayInt
{
private:
	int m_length;
	int* m_data;
public:
	ArrayInt():
		m_length(0), m_data(nullptr)
	{ }

	ArrayInt(int length) :
		m_length(length)
	{		
		if (length <= 0)
		{
			throw bad_length(" bad array length! \n");
		}
		
			m_data = nullptr;
			m_data = new int[length];
	}

	~ArrayInt()
	{
		delete[] m_data;
	}

	void erase()
	{
		delete[] m_data;
		// присваиваем указателю m_data значение nullptr, чтобы не было висячего указателя
		m_data = nullptr;
		m_length = 0;

	}
	int& operator [](const int index)
	{

			if (index >= 0 && index < m_length)
				return m_data[index];
			else
				throw bad_length("bad length in reloaded index \n");

	}

	int getLength() { return m_length; }

	void reAllocate(int newLength)
	{
		erase();
		
		if (newLength <= 0)
			return;
		m_data = new int[newLength];
		m_length = newLength;
	}

	void resize(int newLength)
	{
		if (newLength == m_length)
			return;

		if (newLength <= 0)
		{
			erase();
			return;
		}
	int *data = new int[newLength];
	if (m_length > 0)
	{
		int elementsToCopy = (newLength > m_length) ? m_length : newLength;

		for (int index=0; index < elementsToCopy; ++index)
		{
			data[index] = m_data[index];
		}
	}
		delete m_data;
		m_data = data;
		m_length = newLength;
	}
	void insertBefore(int value, int index)
	{
		if (index >= 0 && index <= m_length)
		{
			int* data = new int[m_length + 1];

			for (int before = 0; before < index; ++before)
				data[before] = m_data[before];

			data[index] = value;

			for (int after = index; after < m_length; ++after)
				data[after + 1] = m_data[after];

			delete[] m_data;
			m_data = data;
			++m_length;
		}
		else
			throw bad_length("bad length in insertBefore \n");
		}

	void remove(int index)
	{
		if (m_length == 1)
			erase();
		if (index >= 0 && index <= m_length)
		{
			int* data = new int[m_length - 1];

			for (int before = 0; before < index; ++before)
				data[before] = m_data[before];

			for (int after = index + 1; after < m_length; ++after)
				data[after - 1] = m_data[after];
			
			delete[]  m_data;
			m_data = data;
			--m_length;
		}
		else
		throw bad_range("bad index in remove index \n");
	}

	void insertAtBeginning(int value) { insertBefore(value, 0); }
	void insertAtEnd(int value) { insertBefore(value,m_length); }

};

#endif
