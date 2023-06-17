///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 11:14)

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