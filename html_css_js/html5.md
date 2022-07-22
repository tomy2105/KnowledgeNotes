# HTML5

<!-- toc -->

- [Resources](#resources)
- [Template](#template)
- [Tags](#tags)
  * [Display](#display)
  * [Block tags](#block-tags)
  * [Inline tags](#inline-tags)
  * [Important attributes](#important-attributes)
- [Various elements](#various-elements)
  * [Favicon](#favicon)
  * [Table](#table)
- [CSS](#css)
  * [Selectors](#selectors)
  * [Pseudo clases](#pseudo-clases)
  * [CSS Properties](#css-properties)
  * [Size values](#size-values)
  * [Size ordering](#size-ordering)
  * [Rule ordering](#rule-ordering)
  * [Media queries](#media-queries)

<!-- tocstop -->

## Resources

1.  [W3School HTML Element
    Reference](http://www.w3schools.com/tags/default.asp)
2.  [W3School CSS Element
    Reference](http://www.w3schools.com/css/default.asp)
3.  [Validator](https://validator.w3.org/)
4.  [CSS Validator](https://jigsaw.w3.org/css-validator/)
5.  The [Learn to Code HTML & CSS](http://learn.shayhowe.com/html-css/)
6.  The [World Wide Web project page (ancient
    history)](http://info.cern.ch/hypertext/WWW/TheProject.html)
7.  [Web Accessibility Evaluation Tool](http://wave.webaim.org/)
8.  [Bootstrap](http://getbootstrap.com/) - popular HTML, CSS, and JS
    framework for developing responsive, mobile first projects on the
    web.
9.  [HTML by Mozilla](https://developer.mozilla.org/en-US/Learn/HTML)
10. [CSS by Mozilla](https://developer.mozilla.org/en-US/Learn/CSS)
11. [Codepen](http://codepen.io/)
12. [CSS Zen Garden](http://www.csszengarden.com/)
13. [Importance of
    headings](http://webdesign.tutsplus.com/articles/the-truth-about-multiple-h1-tags-in-the-html5-era--webdesign-16824)
14. [CSS Tools (including reset and diagnostic
    css)](http://meyerweb.com/eric/tools/css/)
15. [Normalize CSS](http://necolas.github.io/normalize.css/)
16. [Reboot Normalize
    CSS](http://v4-alpha.getbootstrap.com/content/reboot/)
17. [CSS Generator](http://css3generator.com/)
18. [Web Developer toolbar for
    browsers](http://chrispederick.com/work/web-developer/)
19. [Can I use new features in HTML/CSS in which browser
    version](http://caniuse.com/)
20. [Web Accessibility Initiative](http://www.w3.org/WAI/)
21. [Text Only Internet](http://www.textise.net/)
22. [ChromeVox web page screen reader](http://www.chromevox.com/)
23. [Font Awesome](https://fortawesome.github.io/Font-Awesome/)
24. [Beginner’s Guide to Responsive Web
    Design](http://blog.teamtreehouse.com/beginners-guide-to-responsive-web-design)
25. [The 2014 Guide to Responsive Web
    Design](http://blog.teamtreehouse.com/modern-field-guide-responsive-web-design)
26. [Navigation
    design](http://www.hongkiat.com/blog/navigation-design-ideas-inspiration/)
27. [Breeadcrumbs
    guide](http://blog.woorank.com/2014/11/breadcrumb-navigation-guide/)
28. [The Final Nail in the Icon Fonts
    Coffin?](http://www.sitepoint.com/final-nail-icon-fonts-coffin/)
29. [Using SVG](http://gomakethings.com/using-svgs/)
30. [Web design for everybody](http://www.intro-webdesign.com/)
31. [Less getting started](http://lesscss.org/)
32. [Another Less getting
    started](https://scotch.io/tutorials/getting-started-with-less)
33. [Sass basics](http://sass-lang.com/guide)
34. [Getting started with Sass with interactive
    examples](https://scotch.io/tutorials/getting-started-with-sass)
35. [Bower Web package manager](http://bower.io/)
36. [Favicon generator](http://realfavicongenerator.net/)
37. [JavaScript/HTML/CSS online editing](http://jsbin.com/)
38. [Another JavaScript/HTML/CSS online editing](http://codepen.io/)
39. [Rem vs. Em vs. Px — Sizing Elements In
    CSS](https://www.futurehosting.com/blog/web-design-basics-rem-vs-em-vs-px-sizing-elements-in-css/)
40. [Font Size Idea: px at the Root, rem for Components, em for Text
    Elements](https://css-tricks.com/rems-ems/)

## Template

    <!DOCTYPE html>
    <html lang="en">
    <head>
        <meta charset="UTF-8">
        <title>My First Page</title>
    </head>
    <body>
        <header>
            An important information at the top
        </header>
        <nav>
            Here goes navigation (some prefer it to be a list).
        </nav>
        <main>
            <p>This should be displayed by the browser.</p>
        </main>
        <footer>
            Copyright by me.
        </footer>
        
    </body>
    </html>

## Tags

### Display

The most important attributes in an element and that's its display. The
two most common display types are:

  - *Block* tags are ones that take up a certain amount of width and
    height. So anytime you have a tag that's called block, it's the same
    thing as if when you were typing, you hit newline at the end, or
    enter or return.
  - *Inline* tags are ones that only take up as much space as is needed.

### Block tags

  - *address* - Contact information
  - *article* - (HTML5) Article content
  - *aside* - (HTML5) Aside content
  - *blockquote* - Long ("block") quotation
  - *canvas* - (HTML5) Drawing canvas
  - *dd* - Definition description
  - *div* - Document division - generic section larger than paragraph
  - *dl* - Definition list, tag is used in conjunction with dt (defines
    terms/names) and dd (describes each term/name).
  - *fieldset* - Field set label
  - *figcaption* - (HTML5) Figure caption
  - *figure* - (HTML5) Groups media content with a caption (see
    figcaption) has a lot more semantics than the image tag, can include
    additional information like an image, multimedia, a combination of
    all of them
  - *footer* - (HTML5) Section or page footer - a section that contains
    information that is pretty typical for the bottom of the page, such
    as copyright data, related documents, your links to social media
  - *form* - Input form
  - *h1..6* - Heading levels 1-6
  - *header* - (HTML5) Section or page header
  - *hgroup* - (HTML5) Groups header information
  - *hr* - Horizontal rule (dividing line), void element (no end tag)
  - *main* - (HTML5) Contains the central content unique to this
    document
  - *nav* - (HTML5) Contains navigation links - a section of your page
    that links to other pages or parts within your page
  - *noscript* - Content to use if scripting is not supported or turned
    off
  - *ol* - Ordered list, *start* attribute specifies start number and
    *reversed* attribute for reverse ordering, *type* attribute
    specifies number kind (1, A, a, I, i)
  - *output* - (HTML5) Form output
  - *p* - Paragraph - should contain only inline elements
  - *pre* - Preformatted text
  - *section* - (HTML5) Section of a web page
  - *table* - Table
  - *thead* - Table header
  - *tbody* - Table body
  - *tfoot* - Table footer
  - *ul* - Unordered list
  - *video* - (HTML5) Video player
  - *details* (HTML5) tag specifies additional details that the user can
    view or hide on demand
  - *meter* tag defines a scalar measurement within a known range, or a
    fractional value. This is also known as a gauge.
  - *progress* tag represents the progress of a task.
  - *mark* tag if you want to highlight parts of your text.

### Inline tags

  - *legend* - used with fieldset
  - *u* underline, do not use since it is confusing what is semantic
    meaning
  - *b* bold
  - *big*
  - *i*italic
  - *small*
  - *tt*
  - *abbr* - tag defines an abbreviation or an acronym \<abbr
    title="World Health Organization"\>WHO\</abbr\>
  - *acronym*
  - *cite*
  - *code*
  - *dfn*
  - *em* tag if you want to emphasize parts of your text.
  - *kbd*
  - *strong* tag if you want to make your parts of your text important.
  - *samp*
  - *var*
  - *a* with href attribute creates link, href can be absolute or
    relative address, if starting with \# goes to id of any tag in
    current document
  - *bdo*
  - *br* break, void element (no end tag)
  - *wbr* word break, void element (no end tag)
  - *img* add image to page, void element (no end tag)
  - *map*
  - *object*
  - *q*
  - *script*
  - *span*
  - *sub*
  - *sup*
  - *button*
  - *input* void element (no end tag)
  - *label*
  - *select*
  - *textarea*
  - *tr* - table row
  - *td* - table cell
  - *th* - table heading cell
  - *caption* - caption of something, can be inside table for example
  - *time* - defines a human-readable date/time
  - *meta* metadata for browser in head section, void element (no end
    tag)
  - *ins* - defines a text that has been inserted into a document.
  - *del* - defines a text that has been deleted from a document.

### Important attributes

  - *accesskey* - a shortcut key to kind of activate, or put into focus,
    an element
  - *alt* - alternative text (e.g. for images)
  - *class*
  - *id* - unique id for an element on the page
  - *style*
  - *tabindex* - order elements are visited when tabbing through page

## Various elements

### Favicon

    <head profile="http://www.w3.org/2005/10/profile">
    <link rel="icon" 
          type="image/png" 
          href="http://example.com/myicon.png">
    […]
    </head>

### Table

    <!DOCTYPE html>
    <html>
    <head>
    <style>
    table, th, td {
        border: 1px solid black;
    }
    </style>
    </head>
    <body>
    
    <table>
      <caption>Monthly savings</caption>
      <tr>
        <th>Month</th>
        <th>Savings</th>
      </tr>
      <tr>
        <td>January</td>
        <td>$100</td>
      </tr>
      <tr>
        <td>February</td>
        <td>$50</td>
      </tr>
    </table>
    
    </body>
    </html>

## CSS

Can be embedded in HTML (inline - style attribute, between style tags)
or external.

    <link rel="stylesheet" href="styles.css" type="text/css";>

### Selectors

Apply to tag name (selector), if start with . then class name (class
selector), if start with \# then id (id selector).

    #myid {color: red}
    p {color: red}
    .myclass {color: red}

Selectors can combines one after another (contextual selectors), so *p
em {background: yelow}* applies to emphasized text within paragraph.
Those take precedence over simple selectors.

Selectors can be grouped (separated with ,): *H1, H2, H3, H4, H5, H6
{color: red; font-family: sans-serif }*

Descendant selectors - separate with space (*nav a* - all anchors inside
a nav tag)

Child selectors - separate \> (*nav \> a* - all anchors that are
children of a nav tag)

Sibling selectors - separate \~ (*h1 \~ ol* - selects ol tag which
follows and is sibling of h1 tag)

Adjacent sibling selectors - separate + (*h1 + ol* - selects ol tag
which follows h1 tag)

Attribute selector - inside \[\] (a\[href="info.html"\]), can use
operators:

  - *^* - match beginning a\[href^="info.html"\]
  - *$* - match end a\[href$="info.html"\]
  - *\** - match anywhere a\[href\*="info.html"\]
  - *\~* - whitespace spearated with one word marthca \[rel\~="info"\]
  - *|* - hypenated spearated with one word marthca \[lang|="en"\]

### Pseudo clases

*selector.class:pseudo-class { property: value }*

  - *:active* Selects the active link
  - *:focus* Selects the \<input\> element that has focus
  - *:hover* Selects links on mouse over
  - *:link* Selects all unvisited links
  - *:visited* Selects all visited links
  - *:any-link* Selects all, both visited and unvisited, links
  - *:checked* Selects every checked \<input\> element
  - *:disabled* Selects every disabled \<input\> element
  - *:valid* Selects all \<input\> elements with a valid value
  - *:invalid* Selects all \<input\> elements with an invalid value
  - *:optional* Selects \<input\> elements with no "required" attribute
  - *:enabled* Selects every enabled \<input\> element
  - *:read-only* Selects \<input\> elements with a "readonly" attribute
    specified
  - *:read-write* Selects \<input\> elements with no "readonly"
    attribute
  - *:required* Selects \<input\> elements with a "required" attribute
    specified
  - *:in-range* Selects \<input\> elements with a value within a
    specified range
  - *:out-of-range* Selects \<input\> elements with a value outside a
    specified range
  - *:first-child* Selects every \<p\> elements that is the first child
    of its parent
  - *:last-child* Selects every \<p\> elements that is the last child of
    its parent
  - *:nth-child(n)* Selects every \<p\> element that is the second child
    of its parent
  - *:nth-last-child(n)* Selects every \<p\> element that is the second
    child of its parent, counting from the last child
  - *:only-child* Selects every \<p\> element that is the only child of
    its parent
  - *:first-of-type* Selects every \<p\> element that is the first \<p\>
    element of its parent
  - *:last-of-type* Selects every \<p\> element that is the last \<p\>
    element of its parent
  - *:nth-last-of-type(n)* Selects every \<p\> element that is the
    second \<p\> element of its parent, counting from the last child
  - *:nth-of-type(n)* Selects every \<p\> element that is the second
    \<p\> element of its parent
  - *:only-of-type* Selects every \<p\> element that is the only \<p\>
    element of its parent
  - *:empty* Selects every \<p\> element that has no children
  - *:root* Selects the document's root element
  - *:target* Selects the current active \#news element (clicked on a
    URL containing that anchor name)
  - *:lang(language)* Selects every \<p\> element with a lang attribute
    value starting with "it"
  - *:not(selector)* Selects every element that is not a \<p\> element
  - *::after* Insert content after every \<p\> element
  - *::before* Insert content before every \<p\> element
  - *::first-letter* Selects the first letter of every \<p\> element
  - *::first-line* Selects the first line of every \<p\> element
  - *::selection* Selects the portion of an element that is selected by
    a user
  - *:in-range* Matches when an element has its value attribute inside
    the specified range limitations for this element
  - *:out-of-range* Matches when an element has its value attribute
    outside the specified range limitations for this element
  - *:target* represents the unique element, if any, with an id matching
    the fragment identifier of the URI of the document

### CSS Properties

  - *background-position*
  - *background-size* - auto|length|cover (as large as possible so that
    the background area is completely covered) |contain (to the largest
    size such that both its width and its height can fit inside the
    content area)
  - *background-repeat*
  - *background-image*
  - *background-color* - background color, can use linear-gradient (with
    browser suffixes) for gradient color
  - *background-origin*
  - *background-clip*
  - *background-attachment*
  - *background* - shorthand for all above color image position/size
    repeat origin clip attachment
  - *color* - Color of text
  - *font-family* - text fonts
  - *font-face* - custom text fonts
  - *font-style* - normal/italic/oblique
  - *font-variant* - normal/small-caps
  - *font-size* - text size
  - *text-align* - text alignment left/right/center/justify
  - *line-height* - space between lines
  - *text-shadow* - adds shadow to text h-shadow v-shadow blur-radius
    color
  - *position* - element positioning, absolute, relative (in conjuction
    with top, left)
      - *static* Default value. Elements render in order, as they appear
        in the document flow
      - *absolute* The element is positioned relative to its first
        positioned (not static) ancestor element
      - *fixed* The element is positioned relative to the browser window
      - *relative* The element is positioned relative to its normal
        position, so left:20 adds 20 pixels to the element's LEFT
        position
  - *margin (-left/-top/-bottom/-right)* - additional space outside
    border between neighbours - positive (element moves right/down) -
    transparent  
    *margin: 0 auto;* can be used to center element that is block, not
    floating, and not fixed or absolute position.  
    If percentage it is percentage of width\!\!\! (even for top, bottom)
  - *z-index* - stacking order when elements are one above another
  - *padding (-left/-top/-bottom/-right)* - additional space between
    element and border - positive (element moves right/down) - color of
    the element  
    If percentage it is percentage of width\!\!\! (even for top, bottom)
  - *display*
      - *inline* - sits next to other elements and takes up just enough
        width and height
      - *block* - forces line break, takes up (by default) all
        horizontal width and just enough height but height and width can
        be specified
      - *inline-block* - same as inline but accepts height/width rules
      - *none* - removed from web page
      - *flex*
      - *inline-flex*
      - *inline-table*
      - *list-item*
      - *run-in*
      - *table*
      - *table-caption*
      - *table-column-group*
      - *table-header-group*
      - *table-footer-group*
      - *table-row-group*
      - *table-cell*
      - *table-column*
      - *table-row*
    
    [Display
    propery](http://www.w3schools.com/cssref/pr_class_display.asp)
  - *float* - left/right - reposition element to the right or left
    (won't overlap, "aware" of others)
  - *clear* - left/right/both - keep floating elements away
  - *overflow* - what happens if element is too small for its content
      - *visible* - show on top of other text
      - *hidden* - hide anything that goes beyond the box
      - *scroll* - display scrollbars
      - *auto* - adds scrollbars as needed
  - *visibility* - wether or not element is visible
      - *visible*
      - *hidden* - but space for it is reserved
      - *colapse* - only for table elements
  - *border* style width color (style is mandatory =
    none|hidden|dotted|dashed|solid|double|groove|ridge|inset|outset|initial|inherit)
  - *border-style*
    none|hidden|dotted|dashed|solid|double|groove|ridge|inset|outset|initial|inherit
  - *border-width* top right bottom left
  - *border-color* top right bottom left
  - *border-collapse* property sets whether the table borders are
    collapsed into a single border or separated
  - *box-sizing* - is used to tell the browser what the sizing
    properties (width and height) should include
      - *content-box* - the width and height properties (and min/max
        properties) includes only the content. Border, padding, or
        margin are not included
      - *border-box* - the width and height properties (and min/max
        properties) includes content, padding and border, but not the
        margin
  - *text-decoration* -
  - *list-style-type* - "numbering of lists" - disc |armenian | circle |
    cjk-ideographic | decimal | decimal-leading-zero | georgian | hebrew
    | hiragana | hiragana-iroha | katakana | katakana-iroha |
    lower-alpha | lower-greek | lower-latin | lower-roman | none|square
    | upper-alpha | upper-latin | upper-roman
  - *list-style-image* - url("path") - image of list items, overrides
    type
  - *list-style-position* - position of "disc" relative to border -
    inside | outside
  - *list-style* - shorthand for above list-style-type
    list-style-position list-style-image
  - *list-style* - shorthand for above list-style-type
    list-style-position list-style-image
  - *column-count* - the number of columns an element should be divided
    into (use prefixes to get it working on all browsers\!)
  - *column-gap* - the gap between the columns (use prefixes to get it
    working on all browsers\!)
  - *border-radius* - radius of border (use prefixes to get it working
    on all browsers\!)
  - *transition-property* - what to change (one|all|coma separated
    properties), like color, size, position
  - *transition-duration* - how long should it last
  - *transition-timing-function* -
    ease|linear|ease-in|ease-out|ease-in-out|cubic-bezier()
  - *transition-delay* - when transition starts
  - *transition* - shorthand property duration timing-function delay
  - *transform* - browser prefixes
      - *matrix(n,n,n,n,n,n)* Defines a 2D transformation, using a
        matrix of six values
      - *matrix3d (n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n)* Defines a 3D
        transformation, using a 4x4 matrix of 16 values
      - *translate(x,y)* Defines a 2D translation
      - *translate3d(x,y,z)* Defines a 3D translation
      - *translateX(x)* Defines a translation, using only the value for
        the X-axis
      - *translateY(y)* Defines a translation, using only the value for
        the Y-axis
      - *translateZ(z)* Defines a 3D translation, using only the value
        for the Z-axis
      - *scale(x,y)* Defines a 2D scale transformation
      - *scale3d(x,y,z)* Defines a 3D scale transformation
      - *scaleX(x)* Defines a scale transformation by giving a value for
        the X-axis
      - *scaleY(y)* Defines a scale transformation by giving a value for
        the Y-axis
      - *scaleZ(z)* Defines a 3D scale transformation by giving a value
        for the Z-axis
      - *rotate(angle)* Defines a 2D rotation, the angle is specified in
        the parameter
      - *rotate3d(x,y,z,angle)* Defines a 3D rotation
      - *rotateX(angle)* Defines a 3D rotation along the X-axis
      - *rotateY(angle)* Defines a 3D rotation along the Y-axis
      - *rotateZ(angle)* Defines a 3D rotation along the Z-axis
      - *skew(x-angle,y-angle)* Defines a 2D skew transformation along
        the X- and the Y-axis
      - *skewX(angle)* Defines a 2D skew transformation along the X-axis
      - *skewY(angle)* Defines a 2D skew transformation along the Y-axis
      - *perspective(n)* Defines a perspective view for a 3D transformed
        element
  - *animation-name* Specifies the name of the keyframe you want to bind
    to the selector
  - *animation-duration* Specifies how many seconds or milliseconds an
    animation takes to complete
  - *animation-timing-function* Specifies the speed curve of the
    animation
  - *animation-delay* Specifies a delay before the animation will start
  - *animation-iteration-count* Specifies how many times an animation
    should be played
  - *animation-direction* Specifies whether or not the animation should
    play in reverse on alternate cycles
  - *animation-fill-mode* Specifies what values are applied by the
    animation outside the time it is executing
  - *animation-play-state* Specifies whether the animation is running or
    paused
  - *animation* Specifies shorthand for name duration timing-function
    delay iteration-count direction fill-mode play-state
  - *content* - is used with the :before and :after pseudo-elements, to
    insert generated content, can be:
      - *normal* Sets the content, if specified, to normal, which
        default is "none" (which is nothing)
      - *none* Sets the content, if specified, to nothing
      - *counter* Sets the content as a counter
      - *attr(attribute)* Sets the content as one of the selector's
        attribute
      - *string* Sets the content to the text you specify
      - *open-quote* Sets the content to be an opening quote
      - *close-quote* Sets the content to be a closing quote
      - *no-open-quote* Removes the opening quote from the content, if
        specified
      - *no-close-quote* Removes the closing quote from the content, if
        specified
      - *url(url)* Sets the content to be some kind of media (an image,
        a sound, a video, etc.)

For complete list of properties go to [CSS Properties
list](http://www.w3schools.com/cssref/)

### Size values

  - *absolute* in px, mm, cm, pt, etc...
  - *fluid* - relative to surrounding elements
      - *em* font size of the element
      - *ex* x-height of the element’s font
      - *ch* width of the "0" (ZERO, U+0030) glyph in the element’s font
      - *rem* font size of the root element
      - *vw* 1% of viewport’s width
      - *vh* 1% viewport’s height
      - *vmin* 1% of viewport’s smaller dimension
      - *vmax* 1% of viewport’s larger dimension
    
    [Browser support.](http://www.quirksmode.org/css/units-values/)

### Size ordering

when specifying border, padding, margin, etc

top right bottom left

top left-and-right bottom

top-and-bottom left-and-right

top-and-bottom-and-left-and-right

### Rule ordering

1.  *\!important* - A style that is designated as important will win out
    over contradictory styles of otherwise equal weight

2.  1.  Count the number of ID attributes in the selector.
    2.  Count the number of CLASS attributes in the selector.
    3.  Count the number of HTML tag names in the selector.
    
    Finally, write the three numbers in exact order with no spaces or
    commas to obtain a three digit number. (Note, you may need to
    convert the numbers to a larger base to end up with three digits.)
    The final list of numbers corresponding to selectors will easily
    determine specificity with the higher numbers winning out over lower
    numbers.

a:hover MUST come after a:link and a:visited and a:active MUST come
after a:hover in style sheet

### Media queries

Change css rules applied based on screen type, width/height,
orientation, etc....

    @media only screen and (max-width: 500px) {
        .gridmenu {
            width:100%;
        }
    }
    
    @media not|only mediatype and (media feature) {
        CSS-Code;
    }

or you can have different stylesheets for different media

``` 
<link rel="stylesheet" media="mediatype and|not|only (media feature)" href="mystylesheet.css">
                        
```

Media types are:

  - *all* Used for all media type devices
  - *print* Used for printers
  - *screen* Used for computer screens, tablets, smart-phones etc.
  - *speech* Used for screenreaders that "reads" the page out loud

Media queries are:

  - *aspect-ratio* The ratio between the width and the height of the
    viewport
  - *color* The number of bits per color component for the output device
  - *color-index* The number of colors the device can display
  - *device-aspect-ratio* The ratio between the width and the height of
    the device
  - *device-height* The height of the device, such as a computer screen
  - *device-width* The width of the device, such as a computer screen
  - *grid* Whether the device is a grid or bitmap
  - *height* The viewport height
  - *max-aspect-ratio* The maximum ratio between the width and the
    height of the display area
  - *max-color* The maximum number of bits per color component for the
    output device
  - *max-color-index* The maximum number of colors the device can
    display
  - *max-device-aspect-ratio* The maximum ratio between the width and
    the height of the device
  - *max-device-height* The maximum height of the device, such as a
    computer screen
  - *max-device-width* The maximum width of the device, such as a
    computer screen
  - *max-height* The maximum height of the display area, such as a
    browser window
  - *max-monochrome* The maximum number of bits per "color" on a
    monochrome (greyscale) device
  - *max-resolution* The maximum resolution of the device, using dpi or
    dpcm
  - *max-width* The maximum width of the display area, such as a browser
    window
  - *min-aspect-ratio* The minimum ratio between the width and the
    height of the display area
  - *min-color* The minimum number of bits per color component for the
    output device
  - *min-color-index* The minimum number of colors the device can
    display
  - *min-device-aspect-ratio* The minimum ratio between the width and
    the height of the device
  - *min-device-width* The minimum width of the device, such as a
    computer screen
  - *min-device-height* The minimum height of the device, such as a
    computer screen
  - *min-height* The minimum height of the display area, such as a
    browser window
  - *min-monochrome* The minimum number of bits per "color" on a
    monochrome (greyscale) device
  - *min-resolution* The minimum resolution of the device, using dpi or
    dpcm
  - *min-width* The minimum width of the display area, such as a browser
    window
  - *monochrome* The number of bits per "color" on a monochrome
    (greyscale) device
  - *orientation* The orientation of the viewport (landscape or portrait
    mode)
  - *overflow-block* How does the output device handle content that
    overflows the viewport along the block axis (added in Media Queries
    Level 4)
  - *overflow-inline* Can content that overflows the viewport along the
    inline axis be scrolled (added in Media Queries Level 4)
  - *resolution* The resolution of the output device, using dpi or dpcm
  - *scan* The scanning process of the output device
  - *update-frequency* How quickly can the output device modify the
    appearance of the content (added in Media Queries Level 4)
  - width The viewport width

For more complete list of possible queries [CSS3 @media
Rule](http://www.w3schools.com/cssref/css3_pr_mediaquery.asp)

Can be included by:

  - *directly* in CSS
  - *@import* in CSS
  - *HTML link* so different CSS is included byased on media attribute

Compiled by Tomy from various sources
