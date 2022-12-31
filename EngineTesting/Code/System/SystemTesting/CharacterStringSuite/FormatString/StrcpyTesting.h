///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.4 (2022/11/30 14:46)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_STRCPY_TESTING_H
#define SYSTEM_CHARACTER_STRING_SUITE_STRCPY_TESTING_H

#include "FormatStringTestingBase.h"

namespace System
{
    class StrcpyTesting : public FormatStringTestingBase
    {
    public:
        using ClassType = StrcpyTesting;
        using ParentType = FormatStringTestingBase;

    public:
        explicit StrcpyTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void StrcpyTest();
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_STRCPY_TESTING_H