// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ²âÊÔ°æ±¾£º0.0.2.3 (2020/03/06 17:15)

#include "HandleManagerTestData.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

CoreTools::HandleManagerTestData
	::HandleManagerTestData(const string& name)
	:m_Name{ name }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, HandleManagerTestData)

void CoreTools::HandleManagerTestData ::Reset() noexcept
{
	m_Name.clear();
}

void CoreTools::HandleManagerTestData
	::Reset(const string& name)
{
	m_Name = name;
}