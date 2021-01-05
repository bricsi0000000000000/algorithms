#ifndef DYNAMIC_ARRAY_ITERATOR_HPP
#define DYNAMIC_ARRAY_ITERATOR_HPP

namespace Ricsi{

	template <typename U> struct DynamicArrayIterator{
		DynamicArrayIterator(U* ptr);

		U& operator*() const;
    U* operator->();

		// Prefix increments
		DynamicArrayIterator& operator++();
		DynamicArrayIterator& operator--();

		// Postfix increments
		DynamicArrayIterator operator++(U);
		DynamicArrayIterator operator--(U);


    friend bool operator== (const DynamicArrayIterator<U>& a, const DynamicArrayIterator<U>& b) { return a.item == b.item; };
    friend bool operator!= (const DynamicArrayIterator<U>& a, const DynamicArrayIterator<U>& b) { return a.item != b.item; };  

	private:
		U* item;
	};
}

#endif //DYNAMIC_ARRAY_ITERATOR_HPP