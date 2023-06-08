///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/08 18:10)

#ifndef MATHEMATICS_ALGEBRA_SUITE_VECTOR_3D_TOOLS_TESTING_H
#define MATHEMATICS_ALGEBRA_SUITE_VECTOR_3D_TOOLS_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class Vector3ToolsTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = Vector3ToolsTesting;
        using ParentType = UnitTest;

    public:
        explicit Vector3ToolsTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void DistanceTest();
        void ProductTest();
        void ProjectionTest();
        void ConversionTest();
        void CompareTest();
        void OtherCalculateTest();

        void DoRunUnitTest() override;

        NODISCARD constexpr static double Half(double value)
        {
            return value * 0.5;
        }
    };
}

#endif  // MATHEMATICS_ALGEBRA_SUITE_VECTOR_3D_TOOLS_TESTING_H