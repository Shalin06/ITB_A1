//
// Generated file, do not edit! Created by opp_msgtool 6.0 from message.msg.
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
#include "message_m.h"

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

vector::vector()
{
}

vector::vector(const vector& other)
{
    copy(other);
}

vector::~vector()
{
}

vector& vector::operator=(const vector& other)
{
    if (this == &other) return *this;
    copy(other);
    return *this;
}

void vector::copy(const vector& other)
{
// cplusplus {{
    labels = other.labels;
// }}
}

void vector::parsimPack(omnetpp::cCommBuffer *b) const
{
    // field label is abstract or custom -- please do packing in customized class
}

void vector::parsimUnpack(omnetpp::cCommBuffer *b)
{
    // field label is abstract or custom -- please do unpacking in customized class
}

class vectorDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_label,
    };
  public:
    vectorDescriptor();
    virtual ~vectorDescriptor();

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

Register_ClassDescriptor(vectorDescriptor)

vectorDescriptor::vectorDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(vector)), "")
{
    propertyNames = nullptr;
}

vectorDescriptor::~vectorDescriptor()
{
    delete[] propertyNames;
}

bool vectorDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<vector *>(obj)!=nullptr;
}

const char **vectorDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *vectorDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int vectorDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 1+base->getFieldCount() : 1;
}

unsigned int vectorDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISEDITABLE | FD_ISRESIZABLE,    // FIELD_label
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *vectorDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "label",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int vectorDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "label") == 0) return baseIndex + 0;
    return base ? base->findField(fieldName) : -1;
}

const char *vectorDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int32_t",    // FIELD_label
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **vectorDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_label: {
            static const char *names[] = { "custom", "sizeGetter", "sizeSetter",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *vectorDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_label:
            if (!strcmp(propertyName, "custom")) return "";
            if (!strcmp(propertyName, "sizeGetter")) return "getNumLabels";
            if (!strcmp(propertyName, "sizeSetter")) return "setNumLabels";
            return nullptr;
        default: return nullptr;
    }
}

int vectorDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    vector *pp = omnetpp::fromAnyPtr<vector>(object); (void)pp;
    switch (field) {
        case FIELD_label: return pp->getNumLabels();
        default: return 0;
    }
}

void vectorDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    vector *pp = omnetpp::fromAnyPtr<vector>(object); (void)pp;
    switch (field) {
        case FIELD_label: pp->setNumLabels(size); break;
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'vector'", field);
    }
}

const char *vectorDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    vector *pp = omnetpp::fromAnyPtr<vector>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string vectorDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    vector *pp = omnetpp::fromAnyPtr<vector>(object); (void)pp;
    switch (field) {
        case FIELD_label: return long2string(pp->getLabel(i));
        default: return "";
    }
}

void vectorDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    vector *pp = omnetpp::fromAnyPtr<vector>(object); (void)pp;
    switch (field) {
        case FIELD_label: pp->setLabel(i,string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'vector'", field);
    }
}

omnetpp::cValue vectorDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    vector *pp = omnetpp::fromAnyPtr<vector>(object); (void)pp;
    switch (field) {
        case FIELD_label: return pp->getLabel(i);
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'vector' as cValue -- field index out of range?", field);
    }
}

void vectorDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    vector *pp = omnetpp::fromAnyPtr<vector>(object); (void)pp;
    switch (field) {
        case FIELD_label: pp->setLabel(i,omnetpp::checked_int_cast<int32_t>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'vector'", field);
    }
}

const char *vectorDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr vectorDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    vector *pp = omnetpp::fromAnyPtr<vector>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void vectorDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    vector *pp = omnetpp::fromAnyPtr<vector>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'vector'", field);
    }
}

Register_Class(AddPeerToSeedRequest)

AddPeerToSeedRequest::AddPeerToSeedRequest(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

AddPeerToSeedRequest::AddPeerToSeedRequest(const AddPeerToSeedRequest& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

AddPeerToSeedRequest::~AddPeerToSeedRequest()
{
}

AddPeerToSeedRequest& AddPeerToSeedRequest::operator=(const AddPeerToSeedRequest& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void AddPeerToSeedRequest::copy(const AddPeerToSeedRequest& other)
{
    this->peer_ind = other.peer_ind;
    this->seed_ind = other.seed_ind;
    this->msg = other.msg;
}

void AddPeerToSeedRequest::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->peer_ind);
    doParsimPacking(b,this->seed_ind);
    doParsimPacking(b,this->msg);
}

void AddPeerToSeedRequest::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->peer_ind);
    doParsimUnpacking(b,this->seed_ind);
    doParsimUnpacking(b,this->msg);
}

int AddPeerToSeedRequest::getPeer_ind() const
{
    return this->peer_ind;
}

void AddPeerToSeedRequest::setPeer_ind(int peer_ind)
{
    this->peer_ind = peer_ind;
}

int AddPeerToSeedRequest::getSeed_ind() const
{
    return this->seed_ind;
}

void AddPeerToSeedRequest::setSeed_ind(int seed_ind)
{
    this->seed_ind = seed_ind;
}

const char * AddPeerToSeedRequest::getMsg() const
{
    return this->msg.c_str();
}

void AddPeerToSeedRequest::setMsg(const char * msg)
{
    this->msg = msg;
}

class AddPeerToSeedRequestDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_peer_ind,
        FIELD_seed_ind,
        FIELD_msg,
    };
  public:
    AddPeerToSeedRequestDescriptor();
    virtual ~AddPeerToSeedRequestDescriptor();

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

Register_ClassDescriptor(AddPeerToSeedRequestDescriptor)

AddPeerToSeedRequestDescriptor::AddPeerToSeedRequestDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(AddPeerToSeedRequest)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

AddPeerToSeedRequestDescriptor::~AddPeerToSeedRequestDescriptor()
{
    delete[] propertyNames;
}

bool AddPeerToSeedRequestDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<AddPeerToSeedRequest *>(obj)!=nullptr;
}

const char **AddPeerToSeedRequestDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *AddPeerToSeedRequestDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int AddPeerToSeedRequestDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int AddPeerToSeedRequestDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_peer_ind
        FD_ISEDITABLE,    // FIELD_seed_ind
        FD_ISEDITABLE,    // FIELD_msg
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *AddPeerToSeedRequestDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "peer_ind",
        "seed_ind",
        "msg",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int AddPeerToSeedRequestDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "peer_ind") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "seed_ind") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "msg") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *AddPeerToSeedRequestDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_peer_ind
        "int",    // FIELD_seed_ind
        "string",    // FIELD_msg
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **AddPeerToSeedRequestDescriptor::getFieldPropertyNames(int field) const
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

const char *AddPeerToSeedRequestDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int AddPeerToSeedRequestDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    AddPeerToSeedRequest *pp = omnetpp::fromAnyPtr<AddPeerToSeedRequest>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void AddPeerToSeedRequestDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    AddPeerToSeedRequest *pp = omnetpp::fromAnyPtr<AddPeerToSeedRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'AddPeerToSeedRequest'", field);
    }
}

const char *AddPeerToSeedRequestDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    AddPeerToSeedRequest *pp = omnetpp::fromAnyPtr<AddPeerToSeedRequest>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string AddPeerToSeedRequestDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    AddPeerToSeedRequest *pp = omnetpp::fromAnyPtr<AddPeerToSeedRequest>(object); (void)pp;
    switch (field) {
        case FIELD_peer_ind: return long2string(pp->getPeer_ind());
        case FIELD_seed_ind: return long2string(pp->getSeed_ind());
        case FIELD_msg: return oppstring2string(pp->getMsg());
        default: return "";
    }
}

void AddPeerToSeedRequestDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    AddPeerToSeedRequest *pp = omnetpp::fromAnyPtr<AddPeerToSeedRequest>(object); (void)pp;
    switch (field) {
        case FIELD_peer_ind: pp->setPeer_ind(string2long(value)); break;
        case FIELD_seed_ind: pp->setSeed_ind(string2long(value)); break;
        case FIELD_msg: pp->setMsg((value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'AddPeerToSeedRequest'", field);
    }
}

omnetpp::cValue AddPeerToSeedRequestDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    AddPeerToSeedRequest *pp = omnetpp::fromAnyPtr<AddPeerToSeedRequest>(object); (void)pp;
    switch (field) {
        case FIELD_peer_ind: return pp->getPeer_ind();
        case FIELD_seed_ind: return pp->getSeed_ind();
        case FIELD_msg: return pp->getMsg();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'AddPeerToSeedRequest' as cValue -- field index out of range?", field);
    }
}

void AddPeerToSeedRequestDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    AddPeerToSeedRequest *pp = omnetpp::fromAnyPtr<AddPeerToSeedRequest>(object); (void)pp;
    switch (field) {
        case FIELD_peer_ind: pp->setPeer_ind(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_seed_ind: pp->setSeed_ind(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_msg: pp->setMsg(value.stringValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'AddPeerToSeedRequest'", field);
    }
}

const char *AddPeerToSeedRequestDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr AddPeerToSeedRequestDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    AddPeerToSeedRequest *pp = omnetpp::fromAnyPtr<AddPeerToSeedRequest>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void AddPeerToSeedRequestDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    AddPeerToSeedRequest *pp = omnetpp::fromAnyPtr<AddPeerToSeedRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'AddPeerToSeedRequest'", field);
    }
}

Register_Class(AddPeerToPeerRequest)

AddPeerToPeerRequest::AddPeerToPeerRequest(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

AddPeerToPeerRequest::AddPeerToPeerRequest(const AddPeerToPeerRequest& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

AddPeerToPeerRequest::~AddPeerToPeerRequest()
{
}

AddPeerToPeerRequest& AddPeerToPeerRequest::operator=(const AddPeerToPeerRequest& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void AddPeerToPeerRequest::copy(const AddPeerToPeerRequest& other)
{
    this->sender_peer_ind = other.sender_peer_ind;
    this->reciever_peer_ind = other.reciever_peer_ind;
}

void AddPeerToPeerRequest::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->sender_peer_ind);
    doParsimPacking(b,this->reciever_peer_ind);
}

void AddPeerToPeerRequest::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->sender_peer_ind);
    doParsimUnpacking(b,this->reciever_peer_ind);
}

int AddPeerToPeerRequest::getSender_peer_ind() const
{
    return this->sender_peer_ind;
}

void AddPeerToPeerRequest::setSender_peer_ind(int sender_peer_ind)
{
    this->sender_peer_ind = sender_peer_ind;
}

int AddPeerToPeerRequest::getReciever_peer_ind() const
{
    return this->reciever_peer_ind;
}

