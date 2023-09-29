# CS300-project2

Notes about implementation:

*shapelist.cpp* implements the functions defined in the provided shapelist.h from Canvas.

During my time working on this, I also discovered that there is another copy of the Stanford *cslib* library that can be found on Github - this is NOT the correct version for this assignment, as I found out the hard way.

Of note: as the *cslib* library from Stanford is used, the *std::vector* method *erase* is actually not available/defined. Instead, the Stanford library uses *remove*/*removeAt* in place of *erase*, which I use in the implementation.

*draw()* is implmented by iterating from the end of the vector to the front, due to the implementation notes within *shapelist.h*.

Finally, *tests.cpp* was a file I used to test the implementation of the *contains()* function for the shapes.