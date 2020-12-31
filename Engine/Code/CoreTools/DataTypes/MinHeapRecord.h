//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.2 (2020/10/19 9:56)

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

        Generator GetGenerator() const noexcept(std::is_scalar_v<Generator>);
        Scalar GetValue() const noexcept;
        int GetUniqueIndex() const noexcept;

        void SetGenerator(Generator generator) noexcept(std::is_scalar_v<Generator>);
        void SetValue(Scalar value) noexcept;
        void SetUniqueIndex(int uniqueIndex) noexcept;

    private:
        Generator m_Generator;
        Scalar m_Value;
        int m_UniqueIndex;
    };
}

#endif  // CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_H
