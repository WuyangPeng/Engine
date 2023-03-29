///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/23 10:35)

#ifndef CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_H
#define CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_H

#include "CoreTools/CoreToolsDll.h"

#include <type_traits>

namespace CoreTools
{
    // 储存的是唯一标识索引UniqueIndex
    template <typename Generator, typename Scalar>
    class MinHeapRecord final
    {
    public:
        static_assert(std::is_scalar_v<Scalar>, "Scalar must be scalar");

        using ClassType = MinHeapRecord<Generator, Scalar>;

    public:
        MinHeapRecord() noexcept;
        MinHeapRecord(int uniqueIndex, Scalar initialValue) noexcept;
        MinHeapRecord(int uniqueIndex, Generator generator, Scalar initialValue) noexcept(std::is_scalar_v<Generator>);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Generator GetGenerator() const noexcept(std::is_scalar_v<Generator>);
        NODISCARD Scalar GetValue() const noexcept;
        NODISCARD int GetUniqueIndex() const noexcept;

        void SetGenerator(Generator aGenerator) noexcept(std::is_scalar_v<Generator>);
        void SetValue(Scalar aValue) noexcept;
        void SetUniqueIndex(int aUniqueIndex) noexcept;

    private:
        Generator generator;
        Scalar value;
        int uniqueIndex;
    };
}

#endif  // CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_H