void AddPeerToPeerRequest::setReciever_peer_ind(int reciever_peer_ind)
{
    this->reciever_peer_ind = reciever_peer_ind;
}

class AddPeerToPeerRequestDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_sender_peer_ind,
        FIELD_reciever_peer_ind,
    };
  public:
    AddPeerToPeerRequestDescriptor();
    virtual ~AddPeerToPeerRequestDescriptor();

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

Register_ClassDescriptor(AddPeerToPeerRequestDescriptor)

AddPeerToPeerRequestDescriptor::AddPeerToPeerRequestDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(AddPeerToPeerRequest)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

AddPeerToPeerRequestDescriptor::~AddPeerToPeerRequestDescriptor()
{
    delete[] propertyNames;
}

bool AddPeerToPeerRequestDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<AddPeerToPeerRequest *>(obj)!=nullptr;
}

const char **AddPeerToPeerRequestDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *AddPeerToPeerRequestDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int AddPeerToPeerRequestDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 2+base->getFieldCount() : 2;
}

unsigned int AddPeerToPeerRequestDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_sender_peer_ind
        FD_ISEDITABLE,    // FIELD_reciever_peer_ind
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *AddPeerToPeerRequestDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "sender_peer_ind",
        "reciever_peer_ind",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int AddPeerToPeerRequestDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "sender_peer_ind") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "reciever_peer_ind") == 0) return baseIndex + 1;
    return base ? base->findField(fieldName) : -1;
}

const char *AddPeerToPeerRequestDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_sender_peer_ind
        "int",    // FIELD_reciever_peer_ind
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **AddPeerToPeerRequestDescriptor::getFieldPropertyNames(int field) const
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

const char *AddPeerToPeerRequestDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int AddPeerToPeerRequestDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    AddPeerToPeerRequest *pp = omnetpp::fromAnyPtr<AddPeerToPeerRequest>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void AddPeerToPeerRequestDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    AddPeerToPeerRequest *pp = omnetpp::fromAnyPtr<AddPeerToPeerRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'AddPeerToPeerRequest'", field);
    }
}

const char *AddPeerToPeerRequestDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    AddPeerToPeerRequest *pp = omnetpp::fromAnyPtr<AddPeerToPeerRequest>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string AddPeerToPeerRequestDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    AddPeerToPeerRequest *pp = omnetpp::fromAnyPtr<AddPeerToPeerRequest>(object); (void)pp;
    switch (field) {
        case FIELD_sender_peer_ind: return long2string(pp->getSender_peer_ind());
        case FIELD_reciever_peer_ind: return long2string(pp->getReciever_peer_ind());
        default: return "";
    }
}

void AddPeerToPeerRequestDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    AddPeerToPeerRequest *pp = omnetpp::fromAnyPtr<AddPeerToPeerRequest>(object); (void)pp;
    switch (field) {
        case FIELD_sender_peer_ind: pp->setSender_peer_ind(string2long(value)); break;
        case FIELD_reciever_peer_ind: pp->setReciever_peer_ind(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'AddPeerToPeerRequest'", field);
    }
}

omnetpp::cValue AddPeerToPeerRequestDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    AddPeerToPeerRequest *pp = omnetpp::fromAnyPtr<AddPeerToPeerRequest>(object); (void)pp;
    switch (field) {
        case FIELD_sender_peer_ind: return pp->getSender_peer_ind();
        case FIELD_reciever_peer_ind: return pp->getReciever_peer_ind();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'AddPeerToPeerRequest' as cValue -- field index out of range?", field);
    }
}

void AddPeerToPeerRequestDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    AddPeerToPeerRequest *pp = omnetpp::fromAnyPtr<AddPeerToPeerRequest>(object); (void)pp;
    switch (field) {
        case FIELD_sender_peer_ind: pp->setSender_peer_ind(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_reciever_peer_ind: pp->setReciever_peer_ind(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'AddPeerToPeerRequest'", field);
    }
}

const char *AddPeerToPeerRequestDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr AddPeerToPeerRequestDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    AddPeerToPeerRequest *pp = omnetpp::fromAnyPtr<AddPeerToPeerRequest>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void AddPeerToPeerRequestDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    AddPeerToPeerRequest *pp = omnetpp::fromAnyPtr<AddPeerToPeerRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'AddPeerToPeerRequest'", field);
    }
}

Register_Class(LivelinessRequest)

LivelinessRequest::LivelinessRequest(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

LivelinessRequest::LivelinessRequest(const LivelinessRequest& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

LivelinessRequest::~LivelinessRequest()
{
}

LivelinessRequest& LivelinessRequest::operator=(const LivelinessRequest& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void LivelinessRequest::copy(const LivelinessRequest& other)
{
    this->timestamp = other.timestamp;
    this->self_ind = other.self_ind;
}

void LivelinessRequest::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->timestamp);
    doParsimPacking(b,this->self_ind);
}

void LivelinessRequest::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->timestamp);
    doParsimUnpacking(b,this->self_ind);
}

int LivelinessRequest::getTimestamp() const
{
    return this->timestamp;
}

void LivelinessRequest::setTimestamp(int timestamp)
{
    this->timestamp = timestamp;
}

int LivelinessRequest::getSelf_ind() const
{
    return this->self_ind;
}

void LivelinessRequest::setSelf_ind(int self_ind)
{
    this->self_ind = self_ind;
}

class LivelinessRequestDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_timestamp,
        FIELD_self_ind,
    };
  public:
    LivelinessRequestDescriptor();
    virtual ~LivelinessRequestDescriptor();

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

Register_ClassDescriptor(LivelinessRequestDescriptor)

LivelinessRequestDescriptor::LivelinessRequestDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(LivelinessRequest)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

LivelinessRequestDescriptor::~LivelinessRequestDescriptor()
{
    delete[] propertyNames;
}

bool LivelinessRequestDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<LivelinessRequest *>(obj)!=nullptr;
}

const char **LivelinessRequestDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *LivelinessRequestDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int LivelinessRequestDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 2+base->getFieldCount() : 2;
}

unsigned int LivelinessRequestDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_timestamp
        FD_ISEDITABLE,    // FIELD_self_ind
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *LivelinessRequestDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "timestamp",
        "self_ind",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int LivelinessRequestDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "timestamp") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "self_ind") == 0) return baseIndex + 1;
    return base ? base->findField(fieldName) : -1;
}

const char *LivelinessRequestDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_timestamp
        "int",    // FIELD_self_ind
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **LivelinessRequestDescriptor::getFieldPropertyNames(int field) const
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

const char *LivelinessRequestDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int LivelinessRequestDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    LivelinessRequest *pp = omnetpp::fromAnyPtr<LivelinessRequest>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void LivelinessRequestDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    LivelinessRequest *pp = omnetpp::fromAnyPtr<LivelinessRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'LivelinessRequest'", field);
    }
}

const char *LivelinessRequestDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    LivelinessRequest *pp = omnetpp::fromAnyPtr<LivelinessRequest>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string LivelinessRequestDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    LivelinessRequest *pp = omnetpp::fromAnyPtr<LivelinessRequest>(object); (void)pp;
    switch (field) {
        case FIELD_timestamp: return long2string(pp->getTimestamp());
        case FIELD_self_ind: return long2string(pp->getSelf_ind());
        default: return "";
    }
}

void LivelinessRequestDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    LivelinessRequest *pp = omnetpp::fromAnyPtr<LivelinessRequest>(object); (void)pp;
    switch (field) {
        case FIELD_timestamp: pp->setTimestamp(string2long(value)); break;
        case FIELD_self_ind: pp->setSelf_ind(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'LivelinessRequest'", field);
    }
}

omnetpp::cValue LivelinessRequestDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    LivelinessRequest *pp = omnetpp::fromAnyPtr<LivelinessRequest>(object); (void)pp;
    switch (field) {
        case FIELD_timestamp: return pp->getTimestamp();
        case FIELD_self_ind: return pp->getSelf_ind();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'LivelinessRequest' as cValue -- field index out of range?", field);
    }
}

void LivelinessRequestDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    LivelinessRequest *pp = omnetpp::fromAnyPtr<LivelinessRequest>(object); (void)pp;
    switch (field) {
        case FIELD_timestamp: pp->setTimestamp(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_self_ind: pp->setSelf_ind(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'LivelinessRequest'", field);
    }
}

const char *LivelinessRequestDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr LivelinessRequestDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    LivelinessRequest *pp = omnetpp::fromAnyPtr<LivelinessRequest>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void LivelinessRequestDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    LivelinessRequest *pp = omnetpp::fromAnyPtr<LivelinessRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'LivelinessRequest'", field);
    }
}

Register_Class(LivelinessReply)

LivelinessReply::LivelinessReply(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

LivelinessReply::LivelinessReply(const LivelinessReply& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

LivelinessReply::~LivelinessReply()
{
}

LivelinessReply& LivelinessReply::operator=(const LivelinessReply& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void LivelinessReply::copy(const LivelinessReply& other)
{
    this->timestamp = other.timestamp;
    this->sender_peer_ind = other.sender_peer_ind;
    this->self_ind = other.self_ind;
}

void LivelinessReply::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->timestamp);
    doParsimPacking(b,this->sender_peer_ind);
    doParsimPacking(b,this->self_ind);
}

void LivelinessReply::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->timestamp);
    doParsimUnpacking(b,this->sender_peer_ind);
    doParsimUnpacking(b,this->self_ind);
}

int LivelinessReply::getTimestamp() const
{
    return this->timestamp;
}

void LivelinessReply::setTimestamp(int timestamp)
{
    this->timestamp = timestamp;
}

int LivelinessReply::getSender_peer_ind() const
{
    return this->sender_peer_ind;
}

void LivelinessReply::setSender_peer_ind(int sender_peer_ind)
{
    this->sender_peer_ind = sender_peer_ind;
}

int LivelinessReply::getSelf_ind() const
{
    return this->self_ind;
}

void LivelinessReply::setSelf_ind(int self_ind)
{
    this->self_ind = self_ind;
}

class LivelinessReplyDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_timestamp,
        FIELD_sender_peer_ind,
        FIELD_self_ind,
    };
  public:
    LivelinessReplyDescriptor();
    virtual ~LivelinessReplyDescriptor();

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

Register_ClassDescriptor(LivelinessReplyDescriptor)

LivelinessReplyDescriptor::LivelinessReplyDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(LivelinessReply)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

LivelinessReplyDescriptor::~LivelinessReplyDescriptor()
{
    delete[] propertyNames;
}

bool LivelinessReplyDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<LivelinessReply *>(obj)!=nullptr;
}

