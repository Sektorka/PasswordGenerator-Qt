/* ========================================================================== */
/*                                                                            */
/*   Config.cpp                                                               */
/*   (c) 2011 Sektor                                                          */
/*                                                                            */
/* ========================================================================== */

#include "config.h"
#include <QMessageBox>

#ifdef WIN32
QChar Config::separator = '\\';
#else
QChar Config::separator = '/';
#endif

Config::Config(QString selfPath){
    this->bUpperCase = this->bLowerCase = this->bNumbers = true;
    this->bSpecChars = false;
    this->iPasswordLength = 20;
    this->AppName = selfPath.mid( selfPath.lastIndexOf(Config::separator)+1 );
    this->xmlFile = this->AppName.left(this->AppName.lastIndexOf(".")) + ".xml";
}


bool Config::Load(){

  TiXmlDocument xml(xmlFile.toAscii());
    if (xml.LoadFile()){
        loadDataFromXML(&xml,0,"");
        return true;
    }
    else{
        return false;
    }

}

bool Config::CreateXMLFile(){
    TiXmlDocument doc;
    TiXmlDeclaration * decl = new TiXmlDeclaration( "1.0", "utf-8", "");

    doc.LinkEndChild( decl );

    TiXmlElement * iEPasswordLength = new TiXmlElement( "iPasswordLength" );
    iEPasswordLength->LinkEndChild(new TiXmlText( QString("%1").arg( this->iPasswordLength ).toAscii() ));
    doc.LinkEndChild( iEPasswordLength );

    TiXmlElement * bEUpperCase = new TiXmlElement( "bUpperCase" );
    bEUpperCase->LinkEndChild(new TiXmlText( (this->bUpperCase ? "true" : "false") ));
    doc.LinkEndChild( bEUpperCase );

    TiXmlElement * bELowerCase = new TiXmlElement( "bLowerCase" );
    bELowerCase->LinkEndChild(new TiXmlText( (this->bLowerCase ? "true" : "false") ));
    doc.LinkEndChild( bELowerCase );

    TiXmlElement * bENumbers = new TiXmlElement( "bNumbers" );
    bENumbers->LinkEndChild(new TiXmlText( (this->bNumbers ? "true" : "false") ));
    doc.LinkEndChild( bENumbers );

    TiXmlElement * bESpecChars = new TiXmlElement( "bSpecChars" );
    bESpecChars->LinkEndChild(new TiXmlText( (this->bSpecChars ? "true" : "false") ));
    doc.LinkEndChild( bESpecChars );

    return doc.SaveFile( this->xmlFile.toAscii() );
}

QString Config::GetXmlFile() const{
    return this->xmlFile;
}

QString Config::GetAppName() const{
    return this->AppName;
}

void Config::loadDataFromXML( TiXmlNode * pParent, unsigned int indent, const char * prevTag){
    if ( !pParent ) return;

    if( pParent->Type() == TiXmlNode::TINYXML_TEXT){

        if(!strcmp(prevTag,"iPasswordLength")){
            iPasswordLength = atoi(pParent->ToText()->Value());
        }
        else if(!strcmp(prevTag,"bUpperCase")){
            bUpperCase = (QString(pParent->ToText()->Value()).toLower() == QString("true"));
        }
        else if(!strcmp(prevTag,"bLowerCase")){
            bLowerCase = (QString(pParent->ToText()->Value()).toLower() == QString("true"));
        }
        else if(!strcmp(prevTag,"bNumbers")){
            bNumbers = (QString(pParent->ToText()->Value()).toLower() == QString("true"));
        }
        else if(!strcmp(prevTag,"bSpecChars")){
            bSpecChars = (QString(pParent->ToText()->Value()).toLower() == QString("true"));
        }
    }

    TiXmlNode * pChild;

    for ( pChild = pParent->FirstChild(); pChild != 0; pChild = pChild->NextSibling()){
        loadDataFromXML( pChild, indent+2, (pParent->Type()==TiXmlNode::TINYXML_ELEMENT ? pParent->Value() : ""));
    }
}
