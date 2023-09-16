///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 09:33)

#ifndef SYSTEM_TESTING_HELPER_SUITE_FILE_STREAM_MACRO_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_FILE_STREAM_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class FileStreamMacroTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = FileStreamMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit FileStreamMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void FileStreamMacroTest();
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_FILE_STREAM_MACRO_TESTING_H
