/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/11 14:05)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_WIDE_CHAR_CONVERSION_MULTI_BYTE_TESTING_H
#define SYSTEM_CHARACTER_STRING_SUITE_WIDE_CHAR_CONVERSION_MULTI_BYTE_TESTING_H

#include "WideCharConversionTestingBase.h"
#include "System/CharacterString/Fwd/CharacterStringFlagsFwd.h"

namespace System
{
    class WideCharConversionMultiByteTesting final : public WideCharConversionTestingBase
    {
    public:
        using ClassType = WideCharConversionMultiByteTesting;
        using ParentType = WideCharConversionTestingBase;

    public:
        explicit WideCharConversionMultiByteTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void WideCharToMultiByteTest();
        void WideCharToMultiByteUseFlagTest(WideChar wideChar);
        void WideCharToMultiByteUseFlagAndUsedDefaultChar(WideChar wideChar);

    private:
        std::wstring wideCharInitial;
        int wideCharInitialLength;
        CodePage codePage;
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_WIDE_CHAR_CONVERSION_MULTI_BYTE_TESTING_H