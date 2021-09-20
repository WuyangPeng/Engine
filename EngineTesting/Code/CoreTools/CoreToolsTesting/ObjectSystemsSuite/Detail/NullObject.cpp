// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.0.2.3 (2020/03/06 14:12)

#include "NullObject.h"

#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/BufferSource.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/ObjectRegister.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/MemoryTools/SmartPointerManager.h"

CORE_TOOLS_RTTI_DEFINE(CoreTools, NullObject);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(CoreTools, NullObject);
CORE_TOOLS_FACTORY_DEFINE(CoreTools, NullObject);
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26432)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26456)
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
CoreTools::NullObject
	::NullObject()
	:ParentType{}
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::NullObject
	::NullObject(LoadConstructor value)
	:ParentType{ value }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::NullObject
	::~NullObject()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, NullObject);

int CoreTools::NullObject
	::GetStreamingSize() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	// RTTI名
	auto size = CORE_TOOLS_STREAM_SIZE(GetRttiType().GetName());

	// UniqueID
	size += CORE_TOOLS_STREAM_SIZE(this);

	return size;
}

uint64_t CoreTools::NullObject
	::Register([[maybe_unused]] const ObjectRegisterSharedPtr& target) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	if (SMART_POINTER_SINGLETON.IsSmartPointer(this))
	{
            return 0;
           // target.RegisterRoot(ConstObjectInterfaceSmartPointer{ this });
	}
	else
	{
		THROW_WINDOWS_EXCEPTION;
	}
}

void CoreTools::NullObject ::Save([[maybe_unused]] const BufferTargetSharedPtr& target) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

	//target.WriteString(GetRttiType().GetName());

	if (SMART_POINTER_SINGLETON.IsSmartPointer(this))
	{
		//target.WriteUniqueID(ConstObjectInterfaceSmartPointer{ this });
	}
	else
	{
		THROW_WINDOWS_EXCEPTION;
	}

	CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void CoreTools::NullObject
	::Link([[maybe_unused]] const ObjectLinkSharedPtr& source)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	 
}

void CoreTools::NullObject
	::PostLink()
{
	CORE_TOOLS_CLASS_IS_VALID_9;
}

void CoreTools::NullObject ::Load([[maybe_unused]] const BufferSourceSharedPtr& source)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

	// RTTI名已经在流中读取，以查找正确的对象加载函数。

	// 读取的对象的唯一标识符。这提供信息在链接阶段。
	if (SMART_POINTER_SINGLETON.IsSmartPointer(this))
	{
		//ObjectInterfaceSmartPointer smartPointer(this);

		//source.ReadUniqueID(smartPointer);
	}
	else
	{
		THROW_WINDOWS_EXCEPTION;
	}
	
	CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

CoreTools::ObjectInterfaceSharedPtr CoreTools::NullObject::CloneObject() const
{
    return nullptr;
}

#include STSTEM_WARNING_POP

