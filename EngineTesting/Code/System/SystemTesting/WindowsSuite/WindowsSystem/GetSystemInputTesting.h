///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.6 (2021/07/08 23:01)

#ifndef SYSTEM_WINDOWS_SUITE_GET_SYSTEM_INPUT_TESTING_H
#define SYSTEM_WINDOWS_SUITE_GET_SYSTEM_INPUT_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class GetSystemInputTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = GetSystemInputTesting;
        using ParentType = UnitTest;

    public:
        explicit GetSystemInputTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void GetSystemInputTest();
    };
}

#endif  // SYSTEM_WINDOWS_SUITE_GET_SYSTEM_INPUT_TESTING_H