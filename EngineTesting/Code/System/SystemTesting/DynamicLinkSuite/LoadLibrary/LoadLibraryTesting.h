///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.1 (2021/03/25 10:55)

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