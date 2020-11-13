# SSH Into My Heart

*SSH into my heart is the title of a song written some time ago which talks about SSH in a very romantic way*

This program, however, will spawn two processes (using again the simplified David's maneuver):
* The first one will create a file on a locally hosted, password protected SSH server and will write "*Davide Was Here*"
* The second one is the child with an infinite loop which will disturb the excecution of the program

> *the vector version of exec, fork and the standard library facilities have been used to write this program*