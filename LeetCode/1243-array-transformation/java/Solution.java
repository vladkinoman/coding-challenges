class Solution {

    public List<Integer> transformArray(int[] arr) {
        int n = arr.length;
        if (n < 1 || n > 100) 
            throw new IllegalArgumentException();
        for (int i = 0; i < n; i++)
            if (arr[i] < 1 || arr[i] > 100)
                throw new IllegalArgumentException();
        
        boolean arrayIsChanged = false;
        List<Integer> transformedArr = null;
        // a is the original array
        int[] a = new int [n];
        do { 
            a = Arrays.copyOf(arr, arr.length);
            transformedArr = new ArrayList<>();
            int i = 1;
            transformedArr.add(arr[i - 1]);
            arrayIsChanged = false;
            for (; i < n - 1; i++) {
                if (a[i] < a[i - 1] && a[i] < a[i + 1]) {
                    arr[i]++;
                    transformedArr.add(arr[i]);
                    arrayIsChanged = true;
                } else if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
                    --arr[i];
                    transformedArr.add(arr[i]);
                    arrayIsChanged = true;
                } else {
                    transformedArr.add(arr[i]);
                }
            }
            if (n > 1) transformedArr.add(arr[i]);
        } while (arrayIsChanged);
        
        return transformedArr;
    }
}