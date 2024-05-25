/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/16 16:40)

#ifndef CORE_TOOLS_TESTING_FILE_EVENT_H
#define CORE_TOOLS_TESTING_FILE_EVENT_H

#include "CoreTools/FileManager/FileEventInterface.h"
#include "CoreTools/FileManager/FileManagerFwd.h"

namespace CoreTools
{
    class FileEvent final : public FileEventInterface
    {
    public:
        using ClassType = FileEvent;
        using ParentType = FileEventInterface;

    public:
        NODISCARD static FileEventInterfaceUniquePtr Create();

        FileEvent() noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

        void EventFunction(const FileAsynchronousParameter& fileAsynchronousParameter, const FileBuffer& fileBuffer) noexcept override;
    };
}

#endif  // CORE_TOOLS_TESTING_FILE_EVENT_H