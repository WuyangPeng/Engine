/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 11:18)

#ifndef SYSTEM_FILE_MANAGER_SUITE_READ_FILE_USE_COMPLETION_ROUTINE_TESTING_H
#define SYSTEM_FILE_MANAGER_SUITE_READ_FILE_USE_COMPLETION_ROUTINE_TESTING_H

#include "ReadWriteFileTestingBase.h"
#include "System/Helper/WindowsMacro.h"

namespace System
{
    class ReadFileUseCompletionRoutineTesting final : public ReadWriteFileTestingBase
    {
    public:
        using ClassType = ReadFileUseCompletionRoutineTesting;
        using ParentType = ReadWriteFileTestingBase;

    public:
        explicit ReadFileUseCompletionRoutineTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ReadFileUseCompletionRoutineTest();
        void DoReadFileUseCompletionRoutineTest(WindowsHandle handle);

        static void SYSTEM_WIN_API OverlappedCompletionRoutine(WindowsDWord errorCode, WindowsDWord numberOfBytesTransfered, WindowOverlappedPtr overlapped) noexcept;
    };
}

#endif  // SYSTEM_FILE_MANAGER_SUITE_READ_FILE_USE_COMPLETION_ROUTINE_TESTING_H