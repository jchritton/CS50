/**
 * Declares a dictionary's functionality.
 */

#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45
#define ALPHABET_SIZE 26

int char_index(const char *c)
{
    int index_result = (int)c - (int)'a';
    return index_result;
}

//Defining nodes for use in the trie structure.
typedef struct node
{
    bool is_word;

    struct node *children[ALPHABET_SIZE];
}
node;

//Counter for number of words in dictionary.
int *word_count = 0;
node *root = NULL;

//Returns a new trie node
struct node *new_node(void)
{
  struct node *tNode = NULL;

  tNode = (struct node *)malloc(sizeof(node));

  if (tNode)
  {
    tNode->is_word = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
      tNode->children[i] = NULL;
    }
  }

  return tNode;
}

void insert_node(node *root, char *cur_word[LENGTH])
{
    int level;
    int length = strlen(*cur_word);
    int cur_child;

    node *crawl_temp = root;

	for (level = 0; level < length; level++)
	{
		cur_child = char_index(cur_word[level]);
		if (crawl_temp->children[cur_child] == NULL)
		{
			crawl_temp->children[cur_child] = new_node();
		}
		crawl_temp = crawl_temp->children[cur_child];
	}
	crawl_temp->is_word = true;
	word_count++;
}

void free_trie(node *root)
{
	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		if (root->children[i] != NULL)
		{
			free_trie(root->children[i]);
		}
	}
	free(root);
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word);

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary);

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void);

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void);

#endif // DICTIONARY_H
