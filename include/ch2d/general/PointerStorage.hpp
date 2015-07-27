#ifndef CH2D_POINTERSTORAGE_H
#define CH2D_POINTERSTORAGE_H

// Standard library
#include <memory>
#include <stack>
#include <vector>

namespace ch2d
{
	template <class T>
	class PointerStorage
	{
	public:
		// Add the shared pointer to the vector
		// Arguments: The shared pointer to be added to the vector
		// Returns: Integer used to identify the shared pointer
		unsigned int add(std::shared_ptr<T>);

		// Removes the shared pointer from the vector
		// Arguments: The integer provided by the add() method
		// Returns: Whether or not the shared pointer was successfully removed
		bool remove(unsigned int);

		// Gets the shared pointer from the vector
		// Arguments: The integer provided by the add() method
		// Returns: The shared pointer
		std::shared_ptr<T> get(unsigned int) const;

	private:
		// List of free spaces in the storage vector
		std::stack<unsigned int> mFreelist;

		// Vector to store shared pointers
		std::vector<std::shared_ptr<T> > mPointers;
	};

	template <class T>
	unsigned int PointerStorage<T>::add(std::shared_ptr<T> ref)
	{
		// Integer used to locate pointer in storage vector
		unsigned int id = 0;

		// If there are any free locations in the storage vector
		if(mFreelist.size() > 0)
		{
			// Get the id of the free space
			id = mFreelist.top();

			// Remove the free space from the freelist
			mFreelist.pop();

			// Overwrite shared pointer at this position
			mPointers[id] = ref;
		}
		else
		{
			// Get the position of the shared pointer
			id = mPointers.size();

			// Push the shared pointer
			mPointers.push_back(ref);
		}

		// Return the location of the shared pointer in the storage vector
		return id;
	}

	template <class T>
	bool PointerStorage<T>::remove(unsigned int id)
	{
		// If provided id is outside the bounds of the storage vector
		if(id > mPointers.size())
		{
			return false;
		}
		else
		{
			// If pointer at the position provided by id is valid
			if(nullptr == mPointers.at(id))
			{
				return false;
			}
			else
			{
				mPointers.at(id) = nullptr;
				return true;
			}
		}
	}

	template <class T>
	std::shared_ptr<T> PointerStorage<T>::get(unsigned int id) const
	{
		// If provided id is outside the bounds of the storage vector
		if(id > mPointers.size())
		{
			return nullptr;
		}
		else
		{
			// If pointer at the position provided by id is valid
			if(nullptr == mPointers.at(id))
			{
				return nullptr;
			}
			else
			{
				return mPointers.at(id);
			}
		}
	}
}

#endif
