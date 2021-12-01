#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define WORD_MAX_COUNT 200
#define WORD_MAX_LENGTH 30
#define WORD_TYPES 2
#define WORD_DELIMITER ' '

int wordsCountMax = 0;

char *getEnglish(char *words)
{
    char *ret = (char *)calloc(WORD_MAX_LENGTH, sizeof(char));
    for (int i = 0; i < WORD_MAX_LENGTH; i++)
    {
        if (words[i] == WORD_DELIMITER)
        {
            strncpy(ret, words, i);
            return ret;
        }
    }
}

char *getKorean(char *words)
{
    char *ret = (char *)calloc(WORD_MAX_LENGTH, sizeof(char));
    int from = 0, to = 0;
    for (int i = 0; i < WORD_MAX_LENGTH; i++)
    {
        if (words[i] == WORD_DELIMITER)
        {
            from = i + 1;
            break;
        }
    }
    for (int i = from; i < WORD_MAX_LENGTH; i++)
    {
        if (words[i] == '\n' || words[i] == EOF)
        {
            to = i - 1; // 개행문자(\n, EOF) 제외
            break;
        }
    }
    strncpy(ret, words + from, to - from + 1);
    return ret;
}

char ***readFile(char *fileName)
{
    FILE *pFile;
    char ***ret = (char ***)malloc(sizeof(char **) * WORD_MAX_COUNT);
    for (int i = 0; i < WORD_MAX_COUNT; i++)
    {
        ret[i] = (char **)malloc(sizeof(char *) * WORD_TYPES);
    }

    int wordsCnt = 0;
    pFile = fopen(fileName, "r");
    if (pFile == NULL)
        printf("error opening file");
    else
    {
        char words[WORD_MAX_LENGTH * 2];
        while (fgets(words, WORD_MAX_LENGTH * 2, pFile) != NULL)
        {
            char *korean = getKorean(words);
            char *english = getEnglish(words);
            ret[wordsCnt][0] = korean;
            ret[wordsCnt][1] = english;
            wordsCnt++;
        }
    }

    wordsCountMax = wordsCnt;
    return ret;
}

struct English
{
    char *H;
    char *E;
    struct English *next;
};
typedef struct English Eng;
typedef Eng *Link;

void print_set(Link head)
{
    double correctCount = 0;
    double wordCount = 0;
    char En[15];
    head = head->next;
    while (head != NULL)
    {
        printf("%s -> ", head->H);
        scanf("%s", &En);
        if (!strcmp(En, ".quit"))
        {
            printf("점수:%.2lf", correctCount / wordCount * 100);
            return;
        }

        wordCount += 1;
        if (!strcmp(En, head->E))
        {
            correctCount += 1;
            printf("correct!\n");
        }
        else
        {
            printf("incorrect!\n");
        }
        head = head->next;
    }
    printf("점수:%.2lf", correctCount / wordCount * 100);
}

Link linked_list(char ***words)
{

    Link head = (Link)malloc(sizeof(Eng));
    Link node = head;

    int wordsCnt = 0;
    while (wordsCountMax > wordsCnt)
    {
        node->next = (Link)malloc(sizeof(Eng));
        node = node->next;
        node->H = words[wordsCnt][0];
        node->E = words[wordsCnt][1];
        wordsCnt++;
    }
    return head;
}

Link getNodeByIndex(Link head, int idx)
{
    head = head->next;
    int i = 0;
    while (i < idx && head != NULL)
    {
        head = head->next;
        i++;
    }
    return head;
}

void swap_nodes(Link head, int i, int j)
{
    Link prev, left, right;
    if (i == 0)
    {
        prev = head;
    }
    else
    {
        prev = getNodeByIndex(head, i - 1);
    }
    left = getNodeByIndex(head, i);
    right = getNodeByIndex(head, j);

    if (j - i == 1)
    {
        prev->next = right;
        left->next = right->next;
        right->next = left;
        return;
    }

    Link prevRight = left;
    while (prevRight->next != right)
    {
        prevRight = prevRight->next;
    }

    prev->next = right;
    Link tmp = left->next;
    left->next = right->next;
    right->next = tmp;
    prevRight->next = left;
}

void sort_linked_list(Link head)
{
    for (int i = 0; i < wordsCountMax - 1; i++)
    {
        for (int j = i + 1; j < wordsCountMax; j++)
        {
            Link li = getNodeByIndex(head, i);
            Link lj = getNodeByIndex(head, j);
            // printf("comparing : %s with %s\n", li->E, lj->E);
            if (strcmp(li->E, lj->E) > 0)
            {
                // printf("swapping : %s with %s, swap(%d,%d)\n", li->E, lj->E, i, j);
                swap_nodes(head, i, j);
            }
        }
    }
}

int main()
{
    printf(">>영어 단어 맞추기 프로그램<<\n");
    printf("1.영어 단어 맞추기           2.프로그램 종료\n");
    printf("\n\n");

    int a;
    scanf("%d", &a);

    Link head;
    char ***readWords;
    switch (a)
    {
    case 1:
        readWords = readFile("input.txt");
        head = linked_list(readWords);
        sort_linked_list(head);
        print_set(head);
        break;

    case 2:
        return 0;
        break;
    }
    return 0;
}