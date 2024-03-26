/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 14:03)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_FORMAT_STRING_MESSAGE_USE_ARGUMENT_ARRAY_AND_LOCAL_ALLOC_TESTING_H
#define SYSTEM_CHARACTER_STRING_SUITE_FORMAT_STRING_MESSAGE_USE_ARGUMENT_ARRAY_AND_LOCAL_ALLOC_TESTING_H

#include "FormatStringMessageUseArgumentTestingBase.h"

namespace System
{
    class FormatStringMessageUseArgumentArrayAndLocalAllocTesting final : public FormatStringMessageUseArgumentTestingBase
    {
    public:
        using ClassType = FormatStringMessageUseArgumentArrayAndLocalAllocTesting;
        using ParentType = FormatStringMessageUseArgumentTestingBase;

    public:
        explicit FormatStringMessageUseArgumentArrayAndLocalAllocTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void FormatStringMessageUseArgumentArrayAndLocalAllocTest(WindowsHLocal& resultMessage);
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_FORMAT_STRING_MESSAGE_USE_ARGUMENT_ARRAY_AND_LOCAL_ALLOC_TESTING_H