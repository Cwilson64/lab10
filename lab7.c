#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define AL 26

struct Trie 
{

    int c;
    struct Trie* ch[AL];

}

void insert(struct Trie** ppTrie, char* word) 
{
    if (*ppTrie == NULL) 
    {
        *ppTrie = (struct Trie*) malloc(sizeof(struct Trie));
        (*ppTrie)->c = 0;

        for (int i = 0; i < AL; i++) {

            (*ppTrie)->ch[i] = NULL;

        }

    }

    struct Trie* current = *ppTrie;
    int n = strlen(word);

    for (int i = 0; i < n; i++) 
    {

        int l = word[i] - 'a';

        if (current->ch[l] == NULL) 
        {

            current->ch[l] = (struct Trie*) malloc(sizeof(struct Trie));
            current->ch[l]->c = 0;

            for (int j = 0; j < AL; j++) 
            {

                current->ch[l]->ch[j] = NULL;

            }

        }

        current = current->ch[l];

    }

    current->c++;

}

int numberOfOccurrences(struct Trie* pTrie, char* word) 
{

    struct Trie* current = pTrie;
    int n = strlen(word);

    for (int i = 0; i < n; i++) 
    {

        int x = word[i] - 'a';

        if (current->ch[x] == NULL) 
        {

            return 0;

        }

        current = current->ch[x];

    }

    return current->c;

}

struct Trie* deallocateTrie(struct Trie* pTrie) 
{

    if (pTrie == NULL) 
    {

        return NULL;

    }

    for (int i = 0; i < AL; i++) 
    {

        if (pTrie->ch[i] != NULL) 
        {

            deallocateTrie(pTrie->ch[i]);

        }

    }

    free(pTrie);
    return NULL;

}

int main(void) 
{

    struct Trie* trie = NULL;
    char* pWords[] = {"notaword", "ucf", "no", "note", "corg"};
    int numWords = 5;

    for (int i = 0; i < numWords; i++) 
    {

        insert(&trie, pWords[i]);

    }

    for (int i = 0; i < numWords; i++) {

        printf("%s: %d\n", pWords[i], numberOfOccurrences(trie, pWords[i]));

    }

    trie = deallocateTrie(trie);

    if (trie != NULL) 
    {

        printf("There is an error in this program\n");

    }

    return 0;

}