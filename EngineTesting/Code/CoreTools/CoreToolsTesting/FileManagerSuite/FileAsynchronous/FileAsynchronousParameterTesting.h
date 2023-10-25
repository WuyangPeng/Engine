///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 20:37)

#ifndef CORE_TOOLS_TESTING_FILE_ASYNCHRONOUS_PARAMETER_TESTING_H
#define CORE_TOOLS_TESTING_FILE_ASYNCHRONOUS_PARAMETER_TESTING_H

#include "CoreTools/FileManager/FileEventInterface.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class FileAsynchronousParameterTesting final : public UnitTest
    {
    public:
        using ClassType = FileAsynchronousParameterTesting;
        using ParentType = UnitTest;

        using String = System::String;

    public:
        explicit FileAsynchronousParameterTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void BaseTest();
        void FileBufferFailTest();
        void FileBufferTest();
        void EventTest();

        NODISCARD String GetFileName();
    };
}

#endif  // CORE_TOOLS_TESTING_FILE_ASYNCHRONOUS_PARAMETER_TESTING_H