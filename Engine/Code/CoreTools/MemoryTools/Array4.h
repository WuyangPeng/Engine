///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/29 10:38)

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
        Array4(size_t bound0, size_t bound1, size_t bound2, size_t bound3);

        CLASS_INVARIANT_DECLARE;

        NODISCARD size_t GetBound0() const noexcept;
        NODISCARD size_t GetBound1() const noexcept;
        NODISCARD size_t GetBound2() const noexcept;
        NODISCARD size_t GetBound3() const noexcept;

        NODISCARD T** const* operator[](int cuboid) const noexcept;
        NODISCARD T*** operator[](int cuboid) noexcept;

    private:
        void SetPointers();

    private:
        size_t bound0;
        size_t bound1;
        size_t bound2;
        size_t bound3;
        std::vector<T> objects;
        std::vector<T*> indirect1;
        std::vector<T**> indirect2;
        std::vector<T***> indirect3;
    };
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_ARRAY4_H
