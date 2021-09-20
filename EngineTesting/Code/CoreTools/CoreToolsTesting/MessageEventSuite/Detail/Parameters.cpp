// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 19:00)

#include "Parameters.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
 

using std::make_shared;

CoreTools::Parameters ::Parameters(int value) noexcept
    : m_Value{ value }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, Parameters)

int CoreTools::Parameters ::GetValue() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_Value;
}

void CoreTools::Parameters ::SetValue(int Value) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	m_Value = Value;
}

const CoreTools::Parameters::BaseSharedPtr CoreTools::Parameters
	::Clone() const
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	return CloneClassType();
}

const CoreTools::Parameters::ParametersSharedPtr CoreTools::Parameters
	::CloneClassType() const
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	return make_shared<ClassType>(*this);
}
