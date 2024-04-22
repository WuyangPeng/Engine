/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/16 14:51)

#ifndef CORE_TOOLS_CHARACTER_STRING_SUITE_CASE_INSENSITIVE_STRING_IO_STREAM_TESTING_H
#define CORE_TOOLS_CHARACTER_STRING_SUITE_CASE_INSENSITIVE_STRING_IO_STREAM_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class CaseInsensitiveStringIOStreamTesting final : public UnitTest
    {
    public:
        using ClassType = CaseInsensitiveStringIOStreamTesting;
        using ParentType = UnitTest;

    public:
        explicit CaseInsensitiveStringIOStreamTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void StreamTest();
    };
}

#endif  // CORE_TOOLS_CHARACTER_STRING_SUITE_CASE_INSENSITIVE_STRING_IO_STREAM_TESTING_H
