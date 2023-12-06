///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/22 11:38)

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