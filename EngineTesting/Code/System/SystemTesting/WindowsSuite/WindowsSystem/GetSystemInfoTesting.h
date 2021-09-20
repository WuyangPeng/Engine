///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.6 (2021/07/08 22:42)

#ifndef SYSTEM_WINDOWS_SUITE_GET_SYSTEM_INFO_TESTING_H
#define SYSTEM_WINDOWS_SUITE_GET_SYSTEM_INFO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class GetSystemInfoTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = GetSystemInfoTesting;
        using ParentType = UnitTest;

    public:
        explicit GetSystemInfoTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void InfoTest();
    };
}

#endif  // SYSTEM_WINDOWS_SUITE_GET_SYSTEM_INFO_TESTING_H