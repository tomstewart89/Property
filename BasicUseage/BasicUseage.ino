#include <Property.h>

// We'll declare a class that has a private otherwise inaccessable float, privateFloat
class ExampleClass
{
  float privateFloat;
  
  float GetPrivateFloat() 
  {
    // We can do things as we're getting the member
    Serial.print("Getting private float as: ");
    Serial.println(privateFloat);
    
    return privateFloat; 
  }
  
  const float &SetPrivateFloat(float set)
  {
    // As well as when we're setting it
    Serial.print("Setting private float to: ");
    Serial.println(set);
    
    privateFloat = set;
    return privateFloat;
  }

public:
  
  ExampleClass() : PublicProperty(this, &ExampleClass::GetPrivateFloat, &ExampleClass::SetPrivateFloat) 
  {
    Serial.begin(9600);
  }
  
  // We can safely get and set the private member through this property 
  Property<ExampleClass, float> PublicProperty;
};

void setup()
{
  ExampleClass object;
  
  // We can set the propery like this:
  object.PublicProperty = 12.34;
  
  // And set it like this:
  float localFloat = object.PublicProperty + 34.56;
  
  // It can also be used in compound expressions like so:
  localFloat = object.PublicProperty = 78.90;
}

void loop()
{ }

