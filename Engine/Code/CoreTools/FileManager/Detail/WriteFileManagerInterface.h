/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/03/30 22:50)

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
        using FactoryType = WriteFileManagerInterface;

        using String = System::String;
        using WriteFileManagerSharedPtr = std::shared_ptr<WriteFileManagerInterface>;

    public:
        NODISCARD static WriteFileManagerSharedPtr Create(const String& fileName, bool addition);

        WriteFileManagerInterface() = default;
        virtual ~WriteFileManagerInterface() noexcept = default;

        WriteFileManagerInterface(const WriteFileManagerInterface& rhs) noexcept = default;
        WriteFileManagerInterface& operator=(const WriteFileManagerInterface& rhs) noexcept = default;
        WriteFileManagerInterface(WriteFileManagerInterface&& rhs) noexcept = default;
        WriteFileManagerInterface& operator=(WriteFileManagerInterface&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual int GetFileByteSize() const = 0;

        virtual void Write(size_t itemSize, const void* data) = 0;
        virtual void Write(size_t itemSize, size_t itemsNumber, const void* data) = 0;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_READ_FILE_MANAGER_INTERFACE_H