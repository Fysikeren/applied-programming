#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  double u[3] = {1.0, 2.0, 3.0};
  double v[3] = {6.0, 5.0, 4.0};
  double A[3][3] = {{1.0, 5.0, 0.0},
                    {7.0, 1.0, 2.0},
                    {0.0, 0.0, 1.0}};
  double B[3][3] = {{-2.0, 0.0, 1.0},
                    {1.0, 0.0, 0.0},
                    {4.0, 1.0, 0.0}};
  
  double w[3];
  for (int i=0; i<3; i++) {
    w[i] = u[i] - 3.0*v[i];
  }
  cout << "w = (" << w[0] << " " << w[1] << " " << w[2] << ")" << endl;

  double x[3];
  for (int i=0; i<3; i++) {
    x[i] = u[i] - v[i];
  }
  cout << "x = (" << x[0] << " " << x[1] << " " << x[2] << ")" << endl;

  double y[3] = {0,0,0};
  for (int i=0; i<3; i++) {
    for (int j=0; j<3; j++) {
      y[i] += A[i][j]*u[j];
    }
  }
  cout << "y = (" << y[0] << " " << y[1] << " " << y[2] << ")" << endl;

  double z[3], col;
  for (int i=0; i<3; i++) {
    col = 0;
    for (int j=0; j<3; j++) {
      col += A[i][j]*u[j];
    }
    z[i] = col - v[i];
  }
  cout << "z = (" << z[0] << " " << z[1] << " " << z[2] << ")" << endl;

  double C[3][3];
  for (int i=0; i<3; i++) {
    for (int j=0; j<3; j++) {
      C[i][j] = 4*A[i][j] - 3*B[i][j];
    }
  }
  cout << "C = (" << C[0][0] << " " << C[0][1] << " " << C[0][2] << "\n";
  cout << "     " << C[1][0] << " " << C[1][1] << " " << C[1][2] << "\n";
  cout << "     " << C[2][0] << " " << C[2][1] << " " << C[2][2] << ")" << endl;

  double D[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
  for (int i=0; i<3; i++) {
    for (int j=0; j<3; j++) {
      for (int k=0; k<3; k++) {
        D[i][j] += A[i][k]*B[k][j];
      }
    }
  }
  cout << "D = (" << D[0][0] << " " << D[0][1] << " " << D[0][2] << "\n";
  cout << "     " << D[1][0] << " " << D[1][1] << " " << D[1][2] << "\n";
  cout << "     " << D[2][0] << " " << D[2][1] << " " << D[2][2] << ")" << endl;

  return 0;
}