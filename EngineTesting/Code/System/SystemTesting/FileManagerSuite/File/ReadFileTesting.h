///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/15 12:15)

#ifndef SYSTEM_FILE_MANAGE_SUITE_READ_FILE_TESTING_H
#define SYSTEM_FILE_MANAGE_SUITE_READ_FILE_TESTING_H

#include "System/FileManager/Using/FileToolsUsing.h"
#include "System/Helper/WindowsMacro.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class ReadFileTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ReadFileTesting;
        using ParentType = UnitTest;

    public:
        explicit ReadFileTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ReadTest();
        void ReadFileUseOverlappedTest();
        void ReadFileUseCompletionRoutineTest();

        static void SYSTEM_WINAPI OverlappedCompletionRoutine(WindowsDWord errorCode, WindowsDWord numberOfBytesTransfered, WindowOverlappedPtr overlapped) noexcept;
    };
}

#endif  // SYSTEM_FILE_MANAGE_SUITE_READ_FILE_TESTING_H