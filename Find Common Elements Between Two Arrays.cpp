class Solution {
public:
// MAP SOLUTION 
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> count1;
        map<int, int> count2;
        // Count occurrences in nums1
        for(auto&num : nums1) {
            count1[num]++;
        }
        
        // Count occurrences in nums2
        for (int num : nums2) {
            count2[num]++;
        }
        
        int answer1 = 0;
        int answer2 = 0;
        
        // Calculate answer1: For each unique element in nums1, check if it exists in nums2
        for ( auto&pair : count1){
            if(count2.find(pair.first) != count2.end()) {
                answer1+=pair.second;  
            }
        }
        
        // Calculate answer2: For each unique element in nums2, check if it exists in nums1
        for (const auto& pair : count2) {
            if (count1.find(pair.first) != count1.end()) {
                answer2 += pair.second;  // Add the count of occurrences in nums2
            }
        }
        
        return {answer1, answer2};
    }
};
// SET SOLUTION


class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        set<int> set1(nums1.begin(), nums1.end());
        set<int> set2(nums2.begin(), nums2.end());
        int answer1 = 0;
        for (auto&num : nums1){
            if (set2.count(num)){
                answer1++;
            }
        }
        int answer2 = 0;
        for (auto&num : nums2){
            if (set1.count(num)){
                answer2++;
            }
        }
        
        return {answer1, answer2};
    }
};


