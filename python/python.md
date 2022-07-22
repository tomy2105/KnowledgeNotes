# Python

<!-- toc -->

- [Resources](#resources)
- [Installing Python](#installing-python)
- [Variables](#variables)
  * [Python and Computer Memory](#python-and-computer-memory)
  * [Variable names](#variable-names)
  * [Variable types](#variable-types)
  * [String Literal](#string-literal)
  * [Assignment statements](#assignment-statements)
- [Operators and methods](#operators-and-methods)
  * [Arithmetic](#arithmetic)
  * [Arithmetic Operator Precedence](#arithmetic-operator-precedence)
  * [Comparison](#comparison)
  * [Logical](#logical)
  * [Sequence](#sequence)
  * [String](#string)
  * [Dictionary](#dictionary)
  * [Sets](#sets)
- [Functions](#functions)
  * [Function Call](#function-call)
  * [Defining Functions](#defining-functions)
  * [Docstrings and Function `help`](#docstrings-and-function-help)
  * [Understanding Scope](#understanding-scope)
  * [Builtin conversion functions](#builtin-conversion-functions)
  * [Modules and using non-builtin functions](#modules-and-using-non-builtin-functions)
- [Statements](#statements)
  * [Comments](#comments)
  * [If statement](#if-statement)
  * [For loop](#for-loop)
  * [While loop](#while-loop)
- [File operations](#file-operations)
  * [Opening a file](#opening-a-file)
  * [Reading a file](#reading-a-file)
    + [The readline approach](#the-readline-approach)
    + [The for line infile approach](#the-for-line-infile-approach)
    + [The read approach](#the-read-approach)
    + [The readlines approach](#the-readlines-approach)
  * [Writing to a file](#writing-to-a-file)
- [Classes](#classes)
  * [Class Definition Syntax](#class-definition-syntax)
  * [Class Instantiation](#class-instantiation)
  * [Data attributes](#data-attributes)
  * [Class and Instance Variables](#class-and-instance-variables)
  * [Private Variables and Class-local References](#private-variables-and-class-local-references)
- [Regular expressions](#regular-expressions)
  * [Quick guide](#quick-guide)
  * [Regular expression module](#regular-expression-module)
- [XML Processing](#xml-processing)
  * [Quick guide](#quick-guide-1)
- [JSON Processing](#json-processing)
  * [Quick guide](#quick-guide-2)
- [Sockets and URLs](#sockets-and-urls)
  * [socket library](#socket-library)
  * [urllib library](#urllib-library)
  * [BeautifulSoup library](#beautifulsoup-library)

<!-- tocstop -->

## Resources

1.  [Main Python website](http://python.org/ "Link: http://python.org/")
2.  The [Python Standard
    Library](http://docs.python.org/3/library/index.html "Link: http://docs.python.org/3/library/index.html")
3.  [The Python
    Visualizer](http://tinyurl.com/ls7xp3k "Link: http://tinyurl.com/ls7xp3k"),
    written by Philip Guo.
4.  [Practical Programming (2nd edition): An Introduction to Computer
    Science Using
    Python](http://pragprog.com/book/gwpy2/practical-programming "Link: http://pragprog.com/book/gwpy2/practical-programming")
5.  <http://www.codeskulptor.org/> - Python inside a browser environment
    or [http://www.codeskulptor.org/viz](http://www.codeskulptor.org/) -
    Python inside a browser environment wizard mode
6.  [SimpleGUICS2Pygame](https://pypi.python.org/pypi/SimpleGUICS2Pygame)
    - standard Python module reimplementing the SimpleGUI particular
    module of CodeSkulptor
7.  [Python by
    Mozilla](https://developer.mozilla.org/en-US/Learn/Python)
8.  [Visualize Python, Java, JavaScript, TypeScript, and Ruby code
    execution](http://www.pythontutor.com/visualize.html)
9.  [Python School](http://www.pythonschool.net/)

## Installing Python

1.  Download and install the latest version of Python 3:
    [](http://www.python.org/download "Link: http://www.python.org/download")[http://www.python.org/download](http://www.python.org/download "Link: http://www.python.org/download").
    (Please do *not* install Python 2: you need Python 3.)
      - Linux users: use your package manager to install Python 3.
      - Windows users: choose the "Python 3.3.2 Windows x86 MSI
        Installer" from the downloads page.
      - Mac users: choose the "Python 3.3.2 Mac OS X 64-bit/32-bit
        x86-64/i386 Installer" from the downloads page, unless you have
        OS X version 10.5 or earlier.
2.  OS X users only: install [ActiveTCL
    8.5.14](http://www.activestate.com/activetcl/downloads "Link: http://www.activestate.com/activetcl/downloads").

## Variables

### Python and Computer Memory

You may think of *computer memory* as a long list of storage locations
where each location is identified with a unique number and each location
houses a value. This unique number is called a *memory address*.
Typically, we will write memory addresses as a number with an "id" as a
prefix to distinguish them from other numbers (for example, `id201` is
memory address 201).

Variables are a way to keep track of values stored in computer memory. A
*variable* is a named location in computer memory. Python keeps
variables in a separate list from values. A variable will contain a
memory address, and that memory address contains the value. The variable
then refers to the value. Python will pick the memory addresses for you.

A value has a memory address.  
A variable contains a memory address.  
A variable refers to a value.  
A variable points to a value.  

Example: Value `8.5` has memory address `id34`.  
Variable `shoe_size` contains memory address `id34`.  
The value of `shoe_size` is `8.5`.  
`shoe_size` refers to value `8.5`.  
`shoe_size` points to value `8.5`.  

### Variable names

The rules for legal Python names:

1.  Names must start with a letter or `_`.
2.  Names must contain only letters, digits, and `_`.

For Python, in most situations, the convention is to use `pothole_case`.

### Variable types

A *type* is a set of values and operations that can be performed on
those values.

  - `int`: integer  
    For example: `3`, `4`, `894`, `0`, `-3`, `-18`
  - `float`: floating point number (an approximation to a real number)  
    For example: `5.6`, `7.342`, `53452.0`, `0.0`, `-89.34`, `-9.5`
  - `str`: immutable sequence of characters  
    For example: `"foo"`, `'bar'`  
    Strings are immutable meaning operations on them return new strings
    and/or throw an error
  - `bool`: a boolean value  
    has two values: `True` and `False`.
  - `list`: a list collections of data, sequence  
    The general form of a list is: `[expr1, expr2, ..., exprN]`. For
    example: `grades = [80, 90, 70]`  
    Lists elements may be of any type and can also contain elements of
    more than one type.
  - `range`: an immutable sequence of numbers  
    `range([start,] stop[, step])` a virtual sequence of numbers from
    start to stop by step  
    It's advanteage is that it always take exact same small amount of
    memory.
  - `tuple`: an immutable sequence  
    Use parentheses instead of square brackets `lst = ['a', 3, -0.2],
    tup = ('a', 3, -0.2)`
  - `set`: collection of items  
    The general form of a dictionary is: `{value1, value2, ...,
    valueN}`  
    Sets are unordered. That is, the order the values are added has no
    effect on the order in which they are accessed.  
    Sets are mutable: they can be modified. `frozenset` is immutable.  
    Set elements must be hashable.  
  - `dict`: collection of name =\> value pairs  
    The general form of a dictionary is: `{key1: value1, key2: value2,
    ..., keyN: valueN}`  
    Keys must be unique. Values may be duplicated.  
    Dictionaries are unordered. That is, the order the key-value pairs
    are added to the dictionary has no effect on the order in which they
    are accessed.  
    Dictionaries are mutable: they can be modified. There are a series
    of operations and methods you can apply to dictionaries.  
    A dictionary can have keys of different types. For example, one key
    can be of type `int` and another of type `str`.  
    The keys of a dictionary must be immutable. Therefore, lists,
    dictionary and other mutable types cannot be used as keys.  

For more info on builtin types and methods available on these types go
to [The Python Standard Library - Built-in
Types](https://docs.python.org/3/library/stdtypes.html)

We say that lists and dict are *mutable*: they can be modified. All the
other types (`str`, `int`, `float` and `bool`, ...) are *immutable*:
they cannot be modified.

### String Literal

A *string literal* is a sequence of characters. In Python, this type is
called `str`. Strings in Python start and end with a single quotes (`'`)
or double quotes (`"`). A string can be made up of letters, numbers, and
special characters.

If a string begins with a single quote, it must end with a single quote.
The same applies to double-quoted strings. You can not mix the type of
quotes.

To include a quote within a string, use an *escape character* (`\`)
before it. Otherwise Python interprets that quote as the end of a string
and an error occurs.

An alternative approach is to use a double-quoted string when including
a a single-quote within it, or vice-versa. Single- and double-quoted
strings are equivalent.

The third string format uses triple-quotes (single and/or double) and a
triple-quoted string can span multiple lines. For example:

``` 

>>> print(''' How
... are you today''')
 How
are you today
```

### Assignment statements

The general form of an assignment statement:

*`variable = expression`*

Example assignment statements:



``` 
>>> base = 20  
>>> height = 12    
>>> area = base * height / 2  
>>> area = 120.0                           
```

The rules for executing an assignment statement:

1.  Evaluate the expression. This produces a memory address.
2.  Store the memory address in the variable.

Assigment statements when using muttable variables creates an alias.
When two variables refer to the same objects, they are *aliases*. If
that object is modified, both of variables will see the change.

``` 
>>> lst1 = [11, 12, 13, 14, 15, 16, 17]
>>> lst2 = lst1
>>> lst1[-1] = 18
>>> lst2
[11, 12, 13, 14, 15, 16, 18]                        
```

## Operators and methods

### Arithmetic

|          |                                                                |            |                     |                      |
| -------- | -------------------------------------------------------------- | ---------- | ------------------- | -------------------- |
| Operator | Operation                                                      | Expression | English description | Result               |
| `+`      | addition                                                       | `11 + 56`  | 11 plus 56          | 67                   |
| `-`      | subtraction                                                    | `23 - 52`  | 23 minus 52         | \-29                 |
| `*`      | multiplication                                                 | `4 * 5`    | 4 multiplied by 5   | 20                   |
| `**`     | exponentiation                                                 | `2 ** 5`   | 2 to the power of 5 | 32                   |
| `/`      | division (*integer division for integer arguments in Pyhton2*) | `9 / 2`    | 9 divided by 2      | 4.5 (*4 in Pyhton2*) |
| `//`     | integer division                                               | `9 // 2`   | 9 divided by 2      | 4                    |
| `%`      | modulo (remainder)                                             | `9 % 2`    | 9 mod 2             | 1                    |

### Arithmetic Operator Precedence

When multiple operators are combined in a single expression, the
operations are evaluated in order of precedence.

|                                |            |
| ------------------------------ | ---------- |
| Operator                       | Precedence |
| \*\*                           | highest    |
| \- (negation)                  |            |
| \*, /, //, %                   |            |
| \+ (addition), - (subtraction) | lowest     |

### Comparison

The comparison operators take two values and produce a Boolean value.

|                          |          |          |                   |
| ------------------------ | -------- | -------- | ----------------- |
| Description              | Operator | Example  | Result of example |
| less than                | `<`      | `3 < 4`  | `True`            |
| greater than             | `>`      | `3 > 4`  | `False`           |
| equal to                 | `==`     | `3 == 4` | `False`           |
| greater than or equal to | `>=`     | `3 >= 4` | `False`           |
| less than or equal to    | `<=`     | `3 <= 4` | `True`            |
| not equal to             | `!=`     | `3 != 4` | `True`            |

Comparisons can be chained arbitrarily, e.g., x \< y \<= z is equivalent
to x \< y and y \<= z, except that y is evaluated only once (but in both
cases z is not evaluated at all when x \< y is found to be false).  
Formally, if a, b, c, ..., y, z are expressions and op1, op2, ..., opN
are comparison operators, then a op1 b op2 c ... y opN z is equivalent
to a op1 b and b op2 c and ... y opN z, except that each expression is
evaluated at most once.  
Note that a op1 b op2 c doesn’t imply any kind of comparison between a
and c, so that, e.g., x \< y \> z is perfectly legal (though perhaps not
pretty).

### Logical

There are also three logical operators that produce Boolean values:
`and`, `or`, and `not`.

The `and` operator produces `True` if and only if both expressions are
`True`.  
As such, if the first operand is `False`, the second condition will not
even be checked, because it is already known that the expression will
produce `False`.

|         |         |                   |
| ------- | ------- | ----------------- |
| `expr1` | `expr2` | `expr1 and expr2` |
| `True`  | `True`  | `True`            |
| `True`  | `False` | `False`           |
| `False` | `True`  | `False`           |
| `False` | `False` | `False`           |

  

The `or` operator evaluates to `True` if and only if at least one
operand is `True`.  
As such, if the first operand is `True`, the second condition will not
even be checked, because it is already known that the expression will
produce `True`.

|         |         |                  |
| ------- | ------- | ---------------- |
| `expr1` | `expr2` | `expr1 or expr2` |
| `True`  | `True`  | `True`           |
| `True`  | `False` | `True`           |
| `False` | `True`  | `True`           |
| `False` | `False` | `False`          |

  

The `not` operator evaluates to `True` if and only if the operand is
`False`.  

|         |             |
| ------- | ----------- |
| `expr1` | `not expr1` |
| `True`  | `False`     |
| `False` | `True`      |

The order of precedence for logical operators is: `not`, `and`, then
`or`. We can override precedence using parentheses and parentheses can
also be added to make things easier to read and understand.  

### Sequence

Elements of a list and/or string can be accessed using indices. An index
is a position within the list/string.  
Positive indices count from the beginning (left-hand side) with the
first element/character at index 0, the second at index 1, and so on.  
Negative indices count from the end (right-hand side) with the last
element/character at index -1, the second last at index -2, and so on.

``` 

>>> s = "Learn to Program"
>>> s[0]
'L'
>>> s[1]
'e'
>>> s[-1]
'm'
>>> s[-2]
'a'                      
```

We can extract more than one element/character using slicing. A slice is
a list/substring from the start index up to but not including the end
index. For example:

``` 

>>> s = "Learn to Program"
>>> s[0:5]
'Learn'
>>> s[6:8]
'to'
>>> s[9:16]
'Program'                      
```

The end index may be omitted entirely and the default is length of
list/string.  
Similarly, if the start index is omitted, the slice starts from index
0.  

``` 

>>> s = "Learn to Program"
>>> s[9:]
'Program'
>>> s[:]
'Learn to Program'
>>> s[:8]
'Learn to'                      
```

Example with list:

``` 

>>> grades = [80, 90, 70]
>>> grades[0]
80
>>> grades[1]
90
>>> grades[2]
70
>>> grades[0:2]
[80, 90]
>>> 90 in grades
True
>>> 60 in grades
False                      
```

`in` operator returns `True` if item of sequence (second argument) is
equal to first argument, `False` otherwise.

    
>>> grades = [80, 90, 70]
>>> 90 in gradesTrue
>>> 60 in gradesFalse

While the in and operation is used only for simple containment testing
in the general case, some specialised sequences also use them for
subsequence testing:

``` 

>>> "gg" in "eggs"
True                        
```

Operator `+` concatenates two sequences

``` 

>>> [10, 20] + [30, 40]
[10, 20, 30, 40]                       
```

Concatenation of immutable sequences always results in a new sequence\!

Operator `*` concatenates n *shallow* copies of a sequence

``` 

>>> lists = [[]] * 3
>>> lists
[[], [], []]
>>> lists[0].append(3)
>>> lists
[[3], [3], [3]]                        
```

To create a list of different lists:

``` 

>>> lists = [[] for i in range(3)]
>>> lists[0].append(3)
>>> lists[1].append(5)
>>> lists[2].append(7)
>>> lists
[[3], [5], [7]]                      
```

Several of Python's built-in functions can be applied to lists,
including:

  - `len(list)`: return the length of `list`.
  - `min(list)`: return the smallest element in `list`.
  - `max(list)`: return the largest element in `list`.
  - `sum(list)`: return the sum of elements of `list` (where list items
    must be numeric).

Sequences have several methods

  - `s.index(x[, i[, j]])`: index of the first occurrence of x in s (at
    or after index i and before index j).
  - `s.count(x)`: total number of occurrences of x in s.

<!-- end list -->

``` 

>>> letters = ['a', 'a', 'b', 'c']
>>> letters.count('a')
2
>>> letters.index('a')
0
>>> letters.index('d')
Traceback (most recent call last):  File "<pyshell#24>", line 1, in <module>    letters.index('d')ValueError: 'd' is not in list                                                         
```

Mutable sequences have several methods

| Operation                                   | Result                                                                                 |
| ------------------------------------------- | -------------------------------------------------------------------------------------- |
| `s[i] = x`                                  | item *i* of *s* is replaced by *x*                                                     |
| `s[i:j] = t`                                | slice of *s* from *i* to *j*is replaced by the contents of the iterable *t*            |
| `del s[i:j]`                                | same as `s[i:j] = []`                                                                  |
| `s[i:j:k] = t`                              | the elements of `s[i:j:k]`are replaced by those of *t*                                 |
| `del s[i:j:k]`                              | removes the elements of`s[i:j:k]` from the list                                        |
| `s.append(x)`                               | appends *x* to the end of the sequence (same as `s[len(s):len(s)] = [x]`)              |
| `s.clear()`                                 | removes all items from `s` (same as `del s[:]`)                                        |
| `s.copy()`                                  | creates a shallow copy of `s`(same as `s[:]`)                                          |
| `s.extend(t)`                               | extends *s* with the contents of *t* (same as `s[len(s):len(s)] = t`)                  |
| `s.insert(i, x)`                            | inserts *x* into *s* at the index given by *i* (same as `s[i:i] = [x]`)                |
| `s.pop([i])`                                | retrieves the item at *i* and also removes it from *s*                                 |
| `s.remove(x)`                               | remove the first item from *s*where `s[i] == x`                                        |
| `s.reverse()`                               | reverses the items of *s* inplace                                                      |
| `s.sort(cmp=None, key=None, reverse=False)` | sort the items of the list in place (the arguments can be used for sort customization) |

``` 

>>> colours = ['yellow', 'blue']
>>> colours.append('red')
>>> print(colours)
['yellow', 'blue', 'red']
>>> colours.extend(['pink', 'green'])
>>> print(colours)
['yellow', 'blue', 'red', 'pink', 'green']
>>> colours.pop()'green'
>>> print(colours)
['yellow', 'blue', 'red', 'pink']
>>> colours.pop(2)'red'
>>> print(colours)
['yellow', 'blue', 'pink']
>>> colours.remove('green')
Traceback (most recent call last):  File "<pyshell#10>", line 1, in <module>    colours.remove('green')ValueError: list.remove(x): x not in list
>>> colours.remove('pink')
>>> print(colours)                     
```

### String

Strings are also a sequence but with some special meanings

|               |                                     |                     |            |
| ------------- | ----------------------------------- | ------------------- | ---------- |
| Expression    | Description                         | Example             | Output     |
| `str1 + str2` | concatenate `str1` and `str1`       | `print('ab' + 'c')` | `abc`      |
| `str1 * int1` | concatenate `int1` copies of `str1` | `print('a' * 5)`    | `aaaaa`    |
| `int1 * str1` | concatenate `int1` copies of `str1` | `print(4 * 'bc')`   | `bcbcbcbc` |

The `*` and `+` operands obey by the standard precedence rules when used
with strings.

All other mathematical operators and operands result in a `TypeError`.

|                       |          |                          |                   |
| --------------------- | -------- | ------------------------ | ----------------- |
| Description           | Operator | Example                  | Result of example |
| equality              | `==`     | `'cat' == 'cat'`         | `True`            |
| inequality            | `!=`     | `'cat' != 'Cat'`         | `True`            |
| less than             | `<`      | `'A' < 'a'`              | `True`            |
| greater than          | `>`      | `'a' > 'A'`              | `True`            |
| less than or equal    | `<=`     | `'a' <= 'a'`             | `True`            |
| greater than or equal | `>=`     | `'a' >= 'A'`             | `True`            |
| contains              | `in`     | `'cad' in 'abracadabra'` | `True`            |
| length of `str` s     | `len(s)` | `len("abc")`             | `3`               |

We can compare two strings for their dictionary order, comparing them
letter by letter:

``` 

>>> 'abracadabra' < 'ace'
True
>>> 'abracadabra' > 'ace'
False
>>> 'a' <= 'a'
True
>>> 'A' < 'B'
True                     
```

Capitalization matters, and capital letters are less than lowercase
letters:

``` 

>>> 'a' != 'A'
True
>>> 'a' < 'A'
False                      
```

We can compare a string and an integer for equality:

``` 

>>> 's' == 3
False                     
```

We can't compare values of two different types for ordering:

``` 

>>> 's' <= 3
Traceback (most recent call last):  File "<stdin>", line 1, in <module>>TypeError: unorderable types: str() <= int()                     
```

String objects have one unique built-in operation: the `%` operator
(modulo). This is also known as the string formatting or interpolation
operator.  
Given format % values (where format is a string), % conversion
specifications in format are replaced with zero or more elements of
values. The effect is similar to using the sprintf() in the C language.
For specification go to [The Python Standard Library - printf-style
String
Formatting](https://docs.python.org/3/library/stdtypes.html#old-string-formatting)

``` 

>>> print('%(language)s has %(number)03d quote types.' %
... {'language': "Python", "number": 2})
Python has 002 quote types.                     
```

For more info on string methods go to [The Python Standard Library -
String
methods](https://docs.python.org/3/library/stdtypes.html#text-sequence-type-str)

### Dictionary

  - *len(d)* - Return the number of items in the dictionary d.
  - *d\[key\]* - Return the item of d with key key. Raises a KeyError if
    key is not in the map (refer to \_\_missing\_\_() \!\!\!)
  - *d\[key\] = value* - Set d\[key\] to value.
  - *del d\[key\]* - Remove d\[key\] from d. Raises a KeyError if key is
    not in the map.
  - *key in d* - Return True if d has a key key, else False.
  - *key not in d* - Equivalent to not key in d.
  - *iter(d)* - Return an iterator over the keys of the dictionary. This
    is a shortcut for iter(d.keys()).
  - *clear()* - Remove all items from the dictionary.
  - *copy()* - Return a shallow copy of the dictionary.
  - *classmethod fromkeys(seq\[, value\])* - Create a new dictionary
    with keys from seq and values set to value.
  - *get(key\[, default\])* - Return the value for key if key is in the
    dictionary, else default. If default is not given, it defaults to
    None, so that this method never raises a KeyError.
  - *items()* - Return a new view of the dictionary’s items ((key,
    value) pairs).
  - *keys()* - Return a new view of the dictionary’s keys.
  - *pop(key\[, default\])* - If key is in the dictionary, remove it and
    return its value, else return default. If default is not given and
    key is not in the dictionary, a KeyError is raised.
  - *popitem()* - Remove and return an arbitrary (key, value) pair from
    the dictionary.
  - *setdefault(key\[, default\])* - If key is in the dictionary, return
    its value. If not, insert key with a value of default and return
    default. default defaults to None.
  - *update(\[other\])* - Update the dictionary with the key/value pairs
    from other, overwriting existing keys. Return None.
  - *values()* - Return a new view of the dictionary’s values.

### Sets

  - *len(s)* - Return the cardinality of set s.
  - *x in s* - Test x for membership in s.
  - *x not in s* - Test x for non-membership in s.
  - *isdisjoint(other)* - Return True if the set has no elements in
    common with other. Sets are disjoint if and only if their
    intersection is the empty set.
  - *issubset(other)* - Test whether every element in the set is in
    other.
  - *set \<= other* - Test whether every element in the set is in other.
  - *set \< other* - Test whether the set is a proper subset of other,
    that is, set \<= other and set \!= other.
  - *issuperset(other)* and/or *set \>= other* - Test whether every
    element in other is in the set.
  - *set \> other* - Test whether the set is a proper superset of other,
    that is, set \>= other and set \!= other.
  - *union(other, ...)* and/or *set | other | ...* - Return a new set
    with elements from the set and all others.
  - *intersection(other, ...)* and/or *set & other & ...* - Return a new
    set with elements common to the set and all others.
  - *difference(other, ...)* and/or *set - other - ...* - Return a new
    set with elements in the set that are not in the others.
  - *difference\_update(other, ...)* a - Updates set leaving it with
    elements in the set that are not in the others.
  - *symmetric\_difference(other)* and/or *set ^ other* - Return a new
    set with elements in either the set or other but not both.
  - *copy()* - Return a new set with a shallow copy of s.

The non-operator versions of union(), intersection(), difference(), and
symmetric\_difference(), issubset(), and issuperset() methods will
accept any iterable as an argument. In contrast, their operator based
counterparts require their arguments to be sets. This precludes
error-prone constructions like set('abc') & 'cbs' in favor of the more
readable set('abc').intersection('cbs').

Two sets are equal if and only if every element of each set is contained
in the other (each is a subset of the other). A set is less than another
set if and only if the first set is a proper subset of the second set
(is a subset, but is not equal). A set is greater than another set if
and only if the first set is a proper superset of the second set (is a
superset, but is not equal).

Following are operations available for set that do not apply to
immutable instances of frozenset:

  - *update(other, ...)* and/or *set |= other | ...* - Update the set,
    adding elements from all others.
  - *intersection\_update(other, ...)* and/or *set &= other & ...* -
    Update the set, keeping only elements found in it and all others.
  - *difference\_update(other, ...)* and/or *set -= other | ...* -
    Update the set, removing elements found in others.
  - *symmetric\_difference\_update(other)* and/or *set ^= other* -
    Update the set, keeping only elements found in either set, but not
    in both.
  - *add(elem)* - Add element elem to the set.
  - *remove(elem)* - Remove element elem from the set. Raises KeyError
    if elem is not contained in the set.
  - *discard(elem)* - Remove element elem from the set if it is present.
  - *pop()* - Remove and return an arbitrary element from the set.
    Raises KeyError if the set is empty.
  - *clear()* - Remove all elements from the set.

The non-operator versions of the update(), intersection\_update(),
difference\_update(), and symmetric\_difference\_update() methods will
accept any iterable as an argument.

For more info on builtin types and methods available on these types go
to [The Python Standard Library - Built-in
Types](https://docs.python.org/3/library/stdtypes.html)

## Functions

### Function Call

The general form of a function call:

> *`function_name(arguments)`*

A *method* is a function inside of an object.

The general form of a method call is:  
  
`object.method(arguments)`

The rules for executing a function call:

1.  Evaluate the arguments.
2.  Call the function, passing in the argument values.

Terminology:

  - *Argument*: a value given to a function
  - *Pass*: to provide to a function
  - *Call*: ask Python to evaluate a function
  - *Return*: pass back a value

Example function calls:

``` 
   
>>> abs(-23)   
23  
>>> abs(56.24) 
56.24                           
```

Python has a set of built-in functions. To see the list of built-in
functions, run `dir(__builtins__)`.

To get information about a particular function, call `help` and pass the
function as the argument. For example `help(abs)`.

In the description of function the square brackets around `[, z]`
indicate that the argument is optional.

### Defining Functions

The general form of a function definition:

``` 
   def function_name(parameters):
      body                        
```

  - `def`: a keyword indicating a function definition
  - function\_name: the function name
  - parameters:
      - the parameter(s) of the function, 0 or more and are separated by
        a comma
      - a parameter is a variable whose value will be supplied when the
        function is called
  - body:
      - 1 or more statements, often ending with a `return` statement

When execution of a function body ends without having executed a
`return` statement, the function returns value `None`. The type of
`None` is `NoneType`.

Example of a function definition:

``` 
   def f(x):
      return x ** 2                       
```

The general form of a `return` statement:

``` 
   return expression                       
```

The rules for executing a `return` statement:

1.  Evaluate the expression. This produces a memory address.
2.  Pass back that memory address to the caller. Exit the function.

Function calls are expressions and the result can be stored in a
variable.

The general form of a function call:

``` 
   function_name(arguments)                        
```

The rules for executing a function call:

1.  Evaluate the arguments to produce memory addresses.
2.  Store those memory addresses in the corresponding parameters.
3.  Execute the body of the function.

Example of a function definition and function calls:

``` 
   
>>> def area(base, height):        
  return base * height / 2    
>>> area(3, 4) 
6.0 
>>> result = area(10, 7.45)    
>>> result 
37.25                       
```

### Docstrings and Function `help`

A docstring is a string literal that occurs as the first statement in a
module, function, class, or method definition. Such a docstring becomes
the \_\_doc\_\_ special attribute of that object.

Built-in function `help` displays the docstring from a function
definition. For example, consider this function:

``` 
   def area(base, height):
      """
      (number, number) -> number        
      Return the area of a triangle with dimensions base and height.
      """
      return base * height / 2                        
```

Calling `help` on function `area` produces this output:

``` 
   
>>> help(area) 
	Help on function area in module __main__:

	area(base, height)
		(number, number) -> number
		
		Return the area of a triangle with dimensions base
		and height.
```

### Understanding Scope

Explanation of scopes for code below:

``` 
	def convert_to_minutes(num_hours):
		""" (int) -&gt; int
		Return the number of minutes there are in num_hours hours.
		"""
		minutes = num_hours * 60
		return minutes

	def convert_to_seconds(num_hours):
		""" (int) -&gt; int
		Return the number of seconds there are in num_hours hours.
		"""
		minutes = convert_to_minutes(num_hours)
		seconds = minutes * 60
		return seconds

	seconds = convert_to_seconds(2) 
```

Python defines the first two functions, creates objects for them in the
heap, and, in the stack frame for the main program, creates variables
that refer to those function objects.  
  
After that, it executes the assignment statement on line 16. The
right-hand side of the assignment statement is a function call so we
evaluate the argument, `2`, first. The frame for `convert_to_seconds`
will appear on the call stack. The parameter, `num_hours`, will refer to
the value `2`.  
  
The first statement in function `convert_to_seconds` is an assignment
statement. Again, we evaluate the expression on the right-hand side.
This is a function call so we evaluate the argument, `num_hours`. This
produces the value `2`. A stack frame for function `convert_to_minutes`
is created on the call stack. Python stores the memory address of `2` in
the parameter for `convert_to_minutes`, which also happens to be called
`num_hours`.  
  
We now see that there are two variables called `num_hours` in the call
stack; one is in `convert_to_minutes` and the other is in
`convert_to_seconds`.  
The next line of code Python executes is `minutes = num_hours * 60`.
However, which instance of `num_hours` will be used? Python always uses
the variable in the current stack frame. With an assignment statement,
if the variable does not exist in the current stack frame, Python
creates it. So, once `num_hours * 60` is evaluated, variable `minutes`
is created in the current stack frame.  
  
The last line of the function is `return minutes`. Once this statement
is complete, Python will return to the frame just underneath the top of
the call stack.  
  
So, Python is going to produce the value `120`, remove the current stack
frame, create a new variable called `minutes` in the stack frame for
`convert_to_seconds`, and store the memory adress of `120` in that
variable.  
  
Python then executes `seconds = minutes * 60`. Python evaluates the
right-hand side, which produces `7200`, and stores the memory address of
that value in variable `seconds`. Since this variable does not exist
yet, Python creates it in the current stack frame.  
Next is a return statement. Like we saw above, that is going to return
control back to the the main module.  
  
Once the frame for `convert_to_seconds` is removed, the assignment
statement on line 16 (which has been paused a long time\!) is completed,
and a new variable `seconds` is created in the stack frame for the main
program.  

**Assignment statement and computer memory**

    variable = expression

If a variable does not exist in the current stack frame, Python creates
it.

**Return statement and computer memory**

    return expression

In addition to evaluating the expression and yielding its value,
`return` also erases the stack frame on top of the call stack.

### Builtin conversion functions

Builtin function `str` takes any value and returns a string
representation of that value.

``` 
   
>>> str(3)
'3' 
>>> str(47.6)
'47.6'                      
```

Builtin function `int` takes a string containing only digits (possibly
with a leading minus sign `-`) and returns the `int` that represents.
Function `int` also converts `float` values to integers by throwing away
the fractional part.

``` 
   
>>> int('12345')
12345   
>>> int('-998')
-998    
>>> int(-99.9)
-99                     
```

If function `int` is called with a string that contains anything other
than digits, a `ValueError` happens.

``` 
   
>>> int('-99.9')   
Traceback (most recent call last):    
 File "<stdin>", line 1, in <module>   
 ValueError: invalid literal for int() with base 10: '-99.9'                     
```

Builtin function `float` takes a string containing only digits and zero
or one decimal points (possibly with a leading minus sign `-`) and
returns the `float` that represents. Function `float` also converts
`int` values to `float`s.

``` 
   
>>> float('-43.2') 
-43.2   
>>> float('432')   
432.0   
>>> float(4)   
4.0                     
```

If function `float` is called with a string that can't be converted, a
`ValueError` happens.

``` 
   
>>> float('-9.9.9')    
Traceback (most recent call last):
    File "<stdin>", line 1, in <module>   
ValueError: could not convert string to float: '-9.9.9'                     
```

### Modules and using non-builtin functions

Python contains many functions, but not all of them are immediately
available as builtin functions. Instead of being available as builtins,
some functions are saved in different modules. A *module* is a file
containing function definitions and other statements.

We may also define our own modules with our own functions.

In order to gain access to the functions in a module, we must import
that module.

The general form of an import statement is:

    import module_name

To access a function within a module, we use:

    module_name.function_name

For example, we can import the Python module `math` and call the
function `sqrt` from it:

``` 
	import math

	def area2(side1, side2, side3):
			semi = semiperimeter(side1, side2, side3)
			area = math.sqrt(semi * (semi - side1) * (semi - side2) * (semi - side3))
			return area
```

In addition to importing Python's modules, we can also import the
modules that we write. For example, to use the functions from
`triangle.py` in another module, we would `import triangle`. A module
being imported should be in the same directory as the module importing
it.

## Statements

### Comments

As your programs get longer and more complicated, some additional
English explanation can be used to help you and other programmers read
your code.  
These explanations called *comments* document your code, much the way
docstrings document your functions.

A comment begins with the number sign character (`#`) and goes until the
end of the line. One name for this character is the hash character.
Python ignores any lines that start with this character.

Comments are intended for programmers to read, and are usually there to
explain the purpose of a function, as well as to describe relationships
between your variables.  
Comments are to help you, and anyone else who is reading/using your
code, to remember or understand the purpose of a given variable or
function in a program.

If a comment in the first or second line of the Python script matches
the regular expression coding\[=:\]\\s\*(\[-\\w.\]+), this comment is
processed as an encoding declaration; the first group of this expression
names the encoding of the source code file. The recommended forms of
this expression are `# -*- coding: -*-` (Emacs) and/or `#
vim:fileencoding=` (VIM).

### If statement

If statements can be used to control which instructions are executed.
Here is the general form:

``` 
	if expression1:    
		body1
	[elif expression2:      0 or more clauses
		body2]
	[else:                  0 or 1 clause
		bodyN]
```

`elif` stands for "else if", so this forms a chain of conditions.

To execute an `if` statement, evaluate each expression in order from top
to bottom. If an expression produces `True`, execute the body of that
clause and then skip the rest open 3he `if` statement. If there is an
`else`, and none of the expressions produce `True`, then execute the
body of the `else`.

For example, given this function:  

``` 
	def report_status(scheduled_time, estimated_time):
		""" (float, float) -&gt; str """
		if scheduled_time == estimated_time:
			return 'on time'
		elif scheduled_time &gt; estimated_time:  
			return 'early'
		else:
			return 'delayed'
```

In the shell:  

``` 
   
>>> report_status(14.3, 14.3)
'on time'   
>>> report_status(12.5, 11.5)
'early' 
>>> report_status(9.0, 9.5)
'delayed'                       
```

It is possible to place an `if` statement within the body of another
`if` statement. For example:

``` 
		if precipitation:
			if temperature &gt; 0:
				print('Bring your umbrella!')
			else:
				print('Wear your snow boots and winter coat!)   
```

### For loop

The for statement in iterates over the items of any sequence (a list or
a string), in the order that they appear in the sequence.

``` 

>>> words = ['cat', 'window', 'eatmilk']
>>> for w in words:
...     print w, len(w)
...
cat 3
window 6
eatmilk 7                      
```

If you need to modify the sequence you are iterating over while inside
the loop (for example to duplicate selected items), it is recommended
that you first make a copy.  
Iterating over a sequence does not implicitly make a copy. The slice
notation makes this especially convenient:

``` 
>>> for w in words[:]:  # Loop over a slice copy of the entire list.
...     if len(w) &gt; 6:
...         words.insert(0, w)
...
>>> words
['eatmilk', 'cat', 'window', 'eatmilk']
   
```

Example using a string

``` 

>>> s = 'yesterday'
>>> for char in s:
...     print(char)
... 
y
e
s
t
e
r
d
a
y                            
```

### While loop

The general form of a `while` loop:

```while <em>expression</em>:
    <em>statements</em>
else:
    <em>statements</em>
```

The `while` condition, `num < 100`, is evaluated, and if it is `True`
the statements in the loop body are executed. The loop condition is
rechecked and if found to be `True`, the body executes again. This
continues until the loop condition is checked and is `False`. For
example:

``` 

>>> num = 2
>>> while num < 100:
        num = num * 2
        print(num)
        
4
8
16
32
64
128                     
```

## File operations

### Opening a file

Information stored in files can be accessed by a Python program. To get
access to the contents of a file, you need to *open* the file in your
program.  
When you are done using a file, you should *close* it.

Python has a built-in function `open` that can open a file for reading.

The form of `open` is `open(filename,mode)`, where mode is `'r'` (to
openfor reading), `'w'` (to open for writing),or `'a'` (to open for
appending to what isalready in the file).

``` 
flanders_file = open('In Flanders Fields.txt', 'r')                        
```

To close a file, you write `flanders_file.close()`.

### Reading a file

There are four standard ways to read from a file.

#### The readline approach        

`readline()` -read and return the next line from the file, including the newline character (if it exists). Return the empty string if there are no more lines in the file. 

Used when you want to process only part of a file.     

```
file = open(filename, 'r')

# Read lines until we reach the 
# place in the file that we want. 
line = file.readline() 
while we are not at the place we want:
    line = file.readline()  

# Now we have reached the section 
# of the file we want to process.  

line = file.readline() 
while we are not at the end of the section:
    process the line     
    line = file.readline()  
    
file.close()
```

#### The for line infile approach

USed when you want to process every line in the file one at a time.    
```
file = open(filename, 'r')  
for line in file:     
    process the line  
file.close() 								                        
```

#### The read approach

`read()` - read the whole file as a single string.        

Use when you want to read the whole file at once and use it as a single string.

```
file = open(filename, 'r')  
contents = file.read()  
now process contents  
file.close() 								                     
```

#### The readlines approach
`readLines()` - read and return all lines in a file in a list. The lines include the newline character.

Used when you want to examine each line of a file by index.

```
file = open(filename, 'r')

# Get the contents as a list of strings.
contents_list = file.readlines()

process contents_list using indexing to
access particular lines from the file

file.close()
```


### Writing to a file

In order to write to a file, we use `file.write(str)`. This method
writes a string to a file. Method `write` works like Python's `print`
function, except that it does not add a newline character.

Module `tkinter` has a submodule called `filedialog`.

Function `askopenfilename` asks the user to select a file to open:

``` 
import tkinter.filedialog
tkinter.filedialog.askopenfilename()               
```

This function returns the full path to the file, so we can use that when
we call function `open` to open that file.

Function `asksaveasfilename` asks the user to select a file to save to,
and provides a warning if the file already exists.

## Classes

Compared with other programming languages, class mechanism adds classes
with a minimum of new syntax and semantics. Python classes provide all
the standard features of Object Oriented Programming: the class
inheritance mechanism allows multiple base classes, a derived class can
override any methods of its base class or classes, and a method can call
the method of a base class with the same name. Objects can contain
arbitrary amounts and kinds of data.

In C++ terminology, normally class members (including the data members)
are *public* and all member functions are *virtual*. As in Modula-3,
there are no shorthands for referencing the objects members from its
methods: the method function is declared with an explicit first argument
representing the object, which is provided implicitly by the call. As in
Smalltalk, classes themselves are objects. This provides semantics for
importing and renaming. Unlike C++ and Modula-3, built-in types can be
used as base classes for extension by the user. Also, like in C++, most
built-in operators with special syntax (arithmetic operators,
subscripting etc.) can be redefined for class instances.

### Class Definition Syntax

The simplest form of class definition looks like this:

```
class ClassName:
	<statement-1>
	.
	.
	.
	<statement-N>
```

The statements inside a class definition will usually be function
definitions, but other statements are allowed, and sometimes useful. The
function definitions inside a class normally have a peculiar form of
argument list, dictated by the calling conventions for methods.

### Class Instantiation

Class *instantiation* uses function notation. Just pretend that the
class object is a parameterless function that returns a new instance of
the class. For example (assuming the above class):

    x = MyClass()

creates a new *instance* of the class and assigns this object to the
local variable.

The instantiation operation (calling a class object) creates an empty
object. Many classes like to create objects with instances customized to
a specific initial state. Therefore a class may define a special method
named *\_\_init\_\_()*, like this:

```
    def __init__(self):    
        self.data = []
```

When a class defines an method, class instantiation automatically
invokes \_\_init\_\_() for the newly-created class instance.

Of course, the \_\_init\_\_() method may have arguments for greater
flexibility. In that case, arguments given to the class instantiation
operator are passed on to \_\_init\_\_(). For example:

```
>>> class Complex:
...     def __init__(self, realpart, imagpart):
...         self.r = realpart
...         self.i = imagpart
...
>>> x = Complex(3.0, -4.5)
>>> x.r, x.i
(3.0, -4.5)
```

### Data attributes

*Data attributes* correspond to instance variables in Smalltalk, and to
data members in C++. Data attributes need not be declared; like local
variables, they spring into existence when they are first assigned to.
For example

```
class MyClass:
	"""A simple example class"""
	i = 12345
	def f(self):
		x.counter = 1
		while x.counter < 10:
			x.counter = x.counter * 2
		print x.counter
		del x.counter
```

the following piece of code will print the value without leaving a
trace.

### Class and Instance Variables

Generally speaking, instance variables are for data unique to each
instance and class variables are for attributes and methods shared by
all instances of the class:

```
class Dog:
    kind = 'canine'         # class variable shared by all instances
    def __init__(self, name):
        self.name = name    # instance variable unique to each instance

>>> d = Dog('Fido')
>>> e = Dog('Buddy')
>>> d.kind                  # shared by all dogs
'canine'
>>> e.kind                  # shared by all dogs
'canine'
>>> d.name                  # unique to d
'Fido'
>>> e.name                  # unique to e
'Buddy'
```

Inheritance

The syntax for a derived class definition looks like this:

```
class DerivedClassName(BaseClassName):
	<statement-1>
	.
	.
	.
	<statement-N>
```

Derived classes may override methods of their base classes. Because
methods have no special privileges when calling other methods of the
same object, a method of a base class that calls another method defined
in the same base class may end up calling a method of a derived class
that overrides it. (For C++ programmers: all methods in Python are
effectively *virtual*.)

An overriding method in a derived class may in fact want to extend
rather than simply replace the base class method of the same name. There
is a simple way to call the base class method directly: just call
*BaseClassName.methodname(self, arguments)*.

Python has two built-in functions that work with inheritance:

  - *isinstance()* - to check an instance type: isinstance(obj int)
  - *issubclass()* - to check class inheritance: issubclass(bool,int)

### Private Variables and Class-local References

Private instance variables that cannot be accessed except from inside an
object do not exist in Python. However, there is a convention that is
followed by most Python code: a name prefixed with an underscore (e.g.
\_spam) should be treated as a non-public part of the API (whether it is
a function, a method or a data member). It should be considered an
implementation detail and subject to change without notice.

Since there is a valid use-case for class-private members (namely to
avoid name clashes of names with names defined by subclasses), there is
limited support for such a mechanism, called *name mangling*. Any
identifier of the form *\_\_spam* (at least two leading underscores, at
most one trailing underscore) is textually replaced with
*\_classname\_\_spam*. This mangling is done without regard to the
syntactic position of the identifier, as long as it occurs within the
definition of a class.

```
class Mapping:
    def __init__(self, iterable):
        self.items_list = []
        self.__update(iterable)

    def update(self, iterable):
        for item in iterable:
            self.items_list.append(item)

    __update = update   # private copy of original update() method

class MappingSubclass(Mapping):

    def update(self, keys, values):
        # provides new signature for update()
        # but does not break __init__()
        for item in zip(keys, values):
            self.items_list.append(item)
```

For more info on classes go to
[Classes](https://docs.python.org/2/tutorial/classes.html#private-variables-and-class-local-references)
and [Data
Model](https://docs.python.org/2/reference/datamodel.html#newstyle) in
Python documentaiton.

## Regular expressions

[RegExr - learning and visualize regexp](http://www.regexr.com/)

### Quick guide

  - *^* Matches the beginning of a line
  - *$* Matches the end of the line
  - *.* Matches any character
  - *\\s* Matches whitespace
  - *\\S* Matches any non-whitespace character
  - *\** Repeats a character zero or more times
  - *\*?* Repeats a character zero or more times (non-greedy)
  - *+* Repeats a character one or more times
  - *+?* Repeats a character one or more times (non-greedy)
  - *?* Repeats a character zero or one times
  - *??* Repeats a character zero or one times (non-greedy)
  - *{m}* Repeats a character exactly m times
  - *{m,n}* Repeats a character from m to n times
  - *{m,n}?* Repeats a character from m to n times (non-greedy)
  - *\[aeiou\]* Matches a single character in the listed set
  - *\[^XYZ\]* Matches a single character not in the listed set
  - *\[a-z0-9\]* The set of characters can include a range
  - *(* Indicates where string extraction is to start
  - *)* Indicates where string extraction is to end

[More about python regex
syntax](https://docs.python.org/2/library/re.html#regular-expression-syntax)

### Regular expression module

    import re

  - *re.compile(pattern, flags=0)* Compile a regular expression pattern
    into a regular expression object, which can be used for matching
    using its match() and search() methods, described below. The
    sequence prog = re.compile(pattern); result = prog.match(string) is
    equivalent to result = re.match(pattern, string)

  - *re.DEBUG* Display debug information about compiled expression.

  - *re.I re.IGNORECASE* Perform case-insensitive matching; expressions
    like \[A-Z\] will match lowercase letters, too. This is not affected
    by the current locale.

  - *re.L re.LOCALE* Make \\w, \\W, \\b, \\B, \\s and \\S dependent on
    the current locale.

  - *re.M re.MULTILINE* When specified, the pattern character '^'
    matches at the beginning of the string and at the beginning of each
    line (immediately following each newline); and the pattern character
    '$' matches at the end of the string and at the end of each line
    (immediately preceding each newline). By default, '^' matches only
    at the beginning of the string, and '$' only at the end of the
    string and immediately before the newline (if any) at the end of the
    string.

  - *re.S re.DOTALL* Make the '.' special character match any character
    at all, including a newline; without this flag, '.' will match
    anything except a newline.

  - *re.U re.UNICODE* Make \\w, \\W, \\b, \\B, \\d, \\D, \\s and \\S
    dependent on the Unicode character properties database.

  - *re.X re.VERBOSE* This flag allows you to write regular expressions
    that look nicer. Whitespace within the pattern is ignored, except
    when in a character class or preceded by an unescaped backslash,
    and, when a line contains a '\#' neither in a character class or
    preceded by an unescaped backslash, all characters from the leftmost
    such '\#' through the end of the line are ignored.
    
    ``` 
        a = re.compile(r"""\d + # the integral part
					        \. # the decimal point
					        \d * # some fractional digits""", re.X)
        b = re.compile(r"\d+\.\d*")
    ```

  - *re.search(pattern, string, flags=0)* Scan through string looking
    for the first location where the regular expression pattern produces
    a match, and return a corresponding MatchObject instance. Return
    None if no position in the string matches the pattern; note that
    this is different from finding a zero-length match at some point in
    the string.

  - *re.match(pattern, string, flags=0)* If zero or more characters at
    the beginning of string match the regular expression pattern, return
    a corresponding MatchObject instance. Return None if the string does
    not match the pattern; note that this is different from a
    zero-length match.

  - *re.split(pattern, string, maxsplit=0, flags=0)* Split string by the
    occurrences of pattern. If capturing parentheses are used in
    pattern, then the text of all groups in the pattern are also
    returned as part of the resulting list. If maxsplit is nonzero, at
    most maxsplit splits occur, and the remainder of the string is
    returned as the final element of the list. (Incompatibility note: in
    the original Python 1.5 release, maxsplit was ignored. This has been
    fixed in later releases.)

  - *re.findall(pattern, string, flags=0)* Return all non-overlapping
    matches of pattern in string, as a list of strings. The string is
    scanned left-to-right, and matches are returned in the order found.
    If one or more groups are present in the pattern, return a list of
    groups; this will be a list of tuples if the pattern has more than
    one group. Empty matches are included in the result unless they
    touch the beginning of another match.

  - *re.finditer(pattern, string, flags=0)* Return an iterator yielding
    MatchObject instances over all non-overlapping matches for the RE
    pattern in string. The string is scanned left-to-right, and matches
    are returned in the order found. Empty matches are included in the
    result unless they touch the beginning of another match.

  - *re.sub(pattern, repl, string, count=0, flags=0)* Return the string
    obtained by replacing the leftmost non-overlapping occurrences of
    pattern in string by the replacement repl. If the pattern isn't
    found, string is returned unchanged. repl can be a string or a
    function; if it is a string, any backslash escapes in it are
    processed. That is, \\n is converted to a single newline character,
    \\r is converted to a carriage return, and so forth. Unknown escapes
    such as \\j are left alone. Backreferences, such as \\6, are
    replaced with the substring matched by group 6 in the pattern.

  - *re.subn(pattern, repl, string, count=0, flags=0)* Perform the same
    operation as sub(), but return a tuple (new\_string,
    number\_of\_subs\_made).

  - *re.escape(string)* Return string with all non-alphanumerics
    backslashed; this is useful if you want to match an arbitrary
    literal string that may have regular expression metacharacters in
    it.

  - *re.purge()* Clear the regular expression cache.

[More about python regex module
contents](https://docs.python.org/2/library/re.html#module-contents)

## XML Processing

### Quick guide

``` 
import xml.etree.ElementTree as ET
data = '''
<person>
<name>Chuck</name>
<phone type="intl">
+1 734 303 4456
</phone>
<email hide="yes"/>
</person>'''
tree = ET.fromstring(data)
print 'Name:',tree.find('name').text
print 'Attr:',tree.find('email').get('hide')
						
import xml.etree.ElementTree as ET
input = '''
<stuff>
<users>
<user x="2">
<id>001</id>
<name>Chuck</name>
</user>
<user x="7">
<id>009</id>
<name>Brent</name>
</user>
</users>
</stuff>'''
stuff = ET.fromstring(input)
lst = stuff.findall('users/user')
print 'User count:', len(lst)
for item in lst:
	print 'Name', item.find('name').text
	print 'Id', item.find('id').text
	print 'Attribute', item.get("x")                   
```

## JSON Processing

### Quick guide

``` 
import json
data = '''
{
"name" : "Chuck",
"phone" : {
"type" : "intl",
"number" : "+1 734 303 4456"
},
"email" : {
"hide" : "yes"
}
}'''
info = json.loads(data)
print 'Name:',info["name"]
print 'Hide:',info["email"]["hide"]
						
import json
input = '''
[
{ "id" : "001",
"x" : "2",
"name" : "Chuck"
} ,
{ "id" : "009",
"x" : "7",
"name" : "Chuck"
}
]'''
info = json.loads(input)
print 'User count:', len(info)
for item in info:
	print 'Name', item['name']
	print 'Id', item['id']
	print 'Attribute', item['x']
						
import urllib
import twurl
import json
TWITTER_URL = 'https://api.twitter.com/1.1/friends/list.json'
while True:
	print ''
	acct = raw_input('Enter Twitter Account:')
	if ( len(acct) < 1 ) : break
	url = twurl.augment(TWITTER_URL, {'screen_name': acct, 'count': '5'} )
	print 'Retrieving', url
	connection = urllib.urlopen(url)
	data = connection.read()
	headers = connection.info().dict
	print 'Remaining', headers['x­rate­limit­remaining']
	js = json.loads(data)
	print json.dumps(js, indent=4)
	for u in js['users'] :
		print u['screen_name']
		s = u['status']['text']
		print ' ',s[:50]	
```

## Sockets and URLs

### socket library

``` 
import socket
mysock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
mysock.connect(('www.py4inf.com', 80))

mysock.send(bytes('GET http://www.py4inf.com/code/romeo.txt HTTP/1.0\n\n', 'UTF-8'))

while True :
	data = mysock.recv(1024)
	if (len(data) < 1):
		break
	print(data.decode())
	
mysock.close()
		                
```

### urllib library

``` 
import urllib.request

fhand = urllib.request.urlopen('http://www.py4inf.com/code/romeo.txt')

for line in fhand:
    print(line.decode().strip())

#python2 version
#import urllib

#fhand = urllib.open('http://www.py4inf.com/code/romeo.txt')

#for line in fhand:
#    print line.strip()               
```

### BeautifulSoup library

[BeautifulSoup home](http://www.crummy.com/software/BeautifulSoup/)

``` 
html_doc = """
<html><head><title>The Dormouse's story</title></head>
<body>
<p class="title"><b>The Dormouse's story</b></p>

<p class="story">Once upon a time there were three little sisters; and their names were
<a href="http://example.com/elsie" class="sister" id="link1">Elsie</a>,
<a href="http://example.com/lacie" class="sister" id="link2">Lacie</a> and
<a href="http://example.com/tillie" class="sister" id="link3">Tillie</a>;
and they lived at the bottom of a well.</p>

<p class="story">...</p>
"""

from bs4 import BeautifulSoup
soup = BeautifulSoup(html_doc, 'html.parser')

print(soup.prettify())

print(soup.title)
print(soup.title.name)
print(soup.title.string)
print(soup.title.parent.name)
print(soup.p)
print(soup.p['class'])
print(soup.a)
print(soup.find_all('a'))
print(soup.find(id="link3"))

for link in soup.find_all('a'):
    print(link.get('href'))

print(soup.get_text())              
```
