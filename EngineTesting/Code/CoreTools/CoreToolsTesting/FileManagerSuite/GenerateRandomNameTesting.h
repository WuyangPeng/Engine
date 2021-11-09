///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.3 (2021/09/06 16:40)

#ifndef CORE_TOOLS_TESTING_GENERATE_RANDOM_NAME_TESTING_H
#define CORE_TOOLS_TESTING_GENERATE_RANDOM_NAME_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class GenerateRandomNameTesting final : public UnitTest
    {
    public:
        using ClassType = GenerateRandomNameTesting;
        using ParentType = UnitTest;

    public:
        explicit GenerateRandomNameTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void StringTest();
        void WStringTest();
        void TStringTest();
    };
}

#endif  // CORE_TOOLS_TESTING_GENERATE_RANDOM_NAME_TESTING_H