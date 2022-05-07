///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.7 (2022/05/07 16:21)

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
        explicit WindowMessageUnitTestSuiteStream(bool usecommand);

        CLASS_INVARIANT_DECLARE;

        NODISCARD OStreamShared GetStreamShared() noexcept;

    private:
        using Command = CoreTools::CommandHandle;
        using CommandSharedPtr = std::shared_ptr<Command>;

    private:
        NODISCARD static CommandSharedPtr GenerateCommandSharedPtr(bool usecommand);
        NODISCARD static OStreamShared GenerateStreamShared(bool usecommand);
        NODISCARD static std::string GetMultiByteCommandLine();

    private:
        OStreamShared oStreamShared;
    };
}

#endif  // FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_UNIT_TEST_SUITE_STREAM_H