const char **LivelinessReplyDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *LivelinessReplyDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int LivelinessReplyDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int LivelinessReplyDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_timestamp
        FD_ISEDITABLE,    // FIELD_sender_peer_ind
        FD_ISEDITABLE,    // FIELD_self_ind
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *LivelinessReplyDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "timestamp",
        "sender_peer_ind",
        "self_ind",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int LivelinessReplyDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "timestamp") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "sender_peer_ind") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "self_ind") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *LivelinessReplyDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_timestamp
        "int",    // FIELD_sender_peer_ind
        "int",    // FIELD_self_ind
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **LivelinessReplyDescriptor::getFieldPropertyNames(int field) const
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

const char *LivelinessReplyDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int LivelinessReplyDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    LivelinessReply *pp = omnetpp::fromAnyPtr<LivelinessReply>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void LivelinessReplyDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    LivelinessReply *pp = omnetpp::fromAnyPtr<LivelinessReply>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'LivelinessReply'", field);
    }
}

const char *LivelinessReplyDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    LivelinessReply *pp = omnetpp::fromAnyPtr<LivelinessReply>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string LivelinessReplyDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    LivelinessReply *pp = omnetpp::fromAnyPtr<LivelinessReply>(object); (void)pp;
    switch (field) {
        case FIELD_timestamp: return long2string(pp->getTimestamp());
        case FIELD_sender_peer_ind: return long2string(pp->getSender_peer_ind());
        case FIELD_self_ind: return long2string(pp->getSelf_ind());
        default: return "";
    }
}

void LivelinessReplyDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    LivelinessReply *pp = omnetpp::fromAnyPtr<LivelinessReply>(object); (void)pp;
    switch (field) {
        case FIELD_timestamp: pp->setTimestamp(string2long(value)); break;
        case FIELD_sender_peer_ind: pp->setSender_peer_ind(string2long(value)); break;
        case FIELD_self_ind: pp->setSelf_ind(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'LivelinessReply'", field);
    }
}

omnetpp::cValue LivelinessReplyDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    LivelinessReply *pp = omnetpp::fromAnyPtr<LivelinessReply>(object); (void)pp;
    switch (field) {
        case FIELD_timestamp: return pp->getTimestamp();
        case FIELD_sender_peer_ind: return pp->getSender_peer_ind();
        case FIELD_self_ind: return pp->getSelf_ind();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'LivelinessReply' as cValue -- field index out of range?", field);
    }
}

void LivelinessReplyDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    LivelinessReply *pp = omnetpp::fromAnyPtr<LivelinessReply>(object); (void)pp;
    switch (field) {
        case FIELD_timestamp: pp->setTimestamp(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_sender_peer_ind: pp->setSender_peer_ind(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_self_ind: pp->setSelf_ind(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'LivelinessReply'", field);
    }
}

const char *LivelinessReplyDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr LivelinessReplyDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    LivelinessReply *pp = omnetpp::fromAnyPtr<LivelinessReply>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void LivelinessReplyDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    LivelinessReply *pp = omnetpp::fromAnyPtr<LivelinessReply>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'LivelinessReply'", field);
    }
}

Register_Class(Dead)

Dead::Dead(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

Dead::Dead(const Dead& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

Dead::~Dead()
{
}

Dead& Dead::operator=(const Dead& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void Dead::copy(const Dead& other)
{
    this->timestamp = other.timestamp;
    this->peer_ind = other.peer_ind;
    this->seed_ind = other.seed_ind;
}

void Dead::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->timestamp);
    doParsimPacking(b,this->peer_ind);
    doParsimPacking(b,this->seed_ind);
}

void Dead::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->timestamp);
    doParsimUnpacking(b,this->peer_ind);
    doParsimUnpacking(b,this->seed_ind);
}

int Dead::getTimestamp() const
{
    return this->timestamp;
}

void Dead::setTimestamp(int timestamp)
{
    this->timestamp = timestamp;
}

int Dead::getPeer_ind() const
{
    return this->peer_ind;
}

void Dead::setPeer_ind(int peer_ind)
{
    this->peer_ind = peer_ind;
}

int Dead::getSeed_ind() const
{
    return this->seed_ind;
}

void Dead::setSeed_ind(int seed_ind)
{
    this->seed_ind = seed_ind;
}

class DeadDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_timestamp,
        FIELD_peer_ind,
        FIELD_seed_ind,
    };
  public:
    DeadDescriptor();
    virtual ~DeadDescriptor();

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

Register_ClassDescriptor(DeadDescriptor)

DeadDescriptor::DeadDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(Dead)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

DeadDescriptor::~DeadDescriptor()
{
    delete[] propertyNames;
}

bool DeadDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Dead *>(obj)!=nullptr;
}

const char **DeadDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *DeadDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int DeadDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int DeadDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_timestamp
        FD_ISEDITABLE,    // FIELD_peer_ind
        FD_ISEDITABLE,    // FIELD_seed_ind
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *DeadDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "timestamp",
        "peer_ind",
        "seed_ind",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int DeadDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "timestamp") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "peer_ind") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "seed_ind") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *DeadDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_timestamp
        "int",    // FIELD_peer_ind
        "int",    // FIELD_seed_ind
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **DeadDescriptor::getFieldPropertyNames(int field) const
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

const char *DeadDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int DeadDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    Dead *pp = omnetpp::fromAnyPtr<Dead>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void DeadDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    Dead *pp = omnetpp::fromAnyPtr<Dead>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'Dead'", field);
    }
}

