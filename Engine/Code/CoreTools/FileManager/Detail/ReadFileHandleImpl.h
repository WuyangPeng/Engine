///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/23 15:24)

#ifndef CORE_TOOLS_FILE_MANAGER_READ_FILE_HANDLE_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_READ_FILE_HANDLE_IMPL_H

#include "FileHandleImpl.h"
#include "ReadFileManagerInterface.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE ReadFileHandleImpl final : public FileHandleImpl, public ReadFileManagerInterface
    {
    public:
        using ClassType = ReadFileHandleImpl;
        using ParentType = FileHandleImpl;
        using InterfaceType = ReadFileManagerInterface;
        using String = System::String;

    public:
        explicit ReadFileHandleImpl(const String& fileName);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetFileByteSize() const override;

        void Read(size_t itemSize, void* data) override;
        void Read(size_t itemSize, size_t itemsNumber, void* data) override;

    private:
        // 禁止调用以下成员函数
        void WriteToFile(size_t itemSize, size_t itemsNumber, const void* data) noexcept(gAssert < 4 || gCoreToolsAssert < 4) override;
        void AppendToFile(size_t itemSize, size_t itemsNumber, const void* data) noexcept(gAssert < 4 || gCoreToolsAssert < 4) override;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_READ_FILE_HANDLE_IMPL_H