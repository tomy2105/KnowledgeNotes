# Windows tips

<!-- toc -->

- [Forbiden chars in filename](#forbiden-chars-in-filename)
- [Run(once) locations](#runonce-locations)
- [Start explorer in folder](#start-explorer-in-folder)
- [Keyboard and mouse shortcuts](#keyboard-and-mouse-shortcuts)
- [Command prompt keyboard shortcuts](#command-prompt-keyboard-shortcuts)
- [God mode](#god-mode)

<!-- tocstop -->

## Forbiden chars in filename

`\/:*?"<>|`

## Run(once) locations

[Source 1](http://support.microsoft.com/?kbid=284193) and [source 2](http://techsupt.winbatch.com/TS/T000001036F33.html)

```
HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\Run 
HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Run 

HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\RunOnce 
HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\RunOnce 

HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\RunServices 
HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\RunServicesOnce 
HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\RunOnce\Setup
```

## Start explorer in folder

Click on the Shortcut tab, and change the Target so it reads: `c:\windows\EXPLORER.EXE /n, /e, d:\myfolder` (where `c:\windows` is your Windows directory, and `d:\myfolder` is the directory in which you want Explorer to start.)

**Tip**: To have Explorer start with My Computer, so no branches are initially expanded, use the following command line options: `/n, /e, /select, c:\`

## Keyboard and mouse shortcuts

[Source](https://support.microsoft.com/en-us/help/12445/windows-keyboard-shortcuts)

| Shortcut    | What it does |
|-------------|------------|
| ALT + Enter | Properties |
| Ctrl + Shift + Esc    |   Open Task Manager |
| Win + Pause | System Properties |
| Win + D | Desktop |
| Win + M | Minimize All |
| Win + Shift + M | Restore All |
| Win + E | Explorer |
| Win + L | Lock |
| Win + R | Run |
| Win + D | Display and hide the desktop |
| Win + Alt + D | Display and hide the date and time on the desktop |
| Win + I | Settings |
| Win + V | Clipboard history |
| Win + . | Emoji picker |
| Win + Ctrl + V | Cycle through notifications (+Shift = Reverse order) |
| Win					| 	Show the Windows 10 Start Menu |
| Ctrl + Arrow keys     |   Change Start menu size |
| Win + Alt + D			| 	Display and hide the date and time on the desktop |
| Win + H				| 	activate Windows Voice Typing |
| Win + H				| 	Share content (if supported by current app) |
| Win + K				| 	Connect to wireless displays and audio devices |
| Win + X				| 	Open Start button context menu |
| Win + G				| 	Opens the Windows 10 Game Bar to take game screenshots and record gaming videos of Windows 10 games (works in any game app, e.g. Microsoft Solitaire Collection) |
| Win + I				| 	Open Windows 10 settings |
| Win + A				| 	Open Windows 10 Action Center (e.g. to display notifications and customizable quick actions) |
| Win + Pause			| 	System Properties |
| Win + P				| 	Project a screen |
| Win + Space			| 	Switch keyboard input language (if you have added at least a second one) |
|  |  |
| Win + Tab | Open Task view |
| Win + Ctrl + D | Add a virtual desktop |
| Win + Ctrl + Left/Right arrow | Switch between virtual desktops you’ve created on the left/right |
| Win + Ctrl + F4 | Close the virtual desktop you're using |
|  |  |
| Alt + Tab					|   Switch to previous window |
| Alt + Space				| 	Restore, move, size, minimize, maximize or close current window. Also works like a charm for Windows 10 modern apps. |
| Alt + F4					|   Close current window, If you’re on your Windows 10 desktop, open Power dialogue to shut down or restart Windows, put your device in sleep mode, sign out or switch the current user  |
| Win + Shift + Left/Right arrow		|	Move current Window from one monitor to another (when using a multiple monitor setup) |
| Win + Left/Right/Up/Down arrow	|	Position windows on your screen |
|  |  |
| Win + number | open pinned app (+Shift - new instance, +Ctrl, +Alt, +Ctrl+Shift - new instance as admin) |
| Shift + click a taskbar button | Open an app or quickly open another instance of an app |
| Ctrl + Shift + click a taskbar button | Open an app as an administrator |
| Shift + right-click a taskbar button | Show the window menu for the app |
| Shift + right-click a grouped taskbar button | Show the window menu for the group |
| Ctrl + click a grouped taskbar button | Cycle through the windows of the group |
|  |  |
| Win + C	|				Search the web and Windows with Cortana (speech) |
| Win + S	|				Search the web and Windows with Cortana (keyboard input) |

More [here](win-8-shortcuts.png).


## Command prompt keyboard shortcuts


| Shortcut    | What it does |
|-------------|------------|
| SHIFT + LEFT ARROW		   | Moves the cursor to the left one character, extending the selection. |
| SHIFT + RIGHT ARROW		   | Moves the cursor to the right one character, extending the selection. |
| SHIFT + UP ARROW		       | Selects text up line by line starting from the location of the insertion point. |
| SHIFT + DOWN ARROW		   | Extends text selection down one line, starting at the location of the insertion point. |
| SHIFT + END			       | If cursor is in current line being edited, First time extends selection to the last character in the input line, Second consecutive press extends selection to the right margin. Else Selects text from the insertion point to the right margin. |
| SHIFT + HOME			       | If cursor is in current line being edited, First time extends selection to the character immediately after the command prompt, Second consecutive press extends selection to the left margin. Else Extends selection to the left margin. |
| SHIFT + PAGE DOWN		       | Extends selection down one screen. |
| SHIFT + PAGE UP			   | Extends selection up one screen. |
| CTRL + SHIFT + RIGHT ARROW	 |Extends the selection one word to the right.  |
| CTRL + SHIFT + LEFT ARROW	   | Extends the selection one word to the left.  |
| CTRL + SHIFT + HOME		   | Extend selection to the beginning of the screen buffer. |
| CTRL + SHIFT + END		   | Extend selection to the end of the screen buffer. |
| CTRL + A			           | If cursor is in current line being edited (from first typed char to last type char) and line is not empty and any selection cursor is also within the line being edited Selects all text after the prompt.  (phase 1) Else Selects the entire buffer.  (phase 2) |
|                              |  |
| CTRL + V	                   | Paste text into the command line. |
| SHIFT + INS	               | Paste text into the command line. |
| CTRL + C	                   | Copy selected text to the clipboard. |
| CTRL + INS	               | Copy selected text to the clipboard. |
|                              |  |
| CTRL + M	                   | Enter "Mark Mode" to move cursor within window. |
| ALT	+ ARROW KEYS	       | Move cursor in the direction specified selection in block mode. |
| ALT	+ PAGE KEYS	           | Move cursor by one page in the direction specified selection in block mode. |
| ALT	+ CTRL + HOME	       | Move cursor to beginning of buffer selection in block mode. |
| ALT	+ CTRL + END	       | Move cursor to end of buffer selection in block mode. |
|                              |  |
| CTRL + UP ARROW		       | Moves up one line in the output history. |
| CTRL + DOWN ARROW	           | Moves down one line in the output history. |
| CTRL + PAGE UP		       | Moves up one page in the output history. |
| CTRL + PAGE DOWN	           |  Moves down one page in the output history. |
|                              |  |
| CTRL + F	                   | Opens "Find" in console dialog. |
| ALT + F4	                   | Close the console window, of course! |
 
## God mode

Create a folder and give it a name: `GodMode.{ED7BA470-8E54-465E-825C-99712043E01C}`. Look inside to see many system related shortcuts.....