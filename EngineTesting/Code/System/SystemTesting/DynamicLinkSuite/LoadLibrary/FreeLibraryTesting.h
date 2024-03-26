/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/09 21:22)

#ifndef SYSTEM_TESTING_DYNAMIC_LINK_SUITE_FREE_LIBRARY_TESTING_H
#define SYSTEM_TESTING_DYNAMIC_LINK_SUITE_FREE_LIBRARY_TESTING_H

#include "System/DynamicLink/Using/LoadLibraryUsing.h"
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