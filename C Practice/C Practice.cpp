/* Git Master!! */
#include <stdio.h>

void SelectSort(int *data, int len)
{
	int temp,i,j,idx,min;


	for(i=0; i<len; i++) {
		min = data[i];
		for(j=i;j<len; j++) {
			if(min > data[j]) {
				min = data[j];
				idx = j;
			} 
		}

		temp = data[idx];
		data[idx] = data[i];
		data[i] = temp;

	}

	for(int i=0; i<len; i++)
		printf("%d ", data[i]);
}

void BubbleSort(int *data, int len)
{
	int temp,i,j;

	for(i=0; i<len-1; i++) {
		for(j=0; j<len-1-i; j++) {
			if(data[j]>data[j+1]) {
				temp = data[j];
				data[j] = data[j+1];
				data[j+1] = temp;
			}
		}
	}

	for(int i=0; i<len; i++) 
		printf("%d ", data[i]);
}

void InsertSort(int *data, int len)
{
	int i,j, val;

	for(i=1; i<len; i++) {
		val = data[i];
		for(j=i; j>0; j--) {
			if(val < data[j-1]) {
				data[j] = data[j-1];
				data[j-1] = val;
			} else break;
		}

		
	}
	for(int i=0; i<len; i++)
		printf("%d ", data[i]);
}

void QuickSort(int *data, int start, int end)
{
	if(start>=end) return ;

	int i=start+1;
	int j=end;
	int pivot=start;

	while(i<=j) {
		while(data[pivot] >= data[i]) i++;
		while(data[pivot] <= data[j] && j>0) j--;

		if(i<=j) {
			int temp=data[i];
			data[i]=data[j];
			data[j]=temp;
		} else {
			int temp=data[pivot];
			data[pivot]=data[j];
			data[j]=temp;
		}
	}

	QuickSort(data, start, j-1);
	QuickSort(data, j+1, end);
}

int BinarySearch(int *data,int len, int searchVal)
{
	int endVal= len-1;
	int startVal=0;
	int middle = (startVal + endVal) / 2;
	
	while(data[startVal] < endVal) {
		middle = (startVal + endVal)/ 2;

		if(data[middle] > searchVal) {
			endVal = middle-1;
		}
		else if(data[middle] < searchVal) {
			startVal = middle+1;
		}
		else return middle;
	}

	return -1;
}

#pragma pack (push,1)
struct BitField {
	unsigned char INT0 : 1;
	unsigned char INT1 : 1;
	unsigned char : 1;
	unsigned char LSTVAL: 4;
	
	unsigned short SPARE : 16;
}Bits;
#pragma pack (pop,1)

int main(void)
{
	int arr[10] = { 10,8,9,2,4,3,1,5,6,7 };
	
	Bits.INT0 = 0x01;
	Bits.INT1 = 0x01;
	Bits.LSTVAL = 0x0f;
	
	printf("0x%02x\n", Bits.INT0);
	printf("0x%02x\n", Bits.INT1);
	printf("0x%05x\n", Bits.LSTVAL);
	
	printf("size : %d\n", sizeof(Bits));
	return 0;
}
