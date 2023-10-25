///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 17:03)

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
