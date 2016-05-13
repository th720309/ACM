// 返回要查找元素的下标，-1为没有找到

int BinarySearch ( int A[], int l, int r, int key){
	int m = ( l + r ) / 2;
	while(l <= r){
		if( A[m] == key )
			return m;
		if( A[m] < key)
			l = m + 1;
		else 
			r = m - 1;
	}
	return -1;
}

//复杂度低，但是需要满足    A[1]<=key&&A[m]>=key

int BinarySearch ( int A[], int l, int r, int key ){
	int m = ( l + r ) / 2;
	while( r - l > 1 ){
		if( A[m] <= key )
			l = m ;
		else
			r = m;
	}
	if( A[l] == key )
		return l;
	else
		return -1;
}