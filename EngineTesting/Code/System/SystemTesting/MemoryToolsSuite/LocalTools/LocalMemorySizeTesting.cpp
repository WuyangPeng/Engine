/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/12 10:16)

#include "LocalMemorySizeTesting.h"
#include "System/MemoryTools/LocalTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::LocalMemorySizeTesting::LocalMemorySizeTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, LocalMemorySizeTesting)

void System::LocalMemorySizeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::LocalMemorySizeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LocalMemorySizeTest);
}

void System::LocalMemorySizeTesting::LocalMemorySizeTest()
{
    for (const auto localMemory : *this)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoLocalMemorySizeTest, localMemory);
    }
}

void System::LocalMemorySizeTesting::DoLocalMemorySizeTest(LocalMemory localMemory)
{
    constexpr WindowsSize localSize{ 256 * sizeof(TChar) };

    auto local = LocalMemoryAlloc(localMemory, localSize);
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(local, "LocalMemoryAlloc ʧ�ܡ�");

    ASSERT_EQUAL(GetLocalMemorySize(local), localSize);

    ASSERT_NOT_THROW_EXCEPTION_1(LocalMemoryFreeTest, local);
}
