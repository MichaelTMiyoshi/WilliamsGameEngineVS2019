# Game Engine Tutorial
*Mr. Miyoshi’s Beginning Programming / Game Programming Class*

This tutorial will walk you through the process of creating your own game, starting with a barebones project and building up to a 
complete game with user input, game objects, collisions, and more. Along the way we’ll explore each piece of the game in-depth. 
After working through this tutorial you’ll be able to use the skills you’ve learned to make any kind of game you’d like.

See Game Engine Tutorial.pdf for a full step-by-step tutorial.

### Important Notes

1. Toward the end of the tutorial, there is a call to a function that no longer exists.  So in place of `setColor` use `setFillColor`.
1. There are some typos in the tutorial.  They are good because they make you think.  They make you look at the code instead of just typing away.  So actually read the code and the surrounding text.  You may learn something.  (Probably lots of somethings.)
1. As the tutorial goes along, the author does not give you all the code.  He expects that you learned the techniques before, so you should be able to do so again.  Or in some cases, he tells you in the text rather than in the code segments he gives you.
1. Creating a scrolling background is not part of the tutorial.  I always think that it is because the background picture is in the art.  There is a special section below to give you a start.
1. There are no deletions in the tutorial.  In other words, you do not need to delete any code that he has written.  There are places where he writes "omitted code" which are just placeholders for code you have already written before.  There are also a couple places where new code may not be in color.

### Creating a Scrolling Background for the Game

When you get to the end of the tutorial, there is one more step.  That step is not included in the tutorial, but the art is.  (I thought the tutorial had a section about this, but I was either mistaken or I misplaced that tutorial version.)  The art is for a scrolling background.  (It is called background.png.)  Use what you have learned from the tutorial to create a seemless scrolling background.  All you are doing is placing a sprite on the screen.  Two actually.  But you only need to create one class for the object.  You can even name the object background.  The background images will move to the left so it appears that the ship moves through space to the right.  You have all the tools you need to create this background.  One last note: this step could make your game go very slowly.  If it does, just take it out.  Which brings me to one final note.  You should already be aware, but there is an order to what is drawn on the screen.  Pay attention to that order or you might think that things have disappeared when you place the background.

## Setup in VS2019

### Option #1: clone from GitHub with VS2019

1) Make sure you are logged into your GitHub account.  Fork this repo by clicking on the Fork button in the top right corner of this web page.  This will make an exact copy of this repository in your own GitHub account.  (Note: This step does not pull the repository down to your local computer.)
1) Launch VS2019.
1) Click “Clone or check out code”
1) Paste in `https://github.com/[Your GitHub username]/WilliamsGameEngineVS2019.git` and click Clone.  (You can get the link by going to your forked repository on your GitHub account, and pressing the copy link button.)
1) After it finishes cloning, open Solution Explorer with View -> Solution Explorer
1) Open Base Project -> MyGame and double-click MyGame.sln
1) This should open the solution and the tool bar should now contain a run button with “Debug, Win32, Local Windows Debugger”.
1) Press play and see it compile and run, showing a blank window ready for the tutorial to start.

### Option #2 (only use this option if you are NOT using GitHub): download a .zip file

1) Go to [https://github.com/MichaelTMiyoshi/WilliamsGameEngineVS2019](https://github.com/MichaelTMiyoshi/WilliamsGameEngineVS2019)
1) Click on the green “Clone or Download”
1) Click on “Download Zip” to download a copy of the repository
1) Unzip the files to wherever you’d like.
1) Navigate to Base Project -> MyGame within the new directory and double-click MyGame.sln.
1) This should open the solution and the tool bar should now contain a run button with “Debug, Win32, Local Windows Debugger”.
1) Press play and see it compile and run, showing a blank window ready for the tutorial to start.


## Updates to the Tutorial

No modifications to the VS Project are needed after forking and cloning this repository to your computer.

You can skip any mention of SFMLProjectModification.docx, and no changes are needed to any compiler or linker options.

You can ignore the references to the H:\ drive.

You do not need to move the art as instructed.  They are in the resources folder (Base project/MyGame/MyGame).

There is a link to a sprite sheet making website.  That website was no longer running as a sprite sheet maker.  If you decide to make sprites for your own game, you can look up piskel or click on this link [piskel](https://www.piskelapp.com), which was running at the time of this writing.

## Credits

This tutorial and SFML-based game engine was originally written by Eric Williams.
  
