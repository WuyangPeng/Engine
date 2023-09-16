///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 15:41)

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
    SYSTEM_SELF_CLASS_IS_VALID_9;
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

void System::EngineeringTypeDisplayerTesting::TypeDisplayerTest() noexcept
{
#ifdef SYSTEM_TEST_TYPE_DISPLAYER

    TypeDisplayer<ClassType> typeDisplayer{};

#endif  // SYSTEM_TEST_TYPE_DISPLAYER
}
