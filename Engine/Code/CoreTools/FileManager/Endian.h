///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.3 (2023/03/02 10:04)

#ifndef CORE_TOOLS_FILE_MANAGER_ENDIAN_H
#define CORE_TOOLS_FILE_MANAGER_ENDIAN_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"

#include <vector>

namespace CoreTools
{
    // �ֽڴ洢˳�򣬽����ͨ���������أ������߱��뱣�ֵ���������Ч�ԡ�
    class CORE_TOOLS_DEFAULT_DECLARE Endian final
    {
    public:
        using ClassType = Endian;

    public:
        Endian() = delete;

    public:
        // ���Ի������ֽ�˳���Ƿ���big endian��
        NODISCARD static bool IsBigEndian() noexcept(gAssert < 0 || gCoreToolsAssert < 0);

        // ���Ի������ֽ�˳���Ƿ���little endian��
        NODISCARD static bool IsLittleEndian() noexcept(gAssert < 0 || gCoreToolsAssert < 0);

        // �����ֽ�˳��
        static void Swap2ByteOrder(void* data) noexcept(gAssert < 0 || gCoreToolsAssert < 0);
        static void Swap2ByteOrder(size_t itemsNumber, void* data) noexcept(gAssert < 0 || gCoreToolsAssert < 0);
        static void Swap4ByteOrder(void* data) noexcept(gAssert < 0 || gCoreToolsAssert < 0);
        static void Swap4ByteOrder(size_t itemsNumber, void* data) noexcept(gAssert < 0 || gCoreToolsAssert < 0);
        static void Swap8ByteOrder(void* data) noexcept(gAssert < 0 || gCoreToolsAssert < 0);
        static void Swap8ByteOrder(size_t itemsNumber, void* data) noexcept(gAssert < 0 || gCoreToolsAssert < 0);

        static void SwapByteOrder(size_t itemSize, void* data) noexcept(gAssert < 0 || gCoreToolsAssert < 0);
        static void SwapByteOrder(size_t itemSize, size_t itemsNumber, void* data) noexcept(gAssert < 0 || gCoreToolsAssert < 0);

        static void Swap2ByteOrderToTarget(size_t itemsNumber, const uint16_t* source, uint16_t* target) noexcept(gAssert < 0 || gCoreToolsAssert < 0);
        static void Swap4ByteOrderToTarget(size_t itemsNumber, const uint32_t* source, uint32_t* target) noexcept(gAssert < 0 || gCoreToolsAssert < 0);
        static void Swap8ByteOrderToTarget(size_t itemsNumber, const uint64_t* source, uint64_t* target) noexcept(gAssert < 0 || gCoreToolsAssert < 0);
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_ENDIAN_H
