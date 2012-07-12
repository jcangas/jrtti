jrtti Documentation
===================

Overview
--------

jrtti is a C++ template library providing reflection capabilities for such programing language

jrtti provides abstraction for standard and custom C++ types and classes. This abstraction exposes class members at run time, wich can be accessed by its string name.

It also provides a string representation of class members that can be used for object serialization and deserialization.

Main Classes
------------

 * jrtti
 * CustomMetaclass
 * Property
 * Method

Download
--------

You can get jrtti from GitHub at https://github.com/jseto/jrtti

Dependencies
------------

boost http://www.boost.org/

Install
-------

jrtti is a header only library. Just include jrtti.hpp to your project and make boost header file path available to your project.

Example
-------

This example shows the main capabilities and usage of jrtti.

See also:
sample.h and tests.

```c++
   #include <jrtti.hpp>
   #include <string>
   
   // Define C++ classes
   struct Position {
       double x;
       double y;
       double z;
   };
   
   class Ball
   {
   public:
           // color setter
       void setColor( std::string color )
       {
           m_color = color;
       }
   
       // color getter
       std::string getColor()
       {
           return m_color;
       }
   
       // position getter
       Position getPosition()
       {
           return m_position;
       }
   
       // move ball ( method call example )
       void quick()
       {
           ++m_position.x;
           ++m_position.y;
           ++m_position.z;
       }
   
   private:
   
       std::string m_color;
       Position m_position;
   };
   
   int main()
   {
       // Make Position class available to jrtti
       jrtti::declare< Position >()
           .property( "x", &Position::x )
           .property( "y", &Position::y )
           .property( "z", &Position::z )
   
       // Make Ball class available to jrtti
       jrtti::declare< Ball >()
           .property( "color", &Ball::setColor, &Ball::getColor )
           .property( "position", &Ball::getPosition )
           .method< void >( "quick", &Ball::quick )
   
       // Use jrtti
       Ball ball;
  
       // set the ball color
       jrtti::getType( "Ball" ).property( "color" ).set( &ball, "red" );
   
       //get a Metatype object
       jrtti::Metatype & mt = jrtti::getType("Sample");
  
       //and working with it accessing properties as an array
       mt[ "color" ].set( &s, "green" );
  
       //call a method
       mt.call< void >( "quick", &ball );
  
       //get a property value by full categorized name
           double xPos = mt.eval( &s, "ball.x" );
       //get property string representation
       cout << mt.toStr( &ball );
       return 0;
   }
```

License
-------

jrtti is distributed under the terms of the GNU Lesser General Public License as published by the Free Software Foundation (LGPLv3).

jrtti is distributed WITHOUT ANY WARRANTY. Use at your own risk.

