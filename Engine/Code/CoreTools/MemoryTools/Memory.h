//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/19 16:45)

#ifndef CORE_TOOLS_MEMORY_TOOLS_MEMORY_H
#define CORE_TOOLS_MEMORY_TOOLS_MEMORY_H

#include "CoreTools/CoreToolsDll.h"

#include "MemoryManager.h"
#include "CoreTools/Contract/ContractFwd.h"

// 内存跟踪调试。
namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Memory final
    {
    public:
        using ClassType = Memory;

    public:
        explicit Memory(const FunctionDescribed& functionDescribed) noexcept;

        CLASS_INVARIANT_DECLARE;

        // 对 1D 数组:  data[bound1]
        template <typename T>
        [[nodiscard]] T* New1DArray(const int bound);

        // 对 2D 数组:  data[bound2][bound1]
        template <typename T>
        [[nodiscard]] T** New2DArray(const int bound1, const int bound2);

        // 对 3D 数组:  data[bound3][bound2][bound1]
        template <typename T>
        [[nodiscard]] T*** New3DArray(const int bound1, const int bound2, const int bound3);

        // 对 4D 数组:  data[bound4][bound3][bound2][bound1]
        template <typename T>
        [[nodiscard]] T**** New4DArray(const int bound1, const int bound2, const int bound3, const int bound4);

        // 对单例
        template <typename T>
        void DeleteSingle(T*& data);

        // 对 1D 数组:  data[bound1]
        template <typename T>
        void Delete1DArray(T*& data);

        // 对 2D 数组:  data[bound2][bound1]
        template <typename T>
        void Delete2DArray(T**& data);

        // 对 3D 数组:  data[bound3][bound2][bound1]
        template <typename T>
        void Delete3DArray(T***& data);

        // 对 4D 数组:  data[bound4][bound3][bound2][bound1]
        template <typename T>
        void Delete4DArray(T****& data);

        [[nodiscard]] const FunctionDescribed& GetFunctionDescribed() const noexcept;

    private:
        template <typename T>
        void CallConstructor(T*& data, int bound);

        template <typename T>
        void CallConstructor(T**& data, int bound);

        template <typename T>
        void CallConstructor(T***& data, int bound);

        template <typename T>
        void CallConstructor(T****& data, int bound);

        template <typename T>
        void DeleteArray(T*& data, size_t constructorSuccess);

    private:
        FunctionDescribed m_FunctionDescribed;
    };
}

[[nodiscard]] inline void* operator new(size_t bytesNumber, const CoreTools::Memory& memory)
{
    return MEMORY_MANAGER_SINGLETON.CreateBlock(bytesNumber, 0, memory.GetFunctionDescribed());
}

inline void operator delete(void*, const CoreTools::Memory&)
{
    // 只在异常处理调用。
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_MEMORY_H
