///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/29 10:38)

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
        Array2(int bound0, int bound1);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetBound0() const noexcept;
        NODISCARD int GetBound1() const noexcept;

        NODISCARD const T* operator[](int row) const;
        NODISCARD T* operator[](int row);

    private:
        void SetPointers();
        NODISCARD constexpr static int GetObjectSize(int bound0, int bound1) noexcept
        {
            return bound0 * bound1;
        }

    private:
        int bound0;
        int bound1;
        std::vector<T> objects;
        std::vector<T*> indirect;
    };
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_ARRAY2_H
