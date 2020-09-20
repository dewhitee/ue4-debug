# ue4-debug
* [General info](#general-info)
* [Examples](#examples)
* [Technologies](#technologies)

## General info
Unity-like logging methods for Unreal Engine 4.

## Examples
```cpp
// SomeClass.cpp

using namespace Debugging;

void USomeClass::Foo()
{
  // Will log only the "Bar" string into the LogDebug category.
  Debug::Log("Bar");
  
  // You can add the "this" as the first parameter to also add the USomeClass instance name to the log
  Debug::Log(this, "Bar");
  
  // Will output the "Bar" string to the viewport with the default white color and duration of 5 seconds.
  Debug::Screen("Bar");
  
  // As with Log methods, you can add *this* keyword (or any other UObject) as the first parameter to add the name of it
  Debug::Screen(this, "Bar");
  
  // You can specify the color of an output text:
  Debug::Screen("Bar", FColor::Red);
  
  // And duration:
  Debug::Screen(this, "Bar", 10.f, FColor::Red);
}

```

## Technologies
Project is created with:
* [Unreal Engine 4](https://www.unrealengine.com/en-US/): v4.24
