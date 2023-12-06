///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 15:54)

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