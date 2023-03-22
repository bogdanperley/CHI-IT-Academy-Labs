#pragma once
#include <fstream>
#include <string>

namespace l1 {
	class Txt {
	public:
		Txt() = default;
		Txt(const std::string& file);
		Txt(const Txt& copy);
		Txt(Txt&& mv);
		~Txt();
		Txt& operator=(const Txt& obj);
		Txt& operator=(Txt&& obj);
		std::size_t size() const;

	private:
		size_t count_lines(std::ifstream& file);
		std::string* data_{};
		std::size_t size_{};
	};

} 