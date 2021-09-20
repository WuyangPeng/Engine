//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/13 20:22)

#ifndef CORE_TOOLS_FILE_MANAGER_WRITE_FILE_MANAGER_INTERFACE_H
#define CORE_TOOLS_FILE_MANAGER_WRITE_FILE_MANAGER_INTERFACE_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <string>
#include <memory>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE WriteFileManagerInterface
    {
    public:
        using ClassType = WriteFileManagerInterface;
        using String = System::String;
        using FactoryType =  WriteFileManagerInterface;

    public:
        WriteFileManagerInterface() = default;
        virtual ~WriteFileManagerInterface() noexcept = default;

        WriteFileManagerInterface(const WriteFileManagerInterface&) = default;
        WriteFileManagerInterface& operator=(const WriteFileManagerInterface&) = default;
        WriteFileManagerInterface(WriteFileManagerInterface&&) = default;
        WriteFileManagerInterface& operator=(WriteFileManagerInterface&&) = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        [[nodiscard]] virtual int GetFileByteSize() const = 0;

        [[nodiscard]] virtual void Write(size_t itemSize, const void* data) = 0;
        [[nodiscard]] virtual void Write(size_t itemSize, size_t itemsNumber, const void* data) = 0;

        using WriteFileManageInterfacePtr = std::shared_ptr<WriteFileManagerInterface>;

    public:
        [[nodiscard]] static WriteFileManageInterfacePtr Create (const String& fileName);
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_READ_FILE_MANAGER_INTERFACE_H