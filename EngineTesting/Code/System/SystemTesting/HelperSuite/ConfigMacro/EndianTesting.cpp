/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 17:34)

#include "EndianTesting.h"
#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::EndianTesting::EndianTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, EndianTesting)

void System::EndianTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::EndianTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(EndianTest);
}

void System::EndianTesting::EndianTest()
{
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    constexpr size_t one{ 1 };
    const auto isLittleEndian = (*reinterpret_cast<const char*>(&one) != 0);

#include SYSTEM_WARNING_POP

#ifdef SYSTEM_LITTLE_ENDIAN

    ASSERT_TRUE(isLittleEndian);

#else  // !SYSTEM_LITTLE_ENDIAN

    ASSERT_FALSE(isLittleEndian);

#endif  // SYSTEM_LITTLE_ENDIAN
}
