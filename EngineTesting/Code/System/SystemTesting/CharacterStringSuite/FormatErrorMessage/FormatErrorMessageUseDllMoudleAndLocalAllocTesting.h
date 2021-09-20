///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.2 (2021/04/01 20:08)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_FORMAT_ERROR_MESSAGE_USE_DLL_MOUDLE_AND_LOCAL_ALLOC_TESTING_H
#define SYSTEM_CHARACTER_STRING_SUITE_FORMAT_ERROR_MESSAGE_USE_DLL_MOUDLE_AND_LOCAL_ALLOC_TESTING_H

#include "System/Windows/Fwd/WindowsFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <set>

namespace System
{
    class FormatErrorMessageUseDllMoudleAndLocalAllocTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = FormatErrorMessageUseDllMoudleAndLocalAllocTesting;
        using ParentType = UnitTest;

    public:
        explicit FormatErrorMessageUseDllMoudleAndLocalAllocTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void FormatLastErrorUseDllMoudleAndLocalAllocTest();

    private:
        using WindowErrorFlagsCollection = std::set<WindowError>;

    private:
        WindowErrorFlagsCollection windowErrorFlags;
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_FORMAT_ERROR_MESSAGE_USE_DLL_MOUDLE_AND_LOCAL_ALLOC_TESTING_H