#include <vector>
#include <fstream>
#include <math.h>

class Matrix {
  public:
    Matrix(std::string file);
    friend std::ostream &operator<<(std::ostream &out, const Matrix &m);
    friend bool operator==(const Matrix & m1, const Matrix & m2);
    std::vector<int> operator[](int i);
    friend Matrix operator*(const Matrix & m, const int multiplier);
    friend Matrix operator+(const Matrix & m1, const Matrix & m2);
    friend Matrix operator-(const Matrix & m1, const Matrix & m2);
    friend Matrix operator*(const Matrix & m1, const Matrix & m2);
  private:
    std::vector<std::vector<int>> v;
};

Matrix::Matrix(std::string file) {
      std::ifstream fin;
      fin.open(file);
      int row,col;
      fin >> row >> col;
      v.resize(row, std::vector<int>(col));
      for(int i = 0; i < row; i++){
        for(int j = 0 ; j < col ; j++){
          fin >> v[i][j];
      }
    }
}

std::ostream &operator<<(std::ostream &out, const Matrix &m) {
  if (!m.v.size()) {
    return out;
  }
  for(int i = 0; i < m.v.size(); i++){
    out << "|";
    for(int j = 0 ; j < m.v[i].size() ; j++){
      std::string space = "";
      for (int k=0; k < 3 - log10 (m.v[i][j]); k++) {
        space += " ";
      }
      out << space << m.v[i][j];
    }
    out << "|" << std::endl;
  }
  out << std::endl;
  return out;

}

bool operator==(const Matrix & m1, const Matrix & m2) {
    for(int i = 0; i < m1.v.size(); i++){
        for(int j = 0 ; j < m1.v[i].size() ; j++){
          if (m1.v[i][j] != m2.v[i][j]) {
            return false;
          }
      }
    }

    return true;
}

std::vector<int> Matrix::operator[](int i) {
  return v[i];
}

Matrix operator*(const Matrix & m, const int multiplier) {
  Matrix temp = m;
  for (int i=0; i< temp.v.size(); i++) {
    for (int j=0; j < temp.v[i].size(); j++) {
      temp.v[i][j] *= multiplier;
    }
  }
  return temp;
}

Matrix operator+(const Matrix & m1, const Matrix & m2) {
  Matrix temp = m1;
  for (int i=0; i< temp.v.size(); i++) {
    for (int j=0; j < temp.v[i].size(); j++) {
      temp.v[i][j] += m2.v[i][j];
    }
  }

  return temp;
}

Matrix operator-(const Matrix & m1, const Matrix & m2) {
  Matrix temp = m1;
  for (int i=0; i< temp.v.size(); i++) {
    for (int j=0; j < temp.v[i].size(); j++) {
      temp.v[i][j] -= m2.v[i][j];
    }
  }
  return temp;
}

Matrix operator*(const Matrix & m1, const Matrix & m2) {
  Matrix temp = m1;
  int r1 = m1.v.size();
  int c1 = m1.v[0].size();
  int r2 = m2.v.size();
  int c2 = m2.v[0].size();
  temp.v.clear();
  if (c1 == r2) {
    temp.v.resize(r1, std::vector<int> (c2));
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++) {
                temp.v[i][j] = 0;
                for (int k = 0; k < r2; k++) {
                    temp.v[i][j] += m1.v[i][k] * m2.v[k][j];
                }
            }
        }
  } else {
        std::cout << "Empty" << std::endl;
  }
  return temp;
}

