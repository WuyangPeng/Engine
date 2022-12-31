///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/09 18:25)

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
        void DoRunUnitTest() final;
        void MainTest();

        void FreeLibraryTest();
        void FreeLibraryThread();

        void DoFreeLibraryTest(const DynamicLinkModule& module);
    };
}

#endif  // SYSTEM_TESTING_DYNAMIC_LINK_SUITE_FREE_LIBRARY_TESTING_H