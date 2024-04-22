/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 14:45)

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

        using ResultContainer = std::vector<Value>;

    public:
        ThreadSafeMap() noexcept = default;
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
        NODISCARD ResultContainer GatherAll() const;

    private:
        using ContainerType = std::map<Key, Value>;

    private:
        NODISCARD ContainerType GetThreadSafeMap() const;

    private:
        ContainerType threadSafeMap;
        mutable std::mutex mutex;
    };
}

#endif  // CORE_TOOLS_DATA_TYPE_THREAD_SAFE_MAP_H