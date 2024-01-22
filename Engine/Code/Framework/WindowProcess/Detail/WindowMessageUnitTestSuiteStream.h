/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 14:15)

#ifndef FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_UNIT_TEST_SUITE_STREAM_H
#define FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_UNIT_TEST_SUITE_STREAM_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Command/CommandFwd.h"
#include "CoreTools/UnitTestSuite/OStreamShared.h"

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE WindowMessageUnitTestSuiteStream
    {
    public:
        using ClassType = WindowMessageUnitTestSuiteStream;

        using OStreamShared = CoreTools::OStreamShared;

    public:
        explicit WindowMessageUnitTestSuiteStream(bool useCommand);

        CLASS_INVARIANT_DECLARE;

        NODISCARD OStreamShared GetStreamShared() noexcept;

    private:
        using Command = CoreTools::CommandHandle;
        using CommandSharedPtr = std::shared_ptr<Command>;

    private:
        NODISCARD static CommandSharedPtr GenerateCommandSharedPtr(bool useCommand);
        NODISCARD static OStreamShared GenerateStreamShared(bool useCommand);
        NODISCARD static std::string GetMultiByteCommandLine();

    private:
        OStreamShared oStreamShared;
    };
}

#endif  // FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_UNIT_TEST_SUITE_STREAM_H
