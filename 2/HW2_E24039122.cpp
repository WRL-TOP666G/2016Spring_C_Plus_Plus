#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;


int bucket_number = 10 ;
int array_number = 28 ;
char arr[80];
int arr_1[80];
int atoi (const char * arr[]);
struct Node
{
	int data;
	struct Node *next;
};

void BucketSort(int arr[]);
struct Node *InsertionSort(struct Node *list);
void print(int arr[]);
void printBuckets(struct Node *list);
int getBucketIndex(int value);

void inputfile();
void outputfile();

ofstream b;

int main(void)
{
    inputfile();




	int array[] = {49,2,21,5,97,36,38,48,24,6,17,25,1,14,4,30,47,32,0,80,84,91,96,78,45,43,51,77};
	outputfile();

	BucketSort(array);


}

void BucketSort(int arr[])
{
	int i,j;
	struct Node **buckets;

	/* allocate memory for array of pointers to the buckets */
	buckets = (struct Node **) malloc(sizeof(struct Node*) * bucket_number);

	/* initialize pointers to the buckets */
	for(i = 0; i < bucket_number;++i) {
		buckets[i] = NULL;
	}

	/* put items into the buckets */
	for(i = 0; i < array_number;++i) {
		struct Node *current;
		int pos = getBucketIndex(arr[i]);
		current = (struct Node *) malloc(sizeof(struct Node));
		current->data = arr[i];
		current->next = buckets[pos];
		buckets[pos] = current;
	}

	/* check what's in each bucket */
	cout<<"key"<<endl;
    b<<"key"<<endl;
	for(i = 0; i < bucket_number; i++) {
		cout << i << " : ";
         b<< i << " : ";
	        printBuckets(buckets[i]);
		cout << endl;
		b << endl;

	}


    for(int j=0; j < bucket_number; j++){

        cout<< "key = " << j <<endl;
        b<< "key = " << j <<endl;
        buckets[j] = InsertionSort(buckets[j]);

        for(i = 0; i < bucket_number; i++) {
            cout << i << " : ";
            b << i << " : ";
	        printBuckets(buckets[i]);
            cout << endl;
            b << endl;
        }
    }
	/* put items back to original array */
	for(j =0, i = 0; i < bucket_number; ++i) {
		struct Node *node;
		node = buckets[i];
		while(node) {
			arr[j++] = node->data;
			node = node->next;
		}
	}

	/* free memory */
	for(i = 0; i < bucket_number;++i) {
		struct Node *node;
		node = buckets[i];
		while(node) {
			struct Node *tmp;
			tmp = node;
			node = node->next;
			free(tmp);
		}
	}
	free(buckets);
	return;
}

/* Insertion Sort */
struct Node *InsertionSort(struct Node *list)
{
	struct Node *k,*nodeList;
	/* need at least two items to sort */
	if(list == 0 || list->next == 0) {
            //point to the end
            return list;
	}

	nodeList = list;
	k = list->next;
	nodeList->next = 0;
	while(k != 0) {
		struct Node *ptr;

		if(nodeList->data > k->data)  {
			struct Node *tmp;
			tmp = k;
			k = k->next;
			tmp->next = nodeList;
			nodeList = tmp;
			continue;
		}

		for(ptr = nodeList; ptr->next != 0; ptr = ptr->next) {
			if(ptr->next->data > k->data) break;
		}

		if(ptr->next!=0){
			struct Node *tmp;
			tmp = k;
			k = k->next;
			tmp->next = ptr->next;
			ptr->next = tmp;
			continue;
		}
		else{
			ptr->next = k;
			k = k->next;
			ptr->next->next = 0;
			continue;
		}
	}
	return nodeList;
}

int getBucketIndex(int value)
{
	return value/10;
}
/*
void print(int ar[])
{
	int i;
	for(i = 0; i < array_number; ++i) {
		cout << "   " << ar[i];
	}
	cout << endl;
}
*/
void printBuckets(struct Node *list)
{   //Inside the number of bucket
	struct Node *cur = list;
	while(cur) {
		cout << "   " << cur->data;
		b << "   " << cur->data;
		cur = cur->next;
	}
}

void inputfile(){


    fstream a;
    char symbol;
    a.open("input1.txt",ios::in);
    if(!a)
        cout<<"File can not open!"<<endl;
    else{
        a.read(arr,sizeof(arr));
        cout << arr ;
    }
    for(int i;i<80;i++);
        //arr[i]=atoi(arr_1[i]);
}



void outputfile(){

        cout<<"Output filename:Output1_E24039122.txt";
        b.open("Output1_E24039122.txt",ios::out);
        if(!b)
            cout<<"File can not open!"<<endl;


}






