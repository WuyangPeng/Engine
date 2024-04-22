/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 14:47)

#ifndef CORE_TOOLS_DATA_TYPE_THREAD_SAFE_QUEUE_DETAIL_H
#define CORE_TOOLS_DATA_TYPE_THREAD_SAFE_QUEUE_DETAIL_H

#include "ThreadSafeQueue.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Element>
CoreTools::ThreadSafeQueue<Element>::ThreadSafeQueue(int maxNumElements) noexcept
    : maxNumElements{ maxNumElements }, queue{}, mutex{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename Element>
std::queue<Element> CoreTools::ThreadSafeQueue<Element>::GetThreadSafeQueue() const
{
    const std::unique_lock holder{ mutex };

    return queue;
}

template <typename Element>
CoreTools::ThreadSafeQueue<Element>::ThreadSafeQueue(const ThreadSafeQueue& rhs)
    : maxNumElements{ rhs.maxNumElements }, queue{ rhs.GetThreadSafeQueue() }, mutex{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename Element>
CoreTools::ThreadSafeQueue<Element>& CoreTools::ThreadSafeQueue<Element>::operator=(const ThreadSafeQueue& rhs)
{
    const std::unique_lock holder{ mutex };

    CORE_TOOLS_CLASS_IS_VALID_9;

    if (this != &rhs)
    {
        maxNumElements = rhs.maxNumElements;
        queue = rhs.GetThreadSafeQueue();
    }

    return *this;
}

template <typename Element>
CoreTools::ThreadSafeQueue<Element>::ThreadSafeQueue(ThreadSafeQueue&& rhs) noexcept
    : maxNumElements{ rhs.maxNumElements }, queue{ std::move(rhs.queue) }, mutex{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename Element>
CoreTools::ThreadSafeQueue<Element>& CoreTools::ThreadSafeQueue<Element>::operator=(ThreadSafeQueue&& rhs) noexcept
{
    const std::unique_lock holder{ mutex };

    CORE_TOOLS_CLASS_IS_VALID_9;

    if (this != &rhs)
    {
        maxNumElements = rhs.maxNumElements;
        queue = std::move(rhs.queue);
    }

    return *this;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Element>
bool CoreTools::ThreadSafeQueue<Element>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Element>
int CoreTools::ThreadSafeQueue<Element>::GetMaxNumElements() const
{
    const std::unique_lock holder{ mutex };

    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return maxNumElements;
}

template <typename Element>
int CoreTools::ThreadSafeQueue<Element>::GetNumElements() const
{
    const std::unique_lock holder{ mutex };

    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(queue.size());
}

template <typename Element>
bool CoreTools::ThreadSafeQueue<Element>::Push(ParamType element)
{
    const std::unique_lock holder{ mutex };

    CORE_TOOLS_CLASS_IS_VALID_9;

    if (boost::numeric_cast<int>(queue.size()) < maxNumElements)
    {
        queue.emplace(element);

        return true;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("容器已满。\n"s))
    }
}

template <typename Element>
typename CoreTools::ThreadSafeQueue<Element>::PopResultType CoreTools::ThreadSafeQueue<Element>::Pop()
{
    const std::unique_lock holder{ mutex };

    CORE_TOOLS_CLASS_IS_VALID_9;

    if (!queue.empty())
    {
        const auto element = queue.front();
        queue.pop();

        return { element, true };
    }
    else
    {
        return { Element{}, false };
    }
}

#endif  // CORE_TOOLS_DATA_TYPE_THREAD_SAFE_QUEUE_DETAIL_H