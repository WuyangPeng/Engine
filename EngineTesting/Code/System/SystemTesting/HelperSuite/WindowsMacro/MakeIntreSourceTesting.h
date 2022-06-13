///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/15 0:43)

#ifndef SYSTEM_TESTING_HELPER_SUITE_MAKE_INTRE_SOURCE_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_MAKE_INTRE_SOURCE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class MakeIntreSourceTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = MakeIntreSourceTesting;
        using ParentType = UnitTest;

    public:
        explicit MakeIntreSourceTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void MakeIntreSourceTest();
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_MAKE_INTRE_SOURCE_TESTING_H
