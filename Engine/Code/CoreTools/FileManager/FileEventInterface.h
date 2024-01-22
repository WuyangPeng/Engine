/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 21:44)

#ifndef CORE_TOOLS_FILE_MANAGER_FILE_EVENT_INTERFACE_H
#define CORE_TOOLS_FILE_MANAGER_FILE_EVENT_INTERFACE_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/Helper/SharedPtrMacro.h"

#include <memory>

template class CORE_TOOLS_DEFAULT_DECLARE std::weak_ptr<CoreTools::FileEventInterface>;
template class CORE_TOOLS_DEFAULT_DECLARE std::enable_shared_from_this<CoreTools::FileEventInterface>;

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE FileEventInterface : public std::enable_shared_from_this<FileEventInterface>
    {
    public:
        using ClassType = FileEventInterface;

        using FileEventInterfaceUniquePtr = std::unique_ptr<FileEventInterface>;

    public:
        FileEventInterface() noexcept = default;
        virtual ~FileEventInterface() noexcept = default;
        FileEventInterface(const FileEventInterface& rhs) noexcept = default;
        FileEventInterface& operator=(const FileEventInterface& rhs) noexcept = default;
        FileEventInterface(FileEventInterface&& rhs) noexcept = default;
        FileEventInterface& operator=(FileEventInterface&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        virtual void EventFunction(const FileAsynchronousParameter& fileAsynchronousParameter, const FileBuffer& fileBuffer) = 0;
    };

    CORE_TOOLS_SHARED_PTR_DECLARE(FileEventInterface);
    CORE_TOOLS_WEAK_PTR_DECLARE(FileEventInterface);
}

#endif  // CORE_TOOLS_FILE_MANAGER_FILE_EVENT_INTERFACE_H
