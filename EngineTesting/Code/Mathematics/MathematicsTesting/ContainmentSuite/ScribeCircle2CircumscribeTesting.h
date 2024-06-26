///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 15:29)

#ifndef MATHEMATICS_CONTAINMENT_SUITE_SCRIBE_CIRCLE2_CIRCUMSCRIBE_TESTING_H
#define MATHEMATICS_CONTAINMENT_SUITE_SCRIBE_CIRCLE2_CIRCUMSCRIBE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class ScribeCircle2CircumscribeTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = ScribeCircle2CircumscribeTesting;
        using ParentType = UnitTest;

    public:
        explicit ScribeCircle2CircumscribeTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void CircumscribeTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_CONTAINMENT_SUITE_SCRIBE_CIRCLE2_CIRCUMSCRIBE_TESTING_H