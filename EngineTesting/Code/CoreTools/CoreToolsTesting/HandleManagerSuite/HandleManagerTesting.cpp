// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 17:16)

#include "HandleManagerTesting.h"
#include "Detail/HandleManagerTestData.h"
#include "Detail/ResourceHandleTestTag.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, HandleManagerTesting)

void CoreTools::HandleManagerTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AcquireExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ReleaseExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DereferenceExceptionTest);
}

void CoreTools::HandleManagerTesting ::SucceedTest() noexcept
{
}

void CoreTools::HandleManagerTesting ::AcquireExceptionTest() noexcept
{
}

void CoreTools::HandleManagerTesting ::ReleaseExceptionTest() noexcept
{
}

void CoreTools::HandleManagerTesting ::DereferenceExceptionTest() noexcept
{
}
