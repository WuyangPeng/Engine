// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 13:47)

#ifndef FRAMEWORK_APPLICATION_WINDOW_APPLICATION_INFORMATION_H
#define FRAMEWORK_APPLICATION_WINDOW_APPLICATION_INFORMATION_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Window/Fwd/WindowFlagsFwd.h"
#include "Rendering/Renderers/RenderersFwd.h"
#include "Framework/WindowCreate/WindowCreateFwd.h"
#include "Framework/WindowRegister/WindowName.h"
#include "Framework/WindowRegister/WindowPictorial.h"

FRAMEWORK_EXPORT_SHARED_PTR(WindowApplicationInformationImpl);

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE WindowApplicationInformation
	{
	public:
		DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(WindowApplicationInformation);
		using String = System::String;
		using WindowStyles = System::WindowStyles;
		using HInstance = System::WindowHInstance;
		using RendererParameter = Rendering::RendererParameter;

	public:
		WindowApplicationInformation(const String& windowTitle, const WindowSize& size, const WindowPoint& point, bool allowResize);
		WindowApplicationInformation(const String& windowTitle, const WindowSize& size);
		WindowApplicationInformation(HInstance instance, const RendererParameter& rendererParameter);

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

		void SetWindowSize(const WindowSize& size);

		WindowName GetWindowName() const noexcept;
		WindowPictorial GetWindowPictorial() const noexcept;

	private:
		IMPL_TYPE_DECLARE(WindowApplicationInformation);
	};
}

#endif // FRAMEWORK_APPLICATION_WINDOW_APPLICATION_INFORMATION_H
