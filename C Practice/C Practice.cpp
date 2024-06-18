
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

//#pragma pack(push,1)
struct BitField {
	unsigned char A : 4;
	
	unsigned short C: 5;
};
//#pragma pack(pop)

int main(void)
{
	int arr[10] = { 10,8,9,2,4,3,1,5,6,7 };
	
//	SelectSort(arr, sizeof(arr) / sizeof(int));
//	BubbleSort(arr, sizeof(arr) / sizeof(int));
//	InsertSort(arr, sizeof(arr) / sizeof(int));
	QuickSort(arr, 0, 9);

	for(int i=0; i<10; i++)
		printf("%d ", arr[i]);
	
	printf("\n\n");

	int val = BinarySearch(arr,sizeof(arr)/sizeof(int),5);

	printf("val : %d\n", val);
	
	printf("size : %d\n", sizeof(struct BitField));
	
	struct BitField bits = { 0xff, 0x00 };
	//bits.A = 0xff;
	//bits.C = 0x03;

	printf("0x%16x\n", bits.A);
	
	printf("0x%x\n", bits.C);

	unsigned short val2 = 20;
	printf("size -- : %d\n", sizeof(signed long));
	return 0;
}