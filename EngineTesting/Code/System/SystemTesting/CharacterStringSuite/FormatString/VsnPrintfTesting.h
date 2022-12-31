///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.4 (2022/11/30 14:54)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_VSN_PRINTF_TESTING_H
#define SYSTEM_CHARACTER_STRING_SUITE_VSN_PRINTF_TESTING_H

#include "FormatStringTestingBase.h"

namespace System
{
    class VsnPrintfTesting : public FormatStringTestingBase
    {
    public:
        using ClassType = VsnPrintfTesting;
        using ParentType = FormatStringTestingBase;

    public:
        explicit VsnPrintfTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void VsnprintfTest();

        void VsnprintfUseIndefiniteParameterTest(int testStringSize, char* buffer, size_t size, const char* format, ...);
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_VSN_PRINTF_TESTING_H