///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 14:12)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_SUITE_FILE_OUT_STREAM_TESTING_H
#define CORE_TOOLS_OBJECT_SYSTEMS_SUITE_FILE_OUT_STREAM_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class FileOutStreamTesting final : public UnitTest
    {
    public:
        using ClassType = FileOutStreamTesting;
        using ParentType = UnitTest;

    public:
        explicit FileOutStreamTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void WriteNullObjectTest();
        void DeleteFileTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_SUITE_FILE_OUT_STREAM_TESTING_H