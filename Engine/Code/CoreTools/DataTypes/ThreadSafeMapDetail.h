/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.5 (2024/01/25 09:37)

#ifndef CORE_TOOLS_DATA_TYPE_THREAD_SAFE_MAP_DETAIL_H
#define CORE_TOOLS_DATA_TYPE_THREAD_SAFE_MAP_DETAIL_H

#include "ThreadSafeMap.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#ifdef OPEN_CLASS_INVARIANT

template <typename Key, typename Value>
bool CoreTools::ThreadSafeMap<Key, Value>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Key, typename Value>
CoreTools::ThreadSafeMap<Key, Value>::ThreadSafeMap(const ThreadSafeMap& rhs)
    : threadSafeMap{ rhs.GetThreadSafeMap() }, mutex{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename Key, typename Value>
std::map<Key, Value> CoreTools::ThreadSafeMap<Key, Value>::GetThreadSafeMap() const
{
    const std::unique_lock holder{ mutex };

    return threadSafeMap;
}

template <typename Key, typename Value>
CoreTools::ThreadSafeMap<Key, Value>& CoreTools::ThreadSafeMap<Key, Value>::operator=(const ThreadSafeMap& rhs)
{
    const std::unique_lock holder{ mutex };

    CORE_TOOLS_CLASS_IS_VALID_9;

    if (this != &rhs)
    {
        threadSafeMap = rhs.GetThreadSafeMap();
    }

    return *this;
}

template <typename Key, typename Value>
CoreTools::ThreadSafeMap<Key, Value>::ThreadSafeMap(ThreadSafeMap&& rhs) noexcept
    : threadSafeMap{ std::move(rhs.threadSafeMap) }, mutex{ std::move(rhs.mutex) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename Key, typename Value>
CoreTools::ThreadSafeMap<Key, Value>& CoreTools::ThreadSafeMap<Key, Value>::operator=(ThreadSafeMap&& rhs) noexcept
{
    const std::unique_lock holder{ mutex };

    CORE_TOOLS_CLASS_IS_VALID_9;

    if (this != &rhs)
    {
        threadSafeMap = std::move(rhs.threadSafeMap);
    }

    return *this;
}

template <typename Key, typename Value>
bool CoreTools::ThreadSafeMap<Key, Value>::HasElements() const
{
    const std::unique_lock holder{ mutex };

    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return !threadSafeMap.empty();
}

template <typename Key, typename Value>
bool CoreTools::ThreadSafeMap<Key, Value>::Exists(KeyParamType key) const
{
    const std::unique_lock holder{ mutex };

    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return threadSafeMap.contains(key);
}

template <typename Key, typename Value>
void CoreTools::ThreadSafeMap<Key, Value>::Insert(KeyParamType key, ValueParamType value)
{
    const std::unique_lock holder{ mutex };

    CORE_TOOLS_CLASS_IS_VALID_9;

    threadSafeMap[key] = value;
}

template <typename Key, typename Value>
bool CoreTools::ThreadSafeMap<Key, Value>::Remove(KeyParamType key)
{
    const std::unique_lock holder{ mutex };

    CORE_TOOLS_CLASS_IS_VALID_9;

    return 0 < threadSafeMap.erase(key);
}

template <typename Key, typename Value>
void CoreTools::ThreadSafeMap<Key, Value>::RemoveAll()
{
    const std::unique_lock holder{ mutex };

    CORE_TOOLS_CLASS_IS_VALID_9;

    threadSafeMap.clear();
}

template <typename Key, typename Value>
Value CoreTools::ThreadSafeMap<Key, Value>::Get(KeyParamType key) const
{
    const std::unique_lock holder{ mutex };

    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (const auto iter = threadSafeMap.find(key);
        iter != threadSafeMap.cend())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("未找到指定元素。\n"s))
    }
}

template <typename Key, typename Value>
typename CoreTools::ThreadSafeMap<Key, Value>::ResultContainer CoreTools::ThreadSafeMap<Key, Value>::GatherAll() const
{
    const std::unique_lock holder{ mutex };

    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    ResultContainer result{};

    result.reserve(threadSafeMap.size());
    for (const auto& value : threadSafeMap)
    {
        result.emplace_back(value.second);
    }

    return result;
}

#endif  // CORE_TOOLS_DATA_TYPE_THREAD_SAFE_MAP_DETAIL_H