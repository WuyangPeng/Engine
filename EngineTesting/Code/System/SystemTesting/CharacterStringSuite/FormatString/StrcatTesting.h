///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.4 (2022/11/30 14:45)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_STRCAT_TESTING_H
#define SYSTEM_CHARACTER_STRING_SUITE_STRCAT_TESTING_H

#include "FormatStringTestingBase.h"

namespace System
{
    class StrcatTesting : public FormatStringTestingBase
    {
    public:
        using ClassType = StrcatTesting;
        using ParentType = FormatStringTestingBase;

    public:
        explicit StrcatTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void StrcatTest();
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_STRCAT_TESTING_H