/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 14:44)

#ifndef CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_H
#define CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_H

#include "CoreTools/CoreToolsDll.h"

#include <type_traits>

namespace CoreTools
{
    template <typename KeyType, typename ValueType>
    class MinHeapRecord final
    {
    public:
        using ClassType = MinHeapRecord<KeyType, ValueType>;

        static constexpr auto isArithmetic = std::is_arithmetic_v<KeyType> && std::is_arithmetic_v<ValueType>;

    public:
        MinHeapRecord() noexcept;
        MinHeapRecord(int index, const KeyType& handle, const ValueType& weight) noexcept(isArithmetic);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetIndex() const noexcept;
        NODISCARD KeyType GetHandle() const noexcept(std::is_arithmetic_v<KeyType>);
        NODISCARD ValueType GetWeight() const noexcept(std::is_arithmetic_v<ValueType>);

        void SetIndex(int aIndex) noexcept;
        void SetHandle(const KeyType& aHandle) noexcept(std::is_arithmetic_v<KeyType>);
        void SetWeight(const ValueType& aWeight) noexcept(std::is_arithmetic_v<ValueType>);
        void SetRecord(int aIndex, const KeyType& aHandle, const ValueType& aWeight) noexcept(isArithmetic);

    private:
        int index;
        KeyType handle;
        ValueType weight;
    };
}

#endif  // CORE_TOOLS_DATA_TYPE_MIN_HEAP_RECORD_H
