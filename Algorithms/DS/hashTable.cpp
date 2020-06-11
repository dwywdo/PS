#include<iostream>
#define MAX_HASHTABLE_SIZE 10
#define HASH_KEY(key) key%MAX_HASHTABLE_SIZE
using namespace std;
typedef struct Node{
    int id;
    Node* hashNext;
}Node; 
Node* hashTable[MAX_HASHTABLE_SIZE];
void  AddHashData(int key, Node* node){
    int hash_key = HASH_KEY(key);
    if (hashTable[hash_key] == NULL){ // 현재 버킷에 데이터 없으면
        hashTable[hash_key] = node;
    }
    else{ // 현재 버킷에 데이터 있으면
        // 노드를 맨 앞에 넣어주고 꼬리 링크를 현재 있는 노드에 붙임
        node->hashNext = hashTable[hash_key];
        hashTable[hash_key] = node;
    }
}
void DelHashData(int id){
    int hash_key = HASH_KEY(id);
    if (hashTable[hash_key] == NULL) // 비어있으면
        return;
 
    Node* delNode = NULL; // 지워질 노드
    if (hashTable[hash_key]->id == id){ // 바로 있으면
        delNode = hashTable[hash_key]; // 지울 데이터 지정
        hashTable[hash_key] = hashTable[hash_key]->hashNext; // 처음 원소를 2번째 것으로
    }
    else{
        Node* node = hashTable[hash_key]; // 첫 노드
        Node* next = node->hashNext; // 다음 노드(두번째 노드)
        while (next){ // 다음 노드가 있으면
            if (next->id == id){ // 아이디 확인 후 같으면
                node->hashNext = next->hashNext; // 노드의 다음 노드를 건너 노드로
                delNode = next; // 지워질 노드는 다음 노드
                break;
            }
            node = next; // 못찾은 경우 다음걸로 넘겨주자
            next = node->hashNext; 
        }
    }
    free(delNode); 
}
Node* FindHashData(int id){
    int hash_key = HASH_KEY(id);
    if (hashTable[hash_key] == NULL)
        return NULL;
 
    if (hashTable[hash_key]->id == id){
        return hashTable[hash_key];
    }
    else{
        Node* node = hashTable[hash_key];
        while (node->hashNext){
            if (node->hashNext->id == id){
                return node->hashNext;
            }
            node = node->hashNext;
        }
    }
    return  NULL;
}
int main(){
    return 0;
}
