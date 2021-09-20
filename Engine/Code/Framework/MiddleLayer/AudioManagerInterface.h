// Copyright (c) 2010-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.1 (2020/05/21 14:47)

#ifndef FRAMEWORK_MIDDLE_LAYER_AUDIO_MANAGER_INTERFACE_H
#define FRAMEWORK_MIDDLE_LAYER_AUDIO_MANAGER_INTERFACE_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h" 
#include "EngineMiddleLayerInterface.h"  
#include "Framework/Helper/MiddleLayerMacro.h"

FRAMEWORK_NON_COPY_EXPORT_IMPL(EngineMiddleLayerInterfaceImpl);

namespace Framework
{
	// 音频管理（音效处理过程，包括简单的音频回放以及空间定位功能）。
	class FRAMEWORK_DEFAULT_DECLARE AudioManagerInterface : public EngineMiddleLayerInterface
	{
	public:
		using AudioManagerInterfaceImpl = EngineMiddleLayerInterfaceImpl;
		NON_COPY_TYPE_DECLARE(AudioManagerInterface);
		using ParentType = EngineMiddleLayerInterface;

	public:
		explicit AudioManagerInterface(MiddleLayerPlatform middleLayerPlatform);

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

		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(System);
		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Resource);

	private:
                PackageType impl;
	};

	using AudioManagerInterfaceSharedPtr = std::shared_ptr<AudioManagerInterface>;
	using ConstAudioManagerInterfaceSharedPtr = std::shared_ptr<const AudioManagerInterface>;
}

#endif // FRAMEWORK_MIDDLE_LAYER_AUDIO_MANAGER_INTERFACE_H

