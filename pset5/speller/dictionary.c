/**
 * Implements a dictionary's functionality.
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "dictionary.h"

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
	int level;
	int length = strlen(word);
	int cur_child;

	node crawl_temp = *root;

	for (level = 0; level < length; level++)
	{
		cur_child = char_index(&word[level]);
		if (crawl_temp.children[cur_child] == NULL)
		{
			return false;
		}

		crawl_temp = crawl_temp.children[cur_child];
	}
    if (crawl_temp != NULL && crawl_temp.is_word = true)
    {
        return true;
    }
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
  //Open dictionary file, error if does not open.
  FILE* dict_in = fopen(dictionary, "rb");
  if (dict_in == NULL)
	{
		fprintf(stderr, "Could not open dictionary file.\n");
		return false;
	}

  char *cur_word[LENGTH];
  *root = new_node();

	while(1)
	{
		//Gets characters one at a time from dictionary file.
		int c = fgetc(dict_in);
		int word_index = 0;

  	if (c != '\n')
  	{
    	//Create a string for the current word being stored.
    	cur_word[word_index] = (char)c;
    	word_index++;
  	}
  	else
  	{
    	//Check for the word in the trie, insert if doesn't exist.
		insert_node(root, cur_word);
  	}
	}
  return false;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
		if (!*root)
		{
			return *word_count;
		}
    return 0;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
	free_trie(root);
	if (!root)
	{
		return true;
	}
	else
	{
  	return false;
	}
}
