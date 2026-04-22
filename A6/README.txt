The following is my implementation of indexing binary files!

Here are the functions I had to implement:

searchSample(speciesCode, offset, filename) --->  while the title and params may be a little 
misleading, this function takes the starting index of samples (speciesCode) and adds an offset,
and reads that location in the file. If it is not out of bounds and if it is not deleted, then 
it returns true (an element exists at that location.)

p_index(array[], indexArray[]) ---> this function takes an array of samples, and an array to
store the values that are used for indexing. It runs through the array, finds the first 
instance of each speciesCode, and stores it in the index array.

p_displayResearcher(speciesCode, offset, filename) ---> similarly to searchSample, this function
uses the provided params to open the file and read the data, then it gets the researcher and 
prints it to the console.

p_updateResearcher(speciesCode, offset, newName, filename) ---> if the entry exists, then it will
find the entry and change the researcher to the newName provided.

p_deleteSample(speciesCode, offset, filename) ---> it goes into the location in the file, and
marks the speciesCode as -1. This indicates that the selected entry has been deleted (and it is
what the searchSample function looks for.)

p_printRange(speciesCode, startIndex, endIndex, filename) ---> opens the file and reads the all of
the entrys between startIndex and endIndex in the designated speciesCode. Any deleted samples it
runs into will be skiped. This means that if you print 1 - 10, but there is a deleted entry in that
range, it will only print 9 values rather than 10. 

sort(array[], fileSize) ---> My sort implementation does not use anything fancy, but something simple
really. It counts how many of each speciesCode there is, and then it indexs it right away. It should 
be an O(3n) [technically O(n)] since it only goes through the array three times. Onece for indexing,
another time for sorting, and the last time for copying the array. 

A makefile is provided for your convenience, I hope you enjoy :P