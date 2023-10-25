///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/21 09:33)

#ifndef CORE_TOOLS_MEMORY_TOOLS_ARRAY4_H
#define CORE_TOOLS_MEMORY_TOOLS_ARRAY4_H

#include "CoreTools/CoreToolsDll.h"

#include <vector>

namespace CoreTools
{
    template <typename T>
    class Array4 final
    {
    public:
        using ClassType = Array4<T>;

    public:
        Array4(int bound0, int bound1, int bound2, int bound3);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetBound0() const noexcept;
        NODISCARD int GetBound1() const noexcept;
        NODISCARD int GetBound2() const noexcept;
        NODISCARD int GetBound3() const noexcept;

        NODISCARD T** const* operator[](int cuboid) const;
        NODISCARD T*** operator[](int cuboid);

    private:
        void SetPointers();
        NODISCARD constexpr static int GetObjectSize(int bound0, int bound1) noexcept
        {
            return bound0 * bound1;
        }
        NODISCARD constexpr static int GetObjectSize(int bound0, int bound1, int bound2) noexcept
        {
            return bound0 * bound1 * bound2;
        }
        NODISCARD constexpr static int GetObjectSize(int bound0, int bound1, int bound2, int bound3) noexcept
        {
            return bound0 * bound1 * bound2 * bound3;
        }

    private:
        int bound0;
        int bound1;
        int bound2;
        int bound3;
        std::vector<T> objects;
        std::vector<T*> indirect1;
        std::vector<T**> indirect2;
        std::vector<T***> indirect3;
    };
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_ARRAY4_H
