/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 14:15)

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
