#include<unordered_map>
#include<exception>

template <typename T>
class QuickFind
{
private:
	int* sets; 
	std::unordered_map<T, int> dictionary;
	int length;

public:
	QuickFind(T values[], int length)
	{
		this->length = length;
		sets = new int[length];
		dictionary = std::unordered_map<T, int>();
		for (int i = 0; i < length ; i ++)
		{
			dictionary.insert(std::pair<T, int>(values[i], i));
			sets[i] = i;
		}
	}

	~QuickFind()
	{
		delete sets;
	}

	int Find(T value)
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
		int oldSet = Find(p);
		int newSet = Find(q);
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
	int* sets;
	std::unordered_map<T, int> dictionary;
	int length;

public:
	QuickUnion(T values[], int length)
	{
		this->length = length;
		sets = new int[length];
		dictionary = std::unordered_map<T, int>();
		for (int i = 0; i < length; i++)
		{
			dictionary.insert(std::pair<T, int>(values[i], i));
			sets[i] = i;
		}
	}

	~QuickUnion()
	{
		delete sets;
	}

	int Find(T value, int& depth)
	{
		if (!dictionary.contains(value))
		{
			return -1;
		}
		depth = 0;
		int currentIndex = dictionary[value];
		while (sets[currentIndex] != currentIndex)
		{
			depth++;
			currentIndex = sets[currentIndex];
		}
		return currentIndex;
	}

	int Find(T value)
	{
		int bla;
		return Find(value, bla);
	}


	bool Union(T p, T q)
	{
		if (!dictionary.contains(p) || !dictionary.contains(q))
		{
			return false;
		}
		
		int depth1;
		int set1 = Find(p, depth1);
		int depth2;
		int set2 = Find(q, depth2);
		if (set1 == set2)
		{
			return false;
		}

		int newSet;
		int oldSet;
		if (depth1 < depth2)
		{
			newSet = set1;
			oldSet = set2;
		}
		else
		{
			newSet = set2;
			oldSet = set1;
		}

		sets[oldSet] = newSet;
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
