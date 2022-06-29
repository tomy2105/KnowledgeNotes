FORFILES /S /M *.md /C "cmd /c echo @path && markdown-toc -i @path"
