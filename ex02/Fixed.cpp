#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPoint(0)   // Constructeur
{
    return ;
}

Fixed::Fixed(int const itoi)
{
    this->_fixedPoint = itoi << this->_bit;
    return ;
}

Fixed::Fixed(float const ftoi)
{
    this->_fixedPoint = (int)roundf(ftoi * (1 << this->_bit));
    return ;
}

Fixed::Fixed(const Fixed& cp)	    // Constructeur de recopie
{
    
    this->getRawBits();
    *this = cp;
    return ;
}

Fixed::~Fixed(void)					// Destructeur
{
    return ;
}

Fixed& Fixed::operator=(const Fixed& p)	// Operator d'affectation 
{
    if(this != &p) 
        this->getRawBits();
    this->_fixedPoint = p._fixedPoint;
    return (*this);
}

std::ostream & operator << (std::ostream &out, const Fixed &f)
{
    out << f.toFloat();
    return out;
}

int		Fixed::getRawBits(void) const
{
    return (this->_fixedPoint);
}

float   Fixed::toFloat(void) const
{
    return ((float)_fixedPoint / (float)(1 << _bit));
}

int     Fixed::toInt(void) const
{
    return ((int)_fixedPoint >> _bit);
}

void	Fixed::setRawBits(int const raw)
{
    this->_fixedPoint = raw;
    return ;
}

bool    Fixed::operator >(Fixed &change)
{
	return (this->getRawBits() > change.getRawBits());
}

bool    Fixed::operator <(Fixed &change)
{
    return (this->getRawBits() < change.getRawBits());
}

bool    Fixed::operator >=(Fixed &change)
{
    return (this->getRawBits() >= change.getRawBits());
}

bool    Fixed::operator <=(Fixed &change)
{
	return (this->getRawBits() <= change.getRawBits());
}

bool    Fixed::operator ==(Fixed &change)
{
	return (this->getRawBits() == change.getRawBits());
}

bool    Fixed::operator !=(Fixed &change)
{
	return (this->getRawBits() != change.getRawBits());
}

Fixed     Fixed::operator +(const Fixed &change)
{
	Fixed res;
	res.setRawBits(this->getRawBits() + change.getRawBits());
	return (res);
}

Fixed     Fixed::operator -(const Fixed &change)
{
	Fixed res;
	res.setRawBits(this->getRawBits() - change.getRawBits());
	return (res);
}

Fixed     Fixed::operator *(const Fixed &change)
{
	Fixed res;
	res.setRawBits(this->getRawBits() * change.getRawBits() >> this->_bit );
	return (res);
}

Fixed     Fixed::operator /(const Fixed &change)
{
	Fixed res;
	res.setRawBits(this->getRawBits() / change.getRawBits() << this->_bit);
	return (res);
}

Fixed&   Fixed::operator ++()
{
	this->_fixedPoint++;
	return (*this);
}

Fixed    Fixed::operator ++(int)
{
	Fixed res = *this;
	operator++();
	return (res);

}

Fixed&   Fixed::operator --()
{
	this->_fixedPoint--;
	return (*this);
}
Fixed    Fixed::operator --(int)

{
	Fixed res = *this;
	operator--();
	return (res);
}

Fixed& Fixed::min(Fixed& nb1, Fixed& nb2)
{
	if (nb1._fixedPoint > nb2._fixedPoint)
		return (nb2);
	return (nb1);
}

Fixed& Fixed::max(Fixed& nb1, Fixed& nb2)
{
	if (nb1._fixedPoint > nb2._fixedPoint)
		return (nb1);
	return (nb2);
}

const Fixed& Fixed::min(const Fixed& nb1, const Fixed& nb2)
{
	if (nb1._fixedPoint > nb2._fixedPoint)
		return (nb2);
	return (nb1);
}

const Fixed& Fixed::max(const Fixed& nb1, const Fixed& nb2)
{
	if (nb1._fixedPoint > nb2._fixedPoint)
		return (nb1);
	return (nb2);
}

Fixed &min(Fixed &nb1, Fixed &nb2)
{

	if (nb1 > nb2)
		return (nb2);
	return (nb1);
}

Fixed &max(Fixed &nb1, Fixed &nb2)
{
	if (nb1 > nb2)
		return (nb1);
	return (nb2);
}