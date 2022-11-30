///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.4 (2022/11/29 18:51)

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
    String result{ buffer.data() };
    ASSERT_EQUAL(size, result.size());
}

void System::FormatErrorMessageUseBufferTestingBase::NullBufferTest(const BufferType& buffer)
{
    constexpr BufferType nullBuffer{};
    ASSERT_EQUAL(buffer, nullBuffer);
}