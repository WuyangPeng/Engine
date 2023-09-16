///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 15:54)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_STR_CAT_TESTING_H
#define SYSTEM_CHARACTER_STRING_SUITE_STR_CAT_TESTING_H

#include "FormatStringTestingBase.h"

namespace System
{
    class StrCatTesting final : public FormatStringTestingBase
    {
    public:
        using ClassType = StrCatTesting;
        using ParentType = FormatStringTestingBase;

    public:
        explicit StrCatTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void StrCatTest();
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_STR_CAT_TESTING_H