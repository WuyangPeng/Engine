// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.2.1 (2020/01/21 15:54)

#include "CoreTools/CoreToolsExport.h"

#include "ObjectInterface.h"
#include "BufferInStream.h"
#include "InitTerm.h"
#include "ObjectManager.h"
#include "System/Helper/UnusedMacro.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

CoreTools::ObjectInterface
	::ObjectInterface() noexcept
	:m_UniqueID{ 0 }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::ObjectInterface
	::ObjectInterface(LoadConstructor value) noexcept
	:m_UniqueID{ 0 }
{
	SYSTEM_UNUSED_ARG(value);

	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::ObjectInterface
	::~ObjectInterface()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ObjectInterface);

CORE_TOOLS_RTTI_BASE_DEFINE(CoreTools, ObjectInterface);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(CoreTools, ObjectInterface);

bool CoreTools::ObjectInterface
	::sm_StreamRegistered{ false };

// static
bool CoreTools::ObjectInterface
	::RegisterFactory()
{
	if (!sm_StreamRegistered)
	{
		InitTerm::AddInitializer(ClassType::InitializeFactory);
		InitTerm::AddTerminator(ClassType::TerminateFactory);

		sm_StreamRegistered = true;
	}

	return sm_StreamRegistered;
}

// static
void CoreTools::ObjectInterface
	::InitializeFactory()
{
	OBJECT_MANAGER_SINGLETON.Insert(sm_Type.GetName(), Factory);
}

// static
void CoreTools::ObjectInterface
	::TerminateFactory()
{
	OBJECT_MANAGER_SINGLETON.Remove(sm_Type.GetName());
}

uint64_t CoreTools::ObjectInterface
	::GetUniqueID() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_UniqueID;
}

void CoreTools::ObjectInterface
	::SetUniqueID(uint64_t uniqueID) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	m_UniqueID = uniqueID;
}

bool CoreTools::ObjectInterface
	::IsExactly(const Rtti& type) const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return GetRttiType().IsExactly(type);
}

bool CoreTools::ObjectInterface
	::IsDerived(const Rtti& type) const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return GetRttiType().IsDerived(type);
}

bool CoreTools::ObjectInterface
	::IsExactlyTypeOf(const ObjectInterface* object) const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return object != nullptr && GetRttiType().IsExactly(object->GetRttiType());
}

bool CoreTools::ObjectInterface
	::IsDerivedTypeOf(const ObjectInterface* object) const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return object != nullptr && GetRttiType().IsDerived(object->GetRttiType());
}

#include STSTEM_WARNING_POP