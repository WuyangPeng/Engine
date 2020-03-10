// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/08/01 13:07)

#include "Framework/FrameworkExport.h"

#include "EngineMiddleLayerInterface.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "System/Helper/UnusedMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Framework::EngineMiddleLayerInterface
	::EngineMiddleLayerInterface()
	:ParentType{} 
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::EngineMiddleLayerInterface
	::~EngineMiddleLayerInterface()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, EngineMiddleLayerInterface)

void Framework::EngineMiddleLayerInterface
	::SetNetworkManager(MiddleLayerInterfaceSmartPointer& networkManager)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(networkManager);

	THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"));
}

void Framework::EngineMiddleLayerInterface
	::SetInputManager(MiddleLayerInterfaceSmartPointer& inputManager)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(inputManager);

	THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"));
}

void Framework::EngineMiddleLayerInterface
	::SetObjectLogicManager(MiddleLayerInterfaceSmartPointer& objectLogicManager)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(objectLogicManager);

	THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"));
}

void Framework::EngineMiddleLayerInterface
	::SetPhysicalModellingManager(MiddleLayerInterfaceSmartPointer& physicalModellingManager)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(physicalModellingManager);

	THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"));
}

void Framework::EngineMiddleLayerInterface
	::SetMessageManager(MiddleLayerInterfaceSmartPointer& messageManager)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(messageManager);

	THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"));
}

void Framework::EngineMiddleLayerInterface
	::SetEventManager(MiddleLayerInterfaceSmartPointer& eventManager)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(eventManager);

	THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"));
}

void Framework::EngineMiddleLayerInterface
	::SetSystemManager(MiddleLayerInterfaceSmartPointer& systemManager)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(systemManager);

	THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"));
}

void Framework::EngineMiddleLayerInterface
	::SetResourceManager(MiddleLayerInterfaceSmartPointer& resourceManager)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(resourceManager);

	THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"));
}

void Framework::EngineMiddleLayerInterface
	::SetAudioManager(MiddleLayerInterfaceSmartPointer& audioManager)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(audioManager);

	THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"));
}

void Framework::EngineMiddleLayerInterface
	::SetCameraSystemsManager(MiddleLayerInterfaceSmartPointer& cameraSystemsManager)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(cameraSystemsManager);

	THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"));
}

void Framework::EngineMiddleLayerInterface
	::SetRenderingManager(MiddleLayerInterfaceSmartPointer& renderingManager)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(renderingManager);

	THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"));
}

void Framework::EngineMiddleLayerInterface
	::SetGUIManager(MiddleLayerInterfaceSmartPointer& guiManager)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(guiManager);

	THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"));
}

const Framework::MiddleLayerInterfaceSmartPointer Framework::EngineMiddleLayerInterface
	::GetNetworkManager()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"));
}

const Framework::ConstMiddleLayerInterfaceSmartPointer Framework::EngineMiddleLayerInterface
	::GetConstNetworkManager() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"));
}

const Framework::MiddleLayerInterfaceSmartPointer Framework::EngineMiddleLayerInterface
	::GetInputManager()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"));
}

const Framework::ConstMiddleLayerInterfaceSmartPointer Framework::EngineMiddleLayerInterface
	::GetConstInputManager() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"));
}

const Framework::MiddleLayerInterfaceSmartPointer Framework::EngineMiddleLayerInterface
	::GetObjectLogicManager()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"));
}

const Framework::ConstMiddleLayerInterfaceSmartPointer Framework::EngineMiddleLayerInterface
	::GetConstObjectLogicManager() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"));
}

const Framework::MiddleLayerInterfaceSmartPointer Framework::EngineMiddleLayerInterface
	::GetPhysicalModellingManager()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"));
}

const Framework::ConstMiddleLayerInterfaceSmartPointer Framework::EngineMiddleLayerInterface
	::GetConstPhysicalModellingManager() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"));
}

const Framework::MiddleLayerInterfaceSmartPointer Framework::EngineMiddleLayerInterface
	::GetMessageManager()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"));
}

const Framework::ConstMiddleLayerInterfaceSmartPointer Framework::EngineMiddleLayerInterface
	::GetConstMessageManager() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"));
}

const Framework::MiddleLayerInterfaceSmartPointer Framework::EngineMiddleLayerInterface
	::GetEventManager()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"));
}

const Framework::ConstMiddleLayerInterfaceSmartPointer Framework::EngineMiddleLayerInterface
	::GetConstEventManager() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"));
}

const Framework::MiddleLayerInterfaceSmartPointer Framework::EngineMiddleLayerInterface
	::GetSystemManager()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"));
}

const Framework::ConstMiddleLayerInterfaceSmartPointer Framework::EngineMiddleLayerInterface
	::GetConstSystemManager() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"));
}

const Framework::MiddleLayerInterfaceSmartPointer Framework::EngineMiddleLayerInterface
	::GetResourceManager()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"));
}

const Framework::ConstMiddleLayerInterfaceSmartPointer Framework::EngineMiddleLayerInterface
	::GetConstResourceManager() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"));
}

const Framework::MiddleLayerInterfaceSmartPointer Framework::EngineMiddleLayerInterface
	::GetAudioManager()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"));
}

const Framework::ConstMiddleLayerInterfaceSmartPointer Framework::EngineMiddleLayerInterface
	::GetConstAudioManager() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"));
}

const Framework::MiddleLayerInterfaceSmartPointer Framework::EngineMiddleLayerInterface
	::GetCameraSystemsManager()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"));
}

const Framework::ConstMiddleLayerInterfaceSmartPointer Framework::EngineMiddleLayerInterface
	::GetConstCameraSystemsManager() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"));
}

const Framework::MiddleLayerInterfaceSmartPointer Framework::EngineMiddleLayerInterface
	::GetRenderingManager()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"));
}

const Framework::ConstMiddleLayerInterfaceSmartPointer Framework::EngineMiddleLayerInterface
	::GetConstRenderingManager() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"));
}

const Framework::MiddleLayerInterfaceSmartPointer Framework::EngineMiddleLayerInterface
	::GetGUIManager()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"));
}

const Framework::ConstMiddleLayerInterfaceSmartPointer Framework::EngineMiddleLayerInterface
	::GetConstGUIManager() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	THROW_EXCEPTION(SYSTEM_TEXT("函数被禁止调用。"));
}

 