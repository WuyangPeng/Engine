///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 15:59)

#ifndef RENDERING_CURVES_SURFACES_SUITE_SURFACE_PATCH_TESTING_H
#define RENDERING_CURVES_SURFACES_SUITE_SURFACE_PATCH_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Rendering
{
    class SurfacePatchTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = SurfacePatchTesting;
        using ParentType = UnitTest;

    public:
        explicit SurfacePatchTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void ParameterTest() noexcept;
        void DerivativesTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_CURVES_SURFACES_SUITE_SURFACE_PATCH_TESTING_H