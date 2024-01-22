/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 21:40)

#ifndef CORE_TOOLS_FILE_MANAGER_READ_FILE_MANAGER_INTERFACE_H
#define CORE_TOOLS_FILE_MANAGER_READ_FILE_MANAGER_INTERFACE_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <memory>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE ReadFileManagerInterface
    {
    public:
        using ClassType = ReadFileManagerInterface;
        using FactoryType = ReadFileManagerInterface;

        using String = System::String;
        using ReadFileManagerSharedPtr = std::shared_ptr<ReadFileManagerInterface>;

    public:
        ReadFileManagerInterface() = default;
        virtual ~ReadFileManagerInterface() noexcept = default;
        ReadFileManagerInterface(const ReadFileManagerInterface&) noexcept = default;
        ReadFileManagerInterface& operator=(const ReadFileManagerInterface&) noexcept = default;
        ReadFileManagerInterface(ReadFileManagerInterface&&) noexcept = default;
        ReadFileManagerInterface& operator=(ReadFileManagerInterface&&) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual int GetFileByteSize() const = 0;

        virtual void Read(size_t itemSize, void* data) = 0;
        virtual void Read(size_t itemSize, size_t itemsNumber, void* data) = 0;

    public:
        NODISCARD static ReadFileManagerSharedPtr Create(const String& fileName);
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_READ_FILE_MANAGER_INTERFACE_H