///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 16:00)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_VSN_PRINT_F_TESTING_H
#define SYSTEM_CHARACTER_STRING_SUITE_VSN_PRINT_F_TESTING_H

#include "FormatStringTestingBase.h"

namespace System
{
    class VsnPrintFTesting final : public FormatStringTestingBase
    {
    public:
        using ClassType = VsnPrintFTesting;
        using ParentType = FormatStringTestingBase;

    public:
        explicit VsnPrintFTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void VsnPrintFTest();

        void VsnPrintFUseIndefiniteParameterTest(int testStringSize, char* buffer, size_t size, const char* format, ...);
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_VSN_PRINT_F_TESTING_H