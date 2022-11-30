///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.4 (2022/11/03 22:16)

#ifndef SYSTEM_SECURITY_SUITE_SELECT_TESTING_H
#define SYSTEM_SECURITY_SUITE_SELECT_TESTING_H

#include "System/DynamicLink/Using/LoadLibraryUsing.h"
#include "System/Network/Using/SocketPrototypesUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class SelectTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = SelectTesting;
        using ParentType = UnitTest;

    public:
        explicit SelectTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void SelectTest();
        void SelectThreadTest();

        void Init();
        void Cleanup();

    private:
        WinSockFdSet winSockFdSet;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_SELECT_TESTING_H