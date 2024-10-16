#include<bits/stdc++.h>
using namespace std;



//  Next Greater Element I


// broute force
// vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//     vector<int> temp;
//     for(int i = 0 ; i < nums1.size(); i++){
//         bool found = false;
//         for(int j = 0; j < nums2.size();j++){
//             if(nums1[i] == nums2[j]){
//                 for(int k = j + 1; k < nums2.size();k++){
//                     if(nums1[i] < nums2[k]){
//                         temp.push_back(nums2[k]);
//                         found = true;
//                         break;
//                     }
//                 }
//                 if(!found){
//                     temp.push_back(-1);
//                 }
//                 break;
//             }
//         }
//     }
//     return temp;
// }



int main() {
  vector < int > v1 {5,6,0};
  vector < int > v {5,7,1,2,6,0};
  vector < int > res =  nextGreaterElement(v1,v);
  cout << "The next greater elements are" << endl;
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
}