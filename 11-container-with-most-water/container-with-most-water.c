int maxArea(int* height, int heightSize) {
    int low = 0;
    int high= heightSize - 1;
    int max = 0;
    while(low < high){
        int h =height[low] < height[high] ? height[low] : height[high];
        int width = high - low;
        int area = h * (high-low);
        if (area > max){
            max=area;
        }

         if(height[low] > height[high])
            high --;
            else
            low ++;
    }
    return max ;
}