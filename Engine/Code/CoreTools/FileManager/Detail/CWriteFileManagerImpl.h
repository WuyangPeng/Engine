///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.3 (2021/09/03 13:41)

#ifndef CORE_TOOLS_FILE_MANAGER_C_WRITE_FILE_MANAGER_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_C_WRITE_FILE_MANAGER_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CFileManagerImpl.h"
#include "WriteFileManagerInterface.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"

namespace CoreTools
{
    // 一个提示传递给_tfopen_s表示从磁盘顺序存取，以优化缓存。调用子程序ReadFromFile将产生错误。
    class CORE_TOOLS_HIDDEN_DECLARE CWriteFileManagerImpl final : public CFileManagerImpl, public WriteFileManagerInterface
    {
    public:
        using ClassType = CWriteFileManagerImpl;
        using ParentType = CFileManagerImpl;
        using InterfaceType = WriteFileManagerInterface;
        using String = System::String;

    public:
        explicit CWriteFileManagerImpl(const String& fileName, bool addition);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetFileByteSize() const final;

        // 当且仅当写入的字节数等于data的大小，操作是成功的。否则抛出Error异常。
        void Write(size_t itemSize, const void* data) final;
        void Write(size_t itemSize, size_t itemsNumber, const void* data) final;

#ifdef SYSTEM_BIG_ENDIAN
    private:
        NODISCARD size_t WriteToFileWithBigEndian(size_t itemSize, size_t itemsNumber, const void* data);
        NODISCARD size_t WriteToFileSwap2ByteOrder(size_t itemsNumber, const void* data);
        NODISCARD size_t WriteToFileSwap4ByteOrder(size_t itemsNumber, const void* data);
        NODISCARD size_t WriteToFileSwap8ByteOrder(size_t itemsNumber, const void* data);
#endif  // SYSTEM_BIG_ENDIAN

    private:
        // 禁止调用以下成员函数
        size_t ReadFromFile(MAYBE_UNUSED size_t itemSize, MAYBE_UNUSED size_t itemsNumber, MAYBE_UNUSED void* data) noexcept(g_Assert < 4 || g_CoreToolsAssert < 4) final;
        int GetCharacter() noexcept(g_Assert < 4 || g_CoreToolsAssert < 4) final;
        bool UnGetCharacter(MAYBE_UNUSED int character) noexcept(g_Assert < 4 || g_CoreToolsAssert < 4) final;
        std::string GetString(MAYBE_UNUSED int count) noexcept(g_Assert < 4 || g_CoreToolsAssert < 4) final;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_C_WRITE_FILE_MANAGER_IMPL_H