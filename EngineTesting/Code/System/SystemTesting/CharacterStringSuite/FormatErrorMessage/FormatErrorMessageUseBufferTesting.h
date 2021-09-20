///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.2 (2021/04/01 19:29)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_FORMAT_ERROR_MESSAGE_USE_BUFFER_TESTING_H
#define SYSTEM_CHARACTER_STRING_SUITE_FORMAT_ERROR_MESSAGE_USE_BUFFER_TESTING_H

#include "System/Windows/Fwd/WindowsFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <set>

namespace System
{
    class FormatErrorMessageUseBufferTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = FormatErrorMessageUseBufferTesting;
        using ParentType = UnitTest;

    public:
        explicit FormatErrorMessageUseBufferTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void FormatLastErrorUseBufferTest();

    private:
        using WindowErrorFlagsCollection = std::set<WindowError>;

    private:
        WindowErrorFlagsCollection windowErrorFlags;
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_FORMAT_ERROR_MESSAGE_USE_BUFFER_TESTING_H