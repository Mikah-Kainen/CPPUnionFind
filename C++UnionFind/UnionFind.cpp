#include<unordered_map>
#include<exception>

template <typename T>
class QuickFind
{
private:
	std::pair<int, int>* sets;
	std::unordered_map<T, int> dictionary;
	int length;

public:
	QuickFind(T values[], int length)
	{
		this->length = length;
		sets = new std::pair<int, int>[length];
		dictionary = std::unordered_map<T, int>();
		for (int i = 0; i < length; i++)
		{
			dictionary.insert(std::pair<T, int>(values[i], i));
			sets[i] = std::pair<int, int>(i, 0);
		}
	}

	~QuickFind()
	{
		delete[] sets;
	}

	std::pair<int, int> Find(T value)
	{
		if (!dictionary.contains(value))
		{
			return -1;
		}
		return sets[dictionary[value]];
	}

	bool Union(T p, T q)
	{
		if (!dictionary.contains(p) || !dictionary.contains(q))
		{
			return false;
		}
		std::pair<int, int> oldSet = Find(p);
		std::pair<int, int> newSet = Find(q);
		if (oldSet == newSet)
		{
			return false;
		}
		bool didChange = false;
		for (int i = 0; i < length; i++)
		{
			if (sets[i] == oldSet)
			{
				sets[i] = newSet;
				didChange = true;
			}
		}
		if (!didChange)
		{

		}
		return true;
	}

	bool AreConnected(T p, T q)
	{
		if (!dictionary.contains(p) || !dictionary.contains(q))
		{
			return false;
		}
		return Find(p) == Find(q);
	}

};


template <typename T>
class QuickUnion
{
private:
	std::pair<int, int>* sets;
	std::unordered_map<T, int> dictionary;
	int length;

public:
	QuickUnion(T values[], int length)
	{
		this->length = length;
		sets = new std::pair<int, int>[length];
		dictionary = std::unordered_map<T, int>();
		for (int i = 0; i < length; i++)
		{
			dictionary.insert(std::pair<T, int>(values[i], i));
			sets[i] = std::pair<int, int>(i, 0);
		}
	}

	~QuickUnion()
	{
		delete[] sets;
	}

	std::pair<int, int> Find(T value)
	{
		if (!dictionary.contains(value))
		{
			return std::pair<int, int>(-1, -1);
		}

		int currentIndex = dictionary[value];
		while (sets[currentIndex].first != currentIndex)
		{
			currentIndex = sets[currentIndex].first;
		}
		return sets[currentIndex];
	}


	bool Union(T p, T q)
	{
		if (!dictionary.contains(p) || !dictionary.contains(q))
		{
			return false;
		}

		std::pair<int, int> set1 = Find(p);
		std::pair<int, int> set2 = Find(q);
		if (set1 == set2)
		{
			return false;
		}

		if (set1.second == set2.second)
		{
			set2 = std::pair<int, int>(set2.first, set2.second + 1);
			sets[set2.first] = set2;
			sets[set1.first] = set2;
		}
		else if (set1.second > set2.second)
		{
			sets[set2.first] = set1;
		}
		else
		{
			sets[set1.first] = set2;
		}

		return true;
	}

	bool AreConnected(T p, T q)
	{
		if (!dictionary.contains(p) || !dictionary.contains(q))
		{
			return false;
		}
		return Find(p) == Find(q);
	}
};
