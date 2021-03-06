
# Property
A short class allowing classes to be written with properties like in C# and objective C.

A property is a member of a class that can be accessed and used just like a normal data member. When set, the property calls a predefined "setter" function and similarly when read, the property calls and returns the result of a predefined "getter" function. The upshot is that a class can define a Property instead of a data member. When gotten or set the Property can carry out functions that are necessary to properly reflect the change in the member. 

A common use of Properties is to ensure that interrupts are disabled while getting and setting a variable that is set by an ISR.  To avoid race conditions, the getters and setters can be implemented call cli and sei (or whatever) while working with the variable. That way, code outside of these accessor methods can then directly access the Property as if it were plain ol' data and the code writer can be safe in the knowledge that interrupts will be correctly handled whenever the variable is accessed.

To use Properties, a parent class that wishes to define a property must be written; we'll say this class is called "Foo".

The Property class itself is a template class that expects two parameters:

	ParentType - the type of it's parent class 
	PropertyType - the type of the variable it will be acing for.

We'll say this property is to act like an integer so we can define it as:
```
Property<Foo, int> aProperty;
```
The property also requires three parameters upon construction:

- A pointer to an object of type ParentType
- A pointer to a member-function of the parent class that conforms to the prototype: PropertyType Getter()
- A pointer to a member-function of the parent class that conforms to the prototype: const PropertyType &Setter(PropertyType)

The first should pretty much always be the 'this' pointer. The other two will be the Getter and Setter function defined in the parent class. These need to be specified in the initialiser list of the parent class like so:
```
Foo() : aProperty(this, &Foo::Getter, &Foo::Setter) 
{ }
```
Where Getter and Setter should be defined as:
```
int Foo::Getter();
const int &Foo::Setter(int set);
```
And that's it! A working example of this is in BasicUseage.

