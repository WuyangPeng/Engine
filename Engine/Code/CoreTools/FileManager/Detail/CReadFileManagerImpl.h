///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/08 14:42)

#ifndef CORE_TOOLS_FILE_MANAGER_C_READ_FILE_MANAGER_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_C_READ_FILE_MANAGER_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CFileManagerImpl.h"
#include "ReadFileManagerInterface.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"

namespace CoreTools
{
    // 一个提示传递给_tfopen_s表示从磁盘顺序存取，以优化缓存。
    // 调用成员函数WriteToFile、PutCharacter和PutString将产生错误。
    class CORE_TOOLS_HIDDEN_DECLARE CReadFileManagerImpl final : public CFileManagerImpl, public ReadFileManagerInterface
    {
    public:
        using ClassType = CReadFileManagerImpl;
        using ParentType = CFileManagerImpl;
        using InterfaceType = ReadFileManagerInterface;
        using String = System::String;

    public:
        explicit CReadFileManagerImpl(const String& fileName);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetFileByteSize() const final;

        // 当且仅当读出的字节数等于data的大小，操作是成功的。否则抛出Error异常。
        void Read(size_t itemSize, void* data) final;
        void Read(size_t itemSize, size_t itemsNumber, void* data) final;

    private:
        // 禁止调用以下成员函数
        size_t WriteToFile(MAYBE_UNUSED size_t itemSize, MAYBE_UNUSED size_t itemsNumber, MAYBE_UNUSED const void* data) noexcept(g_Assert < 4 || g_CoreToolsAssert < 4) final;
        bool PutCharacter(MAYBE_UNUSED int character) noexcept(g_Assert < 4 || g_CoreToolsAssert < 4) final;
        bool PutString(MAYBE_UNUSED const std::string& str) noexcept(g_Assert < 4 || g_CoreToolsAssert < 4) final;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_C_READ_FILE_MANAGER_IMPL_H