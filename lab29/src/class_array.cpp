#include "class_array.h"


//Array_Desserts<T>::Array_Desserts() {
//	size = 3;
//	ptr = new Dessert * [size];
//	for (size_t i = 0; i < size; i++) {
//		ptr[i] = new Dessert;
//	}
//
//	std::string nullname = "0";
//	std::string nulltaste = "0";
//	for (size_t i = 0; i < size; i++) {
//		ptr[i]->setter(false, nullname, 0, 0, 0, 0, 0, nulltaste);
//	}
//}


//Array_Desserts<T>::Array_Desserts(size_t sizearr) {
//	size = sizearr;
//	ptr = new Dessert * [size];
//	for (size_t i = 0; i < size; i++) {
//		ptr[i] = new Dessert;
//	}
//
//	std::string nullname = "0";
//	std::string nulltaste = "0";
//	for (size_t i = 0; i < size; i++) {
//		ptr[i]->setter(false, nullname, 0, 0, 0, 0, 0, nulltaste);
//	}
//}

template <class T>
void Array_Desserts<T>::setarray(int index, bool glucose, std::string name, double weight, double nkkal, double nproteins, double nfats, double ncarb, std::string taste) {
	ptr[index]->setter(glucose, name, weight, nkkal, nproteins, nfats, ncarb, taste);
}


//template <class T>
//Array_Desserts<T>::~Array_Desserts() {
//	for (size_t i = 0; i < size; i++) {
//		delete ptr[i];
//	}
//	delete[] ptr;
//}


template <class T>
void Array_Desserts<T>::delete_el(size_t index) {
	if (this->size == 0) return;
	Dessert * *new_array = new Dessert * [size - 1];
	if (index >= size) index = this->size - 1;
	memcpy(new_array, this->ptr, index * sizeof(Dessert*));
	memcpy(new_array + index, this->ptr + index + 1, (this->size - index - 1) * sizeof(Dessert*));
	delete ptr[index];
	delete[] this->ptr;
	this->ptr = new_array;
	this->size--;
}


template <class T>
void Array_Desserts<T>::add_el(size_t index, T * smth) {
	Dessert** new_Dessert = new Dessert * [size + 1];
	int n = 0;
	for (size_t i = 0; i < size + 1; i++) {
		new_Dessert[i] = this->ptr[n];
		if (i == index) {
			new_Dessert[i] = smth;
			n--;
		}
		n++;
	}
	delete[] this->ptr;
	this->ptr = new_Dessert;
	this->size++;
}


//template <class T>
//void Array_Desserts<T>::searching_by_min_weight_and_taste() {
//	double min_weight = -1;
//	size_t i_min = 0;
//	std::string taste_for_finding = "sugar";
//	for (size_t i = 0; i < size; i++) {
//		if ((ptr[i]->getter_taste() == taste_for_finding) && (min_weight > ptr[i]->getter_weight())) {
//			i_min = i;
//			min_weight = ptr[i]->getter_weight();
//		}
//	}
//	if (min_weight != -1) {
//		std::cout << "Finding dessert:\n";
//		std::cout << ptr[i_min];
//	}
//	else {
//		std::cout << "Dessert not found\n";
//	}
//}


//template <class T>
//void Array_Desserts<T>::search_by_index(int index) {
//	for (size_t i = 0; i < size; i++) {
//		if (i == index) {
//			std::cout << *ptr[i];
//			std::cout << std::endl;
//		}
//	}
//
//}


//template <class T> void Array_Desserts<T>::showarray() {
//	for (size_t i = 0; i < size; i++) {
//		search_by_index(i);
//	}
//}


//template <class T>
//void Array_Desserts<T>::Array_Desserts::set_information_to_array() {
//	bool is_glucose_array[3] = { true, false, true };
//	char name_dessert_array[3][20] = { "cupcake", "donut", "eclair" };
//	double weight_array[3] = { 500, 200, 236 };
//	double kkal_array[3] = { 1200, 1000, 500 };
//	double proteins_array[3] = { 230, 120, 320 };
//	double fats_array[3] = { 20, 23, 50 };
//	double carbohydrates[3] = { 123, 321, 231 };
//	char taste_array[3][20] = { "vanil", "sugar", "creme" };
//
//	for (size_t i = 0; i < size; i++) {
//		ptr[i]->setter(is_glucose_array[i], name_dessert_array[i], weight_array[i], kkal_array[i], proteins_array[i], fats_array[i], carbohydrates[i], taste_array[i]);
//	}
//}


