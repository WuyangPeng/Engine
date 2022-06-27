///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/16 18:55)

#ifndef RENDERING_CURVES_SURFACES_SUITE_PRINCIPAL_CURVATURE_INFO_TESTING_H
#define RENDERING_CURVES_SURFACES_SUITE_PRINCIPAL_CURVATURE_INFO_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
    class PrincipalCurvatureInfoTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(PrincipalCurvatureInfoTesting);

    private:
        void MainTest();
        void InitTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_CURVES_SURFACES_SUITE_PRINCIPAL_CURVATURE_INFO_TESTING_H