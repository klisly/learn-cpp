#include <stdio.h>
void displayArray(int array[], int size){
	printf("the array is:");
	int i; 
	for(int i = 0; i < size; i++){
		printf(" %d", array[i]);
	}
	printf("\n");
}
void displayBitmap(unsigned char bitmap[], int bitMapSize){
	unsigned char mask = 0x1;
	int i, j;
	printf("this result array is:");
	for(int i = 0; i < bitMapSize; i++){
		for(j = 7; j >= 0; j--){
			if((bitmap[i] & (0x1<<j))!=0){
				printf(" %d", i*8+(7-j));
			}
		}
	}
	printf("\n");
}

void createBitmap(unsigned char bitmap[], int bitMapSize, int array[], int arraySize){
	int i = 0;
	for(i = 0; i < arraySize; i++){
		bitmap[array[i]/8] = bitmap[array[i]/8]|(0x1<<(7-array[i]%8));
	}
}

int main(void){
	int array[10] = {34,45, 1, 39, 21, 68, 65, 100, 4, 51};
	displayArray(array, 10);
	unsigned char bitmap[13] = {0};
	createBitmap(bitmap, 13, array, 10);
	displayBitmap(bitmap, 13);
	return 0;
}
