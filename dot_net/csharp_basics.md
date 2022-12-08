# C# basics

<!-- toc -->

- [Essentials](#essentials)
  * [Built-in value types](#built-in-value-types)
  * [Literals](#literals)
  * [Reference vs value types](#reference-vs-value-types)
  * [Built-in reference types](#built-in-reference-types)
  * [Enumeration](#enumeration)
  * [Tuples](#tuples)
  * [Nullable types](#nullable-types)
  * [Variables](#variables)
  * [Basic operators](#basic-operators)
- [Basic programming (call flow and methods)](#basic-programming-call-flow-and-methods)
  * [If-else](#if-else)
  * [Switch](#switch)
  * [for loop](#for-loop)
  * [foreach loop](#foreach-loop)
  * [do loop](#do-loop)
  * [while loop](#while-loop)
  * [break/continue](#breakcontinue)
  * [exceptions](#exceptions)
- [Arrays and Collections](#arrays-and-collections)
  * [one dimensional arrays](#one-dimensional-arrays)
  * [multi-dimensional arrays](#multi-dimensional-arrays)
  * [jagged arrays](#jagged-arrays)
  * [Array class methods and properties](#array-class-methods-and-properties)
  * [arrays as method parameters](#arrays-as-method-parameters)
  * [Collections](#collections)
- [Object oriented programming](#object-oriented-programming)
  * [class](#class)
  * [static](#static)
  * [fields](#fields)
  * [constructors](#constructors)
  * [constants](#constants)
  * [properties](#properties)
  * [object initialization](#object-initialization)
  * [indexers](#indexers)
  * [method definition and invocation](#method-definition-and-invocation)
  * [extension methods](#extension-methods)
  * [events](#events)
  * [anonymous methods and lambda expressions](#anonymous-methods-and-lambda-expressions)
  * [operators](#operators)
  * [finalizer](#finalizer)
  * [polymorphism](#polymorphism)
  * [abstract and sealed](#abstract-and-sealed)
  * [partial](#partial)
  * [interfaces](#interfaces)
  * [records](#records)
  * [generics](#generics)
  * [anonymous types](#anonymous-types)
  * [deconstructing to tuple](#deconstructing-to-tuple)
- [Some of the references](#some-of-the-references)

<!-- tocstop -->

## Essentials

### Built-in value types

|Keyword | Ranged 	|Size |
|-----------|---------------|--------------------|
|sbyte 	|-128 to 127 	|Signed 8-bit integer|
|byte 	|0 to 255 	|Unsigned 8-bit integer|
|short 	|-32,768 to 32,767 	|Signed 16-bit integer|
|ushort 	|0 to 65,535 	|Unsigned 16-bit integer |
|int 	|-2,147,483,648 to 2,147,483,647 	|Signed 32-bit integer|
|uint 	|0 to 4,294,967,295 	|Unsigned 32-bit integer |
|long 	|-9,223,372,036,854,775,808 to 9,223,372,036,854,775,807| 	Signed 64-bit integer |
|ulong 	|0 to 18,446,744,073,709,551,615 	|Unsigned 64-bit integer|
|nint 	|Depends on platform (computed at runtime) 	|Signed 32-bit or 64-bit (native sized) integer| 
|nuint 	|Depends on platform (computed at runtime) 	|Unsigned 32-bit or 64-bit (native sized) integer| 	
|float 	| +-1.5 x 10<sup>−45</sup> to +-3.4 x 10<sup>38</sup> | 	~6-9 digits 	4 bytes|
|double | +-5.0 × 10<sup>−324</sup> to +-1.7 × 10<sup>308</sup> | 	~15-17 digits 	8 bytes|
|decimal | +-1.0 x 10<sup>-28</sup> to +-7.9228 x 10<sup>28</sup> | 	28-29 digits 	16 bytes|
|bool | true or false boolean value | | 
|char | a Unicode UTF-16 character| 2 bytes |

[Convert class](https://docs.microsoft.com/en-us/dotnet/api/system.convert?view=net-6.0) can be used to convert between various types, also other built-in classes have various `ToString` and `To*` and `Parse` methods.

### Literals

Literals are:

- decimal: without any prefix
- hexadecimal: with the 0x or 0X prefix
- binary: with the 0b or 0B prefix (available in C# 7.0 and later)
- character: inside single quotes `'`, can contain unicode `\u` or hexadecimal `\x` escapes sequences 
- string: 
  - raw - inside **minimum** of three double quotation marks `"""` and can contain newlines, embedded quotes, etc...
  - quoted - inside double quotation marks `"` - can also contain escape sequence
  - verbatim - inside double quotation marks `"` but starting with `@` - escape sequences not processed
  - interpolated - C# 6, inside double quotation marks `"` but starting with, **minimum one**, `$` - everything within `{` and `}` is evaluated and replaced with string version of the evaluation result (with formatting see [here](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/tokens/interpolated))

Suffix like `UL` determines integer literal type `200UL` is `ulong`, `d` is `double`, `f` is `float` and `m` is `decimal`. From C# 7 `_` can be used as digit separator.

### Reference vs value types

Reference types store references to their data (objects), value types directly contain their data. 
Two variables can reference the same object, with value types, each variable has its own copy of the data.

 `class`, `interface`, `delegate` and `record` keywords can be used to declare reference types.

### Built-in reference types

- `object` - all types, reference types and value types, inherit directly or indirectly from it

- `string` -  sequence of zero or more Unicode characters, although it is reference equality operators operator on value, it is **immutable** (more info [here](https://docs.microsoft.com/en-us/dotnet/api/system.string)), for **mutable** string operations use [StringBuilder](https://docs.microsoft.com/en-us/dotnet/api/system.text.stringbuilder).

- `dynamic` -  use of the variable and references to its members bypass compile-time type checking


### Enumeration

Value type defined by set of named constants (of underlying integral type which is optional).

```
enum ErrorCode : ushort
{
    None = 0,
    Unknown = 1
}
```

Underlying type `: ushort` and values of constants can be omitted (will be created automatically).

### Tuples

Concise way of grouping data in a lightweight structure, defined with `(` and `)`.

```
var t1 = (100, "Orange");
Console.WriteLine(t1.Item1);
Console.WriteLine(t1.Item2);

(int Quantity, string Name) t2 = (200, "Apples");
Console.WriteLine(t2.Name);
Console.WriteLine(t2.Quantity);

var t3 = (Quantity:300, Name:"Pineapples");
Console.WriteLine(t3.Name);
Console.WriteLine(t3.Quantity);

//deconstruction

var (Quantity, Name) = t1;
Console.WriteLine(Name);
Console.WriteLine(Quantity);

(_, Name) = t2;
Console.WriteLine(Name);
Console.WriteLine(Quantity);

```

**Discard `_` can be used in deconstruction to ignore some member of tuple.**

Tuples are actually mutable value type [ValueTuple](https://docs.microsoft.com/en-us/dotnet/api/system.valuetuple) with fields unlike [Tuple](https://docs.microsoft.com/en-us/dotnet/api/system.tuple) which is immutable reference type with properties.

### Nullable types

A nullable **value** type `T?` represents all values of this value type T and an additional `null` value. 

Nullable **reference** types are available C# 8.0. If enabled:

- variable of a type `T` must be initialized with non-null, and may not be assigned a null.
- variable of a type `T?` may be initialized with null or assigned null, **required ** to be checked against null before de-referencing
- variable `m` of type `T?` is non-null when you apply the null-forgiving/surpression operator `m!`


### Variables

Variables are declared and initialized `type variableName = value;`.

Constants just have `const` before the type (and capitalized name).

C# 3 and above, instead of `type`, a keyword `var` can be used for implicit typing (based on `value`).

### Basic operators

| operator | name |
| -------- | ---- |
| ++ | unary increment |
| -- | unary decremenet |
| + | unary plus or binary addition |
| - | unary minus or binary subtraction |
| * | binary multiplication |
| / | binary division (**integer if both operands are integers!!!**) |
| % | binary remainder of division |
| < | binary less than |
| \<\= | binary less than or equal |
| > | binary greater than |
| >= | binary greater than or equal |
| == | binary equality |
| != | binary inequality |
| ! | unary logical negation |
| & | binary logical (or bitwise) AND **always evaluates both arguments** |
| \| | binary logical (or bitwise) OR **always evaluates both arguments**|
| ^ | | binary logical (or bitwise) exclusive OR **always evaluates both arguments**|
| && | binary logical AND **evaluate the right-hand operand only if it's necessary** |
| \|\| | binary logical OR **evaluate the right-hand operand only if it's necessary**|
| ~  | unary bitwise complement |
| << | binary left shift |
| >> | binary right shift |
| >>>|  binary unsigned right shift |
| is |  result of an expression is compatible with a given type |
| as |  converts to provided type, if not convertible returns null |
| ?? |  null coalescing, returns the value of its left-hand operand if it isn't null; otherwise, it evaluates the right-hand operand and returns its result.|
| ? |  null conditional operator, returns null if left is null, othwerwise result as if no null conditional operator|



Compound assignment operator is operator looking like `=op` and `x =op y` is equivalent to `x = x op y`.

**Note**: beware of "equality"

- operands of the built-in value types are equal if their values are equal
- user-defined struct types don't support the `==` operator by default, must overload it
- **by default, two non-record reference-type operands are equal if they refer to the same object**
- `record` types (C# 9) support the `==` and `!=` operators that provide value equality 
- `string` operands are equal when both of them are null or both string instances are of the same length and have identical characters in each character position

Precedence:

- postfix `++`/`--`
- prefix `++`/`--` and unary `+`/`-`
- `*`, `/`, and `%`
- binary `+` and `-`
- `>>` and `>>`
- `<`, `>`, `>=`, `<=`
- `==` and `!=`
- `&`
- `^`
- `|`
- `&&`
- `||`
- `=` or any of compound assignments `=op`

[See for operator overloading](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/operator-overloading).



## Basic programming (call flow and methods)

### If-else

```
if (booleanCondition1)
{
...
}
else if (booleanCondition2)
{
...
}
else
{
...
}
```

### Switch

Unlike C++ switch `case`s can have various [patterns](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/patterns) in addition to constants as well as case guards (`when`)!


```
switch ((a, b))
{
    case (> 0, > 0) when a == b:
        Console.WriteLine($"Both are positive and equal to {a}.");
        break;

    case (> 0, > 0):
        Console.WriteLine($"First  is {a}, second is {b}.");
        break;

    default:
        Console.WriteLine("One or both are negative.");
        break;
}
```

In addition to `switch` statement there is a `switch` expression (C# 8).

```
string Choose(int param) => param switch
{
    > 0 => "positive",
    < 0 => "negative",
    _ => "zero"
};
```

### for loop

The standard initializer, condition, iterator trio fantasticus :).

```
for (var i = 0; i < 3; i++)
{
    Console.Write(i);
}
```

### foreach loop

Loop over `IEnumerable` or `IEnumerable<T>` or any type that has:

- `GetEnumerator` public method with no parameter
- the return type of `GetEnumerator` has `Current` property and `MoveNext` method that returns `bool`

```
foreach (var element in new List<int> { 1, 2, 3, 4, 5 })
{
    Console.Write($"{element} ");
}
```

There is also `await foreach` for `IAsyncEnumerable<T>`....

### do loop

```
var n = 0;
do
{
    n++;
} while (n < 5);

```


### while loop

```
var n = 0;
while (n < 5)
{
    n++;
}
```


### break/continue

`break` and `continue` can be used as in similar languages to break out from loop or continue with next iteration.


### exceptions

All exceptions are derived from `Exception`. `throw` is used to throw them (or rethrow if used on its own!).
`try`/`catch`/`finally` is used to create structured exception handling block. As usual, catch blocks need to be in most specific then least specific order.

**Note**: `catch` can have `when` filter restriction (so catch selection is based on additional restriction, not just exception type)! Using filter is preferable over catching and rethrowing (because exception stack is left "unharmed").

**Note**: When catching and throwing different exception it is strongly preferred to include original exception as an inner exception of the new, different, one.

```
for (var i = 0; i < 3; i++)
{
    Console.WriteLine(i);
    try
    {
        switch (i)
        {
            case 0:
            case 1:
                throw new ApplicationException("Exception case 0 and 1");
            case 2:
                throw new Exception("Exception case 2");
        }
    }
    catch (ApplicationException ex) when (i == 0)   
    {
        Console.WriteLine("Zero ApplicationException: " + ex.Message);
    }
    catch (ApplicationException ex)
    {
        Console.WriteLine("ApplicationException: " + ex.Message);
    }
    catch (Exception ex)
    {
        Console.WriteLine("Exception: " + ex.Message);
    }
    finally
    {
        Console.WriteLine("Finally");
    }
}
```

## Arrays and Collections

All arrays are derived from `Array` and implement `IList` and `IEnumerable` (`IList<T>` and `IEnumerable<T>` for one dimensional arrays). They all have fixed size (determined at creation time) unlike collections.

### one dimensional arrays

As in similar languages declared via:

- `type[]/var arrayName = new type[arrayLength];`
- `type[] arrayName = { item1, item2, .... itemn };`
- `var arrayName = new type[] { item1, item2, .... itemn };` 
- `var arrayName = new[] { item1, item2, .... itemn };` 

Members accessed via `[]` like `arrayName[2] = 3`, all arrays have `Length` property where their size is stored.

`for` loop can be used to traverse arrays in traditional by index fashion, `foreach` too since `IEnumerable` is implemented.

```
var intArr = new int[] { 10, 20, 30, 40, 50, 60 };
var longArr = new[] { 1L, 2, 3, 4, 5 };


System.Console.WriteLine(intArr.Length);
for (var i = 0; i < intArr.Length; i++)
    System.Console.WriteLine(intArr[i]);

System.Console.WriteLine(longArr.Length);
foreach (var item in longArr)
    System.Console.WriteLine(item);

System.Console.WriteLine(String.Join(", ", intArr));

System.Console.WriteLine(String.Join(", ", longArr));
```

### multi-dimensional arrays

Arrays can have multiple dimensions, declared as:

- `type[,,]/var arrayName = new type[dim1Len, dim2Len, dim3Len];`
- `type[,,] arrayName = { { { 1, 2 }, { 3, 4 }, { 5, 6 } }, { { 11, 12 }, { 13, 14 }, { 15, 16 } }, { { 21, 22 }, { 23, 24 }, { 25, 26 } } };`
- `var arrayName = new type[,,] { { { 1, 2 }, { 3, 4 }, { 5, 6 } }, { { 11, 12 }, { 13, 14 }, { 15, 16 } }, { { 21, 22 }, { 23, 24 }, { 25, 26 } } };`
- `var arrayName = new[,,] { { { 1, 2 }, { 3, 4 }, { 5, 6 } }, { { 11, 12 }, { 13, 14 }, { 15, 16 } }, { { 21, 22 }, { 23, 24 }, { 25, 26 } } };`

Members accessed via `[,,]` like `arrayName[2,3,4] = 3`, all arrays have `GetLength` method which returns size of the dimension provided as parameter.

```
var multiIntArr = new int[,,] { { { 1, 2 }, { 3, 4 }, { 5, 6 } }, { { 11, 12 }, { 13, 14 }, { 15, 16 } }, { { 21, 22 }, { 23, 24 }, { 25, 26 } } };

for (var i = 0; i < multiIntArr.GetLength(0); i++)
    for (var j = 0; j < multiIntArr.GetLength(1); j++)
        for (var k = 0; k < multiIntArr.GetLength(2); k++)
            System.Console.WriteLine(multiIntArr[i, j, k]);

foreach(var item in multiIntArr)
{
    System.Console.WriteLine(item);
}
```

### jagged arrays

Jagged arrays are arrays of arrays (whose dimensions may differ) as in many similar languages.

```
var jaggedIntArr = new int[3][];
jaggedIntArr[0] = new[] { 1, 2, 3};
jaggedIntArr[1] = new[] { 11, 12 };
jaggedIntArr[2] = new[] { 21, 22, 23, 24 };


for (var i = 0; i < jaggedIntArr.Length; i++)
    for (var j = 0; j < jaggedIntArr[i].Length; j++)
        System.Console.WriteLine(jaggedIntArr[i][j]);

foreach(var item in jaggedIntArr)
    foreach (var innerItem in item)
        System.Console.WriteLine(innerItem);
```

### Array class methods and properties

Some of the properties:

- `Length` - total number of elements in all the dimensions 
- `Rank` - number of dimensions
- `SyncRoot` - object used to synchronize access to array

Some of the methods:

- `BinarySearch`
- `Clear` - sets all members to default value
- `ConstrainedCopy`, `Copy`, `CopyTo` - copy items from one array to another
- `ConvertAll` - convert array of one type to another
- `Empty` - returns empty array
- `Find`, `FindAll`, `IndexOf`, `LastIndexOf`, `FindIndex`, `FindLast`, `FindLastIndex` - find elements in array 
- `ForEach` - perform specified action on all elements
- `GetLength` - number of elements in the specified dimension
- `Resize`
- `Reverse`
- `Sort`
- `TrueForAll`, `Exists` - find if all or single element satisfy a condition/predicate

### arrays as method parameters

You can pass arrays as method parameter (**passed by reference!**) in usual fashion.

**However**, if you prefix parameter type with `params` keyword then the method will also accept a list of items as parameters in addition to array itself.

```
void PrintArr(int[] arr)
{
    foreach (var item in arr)
        Console.WriteLine(item);
}

void PrintParamsArr(params int[] arr)
{
    PrintArr(arr);
}

PrintArr(new [] { 1, 2, 3 });
//PrintArr(1, 2, 3); // cannot pass a list of items here!
PrintParamsArr(new[] { 10, 20, 30 });
PrintParamsArr(100, 200, 300); // can pass a list of items here!
```

See [here](https://docs.microsoft.com/en-us/dotnet/api/system.array) for all methods and properties.

### Collections

Collections are classes that can grow/shrink in size of elements they contain.

`IList` based are:

- [List<T>](https://docs.microsoft.com/en-us/dotnet/api/system.collections.generic.list-1) - uses an array whose size is dynamically increased as required (fast to access members by index, slow to insert in the middle)
- [Queue<T>](https://docs.microsoft.com/en-us/dotnet/api/system.collections.generic.queue-1) - first in first out
- [PriorityQueue<TElement,TPriority>](https://docs.microsoft.com/en-us/dotnet/api/system.collections.generic.priorityqueue-2) - first with lowest priority out
- [Stack<T>](https://docs.microsoft.com/en-us/dotnet/api/system.collections.generic.stack-1) - last in first out
- [LinkedList<T>](https://docs.microsoft.com/en-us/dotnet/api/system.collections.generic.linkedlist-1) - no indexed access, fast insertions and deletions

`IDictionary` based are:

- [Dictionary<TKey,TValue>](https://docs.microsoft.com/en-us/dotnet/api/system.collections.generic.dictionary-2) - maps keys to values
- [SortedList<TKey,TValue>](https://docs.microsoft.com/en-us/dotnet/api/system.collections.generic.sortedlist-2) and [SortedDictionary<TKey,TValue>](https://docs.microsoft.com/en-us/dotnet/api/system.collections.generic.sorteddictionary-2)- sorted mapping of keys to values

There are also `ISet` based ones like [HashSet<T>](https://docs.microsoft.com/en-us/dotnet/api/system.collections.generic.hashset-1) and [SortedSet<T>](https://docs.microsoft.com/en-us/dotnet/api/system.collections.generic.sortedset-1) who add mathematical like union/difference capabilities.

[Help on choosing between various collections here!](https://docs.microsoft.com/en-us/dotnet/standard/collections/#choose-a-collection).

There are also various [concurrent](https://docs.microsoft.com/en-us/dotnet/api/system.collections.concurrent) and [immutable](https://docs.microsoft.com/en-us/dotnet/api/system.collections.immutable) "versions" of each of the collections.

## Object oriented programming

### class

Class is defined using `class` keyword and can have following members:

 - fields - representing variables
 - instance constructors - to initialize members of class instances
 - static constructor - to initialize the class itself
 - constants - representing constant values
 - properties - define the class features and include actions to fetch and modify them
 - indexers - special properties that help in accessing class instances similar to arrays
 - methods - providing actions on its members
 - events - generated to communicate between different classes /objects
 - operators - that define semantics when used in expressions with class instances
 - finalizers - to execute actions necessary to be performed before class instances are discarded
 
 Each of the members can have following accessibility (default is `private`):

 - `public` – accessible by any code within current or external assembly
 - `protected` – accessible within the same class or its derived class
 - `private` – accessible within the same class
 - `internal` – accessible within current assembly
 - `protected internal` – accessible within current assembly or classes derived from containing class 
 - `private protected` – accessible within class or classes derived from containing class within current assembly 

 Class can derive from single base class only but can implement any number of interfaces.
 
### static

 A `static` class cannot be instantianed and can be used to hold static members only.

 A `static` class member can be used (through class name) even without any class instance, and only one per class exists (regardless of how many instances were created).

### fields

A field is a variable that is declared in a class (or struct). It is best practice to use them with `private` or `protected` accessibility. Data exposed to public should be accessed through methods, properties or indexers.

```
class Cls
{
    private string myFirstField;
}
```

### constructors

Constructor is a method whose name is same as class name. Instance constructor is called whenever an instance of this class is created (using `new`), static constructor is called only once. Static constructor cannot have parameters and has no access modifiers.

Constructor calls can be forwarded using `this` keyword. This can be used to write (copy) constructors without code duplication.

```
var cls1 = new Cls();
var cls2 = new Cls("Foo");
var cls3 = new Cls(cls2);

class Cls
{
    private readonly string _name;
    public Cls(in string name = "Some name")
    {
        // instance constructor
        Console.WriteLine("Instance " + name + " created");
        _name = name;
    }

    public Cls(in Cls other)
        : this(other._name)
    {
    }

    static Cls()
    {
        // static constructor
        Console.WriteLine("Class created");
    }
}
```

### constants

 `const` is used to declare constants (builtin types, immutable, value know at compile time). They are inherently static (accessed using class name and not instance).

 `readonly` is used to declare "constants" that are initialized once during runtime and cannot be changed afterwards.

```
var cls = new Cls("Foo");

// Cls.Name = "Bar"; // cannot be modified
// cls.MyName = "Bar"; // cannot be modified
Console.WriteLine(cls.MyName);
Console.WriteLine(Cls.Name);

class Cls
{
    public const string Name = "My Class";

    public readonly string MyName;

    public Cls(in string clsName) { MyName = Name + " " + clsName; }
}
```

### properties

Properties expose a public way of getting and setting values (as data members), while hiding implementation or verification code (hidden in accessor methods). It consists of (up to three) accessor methods:

- `get` - returns a value
- `set` - sets a value using keyword `value`
- `init` - sets a value using keyword `value` **during construction only** (cannot be used together with set, doesn't make sense to have both)

Depending on which of the `get` or `set` are defined property can be read only, write only, or read write.

Properties are usually implemented by having a private backing field (but this one can be omitted in simple cases).

**Note**: property itseld defines it accessibility level but also each accessor can set its own, hence, for example, you can have properties that are read only for public but read write withing class itself.

```
var distance1 = new Distance(10.5, "Ten and half");

Console.WriteLine($"{distance1.Name}: {distance1.Meters:0.000}m {distance1.Yards:0.000}yd {distance1.Kilometers:0.000}km");

distance1.Yards = 100;
distance1.Name = "100 Yards";

Console.WriteLine($"{distance1.Name}: {distance1.Meters:0.000}m {distance1.Yards:0.000}yd {distance1.Kilometers:0.000}km");

class Distance
{
    private const double YardsToMeters = 0.9144;
    private const double MetersToKilo = 0.001;
    
    public Distance(double meters, string name)
    {
        Meters = meters;
        Name = name;
    }

    // property with backing field and "normal" methods
    private double _meters;
    public double Meters {
        get { return _meters; }
        set
        {
            if (value < 0)
                throw new ArgumentOutOfRangeException(nameof(value), "Must be positive");

            _meters = value;
        }
    }

    // expression body implemented methods
    public double Yards
    {
        get => Meters / YardsToMeters; 
        set => Meters = value * YardsToMeters;  
    }

    // expression body read only implemented methods
    public double Kilometers => Meters * MetersToKilo;

    // auto implemented 
    public string Name { get; set; }
}
```

### object initialization

Public members of an object can be initialized during construction using `{}` braces in a single statement.

```
var john = new Person("John", "Wayne");
var clint = new Person("Clint") { Surname = "Eastwood" };
var james = new Person { Name = "James", Surname = "Stewart" };

Console.WriteLine(john);
Console.WriteLine(clint);
Console.WriteLine(james);

class Person
{
    public string Name { get; init; }
    public string Surname { get; init; }

    public Person(string name = "", string surname = "")
    {
        Name = name;
        Surname = surname;  
    }

    public override string ToString() => $"{Name} {Surname}";
}
```

### indexers

Indexer is a special property that enables type to be used in an array like fashion and is declared using `this` keyword. Indexer cannot be static and cannot be auto-implemented.

```
class MyIntArray
{
    // Declare an array to store the data elements.
    private int[] arr = new int[100];

    // Define the indexer to allow client code to use [] notation.
    public int this[int i]
    {
        get {
            if (i < 0 || i > arr.Length)
                throw new ArgumentOutOfRangeException("Index must be valid");
            return arr[i];
        }
        set {
            if (i < 0 || i > arr.Length)
                throw new ArgumentOutOfRangeException("Index must be valid");
            arr[i] = value;
        }
    }
}
```

### method definition and invocation

Methods are defined as in similar languages using method name and parameter list.

**When invoked parameters can be positional or named!**

```
void PrintThree(int first = 1, int second = 2, int third = 3) { 
    Console.WriteLine($"{first} {second} {third}"); 
}

PrintThree();                                // default values, 1 2 3
PrintThree(5, 3, 1);                         // positional, 5 3 1
PrintThree(second: 10, third: 20, first: 5); // named, 5 10 20
PrintThree(10, third: 20);                   // mixed with default, 10 2 20
```

Arguments are passed by value but `ref` keyword can be added in front of type to pass by reference.
In addition `out` keyword can be used for output only parameters (like `ref` but without need to be initialized).
On the other hand `in` keyword can be used for passing by reference but cannot be modified inside method.
**Note**: `ref` and `out` modifiers will need to be used when invoking method too!

```
void Method(string a) { a = "trt"; }
void MethodIn(in string a) { /* a = "trt";*/  }
void MethodRef(ref string a) { a = "ref"; }
void MethodOut(out string a) { a = "out"; }

var s = "one";

MethodIn(s);
Console.WriteLine(s);  // one, copy is passed to method

Method(s);
Console.WriteLine(s);  // one, method cannot modify

MethodRef(ref s);
Console.WriteLine(s);  // ref

string s2;
MethodOut(out s2);     // can be uninitialized
Console.WriteLine(s2); // out
MethodOut(out var s3); // variable declared as part of method invocation
Console.WriteLine(s3); // out

```

**Note**: Beware of the difference of passing value types by value and passing reference types by value explained [here](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/classes-and-structs/how-to-know-the-difference-passing-a-struct-and-passing-a-class-to-a-method). In short changes to value types are not visible outside (because whole instance is copied for method) but changes to reference types are visible (just the reference is copied but points to same instance).


Simple methods (having one single statement) can be written concisely in expression body definition (using `=>`)

```
int Add(int a, int b) => a + b;
```

Methods/functions can be embedded one inside another. Unless `static` such methods have access to params and local variables of outer method.

```
void ProcessMe(int a)
{
    void InnerProcess(int b)
    {
        Console.WriteLine(a);
        Console.WriteLine(b);
    }

    Console.WriteLine(a);
    InnerProcess(a+1);
}

ProcesMe(1);
```


Inside instance methods, as usual, one can access all members of the enclosing class as well as base ones (protected, public) and can use `this` to access instance member (if needed for disambiguation or passing instance as method parameter) and `base` to access base class if needed.



A discard `_` can be used in place of, `out`, method argument if its value is not needed.

```
if (int.TryParse("100", out _))
    Console.WriteLine("Valid integer");
else
    Console.WriteLine("Invalid integer");
```

**Note**: discard is also used in switch expression for default action value, and can be used in deconstruction expressions also to ignore some values, even standa alone to, clearly, discard value of some expression.

### extension methods

Used to add methods to existing types without creating a new derived type. Static but called as if instance methods, first parameter has `this` modifier.

```
using System.Linq;

Console.WriteLine("America".ReplaceAllAAAAs());

public static class CustomExtensions
{
    public static string ReplaceAllAAAAs(this string str)
    {
        return str.Replace('A', 'E').Replace('a', 'e');
    }
}
```

Name (extension method with same name as existing instance method) collisions are resolved in favor of the instance or static method defined by the type itself and extension methods cannot access any private data in the extended class.

Extension methods can be used to extend enums too.

### events

Events enable publisher/subscriber style communication between objects using `event` and `delegate` keywords.

``` 
var pub = new Publisher();
var sub1 = new Subscriber("Sub1");
var sub2 = new Subscriber("Sub2");

pub.SampleEvent += sub1.SampleEventHandler; // subscribe
pub.SampleEvent += sub2.SampleEventHandler; // subscribe

pub.RaiseSampleEvent("world"); // two subscribers

pub.SampleEvent -= sub1.SampleEventHandler; // unsubscribe

pub.RaiseSampleEvent("again"); // one subscribers


public class Publisher
{
    // definition of delegate
    public delegate void SampleEventHandler(object sender, string e);

    public event SampleEventHandler SampleEvent;

    public virtual void RaiseSampleEvent(string suffix)
    {
        SampleEvent?.Invoke(this, "Hello " + suffix);
    }
}

public class Subscriber
{
    private readonly string _name;
    
    public Subscriber(string name) { _name = name; }

    // must match definition of delegate
    public void SampleEventHandler(object sender, string e)
    {
        Console.WriteLine($"{_name} {e}");
    }
}
```

### anonymous methods and lambda expressions

Anonymous method is a method without a name, can be defined using the `delegate` keyword and can be assigned to a variable of delegate type. 

Lambda is another way declarin anonymous functions using `=>` and can be single expression following `=>` or multiple statements inside `{}` following `=>`.

Both ways of declaring anonymous methods have access to variables in the scope where they were declared.

```
var pub = new Publisher();

var cnt = 0;

// anonymous method
pub.SampleEvent += delegate (object sender, string e)
{
    Console.WriteLine("First " + e + cnt);
};

// expression lambda
pub.SampleEvent += (object sender, string e) => Console.WriteLine("Second " + e + cnt);

// statement lambda
pub.SampleEvent += (object sender, string e) => { Console.WriteLine("Third " + e); Console.WriteLine("Fourth " + e + cnt); };

pub.RaiseSampleEvent("world"); // two subscribers


public class Publisher
{
    // definition of delegate
    public delegate void SampleEventHandler(object sender, string e);

    public event SampleEventHandler SampleEvent;

    public virtual void RaiseSampleEvent(string suffix)
    {
        SampleEvent?.Invoke(this, "Hello " + suffix);
    }
}
```

### operators

User defined types can have custom implementation of operators using `operator` keyword which must:

- be public static
- have two input parameters of that type if binary operator, or one if unary.

For more info with an example see [here](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/operator-overloading).

Same keyword is used in conversion user defined operations, see [here](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/user-defined-conversion-operators).

```
var k1 = (Kilometer)123.5;
var k2 = (Kilometer)321.6;

Console.WriteLine($"{k1 + k2}km or {(Mile)(k1 + k2)}mi");

class Kilometer
{
    private const double KilometerToMile = 0.621371192;
    public Kilometer(double value)
    {
        Value = value;
    }

    public double Value { get; init; }  

    public static Kilometer operator + (Kilometer k1, Kilometer k2) => new Kilometer(k1.Value + k2.Value);
    public static implicit operator Mile(Kilometer k) => new Mile(k.Value * KilometerToMile);
    public static explicit operator Kilometer(double v) => new Kilometer(v);
    public override string ToString() => $"{Value}";
}

class Mile
{
    public Mile(double value)
    {
        Value = value;
    }

    public double Value { get; init; }
    public override string ToString() => $"{Value}";
}
```


**Note**:
- if you overload `==` must also overload `Equals`, and use `Equals` to implement `operator ==` (make sure to test for `null` values before calling `Equals`, two `null` should be equal)!
- operators come in pairs, if `==` is overloaded so should be `!=`!
- if `Equals` is overloaded so must be `GetHashCode` cause instances who are equal must return same hash code!


### finalizer

[Finalizers](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/classes-and-structs/finalizers) are invoked when instance is being collected by the garbage collector which you cannot know when (and even if) will happen.

If explicit cleanup is required class should implement [IDisposable](https://docs.microsoft.com/en-us/dotnet/api/system.idisposable) interface instead and use `using` statements or `using` variables for such objects.


```
using (var res = new Resource())
{
    res.Work();
}

{
    using var res2 = new Resource();
    res2.Work();
}

public class Resource : IDisposable
{
    private bool disposed = false;

    public Resource()
    {
        Console.WriteLine("Creating resource");
    }

    public void Work()
    {
        Console.WriteLine("Doing something with resource");
    }

    public void Dispose()
    {
        Dispose(disposing: true);
    }

    protected virtual void Dispose(bool disposing)
    {
        if (!this.disposed)
        {
            if (disposing)
            {
                Console.WriteLine("Dispose managed resources");
                // Dispose managed resources.
            }

            Console.WriteLine("Cleanup unmanaged resources");
            // Call the appropriate methods to clean up
            // unmanaged resources here.

            disposed = true;
        }
    }

    ~Resource()
    {
        Dispose(disposing: false);
    }
}
```

### polymorphism

 Base class has `virtual` (or `abstract`) methods that derived one can `override`. In addition derived one can hide members of base by declaring its `new` member. 

 **Note:** if `override` is forgotten the virtual base method won't be derived, just hidden!

```
Base baseDerived = new Derived();
Derived derived = new Derived();

baseDerived.Virtual();         // Derived::Virtual - true virtual call
baseDerived.HiddenVirtual();   // Base::HiddenVirtual - base called because type is Base and derived implementation hides base not overrides 
baseDerived.NonVirtual();      // Base::NonVirtual - base called because type is Base and derived implementation hides base not overrides 

derived.Virtual();             // Derived::Virtual
derived.HiddenVirtual();       // Derived::HiddenVirtual
derived.NonVirtual();          // Derived::NonVirtual

class Base
{
    public virtual void Virtual()
    {
        Console.WriteLine("Base::Virtual");
    }

    public virtual void HiddenVirtual()
    {
        Console.WriteLine("Base::HiddenVirtual");
    }

    public void NonVirtual()
    {
        Console.WriteLine("Base::NonVirtual");
    }
}

class Derived : Base
{
    public override void Virtual()
    {
        Console.WriteLine("Derived::Virtual");
    }

    public void HiddenVirtual()
    {
        Console.WriteLine("Derived::HiddenVirtual");
    }

    public new void NonVirtual()
    {
        Console.WriteLine("Derived::NonVirtual");
    }
}
```

### abstract and sealed

 An `abstract` class cannot be instantiated and only such a class can have `abstract` method that has no implementation (derived class will implement).

 On the other hand a `sealed` class cannot be used as a base class, and a `sealed` method negates virtual aspect of it for any derived class.

 ### partial 

 Class declaration can be spread across several files using `partial` keyword.
 
### interfaces

Interfaces, `interface` keyword instead of `class` are contracts containing member definitions that must be implemented in any class/struct that implements this interface. Members can be methods, properties, indexers or events.

**Class can inherit from single class only but can implement number of interfaces!!!**

**Note**: Explicit interface method implementation can be used for members that can be invoked trough interface only!

**Note**: C# 8 and above, an interface may have default implementation as well as static members as well as constants, operatoes, static members, etc...

**Note**: C# 11 and above, an interface define `static abstrac/virtual` members typically used for overloaded operators.

**Note**: Auto property defined in interface doesn't actually implement it with hidden field, it just defines it!

```
IInterface obj = new Implementation { Name = "Test" };
obj.Method();
obj.Method2();
obj.Method3();
// not part of the interface
//obj.Method4(); 
Console.WriteLine(obj.Name);

Implementation obj2 = new Implementation { Name = "Test2" }; ;
// uses explicit interface member implementation so cannot be called through class type
//obj2.Method(); 
obj2.Method2();
// default implementation cannot be called through class type
//obj2.Method3(); 
obj2.Method4();
Console.WriteLine(obj2.Name);

interface IBaseInterface
{
    void Method();
    void Method2();
}

interface IInterface : IBaseInterface
{
    string Name { get; set; } // just a definition
    void Method3()
    {
        Console.WriteLine("IInterface::Method3");
    }
}

class Implementation : IInterface
{
    public string Name { get; set; } = default!; // actual implementation

    // Explicit interface member implementation:
    void IBaseInterface.Method()
    {
        Console.WriteLine("Implementation::Method");
    }
    public void Method2()
    {
        Console.WriteLine("Implementation::Method2");
    }
    public void Method4()
    {
        Console.WriteLine("Implementation::Method4");
        // how to call interface default implementation in implementing class
        ((IInterface)this).Method3(); 
    }
}
```

See more [here](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/interface).



### records

With C# 9, you use the `record` defines a reference type providing built-in functionality for encapsulating data. C# 10 allows the `record class` syntax as a synonym, and `record struct` to define a value type with similar functionality. It provides concise syntax (also called positional records, see note below), value equality, built-in formatting, and inheritance for `record class`es. `with` expression can be used for mutation (create new record based on existing one).

**Note**: Concise syntax `record` and a `readonly record struct` declare init-only properties, `record struct` declares read-write properties. This can be overridden by hand.

```
var order = new Order("Apples", 10.10, 10);
var saleOrder = order with { Price = 5.5 };

// order.ItemName = "Oranges"; // concise syntax creates read-only properties
Console.WriteLine(order);
Console.WriteLine(saleOrder);

var mutableOrder = new MutableOrder("Oranges", 20.20, 5);
mutableOrder.ItemName = "Pineapples";
Console.WriteLine(mutableOrder);

var (name, price, quantity) = mutableOrder; // deconstruction
Console.WriteLine((name, price, quantity));

record Item(string ItemName, double Price);
record Order(string ItemName, double Price, int Quantity) : Item(ItemName, Price);


record MutableItem(string ItemName, double Price)
{
    public string ItemName { get; set; } = ItemName;
    public double Price { get; set; } = Price;
}

record MutableOrder(string ItemName, double Price, int Quantity) : MutableItem(ItemName, Price)
{
    public int Quantity { get; set; } = Quantity;
}

```

### generics

Generic methods/class is a method which has a number of type parameters that are resolved only when class/methods is instantiated/invoked in client code.

```
using System.Collections;

var crazy = new CrazyList<int>();

crazy.Add(1);
crazy.Add(2);
crazy.Add(3);
crazy.Add(4);
crazy.Add(5);

foreach (var item in crazy)
    Console.WriteLine(item);

class CrazyList<T> : IEnumerable<T>
{
    private List<T> list = new();

    public IEnumerator<T> GetEnumerator() => ((IEnumerable<T>)list).GetEnumerator();
    IEnumerator IEnumerable.GetEnumerator() => list.GetEnumerator();
    public void Add(in T item) 
    {
        if (list.Count % 2 == 0)
            list.Add(item);
        else
            list.Insert(0, item);
    }

}
```

Generic type can be further constrained by using `where` keyword. Constrain can specify that:
- `T` must be some class `class Generic<T> where T: SomeClass`
- `T` must implement some interface `class Generic<T> where T: IComparable<T>`
- `T` must be a class `class Generic<T> where T: class`
- `T` must be a struct `class Generic<T> where T: struct`
- `T` must have default constructor `class Generic<T> where T: new()`

Constraints can be combined `class Generic<T> where T: class, IComparable<T>, new()`.

### anonymous types

Set of **read-only** properties encapsulated in an object without explicit object definition. Created using `new` and curly braces object initialization. `with` expression can be used to for "mutation".

```
 var orderItem = new { Quantity = 2, UnitPrice = 10.10, Name = "Apples" };
var order = new[] {
    new { Quantity = 2, UnitPrice = 10.10, Name = "Apples" },
    new { Quantity = 3, UnitPrice = 20.10, Name = "Oranges" }
};

var saleOrderItem  = orderItem with { UnitPrice = 5.5 };

Console.WriteLine(orderItem.Quantity);
Console.WriteLine(saleOrderItem.UnitPrice);
Console.WriteLine(order[0].Name);
```

### deconstructing to tuple

`Deconstruct` method(s) can be used as part of class/struct to support deconstructing to tuple (it can also be an extension method). Compiler automatically generates this method for `record`s.

```
var john = new Person { Name = "John", Surname = "Wayne" };

var (name, surname) = john;
Console.WriteLine(name);
Console.WriteLine(surname);

class Person
{
    public string Name { get; init; }
    public string Surname { get; init; }

    public void Deconstruct(out string name, out string surname)
    {
        name = Name;
        surname = Surname;
    }
}
```

## Runtime libraties, a.k.a. some of .NET classes

### File operations

- [Directory](https://docs.microsoft.com/en-us/dotnet/api/system.io.directory) - creating, moving, and enumerating through directories and subdirectories
- [File](https://docs.microsoft.com/en-us/dotnet/api/system.io.file) - creation, copying, deletion, moving, and opening of a single file
- [Path](https://docs.microsoft.com/en-us/dotnet/api/system.io.path) - cross platform operations on strings containing path information
- [FileStream](https://docs.microsoft.com/en-us/dotnet/api/system.io.filestream) - provides stream from a file
- [StreamReader](https://docs.microsoft.com/en-us/dotnet/api/system.io.streamreader) - reads characters from a stream in an encoding
- [StreamWriter](https://docs.microsoft.com/en-us/dotnet/api/system.io.streamwriter) - writes characters to a stream in an encoding
- [BinaryReader](https://docs.microsoft.com/en-us/dotnet/api/system.io.binaryreader) - reads primitive types and strings from binary file
- [BinaryWriter](https://docs.microsoft.com/en-us/dotnet/api/system.io.binarywriter) - writes primitive types and strings from binary file

```
using System.IO;
using System.Text;

var tmpFolder = Path.Combine(Directory.GetCurrentDirectory(), "tmp");
if (!Directory.Exists(tmpFolder))
    Directory.CreateDirectory(tmpFolder);

try
{
    var tmpFile = Path.Combine(tmpFolder, "tmp.txt");
    if (File.Exists(tmpFile))
        File.Delete(tmpFile);

    using (FileStream fs = File.Create(tmpFile))
    {
        var bytes = new UTF8Encoding(true).GetBytes("This is some text");
        fs.Write(bytes);
    }

    var newTmpFile = Path.ChangeExtension(tmpFile, "log");
    if (File.Exists(newTmpFile))
        File.Delete(newTmpFile);
    File.Move(tmpFile, newTmpFile);

    using (FileStream fs = File.OpenRead(newTmpFile))
    {
        var bytes = new byte[fs.Length];
        fs.Read(bytes);
        var text = new UTF8Encoding(true).GetString(bytes);
        Console.WriteLine(text);
    }

    using (StreamWriter sw = File.CreateText(tmpFile))
    {
        sw.WriteLine("Hello");
        sw.WriteLine("My");
        sw.WriteLine("First");
        sw.WriteLine("Text");
        sw.WriteLine("File");
    }

    using (StreamReader sr = File.OpenText(tmpFile))
    {
        string? s;
        while ((s = sr.ReadLine()) != null)
        {
            Console.WriteLine(s);
        }
    }

    var binTmpFile = Path.ChangeExtension(tmpFile, "bin");
    if (File.Exists(binTmpFile))
        File.Delete(binTmpFile);

    using (var stream = File.Open(binTmpFile, FileMode.Create))
    {
        using (var writer = new BinaryWriter(stream, Encoding.UTF8, false))
        {
            writer.Write(21.051976);
            writer.Write("Some text");
            writer.Write(2105);
            writer.Write(false);
        }
    }

    using (var stream = File.Open(binTmpFile, FileMode.Open))
    {
        using (var reader = new BinaryReader(stream, Encoding.UTF8, false))
        {
            Console.WriteLine(reader.ReadDouble());
            Console.WriteLine(reader.ReadString());
            Console.WriteLine(reader.ReadInt32());
            Console.WriteLine(reader.ReadBoolean());
        }
    }

    foreach (var file in Directory.EnumerateFiles(tmpFolder))
    {
        Console.WriteLine(file);
    }

    Directory.Delete(tmpFolder, true);
}
catch (IOException ex)
{
    Console.WriteLine(ex);
}

```

### XML operations

- [XmlWriter](https://learn.microsoft.com/en-us/dotnet/api/system.xml.xmlwriter) - fast forward-only way to generate XML
- [XmlReader](https://learn.microsoft.com/en-us/dotnet/api/system.xml.xmlreader) - fast forward-only way to read XML
- [XmlDocument](https://learn.microsoft.com/en-us/dotnet/api/system.xml.xmldocument) - in-memory representation of an XML document, implements the Document Object Model
- [XmlSerializer](https://learn.microsoft.com/en-us/dotnet/api/system.xml.serialization.xmlserializer) - serializes and deserializes objects into and from XML 

```
using System.IO;
using System.Text;
using System.Xml;
using System.Xml.Serialization;

var tmpFolder = Path.Combine(Directory.GetCurrentDirectory(), "tmp");
if (!Directory.Exists(tmpFolder))
    Directory.CreateDirectory(tmpFolder);

try
{
    var tmpFile = Path.Combine(tmpFolder, "tmp.xml");
    if (File.Exists(tmpFile))
        File.Delete(tmpFile);

    var settings = new XmlWriterSettings();
    settings.Indent = true;
    settings.Encoding = Encoding.UTF8;

    using (var writer = XmlWriter.Create(tmpFile, settings))
    {
        writer.WriteComment(" a list of actors ");
        writer.WriteStartElement("", "actors", "");
        writer.WriteStartElement("", "actor", "");
        writer.WriteAttributeString(null, "dob", null, "26th May 1907");
        writer.WriteStartElement("", "name", "");
        writer.WriteString("John");
        writer.WriteEndElement();
        writer.WriteStartElement("", "surname", "");
        writer.WriteString("Wayne");
        writer.WriteEndElement();
        writer.WriteEndElement();
        writer.WriteStartElement("", "actor", "");
        writer.WriteAttributeString(null, "dob", null, "31st May 1930");
        writer.WriteStartElement("", "name", "");
        writer.WriteString("Clint");
        writer.WriteEndElement();
        writer.WriteStartElement("", "surname", "");
        writer.WriteString("Eastwood");
        writer.WriteEndElement();
        writer.WriteEndElement();
        writer.WriteEndElement();
        writer.Flush();
    }

    using (var reader = XmlReader.Create(tmpFile))
    {
        while (reader.Read())
        {
            Console.WriteLine("Node type {0}", reader.NodeType);
            switch (reader.NodeType)
            {
                case XmlNodeType.Element:
                    Console.WriteLine("Start Element {0}", reader.Name);
                    if (reader.HasAttributes)
                    {
                        for (var i = 0; i < reader.AttributeCount; i++)
                        {
                            Console.WriteLine("Attribute: {0} {1}", i, reader.GetAttribute(i));
                        }
                    }
                    break;
                case XmlNodeType.Text:
                    Console.WriteLine("Text Node: {0}", reader.Value);
                    break;
                case XmlNodeType.EndElement:
                    Console.WriteLine("End Element {0}", reader.Name);
                    break;
                case XmlNodeType.Comment:
                    Console.WriteLine("Comment {0}", reader.Value);
                    break;
                case XmlNodeType.Whitespace:
                case XmlNodeType.XmlDeclaration:
                    break;
                default:
                    Console.WriteLine("Other node {0} with value {1}",
                                    reader.NodeType, reader.Value);
                    break;
            }
        }
        reader.Close();
    }

    XmlDocument doc = new XmlDocument();
    doc.Load(tmpFile);
    XmlElement actor = doc.CreateElement("actor");
    XmlAttribute dob = doc.CreateAttribute("dob");
    dob.Value = "1st February 1901";
    XmlElement name = doc.CreateElement("name");
    name.InnerText = "Clark";
    XmlElement surname = doc.CreateElement("surname");
    surname.InnerText = "Gable";
    actor.Attributes.Append(dob);
    actor.AppendChild(name);
    actor.AppendChild(surname);
    doc.DocumentElement.AppendChild(actor);
    doc.Save(tmpFile);

    foreach (XmlNode childActor in doc.DocumentElement.ChildNodes)
    {
        Console.WriteLine("Actor {0} {1} {2}", childActor.FirstChild.InnerText, childActor.ChildNodes[1].InnerText, actor.Attributes[0].Value);
    }


    List<Actor> actors;

    using (var fs = File.OpenRead(tmpFile))
    {
        var serializer = new XmlSerializer(typeof(List<Actor>), new XmlRootAttribute("actors"));
        actors = (List<Actor>)serializer.Deserialize(fs);
    }

    foreach (var anActor in actors)
    {
        Console.WriteLine(anActor.ToString());
    }

    actors.Add(new Actor { Name = "Clint", Surname = "Eastwood", DOB = "31st May 1930" });

    using (var fs = File.Create(tmpFile))
    {
        var serializer = new XmlSerializer(typeof(List<Actor>), new XmlRootAttribute("actors"));
        serializer.Serialize(fs, actors);
    }

    Directory.Delete(tmpFolder, true);
}
catch (XmlException ex)
{
    Console.WriteLine(ex);
}
catch (IOException ex)
{
    Console.WriteLine(ex);
}

[XmlType("actor")]
public class Actor
{
    [XmlElement("name")]
    public string Name { get; set; }
    [XmlElement("surname")]
    public string Surname { get; set; }
    [XmlAttribute("dob")] 
    public string DOB { get; set; }

    public override string ToString() => $"{Name} {Surname} born at {DOB}";
}

```

### JSON operations

- [JsonSerializer](https://learn.microsoft.com/en-us/dotnet/api/system.text.json.jsonserializer) - serializes and deserializes objects into and from JSON 
- [JsonDocument](https://learn.microsoft.com/en-us/dotnet/api/system.text.json.jsondocument) - a read-only in-memory JSON DOM representation, to be used when JSON has not preset schema so cannot convert to objects, (faster than JsonNode but immutable)
- [JsonNode](https://learn.microsoft.com/en-us/dotnet/api/system.text.json.nodes.jsonnode) - a mutable in-memory JSON DOM representation, to be used when JSON has not preset schema so cannot convert to objects,
- [Utf8JsonWriter](https://learn.microsoft.com/en-us/dotnet/api/system.text.json.utf8jsonwriter) - low level, high-performance, forward only, way to write UTF-8 encoded JSON text from common .NET types
- [Utf8JsonReader](https://learn.microsoft.com/en-us/dotnet/api/system.text.json.utf8jsonreader) - low level, high-performance, low allocation, forward only, way to read UTF-8 encoded JSON text


More info [here](https://learn.microsoft.com/en-us/dotnet/standard/serialization/system-text-json/how-to) and [here](https://learn.microsoft.com/en-us/dotnet/standard/serialization/system-text-json/use-dom-utf8jsonreader-utf8jsonwriter).

```
using System.Text;
using System.Text.Json;
using System.Text.Json.Nodes;

var actors = new List<Actor>();
actors.Add(new Actor { Name = "John", Surname = "Wayne", DOB = "26th May 1907" });
actors.Add(new Actor { Name = "Clint", Surname = "Eastwood", DOB = "31st May 1930" });
actors.Add(new Actor { Name = "Clark", Surname = "Gable", DOB = "1st February 1901" });

var options = new JsonSerializerOptions { WriteIndented = true };
string jsonString = JsonSerializer.Serialize(actors, options);
Console.WriteLine(jsonString);
// faster than Serialize to string
byte[] jsonUtf8Bytes = JsonSerializer.SerializeToUtf8Bytes(actors);

var actors2 = JsonSerializer.Deserialize<Actor[]>(jsonString);
foreach(var actor in actors2)
    Console.WriteLine(actor);
var actors3 = JsonSerializer.Deserialize<Actor[]>(jsonUtf8Bytes);

var node = JsonNode.Parse(jsonString);
Console.WriteLine($"Type={node.GetType()}");
node.AsArray().RemoveAt(1);
foreach (var element in node.AsArray())
{
    Console.WriteLine($"Type={element.GetType()}");
    foreach (var (name, value) in element.AsObject())
    {
        Console.WriteLine($"Name={name} Value={value}");
    }
}
var newActor = new JsonObject
{
    ["Name"] = "Gary",
    ["Surname"] = "Cooper",
    ["DOB"] = "7th May 1901",
    ["RealName"] = "Frank James"
};
node.AsArray().Add(newActor);
Console.WriteLine(node.ToJsonString(options));

using (var doc = JsonDocument.Parse(jsonString))
{
    foreach(var element in doc.RootElement.EnumerateArray())
    {
        foreach (var member in element.EnumerateObject())
        {
            Console.WriteLine($"Name={member.Name} Value={member.Value}");
        }
    }
}

{
    var options2 = new JsonWriterOptions
    {
        Indented = true
    };
    using var stream = new MemoryStream();
    using var writer = new Utf8JsonWriter(stream, options2);

    writer.WriteStartArray();
    writer.WriteStartObject();
    writer.WriteString("dob", "26th May 1907");
    writer.WriteString("name", "John");
    writer.WriteString("surname", "Wayne");
    writer.WriteEndObject();
    writer.WriteStartObject();
    writer.WriteString("dob", "31st May 1930");
    writer.WriteString("name", "Clint");
    writer.WriteString("surname", "Eastwood");
    writer.WriteEndObject();
    writer.WriteEndArray();
    writer.Flush();

    string json = Encoding.UTF8.GetString(stream.ToArray());
    Console.WriteLine(json);
}

var options3 = new JsonReaderOptions
{
    AllowTrailingCommas = true,
    CommentHandling = JsonCommentHandling.Skip
};
var reader = new Utf8JsonReader(jsonUtf8Bytes, options3);

while (reader.Read())
{
    Console.Write(reader.TokenType);

    switch (reader.TokenType)
    {
        case JsonTokenType.PropertyName:
        case JsonTokenType.String:
            Console.Write($" {reader.GetString()}");
            break;
        // Other types should go here.....
    }
    Console.WriteLine();
}

public class Actor
{
    public string Name { get; set; } = default!
    public string Surname { get; set; } = default!
    public string DOB { get; set; } = default!

    public override string ToString() => $"{Name} {Surname} born at {DOB}";
}


```


## Some of the references

- [C# Language reference](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/)
