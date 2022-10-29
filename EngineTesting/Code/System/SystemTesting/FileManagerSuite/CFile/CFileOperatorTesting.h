///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/29 19:52)

#ifndef SYSTEM_FILE_MANAGE_SUITE_CFILE_OPERATOR_TESTING_H
#define SYSTEM_FILE_MANAGE_SUITE_CFILE_OPERATOR_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class CFileOperatorTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = CFileOperatorTesting;
        using ParentType = UnitTest;

    public:
        explicit CFileOperatorTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void OperatorTest();

        NODISCARD static const String GetFileName();
    };
}

#endif  // SYSTEM_FILE_MANAGE_SUITE_CFILE_OPERATOR_TESTING_H