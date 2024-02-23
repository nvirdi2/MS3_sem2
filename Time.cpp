// Name: Navdeep Virdi
// Seneca email: nvirdi2@myseneca.ca
// Student ID: 166485193
// Date: March 27, 2021

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <cmath>
#include <string>

#include "Time.h"
#include "utils.h"

using namespace std;
namespace sdds
{
    Time &Time::setToNow()
    {
        *this = getTime();
            return (*this);
    }
    
    Time::Time(unsigned int minutes)
    {
        m_minutes = minutes;
    }

    ostream &Time::write(ostream &ostr) const
    {
        double Hours = 0;
        double Mins;

            if (m_minutes >= 60) 
            {  
                Hours = floor(m_minutes / 60);
            }
        Mins = m_minutes - (60 * Hours);

            ostr.width(2);
            ostr.fill('0');

            ostr << Hours;

            ostr << ":";

            ostr.width(2);
            ostr.fill('0');

            ostr << Mins;

        return ostr;
    }

        std::istream& Time::read(std::istream& istr)
    {
        string InputUser;
        int Hours;
        int Minutes;
        int i;
        
        istr >> InputUser;

        if(InputUser.length() == 0)
        {
            istr.setstate(ios::failbit);
            return istr;
        }

        for(i = 0; InputUser[i] != '\0'; i++)
        {
            if(!(InputUser[i] == ':' || InputUser[i] == '0' || InputUser[i] == '1' || InputUser[i] == '2' ||
                     InputUser[i] == '3' || InputUser[i] == '4' || InputUser[i] == '5' || InputUser[i] == '6' ||   
                     InputUser[i] == '7' || InputUser[i] == '8' || InputUser[i] == '9') && InputUser[i] != ':')
            {
                istr.setstate(ios::failbit);
                return istr;
            }
        }

        Hours = stoi(InputUser.substr(0,InputUser.find(':')));
        Minutes = stoi(InputUser.substr(InputUser.find(':') + 1));
        
        if(Hours < 0 || Minutes < 0)
        {
            istr.setstate(ios::failbit);
        }
        else
        {
            m_minutes = Hours * 60 + Minutes;
        } return istr;
    }



    Time &Time::operator=(unsigned int val)
    {
        m_minutes = val;
            return *this;
    }

    Time &Time::operator*=(unsigned int val)
    {
        m_minutes *= val;
            return *this;
    }

    Time &Time::operator/=(unsigned int val)
    {
        m_minutes /= val;
            return *this;
    }



    ostream &operator<<(ostream &ostr, const Time &D)
    {
        D.write(ostr);
            return ostr;
    }

    istream &operator>>(istream &istr, Time &D)
    {
        D.read(istr);
            return istr;
    }



    Time::operator unsigned int() const
    {
        return m_minutes;
    }

    Time::operator int() const
    {
        return int(m_minutes);
    }



    Time &Time::operator+=(const Time &D)
    {
        m_minutes += D.m_minutes;
        return *this;
    }

    Time Time::operator+(const Time &D) const
    {
        Time tmp(m_minutes);
            tmp += D;
                return tmp;
    }



    Time Time::operator-(const Time &D) const
    {
        Time tmp(m_minutes);
        tmp -= D;
        return tmp;
    }

    Time Time::operator*(unsigned int val) const
    {
        Time tmp(m_minutes);
            tmp *= val;
                return tmp;
    }

    Time Time::operator/(unsigned int val) const
    {
        Time tmp(m_minutes);
            tmp /= val;
                return tmp;
    }

    Time &Time::operator-=(const Time &D)
    {
        if (m_minutes > D.m_minutes)
        {
            m_minutes -= D.m_minutes;
        }
            else
            {
                double hour = 0;
                double min;
                double Hours = 0;
                double Mins;

            if (m_minutes >= 60)
            {
                Hours = floor(m_minutes / 60);
            }
                Mins = m_minutes - (60 * Hours);


            if (D.m_minutes >= 60)
            {
                hour = floor(D.m_minutes / 60);
            }
                min = D.m_minutes - (60 * hour);

                if (Mins < min)
                {
                    Mins += 60;
                    Mins -= min;
                    Hours--;
                }
                else
                {
                    Mins -= min;
                }

            double ttime = ceil(hour / 24);

            Hours += 24.0 * ttime;
            Hours -= hour;

            m_minutes = int(Mins + (Hours * 60));
        } return *this;
    }

}