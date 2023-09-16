///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 16:38)

#include "ConsoleStandardHandlesTesting.h"
#include "System/Console/ConsoleColour.h"
#include "System/Console/ConsoleHandle.h"
#include "System/Console/Flags/ConsoleHandleFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::ConsoleStandardHandlesTesting::ConsoleStandardHandlesTesting(const OStreamShared& stream)
    : ParentType{ stream },
      standardHandles{ StandardHandle::Output, StandardHandle::Error }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ConsoleStandardHandlesTesting)

void System::ConsoleStandardHandlesTesting::RandomShuffleStandardHandle(std::default_random_engine& randomEngine)
{
    SYSTEM_CLASS_IS_VALID_1;

    std::ranges::shuffle(standardHandles, randomEngine);
}

System::StandardHandle System::ConsoleStandardHandlesTesting::GetConsoleStandardHandle(size_t index) const
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return standardHandles.at(index % standardHandles.size());
}

void System::ConsoleStandardHandlesTesting::SetDefaultTextAttribute()
{
    SYSTEM_CLASS_IS_VALID_1;

    for (const auto standardHandle : standardHandles)
    {
        ASSERT_TRUE(SetSystemConsoleDefaultTextAttribute(GetStandardHandle(standardHandle)));
    }
}

System::ConsoleStandardHandlesTesting::StandardHandleContainerConstIter System::ConsoleStandardHandlesTesting::begin() const noexcept
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return standardHandles.begin();
}

System::ConsoleStandardHandlesTesting::StandardHandleContainerConstIter System::ConsoleStandardHandlesTesting::end() const noexcept
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return standardHandles.end();
}

size_t System::ConsoleStandardHandlesTesting::GetStandardHandleSize() const noexcept
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return standardHandles.size();
}
