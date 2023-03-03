///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.3 (2023/03/03 09:11)

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

        void EventFunction(const FileAsynchronousParameter& fileAsynchronousParameter, const FileBuffer& fileBuffer) noexcept override;
    };
}

#endif  // CORE_TOOLS_TESTING_FILE_EVENT_H