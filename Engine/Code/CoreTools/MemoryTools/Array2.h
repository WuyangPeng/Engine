///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/04/24 16:20)

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
        Array2() noexcept;
        Array2(size_t bound0, size_t bound1);

        CLASS_INVARIANT_DECLARE;

        NODISCARD size_t GetBound0() const noexcept;
        NODISCARD size_t GetBound1() const noexcept;

        NODISCARD T const* operator[](int row) const noexcept;
        NODISCARD T* operator[](int row) noexcept;

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
