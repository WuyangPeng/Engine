//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/13 20:20)

#ifndef CORE_TOOLS_FILE_MANAGER_READ_FILE_MANAGER_INTERFACE_H
#define CORE_TOOLS_FILE_MANAGER_READ_FILE_MANAGER_INTERFACE_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE ReadFileManagerInterface
    {
    public:
        using ClassType = ReadFileManagerInterface;

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
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_READ_FILE_MANAGER_INTERFACE_H