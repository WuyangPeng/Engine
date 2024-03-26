/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 18:30)

#include "ConsoleScreenBufferTesting.h"
#include "System/Console/Flags/ConsoleScreenBufferFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::ConsoleScreenBufferTesting::ConsoleScreenBufferTesting(const OStreamShared& stream)
    : ParentType{ stream },
      desiredAccessGenerics{ DesiredAccessGeneric::Read, DesiredAccessGeneric::Write, DesiredAccessGeneric::ReadAndWrite },
      consoleScreenBufferShareModes{ ConsoleScreenBufferShareMode::Read, ConsoleScreenBufferShareMode::Write, ConsoleScreenBufferShareMode::ReadAndWrite },
      randomEngine{ GetEngineRandomSeed() },
      maxSize{ std::max(desiredAccessGenerics.size(), consoleScreenBufferShareModes.size()) }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ConsoleScreenBufferTesting)

void System::ConsoleScreenBufferTesting::RandomShuffleConsoleFlags()
{
    std::ranges::shuffle(desiredAccessGenerics, randomEngine);
    std::ranges::shuffle(consoleScreenBufferShareModes, randomEngine);
}

size_t System::ConsoleScreenBufferTesting::GetMaxSize() const noexcept
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return maxSize;
}

System::DesiredAccessGeneric System::ConsoleScreenBufferTesting::GetDesiredAccessGeneric(size_t index) const
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return desiredAccessGenerics.at(index % desiredAccessGenerics.size());
}

System::ConsoleScreenBufferShareMode System::ConsoleScreenBufferTesting::GetConsoleScreenBufferShareMode(size_t index) const
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return consoleScreenBufferShareModes.at(index % consoleScreenBufferShareModes.size());
}
