///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/07 16:21)

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
