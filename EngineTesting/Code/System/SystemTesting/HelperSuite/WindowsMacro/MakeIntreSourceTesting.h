///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.1 (2021/03/16 19:47)

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
