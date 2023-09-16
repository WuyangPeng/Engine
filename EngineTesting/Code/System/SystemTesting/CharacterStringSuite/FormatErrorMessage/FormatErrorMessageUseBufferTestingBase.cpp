///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 16:09)

#include "FormatErrorMessageUseBufferTestingBase.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::FormatErrorMessageUseBufferTestingBase::FormatErrorMessageUseBufferTestingBase(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, FormatErrorMessageUseBufferTestingBase)

void System::FormatErrorMessageUseBufferTestingBase::SizeEqualTest(const BufferType& buffer, size_t size)
{
    const String result{ buffer.data() };
    ASSERT_EQUAL(size, result.size());
}

void System::FormatErrorMessageUseBufferTestingBase::NullBufferTest(const BufferType& buffer)
{
    constexpr BufferType nullBuffer{};
    ASSERT_EQUAL(buffer, nullBuffer);
}