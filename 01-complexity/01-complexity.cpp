#include <iostream>
#include <cstring>

// array[n] -> броя на елементите в масива определя големината му (когато разглеждаме големина на входа)

// Time complexity: O(1)
// Space complexity: O(1)
double sum_two_double_numbers(double num1, double num2)
{
    double sum = num1 + num2;
    return sum;
}

// Time complexity: O(n)
// Space complexity: O(1)
int sum_first_n_numbers(int n)
{
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
        sum += i;
    }
	return sum; // +1
}

// Time complexity: O(1)
// Space complexity: O(1)
int sum_first_n_numbers_const(int n)
{
    return (n * (n + 1)) / 2;
}

// Time complexity: O(1)
// Space complexity: O(1)
double sum_first_and_last_element(const double arr[], int n)
{
    return arr[0] + arr[n - 1];
}

// Time complexity: O(n)
// Space complexity: O(1)
double sum_of_array(const double arr[], int n)
{
    int sum = 0; // +1 (space)
    for(int i = 0; i < n; i++) // +1 (space);
    {
        sum += arr[i];
    }
    // +n (time)

    return sum; // +1 (time)
}

// Time complexity: O(n)
// Space complexity: O(1)
void find_odd_and_even_sum(int* arr, int n, int &oddSum, int &evenSum)
{
    for (int i = 0; i < n; i++)
    {
        if (i % 2 != 0)
        {
            oddSum += arr[i];
        }
        else
        {
            evenSum += arr[i];
        }
    }
}

// Time complexity: O(log(n))
// Space complexity: O(1)
double sum_array_elements(const double arr[], int n) // 1 -> 2 -> 4 -> 8 -> 16... // 2^0 -> 2^1 -> 2^2 -> ... -> 2^(log_2(n))
{
    int sum = 0;
    for (int i = 1; i < n; i *= 2)
    {
        sum += arr[i];
    }
    return sum;
}

// 1/2*n

// BC: O(1) -> първи елемент
// AC: O(n/2) -> O(n) -> някъде по средата
// WC: O(n) -> последен елемент
bool linear_search(const int arr[], int n, int element)
{
    for(int i = 0; i < n; i++)
    {
        if (arr[i] == element)
        {
            return true;
        }
    }

    return false;
}

// Time complexity:
// B.C.: O(1)
// A.C.: O(log(n))
// W.C.: O(log(n))
// Space complexity: O(1)
int binary_search(int sortedArray[], int n, int element)
{
    int start = 0;
    int end = n - 1;
    int mid = (start + end) / 2;

	while (start <= end)
	{
		mid = (start + end) / 2;
		if (sortedArray[mid] == element)
		{
            return mid;
        }

		if (sortedArray[mid] > element)
		{
            end = mid - 1;
        }

        else
		{
            start = mid + 1;
	    }
    }

	return -1;
}

// Time complexity:
// B.C.: O(1)
// A.C.: O(log(n))
// W.C.: O(log(n))
// Space complexity: O(log(n))
int binary_search_recursive(int* arr, int start, int end, int element)
{
	if (start > end)
	{
        return -1;
    }

	int mid = (start + end) / 2;

    if (arr[mid] == element)
	{
        return mid;
    }

	if (arr[mid] > element)
	{
        return binary_search_recursive(arr, start, mid - 1, element);
    }
	else
	{
        return binary_search_recursive(arr, mid + 1, end, element);
    }
}

// Time complexity:
// B.C.: O(1)
// A.C.: O(log(n))
// W.C.: O(log(n))
// Space complexity: O(1)
int sum_powers_of_two_until_n(int n)
{
	int res = 0;
	for (int i = 1; i <= n; i *= 2)
	{
		res += i;
	}
    return res;
}

