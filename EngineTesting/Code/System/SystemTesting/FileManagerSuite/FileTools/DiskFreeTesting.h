///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.3 (2021/05/24 14:50)

#ifndef SYSTEM_FILE_MANAGE_SUITE_DISK_FREE_TESTING_H
#define SYSTEM_FILE_MANAGE_SUITE_DISK_FREE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class DiskFreeTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = DiskFreeTesting;
        using ParentType = UnitTest;

    public:
        explicit DiskFreeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void DiskFreeSpaceTest();
    };
}

#endif  // SYSTEM_FILE_MANAGE_SUITE_DISK_FREE_TESTING_H