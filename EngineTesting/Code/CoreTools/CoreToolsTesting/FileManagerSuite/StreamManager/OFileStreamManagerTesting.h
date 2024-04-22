/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/16 17:19)

#ifndef CORE_TOOLS_TESTING_O_FILE_STREAM_MANAGER_TESTING_H
#define CORE_TOOLS_TESTING_O_FILE_STREAM_MANAGER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class OFileStreamManagerTesting final : public UnitTest
    {
    public:
        using ClassType = OFileStreamManagerTesting;
        using ParentType = UnitTest;

        using String = System::String;

    public:
        explicit OFileStreamManagerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void OFileStreamManagerMessageTest();
        void OFileStreamManagerSizeTest();
        static NODISCARD String GetOFileStreamFileName();
        static NODISCARD String GetOFileStreamFileContent();
    };
}

#endif  // CORE_TOOLS_TESTING_O_FILE_STREAM_MANAGER_TESTING_H