// 1 -> sum: 1
// 1,2 -> sum: 3
// 1,2,4 -> sum: 7
// 1,2,4,8 -> sum: 15
int sum_powers_of_two_until_n_const(int n) // 1000 = 15 // n = 5;  1 2 4: 7 // n = 17; 1 2 4 8 16 => 31; 32 - 1 // 10001
{
    return; // 2^(k+1) - 1
} // https://math.stackexchange.com/questions/1990137/the-idea-behind-the-sum-of-powers-of-2 - proof

// Time complexity:
// B.C.: O(1)
// A.C.: O(log(n))
// W.C.: O(log(n))
// Space complexity: O(1)
bool is_power_of_two(int n) // n = 16 -> 8 -> 4 -> 2 -> 1 -> 0
{
	while (n > 1)
	{
		if (n % 2 == 1) // 46 / 2 = 23
		{
            return false;
        }

		n /= 2; // 16 / 8
	}
	return true;
}

// n е степен на двойката когато двоичната му репрезентация съдържа 1 единица
// Ако n e степен на 2 =>  n-1 = 011...11
// Тогава единствения случай с побитово И => n & (n - 1) ще дава лъжа
// Трябва да гарантираме и че n != 0.

// Time complexity: O(1)
bool is_power_of_two_constant(int n)
{
    return n && !(n & (n-1));
}

// Time complixity: O(n + m) = O(max{n,m})
// Space complexity: O(1)
int count_of_odd_numbers(const int arr1[], const int n, const int arr2[], const int m)
{
    int oddCount1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr1[i] % 2)
        {
            oddCount1++;
        }
    }

    int oddCount2 = 0;
    for (int i = 0; i < m; i++)
    {
         if (arr2[i] % 2)
        {
            oddCount2++;
        }
    }

    return oddCount1 + oddCount2;
}

// 1 2 3 4
// 6 7 8 3

// Time complexity:
// B.C.: O(1)
// A.C.: O(n^2)
// W.C.: O(n^2)
bool contain_shared_element(const int arr1[], int n, const int arr2[], int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr1[i] == arr2[j])
            {
                return true;
            }
        }
    }

    return false;
}

// Time complexity: O(n^3)
int triple_sum_zero_count(const int arr[], const int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == 0)
                {
                    count++;
                }
            }
        }
    }
    return count;
}

// Time complexity:
// BC: O(1)
// AC: O(n^3)
// WC: O(n^3)
bool contains_triple_sum_zero(const int arr[], const int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == 0)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

void swap(char* a, char* b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

// 1 2 3 => 1 2 3, 1 3 2, 2 1 3, 2 3 1, 3 1 2, 3 2 1 => n! permutations for n elements
// Time complexity:
// B.C.: O(1)
// A.C.: O(n!)
// W.C.: O(n!)
bool are_permutations(char word1[], char word2[], const int size, int index)
{
    if(index + 1 == size)
    {
        return strcmp(word1, word2) == 0;
    }

    for (int i = index; i < size; i++)
    {
        swap(&word1[i], &word1[index]);
        if (are_permutations(word1, word2, size, index + 1))
        {
            return true;
        }
        swap(&word1[i], &word1[index]);
    }
    return false;
}

// Time complexity: O(sorting-alg-complexity + n) = O(sorting-alg-complexity) // minimum: O(n*log(n))
bool are_permutations_with_sort(char word1[], char word2[], const int size)
{
    sort(word1, size);
    sort(word2, size);

    for (int i = 0; i < size; i++)
    {
        if (word1[i] != word2[i])
            return false;
    }
    return true;
}

// Time complexity: O(n)
bool are_permutations_with_histogram(const char word1[], const char word2[], const int size)
{
    const int character_count = 256;
    int histogram_word1[character_count] = {};
    int histogram_word2[character_count] = {};
    for (int i = 0; i < size; i++)
    {
        histogram_word1[word1[i]]++;
        histogram_word2[word2[i]]++;
    }

    for (int i = 0; i < character_count; i++)
    {
        if (histogram_word1[i] != histogram_word2[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{

    return 0;
}