template <class T>
Array_Desserts<T>::Array_Desserts(const Array_Desserts & arrayToCopy) // ����������� �����
	:size(arrayToCopy.size)              // ������������� ������� �������
{
	ptr = new Dessert * [size]; // �������� ����� � ������ ��� �������

	for (size_t ix = 0; ix < size; ix++)
		ptr[ix] = arrayToCopy.ptr[ix]; // ��������� ������ ���������� ������� arrayToCopy
}

//template <class T>
//T*& Array_Desserts<T>::operator[](size_t index)
//{
//	return ptr[index];
//}

//template <class T>
//Array_Desserts<T> &Array_Desserts<T>::operator+=(T * smth)
//{
//	T** newdessert = new T * [size + 1];
//	memcpy(newdessert, ptr, size * sizeof(T*));
//	newdessert[size] = smth;
//	delete[] this->ptr;
//	this->ptr = newdessert;
//	this->size++;
//	return *this; // ��������� ����� �������������� ���������
//}


template <class T>
Array_Desserts<T> &Array_Desserts<T>::operator-(size_t index)
{
	if (this->size == 0) return *this;
	T * *new_array = new T * [size - 1];
	if (index >= size) index = this->size - 1;
	memcpy(new_array, this->ptr, index * sizeof(T*));
	memcpy(new_array + index, this->ptr + index + 1, (this->size - index - 1) * sizeof(T*));
	delete[] this->ptr;
	this->ptr = new_array;
	this->size--;
	return *this;
}


template <class T>
const Array_Desserts<T> & Array_Desserts<T>::operator=(const Array_Desserts & right)
{
	if (&right != this) // ����� �� ����������� ����������������
	{
		if (size != right.size)
		{
			delete[] ptr; // ���������� ������������
			size = right.size; // ���������� ������ ������ �������
			ptr = new T * [size]; // �������� ������ ��� ���������� ������
		}

		for (size_t ix = 0; ix < size; ix++)
			ptr[ix] = right.ptr[ix]; // ����������� ������
	}

	return *this; // ��������� ������������� ������������, �������� x = t = e
}


template <class T>
bool Array_Desserts<T> ::operator==(const Array_Desserts<T> & right) const
{
	if (size != right.size)
		return false; // ������� � ������ ����������� ���������
	for (size_t ix = 0; ix < size; ix++)
		if (ptr[ix] != right.ptr[ix])
			return false; // ������� �� �����

	return true; // ������� �����
}


//template <class T>
//void Array_Desserts<T>::read_from_file(std::string filename)
//{
//	std::ifstream myfile;
//	myfile.open(filename);
//	if (myfile.is_open()) {
//		for (size_t i = 0; i < this->size; i++) {
//			if (!myfile.eof()) {
//				std::string buff;
//				std::getline(myfile, buff);
//				ptr[i]->from_string(buff);
//			}
//		}
//	}
//	else {
//		myfile.close();
//		return;
//	}
//	myfile.close();
//}

// ������������� �������� �����, ��� ����� �������� ������� � ����������
//istream& operator>> (istream& input, Array_Desserts& obj)
//{
//	for (int ix = 0; ix < obj.size; ix++)
//		input >> obj.ptr[ix]->setter; // ��������� ������ ������� obj
//	return input; // ��������� ������������� ����, ���� cin >> x >> y >> z >> ...
//}

// ������������� �������� ������ ��� ������ Array (����� ��������� ������� �� �����)
//template <class T>
//ostream& operator<< (ostream & output, const Array_Desserts<T> & obj)
//{
//	for (size_t ix = 0; ix < obj.size; ix++)
//	{
//		output << *obj.ptr[ix];
//		output << std::endl;
//	}
//
//	output << std::endl; // ������� ������� �� ����� ������
//
//	return output; // ��������� ������������� �����, ���� cout << x << y << z << ...
//}


template <class T>
void Array_Desserts<T>::write_to_file(std::string filename, Array_Desserts smth) {
	std::ofstream myfile;
	myfile.open(filename);
	if (myfile.is_open()) {
		for (size_t i = 0; i < size; i++) {
			std::string tmp = smth[i]->to_string();
			myfile << tmp;
		}
	}
	myfile.close();
}

