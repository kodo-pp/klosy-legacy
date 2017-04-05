#ifndef __cplusplus
#error this file MUST be compiled with g++
#endif

#ifndef CPP_LIST_HPP
#define CPP_LIST_HPP

#include <stdlib.h>
#include <list.h>
#include <cpp/allocator.hpp>

template <typename T> class List
{
	protected:
		list _ls;
		size_t _len;
	public:
		List()
		{
			_len = 0;
			_ls = null
		}
		
		bool insert_next(T elem)
		{
			void *elem_ptr = new T;
			if (elem_ptr == null)
			{
				return false;
			}
			cppmemfree
			
		}
};

#endif
