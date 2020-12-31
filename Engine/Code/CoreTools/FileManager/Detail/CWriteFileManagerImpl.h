//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/13 17:22)

#ifndef CORE_TOOLS_FILE_MANAGER_C_WRITE_FILE_MANAGER_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_C_WRITE_FILE_MANAGER_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CFileManagerImpl.h"
#include "WriteFileManagerInterface.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"

// 一个提示传递给_tfopen_s表示从磁盘顺序存取，以优化缓存。调用子程序ReadFromFile将产生错误。

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CWriteFileManagerImpl final : public CFileManagerImpl, public WriteFileManagerInterface
    {
    public:
        using ClassType = CWriteFileManagerImpl;
        using ParentType = CFileManagerImpl;
        using InterfaceType = WriteFileManagerInterface;

    public:
        explicit CWriteFileManagerImpl(const String& fileName);

        CLASS_INVARIANT_FINAL_DECLARE;

        [[nodiscard]] int GetFileByteSize() const final;

        // 当且仅当写入的字节数等于data的大小，操作是成功的。否则抛出Error异常。
        void Write(size_t itemSize, const void* data) final;
        void Write(size_t itemSize, size_t itemsNumber, const void* data) final;

#ifdef SYSTEM_BIG_ENDIAN
    private:
        [[nodiscard]] size_t WriteToFileWithBigEndian(size_t itemSize, size_t itemsNumber, const void* data) noexcept;
        [[nodiscard]] size_t WriteToFileSwap2ByteOrder(size_t itemsNumber, const void* data) noexcept;
        [[nodiscard]] size_t WriteToFileSwap4ByteOrder(size_t itemsNumber, const void* data) noexcept;
        [[nodiscard]] size_t WriteToFileSwap8ByteOrder(size_t itemsNumber, const void* data) noexcept;
#endif  // SYSTEM_BIG_ENDIAN

    private:
        // 禁止调用以下成员函数
        size_t ReadFromFile(size_t itemSize, size_t itemsNumber, void* data) noexcept(g_Assert < 4 || g_CoreToolsAssert < 4) final;
        int GetCharacter() noexcept(g_Assert < 4 || g_CoreToolsAssert < 4) final;
        bool UnGetCharacter(int character) noexcept(g_Assert < 4 || g_CoreToolsAssert < 4) final;
        std::string GetString(int count) noexcept(g_Assert < 4 || g_CoreToolsAssert < 4) final;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_C_WRITE_FILE_MANAGER_IMPL_H