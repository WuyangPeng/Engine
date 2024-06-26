/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 11:23)

#include "CoreTools/CoreToolsExport.h"

#include "UnitTestComposite.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::UnitTestComposite::UnitTestComposite(const OStreamShared& streamShared) noexcept
    : ParentType{ streamShared }, InterfaceType{}, testLoopCount{ 0 }, randomSeed{ 0 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::UnitTestComposite::UnitTestComposite(UnitTestComposite&& rhs) noexcept
    : ParentType{ std::move(rhs) }, InterfaceType{ std::move(rhs) }, testLoopCount{ rhs.testLoopCount }, randomSeed{ rhs.randomSeed }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::UnitTestComposite& CoreTools::UnitTestComposite::operator=(UnitTestComposite&& rhs) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (this != &rhs)
    {
        testLoopCount = rhs.testLoopCount;
        randomSeed = rhs.randomSeed;

        ParentType::operator=(std::move(rhs));
    }

    return *this;
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::UnitTestComposite::IsValid() const noexcept
{
    return ParentType::IsValid() && 0 <= testLoopCount;
}

#endif  // OPEN_CLASS_INVARIANT

void CoreTools::UnitTestComposite::ClearUnitTestCollection()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    THROW_EXCEPTION(SYSTEM_TEXT("禁止调用UnitTestComposite::ClearUnitTestCollection()！"s))
}

void CoreTools::UnitTestComposite::AddUnitTest(const UnitTestCompositeSharedPtr& unitTest)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    System::UnusedFunction(unitTest);

    THROW_EXCEPTION(SYSTEM_TEXT("禁止调用UnitTestComposite::AddUnitTest()！"s))
}

int CoreTools::UnitTestComposite::GetTestLoopCount() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return testLoopCount;
}

void CoreTools::UnitTestComposite::SetTestLoopCount(int aTestLoopCount) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    testLoopCount = aTestLoopCount;
}

void CoreTools::UnitTestComposite::SetRandomSeed(int aRandomSeed) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    randomSeed = aRandomSeed;
}

uint32_t CoreTools::UnitTestComposite::GetEngineRandomSeed() const
{
    return boost::numeric_cast<uint32_t>(randomSeed + System::GetEngineeringOffsetValue());
}
