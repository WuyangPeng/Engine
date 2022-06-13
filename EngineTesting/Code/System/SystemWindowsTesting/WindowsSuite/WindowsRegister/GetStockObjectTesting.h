///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/16 14:41)

#ifndef SYSTEM_WINDOWS_TESTING_WINDOWS_SUITE_GET_STOCK_OBJECT_TESTING_H
#define SYSTEM_WINDOWS_TESTING_WINDOWS_SUITE_GET_STOCK_OBJECT_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class GetStockObjectTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = GetStockObjectTesting;
        using ParentType = UnitTest;

    public:
        explicit GetStockObjectTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void GetStockObjectTest();
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_WINDOWS_SUITE_GET_STOCK_OBJECT_TESTING_H