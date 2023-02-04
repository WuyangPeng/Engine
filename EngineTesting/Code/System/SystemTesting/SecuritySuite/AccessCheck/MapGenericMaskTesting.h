///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/01/27 21:45)

#ifndef SYSTEM_SECURITY_SUITE_MAP_GENERIC_MASK_TESTING_H
#define SYSTEM_SECURITY_SUITE_MAP_GENERIC_MASK_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class MapGenericMaskTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = MapGenericMaskTesting;
        using ParentType = UnitTest;

    public:
        explicit MapGenericMaskTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void MapGenericMaskTest();
    };
}

#endif  // SYSTEM_SECURITY_SUITE_MAP_GENERIC_MASK_TESTING_H