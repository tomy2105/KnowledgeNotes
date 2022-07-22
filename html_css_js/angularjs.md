# AngularJS

<!-- toc -->

- [Resources](#resources)
- [General](#general)
  * [Getting started](#getting-started)
- [Data Binding](#data-binding)
  * [General](#general-1)
  * [Templates](#templates)
  * [Compiler](#compiler)
  * [Directive](#directive)
  * [Expression](#expression)
  * [Filters](#filters)
- [Scope](#scope)
  * [General](#general-2)
  * [Hierarchies](#hierarchies)
  * [Debugging](#debugging)
  * [Events](#events)
- [Directives](#directives)
  * [Matching](#matching)
  * [Creating](#creating)
  * [Directive list](#directive-list)
- [Component](#component)
  * [General](#general-3)
- [Controller](#controller)
  * [General](#general-4)
  * [Definition](#definition)
- [Services](#services)
  * [General](#general-5)
- [Deep Linking](#deep-linking)
  * [General](#general-6)
  * [ngRoute & ngView](#ngroute--ngview)
- [Form Validation](#form-validation)
  * [General](#general-7)
  * [CSS Classes](#css-classes)
  * [Example](#example)
  * [Custom validation](#custom-validation)
- [Server Communication](#server-communication)
  * [General](#general-8)
- [Localization](#localization)
  * [General](#general-9)

<!-- tocstop -->

## Resources

1.  [AngularJS](https://angularjs.org/)
2.  [AngularJS Tutorial](https://docs.angularjs.org/tutorial)
3.  [AngularJS Developer guide](https://docs.angularjs.org/guide/)

## General

### Getting started

``` 
    <!doctype html>
    <html ng-app>
      <head>
        <script src="https://ajax.googleapis.com/ajax/libs/angularjs/1.5.0/angular.min.js"></script>
      </head>
      <body>
        <div>
          <label>Name:</label>
          <input type="text" ng-model="yourName" placeholder="Enter a name here">
          <hr>
          <h1>Hello {{yourName}}!</h1>
        </div>
      </body>
    </html>
                        
```

## Data Binding

### General

Data-binding is an automatic way of updating the view whenever the model
changes, as well as updating the model whenever the view changes. This
is awesome because it eliminates DOM manipulation from the list of
things you have to worry about.

Simple example is seen in hello world.

Accomplished using ng-model directive and *{{* *}}*, ng-repeat and
others.

### Templates

Templates are written with HTML that contains Angular-specific elements
and attributes. Angular combines the template with information from the
model and controller to render the dynamic view that a user sees in the
browser.

These are the types of Angular elements and attributes you can use:

  - [Directive](https://docs.angularjs.org/guide/directive) — An
    attribute or element that augments an existing DOM element or
    represents a reusable DOM component.
  - [Markup](https://docs.angularjs.org/api/ng/service/$interpolate) —
    The double curly brace notation {{ }} to bind expressions to
    elements is built-in Angular markup.
  - [Filter](https://docs.angularjs.org/guide/filter) — Formats data for
    display.
  - [Form controls](https://docs.angularjs.org/guide/forms) — Validates
    user input.

In a simple app, the template consists of HTML, CSS, and Angular
directives contained in just one HTML file (usually index.html).  
In a more complex app, you can display multiple views within one main
page using "partials" – segments of template located in separate HTML
files. You can use the ngView directive to load partials based on
configuration passed to the $route service.

### Compiler

Compiler is an Angular service which traverses the DOM looking for
attributes. The compilation process happens in two phases. Compile:
traverse the DOM and collect all of the directives. The result is a
linking function. Link: combine the directives with a scope and produce
a live view. Any changes in the scope model are reflected in the view,
and any user interactions with the view are reflected in the scope
model. This makes the scope model the single source of truth.

### Directive

A directive is a behavior which should be triggered when specific HTML
constructs are encountered during the compilation process. The
directives can be placed in element names, attributes, class names, as
well as comments.

A directive is just a function which executes when the compiler
encounters it in the DOM. See [directive
API](https://docs.angularjs.org/api/ng/provider/$compileProvider#directive)
for in-depth documentation on how to write directives.

More info [here.](https://docs.angularjs.org/guide/directive)

### Expression

The second kind of new markup are the double curly braces {{ expression
| filter }}: When the compiler encounters this markup, it will replace
it with the evaluated value of the markup. An expression in a template
is a JavaScript-like code snippet that allows Angular to read and write
variables. Note that those variables are not global variables.

More info [here.](https://docs.angularjs.org/guide/expression)

### Filters

A filter formats the value of an expression for display to the user.
They can be used in view templates, controllers or services and it is
easy to define your own filter.

More info [here](https://docs.angularjs.org/guide/filter) and
[here](https://docs.angularjs.org/api/ng/filter)

## Scope

### General

Scope is an object that refers to the application model. It is an
execution context for expressions. Scopes are arranged in hierarchical
structure which mimic the DOM structure of the application. Scopes can
watch expressions and propagate events.

Scopes provide APIs ($watch) to observe model mutations. Scopes provide
APIs ($apply) to propagate any model changes through the system into the
view from outside of the "Angular realm" (controllers, services, Angular
event handlers).

### Hierarchies

Each Angular application has exactly one root scope, but may have
several child scopes. The application can have multiple scopes, because
some directives create new child scopes (refer to directive
documentation to see which directives create new scopes). When new
scopes are created, they are added as children of their parent scope.

### Debugging

To examine the scope in the debugger:

1.  Right click on the element of interest in your browser and select
    'inspect element'. You should see the browser debugger with the
    element you clicked on highlighted.

2.  The debugger allows you to access the currently selected element in
    the console as $0 variable.

3.  To retrieve the associated scope in console execute:
    angular.element($0).scope() or just type $scope

### Events

Scopes can propagate events in similar fashion to DOM events. The event
can be broadcasted to the scope children or emitted to scope parents.

More info [here.](https://docs.angularjs.org/guide/scope)

## Directives

Directives is a unique and powerful feature available only in Angular.
Directives let you invent new HTML syntax, specific to your application.

### Matching

Angular normalizes an element's tag and attribute name to determine
which elements match which directives. We typically refer to directives
by their case-sensitive camelCase normalized name (e.g. ngModel).
However, since HTML is case-insensitive, we refer to directives in the
DOM by lower-case forms, typically using dash-delimited attributes on
DOM elements (e.g. ng-model). The normalization process is as follows:
Strip x- and data- from the front of the element/attributes. Convert the
:, -, or _-delimited name to camelCase.

``` 


<div ng-controller="Controller">
  Hello <input ng-model='name'> <hr/>
  <span ng-bind="name"></span> <br/>
  <span ng:bind="name"></span> <br/>
  <span ng_bind="name"></span> <br/>
  <span data-ng-bind="name"></span> <br/>
  <span x-ng-bind="name"></span> <br/>
                        
```

$compile can match directives based on element names, attributes, class
names, as well as comments. All of the Angular-provided directives match
attribute name, tag name, comments, or class name.

``` 
<my-dir></my-dir>
<span my-dir="exp"></span>
<!-- directive: my-dir exp -->
<span class="my-dir: exp;"></span>                        
```

### Creating

Much like controllers, directives are registered on modules. To register
a directive, you use the module.directive API. module.directive takes
the normalized directive name followed by a factory function. This
factory function should return an object with the different options to
tell $compile how the directive should behave when matched.

### Directive list

| Name                                                                         | Description                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |
| ---------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| [ngJq](https://docs.angularjs.org/api/ng/directive/ngJq)                     | Use this directive to force the angular.element library. This should be used to force either jqLite by leaving ng-jq blank or setting the name of the jquery variable under window (eg. jQuery).                                                                                                                                                                                                                                                                                                                                                    |
| [ngApp](https://docs.angularjs.org/api/ng/directive/ngApp)                   | Use this directive to **auto-bootstrap** an AngularJS application. The `ngApp` directive designates the **root element** of the application and is typically placed near the root element of the page - e.g. on the `<body>` or `<html>` tags.                                                                                                                                                                                                                                                                                                      |
| [a](https://docs.angularjs.org/api/ng/directive/a)                           | Modifies the default behavior of the html A tag so that the default action is prevented when the href attribute is empty.                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [ngHref](https://docs.angularjs.org/api/ng/directive/ngHref)                 | Using Angular markup like `{{hash}}` in an href attribute will make the link go to the wrong URL if the user clicks it before Angular has a chance to replace the `{{hash}}` markup with its value. Until Angular replaces the markup the link will be broken and will most likely return a 404 error. The `ngHref` directive solves this problem.                                                                                                                                                                                                  |
| [ngSrc](https://docs.angularjs.org/api/ng/directive/ngSrc)                   | Using Angular markup like `{{hash}}` in a `src` attribute doesn't work right: The browser will fetch from the URL with the literal text `{{hash}}` until Angular replaces the expression inside `{{hash}}`. The `ngSrc` directive solves this problem.                                                                                                                                                                                                                                                                                              |
| [ngSrcset](https://docs.angularjs.org/api/ng/directive/ngSrcset)             | Using Angular markup like `{{hash}}` in a `srcset` attribute doesn't work right: The browser will fetch from the URL with the literal text `{{hash}}` until Angular replaces the expression inside `{{hash}}`. The `ngSrcset` directive solves this problem.                                                                                                                                                                                                                                                                                        |
| [ngDisabled](https://docs.angularjs.org/api/ng/directive/ngDisabled)         | This directive sets the `disabled` attribute on the element if the [expression](guide/expression) inside `ngDisabled` evaluates to truthy.                                                                                                                                                                                                                                                                                                                                                                                                          |
| [ngChecked](https://docs.angularjs.org/api/ng/directive/ngChecked)           | Sets the `checked` attribute on the element, if the expression inside `ngChecked` is truthy.                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
| [ngReadonly](https://docs.angularjs.org/api/ng/directive/ngReadonly)         | Sets the `readOnly` attribute on the element, if the expression inside `ngReadonly` is truthy.                                                                                                                                                                                                                                                                                                                                                                                                                                                      |
| [ngSelected](https://docs.angularjs.org/api/ng/directive/ngSelected)         | Sets the `selected` attribute on the element, if the expression inside `ngSelected` is truthy.                                                                                                                                                                                                                                                                                                                                                                                                                                                      |
| [ngOpen](https://docs.angularjs.org/api/ng/directive/ngOpen)                 | Sets the `open` attribute on the element, if the expression inside `ngOpen` is truthy.                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
| [ngForm](https://docs.angularjs.org/api/ng/directive/ngForm)                 | Nestable alias of [`form`](https://docs.angularjs.org/api/ng/directive/form) directive. HTML does not allow nesting of form elements. It is useful to nest forms, for example if the validity of a sub-group of controls needs to be determined.                                                                                                                                                                                                                                                                                                    |
| [form](https://docs.angularjs.org/api/ng/directive/form)                     | Directive that instantiates [FormController](https://docs.angularjs.org/api/ng/type/form.FormController).                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [textarea](https://docs.angularjs.org/api/ng/directive/textarea)             | HTML textarea element control with angular data-binding. The data-binding and validation properties of this element are exactly the same as those of the [input element](https://docs.angularjs.org/api/ng/directive/input).                                                                                                                                                                                                                                                                                                                        |
| [input](https://docs.angularjs.org/api/ng/directive/input)                   | HTML input element control. When used together with [`ngModel`](https://docs.angularjs.org/api/ng/directive/ngModel), it provides data-binding, input state control, and validation. Input control follows HTML5 input types and polyfills the HTML5 validation behavior for older browsers.                                                                                                                                                                                                                                                        |
| [ngValue](https://docs.angularjs.org/api/ng/directive/ngValue)               | Binds the given expression to the value of `<option>` or [`input[radio]`](https://docs.angularjs.org/api/ng/input/input%5Bradio%5D), so that when the element is selected, the [`ngModel`](https://docs.angularjs.org/api/ng/directive/ngModel) of that element is set to the bound value.                                                                                                                                                                                                                                                          |
| [ngBind](https://docs.angularjs.org/api/ng/directive/ngBind)                 | The `ngBind` attribute tells Angular to replace the text content of the specified HTML element with the value of a given expression, and to update the text content when the value of that expression changes.                                                                                                                                                                                                                                                                                                                                      |
| [ngBindTemplate](https://docs.angularjs.org/api/ng/directive/ngBindTemplate) | The `ngBindTemplate` directive specifies that the element text content should be replaced with the interpolation of the template in the `ngBindTemplate` attribute. Unlike `ngBind`, the `ngBindTemplate` can contain multiple `{{` `}}` expressions. This directive is needed since some HTML elements (such as TITLE and OPTION) cannot contain SPAN elements.                                                                                                                                                                                    |
| [ngBindHtml](https://docs.angularjs.org/api/ng/directive/ngBindHtml)         | Evaluates the expression and inserts the resulting HTML into the element in a secure way. By default, the resulting HTML content will be sanitized using the [$sanitize](api/ngSanitize/service/$sanitize) service. To utilize this functionality, ensure that `$sanitize` is available, for example, by including [`ngSanitize`](api/ngSanitize) in your module's dependencies (not in core Angular). In order to use [`ngSanitize`](api/ngSanitize) in your module's dependencies, you need to include "angular-sanitize.js" in your application. |
| [ngChange](https://docs.angularjs.org/api/ng/directive/ngChange)             | Evaluate the given expression when the user changes the input. The expression is evaluated immediately, unlike the JavaScript onchange event which only triggers at the end of a change (usually, when the user leaves the form element or presses the return key).                                                                                                                                                                                                                                                                                 |
| [ngClass](https://docs.angularjs.org/api/ng/directive/ngClass)               | The `ngClass` directive allows you to dynamically set CSS classes on an HTML element by databinding an expression that represents all classes to be added.                                                                                                                                                                                                                                                                                                                                                                                          |
| [ngClassOdd](https://docs.angularjs.org/api/ng/directive/ngClassOdd)         | The `ngClassOdd` and `ngClassEven` directives work exactly as [ngClass](https://docs.angularjs.org/api/ng/directive/ngClass), except they work in conjunction with `ngRepeat` and take effect only on odd (even) rows.                                                                                                                                                                                                                                                                                                                              |
| [ngClassEven](https://docs.angularjs.org/api/ng/directive/ngClassEven)       | The `ngClassOdd` and `ngClassEven` directives work exactly as [ngClass](https://docs.angularjs.org/api/ng/directive/ngClass), except they work in conjunction with `ngRepeat` and take effect only on odd (even) rows.                                                                                                                                                                                                                                                                                                                              |
| [ngCloak](https://docs.angularjs.org/api/ng/directive/ngCloak)               | The `ngCloak` directive is used to prevent the Angular html template from being briefly displayed by the browser in its raw (uncompiled) form while your application is loading. Use this directive to avoid the undesirable flicker effect caused by the html template display.                                                                                                                                                                                                                                                                    |
| [ngController](https://docs.angularjs.org/api/ng/directive/ngController)     | The `ngController` directive attaches a controller class to the view. This is a key aspect of how angular supports the principles behind the Model-View-Controller design pattern.                                                                                                                                                                                                                                                                                                                                                                  |
| [ngCsp](https://docs.angularjs.org/api/ng/directive/ngCsp)                   | Angular has some features that can break certain [CSP (Content Security Policy)](https://developer.mozilla.org/en/Security/CSP) rules.                                                                                                                                                                                                                                                                                                                                                                                                              |
| [ngClick](https://docs.angularjs.org/api/ng/directive/ngClick)               | The ngClick directive allows you to specify custom behavior when an element is clicked.                                                                                                                                                                                                                                                                                                                                                                                                                                                             |
| [ngDblclick](https://docs.angularjs.org/api/ng/directive/ngDblclick)         | The `ngDblclick` directive allows you to specify custom behavior on a dblclick event.                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
| [ngMousedown](https://docs.angularjs.org/api/ng/directive/ngMousedown)       | The ngMousedown directive allows you to specify custom behavior on mousedown event.                                                                                                                                                                                                                                                                                                                                                                                                                                                                 |
| [ngMouseup](https://docs.angularjs.org/api/ng/directive/ngMouseup)           | Specify custom behavior on mouseup event.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [ngMouseover](https://docs.angularjs.org/api/ng/directive/ngMouseover)       | Specify custom behavior on mouseover event.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |
| [ngMouseenter](https://docs.angularjs.org/api/ng/directive/ngMouseenter)     | Specify custom behavior on mouseenter event.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
| [ngMouseleave](https://docs.angularjs.org/api/ng/directive/ngMouseleave)     | Specify custom behavior on mouseleave event.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
| [ngMousemove](https://docs.angularjs.org/api/ng/directive/ngMousemove)       | Specify custom behavior on mousemove event.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |
| [ngKeydown](https://docs.angularjs.org/api/ng/directive/ngKeydown)           | Specify custom behavior on keydown event.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [ngKeyup](https://docs.angularjs.org/api/ng/directive/ngKeyup)               | Specify custom behavior on keyup event.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             |
| [ngKeypress](https://docs.angularjs.org/api/ng/directive/ngKeypress)         | Specify custom behavior on keypress event.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| [ngSubmit](https://docs.angularjs.org/api/ng/directive/ngSubmit)             | Enables binding angular expressions to onsubmit events.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             |
| [ngFocus](https://docs.angularjs.org/api/ng/directive/ngFocus)               | Specify custom behavior on focus event.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             |
| [ngBlur](https://docs.angularjs.org/api/ng/directive/ngBlur)                 | Specify custom behavior on blur event.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
| [ngCopy](https://docs.angularjs.org/api/ng/directive/ngCopy)                 | Specify custom behavior on copy event.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
| [ngCut](https://docs.angularjs.org/api/ng/directive/ngCut)                   | Specify custom behavior on cut event.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
| [ngPaste](https://docs.angularjs.org/api/ng/directive/ngPaste)               | Specify custom behavior on paste event.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             |
| [ngIf](https://docs.angularjs.org/api/ng/directive/ngIf)                     | The `ngIf` directive removes or recreates a portion of the DOM tree based on an {expression}. If the expression assigned to `ngIf` evaluates to a false value then the element is removed from the DOM, otherwise a clone of the element is reinserted into the DOM.                                                                                                                                                                                                                                                                                |
| [ngInclude](https://docs.angularjs.org/api/ng/directive/ngInclude)           | Fetches, compiles and includes an external HTML fragment.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| [ngInit](https://docs.angularjs.org/api/ng/directive/ngInit)                 | The `ngInit` directive allows you to evaluate an expression in the current scope.                                                                                                                                                                                                                                                                                                                                                                                                                                                                   |
| [ngList](https://docs.angularjs.org/api/ng/directive/ngList)                 | Text input that converts between a delimited string and an array of strings. The default delimiter is a comma followed by a space - equivalent to `ng-list=", "`. You can specify a custom delimiter as the value of the `ngList` attribute - for example, `ng-list=" | "`.                                                                                                                                                                                                                                                                        |
| [ngModel](https://docs.angularjs.org/api/ng/directive/ngModel)               | The `ngModel` directive binds an `input`,`select`, `textarea` (or custom form control) to a property on the scope using [NgModelController](https://docs.angularjs.org/api/ng/type/ngModel.NgModelController), which is created and exposed by this directive.                                                                                                                                                                                                                                                                                      |
| [ngModelOptions](https://docs.angularjs.org/api/ng/directive/ngModelOptions) | Allows tuning how model updates are done. Using `ngModelOptions` you can specify a custom list of events that will trigger a model update and/or a debouncing delay so that the actual update only takes place when a timer expires; this timer will be reset after another change takes place.                                                                                                                                                                                                                                                     |
| [ngNonBindable](https://docs.angularjs.org/api/ng/directive/ngNonBindable)   | The `ngNonBindable` directive tells Angular not to compile or bind the contents of the current DOM element. This is useful if the element contains what appears to be Angular directives and bindings but which should be ignored by Angular. This could be the case if you have a site that displays snippets of code, for instance.                                                                                                                                                                                                               |
| [ngOptions](https://docs.angularjs.org/api/ng/directive/ngOptions)           | The `ngOptions` attribute can be used to dynamically generate a list of `<option>` elements for the `<select>` element using the array or object obtained by evaluating the `ngOptions` comprehension expression.                                                                                                                                                                                                                                                                                                                                   |
| [ngPluralize](https://docs.angularjs.org/api/ng/directive/ngPluralize)       | `ngPluralize` is a directive that displays messages according to en-US localization rules. These rules are bundled with angular.js, but can be overridden (see [Angular i18n](guide/i18n) dev guide). You configure ngPluralize directive by specifying the mappings between [plural categories](http://unicode.org/repos/cldr-tmp/trunk/diff/supplemental/language_plural_rules.html) and the strings to be displayed.                                                                                                                             |
| [ngRepeat](https://docs.angularjs.org/api/ng/directive/ngRepeat)             | The `ngRepeat` directive instantiates a template once per item from a collection. Each template instance gets its own scope, where the given loop variable is set to the current collection item, and `$index` is set to the item index or key.                                                                                                                                                                                                                                                                                                     |
| [ngShow](https://docs.angularjs.org/api/ng/directive/ngShow)                 | The `ngShow` directive shows or hides the given HTML element based on the expression provided to the `ngShow` attribute. The element is shown or hidden by removing or adding the `.ng-hide` CSS class onto the element. The `.ng-hide` CSS class is predefined in AngularJS and sets the display style to none (using an !important flag). For CSP mode please add `angular-csp.css` to your html file (see [ngCsp](https://docs.angularjs.org/api/ng/directive/ngCsp)).                                                                          |
| [ngHide](https://docs.angularjs.org/api/ng/directive/ngHide)                 | The `ngHide` directive shows or hides the given HTML element based on the expression provided to the `ngHide` attribute. The element is shown or hidden by removing or adding the `ng-hide` CSS class onto the element. The `.ng-hide` CSS class is predefined in AngularJS and sets the display style to none (using an !important flag). For CSP mode please add `angular-csp.css` to your html file (see [ngCsp](https://docs.angularjs.org/api/ng/directive/ngCsp)).                                                                           |
| [ngStyle](https://docs.angularjs.org/api/ng/directive/ngStyle)               | The `ngStyle` directive allows you to set CSS style on an HTML element conditionally.                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
| [ngSwitch](https://docs.angularjs.org/api/ng/directive/ngSwitch)             | The `ngSwitch` directive is used to conditionally swap DOM structure on your template based on a scope expression. Elements within `ngSwitch` but without `ngSwitchWhen` or `ngSwitchDefault` directives will be preserved at the location as specified in the template.                                                                                                                                                                                                                                                                            |
| [ngTransclude](https://docs.angularjs.org/api/ng/directive/ngTransclude)     | Directive that marks the insertion point for the transcluded DOM of the nearest parent directive that uses transclusion.                                                                                                                                                                                                                                                                                                                                                                                                                            |
| [script](https://docs.angularjs.org/api/ng/directive/script)                 | Load the content of a `<script>` element into [`$templateCache`](https://docs.angularjs.org/api/ng/service/$templateCache), so that the template can be used by [`ngInclude`](https://docs.angularjs.org/api/ng/directive/ngInclude), [`ngView`](api/ngRoute/directive/ngView), or [directives](guide/directive). The type of the `<script>` element must be specified as `text/ng-template`, and a cache name for the template must be assigned through the element's `id`, which can then be used as a directive's `templateUrl`.                 |
| [select](https://docs.angularjs.org/api/ng/directive/select)                 | HTML `SELECT` element with angular data-binding.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    |
| [ngRequired](https://docs.angularjs.org/api/ng/directive/ngRequired)         | ngRequired adds the required [`validator`](https://docs.angularjs.org/api/ng/type/ngModel.NgModelController#$validators) to [`ngModel`](https://docs.angularjs.org/api/ng/directive/ngModel). It is most often used for [`input`](https://docs.angularjs.org/api/ng/directive/input) and [`select`](https://docs.angularjs.org/api/ng/directive/select) controls, but can also be applied to custom controls.                                                                                                                                       |
| [ngPattern](https://docs.angularjs.org/api/ng/directive/ngPattern)           | ngPattern adds the pattern [`validator`](https://docs.angularjs.org/api/ng/type/ngModel.NgModelController#$validators) to [`ngModel`](https://docs.angularjs.org/api/ng/directive/ngModel). It is most often used for text-based [`input`](https://docs.angularjs.org/api/ng/directive/input) controls, but can also be applied to custom text-based controls.                                                                                                                                                                                      |
| [ngMaxlength](https://docs.angularjs.org/api/ng/directive/ngMaxlength)       | ngMaxlength adds the maxlength [`validator`](https://docs.angularjs.org/api/ng/type/ngModel.NgModelController#$validators) to [`ngModel`](https://docs.angularjs.org/api/ng/directive/ngModel). It is most often used for text-based [`input`](https://docs.angularjs.org/api/ng/directive/input) controls, but can also be applied to custom text-based controls.                                                                                                                                                                                  |
| [ngMinlength](https://docs.angularjs.org/api/ng/directive/ngMinlength)       | ngMinlength adds the minlength [`validator`](https://docs.angularjs.org/api/ng/type/ngModel.NgModelController#$validators) to [`ngModel`](https://docs.angularjs.org/api/ng/directive/ngModel). It is most often used for text-based [`input`](https://docs.angularjs.org/api/ng/directive/input) controls, but can also be applied to custom text-based controls.                                                                                                                                                                                  |

More info can be found
[here.](https://docs.angularjs.org/guide/directive)

## Component

### General

In Angular, a Component is a special kind of directive that uses a
simpler configuration which is suitable for a component-based
application structure.

Advantages of Components:

  - simpler configuration than plain directives
  - promote sane defaults and best practices
  - optimized for component-based architecture
  - writing component directives will make it easier to upgrade to
    Angular 2

When not to use Components:

  - for directives that rely on DOM manipulation, adding event listeners
    etc, because the compile and link functions are unavailable
  - when you need advanced directive definition options like priority,
    terminal, multi-element
  - when you want a directive that is triggered by an attribute or CSS
    class, rather than an element

More info can be found
[here.](https://docs.angularjs.org/guide/component)

## Controller

### General

Controllers are the behavior behind the DOM elements. AngularJS lets you
express the behavior in a clean readable form without the usual
boilerplate of updating the DOM, registering callbacks or watching model
changes.

Accomplished using ng-controller

``` 
<!doctype html>
<html ng-app="todoApp">
  <head>
    <script src="https://ajax.googleapis.com/ajax/libs/angularjs/1.5.0/angular.min.js"></script>
    <script src="second_todo.js"></script>
    <style>
        .done-true {
          text-decoration: line-through;
          color: grey;
        }
    </style>
  </head>
  <body>
    <h2>Todo</h2>
    <div ng-controller="TodoListController as todoList">
      <span>{{todoList.remaining()}} of {{todoList.todos.length}} remaining</span>
      [ <a href="" ng-click="todoList.archive()">archive</a> ]
      <ul class="unstyled">
        <li ng-repeat="todo in todoList.todos">
          <label class="checkbox">
            <input type="checkbox" ng-model="todo.done">
            <span class="done-{{todo.done}}">{{todo.text}}</span>
          </label>
        </li>
      </ul>
      <form ng-submit="todoList.addTodo()">
        <input type="text" ng-model="todoList.todoText"  size="30"
               placeholder="add new todo here">
        <input class="btn-primary" type="submit" value="add">
      </form>
    </div>
  </body>
</html>
                        
```

``` 
angular.module('todoApp', [])
  .controller('TodoListController', function() {
    var todoList = this;
    todoList.todos = [
      {text:'learn angular', done:true},
      {text:'build an angular app', done:false}];

    todoList.addTodo = function() {
      todoList.todos.push({text:todoList.todoText, done:false});
      todoList.todoText = '';
    };

    todoList.remaining = function() {
      var count = 0;
      angular.forEach(todoList.todos, function(todo) {
        count += todo.done ? 0 : 1;
      });
      return count;
    };

    todoList.archive = function() {
      var oldTodos = todoList.todos;
      todoList.todos = [];
      angular.forEach(oldTodos, function(todo) {
        if (!todo.done) todoList.todos.push(todo);
      });
    };
  });

                        
```

### Definition

In Angular, a Controller is defined by a JavaScript constructor function
that is used to augment the Angular Scope.

When a Controller is attached to the DOM via the ng-controller
directive, Angular will instantiate a new Controller object, using the
specified Controller's constructor function. A new child scope will be
created and made available as an injectable parameter to the
Controller's constructor function as $scope.

If the controller has been attached using the controller as syntax then
the controller instance will be assigned to a property on the new scope.

You can associate Controllers with scope objects implicitly via the
ngController directive or $route service.

It is common to attach Controllers at different levels of the DOM
hierarchy. Since the ng-controller directive creates a new child scope,
we get a hierarchy of scopes that inherit from each other.

More info [here.](https://docs.angularjs.org/guide/controller)

## Services

### General

When the application grows it is a good practice to move
view-independent logic from the controller into a service, so it can be
reused by other parts of the application as well.

Angular services are: Lazily instantiated – Angular only instantiates a
service when an application component depends on it. Singletons – Each
component dependent on a service gets a reference to the single instance
generated by the service factory. Angular offers several useful services
(like $http)

To use an Angular service, you add it as a dependency for the component
(controller, service, filter or directive) that depends on the service.

## Deep Linking

### General

A deep link reflects where the user is in the app, this is useful so
users can bookmark and email links to locations within apps. Round trip
apps get this automatically, but AJAX apps by their nature do not.
AngularJS combines the benefits of deep link with desktop app-like
behavior.

### ngRoute & ngView

Starting with AngularJS version 1.2, ngRoute is in its own module and
must be loaded by loading the additional angular-route.js file.

More information [here](https://docs.angularjs.org/api/ngRoute)

More information
[here](https://docs.angularjs.org/api/ngRoute/directive/ngView)

## Form Validation

### General

Client-side form validation is an important part of great user
experience. AngularJS lets you declare the validation rules of the form
without having to write JavaScript code. Write less code, go have beer
sooner.

### CSS Classes

To allow styling of form as well as controls, ngModel adds these CSS
classes:

  - `ng-valid`: the model is valid
  - `ng-invalid`: the model is invalid
  - `ng-valid-[key]`: for each valid key added by `$setValidity`
  - `ng-invalid-[key]`: for each invalid key added by `$setValidity`
  - `ng-pristine`: the control hasn't been interacted with yet
  - `ng-dirty`: the control has been interacted with
  - `ng-touched`: the control has been blurred
  - `ng-untouched`: the control hasn't been blurred
  - `ng-pending`: any `$asyncValidators` are unfulfilled

### Example

``` 


<div ng-controller="ExampleController">
  <form novalidate class="css-form">
    Name: <input type="text" ng-model="user.name" required /><br />
    E-mail: <input type="email" ng-model="user.email" required /><br />
    Gender: <input type="radio" ng-model="user.gender" value="male" />male
    <input type="radio" ng-model="user.gender" value="female" />female<br />
    <input type="button" ng-click="reset()" value="Reset" />
    <input type="submit" ng-click="update(user)" value="Save" />
  </form>
  <pre>user = {{user | json}}</pre>
  <pre>master = {{master | json}}</pre>
<style type="text/css">
  .css-form input.ng-invalid.ng-touched {
    background-color: #FA787E;
  }

  .css-form input.ng-valid.ng-touched {
    background-color: #78FA89;
  }
</style>

<script>
  angular.module('formExample', [])
    .controller('ExampleController', ['$scope', function($scope) {
      $scope.master = {};

      $scope.update = function(user) {
        $scope.master = angular.copy(user);
      };

      $scope.reset = function() {
        $scope.user = angular.copy($scope.master);
      };

      $scope.reset();
    }]);
</script>

                        
```

### Custom validation

Angular provides basic implementation for most common HTML5 input types:
(text, number, url, email, date, radio, checkbox), as well as some
directives for validation (required, pattern, minlength, maxlength, min,
max).

``` 
<form name="form" class="css-form" novalidate>
    <div>Size (integer 0 - 10):
        <input type="number" ng-model="size" name="size" min="0" max="10" integer/>
        {{size}}
        <br/>
        <span ng-show="form.size.$error.integer">The value is not a valid integer!</span>
        <span ng-show="form.size.$error.min || form.size.$error.max">The value must be in range 0 to 10!</span>
    </div>
    <div>Username:
        <input type="text" ng-model="name" name="name" username/>
        {{name}}
        <br/>
        <span ng-show="form.name.$pending.username">Checking if this name is available...</span>
        <span ng-show="form.name.$error.username">This username is already taken!</span>
    </div>
</form>
                        
```


``` 

var app = angular.module('form-example1', []);

var INTEGER_REGEXP = /^-?d+$/;
app.directive('integer', function() {
  return {
    require: 'ngModel',
    link: function(scope, elm, attrs, ctrl) {
      ctrl.$validators.integer = function(modelValue, viewValue) {
        if (ctrl.$isEmpty(modelValue)) {
          // consider empty models to be valid
          return true;
        }

        if (INTEGER_REGEXP.test(viewValue)) {
          // it is valid
          return true;
        }

        // it is invalid
        return false;
      };
    }
  };
});

app.directive('username', function($q, $timeout) {
  return {
    require: 'ngModel',
    link: function(scope, elm, attrs, ctrl) {
      var usernames = ['Jim', 'John', 'Jill', 'Jackie'];

      ctrl.$asyncValidators.username = function(modelValue, viewValue) {

        if (ctrl.$isEmpty(modelValue)) {
          // consider empty model valid
          return $q.when();
        }

        var def = $q.defer();

        $timeout(function() {
          // Mock a delayed response
          if (usernames.indexOf(modelValue) === -1) {
            // The username is available
            def.resolve();
          } else {
            def.reject();
          }

        }, 2000);

        return def.promise;
      };
    }
  };
});

                        
```

More info [here.](https://docs.angularjs.org/guide/forms)

## Server Communication

### General

AngularJS provides built-in services on top of XHR as well as various
other backends using third party libraries. Promises further simplify
your code by handling asynchronous return of data.

## Localization

### General

An important part of serious apps is localization. Angular's locale
aware filters and stemming directives give you building blocks to make
your application available in all locales.

