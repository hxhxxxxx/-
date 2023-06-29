//这题主要是对哈希表的使用以及变长数组vector的综合使用

class RandomizedSet {
public:
    RandomizedSet() {
        srand((unsigned)time(NULL));
    }
    
    bool insert(int val) {
        if(indices.count(val))return false;
        int siz=nums.size();
        nums.push_back(val);
        indices[val]=siz;
        return true;
    }
    
    bool remove(int val) {
        if(!indices.count(val))return false;
        int last=nums.back();
        int index=indices[val];
        nums[index]=last;
        indices[last]=index;
        nums.pop_back();
        indices.erase(val);
        return true;
    }
    
    int getRandom() {
        int randindex=rand()%nums.size();
        return nums[randindex];    
    }
private:
    vector<int>nums;
    unordered_map<int,int>indices;

};
