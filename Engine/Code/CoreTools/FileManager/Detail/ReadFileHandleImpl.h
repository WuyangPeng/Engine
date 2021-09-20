//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/13 20:20)

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

        [[nodiscard]] int GetFileByteSize() const final;

        void Read(size_t itemSize, void* data) final;
        void Read(size_t itemSize, size_t itemsNumber, void* data) final;

        void WriteToFile(size_t itemSize, size_t itemsNumber, const void* data) noexcept(g_Assert < 4 || g_CoreToolsAssert < 4) final;
        void AppendToFile(size_t itemSize, size_t itemsNumber, const void* data) noexcept(g_Assert < 4 || g_CoreToolsAssert < 4) final;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_READ_FILE_HANDLE_IMPL_H