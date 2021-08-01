#include<iostream>

using namespace std;

class Matrix {
	int dim1;
	int dim2;
	int** arr;

public:
	Matrix() {
		dim1 = 0;
		dim2 = 0;
		arr = nullptr;
	}
	Matrix(int dim1, int dim2) {
		this->dim1 = dim1;
		this->dim2 = dim2;
		arr = new int*[dim1];
		for (int i = 0; i < dim1; i++) {
			arr[i] = new int[dim2] {};
		}
		for (int i = 0; i < dim1; i++) {
			for (int j = 0; j < dim2; j++) {
				cout << "\tplease,enter arr[" << i << "]" << "[" << j << "]" << endl;
				cin >> arr[i][j];
			}
		}
		cout << endl;
	}

	Matrix(const Matrix& other) {
		this->dim1 = other.dim1;
		this->dim2 = other.dim2;
		this->arr = new int*[dim1];
		for (int i = 0; i < dim1; i++) {
			this->arr[i] = new int[dim2];
		}
		for (int i = 0; i < dim1; i++) {
			for (int j = 0; j < dim2; j++) {
				this->arr[i][j] = other.arr[i][j];
			}
		}
	}

	Matrix& operator=(const Matrix& other) {

		this->dim1 = other.dim1;
		this->dim2 = other.dim2;
		this->arr = new int*[dim1];
		for (int i = 0; i < dim1; i++) {
			this->arr[i] = new int[dim2];
		}
		for (int i = 0; i < dim1; i++) {
			for (int j = 0; j < dim2; j++) {
				this->arr[i][j] = other.arr[i][j];
			}
		}
		return *this;
	}
	void set_arr() {
		arr = new int*[dim1];
		for (int i = 0; i < dim1; i++) {
			arr[i] = new int[dim2] {};
		}
	}
	void set_ij(int i, int j, int value) {
		arr[i][j] = value;
	}
	void set_dim1(int a) {
		dim1 = a;
	}
	void set_dim2(int a) {
		dim2 = a;
	}
	int get_dim1() {
		return dim1;
	}
	int get_dim2() {
		return dim2;
	}
	int get_ij(int i, int j) {
		return arr[i][j];
	}
	void print() {
		for (int i = 0; i < dim1; i++) {
			for (int j = 0; j < dim1; j++) {
				cout << arr[i][j] << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}
	void _delete() {
		for (int i = 0; i < dim1; i++) {
			delete[] arr[i];
		}
		delete[] arr;
	}
};
Matrix operator+(Matrix& left, Matrix& right) {
	Matrix temp;
	if (left.get_dim1() == right.get_dim1() && left.get_dim2() == right.get_dim2()) {

		temp.set_dim1(left.get_dim1());
		temp.set_dim2(left.get_dim2());
		temp.set_arr();
		for (int i = 0; i < temp.get_dim1(); i++) {
			for (int j = 0; j < temp.get_dim2(); j++) {
				temp.set_ij(i, j, left.get_ij(i, j) + right.get_ij(i, j));
			}
		}

	}
	return temp;
}
int main() {
	Matrix A(2, 2);
	A.print();
	Matrix B = A;
	B.print();
	Matrix C;
	C = A;
	C.print();
	Matrix D;
	D = A + B;
	D.print();

	return 0;
}