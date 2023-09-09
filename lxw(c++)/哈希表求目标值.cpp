#include <iostream>
#include <vector>
#include <map>
#include <iterator>

using namespace std;

//��һ������������ȡ������������������֮��Ϊtarget
vector<int> twoSum(vector<int>& nums, int target)
{
	vector<int> result;

	map<int, int> hashMap;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (hashMap.count(target - nums[i]))
		{
			result.push_back(hashMap[target - nums[i]]);
			result.push_back(i);
			break;
		}
		hashMap.insert(pair<int, int>(nums[i], i));
	}

	return result;
}

int main()
{
	vector<int> result, nums = { 5,6,7,8,9,10,11 };
	int target = 18;
	result = twoSum(nums, target);
	for (auto iter = result.begin(); iter != result.end(); iter++)
		cout << *iter << endl;

	system("pause");

	return 0;
}