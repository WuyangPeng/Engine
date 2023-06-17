///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 15:59)

#ifndef RENDERING_CURVES_SURFACES_SUITE_PRINCIPAL_CURVATURE_INFO_TESTING_H
#define RENDERING_CURVES_SURFACES_SUITE_PRINCIPAL_CURVATURE_INFO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Rendering
{
    class PrincipalCurvatureInfoTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = PrincipalCurvatureInfoTesting;
        using ParentType = UnitTest;

    public:
        explicit PrincipalCurvatureInfoTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void InitTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_CURVES_SURFACES_SUITE_PRINCIPAL_CURVATURE_INFO_TESTING_H