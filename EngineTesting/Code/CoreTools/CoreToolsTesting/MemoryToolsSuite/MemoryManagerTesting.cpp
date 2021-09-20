// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 12:20)

#include "MemoryManagerTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/MemoryTools/MemoryManager.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, MemoryManagerTesting)

void CoreTools::MemoryManagerTesting ::MainTest()
{
#if !defined(CORE_TOOLS_USE_MEMORY) && !defined(CORE_TOOLS_MEMORY_ALWAYS_CREATE)
    MEMORY_MANAGER_SINGLETON.Create();
#endif  // !defined(CORE_TOOLS_USE_MEMORY) && !defined(CORE_TOOLS_MEMORY_ALWAYS_CREATE)

    ASSERT_NOT_THROW_EXCEPTION_0(MemoryTest);

#if !defined(CORE_TOOLS_USE_MEMORY) && !defined(CORE_TOOLS_MEMORY_ALWAYS_CREATE)
    MEMORY_MANAGER_SINGLETON.Destroy();
#endif  // !defined(CORE_TOOLS_USE_MEMORY) && !defined(CORE_TOOLS_MEMORY_ALWAYS_CREATE)
}

void CoreTools::MemoryManagerTesting ::MemoryTest()
{
    constexpr auto dimensionsNumber = 1;
    constexpr auto dimensionsNumberMax = 4;
    constexpr auto bytesNumber = 10;

    for (auto i = dimensionsNumber; i <= dimensionsNumberMax; ++i)
    {
        const auto bytes = bytesNumber + i;
        auto block = MEMORY_MANAGER_SINGLETON.CreateBlock(bytes, i, CORE_TOOLS_FUNCTION_DESCRIBED);

        ASSERT_EQUAL(MEMORY_MANAGER_SINGLETON.GetMemBlockDimensions(block), i);
        ASSERT_EQUAL(boost::numeric_cast<int>(MEMORY_MANAGER_SINGLETON.GetBytesNumber(block)), bytesNumber + i);

        MEMORY_MANAGER_SINGLETON.Delete(block);
    }

    MEMORY_MANAGER_SINGLETON.PrintMemoryLeakInformation();
}
