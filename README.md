# Autocomplete-Feature-using-Trie

Implemented the auto suggest feature used in browsers to suggest the words from incomplete written words by the user.
Used a Trie data structure to store 20,000 most used words in English.

Calculated the ratio of average time required by normal prefix search and the trie search which came out to be 330:1.
So it is about 330 times faster than prefix search. Also the memory required to store the words is very less as compared to storing as a list of strings.
