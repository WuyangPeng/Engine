// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 17:52)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_WINDOW_MAIN_FUNCTION_HELPER_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_WINDOW_MAIN_FUNCTION_HELPER_H

#include "MainFunctionHelperBase.h"
#include "System/Window/Using/WindowUsing.h"

namespace Framework
{
	class WindowApplicationInformation;
	class EnvironmentDirectory;

	template <template<typename > class Build,typename Process>
	class WindowMainFunctionHelper : public MainFunctionHelperBase
	{
	public:
		using ClassType = WindowMainFunctionHelper<Build,Process>;
		using ParentType = MainFunctionHelperBase;
		using BuildType = Build<Process>;
        using HInstance = System::WindowHInstance;
		using HWnd = System::WindowHWnd;

	public:
		WindowMainFunctionHelper(HInstance instance,char* commandLine,
			                     const WindowApplicationInformation& information,
			                     const EnvironmentDirectory& environmentDirectory);
		virtual ~WindowMainFunctionHelper();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
		virtual void Destroy();

	protected:
		virtual int EnterMessageLoop();
		HWnd GetHwnd() const;	

	private:
		using BuildTypePtr = std::shared_ptr<BuildType>;

	private:
		virtual int DoRun();	

        void Initializers(HInstance instance,char* commandLine,const WindowApplicationInformation& information);
        void Terminators();

	private:
		BuildTypePtr m_Build;		
	};
}

#endif // FRAMEWORK_MAIN_FUNCTION_HELPER_WINDOW_MAIN_FUNCTION_HELPER_H