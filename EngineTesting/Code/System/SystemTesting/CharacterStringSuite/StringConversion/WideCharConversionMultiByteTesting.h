///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/01 0:32)

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
        void DoRunUnitTest() final;
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