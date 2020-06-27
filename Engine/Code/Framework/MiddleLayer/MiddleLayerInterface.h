// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.3.0.1 (2020/05/21 14:49)

#ifndef FRAMEWORK_MIDDLE_LAYER_MIDDLE_LAYER_INTERFACE_H
#define FRAMEWORK_MIDDLE_LAYER_MIDDLE_LAYER_INTERFACE_H

#include "Framework/FrameworkDll.h"

#include "MiddleLayerInternalFwd.h"
#include "System/Window/Fwd/WindowFlagsFwd.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Framework/WindowCreate/WindowCreateFwd.h"
#include "Framework/WindowProcess/WindowProcessFwd.h"
#include "Framework/MainFunctionHelper/MainFunctionHelperFwd.h"

template class FRAMEWORK_DEFAULT_DECLARE std::weak_ptr<Framework::MiddleLayerInterface>;
template class FRAMEWORK_DEFAULT_DECLARE std::enable_shared_from_this<Framework::MiddleLayerInterface>;

namespace Framework
{
	// �м��ӿ��࣬�����ṩ�麯����Ĭ��ʵ�֡�
	class FRAMEWORK_DEFAULT_DECLARE MiddleLayerInterface : public std::enable_shared_from_this<MiddleLayerInterface>
	{
	public:
		using ClassType = MiddleLayerInterface;
		using WindowDisplay = System::WindowDisplay;

	public:
		explicit MiddleLayerInterface(MiddleLayerPlatform middleLayerPlatform) noexcept;
		virtual ~MiddleLayerInterface() noexcept = default;

		MiddleLayerInterface(const MiddleLayerInterface& rhs) noexcept = delete;
		MiddleLayerInterface& operator=(const MiddleLayerInterface& rhs) noexcept = delete;
		MiddleLayerInterface(MiddleLayerInterface&& rhs) noexcept;
		MiddleLayerInterface& operator=(MiddleLayerInterface&& rhs) noexcept;

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		// ���������м�㴦��
		virtual bool PreCreate(const EnvironmentDirectory& environmentDirectory);
		virtual bool Create();
		virtual bool Initialize();

		// ���ٴ����м�㴦��
		virtual bool Destroy();
		virtual void Terminate();

		// ����ʱ���м�㴦��
		virtual void PreIdle();
		virtual bool Idle(int64_t timeDelta);

		// ��Ⱦ�м�㴦��
		virtual bool Paint();
		virtual bool Move(const WindowPoint& point);
		virtual bool Resize(WindowDisplay windowDisplay, const WindowSize& size);

		// ������Ϣ�м�㴦��
		virtual bool KeyUp(int key, const WindowPoint& point);
		virtual bool KeyDown(int key, const WindowPoint& point);
		virtual bool SpecialKeyUp(int key, const WindowPoint& point);
		virtual bool SpecialKeyDown(int key, const WindowPoint& point);

		// �����Ϣ�м�㴦��
		virtual bool PassiveMotion(const WindowPoint& point);
		virtual bool Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys);
		virtual bool MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys);
		virtual bool MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys);

		MiddleLayerPlatform GetMiddleLayerPlatform() const noexcept;

	private:
		MiddleLayerPlatform m_MiddleLayerPlatform;
	};

	using MiddleLayerInterfaceSharedPtr = std::shared_ptr<MiddleLayerInterface>;
	using ConstMiddleLayerInterfaceSharedPtr = std::shared_ptr<const MiddleLayerInterface>;
}

#endif // FRAMEWORK_MIDDLE_LAYER_MIDDLE_LAYER_INTERFACE_H

