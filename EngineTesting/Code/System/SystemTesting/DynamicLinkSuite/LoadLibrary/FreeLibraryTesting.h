///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 17:00)

#ifndef SYSTEM_TESTING_DYNAMIC_LINK_SUITE_FREE_LIBRARY_TESTING_H
#define SYSTEM_TESTING_DYNAMIC_LINK_SUITE_FREE_LIBRARY_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class FreeLibraryTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = FreeLibraryTesting;
        using ParentType = UnitTest;

    public:
        explicit FreeLibraryTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void FreeLibraryTest();
        void FreeLibraryThread();

        void DoFreeLibraryTest(const DynamicLinkModule& module);
    };
}

#endif  // SYSTEM_TESTING_DYNAMIC_LINK_SUITE_FREE_LIBRARY_TESTING_H