/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/30 22:50)

#ifndef CORE_TOOLS_FILE_MANAGER_WRITE_FILE_HANDLE_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_WRITE_FILE_HANDLE_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "FileHandleImpl.h"
#include "WriteFileManagerInterface.h"
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

        NODISCARD int GetFileByteSize() const override;

        void Write(size_t itemSize, const void* data) override;
        void Write(size_t itemSize, size_t itemsNumber, const void* data) override;

    private:
        /// 禁止调用以下成员函数
        void ReadFromFile(size_t itemSize, size_t itemsNumber, void* data) noexcept(gAssert < 4 || gCoreToolsAssert < 4) override;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_WRITE_FILE_HANDLE_IMPL_H