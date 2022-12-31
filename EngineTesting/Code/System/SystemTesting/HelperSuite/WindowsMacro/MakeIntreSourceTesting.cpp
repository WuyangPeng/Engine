///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/17 18:20)

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

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    const auto* intrePtr = reinterpret_cast<TChar*>(static_cast<uint64_t>(id));

#include STSTEM_WARNING_POP

    const auto intreSource = MakeIntreSource(id);

    ASSERT_EQUAL(intrePtr, intreSource);
}
