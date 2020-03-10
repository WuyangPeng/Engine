// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 13:17)

#ifndef FRAMEWORK_WINDOWS_API_FRAME_BUILD_H
#define FRAMEWORK_WINDOWS_API_FRAME_BUILD_H

#include "Framework/WindowRegister/WindowRegister.h"
#include "Framework/WindowProcess/WindowProcess.h"
#include "Framework/WindowCreate/WindowCreate.h"

namespace Framework
{
	class WindowApplicationInformation;
	class WindowPictorial;

	template <typename Process>
	class WindowsAPIFrameBuild
	{
	public:
		typedef WindowsAPIFrameBuild ClassType;
        typedef System::WindowHInstance HInstance;	 
		typedef System::WindowWParam WParam;
		typedef System::WindowHWnd HWnd;		

	public:
		explicit WindowsAPIFrameBuild(HInstance hInstance,char* lpCmdLine,
			                          const WindowApplicationInformation& information,
									  const System::String& className = SYSTEM_TEXT("WindowsAPIFrameBuild"),
									  const WindowPictorial& pictorial = WindowPictorial());
		virtual ~WindowsAPIFrameBuild();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		HWnd GetHwnd() const;	
		HInstance GetHInstance() const;

		WParam EnterMessageLoop();

	private:		
		WindowRegisterHandle<Process> m_WindowRegister;
		WindowCreateHandle m_WindowCreate;
		WindowMessageLoop m_WindowMessageLoop;
	};
}

#endif // FRAMEWORK_WINDOWS_API_FRAME_BUILD_H