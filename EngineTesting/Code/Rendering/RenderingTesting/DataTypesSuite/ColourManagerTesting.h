///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 15:56)

#ifndef RENDERING_DATA_TYPES_SUITE_COLOUR_MANAGE_TESTING_H
#define RENDERING_DATA_TYPES_SUITE_COLOUR_MANAGE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Rendering
{
    class ColourManagerTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = ColourManagerTesting;
        using ParentType = UnitTest;

    public:
        explicit ColourManagerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void ColourTest();

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_DATA_TYPES_SUITE_COLOUR_MANAGE_TESTING_H