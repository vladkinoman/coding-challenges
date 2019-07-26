#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int height_of_left_block = 0;
    int height_of_right_block = 0;
    int width_between_left_and_right_blocks = 0;
    int amount_of_filled_blocks_between_left_and_right = 0;
    int amount_of_trapped_water = 0;

public:
    int trap(vector<int>& height) {

        for (int i = 0; i < height.size(); i++)
        {
            if(height[i] > 0 && !height_of_left_block)
            {
                height_of_left_block = height[i];
            }
                
            if(height[i] > 0 && height_of_left_block && height[i] >= height_of_left_block)
            {
                height_of_right_block = height[i];
            }
              
            if(height_of_left_block && !height_of_right_block) 
            {
                width_between_left_and_right_blocks++;
                amount_of_filled_blocks_between_left_and_right += height[i];
            }
            
            if(height_of_left_block && height_of_right_block)
            {
                amount_of_trapped_water += (height_of_right_block / height_of_left_block)
                * width_between_left_and_right_blocks - amount_of_filled_blocks_between_left_and_right;
            
                height_of_left_block = height_of_right_block;
                
                height_of_right_block = width_between_left_and_right_blocks
                = amount_of_filled_blocks_between_left_and_right = 0;
            }
            
        }
        
        return amount_of_trapped_water;
    }
};

void print(int a)
{
    cout << a << " ";
}
int main()
{
    vector<int> v({0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1});
    
    for_each(v.begin(), v.end(), print);
    cout << endl;

    Solution newSolution;
    cout << newSolution.trap(v) << endl;
    
    return 0;
}