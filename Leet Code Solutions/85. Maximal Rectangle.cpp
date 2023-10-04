class Solution {
     private:
    vector<int> nextSmallerElement(int *arr,int n){
        stack<int>s;
        s.push(-1);
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            int curr=arr[i];
            while(s.top()!=-1 && arr[s.top()]>=curr){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
     vector<int> prevSmallerElement(int *arr,int n){
        stack<int>s;
        s.push(-1);
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            int curr=arr[i];
            while(s.top()!=-1 && arr[s.top()]>=curr){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    int largestRectangularArea(int *arr,int n){
        vector<int>next(n);
        next= nextSmallerElement(arr, n);
        vector<int>prev(n);
        prev= prevSmallerElement(arr, n);
        int area=INT_MIN;
        for(int i=0;i<n;i++){
            int l=arr[i];
            if(next[i]==-1){
                next[i]=n;
            }
            int b=next[i]-prev[i]-1;
            int newArea=l*b;
            area=max(area,newArea);
        }
        return area;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rowSize=matrix.size();
        int colSize=matrix[0].size();
        int arr[rowSize][colSize];
        for(int i=0;i<rowSize;i++){
            for(int j=0;j<colSize;j++){
                arr[i][j]=matrix[i][j]-'0';
            }
        }

        int area=largestRectangularArea(arr[0],colSize);
        for(int i=1;i<rowSize;i++){
            for(int j=0;j<colSize;j++){
                if(arr[i][j]!=0){
                    arr[i][j]=arr[i][j]+arr[i-1][j];
                }
                else arr[i][j]=0;
            }
            int newArea=largestRectangularArea(arr[i],colSize);
            area=max(newArea,area);
        }
        return area;
    }
};
