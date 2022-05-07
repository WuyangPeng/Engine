///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.2 (2021/04/01 15:24)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_FORMAT_ERROR_MESSAGE_USE_LOCAL_ALLOC_TESTING_H
#define SYSTEM_CHARACTER_STRING_SUITE_FORMAT_ERROR_MESSAGE_USE_LOCAL_ALLOC_TESTING_H

#include "System/Windows/Fwd/WindowsFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <set>

namespace System
{
    class FormatErrorMessageUseLocalAllocTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = FormatErrorMessageUseLocalAllocTesting;
        using ParentType = UnitTest;

    public:
        explicit FormatErrorMessageUseLocalAllocTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void FormatLastErrorUseLocalAllocTest();

    private:
        using WindowErrorFlagsCollection = std::set<WindowError>;

    private:
        WindowErrorFlagsCollection windowErrorFlags;
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_FORMAT_ERROR_MESSAGE_USE_LOCAL_ALLOC_TESTING_H