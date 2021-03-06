// Copyright (c) 2010-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.1 (2020/05/21 14:50)

#ifndef FRAMEWORK_MIDDLE_LAYER_PHYSICAL_MODELLING_MANAGER_INTERFACE_H
#define FRAMEWORK_MIDDLE_LAYER_PHYSICAL_MODELLING_MANAGER_INTERFACE_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h" 
#include "EngineMiddleLayerInterface.h"  
#include "Framework/Helper/MiddleLayerMacro.h"

FRAMEWORK_EXPORT_SHARED_PTR(EngineMiddleLayerInterfaceImpl);

namespace Framework
{
	// 物理模拟（作用于游戏对象之上的物理力学及其效果的数学表达方式，如对象的碰撞以及分解）。移动除相机之外的全部游戏对象。
	class FRAMEWORK_DEFAULT_DECLARE PhysicalModellingManagerInterface : public EngineMiddleLayerInterface
	{
	public:
		using PhysicalModellingManagerInterfaceImpl = EngineMiddleLayerInterfaceImpl;
		NON_COPY_CLASSES_TYPE_DECLARE(PhysicalModellingManagerInterface);
		using ParentType = EngineMiddleLayerInterface;

	public:
		explicit PhysicalModellingManagerInterface(MiddleLayerPlatform middleLayerPlatform);

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		// 渲染中间层处理
		bool Paint() final;
		bool Move(const WindowPoint& point) final;
		bool Resize(WindowDisplay windowDisplay, const WindowSize& size) final;

		// 按键消息中间层处理
		bool KeyUp(int key, const WindowPoint& point) final;
		bool KeyDown(int key, const WindowPoint& point) final;
		bool SpecialKeyUp(int key, const WindowPoint& point) final;
		bool SpecialKeyDown(int key, const WindowPoint& point) final;

		// 鼠标消息中间层处理
		bool PassiveMotion(const WindowPoint& point) final;
		bool Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys) final;
		bool MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys) final;
		bool MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys) final;

		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(ObjectLogic);

	private:
		IMPL_TYPE_DECLARE(PhysicalModellingManagerInterface);
	};

	using PhysicalModellingManagerInterfaceSharedPtr = std::shared_ptr<PhysicalModellingManagerInterface>;
	using ConstPhysicalModellingManagerInterfaceSharedPtr = std::shared_ptr<const PhysicalModellingManagerInterface>;
}

#endif // FRAMEWORK_MIDDLE_LAYER_PHYSICAL_MODELLING_MANAGER_INTERFACE_H

