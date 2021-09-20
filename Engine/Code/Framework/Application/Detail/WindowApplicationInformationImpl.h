// Copyright (c) 2010-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.1 (2020/05/21 13:41)

#ifndef FRAMEWORK_APPLICATION_WINDOW_APPLICATION_INFORMATION_IMPL_H
#define FRAMEWORK_APPLICATION_WINDOW_APPLICATION_INFORMATION_IMPL_H

#include "System/Helper/UnicodeUsing.h"
#include "System/Windows/Flags/WindowsFlags.h"
#include "Rendering/Renderers/RenderersFwd.h"
#include "Framework/WindowCreate/WindowPoint.h"
#include "Framework/WindowCreate/WindowSize.h"
#include "Framework/WindowRegister/WindowName.h"
#include "Framework/WindowRegister/WindowPictorial.h"

namespace Framework
{
	class FRAMEWORK_HIDDEN_DECLARE WindowApplicationInformationImpl
	{
	public:
		using ClassType = WindowApplicationInformationImpl;
		using String = System::String;
		using WindowStyles = System::WindowsStyles;
		using HInstance = System::WindowsHInstance;
		using RendererParameter = Rendering::RendererParameter;

	public:
		WindowApplicationInformationImpl(const String& windowTitle, const WindowSize& size, const WindowPoint& point, bool allowResize);
		WindowApplicationInformationImpl(const String& windowTitle, const WindowSize& size);
		WindowApplicationInformationImpl(HInstance instance, const RendererParameter& rendererParameter);

		CLASS_INVARIANT_DECLARE;

		const String GetWindowTitle() const;
		const std::string GetWindowTitleWithMultiByte() const;
		int GetXPosition() const noexcept;
		int GetYPosition() const noexcept;
		int GetWidth() const noexcept;
		int GetHeight() const noexcept;
		const WindowSize GetWindowSize() const noexcept;
		float GetAspectRatio() const noexcept;
		WindowStyles GetStyle() const noexcept;

		void SetWindowSize(const WindowSize& size) noexcept;

		WindowName GetWindowName() const noexcept;
		WindowPictorial GetWindowPictorial() const noexcept;

	private:
		static WindowPictorial GetWindowPictorial(HInstance instance, const RendererParameter& rendererParameter);

	private:
		// 窗口参数。
		String m_WindowTitle;
		WindowSize m_Size;
		WindowPoint m_Position;
		WindowStyles m_Style;
		WindowName m_WindowName;
		WindowPictorial m_WindowPictorial;
	};
}

#endif // FRAMEWORK_APPLICATION_WINDOW_APPLICATION_INFORMATION_IMPL_H
