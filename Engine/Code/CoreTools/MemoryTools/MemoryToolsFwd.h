//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.2 (2020/10/19 11:40)

#ifndef CORE_TOOLS_MEMORY_TOOLS_FWD_H
#define CORE_TOOLS_MEMORY_TOOLS_FWD_H

namespace CoreTools
{
    enum class MD5ContextStatus;

    template <typename T>
    class HeapAllocate;

    class DefaultMemory;
    class MemoryManager;
    class Memory;
    class SmartPointerManager;

    template <typename T>
    class SmartPointerSingle;

    template <typename T>
    class SmartPointer1DArray;

    template <typename T>
    class SmartPointer2DArray;

    template <typename T>
    class SmartPointer3DArray;

    template <typename T>
    class SmartPointer4DArray;

    class MD5Context;
    class MD5;

    class Random;
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_FWD_H