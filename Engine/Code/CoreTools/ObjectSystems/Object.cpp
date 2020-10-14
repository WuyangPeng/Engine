// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/21 15:53)

#include "CoreTools/CoreToolsExport.h"

#include "Object.h"
#include "InitTerm.h"
#include "BufferInStream.h"
#include "ObjectManager.h"
#include "ObjectRegister.h"
#include "BufferSource.h"
#include "BufferTargetDetail.h"

#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/MemoryTools/SmartPointerManager.h"
 

using std::string;
using std::vector;
using std::swap;

#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Contract/Noexcept.h"
#include "../Helper/ExceptionMacro.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
CORE_TOOLS_RTTI_DEFINE(CoreTools, Object);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(CoreTools, Object);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(CoreTools, Object);

CoreTools::Object
	::Object(const string& name)
	:ParentType{},
	m_Name{ name }
{
	SetUniqueID(OBJECT_MANAGER_SINGLETON.NextUniqueID());

	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::Object
	::Object(LoadConstructor value)
	:ParentType{ value },
	m_Name{""}
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

 
CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, Object);

// 名字
  string  CoreTools::Object
	::GetName() const  
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_Name.GetName();
}

void CoreTools::Object
	::SetName(const string& name)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	m_Name.SetName(name);
}

// private
void CoreTools::Object
	::Swap(Object& rhs) noexcept
{
    m_Name.SwapObjectName(rhs.m_Name);
}

int CoreTools::Object
	::GetStreamingSize() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	// RTTI名
	int size = CORE_TOOLS_STREAM_SIZE(GetRttiType().GetName());

	// UniqueID
	size += CORE_TOOLS_STREAM_SIZE(this);

	// 对象名
	size += CORE_TOOLS_STREAM_SIZE(m_Name.GetName());

	return size;
}

uint64_t CoreTools::Object ::Register(const CoreTools::ObjectRegisterSharedPtr& target) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	if (SMART_POINTER_SINGLETON.IsSmartPointer(this))
	{
		return target->RegisterRoot(ConstObjectInterfaceSharedPtr{ this });
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("要注册的指针不是由SmartPointer系统创建。"s));
	}
}

void CoreTools::Object
	::Save(const BufferTargetSharedPtr& target) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

	// 写入RTTI名用于加载期间查找工厂函数。
	target->Write(GetRttiType().GetName());

	// 写入对象的唯一标识符。这是加载和链接时使用。
	if (SMART_POINTER_SINGLETON.IsSmartPointer(this))
	{
		ConstObjectInterfaceSharedPtr smartPointer{ this };

		target->WriteUniqueID(smartPointer);
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("要写入的指针不是由SmartPointer系统创建。"s));
	}

	// 写入对象的名字。
	target->Write(m_Name.GetName());

	CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void CoreTools::Object ::Link([[maybe_unused]]const ObjectLinkSharedPtr& source)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	// Object没有Object*成员。

 
	CoreTools::DisableNoexcept();
}

void CoreTools::Object
	::PostLink()
{
	// Object 没有后链接语义。

	CORE_TOOLS_CLASS_IS_VALID_9;

	CoreTools::DisableNoexcept();
}

void CoreTools::Object ::Load(const BufferSourceSharedPtr& source)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

	// RTTI名已经在流中读取，以查找正确的对象加载函数。

	// 读取的对象的唯一标识符。这提供信息在链接阶段。 
	if (SMART_POINTER_SINGLETON.IsSmartPointer(this))
	{
		ObjectInterfaceSharedPtr smartPointer{ this };

		source->ReadUniqueID(smartPointer);
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("要载入的指针不是由SmartPointer系统创建。"s));
	}

	// 读取对象名字。
        auto name = source->ReadString();

	SetName(name);

	CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

const CoreTools::ObjectSharedPtr CoreTools::Object
	::GetObjectByName(const string& name)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	if (name == m_Name.GetName() && SMART_POINTER_SINGLETON.IsSmartPointer(this))
		return ObjectSharedPtr{ this };
	else
		return ObjectSharedPtr{};
}

const vector<CoreTools::ObjectSharedPtr> CoreTools::Object
	::GetAllObjectsByName(const string& name)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	vector<ObjectSharedPtr> objects{};

	if (name == m_Name.GetName() && SMART_POINTER_SINGLETON.IsSmartPointer(this))
	{
		objects.emplace_back(this);
	}

	return objects;
}

const CoreTools::ConstObjectSharedPtr CoreTools::Object
	::GetConstObjectByName(const string& name) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	if (name == m_Name.GetName() && SMART_POINTER_SINGLETON.IsSmartPointer(this))
		return ConstObjectSharedPtr{ this };
	else
		return ConstObjectSharedPtr{};
}

const vector<CoreTools::ConstObjectSharedPtr> CoreTools::Object
	::GetAllConstObjectsByName(const string& name) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	vector<ConstObjectSharedPtr> objects;

	if (name == m_Name.GetName() && SMART_POINTER_SINGLETON.IsSmartPointer(this))
	{
		objects.emplace_back(this);
	}

	return objects;
}
#include STSTEM_WARNING_POP