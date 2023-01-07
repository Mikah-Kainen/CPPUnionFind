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
	QuickFind(T values[])
	{
		length = sizeof(values) / sizeof(T);
		if (length == 0)
		{
			throw std::exception("Don't do this");
		}
		sets = new int[length];
		dictionary = std::unordered_map<T, int>();
		for (int i = 0; i < length ; i ++)
		{
			dictionary.insert(std::pair<T, int>(values[i], i));
			sets[i] = i;
		}
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
		if (Find(p) == Find(q))
		{
			return true;
		}
		int oldSet = Find(p);
		int newSet = Find(q);
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

};
