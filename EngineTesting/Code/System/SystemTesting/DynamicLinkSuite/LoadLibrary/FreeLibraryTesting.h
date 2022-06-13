///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/15 12:46)

#ifndef SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_FREE_LIBRARY_TESTING_H
#define SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_FREE_LIBRARY_TESTING_H

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
        void DoRunUnitTest() final;
        void MainTest();

        void FreeLibraryTest();
        void FreeLibraryThread();
    };
}

#endif  // SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_FREE_LIBRARY_TESTING_H