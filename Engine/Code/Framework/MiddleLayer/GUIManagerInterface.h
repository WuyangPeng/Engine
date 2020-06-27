// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.1 (2020/05/21 14:48)

#ifndef FRAMEWORK_MIDDLE_LAYER_GUI_MANAGER_INTERFACE_H
#define FRAMEWORK_MIDDLE_LAYER_GUI_MANAGER_INTERFACE_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h" 
#include "EngineMiddleLayerInterface.h"  
#include "Framework/Helper/MiddleLayerMacro.h"

FRAMEWORK_EXPORT_SHARED_PTR(EngineMiddleLayerInterfaceImpl);

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE GUIManagerInterface : public EngineMiddleLayerInterface
	{
	public:
		using GUIManagerInterfaceImpl = EngineMiddleLayerInterfaceImpl;
		NON_COPY_CLASSES_TYPE_DECLARE(GUIManagerInterface);
		using ParentType = EngineMiddleLayerInterface;

	public:
		explicit GUIManagerInterface(MiddleLayerPlatform middleLayerPlatform);

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

		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Rendering);

	private:
		IMPL_TYPE_DECLARE(GUIManagerInterface);
	};

	using GUIManagerInterfaceSharedPtr = std::shared_ptr<GUIManagerInterface>;
	using ConstGUIManagerInterfaceSharedPtr = std::shared_ptr<const GUIManagerInterface>;
}

#endif // FRAMEWORK_MIDDLE_LAYER_GUI_MANAGER_INTERFACE_H

