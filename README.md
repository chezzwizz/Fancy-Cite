# Fancy-Cite
CFOSS project to maintain reading lists, quotes, and summaries of books and articles, with the ability to generate useful citations.

A consideration when using citation generators is the availability and access to those generators. Once built and installed, this program will allow you to keep a data file of all the references you have cited and a collection of summaries to go along. Additionally, it will always be available so long as you have the device it is installed on available. Web free!

## Style
The project is written using Microsoft C++/CLI and should use common .NET paradigms. Additionally, the use of CMake allows the user to generate a make file for any of a variety of build systems. The current CMake file include only has the instructions for the MS Build system with the cl.exe compiler.

## Tools and Dependencies
The current IDE of choice is SlickEdit 2020 (Standard) with the Visual Studio 2019 command line tool suite. [SlickEdit](https://www.slickedit.com/) can be downloaded from the there, and you can download the [Visual Studio](https://visualstudio.microsoft.com/) 2019 build tools suite by signing up for an account at https://my.visualstudio.com and downloading the [2019 Build Tools](https://my.visualstudio.com/Downloads?q=Visual%20Studio%202019) from the preceeding link. You can also check out the newest Professional Visual Studio tools at https://visualstudio.microsoft.com.

For the build system, CMake is currently the default choice which is currently being used to build MSBuild files. As of yet, I have not generated make files and attempted to use the traditional make file based build system. If you are able to successfully do this, please update the dependancy information.

**Notes:**
* *If there is an immplementation that allows Mono to be used with C++/CLI, please let me know. That sounds like an interesting cross-platform potential.*
* *Current building instructions consist of creating a sub directory, moving to that sub directory, and then running CMake on `..`. Please indicate in a conversation or specification propsal if traditional make files would be preferred as part of the repository.*

## Future Features
* Copyright contact information and tracking
* Bibliographic citation validation
* DOI meta search
