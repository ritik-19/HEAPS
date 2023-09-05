#include <iostream>
#include <vector>
#include <queue>
class node
{
public:
	int distance;
	int first;
	int second;
};
class compare
{
public:
	bool operator()(node a, node b)
	{
		return a.distance < b.distance;
	}
};
int main()
{
	int n, k;
	std::cin >> n >> k;
	std::vector<std::vector<int>> nums;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		std::cin >> x >> y;
		nums.push_back({x, y});
	}
	std::priority_queue<node, std::vector<node>, compare> pq;
	std::vector<std::vector<int>> ans;
	for (int i = 0; i < nums.size(); i++)
	{
		int firstElement = nums[i][0];
		int secondElement = nums[i][1];
		int tempDistance = firstElement * firstElement + secondElement * secondElement;
		pq.push({tempDistance, firstElement, secondElement});
		if (pq.size() > k)
		{
			pq.pop();
		}
	}
	while (!pq.empty())
	{
		ans.push_back({pq.top().first, pq.top().second});
		pq.pop();
	}
	return 0;
}