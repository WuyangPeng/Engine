///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.4 (2021/06/07 13:47)

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