///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.5 (2022/12/15 11:37)

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
        void DoRunUnitTest() final;
        void MainTest();

        void ReadFileUseCompletionRoutineTest();

        void DoReadFileUseCompletionRoutineTest(WindowsHandle handle);

        static void SYSTEM_WINAPI OverlappedCompletionRoutine(WindowsDWord errorCode, WindowsDWord numberOfBytesTransfered, WindowOverlappedPtr overlapped) noexcept;
    };
}

#endif  // SYSTEM_FILE_MANAGER_SUITE_READ_FILE_USE_COMPLETION_ROUTINE_TESTING_H