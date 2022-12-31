///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.5 (2022/11/30 22:00)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_FORMAT_STRING_TESTING_BASE_H
#define SYSTEM_CHARACTER_STRING_SUITE_FORMAT_STRING_TESTING_BASE_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <array>

namespace System
{
    class FormatStringTestingBase : public CoreTools::UnitTest
    {
    public:
        using ClassType = FormatStringTestingBase;
        using ParentType = UnitTest;

    public:
        explicit FormatStringTestingBase(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        static constexpr auto bufferSize = 256;
        using BufferType = std::array<char, bufferSize>;
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_FORMAT_STRING_TESTING_BASE_H