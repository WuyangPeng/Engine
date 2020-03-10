// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/20 16:42)

#ifndef CORE_TOOLS_MEMORY_TOOLS_POOL_H
#define CORE_TOOLS_MEMORY_TOOLS_POOL_H

// 对象池保持先前分配对象的列表，从而使经常重复使用的对象没有被释放而导致不断的重新分配。
// 该对象池跟踪的类必须有一个无参数的构造函数。所以，它最适合简单的结构。

// 当对象被释放时，它们被添加到对象池的空闲列表。为避免内存泄漏，所有未分配的对象应该被释放，
// 所以当对象池被删除时，所有内存将被释放。也可以随时调用FreeAll复位释放对象池。

#include "CoreTools/CoreToolsDll.h"

#include <boost/noncopyable.hpp>
#include <list>

namespace CoreTools
{
	template<class T>
	class Pool : private boost::noncopyable
	{
	public:
		using ClassType = Pool;

	public:
		Pool();
		virtual ~Pool();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		// 如果可能的话，从空闲的存储中获得对象，否则就重新分配它。
		virtual T* Get();

		virtual void Release(T* ptr);

		void FreeAll();

		int GetAvailableCount() const;
		int GetAllocatedCount() const noexcept;
		int GetTotalCount() const;

	protected:
		using StoreType = std::list<T*>;

	private:
		T* GetConformCondition();
		virtual bool ConformCondition(T* ptr);
		virtual T* DoGet();

	private:
		StoreType m_Store;
		int m_AllocatedCount;
	};
}

#endif // CORE_TOOLS_MEMORY_TOOLS_POOL_H
