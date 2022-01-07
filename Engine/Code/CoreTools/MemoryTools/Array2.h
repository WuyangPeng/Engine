///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/28 20:52)

#ifndef CORE_TOOLS_MEMORY_TOOLS_ARRAY2_H
#define CORE_TOOLS_MEMORY_TOOLS_ARRAY2_H

#include "CoreTools/CoreToolsDll.h"

#include <vector>

namespace CoreTools
{
    template <typename T>
    class Array2 final
    {
    public:
        using ClassType = Array2<T>;

    public:
        Array2(size_t bound0, size_t bound1);

        CLASS_INVARIANT_DECLARE;

        size_t GetBound0() const noexcept;
        size_t GetBound1() const noexcept;

        T const* operator[](int row) const noexcept;
        T* operator[](int row) noexcept;

    private:
        void SetPointers();

    private:
        size_t bound0;
        size_t bound1;
        std::vector<T> objects;
        std::vector<T*> indirect;
    };
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_ARRAY2_H
