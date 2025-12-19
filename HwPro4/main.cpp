#include <iostream>
class Document {
	std::string m_content;
public:
	void insert(size_t pos, const std::string& str) {

	};
	void erase(size_t pos, size_t count) {

	};
	void replace(size_t pos, size_t count, const std::string& str) {

	};
	const std::string& text() const {
		return m_content;
	};
};


int main() {
	std::string text = "Hello, World!";
	std::cout << text[2] << std::endl;
	return 0;
};