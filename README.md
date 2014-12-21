Delay2
======

Delay library using milliseconds in Arduino

Usage
======
* ```Delay2()```  
Instantiates the library and creates a TimeData array that allows you to store 32 delay timers.
* ```boolean start(int index, unsigned long timeDelay)```  
Creates a new delay timer at ```index``` with a ```timeDelay``` in milliseconds. This returns true if the timer has finished and false if it is still running.
* ```boolean start(int index, unsigned long timeDelay, int runTime)```  
Same as above except this will only run the number of times you specify with ```runTime``` and will not run again until you call ```reset()```
* ```int runCount(int index)```  
This is used with the ```start()``` function when you specify a ```runTime```. This returns how many times the timer has been run.
* ```boolean finished(int index)```  
Returns the same data as ```start()```. true if the timer has finished running and false if it is still running. This allows you to check the state of a timer without starting another one if it has finished.
* ```boolean once(int index, unsigned long timeDelay)```  
This creates a timer at ```index``` that will run just once until you call ```reset()```. This function is just a simplified way of calling ```start()``` with a runTime of 1.
* ```unsigned long time(int index)```  
This will give you the milliseconds since the timer at ```index``` has started.
