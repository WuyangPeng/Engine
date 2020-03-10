// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/07/31 17:41)

// main函数所需要的宏
#ifndef FRAMEWORK_MACRO_MAIN_FUNCTION_MACRO_H
#define FRAMEWORK_MACRO_MAIN_FUNCTION_MACRO_H

#include "Framework/Macro/UserMacro.h"
#include "Framework/Application/WindowApplicationInformation.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Window/Using/WindowUsing.h"

#define WINDOWS_MAIN_FUNCTION(namespaceName,helperClassName,windowName) \
		int SYSTEM_WINAPI WinMain(System::WindowHInstance instance, \
		System::WindowHInstance prevInstance,SYSTEM_TCHAR* cmdLine, \
	    int showCmd) { namespaceName::helperClassName helper(instance,cmdLine,windowName); \
		SYSTEM_UNUSED_ARG(prevInstance); SYSTEM_UNUSED_ARG(showCmd);return helper.Run(); }

#define WINDOWS_MAIN_FUNCTION_WITH_INFORMATION(namespaceName,helperClassName,windowName,environmentDirectory,windowSizeWidth,windowSizeHeight) \
		int SYSTEM_WINAPI WinMain(SYSTEM_IN System::WindowHInstance instance,SYSTEM_IN_OPT System::WindowHInstance prevInstance, \
		SYSTEM_IN char* commandLine,SYSTEM_IN int showCmd) { namespaceName::helperClassName helper(instance,commandLine, \
        Framework::WindowApplicationInformation(windowName,Framework::WindowSize(windowSizeWidth,windowSizeHeight)), \
		Framework::EnvironmentDirectory(environmentDirectory));SYSTEM_UNUSED_ARG(prevInstance); SYSTEM_UNUSED_ARG(showCmd); return helper.Run(); }

#define CONSOLE_MAIN_FUNCTION(namespaceName,helperClassName,consoleTitle,environmentDirectory) \
	    int main(int argc,char* argv[]) { namespaceName::helperClassName \
		helper(argc,argv,consoleTitle,Framework::EnvironmentDirectory(environmentDirectory)); return helper.Run(); }

#define CONSOLE_MAIN_FUNCTION_WITH_INFORMATION(namespaceName,helperClassName,environmentDirectory,majorVersion,minorVersion, frame) \
		int main(int argc, char* argv[]) { namespaceName::helperClassName helper(argc, argv, \
		Framework::GLUTApplicationInformation(majorVersion,minorVersion, frame),Framework::EnvironmentDirectory(environmentDirectory)); return helper.Run(); }

#ifndef SYSTEM_PLATFORM_ANDROID

#define ANDROID_MAIN_FUNCTION(namespaceName,helperClassName,environmentDirectory) \
		int main() { System::AndroidApp state;namespaceName::helperClassName helper(&state, \
		Framework::EnvironmentDirectory(environmentDirectory)); return helper.Run(); }

#elif defined(ANDROID_TEST)

#define ANDROID_MAIN_FUNCTION(namespaceName, helperClassName,environmentDirectory) \
		int main() { AndroidApp state;namespaceName::helperClassName helper(&state, \
		Framework::EnvironmentDirectory(environmentDirectory)); \
		return helper.Run(); } void android_main(struct AndroidApp* app) { SYSTEM_UNUSED_ARG(app); }

#else // !ANDROID_TEST && !SYSTEM_PLATFORM_ANDROID

#define ANDROID_MAIN_FUNCTION(namespaceName,helperClassName,environmentDirectory) \
		void android_main(struct AndroidApp* app) { namespaceName::helperClassName \
		helper(app,Framework::EnvironmentDirectory(environmentDirectory)); \
		helper.Run(); }

#endif // SYSTEM_PLATFORM_ANDROID

#endif // FRAMEWORK_MACRO_MAIN_FUNCTION_MACRO_H
