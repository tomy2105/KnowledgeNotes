# Swift

<!-- toc -->

- [Resources](#resources)
- [Basics](#basics)
  * [General](#general)
  * [Variables](#variables)
  * [Optionals](#optionals)
  * [Variable Types](#variable-types)
- [Flow control](#flow-control)
  * [If](#if)
  * [Guard](#guard)
  * [For-in](#for-in)
  * [Switch](#switch)
  * [Control transfer statements](#control-transfer-statements)
  * [For](#for)
  * [While](#while)
  * [Repeat While](#repeat-while)
- [Functions](#functions)
  * [Function Parameter Names](#function-parameter-names)
  * [Specifying External Parameter Names](#specifying-external-parameter-names)
  * [Default Parameter Values](#default-parameter-values)
  * [Variadic Parameters](#variadic-parameters)
  * [Constant and Variable Parameters](#constant-and-variable-parameters)
  * [In-Out Parameters](#in-out-parameters)
  * [Nested Functions](#nested-functions)
- [Closures](#closures)
  * [Closure Expression Syntax](#closure-expression-syntax)
  * [Inferring Type From Context](#inferring-type-from-context)
  * [Implicit Returns from Single-Expression Closures](#implicit-returns-from-single-expression-closures)
  * [Shorthand Argument Names](#shorthand-argument-names)
  * [Trailing closures](#trailing-closures)
  * [Capturing values](#capturing-values)
- [Classes and structures](#classes-and-structures)
  * [Definition syntax](#definition-syntax)
  * [Identity operators](#identity-operators)
  * [Properties](#properties)
  * [Methods](#methods)
  * [Subscripts](#subscripts)
  * [Inheritance](#inheritance)
  * [Initialization](#initialization)
  * [Deinitialization](#deinitialization)
  * [Extensions](#extensions)
  * [Protocols](#protocols)
- [Enumerations](#enumerations)
  * [Matching Enumeration Values with a Switch Statement](#matching-enumeration-values-with-a-switch-statement)
  * [Associated Values](#associated-values)
  * [Raw Values](#raw-values)
  * [Recursive Enumerations](#recursive-enumerations)
  * [Access levels](#access-levels)
- [Properties](#properties-1)
  * [Stored Properties](#stored-properties)
  * [Computed Properties](#computed-properties)
  * [Property Observers](#property-observers)
  * [Type Properties](#type-properties)
- [Generics](#generics)
- [Operators](#operators)
- [UI Elements](#ui-elements)
  * [Label](#label)
  * [Button](#button)
  * [Segmented control](#segmented-control)
  * [Text field](#text-field)
  * [Slider](#slider)
  * [Switch](#switch-1)
  * [Activity indicator](#activity-indicator)
  * [Table View](#table-view)
  * [Image View](#image-view)
  * [Text view](#text-view)
  * [Scroll view](#scroll-view)
  * [Stack view](#stack-view)

<!-- tocstop -->

## Resources

1.  [The Swift Programming
    Language](https://developer.apple.com/library/prerelease/ios/documentation/Swift/Conceptual/Swift_Programming_Language/index.html)
2.  [Online Swift Compiler](http://swiftstub.com/)

## Basics

### General

Optional semicolons (except for multiple commands in one)

### Variables

Language is strongly typed but type can inferred. Options key over
variable with hover with type.

``` 
var str = "a string"
var str: String = "a string"
                        
```

*var* keyword declares variable, *let* defines constants.

*nil* denotes value/type when variable doesn't have value, cannot assign
nil to variable with value.

### Optionals

Variables which need not have a value (be initialized). Optional is
actually separate type....

``` 
var str: String? = "a string"
                        
```

*nil* can be assigned to them.

You use optional binding to find out whether an optional contains a
value, and if so, to make that value available as a temporary constant
or variable. Optional binding can be used with if, guard and while
statements to check for a value inside an optional, and to extract that
value into a constant or variable, as part of a single action.

``` 
if let constantName = someOptional {
    statements
}
if var varName = someOptional {
    statements
}
                    
```

Optional chaining, returns nil if fails or does what it should.
[More](https://developer.apple.com/library/ios/documentation/Swift/Conceptual/Swift_Programming_Language/OptionalChaining.html)

``` 
let value = obj.optionalOne?.optionalTwo?                   
obj.optionalOne?.optionalTwo? = something
                    
```

### Variable Types

  - *Int or UInt* - This is is used for whole numbers. More specifically
    you can use Int8, Int32, Int64 or UInt8, UInt32 or UInt64
  - *Float* - This is used to represent a 32-bit floating-point number
  - *Double* - This is used to represent a 64-bit floating-point number
  - *Bool* - This represents a boolean value which is either true or
    false.
  - *String* - This is ordered collection of characters. For example,
    "Hello, World\!"
  - *Character* - This is a single-character string literal. For
    example, "C"
  - *Tuple* - comma-separated list of zero or more types, enclosed in
    parentheses.  
    You can also name the elements of a tuple type and use those names
    to refer to the values of the individual elements. An element name
    consists of an identifier followed immediately by a colon (:)  
    *Void* is a typealias for the empty tuple type, (). If there is only
    one element inside the parentheses, the type is simply the type of
    that element. For example, the type of (*Int*) is *Int*, not
    (*Int*). As a result, you can name a tuple element only when the
    tuple type has two or more elements.
  - *Function type* - the type of a function, method, or closure and
    consists of a parameter and return type separated by an arrow (-\>)
  - *Array* - alias for Swift standard library *Array\<Element\>* type,
    so following is identical:
    
    ``` 
    let someArray: Array<String> = ["Alex", "Brian", "Dave"]
    let someArray: [String] = ["Alex", "Brian", "Dave"]
                                    
    ```
    
    You can create multidimensional arrays by nesting pairs of square
    brackets, where the name of the base type of the elements is
    contained in the innermost pair of square brackets.
  - *Dictionary* - alias for Swift standard library *Dictionary\<Key,
    Value\>* type, so following is identical:
    
    ``` 
    let someDictionary: [String: Int] = ["Alex": 31, "Paul": 39]
    let someDictionary: Dictionary<String, Int> = ["Alex": 31, "Paul": 39]
                                    
    ```
    The subscript returns an optional value of the dictionary’s value
    type. If the specified key isn’t contained in the dictionary, the
    subscript returns *nil*.  
    The key type of a dictionary must conform to the Swift standard
    library *Hashable* protocol.
  - *Optional* - alias for Swift standard library *Optional\<Wrapped\>*
    type, so following is identical:
    
    ``` 
    var optionalInteger: Int?
    var optionalInteger: Optional<Int>
                                    
    ```
    
    The type Optional\<Wrapped\> is an enumeration with two cases,
    *None* and *Some(Wrapped)*, which are used to represent values that
    may or may not be present. Any type can be explicitly declared to be
    (or implicitly converted to) an optional type. If you don’t provide
    an initial value when you declare an optional variable or property,
    its value automatically defaults to *nil*.  
    If an instance of an optional type contains a value, you can access
    that value using the postfix operator \!, as shown below:
    
    ``` 
    optionalInteger = 42
    optionalInteger! // 42
                                        
    ```

  - *Implicitly Unwrapped Optional* - alias for Swift standard library
    *ImplicitlyUnwrappedOptional\<Wrapped\>* type, so following is
    identical:
    
    ``` 
    var optionalInteger: Int!
    var optionalInteger: ImplicitlyUnwrappedOptional<Int>
                                    
    ```
    
    You can use implicitly unwrapped optionals in all the same places in
    your code that you can use optionals. For instance, you can assign
    values of implicitly unwrapped optionals to variables, constants,
    and properties of optionals, and vice versa.  
    Because the value of an implicitly unwrapped optional is
    automatically unwrapped when you use it, there’s no need to use the
    \! operator to unwrap it. That said, if you try to use an implicitly
    unwrapped optional that has a value of nil, you’ll get a runtime
    error.

Only class is reference type, everything else is value type (struct,
enum, array, ...)

## Flow control

### If

In its simplest form, the if statement has a single if condition. It
executes a set of statements only if that condition is true.  
The if statement can provide an alternative set of statements, known as
an else clause, for when the if condition is false. These statements are
indicated by the else keyword.  
You can chain multiple if statements together, to consider additional
clauses.  

``` 
if temperatureInFahrenheit <= 32 {
    //cold
} else if temperatureInFahrenheit >= 86 {
    //hot
} else {
    //normal
}                       
```

### Guard

Execute block of code if conditon is *NOT* met.

``` 
guard let x = x where x > 0 else {
    // Value requirements not met, do something
    return
}                       
```

### For-in

Iterate over a sequence, such as ranges of numbers, items in an array,
or characters in a string.

``` 
//non inclusive
for counter in 1..<10 {
}
// inclusive
for index in 1...5 {
}

var animals = ["chickens", "cows", "ducks"]
for animal in animals {
}

let numberOfLegs = ["spider": 8, "ant": 6, "cat": 4]
for (animalName, legCount) in numberOfLegs {
}
                        
```

for variable can be scoped (not declared before), it need not be
specified, use *\_* instead

### Switch

A switch statement considers a value and compares it against several
possible matching patterns. It then executes an appropriate block of
code, based on the first pattern that matches successfully.

``` 


    switch some value to consider {
    case value 1:
        respond to value 1
    case value 2, value 3:
        respond to value 2 or 3
    default:
        otherwise, do something else
    }
                        
```

Every switch statement must be exhaustive. The catch-all case is
indicated by the default keyword, and must always appear last.  
The body of each case must contain at least one executable statement.  
In contrast with switch statements in C and Objective-C, switch
statements in Swift do not fall through the bottom of each case and into
the next one by default. Instead, the entire switch statement finishes
its execution as soon as the first matching switch case is completed,
without requiring an explicit break statement.  
You can still use a break statement to match and ignore a particular
case, or to break out of a matched case before that case has completed
its execution.  
To opt in to fallthrough behavior for a particular switch case, use the
fallthrough keyword.  

Values in switch cases can be checked for their inclusion in an
interval.

``` 
switch approximateCount {
case 0:
    naturalCount = "no"
case 1..<5:
    naturalCount = "a few"
case 5..<12:
    naturalCount = "several"
case 12..<100:
    naturalCount = "dozens of"
case 100..<1000:
    naturalCount = "hundreds of"
default:
    naturalCount = "many"
}
                            
```

You can use tuples to test multiple values in the same switch statement.
Each element of the tuple can be tested against a different value or
interval of values. Alternatively, use the underscore character (\_),
also known as the wildcard pattern, to match any possible value.

``` 
let somePoint = (1, 1)
switch somePoint {
case (0, 0):
    // do something
case (_, 0):
    // do something
case (0, _):
    // do something
case (-2...2, -2...2):
    // do something
default:
    // do something
}
                            
```

A switch case can bind the value or values it matches to temporary
constants or variables, for use in the body of the case. This is known
as value binding, because the values are “bound” to temporary constants
or variables within the case’s body.

``` 
let anotherPoint = (2, 0)
switch anotherPoint {
case (let x, 0):
    // use x
case (0, let y):
    // use y
case let (x, y):
    // use x and y
}
                            
```

A switch case can use a where clause to check for additional conditions.

``` 
let yetAnotherPoint = (1, -1)
switch yetAnotherPoint {
case let (x, y) where x == y:
    // do soemthing
case let (x, y) where x == -y:
    // do soemthing
case let (x, y):
    // do soemthing
}
                            
```

### Control transfer statements

  - *continue - tells a loop to stop what it is doing and start again at
    the beginning of the next iteration through the loop*
  - *break - ends execution of an entire control flow statement
    immediately*
  - *fallthrough - C-style fallthrough behavior in switch*
  - *return*
  - *throw*

You can label looping statements to explicitly tell which loop to
continue and/or break

### For

Traditional C-style for loops with a condition and an incrementer.

``` 
for var index = 0; index < 3; ++index {
}                       
```

Unlike C, Swift doesn’t need parentheses around the entire
“initialization; condition; increment” block.

### While

A while loop starts by evaluating a single condition. If the condition
is true, a set of statements is repeated until the condition becomes
false.

``` 
while condition {
    statements
}
                        
```

Unlike C, Swift doesn’t need parentheses around condition.

### Repeat While

Performs a single pass through the loop block first, before considering
the loop’s condition. It then continues to repeat the loop until the
condition is false.

``` 
repeat {
    statements
} while condition
                        
```

Unlike C, Swift doesn’t need parentheses around condition.

## Functions

Functions are self-contained chunks of code that perform a specific
task. You give a function a name that identifies what it does, and this
name is used to call the function to perform its task when needed.

When you define a function, you can optionally define one or more named,
typed values that the function takes as input (known as parameters),
and/or a type of value that the function will pass back as output when
it is done (known as its return type).

``` 
func sayHello(personName: String) -> String {
    let greeting = "Hello, " + personName + "!"
    return greeting
}

print(sayHello("Anna"))
                    
```

### Function Parameter Names

Function parameters have both an external parameter name and a local
parameter name. An external parameter name is used to label arguments
passed to a function call. A local parameter name is used in the
implementation of the function.

``` 
func someFunction(firstParameterName: Int, secondParameterName: Int) {
    // function body goes here
    // firstParameterName and secondParameterName refer to
    // the argument values for the first and second parameters
}
someFunction(1, secondParameterName: 2)
                        
```

### Specifying External Parameter Names

You write an external parameter name before the local parameter name it
supports, separated by a space.

``` 
func sayHello(to person: String, and anotherPerson: String) -> String {
    return "Hello \(person) and \(anotherPerson)!"
}
print(sayHello(to: "Bill", and: "Ted"))
                        
```

By default, the first parameter omits its external name, and the second
and subsequent parameters use their local name as their external name.
All parameters must have unique local names. Although it’s possible for
multiple parameters to have the same external name, unique external
names help make your code more readable.

If you do not want to use an external name for the second or subsequent
parameters of a function, write an underscore (\_) instead of an
explicit external name for that parameter.

``` 
func someFunction(firstParameterName: Int, _ secondParameterName: Int) {
    // function body goes here
    // firstParameterName and secondParameterName refer to
    // the argument values for the first and second parameters
}
someFunction(1, 2)
                        
```

Because the first parameter omits its external parameter name by
default, explicitly writing an underscore is extraneous.

### Default Parameter Values

You can define a default value for any parameter in a function by
assigning a value to the parameter after that parameter’s type. If a
default value is defined, you can omit that parameter when calling the
function.

``` 
func someFunction(parameterWithDefault: Int = 12) {
    // function body goes here
    // if no arguments are passed to the function call,
    // value of parameterWithDefault is 12
}
someFunction(6) // parameterWithDefault is 6
someFunction() // parameterWithDefault is 12
                        
```

### Variadic Parameters

A variadic parameter accepts zero or more values of a specified type.
You use a variadic parameter to specify that the paraeter can be passed
a varying number of input values when the function is called. Write
variadic parameters by inserting three period characters (...) after the
parameter’s type name.  
The values passed to a variadic parameter are made available within the
function’s body as an array of the appropriate type.

``` 
func arithmeticMean(numbers: Double...) -> Double {
    var total: Double = 0
    for number in numbers {
        total += number
    }
    return total / Double(numbers.count)
}
arithmeticMean(1, 2, 3, 4, 5)
// returns 3.0, which is the arithmetic mean of these five numbers
arithmeticMean(3, 8.25, 18.75)
// returns 10.0, which is the arithmetic mean of these three numbers
                        
```

A function may have at most one variadic parameter.

### Constant and Variable Parameters

Function parameters are constants by default. Trying to change the value
of a function parameter from within the body of that function results in
a compile-time error. This means that you can’t change the value of a
parameter by mistake.  
However, sometimes it is useful for a function to have a variable copy
of a parameter’s value to work with. You can avoid defining a new
variable yourself within the function by specifying one or more
parameters as variable parameters instead.  
Define variable parameters by prefixing the parameter name with the var
keyword.

``` 
func alignRight(var string: String, totalLength: Int, pad: Character) -> String {
}
                        
```

The changes you make to a variable parameter do not persist beyond the
end of each call to the function, and are not visible outside the
function’s body. The variable parameter only exists for the lifetime of
that function call.

### In-Out Parameters

If you want a function to modify a parameter’s value, and you want those
changes to persist after the function call has ended, define that
parameter as an in-out parameter.

``` 
func swapTwoInts(inout a: Int, inout _ b: Int) {
    let temporaryA = a
    a = b
    b = temporaryA
}
                        
```

In-out parameters cannot have default values, and variadic parameters
cannot be marked as inout. If you mark a parameter as inout, it cannot
also be marked as var or let.

### Nested Functions

You can also define functions inside the bodies of other functions,
known as nested functions. Nested functions are hidden from the outside
world by default, but can still be called and used by their enclosing
function. An enclosing function can also return one of its nested
functions to allow the nested function to be used in another scope.

``` 
func chooseStepFunction(backwards: Bool) -> (Int) -> Int {
    func stepForward(input: Int) -> Int { return input + 1 }
    func stepBackward(input: Int) -> Int { return input - 1 }
    return backwards ? stepBackward : stepForward
}
var currentValue = -4
let moveNearerToZero = chooseStepFunction(currentValue > 0)
// moveNearerToZero now refers to the nested stepForward() function
while currentValue != 0 {
    print(&quot:\(currentValue)... &quot:)
    currentValue = moveNearerToZero(currentValue)
}
                        
```

## Closures

Closures are self-contained blocks of functionality that can be passed
around and used in your code. Closures in Swift are similar to blocks in
C and Objective-C and to lambdas in other programming languages.  
Global and nested functions, as introduced in Functions, are actually
special cases of closures. Closures take one of three forms:

  - Global functions are closures that have a name and do not capture
    any values.
  - Nested functions are closures that have a name and can capture
    values from their enclosing function.
  - Closure expressions are unnamed closures written in a lightweight
    syntax that can capture values from their surrounding context.

### Closure Expression Syntax

``` 
{ (parameters) -> return type in
    statements
}
                    
```

Closure expression syntax can use constant parameters, variable
parameters, and inout parameters. Default values cannot be provided.
Variadic parameters can be used if you name the variadic parameter.
Tuples can also be used as parameter types and return types.

``` 
reversed = names.sort({ (s1: String, s2: String) -> Bool in
    return s1 > s2
})
                    
```

### Inferring Type From Context

Swift can infer the types of its parameters and the type of the value it
returns.

``` 
reversed = names.sort( { s1, s2 in return s1 > s2 } )                   
                    
```

### Implicit Returns from Single-Expression Closures

Single-expression closures can implicitly return the result of their
single expression by omitting the return keyword from their declaration

``` 
reversed = names.sort( { s1, s2 in s1 > s2 } )                  
                    
```

### Shorthand Argument Names

Swift automatically provides shorthand argument names to inline
closures, which can be used to refer to the values of the closure’s
arguments by the names $0, $1, $2, and so on.  
If you use these shorthand argument names within your closure
expression, you can omit the closure’s argument list from its
definition, and the number and type of the shorthand argument names will
be inferred from the expected function type. The in keyword can also be
omitted, because the closure expression is made up entirely of its body.

``` 
reversed = names.sort( { $0 > $1 } )
                    
```

### Trailing closures

If you need to pass a closure expression to a function as the function’s
final argument and the closure expression is long, it can be useful to
write it as a trailing closure instead. A trailing closure is a closure
expression that is written outside of (and after) the parentheses of the
function call it supports.

``` 
func someFunctionThatTakesAClosure(closure: () -> Void) {
    // function body goes here
}
 
// here's how you call this function without using a trailing closure:
someFunctionThatTakesAClosure({
    // closure's body goes here
})
 
// here's how you call this function with a trailing closure instead:
someFunctionThatTakesAClosure() {
    // trailing closure's body goes here
}

// here's how you call this function with a trailing closure instead:
someFunctionThatTakesAClosure {
    // trailing closure's body goes here
}

                    
```

### Capturing values

A closure can capture constants and variables from the surrounding
context in which it is defined. The closure can then refer to and modify
the values of those constants and variables from within its body, even
if the original scope that defined the constants and variables no longer
exists.

``` 
func makeIncrementer(forIncrement amount: Int) -> () -> Int {
    var runningTotal = 0
    func incrementer() -> Int {
        runningTotal += amount
        return runningTotal
    }
    return incrementer
}
                    
```

More about closures at
[Closures](https://developer.apple.com/library/ios/documentation/Swift/Conceptual/Swift_Programming_Language/Closures.html)

## Classes and structures

Classes and structures are general-purpose, flexible constructs that
become the building blocks of your program’s code. You define properties
and methods to add functionality to your classes and structures by using
exactly the same syntax as for constants, variables, and functions. Both
can:

  - Define properties to store values
  - Define methods to provide functionality
  - Define subscripts to provide access to their values using subscript
    syntax
  - Define initializers to set up their initial state
  - Be extended to expand their functionality beyond a default
    implementation
  - Conform to protocols to provide standard functionality of a certain
    kind

In addition classes can:

  - Inheritance enables one class to inherit the characteristics of
    another.
  - Type casting enables you to check and interpret the type of a class
    instance at runtime.
  - Deinitializers enable an instance of a class to free up any
    resources it has assigned.
  - Reference counting allows more than one reference to a class
    instance.

### Definition syntax

You introduce classes with the class keyword and structures with the
struct keyword. Both place their entire definition within a pair of
braces.  
Whenever you define a new class or structure, you effectively define a
brand new Swift type. Give types UpperCamelCase names (such as SomeClass
and SomeStructure here) to match the capitalization of standard Swift
types (such as String, Int, and Bool). Conversely, always give
properties and methods lowerCamelCase names (such as frameRate and
incrementCount) to differentiate them from type names.

``` 
class SomeClass {
    // class definition goes here
}
struct SomeStructure {
    // structure definition goes here
}
                    
```

### Identity operators

Because classes are reference types, it is possible for multiple
constants and variables to refer to the same single instance of a class
behind the scenes. It can sometimes be useful to find out if two
constants or variables refer to exactly the same instance of a class. To
enable this, Swift provides two identity operators:

Identical to (===)

Not identical to (\!==)

### Properties

See [here](#props)

### Methods

Methods are functions that are associated with a particular type.

Every instance of a type has an implicit property called *self*, which
is exactly equivalent to the instance itself. You use the self property
to refer to the current instance within its own instance methods. In
practice, you don’t need to write self in your code very often.

Structures and enumerations are value types. By default, the properties
of a value type cannot be modified from within its instance methods.
However, if you need to modify the properties of your structure or
enumeration within a particular method, you can opt in to mutating
behavior for that method.

``` 
struct Point {
    var x = 0.0, y = 0.0
    mutating func moveByX(deltaX: Double, y deltaY: Double) {
        x += deltaX
        y += deltaY
    }
}
var somePoint = Point(x: 1.0, y: 1.0)
somePoint.moveByX(2.0, y: 3.0)
print("The point is now at (\(somePoint.x), \(somePoint.y))")
// prints "The point is now at (3.0, 4.0)"
                        
```

Mutating methods can assign an entirely new instance to the implicit
self property.

You can also define methods that are called on the type itself. These
kinds of methods are called type methods. You indicate type methods by
writing the *static* keyword before the method’s func keyword. Classes
may also use the *class* keyword to allow subclasses to override the
superclass’s implementation of that method.

``` 
class SomeClass {
    class func someTypeMethod() {
        // type method implementation goes here
    }
}
SomeClass.someTypeMethod()
                        
```

Within the body of a type method, the implicit *self* property refers to
the type itself, rather than an instance of that type.

### Subscripts

Classes, structures, and enumerations can define subscripts, which are
shortcuts for accessing the member elements of a collection, list, or
sequence.

``` 
subscript(index: Int) -> Int {
    get {
        // return an appropriate subscript value here
    }
    set(newValue) {
        // perform a suitable setting action here
    }
}
                    
```

Subscripts can take any number of input parameters, and these input
parameters can be of any type. Subscripts can also return any type.
Subscripts can use variable parameters and variadic parameters, but
cannot use in-out parameters or provide default parameter values.

``` 
                        struct Matrix {
                            let rows: Int, columns: Int
                            var grid: [Double]
                            init(rows: Int, columns: Int) {
                                self.rows = rows
                                self.columns = columns
                                grid = Array(count: rows * columns, repeatedValue: 0.0)
                            }
                            func indexIsValidForRow(row: Int, column: Int) -> Bool {
                                return row >= 0 && row < rows && column >= 0 && column < columns
                            }
                            subscript(row: Int, column: Int) -> Double {
                                get {
                                    assert(indexIsValidForRow(row, column: column), "Index out of range")
                                    return grid[(row * columns) + column]
                                }
                                set {
                                    assert(indexIsValidForRow(row, column: column), "Index out of range")
                                    grid[(row * columns) + column] = newValue
                                }
                            }
                        }
                        var matrix = Matrix(rows: 2, columns: 2)


                        matrix[0, 1] = 1.5
                        matrix[1, 0] = 3.2
                    
```

### Inheritance

A class can inherit methods, properties, and other characteristics from
another class. When one class inherits from another, the inheriting
class is known as a subclass, and the class it inherits from is known as
its superclass.

``` 
class SomeSubclass: SomeSuperclass {
    // subclass definition goes here
}
                    
```

A subclass can provide its own custom implementation of an instance
method, type method, instance property, type property, or subscript that
it would otherwise inherit from a superclass. This is known as
overriding.  
To override a characteristic that would otherwise be inherited, you
prefix your overriding definition with the override keyword. Doing so
clarifies that you intend to provide an override and have not provided a
matching definition by mistake.  
Where this is appropriate, you access the superclass version of a
method, property, or subscript by using the *super* prefix.  
You can prevent a method, property, or subscript from being overridden
by marking it as final.

### Initialization

Initialization is the process of preparing an instance of a class,
structure, or enumeration for use. This process involves setting an
initial value for each stored property on that instance and performing
any other setup or initialization that is required before the new
instance is ready for use.

Initializers are called to create a new instance of a particular type.
In its simplest form, an initializer is like an instance method with no
parameters, written using the *init* keyword:

``` 
init() {
    // perform some initialization here
}
                        
```

All structures have an automatically-generated memberwise initializer,
which you can use to initialize the member properties of new structure
instances. Initial values for the properties of the new instance can be
passed to the memberwise initializer by name:

    let vga = Resolution(width: 640, height: 480)

Unlike structures, class instances do not receive a default memberwise
initializer.

Swift provides a default initializer for any structure or class that
provides default values for all of its properties and does not provide
at least one initializer itself.

You can set the initial value of a stored property from within an
initializer, as shown above. Alternatively, specify a default property
value as part of the property’s declaration. You specify a default
property value by assigning an initial value to the property when it is
defined.

You can provide initialization parameters as part of an initializer’s
definition, to define the types and names of values that customize the
initialization process. Initialization parameters have the same
capabilities and syntax as function and method parameters.

Properties of optional type are automatically initialized with a value
of nil, indicating that the property is deliberately intended to have
“no value yet” during initialization.

You can assign a value to a constant property at any point during
initialization, as long as it is set to a definite value by the time
initialization finishes. Once a constant property is assigned a value,
it can’t be further modified.

Initializers can be delegated:

``` 
struct Rect {
    var origin = Point()
    var size = Size()
    init() {}
    init(origin: Point, size: Size) {
        self.origin = origin
        self.size = size
    }
    init(center: Point, size: Size) {
        let originX = center.x - (size.width / 2)
        let originY = center.y - (size.height / 2)
        self.init(origin: Point(x: originX, y: originY), size: size)
    }
}
                        
```

*Designated initializers* are the primary initializers for a class. A
designated initializer fully initializes all properties introduced by
that class and calls an appropriate superclass initializer to continue
the initialization process up the superclass chain.  
*Convenience initializers* are secondary, supporting initializers for a
class. You can define a convenience initializer to call a designated
initializer from the same class as the convenience initializer with some
of the designated initializer’s parameters set to default values.  
Convenience initializers are written in the same style, but with the
convenience modifier placed before the init keyword.

To cope with initialization conditions that can fail, define one or more
failable initializers as part of a class, structure, or enumeration
definition. You write a failable initializer by placing a question mark
after the init keyword (init?). Or (init\!).

Write the required modifier before the definition of a class initializer
to indicate that every subclass of the class must implement that
initializer

More
[here](https://developer.apple.com/library/ios/documentation/Swift/Conceptual/Swift_Programming_Language/Initialization.html)

### Deinitialization

A deinitializer is called immediately before a class instance is
deallocated. You write deinitializers with the deinit keyword

``` 
deinit {
    // perform the deinitialization
}
                    
```

### Extensions

Extensions add new functionality to an existing class, structure,
enumeration, or protocol type. This includes the ability to extend types
for which you do not have access to the original source code (known as
retroactive modeling).

  - Add computed properties and computed type properties
  - Define instance methods and type methods
  - Provide new initializers
  - Define subscripts
  - Define and use new nested types
  - Make an existing type conform to a protocol

<!-- end list -->

``` 
extension SomeType {
    // new functionality to add to SomeType goes here
}
                    
```

### Protocols

A protocol defines a blueprint of methods, properties, and other
requirements that suit a particular task or piece of functionality.

``` 


    protocol SomeProtocol {
        // protocol definition goes here
        init(someParameter: Int)
        
        var mustBeSettable: Int { get set }
        var doesNotNeedToBeSettable: Int { get }

        func random() -> Double
    }


    class SomeClass: SomeSuperclass, FirstProtocol, AnotherProtocol {
        // class definition goes here
    }


                    
```

You can implement a protocol initializer requirement on a conforming
class as either a designated initializer or a convenience initializer.
In both cases, you must mark the initializer implementation with the
*required* modifier.

More
[here](https://developer.apple.com/library/ios/documentation/Swift/Conceptual/Swift_Programming_Language/Protocols.html)

## Enumerations

An enumeration defines a common type for a group of related values and
enables you to work with those values in a type-safe way within your
code.

``` 
enum CompassPoint {
    case North
    case South
    case East
    case West
}
                
```

### Matching Enumeration Values with a Switch Statement

``` 
directionToHead = .South
switch directionToHead {
case .North:
    // Lots of planets have a north
case .South:
    // Lots of planets have a south
case .East:
    // Lots of planets have a east
case .West:
    // Lots of planets have a west
}
                    
```

### Associated Values

You can define Swift enumerations to store associated values of any
given type, and the value types can be different for each member of the
enumeration if needed.

``` 
enum Barcode {
    case UPCA(Int, Int, Int, Int)
    case QRCode(String)
}


switch productBarcode {
case let .UPCA(numberSystem, manufacturer, product, check):
    print("UPC-A: \(numberSystem), \(manufacturer), \(product), \(check).")
case let .QRCode(productCode):
    print("QR code: \(productCode).")
}
                    
```

### Raw Values

Raw values can be strings, characters, or any of the integer or
floating-point number types. Each raw value must be unique within its
enumeration declaration.

Raw values are not the same as associated values. Raw values are set to
prepopulated values when you first define the enumeration in your code,
like the three ASCII codes above. The raw value for a particular
enumeration member is always the same. Associated values are set when
you create a new constant or variable based on one of the enumeration’s
members, and can be different each time you do so.

``` 
enum ASCIIControlCharacter: Character {
    case Tab = "\t"
    case LineFeed = "\n"
    case CarriageReturn = "\r"
}

enum Planet: Int {
    case Mercury = 1, Venus, Earth, Mars, Jupiter, Saturn, Uranus, Neptune
}


enum CompassPoint: String {
    case North, South, East, West
}

let earthsOrder = Planet.Earth.rawValue
// earthsOrder is 3

let sunsetDirection = CompassPoint.West.rawValue
// sunsetDirection is "West"
                    
```

If you define an enumeration with a raw-value type, the enumeration
automatically receives an initializer that takes a value of the raw
value’s type (as a parameter called rawValue) and returns either an
enumeration member or nil. You can use this initializer to try to create
a new instance of the enumeration.

``` 
let possiblePlanet = Planet(rawValue: 7)
                    
```

### Recursive Enumerations

A recursive enumeration is an enumeration that has another instance of
the enumeration as the associated value for one or more of the
enumeration members. The compiler has to insert a layer of indirection
when it works with recursive enumerations. You indicate that an
enumeration member is recursive by writing indirect before it.

``` 
enum ArithmeticExpression {
    case Number(Int)
    indirect case Addition(ArithmeticExpression, ArithmeticExpression)
    indirect case Multiplication(ArithmeticExpression, ArithmeticExpression)
}

indirect enum ArithmeticExpression {
    case Number(Int)
    case Addition(ArithmeticExpression, ArithmeticExpression)
    case Multiplication(ArithmeticExpression, ArithmeticExpression)
}


func evaluate(expression: ArithmeticExpression) -> Int {
    switch expression {
    case .Number(let value):
        return value
    case .Addition(let left, let right):
        return evaluate(left) + evaluate(right)
    case .Multiplication(let left, let right):
        return evaluate(left) * evaluate(right)
    }
}
 
// evaluate (5 + 4) * 2
let five = ArithmeticExpression.Number(5)
let four = ArithmeticExpression.Number(4)
let sum = ArithmeticExpression.Addition(five, four)
let product = ArithmeticExpression.Multiplication(sum, ArithmeticExpression.Number(2))
print(evaluate(product))
// prints 18
                    
```

### Access levels

  - *Public access* enables entities to be used within any source file
    from their defining module, and also in a source file from another
    module that imports the defining module. You typically use public
    access when specifying the public interface to a framework.
  - *Internal access* enables entities to be used within any source file
    from their defining module, but not in any source file outside of
    that module. You typically use internal access when defining an
    app’s or a framework’s internal structure.
  - *Private access* restricts the use of an entity to its own defining
    source file. Use private access to hide the implementation details
    of a specific piece of functionality.

## Properties

Properties associate values with a particular class, structure, or
enumeration. Stored properties store constant and variable values as
part of an instance, whereas computed properties calculate (rather than
store) a value. Computed properties are provided by classes, structures,
and enumerations. Stored properties are provided only by classes and
structures.

You can access the properties of an instance using dot syntax. In dot
syntax, you write the property name immediately after the instance name,
separated by a period (.), without any spaces.

### Stored Properties

In its simplest form, a stored property is a constant or variable that
is stored as part of an instance of a particular class or structure.
Stored properties can be either variable stored properties (introduced
by the var keyword) or constant stored properties (introduced by the let
keyword).

``` 
struct FixedLengthRange {
    var firstValue: Int
    let length: Int
}
var rangeOfThreeItems = FixedLengthRange(firstValue: 0, length: 3)
// the range represents integer values 0, 1, and 2
rangeOfThreeItems.firstValue = 6
// the range now represents integer values 6, 7, and 8
                    
```

If you create an instance of a structure and assign that instance to a
constant, you cannot modify the instance’s properties, even if they were
declared as variable properties.

A lazy stored property is a property whose initial value is not
calculated until the first time it is used. You indicate a lazy stored
property by writing the lazy modifier before its declaration. Must
always be a variable ecause its initial value might not be retrieved
until after instance initialization completes.

``` 


class DataImporter {
    var data = 1
}
 
class DataManager {
    lazy var importer = DataImporter()
    var data = [Int]()
}
 
let manager = DataManager()
manager.data.append(1)
manager.data.append(2)
// the DataImporter instance for the importer property has not yet been created

print(manager.importer.fileName)
// the DataImporter instance for the importer property has now been created
// prints 1
                    
```

### Computed Properties

In addition to stored properties, classes, structures, and enumerations
can define computed properties, which do not actually store a value.
Instead, they provide a getter and an optional setter to retrieve and
set other properties and values indirectly.

``` 
struct Point {
    var x = 0.0, y = 0.0
}
struct Size {
    var width = 0.0, height = 0.0
}
struct Rect {
    var origin = Point()
    var size = Size()
    var center: Point {
        get {
            let centerX = origin.x + (size.width / 2)
            let centerY = origin.y + (size.height / 2)
            return Point(x: centerX, y: centerY)
        }
        set(newCenter) {
            origin.x = newCenter.x - (size.width / 2)
            origin.y = newCenter.y - (size.height / 2)
        }
    }
}
var square = Rect(origin: Point(x: 0.0, y: 0.0),
    size: Size(width: 10.0, height: 10.0))
let initialSquareCenter = square.center
square.center = Point(x: 15.0, y: 15.0)
// square.origin is now at (10.0, 10.0)"
                    
```

If a computed property’s setter does not define a name for the new value
to be set, a default name of *newValue* is used.

A computed property with a getter but no setter is known as a read-only
computed property. A read-only computed property always returns a value,
and can be accessed through dot syntax, but cannot be set to a different
value.

### Property Observers

Property observers observe and respond to changes in a property’s value.
Property observers are called every time a property’s value is set, even
if the new value is the same as the property’s current value.  
You have the option to define either or both of these observers on a
property:

  - *willSet* is called just before the value is stored, it is passed
    the new property value as a constant parameter, you can specify a
    name for this parameter or used default name of *newValue*.
  - *didSet* is called immediately after the new value is stored, it is
    passed a constant parameter containing the old property value, you
    can name the parameter if you wish, or use the default parameter
    name of *oldValue*.

<!-- end list -->

``` 
class StepCounter {
    var totalSteps: Int = 0 {
        willSet(newTotalSteps) {
            print("About to set totalSteps to \(newTotalSteps)")
        }
        didSet {
            if totalSteps > oldValue  {
                print("Added \(totalSteps - oldValue) steps")
            }
        }
    }
}
let stepCounter = StepCounter()
stepCounter.totalSteps = 200
// About to set totalSteps to 200
// Added 200 steps
stepCounter.totalSteps = 360
// About to set totalSteps to 360
// Added 160 steps
stepCounter.totalSteps = 896
// About to set totalSteps to 896
// Added 536 steps
                    
```

### Type Properties

Type properties are useful for defining values that are universal to all
instances of a particular type, such as a constant property that all
instances can use (like a static constant in C), or a variable property
that stores a value that is global to all instances of that type (like a
static variable in C).  
You define type properties with the static keyword. For computed type
properties for class types, you can use the class keyword instead to
allow subclasses to override the superclass’s implementation.

``` 
struct SomeStructure {
    static var storedTypeProperty = "Some value."
    static var computedTypeProperty: Int {
        return 1
    }
}
enum SomeEnumeration {
    static var storedTypeProperty = "Some value."
    static var computedTypeProperty: Int {
        return 6
    }
}
class SomeClass {
    static var storedTypeProperty = "Some value."
    static var computedTypeProperty: Int {
        return 27
    }
    class var overrideableComputedTypeProperty: Int {
        return 107
    }
}

print(SomeStructure.storedTypeProperty)
// prints "Some value."
SomeStructure.storedTypeProperty = "Another value."
print(SomeStructure.storedTypeProperty)
// prints "Another value."
print(SomeEnumeration.computedTypeProperty)
// prints "6"
print(SomeClass.computedTypeProperty)
// prints "27"
                    
```

## Generics

More
[here](https://developer.apple.com/library/ios/documentation/Swift/Conceptual/Swift_Programming_Language/Generics.html)

## Operators

More
[here](https://developer.apple.com/library/ios/documentation/Swift/Conceptual/Swift_Programming_Language/BasicOperators.html)
and

More
[here](https://developer.apple.com/library/ios/documentation/Swift/Conceptual/Swift_Programming_Language/AdvancedOperators.html).

## UI Elements

### Label

### Button

### Segmented control

### Text field

### Slider

### Switch

### Activity indicator

### Table View

### Image View

### Text view

### Scroll view

### Stack view

