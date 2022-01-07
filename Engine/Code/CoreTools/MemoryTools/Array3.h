///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/28 20:52)

#ifndef CORE_TOOLS_MEMORY_TOOLS_ARRAY3_H
#define CORE_TOOLS_MEMORY_TOOLS_ARRAY3_H

#include "CoreTools/CoreToolsDll.h"

#include <vector>

namespace CoreTools
{
    template <typename T>
    class Array3 final
    {
    public:
        using ClassType = Array3<T>;

    public:
        Array3(size_t bound0, size_t bound1, size_t bound2);

        CLASS_INVARIANT_DECLARE;

        size_t GetBound0() const noexcept;
        size_t GetBound1() const noexcept;
        size_t GetBound2() const noexcept;

        T* const* operator[](int slice) const noexcept;
        T** operator[](int slice) noexcept;

    private:
        void SetPointers();

    private:
        size_t bound0;
        size_t bound1;
        size_t bound2;
        std::vector<T> objects;
        std::vector<T*> indirect1;
        std::vector<T**> indirect2;
    };
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_ARRAY3_H
