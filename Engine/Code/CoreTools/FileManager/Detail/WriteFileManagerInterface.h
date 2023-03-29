///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/23 15:24)

#ifndef CORE_TOOLS_FILE_MANAGER_WRITE_FILE_MANAGER_INTERFACE_H
#define CORE_TOOLS_FILE_MANAGER_WRITE_FILE_MANAGER_INTERFACE_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE WriteFileManagerInterface
    {
    public:
        using ClassType = WriteFileManagerInterface;
        using String = System::String;
        using FactoryType = WriteFileManagerInterface;
        using WriteFileManagerSharedPtr = std::shared_ptr<WriteFileManagerInterface>;

    public:
        WriteFileManagerInterface() = default;
        virtual ~WriteFileManagerInterface() noexcept = default;

        WriteFileManagerInterface(const WriteFileManagerInterface& rhs) noexcept = default;
        WriteFileManagerInterface& operator=(const WriteFileManagerInterface& rhs) noexcept = default;
        WriteFileManagerInterface(WriteFileManagerInterface&& rhs) noexcept = default;
        WriteFileManagerInterface& operator=(WriteFileManagerInterface&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual int GetFileByteSize() const = 0;

        NODISCARD virtual void Write(size_t itemSize, const void* data) = 0;
        NODISCARD virtual void Write(size_t itemSize, size_t itemsNumber, const void* data) = 0;

    public:
        NODISCARD static WriteFileManagerSharedPtr Create(const String& fileName, bool addition);
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_READ_FILE_MANAGER_INTERFACE_H