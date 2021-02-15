#include "passwordgenerator.h"
#include <QMessageBox>

PasswordGenerator::PasswordGenerator(bool bUpperCase, bool bLowerCase, bool bNumbers, bool bSpecChars, int iPasswordLength){
    this->bUpperCase = bUpperCase;
    this->bLowerCase = bLowerCase;
    this->bNumbers = bNumbers;
    this->bSpecChars = bSpecChars;
    this->iPasswordLength = iPasswordLength;
}

int PasswordGenerator::RandomNumber(int iMin, int iMax) const{
    return int( rand() / (RAND_MAX + 1.0) * (iMax + 1 - iMin) + iMin );
}

int PasswordGenerator::GenerateNumber() const{
    return this->RandomNumber(0,9);
}

QChar PasswordGenerator::GenerateUpperCase() const{
    return QChar(this->RandomNumber(65,90));
}

QChar PasswordGenerator::GenerateLowerCase() const{
    return QChar(this->RandomNumber(97,122));
}

QString PasswordGenerator::GenerateSpecChar() const{
    QChar chars[] = {
        '!','\'','#','$','%','&','"','(',')','*','+','`','-','.','{',
        '/',':',';','<','=','>','?','@','[',']','\\','^','_','|','}'
    };
    return chars[this->RandomNumber(0,sizeof(chars)/sizeof(QChar)-1)];
}

QString PasswordGenerator::GeneratePassword() const{
    QString password = "";
    bool generateDone;

    if(!this->bUpperCase && !this->bLowerCase
            && !this->bNumbers && !this->bSpecChars)
        return "";

    for(int i = 0; i < this->iPasswordLength; i++){
        do{
            generateDone = false;
            switch(this->RandomNumber(0,4)){
                case 0:
                    if(this->bUpperCase){
                        password.append(this->GenerateUpperCase());
                        generateDone = true;
                    }
                    break;
                case 1:
                    if(this->bLowerCase){
                        password.append(this->GenerateLowerCase());
                        generateDone = true;
                    }
                    break;
                case 2:
                    if(this->bNumbers){
                        password.append(QString("%1").arg(this->GenerateNumber()));
                        generateDone = true;
                    }
                    break;
                case 3:
                    if(this->bSpecChars){
                        password.append(this->GenerateSpecChar());
                        generateDone = true;
                    }
                    break;
            }
        }
        while(!generateDone);
    }

    return password;
}
