///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/05 22:11)

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
    shuffle(desiredAccessGenerics.begin(), desiredAccessGenerics.end(), randomEngine);
    shuffle(consoleScreenBufferShareModes.begin(), consoleScreenBufferShareModes.end(), randomEngine);
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
