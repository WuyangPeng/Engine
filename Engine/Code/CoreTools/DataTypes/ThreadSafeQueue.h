///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/23 14:35)

#ifndef CORE_TOOLS_DATA_TYPE_THREAD_SAFE_QUEUE_H
#define CORE_TOOLS_DATA_TYPE_THREAD_SAFE_QUEUE_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/TemplateTools/ParamType.h"

#include <mutex>
#include <queue>

namespace CoreTools
{
    template <typename Element>
    class ThreadSafeQueue final
    {
    public:
        using ClassType = ThreadSafeQueue<Element>;
        using ParamType = typename ParamType<Element>::type;
        using PopResultType = std::pair<Element, bool>;

    public:
        explicit ThreadSafeQueue(size_t maxNumElements = 0) noexcept;
        ~ThreadSafeQueue() = default;
        ThreadSafeQueue(const ThreadSafeQueue& rhs);
        ThreadSafeQueue& operator=(const ThreadSafeQueue& rhs);
        ThreadSafeQueue(ThreadSafeQueue&& rhs) noexcept;
        ThreadSafeQueue& operator=(ThreadSafeQueue&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD size_t GetMaxNumElements() const;
        NODISCARD size_t GetNumElements() const;
        NODISCARD bool Push(ParamType element);
        NODISCARD PopResultType Pop();

    private:
        using ElementType = std::queue<Element>;

    private:
        NODISCARD ElementType GetThreadSafeQueue() const;

    private:
        size_t maxNumElements;
        ElementType queue;
        mutable std::mutex mutex;
    };
}

#endif  // CORE_TOOLS_DATA_TYPE_THREAD_SAFE_QUEUE_H