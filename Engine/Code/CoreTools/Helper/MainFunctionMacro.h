// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/18 10:22)

// main函数所需要的宏
#ifndef CORE_TOOLS_HELPER_MAIN_FUNCTION_MACRO_H
#define CORE_TOOLS_HELPER_MAIN_FUNCTION_MACRO_H

#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/EnumCast.h"
#include "System/DynamicLink/Flags/LoadLibraryFlags.h"
#include "System/DynamicLink/Using/LoadLibraryUsing.h"
#include "System/DynamicLink/Using/LoadResourceToolsUsing.h"
#include "CoreTools/Threading/Mutex.h"
#include "CoreTools/MainFunctionHelper/DllFunctionHelper.h"

#define MAIN_FUNCTION(namespaceName,helperClassName) \
		int main(int argc,char** argv) { namespaceName::helperClassName helper{ argc,argv }; return helper.Run(); }

#if defined(TCRE_USE_GCC) || defined(BUILDING_STATIC)

	#define CORE_TOOLS_MUTEX_INIT(namespaceName) \
            CoreTools::Mutex& SYSTEM_MULTIPLE_CONCATENATOR(Get,namespaceName,Mutex)() { \
			static CoreTools::Mutex mutex{ }; return mutex; }
	#define CORE_TOOLS_MUTEX_EXTERN(namespaceName) \
            CoreTools::Mutex& SYSTEM_MULTIPLE_CONCATENATOR(Get,namespaceName,Mutex)()

#else // !defined(TCRE_USE_GCC) && !defined(BUILDING_STATIC)

	#define CORE_TOOLS_MUTEX_INIT(namespaceName) \
            CoreTools::DllMutex& SYSTEM_MULTIPLE_CONCATENATOR(Get,namespaceName,Mutex)() { \
			static CoreTools::DllMutex dllMutex{ }; return dllMutex; }
	#define CORE_TOOLS_MUTEX_EXTERN(namespaceName) \
            CoreTools::DllMutex& SYSTEM_MULTIPLE_CONCATENATOR(Get,namespaceName,Mutex)();

#endif // defined(TCRE_USE_GCC) || defined(BUILDING_STATIC)

#ifdef TCRE_USE_GCC

	#define DLL_MAIN_FUNCTION(namespaceName) \
			CORE_TOOLS_MUTEX_INIT(namespaceName)

#else // !TCRE_USE_GCC

	#include STSTEM_WARNING_PUSH
	#include SYSTEM_WARNING_DISABLE(26461)
			inline void ExecuteDllMain(System::WindowHInstance instance, System::WindowDWord reason, System::WindowVoidPtr reserved, CoreTools::DllMutex& mutex)
			{				
				switch (System::UnderlyingCastEnum<System::DllMain>(reason))
				{
				case System::DllMain::ProcessAttach:
					CoreTools::DllFunctionHelper::InitializeMutex(&mutex);
					break;
				case System::DllMain::ProcessDetach:
					CoreTools::DllFunctionHelper::DeleteMutex(&mutex);
					break;
				default:
					break;
				}							

				SYSTEM_UNUSED_ARG(instance);
				SYSTEM_UNUSED_ARG(reserved);
			}
	#include STSTEM_WARNING_POP

	#define DLL_MAIN_FUNCTION(namespaceName) \
			CORE_TOOLS_MUTEX_INIT(namespaceName); \
			int SYSTEM_WINAPI DllMain(System::WindowHInstance instance,System::WindowDWord reason,System::WindowVoidPtr reserved) { \
			try { ExecuteDllMain(instance,reason,reserved,SYSTEM_MULTIPLE_CONCATENATOR(Get,namespaceName,Mutex)()); } catch(...){ } return System::g_True; }

#endif // TCRE_USE_GCC

#endif // CORE_TOOLS_HELPER_MAIN_FUNCTION_MACRO_H
