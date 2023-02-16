#include <iostream>
#include <vector>



void merge(std::vector<int> & v, int a_start, int a_end,int b_start, int b_end, std::vector<int> &w, int i, int j, int k){
    if (i > a_end && j > b_end) {
        for(int x = a_start; x <= b_end; x++){
            v[x] = w[x];
        }
        return;
    }
    if (i <= a_end && j <= b_end) {
        if(v[i] < v[j]){
            w[k++] = v[i++];
        }else if(v[j] < v[i]){
            w[k++] = v[j++];
        }else{
            w[k++] = v[i++];
            w[k++] = v[j++];
        }
        merge(v,a_start,a_end,b_start,b_end, w, i, j, k);
        return;
    }

    if (i <= a_end) {
        w[k++] = v[i++];
    }
    if(j <= b_end){
        w[k++] = v[j++];
    }
    merge(v,a_start,a_end,b_start,b_end, w, i, j, k);
}

void ms(std::vector<int> &v, int low, int high,std::vector<int> &w){
    if(low == high){
        return;
    }
    
    int mid = (high+low)/2;
    ms(v,low,mid,w);
    ms(v,mid+1,high,w);
    merge(v,low,mid,mid+1,high,w, low, mid+1, low);
}

void ms(std::vector<int> & v ){
    std::vector<int> w(v.size());
    ms(v,0,v.size()-1,w);
}

void org(std::vector<int> & v, int low, int high){
    while (low < high) {
        if (v[low] % 2 == 0) {
            low++;
        } else if (v[high] % 2 == 1) {
            high--;
        } else {
            int temp = v[low];
            v[low] = v[high];
            v[high] = temp;
            low++;
            high--;
        }
    }
}

void org(std::vector<int> & v) {
    org(v,0,v.size()-1);
}

void double_it(std::string &str, int n){
    if (str.size() == 0 || n < 0) {
        return;
    }
    str += str[n];
    double_it(str, n-1);
}

void double_it(std::string &str) {
    double_it(str, str.size()-1);
}

void print(std::vector<int> &v){
    for(int i : v){
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main(){
    std::vector<int> v = {6,2,8,-2,4,0};
    std::vector<int> v3 = {1,6,2,19,21,4,7,2,2,100,-2,-6,8};
    std::vector<int> v1 = {1,2,4,4,6,8,10,12,25,25,25};
    std::vector<int> v4;
    std::vector<int> v2 = {1,2,3,4,5,6,7};
    std::cout << "Merge Sort Test 1" << std::endl;
    print(v);
    ms(v);
    print(v);
    std::cout << "Merge Sort Test 2" << std::endl;
    print(v3);
    ms(v3);
    print(v3);
    std::cout << "------------------" << std::endl;
    
    std::cout << "Org Test 1" << std::endl;
    print(v1);
    org(v1);
    print(v1);
    std::cout << "Org Test 2" << std::endl;
    print(v4);
    org(v4);
    print(v4);
    std::cout << "Org Test 3" << std::endl;
    print(v2);
    org(v2);
    print(v2);

    std::cout << "------------------" << std::endl;
    std::cout << "double_it Tests" << std::endl;
   
    std::string str = "hello";
    double_it(str);
    std::cout << str << std::endl;
    str = "";
    double_it(str);
    std::cout << str << std::endl;
    str = "last test";
    double_it(str);
    std::cout << str << std::endl;
    return 0;
}
