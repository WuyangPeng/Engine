// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ²âÊÔ°æ±¾£º0.0.2.3 (2020/03/06 12:20)

#include "MemoryManagerTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, MemoryManagerTesting)

void CoreTools::MemoryManagerTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MemoryTest);
}

void CoreTools::MemoryManagerTesting ::MemoryTest() noexcept
{
}
