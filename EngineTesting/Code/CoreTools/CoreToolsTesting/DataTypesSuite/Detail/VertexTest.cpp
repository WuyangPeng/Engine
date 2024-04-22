/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/19 14:39)

#include "VertexTest.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::VertexTest::VertexTest() noexcept
    : previous{ 0 }, current{ 0 }, next{ 0 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::VertexTest::VertexTest(int previous, int current, int next) noexcept
    : previous{ previous }, current{ current }, next{ next }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, VertexTest)

int CoreTools::VertexTest::GetPrevious() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return previous;
}

int CoreTools::VertexTest::GetCurrent() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return current;
}

int CoreTools::VertexTest::GetNext() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return next;
}

void CoreTools::VertexTest::SetPrevious(int aPrevious) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    previous = aPrevious;
}

void CoreTools::VertexTest::SetCurrent(int aCurrent) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    current = aCurrent;
}

void CoreTools::VertexTest::SetNext(int aNext) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    next = aNext;
}

double CoreTools::VertexTest::GetWeight() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return previous * 1.0 + current * 5.0 + next * 2.0;
}
