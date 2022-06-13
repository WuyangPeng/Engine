///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 11:54)

#ifndef CORE_TOOLS_TESTING_ENVIRONMENT_TESTING_H
#define CORE_TOOLS_TESTING_ENVIRONMENT_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class EnvironmentTesting final : public UnitTest
    {
    public:
        using ClassType = EnvironmentTesting;
        using ParentType = UnitTest;
        using String = System::String;

    public:
        explicit EnvironmentTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void InsertDirectoryTest();
        void EraseDirectoryTest();
        void GetPathReadingSucceedTest();
        void GetPathWritingSucceedTest();
        void GetPathReadingAndWritingSucceedTest();
        void GetPathReadingFailureTest();
        void GetPathWritingFailureTest();
        void GetPathReadingAndWritingFailureTest();
        void ConfigurationPathTest();

        NODISCARD static String GetEnvironmentFileName();
        NODISCARD static String GetEnvironmentPathFileName();
    };
}

#endif  // CORE_TOOLS_TESTING_ENVIRONMENT_TESTING_H