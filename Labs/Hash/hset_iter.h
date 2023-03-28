#ifndef HSET_ITER_H_INCLUDED
#define HSET_ITER_H_INCLUDED

#include <list>
#include <vector>
#include <iterator>	// for next()

// Each hset_iter contains a reference to its associated hash,
// and an size_t indicating progress within the hash.

template <typename T>
class hset_iter {
    using table_t = typename std::vector<std::list<T>>;
    const table_t *parent;  // pointer to the hash table we’re iterating over
    size_t num;		    // how far along we are.  0=first item
    size_t n;

  public:
    hset_iter(const table_t *table, size_t n) : parent(table), num(n) , n(0){ }

    bool operator==(const hset_iter &rhs) const {
	return num == rhs.num && n == rhs.n;
    }

    bool operator!=(const hset_iter &rhs) const {
	return !(*this == rhs);
    }

    // Return a pointer to the num'th element,
    // where num==0 is the first element.

    T operator*() const { //Exercise 4
	return *next((*parent)[num].begin(), n);
    }
	
/*	// First, find the right list:*/
/*	auto remaining = num;*/
/*	size_t vector_index;*/
/*	size_t list_index;*/
/*	for (index=0; (*parent)[index].size() <= remaining; index++)*/
/*	    remaining -= (*parent)[index].size();*/
/*	*/
/*	// Second, find the right slot within that list:*/
/*	return *next((*parent)[index].begin(), remaining);*/
 

    // Pre-increment (usually returns a reference to the iterator)
    void operator++() {
	++n;
	if(n == (*parent)[num].size() && num < parent->size()) {
		n = 0;
		++num;	
	}
    }
};

#endif /* HSET_ITER_H_INCLUDED */
