///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/15 12:15)

#ifndef SYSTEM_FILE_MANAGE_SUITE_MOVE_FILE_TESTING_H
#define SYSTEM_FILE_MANAGE_SUITE_MOVE_FILE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class MoveFileTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = MoveFileTesting;
        using ParentType = UnitTest;

    public:
        explicit MoveFileTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void MoveFileTest();
    };
}

#endif  // SYSTEM_FILE_MANAGE_SUITE_MOVE_FILE_TESTING_H