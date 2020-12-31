// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/20 10:57)

#ifndef FRAMEWORK_HELPER_MAIN_FUNCTION_ENTRY_POINT_H
#define FRAMEWORK_HELPER_MAIN_FUNCTION_ENTRY_POINT_H

#include "Framework/FrameworkDll.h"

#include "System/Helper/WindowsMacro.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Window/Using/WindowUsing.h"
#include "System/Android/Using/AndroidNativeAppGlueUsing.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "Rendering/Renderers/RendererParameter.h"
#include "Framework/WindowCreate/WindowSize.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutFrameFwd.h"
#include "Framework/Application/GLUTApplicationInformation.h"
#include "Framework/Application/WindowApplicationInformation.h" 
#include "Framework/MainFunctionHelper/Flags/Directory.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"

namespace Framework
{
#include STSTEM_WARNING_PUSH

	#include SYSTEM_WARNING_DISABLE(26414)
	#include SYSTEM_WARNING_DISABLE(26461)
	template<typename T>
	int WinMainEntryPoint(System::WindowHInstance instance, char* commandLine, const System::TChar* engineEnvironment, const System::TChar* engineDirectory,
                          const System::TChar* windowName, int width, int height, [[maybe_unused]] System::WindowHInstance previousInstance)
	{
		EXCEPTION_TRY
		{
			const WindowSize windowSize{ width,height };
			WindowApplicationInformation windowApplicationInformation{ windowName,windowSize };
			EnvironmentDirectory environmentDirectory{ engineEnvironment,engineDirectory };

			auto helper = std::make_shared<T>(instance,commandLine,windowApplicationInformation ,environmentDirectory);

			return helper->Run();
		}
		EXCEPTION_ENTRY_POINT_CATCH

 

		return -1;
	}
#include STSTEM_WARNING_POP

#include STSTEM_WARNING_PUSH

	#include SYSTEM_WARNING_DISABLE(26414)
	#include SYSTEM_WARNING_DISABLE(26461)
	template<typename T>
        int WinMainEntryPoint(System::WindowHInstance instance, char* commandLine, const System::TChar* engineEnvironment, const System::TChar* engineDirectory, const System::TChar* renderer, [[maybe_unused]] System::WindowHInstance previousInstance)
	{
		EXCEPTION_TRY
		{
			EnvironmentDirectory environmentDirectory{ engineEnvironment, engineDirectory };
			auto fileName = environmentDirectory.GetDirectory(UpperDirectory::Configuration) + renderer;

			Rendering::RendererParameter rendererParameter{ CoreTools::StringConversion::StandardConversionMultiByte(fileName) };
			WindowApplicationInformation windowApplicationInformation{ instance, rendererParameter };

			auto helper = std::make_shared<T>(instance,commandLine,windowApplicationInformation ,environmentDirectory);

			return helper->Run();
		}
		EXCEPTION_ENTRY_POINT_CATCH

 

		return -1;
	}
#include STSTEM_WARNING_POP

#include STSTEM_WARNING_PUSH

	#include SYSTEM_WARNING_DISABLE(26414) 
	template<typename T>
	int MainEntryPoint(int argc, char** argv, const System::TChar* consoleTitle, const System::TChar* engineEnvironment, const System::TChar* engineDirectory)
	{
		EXCEPTION_TRY
		{
			EnvironmentDirectory environmentDirectory{ engineEnvironment,engineDirectory };

			auto helper = std::make_shared<T>(argc,argv,consoleTitle, environmentDirectory);

			return helper->Run();
		}
		EXCEPTION_ENTRY_POINT_CATCH

		return -1;
	}
#include STSTEM_WARNING_POP

#include STSTEM_WARNING_PUSH

	#include SYSTEM_WARNING_DISABLE(26414) 
	template<typename T>
	int GlutMainEntryPoint(int argc, char** argv, const System::TChar* engineEnvironment, const System::TChar* engineDirectory, int majorVersion, int minorVersion, FrameParameter frame)
	{
		EXCEPTION_TRY
		{
			EnvironmentDirectory environmentDirectory{ engineEnvironment, engineDirectory };
			GLUTApplicationInformation glutApplicationInformation{ majorVersion,minorVersion,frame };

			auto helper = std::make_shared<T>(argc, argv,glutApplicationInformation, environmentDirectory);

			helper->Init();

			return helper->Run();
		}
		EXCEPTION_ENTRY_POINT_CATCH

		return -1;
	}
#include STSTEM_WARNING_POP

#include STSTEM_WARNING_PUSH

	#include SYSTEM_WARNING_DISABLE(26414) 
	template<typename T>
	int AndroidMainEntryPoint(System::AndroidApp* androidApp, const System::TChar* engineEnvironment, const System::TChar* engineDirectory)
	{
		EXCEPTION_TRY
		{
			EnvironmentDirectory environmentDirectory{ engineEnvironment,engineDirectory };

			auto helper = std::make_shared<T>(androidApp, environmentDirectory);

			return helper->Run();
		}
		EXCEPTION_ENTRY_POINT_CATCH

		return -1;
	}

#include STSTEM_WARNING_POP
}

#endif // FRAMEWORK_HELPER_MAIN_FUNCTION_ENTRY_POINT_H