const char *DeadDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    Dead *pp = omnetpp::fromAnyPtr<Dead>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string DeadDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    Dead *pp = omnetpp::fromAnyPtr<Dead>(object); (void)pp;
    switch (field) {
        case FIELD_timestamp: return long2string(pp->getTimestamp());
        case FIELD_peer_ind: return long2string(pp->getPeer_ind());
        case FIELD_seed_ind: return long2string(pp->getSeed_ind());
        default: return "";
    }
}

void DeadDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    Dead *pp = omnetpp::fromAnyPtr<Dead>(object); (void)pp;
    switch (field) {
        case FIELD_timestamp: pp->setTimestamp(string2long(value)); break;
        case FIELD_peer_ind: pp->setPeer_ind(string2long(value)); break;
        case FIELD_seed_ind: pp->setSeed_ind(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Dead'", field);
    }
}

omnetpp::cValue DeadDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    Dead *pp = omnetpp::fromAnyPtr<Dead>(object); (void)pp;
    switch (field) {
        case FIELD_timestamp: return pp->getTimestamp();
        case FIELD_peer_ind: return pp->getPeer_ind();
        case FIELD_seed_ind: return pp->getSeed_ind();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'Dead' as cValue -- field index out of range?", field);
    }
}

void DeadDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    Dead *pp = omnetpp::fromAnyPtr<Dead>(object); (void)pp;
    switch (field) {
        case FIELD_timestamp: pp->setTimestamp(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_peer_ind: pp->setPeer_ind(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_seed_ind: pp->setSeed_ind(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Dead'", field);
    }
}

const char *DeadDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr DeadDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    Dead *pp = omnetpp::fromAnyPtr<Dead>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void DeadDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    Dead *pp = omnetpp::fromAnyPtr<Dead>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Dead'", field);
    }
}

Register_Class(AddPeerToSeedReply)

AddPeerToSeedReply::AddPeerToSeedReply(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

AddPeerToSeedReply::AddPeerToSeedReply(const AddPeerToSeedReply& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

AddPeerToSeedReply::~AddPeerToSeedReply()
{
}

AddPeerToSeedReply& AddPeerToSeedReply::operator=(const AddPeerToSeedReply& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void AddPeerToSeedReply::copy(const AddPeerToSeedReply& other)
{
    this->peer_ind = other.peer_ind;
    this->seed_ind = other.seed_ind;
    this->peer_list = other.peer_list;
}

void AddPeerToSeedReply::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->peer_ind);
    doParsimPacking(b,this->seed_ind);
    doParsimPacking(b,this->peer_list);
}

void AddPeerToSeedReply::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->peer_ind);
    doParsimUnpacking(b,this->seed_ind);
    doParsimUnpacking(b,this->peer_list);
}

int AddPeerToSeedReply::getPeer_ind() const
{
    return this->peer_ind;
}

void AddPeerToSeedReply::setPeer_ind(int peer_ind)
{
    this->peer_ind = peer_ind;
}

int AddPeerToSeedReply::getSeed_ind() const
{
    return this->seed_ind;
}

void AddPeerToSeedReply::setSeed_ind(int seed_ind)
{
    this->seed_ind = seed_ind;
}

const vector& AddPeerToSeedReply::getPeer_list() const
{
    return this->peer_list;
}

void AddPeerToSeedReply::setPeer_list(const vector& peer_list)
{
    this->peer_list = peer_list;
}

class AddPeerToSeedReplyDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_peer_ind,
        FIELD_seed_ind,
        FIELD_peer_list,
    };
  public:
    AddPeerToSeedReplyDescriptor();
    virtual ~AddPeerToSeedReplyDescriptor();

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

Register_ClassDescriptor(AddPeerToSeedReplyDescriptor)

AddPeerToSeedReplyDescriptor::AddPeerToSeedReplyDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(AddPeerToSeedReply)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

AddPeerToSeedReplyDescriptor::~AddPeerToSeedReplyDescriptor()
{
    delete[] propertyNames;
}

bool AddPeerToSeedReplyDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<AddPeerToSeedReply *>(obj)!=nullptr;
}

const char **AddPeerToSeedReplyDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *AddPeerToSeedReplyDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int AddPeerToSeedReplyDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int AddPeerToSeedReplyDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_peer_ind
        FD_ISEDITABLE,    // FIELD_seed_ind
        FD_ISCOMPOUND,    // FIELD_peer_list
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *AddPeerToSeedReplyDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "peer_ind",
        "seed_ind",
        "peer_list",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int AddPeerToSeedReplyDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "peer_ind") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "seed_ind") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "peer_list") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *AddPeerToSeedReplyDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_peer_ind
        "int",    // FIELD_seed_ind
        "vector",    // FIELD_peer_list
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **AddPeerToSeedReplyDescriptor::getFieldPropertyNames(int field) const
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

const char *AddPeerToSeedReplyDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int AddPeerToSeedReplyDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    AddPeerToSeedReply *pp = omnetpp::fromAnyPtr<AddPeerToSeedReply>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void AddPeerToSeedReplyDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    AddPeerToSeedReply *pp = omnetpp::fromAnyPtr<AddPeerToSeedReply>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'AddPeerToSeedReply'", field);
    }
}

const char *AddPeerToSeedReplyDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    AddPeerToSeedReply *pp = omnetpp::fromAnyPtr<AddPeerToSeedReply>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string AddPeerToSeedReplyDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    AddPeerToSeedReply *pp = omnetpp::fromAnyPtr<AddPeerToSeedReply>(object); (void)pp;
    switch (field) {
        case FIELD_peer_ind: return long2string(pp->getPeer_ind());
        case FIELD_seed_ind: return long2string(pp->getSeed_ind());
        case FIELD_peer_list: return "";
        default: return "";
    }
}

void AddPeerToSeedReplyDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    AddPeerToSeedReply *pp = omnetpp::fromAnyPtr<AddPeerToSeedReply>(object); (void)pp;
    switch (field) {
        case FIELD_peer_ind: pp->setPeer_ind(string2long(value)); break;
        case FIELD_seed_ind: pp->setSeed_ind(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'AddPeerToSeedReply'", field);
    }
}

omnetpp::cValue AddPeerToSeedReplyDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    AddPeerToSeedReply *pp = omnetpp::fromAnyPtr<AddPeerToSeedReply>(object); (void)pp;
    switch (field) {
        case FIELD_peer_ind: return pp->getPeer_ind();
        case FIELD_seed_ind: return pp->getSeed_ind();
        case FIELD_peer_list: return omnetpp::toAnyPtr(&pp->getPeer_list()); break;
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'AddPeerToSeedReply' as cValue -- field index out of range?", field);
    }
}

void AddPeerToSeedReplyDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    AddPeerToSeedReply *pp = omnetpp::fromAnyPtr<AddPeerToSeedReply>(object); (void)pp;
    switch (field) {
        case FIELD_peer_ind: pp->setPeer_ind(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_seed_ind: pp->setSeed_ind(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'AddPeerToSeedReply'", field);
    }
}

const char *AddPeerToSeedReplyDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_peer_list: return omnetpp::opp_typename(typeid(vector));
        default: return nullptr;
    };
}

omnetpp::any_ptr AddPeerToSeedReplyDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    AddPeerToSeedReply *pp = omnetpp::fromAnyPtr<AddPeerToSeedReply>(object); (void)pp;
    switch (field) {
        case FIELD_peer_list: return omnetpp::toAnyPtr(&pp->getPeer_list()); break;
        default: return omnetpp::any_ptr(nullptr);
    }
}

void AddPeerToSeedReplyDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    AddPeerToSeedReply *pp = omnetpp::fromAnyPtr<AddPeerToSeedReply>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'AddPeerToSeedReply'", field);
    }
}

Register_Class(Gossip)

Gossip::Gossip(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

Gossip::Gossip(const Gossip& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

Gossip::~Gossip()
{
}

Gossip& Gossip::operator=(const Gossip& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void Gossip::copy(const Gossip& other)
{
    this->timestamp = other.timestamp;
    this->sender_peer_ind = other.sender_peer_ind;
    this->msg = other.msg;
}

void Gossip::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->timestamp);
    doParsimPacking(b,this->sender_peer_ind);
    doParsimPacking(b,this->msg);
}

void Gossip::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->timestamp);
    doParsimUnpacking(b,this->sender_peer_ind);
    doParsimUnpacking(b,this->msg);
}

int Gossip::getTimestamp() const
{
    return this->timestamp;
}

void Gossip::setTimestamp(int timestamp)
{
    this->timestamp = timestamp;
}

int Gossip::getSender_peer_ind() const
{
    return this->sender_peer_ind;
}

void Gossip::setSender_peer_ind(int sender_peer_ind)
{
    this->sender_peer_ind = sender_peer_ind;
}

const char * Gossip::getMsg() const
{
    return this->msg.c_str();
}

void Gossip::setMsg(const char * msg)
{
    this->msg = msg;
}

class GossipDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_timestamp,
        FIELD_sender_peer_ind,
        FIELD_msg,
    };
  public:
    GossipDescriptor();
    virtual ~GossipDescriptor();

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

Register_ClassDescriptor(GossipDescriptor)

GossipDescriptor::GossipDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(Gossip)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

GossipDescriptor::~GossipDescriptor()
{
    delete[] propertyNames;
}

bool GossipDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Gossip *>(obj)!=nullptr;
}

const char **GossipDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *GossipDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int GossipDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int GossipDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_timestamp
        FD_ISEDITABLE,    // FIELD_sender_peer_ind
        FD_ISEDITABLE,    // FIELD_msg
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *GossipDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "timestamp",
        "sender_peer_ind",
        "msg",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int GossipDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "timestamp") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "sender_peer_ind") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "msg") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *GossipDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_timestamp
        "int",    // FIELD_sender_peer_ind
        "string",    // FIELD_msg
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **GossipDescriptor::getFieldPropertyNames(int field) const
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

const char *GossipDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int GossipDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    Gossip *pp = omnetpp::fromAnyPtr<Gossip>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void GossipDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    Gossip *pp = omnetpp::fromAnyPtr<Gossip>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'Gossip'", field);
    }
}

const char *GossipDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    Gossip *pp = omnetpp::fromAnyPtr<Gossip>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string GossipDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    Gossip *pp = omnetpp::fromAnyPtr<Gossip>(object); (void)pp;
    switch (field) {
        case FIELD_timestamp: return long2string(pp->getTimestamp());
        case FIELD_sender_peer_ind: return long2string(pp->getSender_peer_ind());
        case FIELD_msg: return oppstring2string(pp->getMsg());
        default: return "";
    }
}

void GossipDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    Gossip *pp = omnetpp::fromAnyPtr<Gossip>(object); (void)pp;
    switch (field) {
        case FIELD_timestamp: pp->setTimestamp(string2long(value)); break;
        case FIELD_sender_peer_ind: pp->setSender_peer_ind(string2long(value)); break;
        case FIELD_msg: pp->setMsg((value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Gossip'", field);
    }
}

omnetpp::cValue GossipDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    Gossip *pp = omnetpp::fromAnyPtr<Gossip>(object); (void)pp;
    switch (field) {
        case FIELD_timestamp: return pp->getTimestamp();
        case FIELD_sender_peer_ind: return pp->getSender_peer_ind();
        case FIELD_msg: return pp->getMsg();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'Gossip' as cValue -- field index out of range?", field);
    }
}

void GossipDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    Gossip *pp = omnetpp::fromAnyPtr<Gossip>(object); (void)pp;
    switch (field) {
        case FIELD_timestamp: pp->setTimestamp(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_sender_peer_ind: pp->setSender_peer_ind(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_msg: pp->setMsg(value.stringValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Gossip'", field);
    }
}

const char *GossipDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr GossipDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    Gossip *pp = omnetpp::fromAnyPtr<Gossip>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void GossipDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    Gossip *pp = omnetpp::fromAnyPtr<Gossip>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Gossip'", field);
    }
}

Register_Class(Block)

Block::Block(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

Block::Block(const Block& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

Block::~Block()
{
}

Block& Block::operator=(const Block& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void Block::copy(const Block& other)
{
    this->previous_hash = other.previous_hash;
    this->merkel_root = other.merkel_root;
    this->timestamp = other.timestamp;
}

void Block::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->previous_hash);
    doParsimPacking(b,this->merkel_root);
    doParsimPacking(b,this->timestamp);
}

void Block::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->previous_hash);
    doParsimUnpacking(b,this->merkel_root);
    doParsimUnpacking(b,this->timestamp);
}

int Block::getPrevious_hash() const
{
    return this->previous_hash;
}

void Block::setPrevious_hash(int previous_hash)
{
    this->previous_hash = previous_hash;
}

int Block::getMerkel_root() const
{
    return this->merkel_root;
}

void Block::setMerkel_root(int merkel_root)
{
    this->merkel_root = merkel_root;
}

int Block::getTimestamp() const
{
    return this->timestamp;
}

void Block::setTimestamp(int timestamp)
{
    this->timestamp = timestamp;
}

class BlockDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_previous_hash,
        FIELD_merkel_root,
        FIELD_timestamp,
    };
  public:
    BlockDescriptor();
    virtual ~BlockDescriptor();

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

Register_ClassDescriptor(BlockDescriptor)

BlockDescriptor::BlockDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(Block)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

BlockDescriptor::~BlockDescriptor()
{
    delete[] propertyNames;
}

bool BlockDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Block *>(obj)!=nullptr;
}

const char **BlockDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *BlockDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int BlockDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int BlockDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_previous_hash
        FD_ISEDITABLE,    // FIELD_merkel_root
        FD_ISEDITABLE,    // FIELD_timestamp
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *BlockDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "previous_hash",
        "merkel_root",
        "timestamp",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int BlockDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "previous_hash") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "merkel_root") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "timestamp") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *BlockDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_previous_hash
        "int",    // FIELD_merkel_root
        "int",    // FIELD_timestamp
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **BlockDescriptor::getFieldPropertyNames(int field) const
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

const char *BlockDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int BlockDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    Block *pp = omnetpp::fromAnyPtr<Block>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void BlockDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    Block *pp = omnetpp::fromAnyPtr<Block>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'Block'", field);
    }
}

const char *BlockDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    Block *pp = omnetpp::fromAnyPtr<Block>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BlockDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    Block *pp = omnetpp::fromAnyPtr<Block>(object); (void)pp;
    switch (field) {
        case FIELD_previous_hash: return long2string(pp->getPrevious_hash());
        case FIELD_merkel_root: return long2string(pp->getMerkel_root());
        case FIELD_timestamp: return long2string(pp->getTimestamp());
        default: return "";
    }
}

void BlockDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    Block *pp = omnetpp::fromAnyPtr<Block>(object); (void)pp;
    switch (field) {
        case FIELD_previous_hash: pp->setPrevious_hash(string2long(value)); break;
        case FIELD_merkel_root: pp->setMerkel_root(string2long(value)); break;
        case FIELD_timestamp: pp->setTimestamp(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Block'", field);
    }
}

omnetpp::cValue BlockDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    Block *pp = omnetpp::fromAnyPtr<Block>(object); (void)pp;
    switch (field) {
        case FIELD_previous_hash: return pp->getPrevious_hash();
        case FIELD_merkel_root: return pp->getMerkel_root();
        case FIELD_timestamp: return pp->getTimestamp();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'Block' as cValue -- field index out of range?", field);
    }
}

void BlockDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    Block *pp = omnetpp::fromAnyPtr<Block>(object); (void)pp;
    switch (field) {
        case FIELD_previous_hash: pp->setPrevious_hash(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_merkel_root: pp->setMerkel_root(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_timestamp: pp->setTimestamp(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Block'", field);
    }
}

const char *BlockDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr BlockDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    Block *pp = omnetpp::fromAnyPtr<Block>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void BlockDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    Block *pp = omnetpp::fromAnyPtr<Block>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Block'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

