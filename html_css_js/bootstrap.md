# Bootstrap

<!-- toc -->

- [Resources](#resources)
- [General](#general)
  * [Getting started](#getting-started)
- [CSS Classes](#css-classes)
  * [Container classes](#container-classes)
  * [Grid classes](#grid-classes)
  * [Navigation classes](#navigation-classes)
  * [Button classes](#button-classes)
  * [Form classes](#form-classes)
  * [Table classes](#table-classes)
  * [Panel classes](#panel-classes)
  * [Well classes](#well-classes)
  * [Image classes](#image-classes)
  * [Media classes](#media-classes)
  * [Responsive embed](#responsive-embed)
  * [Alert classes](#alert-classes)
  * [Label classes](#label-classes)
  * [Progress bar classes](#progress-bar-classes)
  * [Styled tags](#styled-tags)
  * [Other classes](#other-classes)
- [Javascript components](#javascript-components)
  * [Toggable tabs](#toggable-tabs)
  * [Collapse / Accordion](#collapse--accordion)
  * [Scrollspy](#scrollspy)
  * [Affix](#affix)
  * [Tooltip](#tooltip)
  * [Popover](#popover)
  * [Modals](#modals)
  * [Carousel](#carousel)
  * [Checkbox / Radio](#checkbox--radio)

<!-- tocstop -->

## Resources

1.  [Bootstrap](http://getbootstrap.com/)
2.  [Bootstrap Typography](http://getbootstrap.com/css/#type)
3.  [ZURB Foundation](http://foundation.zurb.com/)
4.  [Semantic UI](http://semantic-ui.com/)
5.  [UI Kit](http://getuikit.com/)
6.  [Onseen UI](https://onsen.io/)
7.  [Comparison of popular UI toolkits](http://www.sitepoint.com/5-most-popular-frontend-frameworks-compared/)
8.  [Another Comparison of popular UI toolkits](http://usablica.github.io/front-end-frameworks/compare.html)
9.  [Social buttons for bootstrap](http://lipis.github.io/bootstrap-social/)
10. [Free bootstrap themes](https://bootswatch.com/)
11. [Premium paid bootstrap themes](https://wrapbootstrap.com/)
12. [Bootstrap Zero Free Themes](https://www.bootstrapzero.com/)
13. [Bootstrap - Free Bootstrap Themes & Templates](http://startbootstrap.com/)Start 
14. [List of Bootstrap 3 CSS classes with description](http://tomasjanecek.cz/en/clanky/post/list-of-bootstrap-3-css-classes-with-description)

## General

### Getting started

We can use cdns

``` 
<!-- Latest compiled and minified CSS -->
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/css/bootstrap.min.css">

<!-- Optional theme -->
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/css/bootstrap-theme.min.css">

<!-- Latest compiled and minified JavaScript -->
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/js/bootstrap.min.js"></script>                       
                        
```

or use downloaded version

``` 
<!-- Latest compiled and minified CSS -->
<link rel="stylesheet" href="bootstrap/css/bootstrap.min.css">

<!-- Optional theme -->
<link rel="stylesheet" href="bootstrap/css/bootstrap-theme.min.css">

<!-- Latest compiled and minified JavaScript -->
<script src="bootstrap/js/bootstrap.min.js"></script>                     
                        
```

Javascript files are usually placed at the end of body (so body is
rendered before those are downloaded and parsed).  
In addition jQuery needs to be included before bootstrap JS.

``` 
<script src="https://ajax.googleapis.com/ajax/libs/jquery/2.1.3/jquery.min.js"></script>                      
                        
```

To sum it all up:

``` 
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->
    <title>Bootstrap 101 Template</title>

    <!-- Bootstrap -->
    <link href="css/bootstrap.min.css" rel="stylesheet">

    <!-- HTML5 shim and Respond.js for IE8 support of HTML5 elements and media queries -->
    <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->
    <!--[if lt IE 9]>
      <script src="https://oss.maxcdn.com/html5shiv/3.7.2/html5shiv.min.js"></script>
      <script src="https://oss.maxcdn.com/respond/1.4.2/respond.min.js"></script>
    <![endif]-->
  </head>
  <body>
    <h1>Hello, world!</h1>

    <!-- jQuery (necessary for Bootstrap's JavaScript plugins) -->
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.3/jquery.min.js"></script>
    <!-- Include all compiled plugins (below), or include individual files as needed -->
    <script src="js/bootstrap.min.js"></script>
  </body>
</html>
                        
```

## CSS Classes

### Container classes

To be places at the topmost div. Give slight padding, auto margin. Must
be here\!\!\!

  - *container* - fixed width (based on screen width media queries)
  - *container-fluid* - maximum width

### Grid classes

Bootstrap grid have 12 columns\!\!\! If more than 12 columns are placed
within a single row, each group of extra columns will, as one unit, wrap
onto a new line\!

  - *row* - to denote row
  - *col-size-cnt* to denote columns where:
      - *cnt* - how many of 12 columns to occupy
      - *size* can be:
          - *xs* - Extra small devices Phones (\<768px)
          - *sm* - Small devices Tablets (\>=768px)
          - *md* - Medium devices Desktops (\>=992px)
          - *large* - Large devices Desktops (\>=1200px)
  - *col-size-push-cnt* - change the order of built-in grid columns
  - *col-size-pull-cnt* - change the order of built-in grid columns
  - *col-size-offset-cnt* - increase the left margin of a column by \*
    columns
  - *hidden-size* - hide for certain size
  - *visible-size-display* - visible for certain size and
    display(inline, block, inline-block)

To nest content with the default grid, add a new .row and set of
.col-sm-\* columns within an existing .col-sm-\* column.

[Bootstrap grid system](http://getbootstrap.com/css/#grid)

[The Subtle Magic Behind Why the Bootstrap 3 Grid
Works](http://www.helloerik.com/the-subtle-magic-behind-why-the-bootstrap-3-grid-works)

### Navigation classes

  - *navbar*
  - *navbar-default*
  - *navbar-fixed-top*
  - *navbar-fixed-bottom*
  - *navbar-static-top*
  - *navbar-inverse*
  - *nav*
  - *nav-tabs*
  - *nav-pills*
  - *nav-justified*
  - *navbar-nav*
  - *navbar-btn*
  - *navbar-text*
  - *navbar-link*
  - *active*
  - *disabled*
  - *navbar-header*
  - *navbar-right*
  - *navbar-left*
  - *navbar-colapse*
  - *navbar-toggle*
  - *breadcrumb*

[Bootstrap navbar](http://getbootstrap.com/components/#navbar)

[Bootstrap breadcrumbs](http://getbootstrap.com/components/#breadcrumbs)

``` 
    <nav class="navbar navbar-inverse navbar-fixed-top" role="navigation">
        <div class="container">
            <!-- start collapsed navbar-->
            <div class="navbar-header">
                <button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#navbar" aria-expanded="false" aria-controls="navbar">
                    <span class="sr-only">Toggle navigation</span>
                    <span class="icon-bar"></span>
                    <span class="icon-bar"></span>
                    <span class="icon-bar"></span>
                </button>
                <a class="navbar-brand" href="index.html">Ristorante Con Fusion</a>
            </div>
            <!-- / collapsed navbar-->

            <!-- start un-collapsed navbar-->
            <div id="navbar" class="navbar-collapse collapse">
                <ul class="nav navbar-nav">
                    <li><a href="index.html"><span class="glyphicon glyphicon-home"
                         aria-hidden="true"></span> Home</a></li>
                    <li class="active"><a href="aboutus.html"><span class="glyphicon glyphicon-info-sign"
                         aria-hidden="true"></span> About</a></li>
                    <li class="dropdown">
                        <a href="#" class="dropdown-toggle" data-toggle="dropdown"
                         role="button" aria-haspopup="true" aria-expanded="false">
                         Menu <span class="caret"></span></a>
                        <ul class="dropdown-menu">
                            <li><a href="#">Appetizers</a></li>
                            <li><a href="#">Main Courses</a></li>
                            <li><a href="#">Desserts</a></li>
                            <li><a href="#">Drinks</a></li>
                            <li role="separator" class="divider"></li>
                            <li class="dropdown-header">Specials</li>
                            <li><a href="#">Lunch Buffet</a></li>
                            <li><a href="#">Weekend Brunch</a></li>
                        </ul>
                    </li>
                    <li><a href="#">Contact</a></li>
                </ul>
            </div>
            <!-- / un-collapsed navbar-->
        </div>
    </nav>  
                        
```

``` 
    <ul class="breadcrumb">
        <li><a href="index.html">Home</a></li>
        <li>About Us</li>
    </ul>
                        
```

### Button classes

  - *btn* Adds basic styling to any button
  - *btn-default* Indicates a default/standard button
  - *btn-primary* Provides extra visual weight and identifies the
    primary action in a set of buttons
  - *btn-success* Indicates a successful or positive action
  - *btn-info* Contextual button for informational alert messages
  - *btn-warning* Indicates caution should be taken with this action
  - *btn-danger* Indicates a dangerous or potentially negative action
  - *btn-link* Makes a button look like a link (will still have button
    behavior)
  - *btn-lg* Makes a large button
  - *btn-sm* Makes a small button
  - *btn-xs* Makes an extra small button
  - *btn-block* Makes a block-level button (spans the full width of the
    parent element)
  - *active* Makes the button appear pressed
  - *disabled* Makes the button disabled
  - *navbar-btn*
  - *btn-group* to create a button group
  - *btn-group-size* instead of applying button sizing classes to every
    button
  - *btn-group-vertical* to create a vertical button group
  - *btn-group-justified* to span the entire width of the screen
  - *btn-toolbar* - Combine sets of btn-group btn-toolbar for more
    complex components

Nest button groups to create dropdown menus

``` 
<div class="btn-group">
  <button type="button" class="btn btn-primary">Apple</button>
  <button type="button" class="btn btn-primary">Samsung</button>
  <div class="btn-group">
    <button type="button" class="btn btn-primary dropdown-toggle" data-toggle="dropdown">
    Sony <span class="caret"></span></button>
    <ul class="dropdown-menu" role="menu">
      <li><a href="#">Tablet</a></li>
      <li><a href="#">Smartphone</a></li>
    </ul>
  </div>
</div>                            
                            
```

Split Button Dropdowns

``` 
<div class="btn-group">
  <button type="button" class="btn btn-primary">Sony</button>
  <button type="button" class="btn btn-primary dropdown-toggle" data-toggle="dropdown">
    <span class="caret"></span>
  </button>
  <ul class="dropdown-menu" role="menu">
    <li><a href="#">Tablet</a></li>
    <li><a href="#">Smartphone</a></li>
  </ul>
</div>                            
                            
```

More info at [Bootstrap buttons
page](http://getbootstrap.com/css/#buttons) or [Bootstrap button groups
page](http://getbootstrap.com/components/#btn-groups)

### Form classes

Always use form role="form" (helps improve accessibility for people
using screen readers)

Wrap labels and form controls in div class="form-group" (needed for
optimum spacing)

Add class form-control to all textual input, textarea, and select
elements

All textual input, textarea, and select elements with class form-control
have a width of 100%.

  - *form-inline* - all of the elements are inline, left-aligned, and
    the labels are alongside. Note: This only applies to forms within
    viewports that are at least 768px wide\!
  - *form-horizontal* - stands apart from the other forms both in the
    amount of markup, and in the presentation of the form  
    Add class control-label to all label elements\!\!\!  
    Use Bootstrap's predefined grid classes to align labels and groups
    of form controls in a horizontal layout.
  - *control-label*
  - *checkbox* element containing checkboxes
  - *radio* element containing radio
  - *input-group*
  - *input-group-size* instead of applying button sizing classes to
    every input
  - *input-group-addon* prepend or append elements to a form-control
    place your extra content inside a
  - *input-group-btn* preappend or append buttons in input groups
    instead of input-group-addon (cam even have dropdown/segmented
    buttons), can have multiple buttons
  - *navbar-form* form inside a navbar
  - *has-warning* coloring form items orange
  - *has-error* coloring form items red
  - *has-sucess* coloring form items green
  - *has-feedback* adding feedback icon
  - *form-control-feedback* adding feedback icon
  - *input-lg* large input size
  - *input-sm* small input size
  - *form-group* wrap labels and controls in .form-group for optimum
    spacing
  - *form-group-sm* small input size
  - *form-group-lg* small input size

<!-- end list -->

``` 
<div class="form-group has-success has-feedback">
  <label class="control-label" for="inputSuccess2">Input with success</label>
  <input type="text" class="form-control" id="inputSuccess2" aria-describedby="inputSuccess2Status">
  <span class="glyphicon glyphicon-ok form-control-feedback" aria-hidden="true"></span>
  <span id="inputSuccess2Status" class="sr-only">(success)</span>
</div>
<div class="form-group has-warning has-feedback">
  <label class="control-label" for="inputWarning2">Input with warning</label>
  <input type="text" class="form-control" id="inputWarning2" aria-describedby="inputWarning2Status">
  <span class="glyphicon glyphicon-warning-sign form-control-feedback" aria-hidden="true"></span>
  <span id="inputWarning2Status" class="sr-only">(warning)</span>
</div>
<div class="form-group has-error has-feedback">
  <label class="control-label" for="inputError2">Input with error</label>
  <input type="text" class="form-control" id="inputError2" aria-describedby="inputError2Status">
  <span class="glyphicon glyphicon-remove form-control-feedback" aria-hidden="true"></span>
  <span id="inputError2Status" class="sr-only">(error)</span>
</div>
<div class="form-group has-success has-feedback">
  <label class="control-label" for="inputGroupSuccess1">Input group with success</label>
  <div class="input-group">
    <span class="input-group-addon">@</span>
    <input type="text" class="form-control" id="inputGroupSuccess1" aria-describedby="inputGroupSuccess1Status">
  </div>
  <span class="glyphicon glyphicon-ok form-control-feedback" aria-hidden="true"></span>
  <span id="inputGroupSuccess1Status" class="sr-only">(success)</span>
</div>
                        
```

``` 
<form class="form-horizontal">
  <div class="form-group has-success has-feedback">
    <label class="control-label col-sm-3" for="inputSuccess3">Input with success</label>
    <div class="col-sm-9">
      <input type="text" class="form-control" id="inputSuccess3" aria-describedby="inputSuccess3Status">
      <span class="glyphicon glyphicon-ok form-control-feedback" aria-hidden="true"></span>
      <span id="inputSuccess3Status" class="sr-only">(success)</span>
    </div>
  </div>
  <div class="form-group has-success has-feedback">
    <label class="control-label col-sm-3" for="inputGroupSuccess2">Input group with success</label>
    <div class="col-sm-9">
      <div class="input-group">
        <span class="input-group-addon">@</span>
        <input type="text" class="form-control" id="inputGroupSuccess2" aria-describedby="inputGroupSuccess2Status">
      </div>
      <span class="glyphicon glyphicon-ok form-control-feedback" aria-hidden="true"></span>
      <span id="inputGroupSuccess2Status" class="sr-only">(success)</span>
    </div>
  </div>
</form>
                        
```

More info at [Bootstrap forms page](http://getbootstrap.com/css/#forms)

More info at [Bootstrap navbar forms
page](http://getbootstrap.com/components/#navbar-forms)

More info at [Bootstrap forms control
page](http://getbootstrap.com/css/#forms-control-validation)

### Table classes

  - *table* Adds basic styling (light padding and only horizontal
    dividers) to any table
  - *table-striped* Adds zebra-striping to any table row within tbody
    (not available in IE8)
  - *table-bordered* Adds border on all sides of the table and cells
  - *table-hover* Enables a hover state on table rows within a tbody
  - *table-condensed* Makes table more compact by cutting cell padding
    in half
  - *table-responsive* enclosing div class creates a responsive table.
    The table will then scroll horizontally on small devices (under
    768px). When viewing on anything larger than 768px wide, there is no
    difference
  - *active* Applies the hover color to a particular row or cell
  - *success* Indicates a successful or positive action
  - *info* Indicates a neutral informative change or action
  - *warning* Indicates a warning that might need attention
  - *danger* Indicates a dangerous or potentially negative action

More info at [Bootstrap tables
page](http://getbootstrap.com/css/#tables)

### Panel classes

Panel is content displayed in a bounded box.

  - *panel* outer div of panel
  - *panel-body* inner body div of panel
  - *panel-heading* inner heading div of panel
  - *panel-title* hx class for title inside heading div of panel
  - *panel-footer* inner footer div of panel
  - *panel-group* group several panel divs
  - *panel-default, panel-primary, panel-success, panel-info,
    panel-warning, panel-danger* contextual coloring classes

More info at [Bootstrap panels
page](http://getbootstrap.com/components/#panels)

### Well classes

Well rounded border around an element with a gray background color and
some padding.

  - *well* outer div of well
  - *well-size* well of different size (lg, sm)

More info at [Bootstrap wells
page](http://getbootstrap.com/components/#wells)

### Image classes

  - *img-rounded* Adds rounded corners to an image (not available in
    IE8)
  - *img-circle* Shapes the image to a circle (not available in IE8)
  - *img-thumbnail* Shapes the image to a thumbnail (border)
  - *img-responsive* Makes an image responsive (will scale nicely to the
    parent element)

<!-- end list -->

``` 
<div class="thumbnail"> 
    <a href="#"><img class=“img-thumbnail"  src="img/alberto.png" alt="Alberto Somayya"></a> 
    <div class="caption"> 
        <h2>Alberto Somayya</h2> 
        <h4>ExecuRve Chef</h4> 
        <p>Award winning three-star Michelin chef with wide 
         InternaRonal experience having worked closely with whos-who in the culinary world, he specializes in  
         creaRng mouthwatering Indo-Italian fusion experiences.  
        </p> 
        <p><a class="btn btn -primary btn-xs" href="#">More &raquo;</a></p> 
    </div> 
</div> 
                        
```

More info at [Bootstrap images
page](http://getbootstrap.com/css/#images)

More info at [Bootstrap thumbnails
page](http://getbootstrap.com/components/#thumbnails)

### Media classes

Used for building various types of components (like blog comments,
Tweets, etc) that feature a left- or right-aligned image alongside
textual content

  - *media* outter div for media
  - *media-left* div left of main media div
  - *media-body* main media div
  - *media-right*div right of main media div
  - *media-object* main "object" with media inside those divs
  - *media-heading* heading class for media description
  - *media-middle* media vertical alignment middle
  - *media-bottom* media vertical alignment bottom
  - *media-list* for media inside list styling

More info at [Bootstrap media
page](http://getbootstrap.com/components/#media)

### Responsive embed

Allow browsers to determine video or slideshow dimensions based on the
width of their containing block by creating an intrinsic ratio that will
properly scale on any device.

  - *embed-responsive*
  - *embed-responsive-item*
  - *embed-responsive-item-16by9*
  - *embed-responsive-item-4by3*

More info at [Bootstrap responsive embed
page](http://getbootstrap.com/components/#responsive-embed)

### Alert classes

Wrap any text and an optional dismiss button in .alert and one of the
four contextual classes (e.g., .alert-success) for basic alert messages.

  - *alert*
  - *alert-success*
  - *alert-info*
  - *alert-warning*
  - *alert-danger*
  - *alert-dismissible* dismissable alert (JS)
  - *alert-link* correctly color links inside alerts

More info at [Bootstrap alerts
page](http://getbootstrap.com/components/#alerts)

### Label classes

Labels are used to provide additional information about something

  - *label*
  - *label-default*
  - *label-primary*
  - *label-success*
  - *label-info*
  - *label-warning*
  - *label-danger*

More info at [Bootstrap labels
page](http://getbootstrap.com/components/#labels)

### Progress bar classes

Flexible progress bar styling

  - *progress, progress-bar, progress-bar-success, progress-bar-info,
    progress-bar-warning, progress-bar-danger, progress-bar-stripped,
    active*

<!-- end list -->

``` 
<div class="progress"> 
    <div class="progress-bar progress-bar-danger progress-bar-striped"  role="progressbar" aria-valuenow="80" aria-valuemin="0” aria-valuemax="100" style="width: 80%"> 
        <span class="sr-only">80% Complete (danger)</span> 80% 
    </div> 
</div> 
                        
```

More info at [Bootstrap progress bar
page](http://getbootstrap.com/components/#progress)

### Styled tags

  - *abbr* - for abbreviations and acronyms to show the expanded version on hover, abbreviations with a title attribute have a light dotted bottom border and a help cursor on hover 
  - *address*
  - *blockquote* - add *footer* for identifying the source, wrap the name of the source work in *cite*
  - *dl, dt*
  - *code*
  - *kbd*
  - *pre*
  - *var*
  - *samp*

### Other classes

  - *pull-left* Floats an element to the left
  - *pull-right* Floats an element to the right
  - *center-block* Sets an element to display:block and center
  - *clearfix* Clears floats
  - *show* Forces an element to be shown
  - *hidden* Forces an element to be hidden
  - *fade*
  - *sr-only* Hides an element to all devices except screen readers
  - *sr-only-focusable* Combine with .sr-only to show the element again when it is focused (e.g. by a keyboard-only user)
  - *text-hide* Helps replace an element's text content with a background image
  - *close* Indicates a close icon
  - *caret* Indicates dropdown functionality (will reverse automatically in dropup menus)
  - *bg-primary* Table cell is styled with class bg-primary
  - *bg-success* Table cell is styled with class bg-success
  - *bg-info* Table cell is styled with class bg-info
  - *bg-warning* Table cell is styled with class bg-warning
  - *bg-danger* Table cell is styled with class bg-danger
  - *text-muted* Text styled with class text-muted
  - *text-primary* Text styled with class text-primary
  - *text-success* Text styled with class text-success
  - *text-info* Text styled with class text-info
  - *text-warning* Text styled with class text-warning
  - *text-danger* Text styled with class text-danger
  - *list-unstyled* - list without the bullets
  - *colapse*
  - *colapseed*
  - *icon-bar*
  - *dropdown*
  - *dropdown-menu*
  - *separator*
  - *btn-social-icon*
  - *btn-google-plus*
  - *btn-facebook*
  - *btn-linkedin*
  - *btn-twitter*
  - *btn-youtube*
  - *dl-horizontal* horizontal description list (term and definition in one line), stacked display on narrow widths, truncate if definition too long
  - *text-left, text-center, text-right, text-justify, text-nowrap* text alignment
  - *text-lowercase, text-uppercase, text-capitalize* text transformations
  - *blockquote-reverse* for a blockquote with right-aligned content
  - *list-unstyled* remove the default list-style and left margin on list items (immediate children only).
  - *list-inline* place all list items on a single line with display: inline-block; and some light padding
  - *pre-scrollable* set a max-height of 350px and provide a y-axis scrollbar
  - *thumbnail* div surrounding image with a caption
  - *caption* div inside thumbnail div with caption text inside
  - *list-group*
  - *list-group-item*
  - *list-group-item-heading*
  - *list-group-item-text*

*badge* [badges](http://getbootstrap.com/components/#badges)

## Javascript components

### Toggable tabs

Add quick, dynamic tab functionality to transition through panes of
local content, even via dropdown menus. Nested tabs are not supported.

``` 
$('#myTabs a').click(function (e) {
  e.preventDefault()
  $(this).tab('show')
})                      
```

Also can use html attributes to activate, data-toggle=tab or
data-toggle=pill on an element. Adding the nav and nav-tabs classes to
the tab ul will apply the Bootstrap tab styling, while adding the nav
and nav-pills classes will apply pill styling.

``` 
<div>

  <!-- Nav tabs -->
  <ul class="nav nav-tabs" role="tablist">
    <li role="presentation" class="active"><a href="#home" aria-controls="home" role="tab" data-toggle="tab">Home</a></li>
    <li role="presentation"><a href="#profile" aria-controls="profile" role="tab" data-toggle="tab">Profile</a></li>
    <li role="presentation"><a href="#messages" aria-controls="messages" role="tab" data-toggle="tab">Messages</a></li>
    <li role="presentation"><a href="#settings" aria-controls="settings" role="tab" data-toggle="tab">Settings</a></li>
  </ul>

  <!-- Tab panes -->
  <div class="tab-content">
    <div role="tabpanel" class="tab-pane active" id="home">...</div>
    <div role="tabpanel" class="tab-pane" id="profile">...</div>
    <div role="tabpanel" class="tab-pane" id="messages">...</div>
    <div role="tabpanel" class="tab-pane" id="settings">...</div>
  </div>                        
```

More [Bootstrap tabs page](http://getbootstrap.com/javascript/#tabs)

### Collapse / Accordion

Flexible plugin that utilizes a handful of classes for easy toggle
behavior.

  - *collapse* class hides content
  - *collapsing* is applied during transitions
  - *collapse.in* shows content

You can use a link with the href attribute, or a button with the
data-target attribute. In both cases, the data-toggle=collapse is
required.

``` 
<a class="btn btn-primary" role="button" data-toggle="collapse" href="#collapseExample" aria-expanded="false" aria-controls="collapseExample">
  Link with href
</a>
<button class="btn btn-primary" type="button" data-toggle="collapse" data-target="#collapseExample" aria-expanded="false" aria-controls="collapseExample">
  Button with data-target
</button>
<div class="collapse" id="collapseExample">
  <div class="well">
    ...
  </div>
</div>                        
                        
```

Extend the default collapse behavior to create an accordion with the
panel component, data-parent is used here.

``` 
<div class="panel-group" id="accordion" role="tablist" aria-multiselectable="true">
  <div class="panel panel-default">
    <div class="panel-heading" role="tab" id="headingOne">
      <h4 class="panel-title">
        <a role="button" data-toggle="collapse" data-parent="#accordion" href="#collapseOne" aria-expanded="true" aria-controls="collapseOne">
          Collapsible Group Item #1
        </a>
      </h4>
    </div>
    <div id="collapseOne" class="panel-collapse collapse in" role="tabpanel" aria-labelledby="headingOne">
      <div class="panel-body">
        Anim pariatur cliche reprehenderit, enim eiusmod high life accusamus terry richardson ad squid. 3 wolf moon officia aute, non cupidatat skateboard dolor brunch. Food truck quinoa nesciunt laborum eiusmod. Brunch 3 wolf moon tempor, sunt aliqua put a bird on it squid single-origin coffee nulla assumenda shoreditch et. Nihil anim keffiyeh helvetica, craft beer labore wes anderson cred nesciunt sapiente ea proident. Ad vegan excepteur butcher vice lomo. Leggings occaecat craft beer farm-to-table, raw denim aesthetic synth nesciunt you probably haven't heard of them accusamus labore sustainable VHS.
      </div>
    </div>
  </div>
  <div class="panel panel-default">
    <div class="panel-heading" role="tab" id="headingTwo">
      <h4 class="panel-title">
        <a class="collapsed" role="button" data-toggle="collapse" data-parent="#accordion" href="#collapseTwo" aria-expanded="false" aria-controls="collapseTwo">
          Collapsible Group Item #2
        </a>
      </h4>
    </div>
    <div id="collapseTwo" class="panel-collapse collapse" role="tabpanel" aria-labelledby="headingTwo">
      <div class="panel-body">
        Anim pariatur cliche reprehenderit, enim eiusmod high life accusamus terry richardson ad squid. 3 wolf moon officia aute, non cupidatat skateboard dolor brunch. Food truck quinoa nesciunt laborum eiusmod. Brunch 3 wolf moon tempor, sunt aliqua put a bird on it squid single-origin coffee nulla assumenda shoreditch et. Nihil anim keffiyeh helvetica, craft beer labore wes anderson cred nesciunt sapiente ea proident. Ad vegan excepteur butcher vice lomo. Leggings occaecat craft beer farm-to-table, raw denim aesthetic synth nesciunt you probably haven't heard of them accusamus labore sustainable VHS.
      </div>
    </div>
  </div>
  <div class="panel panel-default">
    <div class="panel-heading" role="tab" id="headingThree">
      <h4 class="panel-title">
        <a class="collapsed" role="button" data-toggle="collapse" data-parent="#accordion" href="#collapseThree" aria-expanded="false" aria-controls="collapseThree">
          Collapsible Group Item #3
        </a>
      </h4>
    </div>
    <div id="collapseThree" class="panel-collapse collapse" role="tabpanel" aria-labelledby="headingThree">
      <div class="panel-body">
        Anim pariatur cliche reprehenderit, enim eiusmod high life accusamus terry richardson ad squid. 3 wolf moon officia aute, non cupidatat skateboard dolor brunch. Food truck quinoa nesciunt laborum eiusmod. Brunch 3 wolf moon tempor, sunt aliqua put a bird on it squid single-origin coffee nulla assumenda shoreditch et. Nihil anim keffiyeh helvetica, craft beer labore wes anderson cred nesciunt sapiente ea proident. Ad vegan excepteur butcher vice lomo. Leggings occaecat craft beer farm-to-table, raw denim aesthetic synth nesciunt you probably haven't heard of them accusamus labore sustainable VHS.
      </div>
    </div>
  </div>
</div>
                        
```

More [Bootstrap colapse
page](http://getbootstrap.com/javascript/#collapse)

### Scrollspy

The ScrollSpy plugin is for automatically updating nav targets based on
scroll position. Scroll the area below the navbar and watch the active
class change. The dropdown sub items will be highlighted as well.

To easily add scrollspy behavior to your topbar navigation, add
data-spy=scroll to the element you want to spy on (most typically this
would be the body). Then add the data-target attribute with the ID or
class of the parent element of any Bootstrap .nav component.

``` 
<div class="bs-example" data-example-id="embedded-scrollspy">
    <nav id="navbar-example2" class="navbar navbar-default navbar-static">
      <div class="container-fluid">
        <div class="navbar-header">
          <button class="navbar-toggle collapsed" type="button" data-toggle="collapse" data-target=".bs-example-js-navbar-scrollspy">
            <span class="sr-only">Toggle navigation</span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
          </button>
          <a class="navbar-brand" href="#">Project Name</a>
        </div>
        <div class="collapse navbar-collapse bs-example-js-navbar-scrollspy">
          <ul class="nav navbar-nav">
            <li class=""><a href="#fat">@fat</a></li>
            <li class=""><a href="#mdo">@mdo</a></li>
            <li class="dropdown active">
              <a href="#" id="navbarDrop1" class="dropdown-toggle" data-toggle="dropdown" role="button" aria-haspopup="true" aria-expanded="false">Dropdown <span class="caret"></span></a>
              <ul class="dropdown-menu" aria-labelledby="navbarDrop1">
                <li class=""><a href="#one">one</a></li>
                <li class=""><a href="#two">two</a></li>
                <li role="separator" class="divider"></li>
                <li class="active"><a href="#three">three</a></li>
              </ul>
            </li>
          </ul>
        </div>
      </div>
    </nav>
    <div data-spy="scroll" data-target="#navbar-example2" data-offset="0" class="scrollspy-example">
      <h4 id="fat">@fat</h4>
      <p>Ad leggings keytar, brunch id art party dolor labore. Pitchfork yr enim lo-fi before they sold out qui. Tumblr farm-to-table bicycle rights whatever. Anim keffiyeh carles cardigan. Velit seitan mcsweeney's photo booth 3 wolf moon irure. Cosby sweater lomo jean shorts, williamsburg hoodie minim qui you probably haven't heard of them et cardigan trust fund culpa biodiesel wes anderson aesthetic. Nihil tattooed accusamus, cred irony biodiesel keffiyeh artisan ullamco consequat.</p>
      <h4 id="mdo">@mdo</h4>
      <p>Veniam marfa mustache skateboard, adipisicing fugiat velit pitchfork beard. Freegan beard aliqua cupidatat mcsweeney's vero. Cupidatat four loko nisi, ea helvetica nulla carles. Tattooed cosby sweater food truck, mcsweeney's quis non freegan vinyl. Lo-fi wes anderson +1 sartorial. Carles non aesthetic exercitation quis gentrify. Brooklyn adipisicing craft beer vice keytar deserunt.</p>
      <h4 id="one">one</h4>
      <p>Occaecat commodo aliqua delectus. Fap craft beer deserunt skateboard ea. Lomo bicycle rights adipisicing banh mi, velit ea sunt next level locavore single-origin coffee in magna veniam. High life id vinyl, echo park consequat quis aliquip banh mi pitchfork. Vero VHS est adipisicing. Consectetur nisi DIY minim messenger bag. Cred ex in, sustainable delectus consectetur fanny pack iphone.</p>
      <h4 id="two">two</h4>
      <p>In incididunt echo park, officia deserunt mcsweeney's proident master cleanse thundercats sapiente veniam. Excepteur VHS elit, proident shoreditch +1 biodiesel laborum craft beer. Single-origin coffee wayfarers irure four loko, cupidatat terry richardson master cleanse. Assumenda you probably haven't heard of them art party fanny pack, tattooed nulla cardigan tempor ad. Proident wolf nesciunt sartorial keffiyeh eu banh mi sustainable. Elit wolf voluptate, lo-fi ea portland before they sold out four loko. Locavore enim nostrud mlkshk brooklyn nesciunt.</p>
      <h4 id="three">three</h4>
      <p>Ad leggings keytar, brunch id art party dolor labore. Pitchfork yr enim lo-fi before they sold out qui. Tumblr farm-to-table bicycle rights whatever. Anim keffiyeh carles cardigan. Velit seitan mcsweeney's photo booth 3 wolf moon irure. Cosby sweater lomo jean shorts, williamsburg hoodie minim qui you probably haven't heard of them et cardigan trust fund culpa biodiesel wes anderson aesthetic. Nihil tattooed accusamus, cred irony biodiesel keffiyeh artisan ullamco consequat.</p>
      <p>Keytar twee blog, culpa messenger bag marfa whatever delectus food truck. Sapiente synth id assumenda. Locavore sed helvetica cliche irony, thundercats you probably haven't heard of them consequat hoodie gluten-free lo-fi fap aliquip. Labore elit placeat before they sold out, terry richardson proident brunch nesciunt quis cosby sweater pariatur keffiyeh ut helvetica artisan. Cardigan craft beer seitan readymade velit. VHS chambray laboris tempor veniam. Anim mollit minim commodo ullamco thundercats.
      </p>
    </div>
  </div>                      
```

More [Bootstrap scrollspy
page](http://getbootstrap.com/javascript/#scrollspy)

### Affix

The affix plugin toggles position: fixed; on and off, emulating the
effect found with position: sticky;. The subnavigation on the right is a
live demo of the affix plugin.

The affix plugin toggles between three classes, each representing a
particular state: .affix, .affix-top, and .affix-bottom. You must
provide the styles, with the exception of position: fixed; on .affix,
for these classes yourself (independent of this plugin) to handle the
actual positions.

To easily add affix behavior to any element, just add data-spy="affix"
to the element you want to spy on. Use offsets to define when to toggle
the pinning of an element.

``` 
<div data-spy="affix" data-offset-top="60" data-offset-bottom="200">
  ...
</div>
                        
```

More [Bootstrap affix page](http://getbootstrap.com/javascript/#affix)

### Tooltip

data-toggle=tooltip data-placement=left|right|top|bottom and title=text
attributes need to be placed.

``` 
<button type="button" class="btn btn-default" data-toggle="tooltip" data-placement="left" title="Tooltip on left">Tooltip on left</button>
<button type="button" class="btn btn-default" data-toggle="tooltip" data-placement="top" title="Tooltip on top">Tooltip on top</button>
<button type="button" class="btn btn-default" data-toggle="tooltip" data-placement="bottom" title="Tooltip on bottom">Tooltip on bottom</button>
<button type="button" class="btn btn-default" data-toggle="tooltip" data-placement="right" title="Tooltip on right">Tooltip on right</button>
                        
```

Must be initialized manually (opt in)

``` 
$(function () {
  $('[data-toggle="tooltip"]').tooltip()
})
                        
```

More [Bootstrap tooltips
page](http://getbootstrap.com/javascript/#tooltips)

### Popover

Add small overlays of content, like those on the iPad, to any element
for housing secondary information.

data-toggle=popover data-placement=left|right|top|bottom, title=text and
data-content=text attributes need to be placed.

``` 
<button type="button" class="btn btn-default" data-container="body" data-toggle="popover" data-placement="left" data-content="Vivamus sagittis lacus vel augue laoreet rutrum faucibus.">
  Popover on left
</button>

<button type="button" class="btn btn-default" data-container="body" data-toggle="popover" data-placement="top" data-content="Vivamus sagittis lacus vel augue laoreet rutrum faucibus.">
  Popover on top
</button>

<button type="button" class="btn btn-default" data-container="body" data-toggle="popover" data-placement="bottom" data-content="Vivamus
sagittis lacus vel augue laoreet rutrum faucibus.">
  Popover on bottom
</button>

<button type="button" class="btn btn-default" data-container="body" data-toggle="popover" data-placement="right" data-content="Vivamus sagittis lacus vel augue laoreet rutrum faucibus.">
  Popover on right
</button>
                        
```

Must be initialized manually (opt in)

``` 
$(function () {
  $('[data-toggle="popover"]').popover()
})
                        
```

Use tabindex=0, a tag with role=button and data-trigger=focus to dismiss
on next click (and not on next click of same button).

More [Bootstrap popover
page](http://getbootstrap.com/javascript/#popovers)

### Modals

Modals are streamlined, but flexible, dialog prompts with the minimum
required functionality and smart defaults.

data-toggle=modal on button along with data-target or href, class=modal
on div, etc.....

``` 
<div style="display: none;" id="myModal" class="modal fade" tabindex="-1" role="dialog" aria-labelledby="myModalLabel">
    <div class="modal-dialog" role="document">
      <div class="modal-content">

        <div class="modal-header">
          <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">×</span></button>
          <h4 class="modal-title" id="myModalLabel">Modal title</h4>
        </div>
        <div class="modal-body">
          <h4>Text in a modal</h4>
          <p>Duis mollis, est non commodo luctus, nisi erat porttitor ligula.</p>

          <h4>Popover in a modal</h4>
          <p>This <a data-original-title="A Title" href="#" role="button" class="btn btn-default popover-test" title="" data-content="And here's some amazing content. It's very engaging. right?">button</a> should trigger a popover on click.</p>

          <h4>Tooltips in a modal</h4>
          <p><a data-original-title="Tooltip" href="#" class="tooltip-test" title="">This link</a> and <a data-original-title="Tooltip" href="#" class="tooltip-test" title="">that link</a> should have tooltips on hover.</p>

          <hr>

          <h4>Overflowing text to show scroll behavior</h4>
          <p>Cras mattis consectetur purus sit amet fermentum. Cras justo odio, dapibus ac facilisis in, egestas eget quam. Morbi leo risus, porta ac consectetur ac, vestibulum at eros.</p>
          <p>Praesent commodo cursus magna, vel scelerisque nisl consectetur et. Vivamus sagittis lacus vel augue laoreet rutrum faucibus dolor auctor.</p>
          <p>Aenean lacinia bibendum nulla sed consectetur. Praesent commodo cursus magna, vel scelerisque nisl consectetur et. Donec sed odio dui. Donec ullamcorper nulla non metus auctor fringilla.</p>
          <p>Cras mattis consectetur purus sit amet fermentum. Cras justo odio, dapibus ac facilisis in, egestas eget quam. Morbi leo risus, porta ac consectetur ac, vestibulum at eros.</p>
          <p>Praesent commodo cursus magna, vel scelerisque nisl consectetur et. Vivamus sagittis lacus vel augue laoreet rutrum faucibus dolor auctor.</p>
          <p>Aenean lacinia bibendum nulla sed consectetur. Praesent commodo cursus magna, vel scelerisque nisl consectetur et. Donec sed odio dui. Donec ullamcorper nulla non metus auctor fringilla.</p>
          <p>Cras mattis consectetur purus sit amet fermentum. Cras justo odio, dapibus ac facilisis in, egestas eget quam. Morbi leo risus, porta ac consectetur ac, vestibulum at eros.</p>
          <p>Praesent commodo cursus magna, vel scelerisque nisl consectetur et. Vivamus sagittis lacus vel augue laoreet rutrum faucibus dolor auctor.</p>
          <p>Aenean lacinia bibendum nulla sed consectetur. Praesent commodo cursus magna, vel scelerisque nisl consectetur et. Donec sed odio dui. Donec ullamcorper nulla non metus auctor fringilla.</p>
        </div>
        <div class="modal-footer">
          <button type="button" class="btn btn-default" data-dismiss="modal">Close</button>
          <button type="button" class="btn btn-primary">Save changes</button>
              </div><!-- /.modal-content -->
    </div><!-- /.modal-dialog -->
  </div>
<div class="bs-example bs-example-padded-bottom">
    <button type="button" class="btn btn-primary btn-lg" data-toggle="modal" data-target="#myModal">
      Launch demo modal
    </button>
  </div>
                        
```

More [Bootstrap modals page](http://getbootstrap.com/javascript/#modals)

### Carousel

A slideshow component for cycling through elements, like a carousel.
Nested carousels are not supported.

Use data attributes to easily control the position of the carousel.
data-slide accepts the keywords prev or next, which alters the slide
position relative to its current position. Alternatively, use
data-slide-to to pass a raw slide index to the carousel data-slide-to=2,
which shifts the slide position to a particular index beginning with 0.
The data-ride=carousel attribute is used to mark a carousel as animating
starting at page load.

``` 
<div id="carousel-example-generic" class="carousel slide" data-ride="carousel">
  <!-- Indicators -->
  <ol class="carousel-indicators">
    <li data-target="#carousel-example-generic" data-slide-to="0" class="active"></li>
    <li data-target="#carousel-example-generic" data-slide-to="1"></li>
    <li data-target="#carousel-example-generic" data-slide-to="2"></li>
  </ol>

  <!-- Wrapper for slides -->
  <div class="carousel-inner" role="listbox">
    <div class="item active">
      <img src="..." alt="...">
      <div class="carousel-caption">
        ...
      </div>
    </div>
    <div class="item">
      <img src="..." alt="...">
      <div class="carousel-caption">
        ...
      </div>
    </div>
    ...
    <!-- Controls -->
  <a class="left carousel-control" href="#carousel-example-generic" role="button" data-slide="prev">
    <span class="glyphicon glyphicon-chevron-left" aria-hidden="true"></span>
    <span class="sr-only">Previous</span>
  </a>
  <a class="right carousel-control" href="#carousel-example-generic" role="button" data-slide="next">
    <span class="glyphicon glyphicon-chevron-right" aria-hidden="true"></span>
    <span class="sr-only">Next</span>
  </a>
</div>            
                        
```

More [Bootstrap carousel
page](http://getbootstrap.com/javascript/#carousel)

### Checkbox / Radio

Add data-toggle=buttons to a .btn-group containing checkbox or radio
inputs to enable toggling in their respective styles.

``` 
<div class="btn-group" data-toggle="buttons">
  <label class="btn btn-primary active">
    <input type="checkbox" autocomplete="off" checked> Checkbox 1 (pre-checked)
  </label>
  <label class="btn btn-primary">
    <input type="checkbox" autocomplete="off"> Checkbox 2
  </label>
  <label class="btn btn-primary">
    <input type="checkbox" autocomplete="off"> Checkbox 3
  </label>

Copy

<div class="btn-group" data-toggle="buttons">
  <label class="btn btn-primary active">
    <input type="radio" name="options" id="option1" autocomplete="off" checked> Radio 1 (preselected)
  </label>
  <label class="btn btn-primary">
    <input type="radio" name="options" id="option2" autocomplete="off"> Radio 2
  </label>
  <label class="btn btn-primary">
    <input type="radio" name="options" id="option3" autocomplete="off"> Radio 3
  </label>
</div>
                        
```

More [Bootstrap checkbox/radio page](http://getbootstrap.com/javascript/#buttons-checkbox-radio)

