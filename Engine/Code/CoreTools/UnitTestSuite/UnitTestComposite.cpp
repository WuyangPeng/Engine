// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.2 (2020/01/22 10:30)

#include "CoreTools/CoreToolsExport.h"

#include "UnitTestComposite.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::ostream;

CoreTools::UnitTestComposite
	::UnitTestComposite(const OStreamShared& osPtr) noexcept
	:ParentType{ osPtr }, InterfaceType{}, m_TestLoopCount{ 0 }, m_RandomSeed{ 0 }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

 

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::UnitTestComposite
	::IsValid() const noexcept
{
	if (ParentType::IsValid() && 0 <= m_TestLoopCount)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26418)
#include SYSTEM_WARNING_DISABLE(26440)
void CoreTools::UnitTestComposite
	::ClearUnitTestCollection()
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	CORE_TOOLS_ASSERTION_4(false, "禁止调用UnitTestComposite::ClearUnitTestCollection()！");
}

void CoreTools::UnitTestComposite
	::AddUnitTest(UnitTestCompositePtr unitTest)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	CORE_TOOLS_ASSERTION_4(false, "禁止调用UnitTestComposite::AddUnitTest()！");

	SYSTEM_UNUSED_ARG(unitTest);
}
#include STSTEM_WARNING_POP
int CoreTools::UnitTestComposite
	::GetTestLoopCount() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_TestLoopCount;
}

void CoreTools::UnitTestComposite
	::SetTestLoopCount(int TestLoopCount) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	m_TestLoopCount = TestLoopCount;
}

void CoreTools::UnitTestComposite
	::SetRandomSeed(int randomSeed) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	m_RandomSeed = randomSeed;
}

int CoreTools::UnitTestComposite
	::GetEngineeringOffsetValue() const noexcept
{
	int offsetValue{ 0 };

	++offsetValue;

#ifdef _DEBUG
	offsetValue += 4;
#endif // _DEBUG

#ifdef BUILDING_CORE_TOOLS_STATIC
	offsetValue += 2;
#endif // BUILDING_CORE_TOOLS_STATIC

#ifdef _WIN64
	offsetValue += 1;
#endif // _WIN64

	return offsetValue;
}
 
int CoreTools::UnitTestComposite
	::GetRandomSeed() const noexcept
{
	return m_RandomSeed + GetEngineeringOffsetValue();
}

uint32_t CoreTools::UnitTestComposite
	::GetEngineRandomSeed() const
{
	return boost::numeric_cast<uint32_t>(GetRandomSeed());
}