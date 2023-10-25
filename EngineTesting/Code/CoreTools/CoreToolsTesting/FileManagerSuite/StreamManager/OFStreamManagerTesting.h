///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 20:27)

#ifndef CORE_TOOLS_TESTING_OF_STREAM_MANAGER_TESTING_H
#define CORE_TOOLS_TESTING_OF_STREAM_MANAGER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class OFStreamManagerTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = OFStreamManagerTesting;
        using ParentType = UnitTest;
        using String = System::String;

    public:
        explicit OFStreamManagerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void OFStreamManagerMessageTest();
        void OFStreamManagerSizeTest();
        static NODISCARD String GetOFStreamFileName();
        static NODISCARD String GetOFStreamFileContent();
    };
}

#endif  // CORE_TOOLS_TESTING_OF_STREAM_MANAGER_TESTING_H
