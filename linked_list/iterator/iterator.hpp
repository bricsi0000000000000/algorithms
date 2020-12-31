#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "../node.hpp"

namespace Ricsi{
	/**
	 * @struct Iterator
	 * @brief Iterator for LinkedList
	*/
	template <typename U>
	struct Iterator{
		/**
		 * Constructor for Iterator.
		*/
		Iterator(Node<U>* ptr);

		U& operator*() const;

		U* operator->();

		// Prefix increments
		Iterator& operator++();
		Iterator& operator--();

		// Postfix increments
		Iterator operator++(U);
		Iterator operator--(U);

		friend bool operator== (const Iterator<U>& a, const Iterator<U>& b) {return a.item == b.item; }
		friend bool operator!= (const Iterator<U>& a, const Iterator<U>& b) {return a.item != b.item; }

	private:
		Node<U>* item;
	};
}

#endif //ITERATOR_HPP