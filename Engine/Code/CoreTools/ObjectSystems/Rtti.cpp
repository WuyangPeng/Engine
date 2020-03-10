// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.2.1 (2020/01/21 15:55)

#include "CoreTools/CoreToolsExport.h"

#include "Rtti.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::Rtti
	::Rtti(const char* name, const Rtti* baseType)
	:m_Name{ name }, m_BaseType{ baseType }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::Rtti
	::IsValid() const noexcept
{
	if (m_Name != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

const char* CoreTools::Rtti
	::GetName() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Name;
}

bool CoreTools::Rtti
	::IsExactly(const Rtti& type) const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return (&type == this);
}

bool CoreTools::Rtti
	::IsDerived(const Rtti& type) const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	auto search = this;
	while (search != nullptr)
	{
		if (search == &type)
		{
			return true;
		}
		search = search->m_BaseType;
	}

	return false;
}

