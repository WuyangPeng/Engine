///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 15:52)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_FORMAT_MESSAGE_TESTING_BASE_H
#define SYSTEM_CHARACTER_STRING_SUITE_FORMAT_MESSAGE_TESTING_BASE_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class FormatMessageTestingBase : public CoreTools::UnitTest
    {
    public:
        using ClassType = FormatMessageTestingBase;
        using ParentType = UnitTest;

    public:
        explicit FormatMessageTestingBase(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        void LocalMemoryFreeTest(WindowsHLocal errorMessage);
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_FORMAT_MESSAGE_TESTING_BASE_H