//
// Generated file, do not edit! Created by opp_msgtool 6.0 from iov_sim/ApplicationLayerTestMessage.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include <type_traits>
#include "ApplicationLayerTestMessage_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

namespace iov_sim {

Register_Class(ApplicationLayerTestMessage)

ApplicationLayerTestMessage::ApplicationLayerTestMessage(const char *name, short kind) : ::veins::BaseFrame1609_4(name, kind)
{
}

ApplicationLayerTestMessage::ApplicationLayerTestMessage(const ApplicationLayerTestMessage& other) : ::veins::BaseFrame1609_4(other)
{
    copy(other);
}

ApplicationLayerTestMessage::~ApplicationLayerTestMessage()
{
}

ApplicationLayerTestMessage& ApplicationLayerTestMessage::operator=(const ApplicationLayerTestMessage& other)
{
    if (this == &other) return *this;
    ::veins::BaseFrame1609_4::operator=(other);
    copy(other);
    return *this;
}

void ApplicationLayerTestMessage::copy(const ApplicationLayerTestMessage& other)
{
    this->demoData = other.demoData;
    this->senderAddress = other.senderAddress;
    this->serial = other.serial;
}

void ApplicationLayerTestMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::veins::BaseFrame1609_4::parsimPack(b);
    doParsimPacking(b,this->demoData);
    doParsimPacking(b,this->senderAddress);
    doParsimPacking(b,this->serial);
}

void ApplicationLayerTestMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::veins::BaseFrame1609_4::parsimUnpack(b);
    doParsimUnpacking(b,this->demoData);
    doParsimUnpacking(b,this->senderAddress);
    doParsimUnpacking(b,this->serial);
}

const char * ApplicationLayerTestMessage::getDemoData() const
{
    return this->demoData.c_str();
}

void ApplicationLayerTestMessage::setDemoData(const char * demoData)
{
    this->demoData = demoData;
}

const ::veins::LAddress::L2Type& ApplicationLayerTestMessage::getSenderAddress() const
{
    return this->senderAddress;
}

void ApplicationLayerTestMessage::setSenderAddress(const ::veins::LAddress::L2Type& senderAddress)
{
    this->senderAddress = senderAddress;
}

int ApplicationLayerTestMessage::getSerial() const
{
    return this->serial;
}

void ApplicationLayerTestMessage::setSerial(int serial)
{
    this->serial = serial;
}

class ApplicationLayerTestMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_demoData,
        FIELD_senderAddress,
        FIELD_serial,
    };
  public:
    ApplicationLayerTestMessageDescriptor();
    virtual ~ApplicationLayerTestMessageDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(ApplicationLayerTestMessageDescriptor)

ApplicationLayerTestMessageDescriptor::ApplicationLayerTestMessageDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(iov_sim::ApplicationLayerTestMessage)), "veins::BaseFrame1609_4")
{
    propertyNames = nullptr;
}

ApplicationLayerTestMessageDescriptor::~ApplicationLayerTestMessageDescriptor()
{
    delete[] propertyNames;
}

bool ApplicationLayerTestMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<ApplicationLayerTestMessage *>(obj)!=nullptr;
}

const char **ApplicationLayerTestMessageDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *ApplicationLayerTestMessageDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int ApplicationLayerTestMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int ApplicationLayerTestMessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_demoData
        0,    // FIELD_senderAddress
        FD_ISEDITABLE,    // FIELD_serial
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *ApplicationLayerTestMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "demoData",
        "senderAddress",
        "serial",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int ApplicationLayerTestMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "demoData") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "senderAddress") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "serial") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *ApplicationLayerTestMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",    // FIELD_demoData
        "veins::LAddress::L2Type",    // FIELD_senderAddress
        "int",    // FIELD_serial
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **ApplicationLayerTestMessageDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *ApplicationLayerTestMessageDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int ApplicationLayerTestMessageDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    ApplicationLayerTestMessage *pp = omnetpp::fromAnyPtr<ApplicationLayerTestMessage>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void ApplicationLayerTestMessageDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    ApplicationLayerTestMessage *pp = omnetpp::fromAnyPtr<ApplicationLayerTestMessage>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'ApplicationLayerTestMessage'", field);
    }
}

const char *ApplicationLayerTestMessageDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    ApplicationLayerTestMessage *pp = omnetpp::fromAnyPtr<ApplicationLayerTestMessage>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string ApplicationLayerTestMessageDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    ApplicationLayerTestMessage *pp = omnetpp::fromAnyPtr<ApplicationLayerTestMessage>(object); (void)pp;
    switch (field) {
        case FIELD_demoData: return oppstring2string(pp->getDemoData());
        case FIELD_senderAddress: return "";
        case FIELD_serial: return long2string(pp->getSerial());
        default: return "";
    }
}

void ApplicationLayerTestMessageDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    ApplicationLayerTestMessage *pp = omnetpp::fromAnyPtr<ApplicationLayerTestMessage>(object); (void)pp;
    switch (field) {
        case FIELD_demoData: pp->setDemoData((value)); break;
        case FIELD_serial: pp->setSerial(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ApplicationLayerTestMessage'", field);
    }
}

omnetpp::cValue ApplicationLayerTestMessageDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    ApplicationLayerTestMessage *pp = omnetpp::fromAnyPtr<ApplicationLayerTestMessage>(object); (void)pp;
    switch (field) {
        case FIELD_demoData: return pp->getDemoData();
        case FIELD_senderAddress: return omnetpp::toAnyPtr(&pp->getSenderAddress()); break;
        case FIELD_serial: return pp->getSerial();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'ApplicationLayerTestMessage' as cValue -- field index out of range?", field);
    }
}

void ApplicationLayerTestMessageDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    ApplicationLayerTestMessage *pp = omnetpp::fromAnyPtr<ApplicationLayerTestMessage>(object); (void)pp;
    switch (field) {
        case FIELD_demoData: pp->setDemoData(value.stringValue()); break;
        case FIELD_serial: pp->setSerial(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ApplicationLayerTestMessage'", field);
    }
}

const char *ApplicationLayerTestMessageDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr ApplicationLayerTestMessageDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    ApplicationLayerTestMessage *pp = omnetpp::fromAnyPtr<ApplicationLayerTestMessage>(object); (void)pp;
    switch (field) {
        case FIELD_senderAddress: return omnetpp::toAnyPtr(&pp->getSenderAddress()); break;
        default: return omnetpp::any_ptr(nullptr);
    }
}

void ApplicationLayerTestMessageDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    ApplicationLayerTestMessage *pp = omnetpp::fromAnyPtr<ApplicationLayerTestMessage>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ApplicationLayerTestMessage'", field);
    }
}

}  // namespace iov_sim

namespace omnetpp {

}  // namespace omnetpp

