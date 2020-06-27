// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/21 11:06)

#ifndef CORE_MEMORY_TOOLS_POOL_DETAIL_H
#define CORE_MEMORY_TOOLS_POOL_DETAIL_H

#include "Pool.h"
#include "System/Helper/UnusedMacro.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"
#include <functional>
#include <algorithm>

template<class T>
CoreTools::Pool<T>
	::Pool()
	:m_Store{}, m_AllocatedCount{ 0 }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

template<class T>
CoreTools::Pool<T>
	::~Pool()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;

	CORE_TOOLS_ASSERTION_1(m_AllocatedCount == 0, "对象池析构时还有内存未释放！");

	FreeAll();
}

#ifdef OPEN_CLASS_INVARIANT
template<class T>
bool CoreTools::Pool<T>
	::IsValid() const noexcept
{
	if (0 <= m_AllocatedCount)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template<class T>
T* CoreTools::Pool<T>
	::Get()
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	auto ptr = GetConformCondition();

	++m_AllocatedCount;

	if (ptr != nullptr)
	{
		return ptr;
	}
	else
	{
		// 没有可用的结构

		return DoGet();
	}
}

// private
template<class T>
T* CoreTools::Pool<T>
	::DoGet()
{
	return NEW0 T;
}

// private
template<class T>
T* CoreTools::Pool<T>
	::GetConformCondition()
{
	// 寻找一个足够大的缓冲区
	auto iter = std::find_if(m_Store.begin(), m_Store.end(), std::bind(&ClassType::ConformCondition, this, std::placeholders::_1));
	if (iter != m_Store.end())
	{
		auto ptr = *iter;
		m_Store.erase(iter);

		return ptr;
	}
	else
	{
		return nullptr;
	}
}

// private
template<class T>
bool CoreTools::Pool<T>
	::ConformCondition(T* ptr)
{
	SYSTEM_UNUSED_ARG(ptr);

	return true;
}

template<class T>
void CoreTools::Pool<T>
	::Release(T* ptr)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	--m_AllocatedCount;

	m_Store.push_front(ptr);
}

template<class T>
void CoreTools::Pool<T>
	::FreeAll()
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	for (auto ptr : m_Store)
	{
		DELETE0(ptr);
	}

	m_Store.clear();
	m_AllocatedCount = 0;
}

template<class T>
int CoreTools::Pool<T>
	::GetAvailableCount() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return boost::numeric_cast<int>(m_Store.size());
}

template<class T>
int CoreTools::Pool<T>
	::GetAllocatedCount() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_AllocatedCount;
}

template<class T>
int CoreTools::Pool<T>
	::GetTotalCount() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return GetAvailableCount() + GetAllocatedCount();
}

#endif // CORE_MEMORY_TOOLS_POOL_DETAIL_H
