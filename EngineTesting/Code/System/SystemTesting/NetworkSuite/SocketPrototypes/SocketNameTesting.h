///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.4 (2021/06/07 11:06)

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