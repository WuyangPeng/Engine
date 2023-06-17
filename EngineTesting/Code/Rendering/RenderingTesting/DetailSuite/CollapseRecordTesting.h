///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 15:46)

#ifndef RENDERING_DETAIL_SUITE_COLLAPSE_RECORD_TESTING_H
#define RENDERING_DETAIL_SUITE_COLLAPSE_RECORD_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Rendering
{
    class CollapseRecordTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = CollapseRecordTesting;
        using ParentType = UnitTest;

    public:
        explicit CollapseRecordTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void InitTest();

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_DETAIL_SUITE_COLLAPSE_RECORD_TESTING_H