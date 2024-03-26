/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 17:20)

#include "EngineeringSuffixTesting.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::EngineeringSuffixTesting::EngineeringSuffixTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, EngineeringSuffixTesting)

void System::EngineeringSuffixTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::EngineeringSuffixTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SuffixTest);
}

void System::EngineeringSuffixTesting::SuffixTest() const
{
    std::ignore = GetEngineeringSuffix();
    std::ignore = GetEngineeringTypesSuffix();
    std::ignore = GetEngineeringExeSuffix();
    std::ignore = GetEngineeringDirectory();
}
