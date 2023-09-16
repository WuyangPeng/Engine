///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 16:03)

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