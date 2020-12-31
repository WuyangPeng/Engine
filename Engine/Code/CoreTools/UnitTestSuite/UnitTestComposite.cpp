//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/23 14:54)

#include "CoreTools/CoreToolsExport.h"

#include "UnitTestComposite.h"

#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::UnitTestComposite::UnitTestComposite(const OStreamShared& streamShared) noexcept
    : ParentType{ streamShared }, InterfaceType{}, m_TestLoopCount{ 0 }, m_RandomSeed{ 0 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::UnitTestComposite::IsValid() const noexcept
{
    if (ParentType::IsValid() && 0 <= m_TestLoopCount)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

void CoreTools::UnitTestComposite::ClearUnitTestCollection()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    THROW_EXCEPTION(SYSTEM_TEXT("禁止调用UnitTestComposite::ClearUnitTestCollection()！"s));
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26418)
void CoreTools::UnitTestComposite::AddUnitTest([[maybe_unused]] const UnitTestCompositeSharedPtr& unitTest)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    THROW_EXCEPTION(SYSTEM_TEXT("禁止调用UnitTestComposite::AddUnitTest()！"s));
}
#include STSTEM_WARNING_POP

int CoreTools::UnitTestComposite::GetTestLoopCount() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_TestLoopCount;
}

void CoreTools::UnitTestComposite::SetTestLoopCount(int TestLoopCount) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    m_TestLoopCount = TestLoopCount;
}

void CoreTools::UnitTestComposite::SetRandomSeed(int randomSeed) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    m_RandomSeed = randomSeed;
}

int CoreTools::UnitTestComposite::GetEngineeringOffsetValue() const noexcept
{
    int offsetValue{ 0 };

    ++offsetValue;

#ifdef _DEBUG
    offsetValue += 4;
#endif  // _DEBUG

#ifdef BUILDING_CORE_TOOLS_STATIC
    offsetValue += 2;
#endif  // BUILDING_CORE_TOOLS_STATIC

#ifdef _WIN64
    offsetValue += 1;
#endif  // _WIN64

    return offsetValue;
}

int CoreTools::UnitTestComposite::GetRandomSeed() const noexcept
{
    return m_RandomSeed + GetEngineeringOffsetValue();
}

uint32_t CoreTools::UnitTestComposite::GetEngineRandomSeed() const
{
    return boost::numeric_cast<uint32_t>(GetRandomSeed());
}