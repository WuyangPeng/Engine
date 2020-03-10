// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:13)

#ifndef FRAMEWORK_APPLICATION_WINDOW_APPLICATION_INFORMATION_H
#define FRAMEWORK_APPLICATION_WINDOW_APPLICATION_INFORMATION_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Window/Flags/WindowFlags.h"

FRAMEWORK_EXPORT_SHARED_PTR(WindowApplicationInformationImpl);

namespace Framework
{
	class WindowSize;
	class WindowPoint;

	class FRAMEWORK_DEFAULT_DECLARE WindowApplicationInformation
	{
	public:
		DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(WindowApplicationInformation);
		using WindowStylesFlags = System::WindowStyles;

	public:	
		WindowApplicationInformation(const System::String& windowTitle,const WindowSize& size,const WindowPoint& point,	bool allowResize);

		WindowApplicationInformation(const System::String& windowTitle, const WindowSize& size);
		
		CLASS_INVARIANT_DECLARE;

		const System::String& GetWindowTitle () const;
		const std::string GetWindowTitleWithMultiByte() const;
		int GetXPosition () const;
		int GetYPosition () const;
		int GetWidth () const;
		int GetHeight () const;
		const WindowSize GetWindowSize() const;
		float GetAspectRatio () const;	
		WindowStylesFlags GetStyle() const;

		void SetWindowSize(const WindowSize& size);

	private:
		IMPL_TYPE_DECLARE(WindowApplicationInformation);
	};
}

#endif // FRAMEWORK_APPLICATION_WINDOW_APPLICATION_INFORMATION_H
