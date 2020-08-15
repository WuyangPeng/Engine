// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/21 15:49)

#include "CoreTools/CoreToolsExport.h"

#include "ObjectNameImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

CoreTools::ObjectNameImpl
	::ObjectNameImpl(const string& name)
	:m_Name{ name }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ObjectNameImpl)

const string& CoreTools::ObjectNameImpl
	::GetName() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_Name;
}

bool CoreTools::ObjectNameImpl
	::IsExactly(const ClassType& name) const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return GetName() == name.GetName();
}

void CoreTools::ObjectNameImpl
	::SetName(const string& name)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	m_Name = name;
}



