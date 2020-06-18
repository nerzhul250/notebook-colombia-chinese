// for std::complex, std::real, std::imag 
#include <complex>
int main() 
{     
  // defines the complex number: (10 + 2i) 
  std::complex<double> mycomplex(10.0, 2.0); 
  
  // prints the real part using the real function 
  cout << "Real part: " << real(mycomplex) << endl; 
  cout << "Imaginary part: " << imag(mycomplex) << endl; 
  
  // defines the complex number: (3.0+4.0i)
  std::complex<double> mycomplex (3.0, 4.0); 
  
  // prints the absolute value of the complex number 
  cout << "The absolute value of " << mycomplex << " is: "; 
  cout << abs(mycomplex) << endl; 
    
  // prints the argument of the complex number 
  cout << "The argument of " << mycomplex << " is: "; 
  cout << arg(mycomplex) << endl; 
  
  cout << "The complex whose magnitude is " << 2.0; 
  cout << " and phase angle is " << 0.5; 
    
  // use of polar() 
  cout << " is " << polar (2.0, 0.5) << endl; 
  
  // initializing the complex: (3.0+4.0i) 
  std::complex<double> mycomplex (3.0, 4.0); 
  
  // use of norm() 
  cout << "The norm of " << mycomplex << " is "   << norm(mycomplex) <<endl; 
  std::complex<double> mycomplex (10.0,2.0); 
  
  cout << "The conjugate of " << mycomplex << " is: "; 
    
  // use of conj() 
  cout << conj(mycomplex) << endl; 
  return 0; 
} 
