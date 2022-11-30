///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.4 (2022/11/26 22:29)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_FORMAT_MESSAGE_TESTING_BASE_H
#define SYSTEM_CHARACTER_STRING_SUITE_FORMAT_MESSAGE_TESTING_BASE_H

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