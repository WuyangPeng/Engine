/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/16 16:04)

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
        void DoRunUnitTest() override;
        void MainTest();

        void StringTest();
        void WStringTest();
        void TStringTest();
    };
}

#endif  // CORE_TOOLS_TESTING_GENERATE_RANDOM_NAME_TESTING_H