///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/29 19:56)

#ifndef SYSTEM_FILE_MANAGE_SUITE_DIRECTORY_TESTING_H
#define SYSTEM_FILE_MANAGE_SUITE_DIRECTORY_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class DirectoryTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = DirectoryTesting;
        using ParentType = UnitTest;

    public:
        explicit DirectoryTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void DirectoryTest();
    };
}

#endif  // SYSTEM_FILE_MANAGE_SUITE_DIRECTORY_TESTING_H