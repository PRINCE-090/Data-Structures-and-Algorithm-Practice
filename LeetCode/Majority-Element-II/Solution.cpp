1import java.util.*;
2
3class Solution {
4    public List<Integer> majorityElement(int[] nums) {
5        int cnt1 = 0, cnt2 = 0;
6        Integer el1 = null, el2 = null;
7
8        // 1st pass: Find candidates
9        for (int num : nums) {
10            if (el1 != null && num == el1) {
11                cnt1++;
12            } else if (el2 != null && num == el2) {
13                cnt2++;
14            } else if (cnt1 == 0) {
15                el1 = num;
16                cnt1 = 1;
17            } else if (cnt2 == 0) {
18                el2 = num;
19                cnt2 = 1;
20            } else {
21                cnt1--;
22                cnt2--;
23            }
24        }
25
26        // 2nd pass: Verify candidates
27        cnt1 = 0;
28        cnt2 = 0;
29        for (int num : nums) {
30            if (el1 != null && num == el1) cnt1++;
31            else if (el2 != null && num == el2) cnt2++;
32        }
33
34        List<Integer> result = new ArrayList<>();
35        int n = nums.length;
36        if (cnt1 > n / 3) result.add(el1);
37        if (cnt2 > n / 3) result.add(el2);
38
39        Collections.sort(result); // optional, for sorted order
40        return result;
41    }
42}
43