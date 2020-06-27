// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.1 (2020/05/21 14:48)

#ifndef FRAMEWORK_MIDDLE_LAYER_EVENT_MANAGER_INTERFACE_H
#define FRAMEWORK_MIDDLE_LAYER_EVENT_MANAGER_INTERFACE_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h" 
#include "EngineMiddleLayerInterface.h"  
#include "Framework/Helper/MiddleLayerMacro.h"

FRAMEWORK_EXPORT_SHARED_PTR(EngineMiddleLayerInterfaceImpl);

namespace Framework
{
	// 游戏事件管理（针对游戏元素中设计者所规定的操作序列进行管理）。
	class FRAMEWORK_DEFAULT_DECLARE EventManagerInterface : public EngineMiddleLayerInterface
	{
	public:
		using EventManagerInterfaceImpl = EngineMiddleLayerInterfaceImpl;
		NON_COPY_CLASSES_TYPE_DECLARE(EventManagerInterface);
		using ParentType = EngineMiddleLayerInterface;

	public:
		explicit EventManagerInterface(MiddleLayerPlatform middleLayerPlatform);

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

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

		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Message);
		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(System);

	private:
		IMPL_TYPE_DECLARE(EventManagerInterface);
	};

	using EventManagerInterfaceSharedPtr = std::shared_ptr<EventManagerInterface>;
	using ConstEventManagerInterfaceSharedPtr = std::shared_ptr<const EventManagerInterface>;
}

#endif // FRAMEWORK_MIDDLE_LAYER_EVENT_MANAGER_INTERFACE_H

