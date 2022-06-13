///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 11:55)

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
        void DoRunUnitTest() final;
        void MainTest();

        void BaseTest();
        void FileBufferFailTest();
        void FileBufferTest();
        void EventTest();

        NODISCARD String GetFileName();
    };
}

#endif  // CORE_TOOLS_TESTING_FILE_ASYNCHRONOUS_PARAMETER_TESTING_H