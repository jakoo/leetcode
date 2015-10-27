class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int all = nums1.size() + nums2.size();
		if (all & 0x1)
			return findKth(nums1, 0, nums2, 0, all / 2 + 1);
		else
			return (findKth(nums1, 0, nums2, 0, all / 2) +
			findKth(nums1, 0, nums2, 0, all / 2 + 1)) /
			2;
	}

	double findKth(vector<int>& a, int pa, vector<int>& b, int pb, int k)
	{
		if (a.size() - pa > b.size() - pb)
			return findKth(b, pb, a, pa, k);

		if (a.size() - pa == 0)
			return b[pb + k - 1];

		if (k == 1)
			return a[pa] < b[pb] ? a[pa] : b[pb];
		
		int next_pa = a.size() - pa < k / 2 ? a.size() - 1 : k / 2 - 1 + pa;
		int next_pb = k - (next_pa - pa + 1) + pb - 1;
		if (a[next_pa] == b[next_pb])
			return a[next_pa];
		else if (a[next_pa] < b[next_pb])
			return findKth(a, next_pa + 1, b, pb, k - (next_pa - pa + 1));
		else
			return findKth(a, pa, b, next_pb + 1, k - (next_pb - pb + 1));
	}
};
