//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/13 20:20)

#ifndef CORE_TOOLS_FILE_MANAGER_READ_FILE_MANAGER_INTERFACE_H
#define CORE_TOOLS_FILE_MANAGER_READ_FILE_MANAGER_INTERFACE_H

#include "CoreTools/CoreToolsDll.h"

#include <memory>
#include "System/Helper/UnicodeUsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE ReadFileManagerInterface
    {
    public:
        using ClassType = ReadFileManagerInterface;
        using FactoryType = ReadFileManagerInterface;
        using String = System::String;
        using ReadFileManageInterfacePtr = std::shared_ptr<ReadFileManagerInterface>;

    public:
        ReadFileManagerInterface() = default;
        virtual ~ReadFileManagerInterface() noexcept = default;
        ReadFileManagerInterface(const ReadFileManagerInterface&) = default;
        ReadFileManagerInterface& operator=(const ReadFileManagerInterface&) = default;
        ReadFileManagerInterface(ReadFileManagerInterface&&) noexcept = default;
        ReadFileManagerInterface& operator=(ReadFileManagerInterface&&) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        [[nodiscard]] virtual int GetFileByteSize() const = 0;

        [[nodiscard]] virtual void Read(size_t itemSize, void* data) = 0;
        [[nodiscard]] virtual void Read(size_t itemSize, size_t itemsNumber, void* data) = 0;

    public:
        [[nodiscard]] static ReadFileManageInterfacePtr Create(const String& fileName);
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_READ_FILE_MANAGER_INTERFACE_H