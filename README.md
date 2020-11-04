# Dictionary-Word-Search

**This program searches through a dictionary text file for either: a full  word, the beginning of a word, or a word with a missing letter.**  

Data Structures Used:  
- **Maps**
- **Stacks**
- **Vectors** (Standard Template Library)
- **Binary Search implemented to increase time efficiency**  

This program provides three **key functionalities**:  
- **Full-Word-Search**: program returns whether a user-**provided word** is **found** in the input dictionary.   
  **e.g. INPUT: figs**   
        **OUTPUT: found**
- **Prefix-Search**: program lists all **words** in the input dictionary that **start with** a user-**provided prefix**.   
  **e.g. INPUT: hum*   
       **OUTPUT: human, humility, etc**
- **Wildcard-Search**: program listd all the **words** of the dictionary that **match** the **search-string up to one character**. 
  **e.g. INPUT: ma*e**   
       **OUTPUT: make, male, etc**

**To run program:**    
mymachine-promt >> ./mydictionary -d <dictionaryFile> -l <MaxNumOfWordsInOutput>

where...
- **-d** is the flag indicating that the lexeme proceeding it is the file name of the dictionary to be used.
- **-l** is the flag indicating that the number proceeding it is the maximum number of results to be outputted.  
  
At the start of the program, the user is presented with a prompt.
