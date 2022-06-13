///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/15 13:07)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_FORMAT_ERROR_MESSAGE_USE_DLL_MOUDLE_AND_USE_BUFFER_TESTING_H
#define SYSTEM_CHARACTER_STRING_SUITE_FORMAT_ERROR_MESSAGE_USE_DLL_MOUDLE_AND_USE_BUFFER_TESTING_H

#include "System/Windows/Fwd/WindowsFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <set>

namespace System
{
    class FormatErrorMessageUseDllMoudleAndUseBufferTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = FormatErrorMessageUseDllMoudleAndUseBufferTesting;
        using ParentType = UnitTest;

    public:
        explicit FormatErrorMessageUseDllMoudleAndUseBufferTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void FormatLastErrorUseDllMoudleAndUseBufferTest();

    private:
        using WindowErrorFlagsCollection = std::set<WindowError>;

    private:
        WindowErrorFlagsCollection windowErrorFlags;
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_FORMAT_ERROR_MESSAGE_USE_DLL_MOUDLE_AND_USE_BUFFER_TESTING_H