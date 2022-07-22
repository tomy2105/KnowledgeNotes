# Apache Cordova

<!-- toc -->

- [Install](#install)
- [Creating project](#creating-project)
- [Add platforms](#add-platforms)
- [Build](#build)
- [Test](#test)

<!-- tocstop -->

More info at [official site doc](https://cordova.apache.org/docs/en/latest/)

## Install

Download and install Node.js from http://nodejs.org/download/ (MSI installer)

Instal cordova by typing in command prompt: `npm install cordova -g`

The -g flag above tells npm to install cordova globally. Otherwise it will be installed in the node_modules subdirectory of the current working directory.
   
## Creating project

`cordova create HelloCordova com.example.hello "Hello Cordova"`
   
Running the command with the -d option displays information about its progress.
Arguments:  	
 - HelloCordova - folder
 - com.example.hello - reverse domain-style identifier (optional, can be edited in config.xml later)
 - "Hello Cordova" -  provides the application's display title (optional, can be edited in config.xml later)
   
## Add platforms
   
```
   cd HelloCordova

    cordova platform add ios
    cordova platform add amazon-fireos
    cordova platform add android
    cordova platform add blackberry10
    cordova platform add firefoxos

    cordova platform add wp8
    cordova platform add windows
    cordova platform add amazon-fireos
    cordova platform add android
    cordova platform add blackberry10
    cordova platform add firefoxos

	cordova platforms ls

    cordova platform remove xyz
```
	
## Build

```
	cordova build
	
	cordova build android
```

## Test

```
	cordova emulate android
```
