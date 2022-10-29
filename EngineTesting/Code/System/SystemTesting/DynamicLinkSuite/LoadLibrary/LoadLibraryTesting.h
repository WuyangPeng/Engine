///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/10/10 19:55)

#ifndef SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_LOAD_LIBRARY_TESTING_H
#define SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_LOAD_LIBRARY_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class LoadLibraryTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = LoadLibraryTesting;
        using ParentType = UnitTest;

    public:
        explicit LoadLibraryTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void LoadLibrarySucceedTest();
        void LoadLibraryFailureTest();
    };
}

#endif  // SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_LOAD_LIBRARY_TESTING_H