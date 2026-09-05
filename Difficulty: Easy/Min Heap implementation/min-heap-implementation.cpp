class minHeap {
  private:
    vector<int>arr;

  public:

    void push(int x) {
        arr.push_back(x);
        int i = arr.size() -1;
        while(i > 0){
            int parent = (i-1)/2;
            
            if(arr[parent] > arr[i]){
                swap(arr[parent],arr[i]);
                i = parent;
            }
            else{
                break;
            }
        }
        
    }

    void pop() {
        if(arr.empty()) return;
        
        arr[0] = arr.back();
        arr.pop_back();
        
        int i = 0, n = arr.size();
        while(true){
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int smallest = i;
            
            if(left < n && arr[left] < arr[smallest]){
                smallest = left;
            }
            if(right < n && arr[right] < arr[smallest]){
                smallest = right;
            }
            if(smallest != i){
                swap(arr[smallest],arr[i]);
                i = smallest;
            }
            else{
                break;
            }
        }
    }

    int peek() {
        if(arr.empty()) return -1;
        return arr[0];
    }

    int size() {
          return arr.size();
    }
};