#ifndef PROPERTY_H
#define PROPERTY_H

// Property is returned from a function and accepts only the specified PropertyType to be enacted on it via the equals
// operator for lvalue operations via the setter function. It can also implicitly cast itself into the specified type
// for rvalue operations by calling the getter function
template<class OwnerType, class PropertyType> class Property
{
public:
    typedef const PropertyType &(OwnerType::*SetterFunction) (PropertyType setValue);
    typedef PropertyType (OwnerType::*GetterFunction) ();

    Property(OwnerType *_owner, GetterFunction _getter, SetterFunction _setter)
    {
        owner = _owner;
        setter = _setter;
        getter = _getter;
    }

    operator PropertyType() { return (owner->*getter)(); }
    const PropertyType &operator=(PropertyType setValue) { (owner->*setter)(setValue); }

private:
    OwnerType *owner;
    SetterFunction setter;
    GetterFunction getter;
};

#endif // PROPERTY_H
