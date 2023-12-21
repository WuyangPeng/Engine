/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/17 20:02)

#ifndef THE_LAST_OVERLORD_TESTING_VERSION_TESTING_H
#define THE_LAST_OVERLORD_TESTING_VERSION_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace TheLastOverlordTesting
{
    class VersionTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = VersionTesting;
        using ParentType = UnitTest;

    public:
        explicit VersionTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;

        void MainTest();
    };
}

#endif  // THE_LAST_OVERLORD_TESTING_VERSION_TESTING_H