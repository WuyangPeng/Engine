///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 15:18)

#ifndef SYSTEM_WINDOWS_TESTING_WINDOWS_SUITE_GET_COMMAND_LINE_TESTING_H
#define SYSTEM_WINDOWS_TESTING_WINDOWS_SUITE_GET_COMMAND_LINE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class GetCommandLineTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = GetCommandLineTesting;
        using ParentType = UnitTest;

    public:
        explicit GetCommandLineTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void GetCommandLineTest();
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_WINDOWS_SUITE_GET_COMMAND_LINE_TESTING_H