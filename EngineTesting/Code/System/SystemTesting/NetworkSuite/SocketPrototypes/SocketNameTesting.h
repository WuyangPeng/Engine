///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/14 16:40)

#ifndef SYSTEM_SECURITY_SUITE_SOCKET_NAME_TESTING_H
#define SYSTEM_SECURITY_SUITE_SOCKET_NAME_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class SocketNameTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = SocketNameTesting;
        using ParentType = UnitTest;

    public:
        explicit SocketNameTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void SocketNameTest();

        void Init();
        void Cleanup();
    };
}

#endif  // SYSTEM_SECURITY_SUITE_SOCKET_NAME_TESTING_H