#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
// struct TreeNode {
//     int val, lcount;
//     TreeNode *left, *right;
//     TreeNode(int val){
//         this->val = val;
//         this->lcount = 0;
//         this->left = this->right = NULL;
//     }
// };

// TreeNode* insert(TreeNode* root, int val){
//     if(!root){
//         return new TreeNode(val);
//     }
//     if(val <= root->val){
//         root->lcount++;
//         root->left = insert(root->left, val);
//     }else{
//         root->right = insert(root->right, val);
//     }
//     return root;
// }

// int gtCnt(TreeNode* root, int n, int val){
//     TreeNode* curr = root;
//     TreeNode* last = NULL;
//     while(curr){
//         if(val < curr->val){
//             last = curr;
//             curr = curr->left;
//         }else{
//             n -= (curr->lcount + 1);
//             curr = curr->right;
//         }
//     }
//     if(last){
//         return n - last->lcount;
//     }
//     return 0;
// }
// #1
// ll solve(vector<int> &ar, int n){
//     ll res = 0;
//     for(int i = 1; i < n; i++){
//         ll t_sum = 0;
//         for(int j = 0; j < i; j++){
//             if(ar[j] < ar[i]){
//                 t_sum += ar[j];
//             }
//         }
//         res += t_sum;
//     }
//     return res;
// }
// #2
// ll solve(vector<int> &ar, int n){
//     int cnt[n];
//     memset(cnt, 0, sizeof(cnt));
//     for(int i = n - 2; i >= 0; i--){
//         int c = 0;
//         for(int j = i + 1; j < n; j++){
//             if(ar[j] > ar[i]){
//                 c++;
//             }
//         }
//         cnt[i] = c;
//     }
//     ll res = 0;
//     for(int i = 0; i < n; i++){
//         res += (ar[i] * cnt[i]);
//     }
//     return res;
// }
// #3
// ll solve(vector<int> &ar, int n){
//     int cnt[n];
//     memset(cnt, 0, sizeof(cnt));
//     TreeNode *root = new TreeNode(ar[n-1]);
//     for(int i = n - 2; i >= 0; --i){
//         cnt[i] = gtCnt(root,n-i-1, ar[i]);
//         root = insert(root, ar[i]);
//     }
//     ll res = 0;
//     for(int i = 0; i < n; i++){
//         res += ((ll) cnt[i] * ar[i]);
//     }
//     return res;
// }

ll res;
void merge(vector<int> &ar, int start, int mid, int end){
    int n1 = mid - start + 1;
    int n2 = end - mid;
    vector<int> left(n1), right(n2);
    for(int i = 0; i < n1; i++)
        left[i] = ar[start + i];
    for(int i = 0; i < n2; i++)
        right[i] = ar[mid + 1 + i];
    int i = 0, j = 0, pos = start;
    while(i < n1 && j < n2){
        if(left[i] < right[j]){ // i < j and ar[i] < ar[j];
            int cnt = n2 - j;
            res += ((ll) cnt * left[i]);
            ar[pos++] = left[i++];
        }else{
            ar[pos++] = right[j++];
        }
    }
    while(i < n1){
        ar[pos++] = left[i++];
    }
    while(j < n2){
        ar[pos++] = right[j++];
    }
}

void merge_sort(vector<int> &ar, int start, int end){
    if(start < end){
        int mid = start + (end - start) / 2;
        merge_sort(ar, start, mid);
        merge_sort(ar, mid + 1, end);
        merge(ar, start, mid, end);
    }
}

ll solve(vector<int> &ar, int n){
    res = 0;
    merge_sort(ar, 0, n - 1);
    return res;
}

int main(){
    fast
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> ar(n);
        for(int i = 0; i < n; i++)
            cin >> ar[i];
        cout << solve(ar, n) << "\n";
    }
    return 0;
}