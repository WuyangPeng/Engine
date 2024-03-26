/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 14:05)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_CONVERSION_TESTING_BASE_H
#define SYSTEM_CHARACTER_STRING_SUITE_CONVERSION_TESTING_BASE_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <array>

namespace System
{
    class ConversionTestingBase : public CoreTools::UnitTest
    {
    public:
        using ClassType = ConversionTestingBase;
        using ParentType = UnitTest;

    public:
        explicit ConversionTestingBase(const OStreamShared& stream, int conversionMinLength);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        using MultiByteType = CharBufferType;
        using WideCharType = WCharBufferType;

    protected:
        void LengthChecking(int length);

    private:
        int conversionMinLength;
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_CONVERSION_TESTING_BASE_H