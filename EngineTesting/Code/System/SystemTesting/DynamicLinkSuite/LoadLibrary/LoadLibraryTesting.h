/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/09 21:21)

#ifndef SYSTEM_TESTING_DYNAMIC_LINK_SUITE_LOAD_LIBRARY_TESTING_H
#define SYSTEM_TESTING_DYNAMIC_LINK_SUITE_LOAD_LIBRARY_TESTING_H

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
        void DoRunUnitTest() override;
        void MainTest();

        void LoadLibrarySucceedTest();
        void LoadLibraryFailureTest();
    };
}

#endif  // SYSTEM_TESTING_DYNAMIC_LINK_SUITE_LOAD_LIBRARY_TESTING_H