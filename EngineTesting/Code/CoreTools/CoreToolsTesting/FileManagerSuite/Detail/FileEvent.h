///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.3 (2021/09/08 14:19)

#ifndef CORE_TOOLS_TESTING_FILE_EVENT_H
#define CORE_TOOLS_TESTING_FILE_EVENT_H

#include "CoreTools/FileManager/FileEventInterface.h"
#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

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

        void EventFunction(MAYBE_UNUSED const FileAsynchronousParameter& fileAsynchronousParameter, MAYBE_UNUSED const FileBuffer& fileBuffer) noexcept final;
    };
}

#endif  // CORE_TOOLS_TESTING_FILE_EVENT_H