# Javascript

<!-- toc -->

- [Resources](#resources)
- [Basics](#basics)
  * [Data Types](#data-types)
  * [Variables](#variables)
  * [Variable scope](#variable-scope)
  * [Functions](#functions)
  * [Closures](#closures)
- [Operators](#operators)
  * [Arithemtic Operators](#arithemtic-operators)
  * [Assignment Operators](#assignment-operators)
  * [String Operators](#string-operators)
  * [Comparison and Logical Operators](#comparison-and-logical-operators)
- [Execution flow control](#execution-flow-control)
  * [If else](#if-else)
  * [Switch](#switch)
  * [while](#while)
  * [do while](#do-while)
  * [for](#for)
  * [for/in](#forin)
- [Builtin objects](#builtin-objects)
  * [Math](#math)
- [HTML Specific](#html-specific)
  * [Events](#events)
  * [onload](#onload)
  * [onresize](#onresize)
  * [onscroll](#onscroll)
  * [onerror](#onerror)
  * [onclick](#onclick)
  * [ondblclick](#ondblclick)
  * [onmousedown](#onmousedown)
  * [onmouseup](#onmouseup)
  * [onmouseover](#onmouseover)
  * [onmouseout](#onmouseout)
  * [onmouseenter](#onmouseenter)
  * [onmouseleave](#onmouseleave)
  * [onkeydown](#onkeydown)
  * [onkeypress](#onkeypress)
  * [onkeyup](#onkeyup)
  * [Window object](#window-object)

<!-- tocstop -->

## Resources

1.  [Eloquent JavaScript](http://eloquentjavascript.net/)
2.  [JavaScript Reference W3
    Schools](http://www.w3schools.com/jsref/default.asp)
3.  [JavaScript Tutorial W3 Schools](http://www.w3schools.com/js/)
4.  [JavaScript Tutorial
    Mozilla](https://developer.mozilla.org/en-US/Learn/JavaScript)
5.  [JavaScript Reference
    Mozilla](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference)
6.  [Event Reference
    Mozilla](https://developer.mozilla.org/en-US/docs/Web/Events)
7.  [jQuery](https://jquery.com/)
8.  [jQuery API Documentation](https://api.jquery.com/)
9.  [jQuery W3 tutorial](http://www.w3schools.com/jquery/)
10. [jQuery Learning Center](https://learn.jquery.com/)
11. [JavaScript Style Guide and Coding
    Conventions](http://www.w3schools.com/js/js_conventions.asp)
12. [Js Exercises for Beginners](http://www.jsexercises.com/)
13. [Js Beautifier](http://jsbeautifier.org/)
14. [Visualize Python, Java, JavaScript, TypeScript, and Ruby code
    execution](http://www.pythontutor.com/visualize.html)
15. [Handlebars template library](http://handlebarsjs.com/)
16. [Mustache template library](https://mustache.github.io/)
17. [JavaScript
    cheat-sheet](http://www.cheat-sheets.org/saved-copy/jsquick.pdf)
18. [JavaScript/HTML/CSS online editing](http://jsbin.com/)
19. [Another JavaScript/HTML/CSS online editing](http://codepen.io/)

## Basics

### Data Types

JavaScript has dynamic types. This means that the same variable can be
used as different types.

  - *String* - A string (or a text string) is a series of characters.
    Strings are written with quotes (single or double).
  - *Number* - Numbers can be written with, or without decimals, Extra
    large or extra small numbers can be written with scientific
    (exponential) notation.
  - *Boolean* - Booleans can only have two values: true or false.
  - *Array* - JavaScript arrays are written with square brackets. Array
    items are separated by commas. Array indexes are zero-based, which
    means the first item is \[0\], second is \[1\], and so on.
      - *length* Sets or returns the number of elements in an array
      - *concat()* Joins two or more arrays, and returns a copy of the
        joined arrays
      - *indexOf()* Search the array for an element and returns its
        position
      - *join()* Joins all elements of an array into a string
      - *lastIndexOf()* Search the array for an element, starting at the
        end, and returns its position
      - *pop()* Removes the last element of an array, and returns that
        element
      - *push()* Adds new elements to the end of an array, and returns
        the new length
      - *reverse()* Reverses the order of the elements in an array
      - *shift()* Removes the first element of an array, and returns
        that element
      - *slice()* Selects a part of an array, and returns the new array
      - *sort()* Sorts the elements of an array
      - *splice()* Adds/Removes elements from an array
      - *toString()* Converts an array to a string, and returns the
        result
      - *unshift()* Adds new elements to the beginning of an array, and
        returns the new length
      - *valueOf()* Returns the primitive value of an array
      - *forEach()* executes a provided function once per array element
      - *every()* tests whether all elements in the array pass the test
        implemented by the provided function
      - some() method tests whether some element in the array passes the
        test implemented by the provided function
      - *filter()* creates a new array with all elements that pass the
        test implemented by the provided function
      - *map()* creates a new array with the results of calling a
        provided function on every element in this array
      - *reduce()* applies a function against an accumulator and each
        value of the array (from left-to-right) to reduce it to a single
        value
      - *reduceRight()* applies a function against an accumulator and
        each value of the array (from right-to-left) has to reduce it to
        a single value
  - *Object* - JavaScript objects are written with curly braces. Object
    properties are written as name:value pairs, separated by commas.

You can use the JavaScript *typeof* operator to find the type of a
JavaScript variable.

In JavaScript, a variable without a value, has the value *undefined*.
The typeof is also undefined.

In JavaScript *null* is "nothing". It is supposed to be something that
doesn't exist. Unfortunately, in JavaScript, the data type of null is an
object.

### Variables

Declared with var statement

### Variable scope

In JavaScript, scope is the set of variables, objects, and functions you
have access to. JavaScript has function scope: The scope changes inside
functions.

Variables declared within a JavaScript function, become LOCAL to the
function. Local variables have local scope: They can only be accessed
within the function.

``` 
// code here can not use carName

function myFunction() {
    var carName = "Volvo";

    // code here can use carName

} 
                        
```

A variable declared outside a function, becomes GLOBAL. A global
variable has global scope: All scripts and functions on a web page can
access it.

If you assign a value to a variable that has not been declared, it will
automatically become a GLOBAL variable.

``` 
var carName = " Volvo";

// code here can use carName
// code here can use otherCarName even tough variable hasn't been declared here

function myFunction() {
    otherCarName = "Volvo";

    // code here can use carName
    // code here can use otherCarName

}
                        
```

Function arguments (parameters) work as local variables inside
functions.

Global and local variables with the same name are different variables.
Modifying one, does not modify the other.

### Functions

A JavaScript function is a block of code designed to perform a
particular task. A JavaScript function is executed when "something"
invokes it (calls it). Example:

    function myFunction(p1, p2) {
        return p1 * p2;              // The function returns the product of p1 and p2
    }

A JavaScript function is defined with the function keyword, followed by
a name, followed by parentheses ().  
Function names can contain letters, digits, underscores, and dollar
signs (same rules as variables).  
The parentheses may include parameter names separated by commas:
(parameter1, parameter2, ...)  
The code to be executed, by the function, is placed inside curly
brackets: {}  
Function parameters are the names listed in the function definition.  
Function arguments are the real values received by the function when it
is invoked.  
Inside the function, the arguments behaves as local variables.  

All functions have access to the global scope.  
In fact, in JavaScript, all functions have access to the scope "above"
them.  
JavaScript supports nested functions. Nested functions have access to
the scope "above" them.  

### Closures

JavaScript variables can belong to the *local* or *global* scope.  
Private variables can be made possible with *closures*.  

``` 
var add = (function () {
    var counter = 0;
    return function () {return counter += 1;}
})();

add();
add();
add();

// the counter is now 3 
                        
```

The self-invoking function only runs once. It declares/sets *private*
variables and returns a function expression.  
This way returned expression becomes a function. The "wonderful" part is
that it can access the *private* variables in the parent scope.  
This is called a JavaScript *closure*.  
The *private* variables are protected by the scope of the anonymous
function, and can only be changed using the returned function.  

## Operators

### Arithemtic Operators

  - *+* - Addition
  - *-* - Subtraction
  - *\** - Multiplication
  - */* - Division
  - *%* - Modulus
  - *++* - Increment
  - *--* - Decrement

### Assignment Operators

  - *=* - Assignment
  - *+=* same as *x = x + y*
  - *-=* same as *x = x - y*
  - *\*=* same as *x = x \* y*
  - */=* same as *x = x / y*
  - *%=* same as *x = x % y*

### String Operators

  - *+* - Concatenation
  - *+=* - Concatenation with assignment

Adding two numbers, will return the sum, but adding a number and a
string will return a string.  
The rule is: *If you add a number and a string, the result will be a
string\!*

### Comparison and Logical Operators

  - *&&* - logical and
  - *||* - logical or
  - *\!* - logical not
  - *==* - equal to
  - *===* - equal value and equal type
  - *\!=* - not equal
  - *\!==* - not equal value or not equal type
  - *\>* - greater than
  - *\<* - less than
  - *\>=* - greater than or equal to
  - *\<=* - less than or equal to

*logical and* and *logical or* are short circuted, meaning that right
hand expression will not be evaluated if the result is already known
(when left hand is true in case of *logical or* or when left hand is
false in case of *logical and*).

## Execution flow control

### If else

Use the if statement to specify a block of JavaScript code to be
executed if a condition is true.  
Use the else if statement to specify a new condition if the previous
condition is false.  
Use the else statement to specify a block of code to be executed if all
the conditions were false.  

``` 
if (condition1) {
    block of code to be executed if condition1 is true
} else if (condition2) {
    block of code to be executed if the condition1 is false and condition2 is true
} else {
    block of code to be executed if the condition1 is false and condition2 is false
}
                        
```

### Switch

Use the switch statement to select one of many blocks of code to be
executed. This is how it works:

  - The switch expression is evaluated once.
  - The value of the expression is compared with the values of each
    case.
  - If there is a match, the associated block of code is executed.

<!-- end list -->

``` 
switch(expression) {
    case n:
        code block
        break;
    case n:
        code block
        break;
    default:
        default code block
}                       
```

When the JavaScript code interpreter reaches a break keyword, it breaks
out of the switch block.  
The default keyword specifies the code to run if there is no case match.

### while

The do/while loop is a variant of the while loop. This loop will execute
the code block once, before checking if the condition is true, then it
will repeat the loop as long as the condition is true.

``` 
do {
    code block to be executed
}
while (condition);
                        
```

### do while

The while loop loops through a block of code as long as a specified
condition is true.

``` 
while (condition) {
    code block to be executed
}
                        
```

### for

The for loop is often the tool you will use when you want to create a
loop.

``` 
for (statement 1; statement 2; statement 3) {
    code block to be executed
}
                        
```

Statement 1 is executed before the loop (the code block) starts.  
Normally you will use statement 1 to initiate the variable used in the
loop (i = 0). This is not always the case, JavaScript doesn't care.
Statement 1 is optional.  
Statement 2 defines the condition for running the loop (the code
block).  
Often statement 2 is used to evaluate the condition of the initial
variable. This is not always the case, JavaScript doesn't care.
Statement 2 is also optional. If statement 2 returns true, the loop will
start over again, if it returns false, the loop will end.  
Statement 3 is executed each time after the loop (the code block) has
been executed.  
Often statement 3 increases the initial variable. This is not always the
case, JavaScript doesn't care, and statement 3 is optional. Statement 3
can do anything like negative increment (i--), positive increment (i = i
+ 15), or anything else. Statement 3 can also be omitted.  

``` 
for (i = 0, len = cars.length, text = ""; i < len; i++) {
    text += cars[i] + "
";
}                       
```

### for/in

The JavaScript for/in statement loops through the properties of an
object.

``` 
var person = {fname:"John", lname:"Doe", age:25};

var text = "";
var x;
for (x in person) {
    text += person[x];
}
                        
```

## Builtin objects

### Math

The Math object allows you to perform mathematical tasks. Math is not a
constructor. All properties/methods of Math can be called by using Math
as an object, without creating it.

  - *E* Returns Euler's number (approx. 2.718)
  - *LN2* Returns the natural logarithm of 2 (approx. 0.693)
  - *LN10* Returns the natural logarithm of 10 (approx. 2.302)
  - *LOG2E* Returns the base-2 logarithm of E (approx. 1.442)
  - *LOG10E* Returns the base-10 logarithm of E (approx. 0.434)
  - *PI* Returns PI (approx. 3.14)
  - *SQRT1\_2* Returns the square root of 1/2 (approx. 0.707)
  - *SQRT2* Returns the square root of 2 (approx. 1.414)
  - *abs(x)* Returns the absolute value of x
  - *acos(x)* Returns the arccosine of x, in radians
  - *asin(x)* Returns the arcsine of x, in radians
  - *atan(x)* Returns the arctangent of x as a numeric value between
    -PI/2 and PI/2 radians
  - *atan2(y,x)* Returns the arctangent of the quotient of its arguments
  - *ceil(x)* Returns x, rounded upwards to the nearest integer
  - *cos(x)* Returns the cosine of x (x is in radians)
  - *exp(x)* Returns the value of Ex
  - *floor(x)* Returns x, rounded downwards to the nearest integer
  - *log(x)* Returns the natural logarithm (base E) of x
  - *max(x,y,z,...,n)* Returns the number with the highest value
  - *min(x,y,z,...,n)* Returns the number with the lowest value
  - *pow(x,y)* Returns the value of x to the power of y
  - *random()* Returns a random number between 0 and 1
  - *round(x)* Rounds x to the nearest integer
  - *sin(x)* Returns the sine of x (x is in radians)
  - *sqrt(x)* Returns the square root of x
  - *tan(x)* Returns the tangent of an angle

## HTML Specific

In a web page, global variables belong to the window object.

### Events

Event handler can be specified in HTML or Javascript

In HTML:

``` 
<element onload="myScript">
                        
```

In JavaScript:

``` 
object.onload=function(){myScript};
                        
```

In JavaScript, using the addEventListener() method:

``` 
object.addEventListener("load", myScript);
object.removeEventListener("load", myScript);
                        
```

Note: The addEventListener() method is not supported in Internet
Explorer 8 and earlier versions.

### onload

The onload event occurs when an object has been loaded.

Supported HTML tags: body, frame, iframe, img, input type="image", link,
script, style

### onresize

The onresize event occurs when the browser window has been resized.

Supported HTML tags: body

### onscroll

The onscroll event occurs when an element's scrollbar is being scrolled.

Supported HTML tags: address, blockquote, body, caption, center, dd,
dir, div, dl, dt, fieldset, form, h1 to h6, html, li, menu, object, ol,
p, pre, select, tbody, textarea, tfoot, thead, ul

### onerror

The onerror event is triggered if an error occurs while loading an
external file (e.g. a document or an image).

Supported HTML tags: img, input type=image, object, script and style

### onclick

The onclick event occurs when the user clicks on an element.

Supported HTML tags: all EXCEPT: base, bdo, br, head, html, iframe,
meta, param, script, style, and title

### ondblclick

The onclick event occurs when the user double-clicks on an element.

Supported HTML tags: all EXCEPT: base, bdo, br, head, html, iframe,
meta, param, script, style, and title

### onmousedown

The onmousedown event occurs when a user presses a mouse button over an
element.

Supported HTML tags: all EXCEPT: base, bdo, br, head, html, iframe,
meta, param, script, style, and title

Tip: The order of events related to the onmousedown event (for the
left/middle mouse button):

1.  onmousedown
2.  onmouseup
3.  onclick

The order of events related to the onmousedown event (for the right
mouse button):

1.  onmousedown
2.  onmouseup
3.  oncontextmenu

### onmouseup

The onmouseup event occurs when a user releases a mouse button over an
element.

Supported HTML tags: all EXCEPT: base, bdo, br, head, html, iframe,
meta, param, script, style, and title

### onmouseover

The onmouseover event occurs when the mouse pointer is moved onto an
element, or onto one of its children.

Supported HTML tags: all EXCEPT: base, bdo, br, head, html, iframe,
meta, param, script, style, and title

### onmouseout

The onmouseout event occurs when the mouse pointer is moved out of an
element, or out of one of its children.

Supported HTML tags: all EXCEPT: base, bdo, br, head, html, iframe,
meta, param, script, style, and title

### onmouseenter

The onmouseenter event occurs when the mouse pointer is moved onto an
element. The onmouseenter event is similar to the onmouseover event. The
only difference is that the onmouseenter event does not bubble (does not
propagate up the document hierarchy).

Supported HTML tags: all EXCEPT: base, bdo, br, head, html, iframe,
meta, param, script, style, and title

### onmouseleave

The onmouseleave event occurs when the mouse pointer is moved out of an
element.The onmouseleave event is similar to the onmouseout event. The
only difference is that the onmouseleave event does not bubble (does not
propagate up the document hierarchy).

Supported HTML tags: all EXCEPT: base, bdo, br, head, html, iframe,
meta, param, script, style, and title

### onkeydown

The onkeydown event occurs when the user is pressing a key (on the
keyboard).

Supported HTML tags: all EXCEPT: base, bdo, br, head, html, iframe,
meta, param, script, style, and title

The order of events related to the onkeydown event:

1.  onkeydown
2.  onkeypress
3.  onkeyup

### onkeypress

The onkeypress event occurs when the user presses a key (on the
keyboard).

Supported HTML tags: all EXCEPT: base, bdo, br, head, html, iframe,
meta, param, script, style, and title

The onkeypress event is not fired for all keys (e.g. ALT, CTRL, SHIFT,
ESC) in all browsers. To detect only whether the user has pressed a key,
use the onkeydown event instead, because it works for all keys.

### onkeyup

The onkeyup event occurs when the user releases a key (on the keyboard).

Supported HTML tags: all EXCEPT: base, bdo, br, head, html, iframe,
meta, param, script, style, and title

### Window object

Properties:

  - *closed* Returns a Boolean value indicating whether a window has
    been closed or not
  - *defaultStatus* Sets or returns the default text in the statusbar of
    a window
  - *document* Returns the Document object for the window (See Document
    object)
  - *frameElement* Returns the iframe element in which the current
    window is inserted
  - *frames* Returns all iframe elements in the current window
  - *history* Returns the History object for the window (See History
    object)
  - *innerHeight* Returns the inner height of a window's content area
  - *innerWidth* Returns the inner width of a window's content area
  - *length* Returns the number of iframe elements in the current window
  - *location* Returns the Location object for the window (See Location
    object)
  - *name* Sets or returns the name of a window
  - *navigator* Returns the Navigator object for the window (See
    Navigator object)
  - *opener* Returns a reference to the window that created the window
  - *outerHeight* Returns the outer height of a window, including
    toolbars/scrollbars
  - *outerWidth* Returns the outer width of a window, including
    toolbars/scrollbars
  - *pageXOffset* Returns the pixels the current document has been
    scrolled (horizontally) from the upper left corner of the window
  - *pageYOffset* Returns the pixels the current document has been
    scrolled (vertically) from the upper left corner of the window
  - *parent* Returns the parent window of the current window
  - *screen* Returns the Screen object for the window (See Screen
    object)
  - *screenLeft* Returns the horizontal coordinate of the window
    relative to the screen
  - *screenTop* Returns the vertical coordinate of the window relative
    to the screen
  - *screenX* Returns the horizontal coordinate of the window relative
    to the screen
  - *screenY* Returns the vertical coordinate of the window relative to
    the screen
  - *scrollX* An alias of pageXOffset
  - *scrollY* An alias of pageYOffset
  - *self* Returns the current window
  - *status* Sets or returns the text in the statusbar of a window
  - *top* Returns the topmost browser window

Methods:

  - *alert()* Displays an alert box with a message and an OK button
  - *atob()* Decodes a base-64 encoded string
  - *blur()* Removes focus from the current window
  - *btoa()* Encodes a string in base-64
  - *clearInterval()* Clears a timer set with setInterval()
  - *clearTimeout()* Clears a timer set with setTimeout()
  - *close()* Closes the current window
  - *confirm()* Displays a dialog box with a message and an OK and a
    Cancel button
  - *createPopup()* Creates a pop-up window
  - *focus()* Sets focus to the current window
  - *moveBy()* Moves a window relative to its current position
  - *moveTo()* Moves a window to the specified position
  - *open()* Opens a new browser window
  - *print()* Prints the content of the current window
  - *prompt()* Displays a dialog box that prompts the visitor for input
  - *resizeBy()* Resizes the window by the specified pixels
  - *resizeTo()* Resizes the window to the specified width and height
  - *scroll()* Deprecated. This method has been replaced by the
    scrollTo() method.
  - *scrollBy()* Scrolls the document by the specified number of pixels
  - *scrollTo()* Scrolls the document to the specified coordinates
  - *setInterval()* Calls a function or evaluates an expression at
    specified intervals (in milliseconds)
  - *setTimeout()* Calls a function or evaluates an expression after a
    specified number of milliseconds
  - *stop()* Stops the window from loading

