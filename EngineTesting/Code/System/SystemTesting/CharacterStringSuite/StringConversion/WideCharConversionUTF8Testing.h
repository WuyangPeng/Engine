///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.5 (2022/12/01 22:39)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_WIDE_CHAR_CONVERSION_UTF8_TESTING_H
#define SYSTEM_CHARACTER_STRING_SUITE_WIDE_CHAR_CONVERSION_UTF8_TESTING_H

#include "WideCharConversionTestingBase.h"
#include "System/CharacterString/Fwd/CharacterStringFlagsFwd.h"

namespace System
{
    class WideCharConversionUTF8Testing final : public WideCharConversionTestingBase
    {
    public:
        using ClassType = WideCharConversionUTF8Testing;
        using ParentType = WideCharConversionTestingBase;

    public:
        explicit WideCharConversionUTF8Testing(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void WideCharConversionUTF8Test();

    private:
        std::wstring wideCharInitial;
        int wideCharInitialLength;
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_WIDE_CHAR_CONVERSION_UTF8_TESTING_H