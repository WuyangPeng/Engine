///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.4 (2022/11/29 18:51)

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
        using BufferType = std::array<TChar, bufferSize>;

    protected:
        void SizeEqualTest(const BufferType& buffer, size_t size);
        void NullBufferTest(const BufferType& buffer);
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_FORMAT_ERROR_MESSAGE_USE_BUFFER_TESTING_BASE_H