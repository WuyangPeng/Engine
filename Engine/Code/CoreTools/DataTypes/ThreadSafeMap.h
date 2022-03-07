///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/12 16:05)

#ifndef CORE_TOOLS_DATA_TYPE_THREAD_SAFE_MAP_H
#define CORE_TOOLS_DATA_TYPE_THREAD_SAFE_MAP_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/TemplateTools/ParamType.h"

#include <map>
#include <mutex>
#include <vector>

namespace CoreTools
{
    template <typename Key, typename Value>
    class ThreadSafeMap final
    {
    public:
        using ClassType = ThreadSafeMap<Key, Value>;
        using KeyParamType = typename ParamType<Key>::type;
        using ValueParamType = typename ParamType<Value>::type;

    public:
        ThreadSafeMap() = default;
        ~ThreadSafeMap() noexcept = default;
        ThreadSafeMap(const ThreadSafeMap& rhs);
        ThreadSafeMap& operator=(const ThreadSafeMap& rhs);
        ThreadSafeMap(ThreadSafeMap&& rhs) noexcept;
        ThreadSafeMap& operator=(ThreadSafeMap&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool HasElements() const;
        NODISCARD bool Exists(KeyParamType key) const;
        void Insert(KeyParamType key, ValueParamType value);
        NODISCARD bool Remove(KeyParamType key);
        void RemoveAll();
        NODISCARD Value Get(KeyParamType key) const;
        NODISCARD std::vector<Value> GatherAll() const;

    private:
        NODISCARD std::map<Key, Value> GetThreadSafeMap() const;

    private:
        std::map<Key, Value> threadSafeMap;
        mutable std::mutex mutex;
    };
}

#endif  // CORE_TOOLS_DATA_TYPE_THREAD_SAFE_MAP_H