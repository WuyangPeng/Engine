/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/12 10:22)

#include "MemoryCopyTesting.h"
#include "System/MemoryTools/MemoryHelper.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::MemoryCopyTesting::MemoryCopyTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, MemoryCopyTesting)

void System::MemoryCopyTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::MemoryCopyTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MemoryCopyTest);
}

void System::MemoryCopyTesting::MemoryCopyTest()
{
    constexpr auto fillValue = 1;

    CharBufferType buffer{};
    buffer.fill(fillValue);

    CharBufferType copyBuffer{};

    MemoryCopy(copyBuffer.data(), buffer.data(), defaultBufferSize);

    CharBufferType result{};
    result.fill(fillValue);

    ASSERT_EQUAL(copyBuffer, result);
}
