#include <iostream>
typedef long long ll;

ll x = 0;
void merge(ll * arr, ll l, ll m, ll r)
{
	ll n1 = m - l + 1;
	ll n2 = r - m;
	ll * left = new ll[n1];
	ll * right = new ll[n2];
	ll i, j, k;
	for (i = 0; i < n1; ++i)
		left[i] = arr[l + i];
	for (j = 0; j < n2; ++j)
		right[j] = arr[m + 1 + j];
	i = j = 0;
	k = l;

	while (i < n1 && j < n2)
	{
		if (left[i] <= right[j])
			arr[k++] = left[i++];
		else {
			arr[k++] = right[j++];
			x += n1 - i;
		}
	}

	while (i < n1)
		arr[k++] = left[i++];
	while (j < n2)
		arr[k++] = right[j++];

	delete[] right;
	delete[] left;
}

void MergeSort(ll * arr, ll l, ll r)
{
	if (l < r) {
		ll m = (l + r) / 2;
		MergeSort(arr, l, m);
		MergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

int main()
{
	ll n;
	std::cin >> n;
	ll* arr = new ll[n];
	for (int i = 0; i < n; ++i)
		std::cin >> arr[i];
	MergeSort(arr, 0, n - 1);
	std::cout << x << std::endl;
	delete[] arr;
	return 0;
}