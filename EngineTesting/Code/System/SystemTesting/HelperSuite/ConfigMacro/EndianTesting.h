/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/06 17:34)

#ifndef SYSTEM_TESTING_HELPER_SUITE_ENDIAN_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_ENDIAN_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class EndianTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = EndianTesting;
        using ParentType = UnitTest;

    public:
        explicit EndianTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void EndianTest();
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_ENDIAN_TESTING_H
