//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 



//
// Generated file, do not edit! Created by nedtool 4.6 from PktBoya.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "PktBoya.h"

USING_NAMESPACE


// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




// Template rule for outputting std::vector<T> types
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');

    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

Register_Class(PktBoya);

PktBoya::PktBoya(const char *name, int kind) : ::cMessage(name,kind)
{
    this->source_var = 0;
    this->destination_var = 0;
    this->hopCount_var = 0;
}

PktBoya::PktBoya(const PktBoya& other) : ::cMessage(other)
{
    copy(other);
}

PktBoya::~PktBoya()
{
}

PktBoya& PktBoya::operator=(const PktBoya& other)
{
    if (this==&other) return *this;
    ::cMessage::operator=(other);
    copy(other);
    return *this;
}

void PktBoya::copy(const PktBoya& other)
{
    this->source_var = other.source_var;
    this->destination_var = other.destination_var;
    this->hopCount_var = other.hopCount_var;
}

void PktBoya::parsimPack(cCommBuffer *b)
{
    ::cMessage::parsimPack(b);
    doPacking(b,this->source_var);
    doPacking(b,this->destination_var);
    doPacking(b,this->hopCount_var);
}

void PktBoya::parsimUnpack(cCommBuffer *b)
{
    ::cMessage::parsimUnpack(b);
    doUnpacking(b,this->source_var);
    doUnpacking(b,this->destination_var);
    doUnpacking(b,this->hopCount_var);
}

int PktBoya::getSource() const
{
    return source_var;
}

void PktBoya::setSource(int source)
{
    this->source_var = source;
}

int PktBoya::getDestination() const
{
    return destination_var;
}

void PktBoya::setDestination(int destination)
{
    this->destination_var = destination;
}

int PktBoya::getHopCount() const
{
    return hopCount_var;
}

void PktBoya::setHopCount(int hopCount)
{
    this->hopCount_var = hopCount;
}

class PktBoyaDescriptor : public cClassDescriptor
{
  public:
    PktBoyaDescriptor();
    virtual ~PktBoyaDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(PktBoyaDescriptor);

PktBoyaDescriptor::PktBoyaDescriptor() : cClassDescriptor("PktBoya", "cMessage")
{
}

PktBoyaDescriptor::~PktBoyaDescriptor()
{
}

bool PktBoyaDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<PktBoya *>(obj)!=NULL;
}

const char *PktBoyaDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int PktBoyaDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int PktBoyaDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *PktBoyaDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "source",
        "destination",
        "hopCount",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int PktBoyaDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "source")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destination")==0) return base+1;
    if (fieldName[0]=='h' && strcmp(fieldName, "hopCount")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *PktBoyaDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *PktBoyaDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int PktBoyaDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    PktBoya *pp = (PktBoya *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string PktBoyaDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    PktBoya *pp = (PktBoya *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getSource());
        case 1: return long2string(pp->getDestination());
        case 2: return long2string(pp->getHopCount());
        default: return "";
    }
}

bool PktBoyaDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    PktBoya *pp = (PktBoya *)object; (void)pp;
    switch (field) {
        case 0: pp->setSource(string2long(value)); return true;
        case 1: pp->setDestination(string2long(value)); return true;
        case 2: pp->setHopCount(string2long(value)); return true;
        default: return false;
    }
}

const char *PktBoyaDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *PktBoyaDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    PktBoya *pp = (PktBoya *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}
