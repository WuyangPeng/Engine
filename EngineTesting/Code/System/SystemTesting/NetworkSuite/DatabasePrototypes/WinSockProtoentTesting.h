///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/14 16:39)

#ifndef SYSTEM_SECURITY_SUITE_DATABASE_PROTOTYPES_TESTING_H
#define SYSTEM_SECURITY_SUITE_DATABASE_PROTOTYPES_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class WinSockProtoentTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WinSockProtoentTesting;
        using ParentType = UnitTest;

    public:
        explicit WinSockProtoentTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void GetProtoentTest();
    };
}

#endif  // SYSTEM_SECURITY_SUITE_DATABASE_PROTOTYPES_TESTING_H