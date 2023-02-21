///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/08 23:32)

#ifndef CORE_TOOLS_FILE_MANAGER_WRITE_FILE_HANDLE_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_WRITE_FILE_HANDLE_IMPL_H

#include "FileHandleImpl.h"
#include "WriteFileManagerInterface.h"
#include "System/FileManager/File.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE WriteFileHandleImpl final : public FileHandleImpl, public WriteFileManagerInterface
    {
    public:
        using ClassType = WriteFileHandleImpl;
        using ParentType = FileHandleImpl;
        using InterfaceType = WriteFileManagerInterface;
        using String = System::String;

    public:
        explicit WriteFileHandleImpl(const String& fileName, FileHandleCreationDisposition creation = FileHandleCreationDisposition::CreateAlways);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetFileByteSize() const final;

        void Write(size_t itemSize, const void* data) final;
        void Write(size_t itemSize, size_t itemsNumber, const void* data) final;

    private:
        // 禁止调用以下成员函数
        void ReadFromFile(MAYBE_UNUSED size_t itemSize, MAYBE_UNUSED size_t itemsNumber, MAYBE_UNUSED void* data) noexcept(gAssert < 4 || gCoreToolsAssert < 4) final;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_WRITE_FILE_HANDLE_IMPL_H