/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 14:13)

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

void System::FormatErrorMessageUseBufferTestingBase::SizeEqualTest(const TCharBufferType& buffer, size_t size)
{
    const String result{ buffer.data() };
    ASSERT_EQUAL(size, result.size());
}

void System::FormatErrorMessageUseBufferTestingBase::NullBufferTest(const TCharBufferType& buffer)
{
    constexpr TCharBufferType nullBuffer{};
    ASSERT_EQUAL(buffer, nullBuffer);
}