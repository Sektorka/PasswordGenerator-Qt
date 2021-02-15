#ifndef CONFIG_H
#define CONFIG_H

#include <QString>
#include <tinyxml.h>

class Config{
  public:
    static QChar separator;
    int iPasswordLength;
    bool bUpperCase, bLowerCase, bNumbers, bSpecChars;
    Config(QString selfPath);

    bool Load();
    bool CreateXMLFile();

    QString GetAppName() const;
    QString GetXmlFile() const;

  private:
    QString AppName;
    QString xmlFile;
    void loadDataFromXML(TiXmlNode * pParent, unsigned int indent, const char * prevTag);
};

#endif // CONFIG_H
