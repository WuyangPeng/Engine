///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 11:51)

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