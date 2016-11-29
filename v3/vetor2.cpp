#include <cmath> 
#include <exception>

using namespace std;

class VetorException: public exception
{
	private:
		char* msg;
	public:
		VetorException(char* aMSg)	{
			this->msg = aMSg;
		
	}

	const char* what() const throw(){

		return msg;

	}
};



template<typename T>
class Vetor {

	public:
		T x,y,z;
		Vetor() : x(T(0)),y(T(0)),z(T(0)) {}
		Vetor(T xx) : x(xx),y(xx),z(xx) {}
		Vetor(T xx, T yy, T zz) : x(xx),y(yy),z(zz) {}
		

		Vetor<T> operator*(const float &c){

		return Vetor<T>(this->x * c,this->y * c,this->z * c);
		
		}


		Vetor<T> operator*(const Vetor<T> &v){

			return Vetor<T>( ((this->y * v.z) - (this->z * v.y)) 
					 , ((this->x * v.z) - (this->z * v.x)) ,
					 ((this->x * v.y) - (this->y * v.x)) 
				  );
		}

		Vetor<T> operator*=(const Vetor<T> &v){

			 Vetor<T> d( ((this->y * v.z) - (this->z * v.y)) 
							 , ((this->x * v.z) - (this->z * v.x)) ,
							 ((this->x * v.y) - (this->y * v.x)) 
						  );

			 this->x = d.x;
			 this->y = d.y;
			 this->z = d.z;
			 return *this;
		}

		Vetor<T> operator*=(const float &c){

			 x *= c;
			 y *= c;;
			 z *= c;;
			 return *this;
		}

		Vetor<T> operator-(const Vetor<T> &v){

			return Vetor<T>(this->x - v.x,this->y - v.y,this->z - v.z);
		}

		Vetor<T> operator-(){

			return Vetor<T>( -this->x, -this->y ,-this->z);
		}

		Vetor<T> operator-(const T &c){

			throw VetorException("Operador não aplicável");

		}

		Vetor<T> operator-=(const Vetor<T> &v){

			x -=  v.x;
			y -= v.y;
			z -= v.z;
			return *this;
		}


		Vetor<T> operator-=(const T &c){

			throw VetorException("Operador não aplicável");
		}	


		Vetor<T> operator+(const Vetor<T> &v){

			return Vetor<T>(this->x + v.x,this->y + v.y,this->z + v.z);
		}

		Vetor<T> operator+(const T &c){

			throw VetorException("Operador não aplicável");

		}

		Vetor<T> operator+=(const Vetor<T> &v){

			x +=  v.x;
			y += v.y;
			z += v.z;
			return *this;
		}

		Vetor<T> operator+=(const T &c){

			throw VetorException("Operador não aplicável");
		}

		Vetor<T> operator/(const T &c){

			throw VetorException("Operador não aplicável");

		}		
		

		Vetor<T> operator/=(const T &c){

			throw VetorException("Operador não aplicável");
		}

		float escalar(const Vetor<T> &v){

			return ((this->x * v.x) + (this->y * v.y) + (this->z * v.z));

		}
		
		float modulo(){

			return sqrt(pow(this->x,2.0) + pow(this->y,2.0) + pow(this->z,2.0));

		}

		Vetor<float> getVersor(){
	
			Vetor<float> vu;
			float mm = this->modulo();	
				
			vu.x = (this->x/mm);
			vu.y = (this->y/mm);
			vu.z = (this->z/mm);
			
			return vu;
		}

};


typedef Vetor<float> Vetor3f;
typedef Vetor<int> Vetor3i;

float angulo(Vetor3f v1,Vetor3f v2){

	Vetor<float>  vu1 = v1.getVersor();
	Vetor<float>  vu2 = v2.getVersor();

	float cosTeta = (vu1.escalar(vu2));
	
	return acos(cosTeta);
	return 0;

}

