///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 16:03)

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
        static constexpr auto bufferSize = 256;
        using MultiByteType = std::array<char, bufferSize>;
        using WideCharType = std::array<wchar_t, bufferSize>;

    protected:
        void LengthChecking(int length);

    private:
        int conversionMinLength;
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_CONVERSION_TESTING_BASE_H