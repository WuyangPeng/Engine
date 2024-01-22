/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 21:38)

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

        using String = System::String;

    public:
        explicit CWriteFileManagerImpl(const String& fileName, bool addition);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetFileByteSize() const override;

        // 当且仅当写入的字节数等于data的大小，操作是成功的。否则抛出Error异常。
        void Write(size_t itemSize, const void* data) override;
        void Write(size_t itemSize, size_t itemsNumber, const void* data) override;

#ifdef SYSTEM_BIG_ENDIAN

    private:
        NODISCARD size_t WriteToFileWithBigEndian(size_t itemSize, size_t itemsNumber, const void* data);
        NODISCARD size_t WriteToFileSwap2ByteOrder(size_t itemsNumber, const void* data);
        NODISCARD size_t WriteToFileSwap4ByteOrder(size_t itemsNumber, const void* data);
        NODISCARD size_t WriteToFileSwap8ByteOrder(size_t itemsNumber, const void* data);

#endif  // SYSTEM_BIG_ENDIAN

    private:
        // 禁止调用以下成员函数
        size_t ReadFromFile(size_t itemSize, size_t itemsNumber, void* data) noexcept(gAssert < 4 || gCoreToolsAssert < 4) override;
        int GetCharacter() noexcept(gAssert < 4 || gCoreToolsAssert < 4) override;
        bool UnGetCharacter(int character) noexcept(gAssert < 4 || gCoreToolsAssert < 4) override;
        std::string GetString(int count) noexcept(gAssert < 4 || gCoreToolsAssert < 4) override;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_C_WRITE_FILE_MANAGER_IMPL_H