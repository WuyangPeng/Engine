// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:52)

#ifndef FRAMEWORK_MIDDLE_LAYER_OBJECT_LOGIC_MANAGER_H
#define FRAMEWORK_MIDDLE_LAYER_OBJECT_LOGIC_MANAGER_H

#include "ObjectLogicManagerInterface.h"

namespace Framework
{	
	template<typename ObjectLogic, typename  ArtificialIntellegence>
	class ObjectLogicManager : public ObjectLogicManagerInterface
	{	
	public:
		using ClassType = ObjectLogicManager<ObjectLogic, ArtificialIntellegence>;
		using ParentType = ObjectLogicManagerInterface;

	public:
		ObjectLogicManager();
		virtual ~ObjectLogicManager();
	
		CLASS_INVARIANT_VIRTUAL_DECLARE;
		
		virtual bool PreCreate();
		virtual bool Initialize();
		virtual void PreIdle();
		virtual void Terminate();		
		
		virtual bool Create();
		virtual bool Destroy();
		virtual bool Idle(int64_t timeDelta);

		virtual void SetNetworkManager(MiddleLayerInterfaceSmartPointer& networkManager);
		virtual void SetInputManager(MiddleLayerInterfaceSmartPointer& inputManager);
		virtual void SetMessageManager(MiddleLayerInterfaceSmartPointer& messageManager);
		virtual void SetPhysicalModellingManager(MiddleLayerInterfaceSmartPointer& physicalModellingManager);
		virtual void SetSystemManager(MiddleLayerInterfaceSmartPointer& systemManager);

	private:
		ObjectLogic m_ObjectLogic;
		ArtificialIntellegence m_ArtificialIntellegence;
	};
}

#endif // FRAMEWORK_MIDDLE_LAYER_OBJECT_LOGIC_MANAGER_H

