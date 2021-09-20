///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.3 (2021/05/24 11:38)

#ifndef SYSTEM_FILE_MANAGE_SUITE_COPY_FILE_TESTING_H
#define SYSTEM_FILE_MANAGE_SUITE_COPY_FILE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class CopyFileTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = CopyFileTesting;
        using ParentType = UnitTest;

    public:
        explicit CopyFileTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void CopyFileTest();
    };
}

#endif  // SYSTEM_FILE_MANAGE_SUITE_COPY_FILE_TESTING_H