#pragma once

#include <concepts>   
#include <algorithm>  
#include <ostream>    

template<typename I> requires std::integral<I>
class rational
{
private:


    I num_;
    I den_;

    void semplifica() {
        // semplifico gli infiniti in 1/0
        if (num_ != 0 && den_ == 0) {
            if (num_ > 0) {
                num_ = 1;
            } else {
                num_ = -1;
            }
            return;
        }

        // sistemo i segni
        if (den_ < 0) {
            num_ *= -1;
            den_ *= -1;
        }


        I min_val;
        bool flag = false;
        while (!flag) {
            flag = true;
            min_val = std::min(std::abs(num_), std::abs(den_));
            for (int i = 2; i <= min_val && flag; i++) {
                if (num_ % i == 0 && den_ % i == 0) {
                    num_ /= i;
                    den_ /= i;
                    flag = false;
                }
            }
        }
    }

    int is_inf() {
        if (den_ == 0) {
            return num_;
        }
        return 0;
    }

public:
    // costruttore vuoto, inizializzo a 0/1
    rational() : num_(0), den_(1) {}

    // costruttore normale num/den
    rational(I num, I den) : num_(num), den_(den) {
        semplifica();
    }

    // costruttore copia
    rational(const rational& altro) : num_(altro.num_), den_(altro.den_) {}


    // output numeratore
    I num() const {
        return num_;
    }

    // output denominatore
    I den() const {
        return den_;
    }


    // OPERATORI
    rational& operator+=(const rational& other) {
        // eccezioni
        if (is_inf() + other.is_inf() == 2) {
            return rational<int>(1,0);
        }
        if (is_inf() + other.is_inf() == -2) {
            return rational<int>(-1,0);
        }
        if (is_inf() == 1 && other.is_inf() == -1) {
            return rational<int>(0,0);
        }
        if (is_inf() == -1 && other.is_inf() == 1) {
            return rational<int>(0,0);
        }

        num_ = num_ * other.den_ + other.num_ * den_;
        den_ = den_ * other.den_;

        semplifica();

        return *this;
    }

    rational operator+(const rational& other) const {
        rational ret = *this;
        ret += other;
        return ret;
    }

    rational& operator-=(const rational& other) {
        // eccezioni
        if (is_inf() + other.is_inf() == 2) {
            return rational<int>(0,0);
        }
        if (is_inf() + other.is_inf() == -2) {
            return rational<int>(0,0);
        }
        if (is_inf() == 1 && other.is_inf() == -1) {
            return rational<int>(1,0);
        }
        if (is_inf() == -1 && other.is_inf() == 1) {
            return rational<int>(-1,0);
        }

        num_ = num_ * other.den_ - other.num_ * den_;
        den_ = den_ * other.den_;

        semplifica();

        return *this;
    }

    rational operator-(const rational& other) const {
        rational ret = *this;
        ret -= other;
        
        return ret;
    }

    rational& operator*=(const rational& other) {
        num_ = num_ * other.num_;
        den_ = den_ * other.den_;

        semplifica();

        return *this;
    }

    rational operator*(const rational& other) const {
        rational ret = *this;
        ret *= other;
        
        return ret;
    }
    
        rational& operator/=(const rational& other) {
        num_ = num_ * other.den_;
        den_ = den_ * other.num_;

        semplifica();

        return *this;
    }

    rational operator/(const rational& other) const {
        rational ret = *this;
        ret /= other;
        
        return ret;
    }
};


template<typename I> requires std::integral<I>
std::ostream& operator<<(std::ostream& os, const rational<I>& r) 
{
    if (r.num() == 0) {
        if (r.den() == 0) {
            os << "NaN";
        }
        else {
           os << 0;
        }
    }
    else {
        if (r.den() == 0) {
             if (r.num() > 0){
                os << "+Inf";
            } else {
                os << "-Inf";
            }
        }
        else {
            os << r.num();
            if (r.den() != 1) {
                os << '/' << r.den();
            }
        }
    }

    return os;
}
