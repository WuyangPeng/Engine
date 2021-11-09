///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.3 (2021/09/06 16:46)

#ifndef CORE_TOOLS_TESTING_COPY_FILE_TOOLS_TESTING_H
#define CORE_TOOLS_TESTING_COPY_FILE_TOOLS_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class CopyFileToolsTesting final : public UnitTest
    {
    public:
        using ClassType = CopyFileToolsTesting;
        using ParentType = UnitTest;
        using String = System::String;

    public:
        explicit CopyFileToolsTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void CopyFileTest();
        void VerificationTest();
        void DeleteFileTest();

        NODISCARD static String GetCopyFileName();
    };
}

#endif  // CORE_TOOLS_TESTING_COPY_FILE_TOOLS_TESTING_H