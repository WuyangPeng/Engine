/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 17:20)

#include "EngineeringTypeDisplayerTesting.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#define SYSTEM_TEST_TYPE_DISPLAYER
#undef SYSTEM_TEST_TYPE_DISPLAYER

System::EngineeringTypeDisplayerTesting::EngineeringTypeDisplayerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, EngineeringTypeDisplayerTesting)

void System::EngineeringTypeDisplayerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::EngineeringTypeDisplayerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TypeDisplayerTest);
}

void System::EngineeringTypeDisplayerTesting::TypeDisplayerTest() const noexcept
{
#ifdef SYSTEM_TEST_TYPE_DISPLAYER

    TypeDisplayer<ClassType> typeDisplayer{};

#endif  // SYSTEM_TEST_TYPE_DISPLAYER
}
