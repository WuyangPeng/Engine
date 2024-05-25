/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/16 16:47)

#ifndef CORE_TOOLS_TESTING_FILE_ASYNCHRONOUS_PARAMETER_TESTING_H
#define CORE_TOOLS_TESTING_FILE_ASYNCHRONOUS_PARAMETER_TESTING_H

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
        static constexpr auto fileBufferCount = 100;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void BaseTest();
        void FileBufferFailTest() const;
        void FileBufferTest();
        void EventTest();

        NODISCARD static String GetFileName();
    };
}

#endif  // CORE_TOOLS_TESTING_FILE_ASYNCHRONOUS_PARAMETER_TESTING_H