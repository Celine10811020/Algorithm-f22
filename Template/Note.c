//C
    #include <stdio.h>
    #include <stdlib.h>

//C++
    #include <algorithm>
    #include <vector>
    using namespace std;

int main()
{
    //一維動態陣列
        int *arrOne;
        arrOne = (int*)malloc(sizeof(int)*num);

    //二維動態陣列
        int **arrTwo;
        arrTwo = (int**)malloc(sizeof(int*)*row);
        for(i=0; i<row; i++)
        {
            arrTwo[i] = (int*)malloc(sizeof(int)*column);
        }


    //C++
        std::sort(arr, arr+10);
        std::sort(std::begin(arr), std::end(arr));

        std::nth_element(arr, arr+temp, arr+num); //找出arr中第temp小的數


    //C++, vector
        vector<int> vec;
        for(i=0; i<num; i++)
        {
            vec.push_back(i); //輸入值入vector
        }

        vec(arr, arr+num); //將陣列複製到vector裡面

        vec.clear(); //清空vector

        //找vector裡面的最大值與最小值
            auto upperBoundNum = upper_bound(v.begin(), v.end(), upperBound);
            auto lowerBoundNum = lower_bound(v.begin(), v.end(), lowerBound);

    return 0;
}
