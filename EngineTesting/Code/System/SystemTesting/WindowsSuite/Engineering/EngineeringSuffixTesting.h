/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 17:18)

#ifndef SYSTEM_WINDOWS_SUITE_ENGINEERING_SUFFIX_TESTING_H
#define SYSTEM_WINDOWS_SUITE_ENGINEERING_SUFFIX_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class EngineeringSuffixTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = EngineeringSuffixTesting;
        using ParentType = UnitTest;

    public:
        explicit EngineeringSuffixTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void SuffixTest() const;
    };
}

#endif  // SYSTEM_WINDOWS_SUITE_ENGINEERING_SUFFIX_TESTING_H