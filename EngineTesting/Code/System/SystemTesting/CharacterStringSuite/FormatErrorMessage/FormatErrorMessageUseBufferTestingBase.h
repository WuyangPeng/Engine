///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 15:49)

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