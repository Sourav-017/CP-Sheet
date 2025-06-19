/**
 * Author: Simon Lindholm, chilli
 * Date: 2018-07-23
 * License: CC0
 * Source: http://codeforces.com/blog/entry/60737
 * Description: SQRT decomposition
 * Uses 1.5x memory. Initial capacity must be a power of 2 (if provided).
 */
int query(int input[], int segment_size, int l, int r) { 
    int sum = 0; 
    
    //loop the first segment
    //until we reach r or a starting index

    while (l < r && l % segment_size != 0) { 
	sum += input[l]; 
	l++; 
    } 

    //Loop until we reach
    //segment that contains r
    while (l + segment_size <= r) {  
        sum += segment[l / segment_size]; 
        l += segment_size; 
    } 
    
    //loop until r
    while (l<=r) { 
        sum += input[l]; 
        l++; 
    } 

    return sum; 
} 


void update(int input[], int segment_size, int i, int val) { 
    int segment_no = i / segment_size; 
    
    segment[segment_no] -= input[i];
    segment[segment_no] += val;
    input[i] = val;
}
