/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/11 14:02)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_FORMAT_ERROR_MESSAGE_USE_BUFFER_TESTING_BASE_H
#define SYSTEM_CHARACTER_STRING_SUITE_FORMAT_ERROR_MESSAGE_USE_BUFFER_TESTING_BASE_H

#include "FormatErrorMessageTestingBase.h"

#include <array>

namespace System
{
    class FormatErrorMessageUseBufferTestingBase : public FormatErrorMessageTestingBase
    {
    public:
        using ClassType = FormatErrorMessageUseBufferTestingBase;
        using ParentType = FormatErrorMessageTestingBase;

    public:
        explicit FormatErrorMessageUseBufferTestingBase(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        void SizeEqualTest(const TCharBufferType& buffer, size_t size);
        void NullBufferTest(const TCharBufferType& buffer);
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_FORMAT_ERROR_MESSAGE_USE_BUFFER_TESTING_BASE_H