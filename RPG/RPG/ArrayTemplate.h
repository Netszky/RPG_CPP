#pragma once

template<typename T>
class ArrayTemplate
{
public:
	ArrayTemplate(unsigned size = 5);
	ArrayTemplate(const ArrayTemplate& obj);

	T& operator[] (const unsigned index);
	void operator= (const ArrayTemplate& obj);

	unsigned max();
	unsigned size();
	void push();
	void remove(const unsigned index, bool ordered = false);

private:
	unsigned limit;
	unsigned initial;
	unsigned nbItem;
	T** arr;

	void expand();
	void initialize(unsigiend from);
};

template<typename T>
ArrayTemplate(unsigned size) {

}

template<typename T>
ArrayTemplate(const ArrayTemplate& obj);
~ArrayTemplate();

template<typename T>
T& operator[] (const unsigned index);

template<typename T>
void operator= (const ArrayTemplate& obj);

template<typename T>
void expand();

template<typename T>
void initialize(unsigned from

template<typename T>
unsigned max();

template<typename T>
unsigned size();

template<typename T>
void push();

template<typename T>
void remove(const unsigned index, bool ordered = false);

ArrayTemplate::ArrayTemplate()
{
}

ArrayTemplate::~ArrayTemplate()
{
}