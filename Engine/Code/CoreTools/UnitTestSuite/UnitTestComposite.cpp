///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/14 21:38)

#include "CoreTools/CoreToolsExport.h"

#include "UnitTestComposite.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::UnitTestComposite::UnitTestComposite(const OStreamShared& streamShared) noexcept
    : ParentType{ streamShared }, InterfaceType{}, m_TestLoopCount{ 0 }, m_RandomSeed{ 0 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::UnitTestComposite::UnitTestComposite(UnitTestComposite&& rhs) noexcept
    : ParentType{ std::move(rhs) }, InterfaceType{ std::move(rhs) }, m_TestLoopCount{ rhs.m_TestLoopCount }, m_RandomSeed{ rhs.m_RandomSeed }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::UnitTestComposite& CoreTools::UnitTestComposite::operator=(UnitTestComposite&& rhs) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (this != &rhs)
    {
        ParentType::operator=(std::move(rhs));
        InterfaceType::operator=(std::move(rhs));
        m_TestLoopCount = rhs.m_TestLoopCount;
        m_RandomSeed = rhs.m_RandomSeed;
    }

    return *this;
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
void CoreTools::UnitTestComposite::AddUnitTest(MAYBE_UNUSED const UnitTestCompositeSharedPtr& unitTest)
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

void CoreTools::UnitTestComposite::SetTestLoopCount(int testLoopCount) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    m_TestLoopCount = testLoopCount;
}

void CoreTools::UnitTestComposite::SetRandomSeed(int randomSeed) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    m_RandomSeed = randomSeed;
}

int CoreTools::UnitTestComposite::GetRandomSeed() const noexcept
{
    return m_RandomSeed + System::GetEngineeringOffsetValue();
}

uint32_t CoreTools::UnitTestComposite::GetEngineRandomSeed() const
{
    return boost::numeric_cast<uint32_t>(GetRandomSeed());
}
