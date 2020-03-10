// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:47)

#ifndef FRAMEWORK_MIDDLE_LAYER_ENGINE_MIDDLE_LAYER_INTERFACE_H
#define FRAMEWORK_MIDDLE_LAYER_ENGINE_MIDDLE_LAYER_INTERFACE_H

#include "Framework/FrameworkDll.h"

#include "MiddleLayerInterface.h"

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE EngineMiddleLayerInterface : public MiddleLayerInterface
	{	
	public:
		using ClassType = EngineMiddleLayerInterface;
		using ParentType = MiddleLayerInterface;

	public:
		EngineMiddleLayerInterface();
		virtual ~EngineMiddleLayerInterface();
	
		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual void SetNetworkManager(MiddleLayerInterfaceSmartPointer& networkManager);
		virtual void SetInputManager(MiddleLayerInterfaceSmartPointer& inputManager);
		virtual void SetObjectLogicManager(MiddleLayerInterfaceSmartPointer& objectLogicManager);
		virtual void SetPhysicalModellingManager(MiddleLayerInterfaceSmartPointer& physicalModellingManager);
		virtual void SetMessageManager(MiddleLayerInterfaceSmartPointer& messageManager);
		virtual void SetEventManager(MiddleLayerInterfaceSmartPointer& eventManager);
		virtual void SetSystemManager(MiddleLayerInterfaceSmartPointer& systemManager);
		virtual void SetResourceManager(MiddleLayerInterfaceSmartPointer& resourceManager);
		virtual void SetAudioManager(MiddleLayerInterfaceSmartPointer& audioManager);
		virtual void SetCameraSystemsManager(MiddleLayerInterfaceSmartPointer& cameraSystemsManager);
		virtual void SetRenderingManager(MiddleLayerInterfaceSmartPointer& renderingManager);
		virtual void SetGUIManager(MiddleLayerInterfaceSmartPointer& guiManager);

	protected:
		virtual const MiddleLayerInterfaceSmartPointer GetNetworkManager();
		virtual const MiddleLayerInterfaceSmartPointer GetInputManager();
		virtual const MiddleLayerInterfaceSmartPointer GetObjectLogicManager();
		virtual const MiddleLayerInterfaceSmartPointer GetPhysicalModellingManager();
		virtual const MiddleLayerInterfaceSmartPointer GetMessageManager();
		virtual const MiddleLayerInterfaceSmartPointer GetEventManager();
		virtual const MiddleLayerInterfaceSmartPointer GetSystemManager();
		virtual const MiddleLayerInterfaceSmartPointer GetResourceManager();
		virtual const MiddleLayerInterfaceSmartPointer GetAudioManager();
		virtual const MiddleLayerInterfaceSmartPointer GetCameraSystemsManager();
		virtual const MiddleLayerInterfaceSmartPointer GetRenderingManager();
		virtual const MiddleLayerInterfaceSmartPointer GetGUIManager();

		virtual const ConstMiddleLayerInterfaceSmartPointer GetConstNetworkManager() const;
		virtual const ConstMiddleLayerInterfaceSmartPointer GetConstInputManager() const;
		virtual const ConstMiddleLayerInterfaceSmartPointer GetConstObjectLogicManager() const;
		virtual const ConstMiddleLayerInterfaceSmartPointer GetConstPhysicalModellingManager() const;
		virtual const ConstMiddleLayerInterfaceSmartPointer GetConstMessageManager() const;
		virtual const ConstMiddleLayerInterfaceSmartPointer GetConstEventManager() const;
		virtual const ConstMiddleLayerInterfaceSmartPointer GetConstSystemManager() const;
		virtual const ConstMiddleLayerInterfaceSmartPointer GetConstResourceManager() const;
		virtual const ConstMiddleLayerInterfaceSmartPointer GetConstAudioManager() const;
		virtual const ConstMiddleLayerInterfaceSmartPointer GetConstCameraSystemsManager() const;
		virtual const ConstMiddleLayerInterfaceSmartPointer GetConstRenderingManager() const;
		virtual const ConstMiddleLayerInterfaceSmartPointer GetConstGUIManager() const;
	};

	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Second,EngineMiddleLayerInterface);
}

#endif // FRAMEWORK_MIDDLE_LAYER_ENGINE_MIDDLE_LAYER_INTERFACE_H

