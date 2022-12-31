///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.5 (2022/12/18 11:06)

#ifndef SYSTEM_TESTING_HELPER_SUITE_GET_ARRAY_SIZE_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_GET_ARRAY_SIZE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class GetArraySizeTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = GetArraySizeTesting;
        using ParentType = UnitTest;

    public:
        explicit GetArraySizeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void GetArraySizeTest() noexcept;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_GET_ARRAY_SIZE_TESTING_H
