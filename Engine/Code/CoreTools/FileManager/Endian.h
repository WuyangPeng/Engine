//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.2 (2020/09/17 16:18)

#ifndef CORE_TOOLS_FILE_MANAGER_ENDIAN_H
#define CORE_TOOLS_FILE_MANAGER_ENDIAN_H

#include "CoreTools/CoreToolsDll.h"

#include <vector>

// 字节存储顺序，结果将通过参数返回，调用者必须保持迭代器的有效性。
namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Endian
    {
    public:
        using ClassType = Endian;
        using DefaultContainer = std::vector<char>;
        using DefaultContainerIter = DefaultContainer::iterator;

    public:
        // 测试机器的字节顺序是否是big endian。
        static bool IsBigEndian();

        // 测试机器的字节顺序是否是little endian。
        static bool IsLittleEndian();

        // 交换字节顺序
        static void Swap2ByteOrder(DefaultContainerIter begin, DefaultContainerIter end);

        static void Swap2ByteOrder(void* data) noexcept;
        static void Swap2ByteOrder(size_t itemsNumber, void* data) noexcept;
        static void Swap4ByteOrder(void* data) noexcept;
        static void Swap4ByteOrder(size_t itemsNumber, void* data) noexcept;
        static void Swap8ByteOrder(void* data) noexcept;
        static void Swap8ByteOrder(size_t itemsNumber, void* data) noexcept;

        static void SwapByteOrder(int itemSize, void* data);
        static void SwapByteOrder(int itemSize, int itemsNumber, void* data);

        static void Swap2ByteOrderToTarget(int itemsNumber, const uint16_t* source, uint16_t* target);
        static void Swap4ByteOrderToTarget(int itemsNumber, const uint32_t* source, uint32_t* target);
        static void Swap8ByteOrderToTarget(int itemsNumber, const uint64_t* source, uint64_t* target);
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_ENDIAN_H
