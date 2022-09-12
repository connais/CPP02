#pragma once 
#include <iostream>
#include <string>
#include <cmath>

class   Fixed
{

public :

    Fixed(void);    				// Constructeur
    Fixed(int const itoi);
    Fixed (float const ftoi);
    Fixed(const Fixed& cp);			// Constructeur de recopie
    ~Fixed(void);					// Destructeur
    Fixed& operator=(const Fixed& p);	// Operator d'affectation 
    // Fixed& operator*(const Fixed& obj1);
    // {
    //     return obj1.height != obj2.height;
    // }
    int		getRawBits(void) const;
	void	setRawBits(int const raw);
    float   toFloat(void) const;
    int     toInt(void) const;
    
    bool    operator >(Fixed &change);
    bool    operator <(Fixed &change);
    bool    operator >=(Fixed &change);
    bool    operator <=(Fixed &change);
    bool    operator ==(Fixed &change);
    bool    operator !=(Fixed &change);

    Fixed     operator +(const Fixed& change);
    Fixed     operator -(const Fixed& change);
    Fixed     operator *(const Fixed& change);
    Fixed     operator /(const Fixed& change);

    Fixed    operator ++(int);
    Fixed    operator --(int);
    Fixed&   operator ++();
    Fixed&   operator --();

    static Fixed& min(Fixed& nb1, Fixed& nb2);
    static Fixed& max(Fixed& nb1, Fixed& nb2);
    const static Fixed& min(const Fixed& nb1, const Fixed& nb2);
    const static Fixed& max(const Fixed& nb1, const Fixed& nb2);

    friend std::ostream& operator<<(std::ostream& os, const Fixed& fx);
private :

    int _fixedPoint;
    int const static _bit = 8;
};

Fixed &min(Fixed &u, Fixed &v);
Fixed &max(Fixed &u, Fixed &v);