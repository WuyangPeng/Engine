// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 14:50)

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
		using ClassShareType = CoreTools::NonCopyClasses;

	public:
		explicit ObjectLogicManager(MiddleLayerPlatform middleLayerPlatform);

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		bool PreCreate(const EnvironmentDirectory& environmentDirectory) override;
		bool Initialize() override;
		void PreIdle() override;
		void Terminate() override;

		bool Create() override;
		bool Destroy() override;
		bool Idle(int64_t timeDelta) override;

		void SetNetworkManager(const MiddleLayerInterfaceSharedPtr& networkManager) override;
		void SetInputManager(const MiddleLayerInterfaceSharedPtr& inputManager) override;
		void SetMessageManager(const MiddleLayerInterfaceSharedPtr& messageManager) override;
		void SetPhysicalModellingManager(const MiddleLayerInterfaceSharedPtr& physicalModellingManager) override;
		void SetSystemManager(const MiddleLayerInterfaceSharedPtr& systemManager) override;

	private:
		ObjectLogic m_ObjectLogic;
		ArtificialIntellegence m_ArtificialIntellegence;
	};
}

#endif // FRAMEWORK_MIDDLE_LAYER_OBJECT_LOGIC_MANAGER_H

