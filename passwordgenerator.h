#ifndef PASSWORDGENERATOR_H
#define PASSWORDGENERATOR_H

#include <QString>
#include <QChar>
#include <cstdlib>

class PasswordGenerator{

private:
    bool bUpperCase, bLowerCase, bNumbers, bSpecChars;
    int iPasswordLength;

    int RandomNumber(int iMin, int iMax) const;
    int GenerateNumber() const;
    QChar GenerateUpperCase() const;
    QChar GenerateLowerCase() const;
    QString GenerateSpecChar() const;

public:
    PasswordGenerator(bool bUpperCase = true, bool bLowerCase = true, bool bNumbers = true, bool bSpecChars = false, int iPasswordLength = 20);
    QString GeneratePassword() const;
};

#endif // PASSWORDGENERATOR_H
