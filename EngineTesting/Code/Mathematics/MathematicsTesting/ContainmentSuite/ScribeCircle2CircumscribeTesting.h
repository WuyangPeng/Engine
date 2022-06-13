///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/07 21:16)

#ifndef MATHEMATICS_CONTAINMENT_SUITE_SCRIBE_CIRCLE2_CIRCUMSCRIBE_TESTING_H
#define MATHEMATICS_CONTAINMENT_SUITE_SCRIBE_CIRCLE2_CIRCUMSCRIBE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
    class ScribeCircle2CircumscribeTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(ScribeCircle2CircumscribeTesting);

    private:
        void MainTest();
        void CircumscribeTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_CONTAINMENT_SUITE_SCRIBE_CIRCLE2_CIRCUMSCRIBE_TESTING_H