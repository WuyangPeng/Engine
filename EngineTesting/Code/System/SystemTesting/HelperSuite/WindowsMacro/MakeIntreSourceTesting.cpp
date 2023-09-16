///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 09:49)

#include "MakeIntreSourceTesting.h"
#include "System/Helper/WindowsMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::MakeIntreSourceTesting::MakeIntreSourceTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, MakeIntreSourceTesting)

void System::MakeIntreSourceTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::MakeIntreSourceTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MakeIntreSourceTest);
}

void System::MakeIntreSourceTesting::MakeIntreSourceTest()
{
    constexpr WindowsWord id{ 101 };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    const auto* intrePtr = reinterpret_cast<TChar*>(static_cast<uint64_t>(id));

#include SYSTEM_WARNING_POP

    const auto* intreSource = MakeIntreSource(id);

    ASSERT_TRUE(intrePtr == intreSource);
}
