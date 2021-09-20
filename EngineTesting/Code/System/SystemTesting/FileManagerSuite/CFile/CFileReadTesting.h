///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.3 (2021/05/18 15:39)

#ifndef SYSTEM_FILE_MANAGE_SUITE_CFILE_READ_TESTING_H
#define SYSTEM_FILE_MANAGE_SUITE_CFILE_READ_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class CFileReadTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = CFileReadTesting;
        using ParentType = UnitTest;

    public:
        explicit CFileReadTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void InitTest();
        void ReadTest();

        NODISCARD static const String GetFileName();
    };
}

#endif  // SYSTEM_FILE_MANAGE_SUITE_CFILE_READ_TESTING_H