//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/13 20:26)

#ifndef CORE_TOOLS_FILE_MANAGER_ENDIAN_H
#define CORE_TOOLS_FILE_MANAGER_ENDIAN_H

#include "CoreTools/CoreToolsDll.h"

#include <vector>

// �ֽڴ洢˳�򣬽����ͨ���������أ������߱��뱣�ֵ���������Ч�ԡ�
namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Endian final
    {
    public:
        using ClassType = Endian; 

    public:
        // ���Ի������ֽ�˳���Ƿ���big endian��
        [[nodiscard]] static bool IsBigEndian();

        // ���Ի������ֽ�˳���Ƿ���little endian��
        [[nodiscard]] static bool IsLittleEndian();

        // �����ֽ�˳��
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
