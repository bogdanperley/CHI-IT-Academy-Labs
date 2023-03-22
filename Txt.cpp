#include "Txt.h"
#include <fstream>
#include <iostream>

namespace l1 
{

Txt::Txt(const std::string& file_name) {
	std::ifstream file(file_name);
	if (!file) {
		std::cout << "Error: Failed to open file\n";

		return;
	}
	size_ = count_lines(file);
	file.seekg(0);
	data_ = new std::string[size_];
	for (size_t i = 0; i < size_; i++) {
		std::getline(file, data_[i]);
	}
}

Txt::Txt(const Txt& copy)
	: data_{ new std::string[copy.size_] }, size_{ copy.size_ } {
	for (size_t i = 0; i < size_; i++) {
		data_[i] = copy.data_[i];
	}
}

Txt::Txt(Txt&& mv) : data_{ mv.data_ }, size_{ mv.size_ } {
	mv.data_ = nullptr;
	mv.size_ = 0;
}

Txt& Txt::operator=(const Txt& obj) {
	if (this == &obj) {
		return *this;
	}
	delete[] data_;
	data_ = new std::string[obj.size_];
	size_ = obj.size_;
	for (size_t i = 0; i < size_; i++) {
		data_[i] = obj.data_[i];
	}
	return *this;
}

Txt& Txt::operator=(Txt&& obj) {
	if (this == &obj) {
		return *this;
	}
	delete[] data_;
	data_ = obj.data_;
	size_ = obj.size_;
	obj.data_ = nullptr;
	obj.size_ = 0;
	return *this;
}

Txt::~Txt() { delete[] data_; }

std::size_t l1::Txt::size() const { return size_; }

size_t Txt::count_lines(std::ifstream& file) {
	size_t count{ 0 };
	std::string line;

	while (std::getline(file, line)) {
		++count;
	}
	return count;
}
}
