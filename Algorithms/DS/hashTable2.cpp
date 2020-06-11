#include <iostream>
#define MAX_TABLE_SIZE 10
#define GET_HASH_KEY(key) key % MAX_TABLE_SIZE
using namespace std;
typedef struct NODE{
    int value = 0;
    NODE* next = NULL;
}NODE;
NODE* hashTable[MAX_TABLE_SIZE];
void addValue(NODE* newNode){
    int hash_key = GET_HASH_KEY(newNode->value);
    
    if(hashTable[hash_key] == NULL){
        hashTable[hash_key] = newNode;
    }
    else{
        newNode->next = hashTable[hash_key];
        hashTable[hash_key] = newNode;
    }
}

void deleteValue(int value){
    int key = GET_HASH_KEY(value);
    if(hashTable[key] == NULL) return;

    NODE* delNode = NULL;
    if(hashTable[key]->value == value){
        delNode = hashTable[key];
        hashTable[key] = hashTable[key]->next;
    }
    else{
        NODE* curNode = hashTable[key];
        NODE* nextNode = hashTable[key]->next;
        while(nextNode){
            if(nextNode->value == value){
                curNode->next = nextNode->next;
                delNode = nextNode;
                break;
            }
            curNode = nextNode;
            nextNode = nextNode->next;
        }
    }
    free(delNode);
}

NODE* findNode(int value){
    int key = GET_HASH_KEY(value);
    NODE* foundNode = NULL;
    if(hashTable[key]->value == value){
        return hashTable[key];
    }
    else{
        NODE* curNode = hashTable[key];
        NODE* nextNode = hashTable[key]->next;
        while(nextNode->value == value){
            foundNode = nextNode;
            break;
        }
    }
    return foundNode;
}
int main(){
    
    return 0;
}
