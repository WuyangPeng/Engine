///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/10 19:15)

#ifndef CORE_TOOLS_BASE_SUITE_LOADING_LIBRARY_TESTING_H
#define CORE_TOOLS_BASE_SUITE_LOADING_LIBRARY_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class LoadingLibraryTesting final : public UnitTest
    {
    public:
        using ClassType = LoadingLibraryTesting;
        using ParentType = UnitTest;

    public:
        explicit LoadingLibraryTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void LoadingNetMessageDllTest();
        void LoadingErrorDllTest();
        void GetProcessAddressTest();
        void GetProcessAddressErrorTest();
    };
}

#endif  // CORE_TOOLS_BASE_SUITE_LOADING_LIBRARY_TESTING_H
