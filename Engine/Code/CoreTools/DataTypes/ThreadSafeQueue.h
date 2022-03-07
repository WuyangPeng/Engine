///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/12 18:03)

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
        ThreadSafeQueue(size_t maxNumElements = 0) noexcept;
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
        NODISCARD std::queue<Element> GetThreadSafeQueue() const;

    private:
        size_t maxNumElements;
        std::queue<Element> queue;
        mutable std::mutex mutex;
    };
}

#endif  // CORE_TOOLS_DATA_TYPE_THREAD_SAFE_QUEUE_H