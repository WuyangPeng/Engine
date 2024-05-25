/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/16 16:03)

#ifndef CORE_TOOLS_TESTING_DELETE_FILE_TOOLS_TESTING_H
#define CORE_TOOLS_TESTING_DELETE_FILE_TOOLS_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class DeleteFileToolsTesting final : public UnitTest
    {
    public:
        using ClassType = DeleteFileToolsTesting;
        using ParentType = UnitTest;

        using String = System::String;

    public:
        explicit DeleteFileToolsTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void CreateFileTest(const String& fileName);
        void DeleteFileSucceedTest();
    };
}

#endif  // CORE_TOOLS_TESTING_DELETE_FILE_TOOLS_TESTING_H