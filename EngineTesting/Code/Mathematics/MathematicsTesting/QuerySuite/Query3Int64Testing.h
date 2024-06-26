///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 16:22)

#ifndef MATHEMATICS_QUERY_SUITE_QUERY3_INT64_TESTING_H
#define MATHEMATICS_QUERY_SUITE_QUERY3_INT64_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class Query3Int64Testing : public CoreTools::UnitTest
    {
    public:
        using ClassType = Query3Int64Testing;
        using ParentType = UnitTest;

    public:
        explicit Query3Int64Testing(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void VerticesTest();
        void PlaneTest();
        void TetrahedronTest();
        void CircumspherTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_QUERY_SUITE_QUERY3_INT64_TESTING_H