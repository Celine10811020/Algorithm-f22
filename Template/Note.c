//C
    #include <stdio.h>
    #include <stdlib.h>

//C++
    #include <algorithm>
    #include <vector>
    using namespace std;

int main()
{
    //�@���ʺA�}�C
        int *arrOne;
        arrOne = (int*)malloc(sizeof(int)*num);

    //�G���ʺA�}�C
        int **arrTwo;
        arrTwo = (int**)malloc(sizeof(int*)*row);
        for(i=0; i<row; i++)
        {
            arrTwo[i] = (int*)malloc(sizeof(int)*column);
        }


    //C++
        std::sort(arr, arr+10);
        std::sort(std::begin(arr), std::end(arr));

        std::nth_element(arr, arr+temp, arr+num); //��Xarr����temp�p����


    //C++, vector
        vector<int> vec;
        for(i=0; i<num; i++)
        {
            vec.push_back(i); //��J�ȤJvector
        }

        vec(arr, arr+num); //�N�}�C�ƻs��vector�̭�

        vec.clear(); //�M��vector

        //��vector�̭����̤j�ȻP�̤p��
            auto upperBoundNum = upper_bound(v.begin(), v.end(), upperBound);
            auto lowerBoundNum = lower_bound(v.begin(), v.end(), lowerBound);

    return 0;
}
