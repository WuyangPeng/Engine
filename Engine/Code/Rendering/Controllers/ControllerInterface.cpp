// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/23 14:41)

#include "Rendering/RenderingExport.h"

#include "ControllerInterface.h"

#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26418)
CORE_TOOLS_RTTI_DEFINE(Rendering,ControllerInterface);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering,ControllerInterface);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(Rendering,ControllerInterface);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, ControllerInterface);

Rendering::ControllerInterface
    ::ControllerInterface()
	:ParentType{ "ControllerInterface" }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

 

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering,ControllerInterface)

void Rendering::ControllerInterface ::AttachController([[maybe_unused]] ControllerInterfaceSmartPointer controller)
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_1(false,"Controller½ûÖ¹µ÷ÓÃAttachController");

	CoreTools::DoNothing();

	 
}

void Rendering::ControllerInterface ::DetachController([[maybe_unused]] ControllerInterfaceSmartPointer controller)
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_1(false,"Controller½ûÖ¹µ÷ÓÃDetachController");

	CoreTools::DoNothing();

	 
}

int Rendering::ControllerInterface
	::GetNumControllers () const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	CoreTools::DoNothing();

	return 0;
}

void Rendering::ControllerInterface
	::SetObjectInCopy(ControllerInterface* object) 
{
	RENDERING_CLASS_IS_VALID_1;

	CoreTools::DoNothing();

	SetObject(object);
}
