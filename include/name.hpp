#ifndef __NAME_H__
#define __NAME_H__

#include <iostream>
#include <string>

class Name
{
private:
    std::string name;
    std::string lastName;

public:
    Name();
    Name(const Name &);

    std::string getName() const;
    std::string getLastName() const;

    void setName(const std::string &);
    void setLastName(const std::string &);

    std::string toString() const;

    Name &operator=(const Name &);

    bool operator == (const Name&) const;
	bool operator != (const Name&) const;
	bool operator < (const Name&) const;
	bool operator <= (const Name&) const;
	bool operator > (const Name&) const;
	bool operator >= (const Name&) const;

    friend std::ostream &operator<<(std::ostream &, const Name &);
    friend std::ostream &operator>>(std::ostream &, Name &);
};
#endif // __NAME_H__