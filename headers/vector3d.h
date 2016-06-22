/** @file */
#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <cmath>
#include <iostream>

/**
 * @brief Template class which defines three components vectors with the 
 * basic operations required by most of the problems in physics.
 * 
 * The actual state of the class is such that only operations for the 
 * same type are supported. Future versions may contain more general
 * features.
 * 
 * @author B. M. Manzi
 * @version 1.0
 */

template<typename Type>
class Vector3D
{
public:
  /**
   * @brief Default Constructor defines vector (0,0,0)
   */
    Vector3D() : m_x(0), m_y(0), m_z(0) {}
  /**
   * @brief Vector defined by its components
   */
    Vector3D(Type x, Type y, Type z) : m_x(x), m_y(y), m_z(z) {}
  /**
   * @brief X component getter
   */
    Type x() const {return m_x;}
  /**
   * @brief Y component getter
   */
    Type y() const {return m_y;}
  /**
   * @brief Z component getter
   */
    Type z() const {return m_z;}
  /**
   * @brief X setter
   */
    void setX(Type x) {m_x = x;}
  /**
   * @brief Y setter
   */
    void setY(Type y) {m_y = y;}
  /**
   * @brief Z setter
   */
    void setZ(Type z) {m_z = z;}
  
  /**
   * @brief Length of the vector
   */
    double module() const {return sqrt(m_x * m_x + m_y * m_y + m_z * m_z);}
  /**
   * @brief Unitary vector with the same direction as the class vector
   */
    Vector3D<double> direction() const { return (*this) / this->module(); }
private:
    Type m_x,m_y,m_z;
};

/**
 * @brief Operator overload to output the Vector components
 * 
 * The components are output as a single string divided by commas.
 * The newline character is not included, giving the client the 
 * possibility to choose when to use it.
 */
template<class Type>
std::ostream& operator<<(std::ostream& os, const Vector3D<Type>& A)
{
    os << A.x() << ", " << A.y() << ", " << A.z();
    return os;
}

/**
 * @brief Operator overload to input the Vector components
 */
template<class Type>
std::istream& operator>>(std::istream& is, Vector3D<Type>& A)
{
    Type x,y,z;
    is >> x >> y >> z;
    A.setX(x);
    A.setY(y);
    A.setZ(z);
    return is;
}

/**
 * @brief Geometrical sum of two vectors
 * 
 * @param A   A three components vector
 * @param B   Another three components vector
 * @return    A three components vector, with 
 * each component equal to the sum of the components
 * of A and B,respectively.
 */ 
template<class Type>
Vector3D<Type> operator+(const Vector3D<Type>& A, const Vector3D<Type>& B)
{
    return Vector3D<Type>(A.x() + B.x(), A.y() + B.y(), A.z() + B.z());
}
/**
 * @brief Geometrical difference of two vectors
 * 
 * @param A   A three components vector
 * @param B   Another three components vector
 * @return    A three components vector, with 
 * each component equal to the difference of the components
 * of A and B,respectively. 
 * @note Order of parameters matters
 */ 
template<class Type>
Vector3D<Type> operator-(const Vector3D<Type>& A, const Vector3D<Type>& B)
{
    return Vector3D<Type>(A.x() - B.x(), A.y() - B.y(), A.z() - B.z());
}

/**
 * @brief Product of a scalar times a vector
 * 
 * @param s   A number of the same type as the vector's components
 * @param A   The vector to be multiplied
 * 
 * @return    A vector obtained by multiplying each component of A
 * by s.
 * @note Order does not matter thanks double operator overload
 * @see  operator*(const Vector3D<Type>& A, const Type s)
 */
template<class Type>
Vector3D<Type> operator*(const Type s, const Vector3D<Type>& A)
{
    return Vector3D<Type>(s * A.x(), s * A.y(), s * A.z());
}
/**
 * @brief Product of a scalar times a vector
 * 
 * @param A   The vector to be multiplied
 * @param s   A number of the same type as the vector's components
 * 
 * @return    A vector obtained by multiplying each component of A
 * by s.
 * @note Order does not matter thanks double operator overload
 * @see  operator*(const Type s,const Vector3D<Type>& A)
 */
template<class Type>
Vector3D<Type> operator*(const Vector3D<Type>& A, const Type s)
{
    return Vector3D<Type>(s * A.x(), s * A.y(), s * A.z());
}
/**
 * @brief Product of the respective components of each of the two vectors
 * passed as arguments.
 * 
 * @return A vector with components equal to the product of the components 
 * of the two vectors passed as argument,respectively
 */ 
template<class Type>
Vector3D<Type> operator* (const Vector3D<Type>& A, const Vector3D<Type>& B)
{
    return Vector3D<Type>(A.x() * B.x(), A.y() * B.y(), A.z() * B.z());
}
/**
 * @brief Division of a vector's components by a scalar
 * 
 * @return A vector whose components are equal to the components
 * of A divided by s
 * @note No exception is thrown if the scalar is 0.
 */
template<class Type>
Vector3D<Type> operator/ (const Vector3D<Type>& A, const Type s)
{
    return Vector3D<Type>(A.x() / s,A.y() / s, A.z() / s);
}

/**
 * @brief Division of the components of a vector by the components of the second
 * 
 * @return A vector whose components equal the ratio of the components of the first
 * argument divided by the second.
 * @note Order matters.
 * @note No exception is thrown if one of the components of the second vector is 0.
 */
template<class Type>
Vector3D<Type> operator/ (const Vector3D<Type>& A, const Vector3D<Type>& B)
{
    return Vector3D<Type>(A.x() / B.x(), A.y() / B.y(), A.z() / B.z());
}

/**
 * @brief Boolean equal operator overload to check if all components of two vectors match
 * 
 */
template<class Type>
bool operator== (const Vector3D<Type>& A, const Vector3D<Type>& B)
{
    return (A.x() == B.x() && A.y() == B.y() && A.z() == B.z());
}
/**
 * @brief Scalar Product between two vectors
 * 
 * The Scalar (or dot) product is defined as the sum of the products
 * of the respective components of two vectors, i.e. 
 * a<sub>1</sub>b<sub>1</sub> + a<sub>2</sub>b<sub>2</sub> + a<sub>3</sub>b<sub>3</sub>
 */
template<class Type>
double scalarProduct(const Vector3D<Type>& A, const Vector3D<Type>& B)
{
    Vector3D<Type> C = A * B;
    return C.x() + C.y() + C.z();
}
/**
 * @brief Cross product of two vectors
 * 
 * The cross product of two vectors is another vector with components
 * a<sub>2</sub>b<sub>3</sub> - a<sub>3</sub>b<sub>2</sub>,
 * a<sub>3</sub>b<sub>1</sub> - a<sub>1</sub>b<sub>3</sub>,
 * a<sub>1</sub>b<sub>2</sub> - a<sub>2</sub>b<sub>1</sub>
 */
template<class Type>
Vector3D<Type> crossProduct(const Vector3D<Type>& A, const Vector3D<Type>& B)
{
    return Vector3D<Type>(A.y() * B.z() - A.z() * B.y(),
                          A.z() * B.x() - A.x() * B.z(),
                          A.x() * B.y() - A.y() * B.x());
}
/**
 * @brief Cartesian distance between two points
 * 
 * @return The module of the difference of two vectors
 */
template<class Type>
double distance(const Vector3D<Type> &A, const Vector3D<Type>& B)
{
    return sqrt((A.x() - B.x()) * (A.x() - B.x()) +
                (A.y() - B.y()) * (A.y() - B.y()) +
                (A.z() - B.z()) * (A.z() - B.z()));
}

#endif // VECTOR3D_H
