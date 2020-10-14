//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/09/30 9:41)

// main��������Ҫ�ĺ�
#ifndef CORE_TOOLS_HELPER_MAIN_FUNCTION_MACRO_H
#define CORE_TOOLS_HELPER_MAIN_FUNCTION_MACRO_H

#include "System/Helper/WindowsMacro.h"
#include "System/SystemOutput/OutputDebugString.h"
#include "CoreTools/MainFunctionHelper/ExecuteDllMain.h"
#include "CoreTools/Threading/Mutex.h"

#define MAIN_FUNCTION(namespaceName, helperClassName)        \
    int main(int argc, char** argv) noexcept                 \
    {                                                        \
        namespaceName::helperClassName helper{ argc, argv }; \
        return helper.Run();                                 \
    }

#if defined(TCRE_USE_GCC) || defined(BUILDING_STATIC)

    #define CORE_TOOLS_MUTEX_INIT(namespaceName)                                    \
        CoreTools::Mutex& SYSTEM_MULTIPLE_CONCATENATOR(Get, namespaceName, Mutex)() \
        {                                                                           \
            static CoreTools::Mutex mutex{};                                        \
            return mutex;                                                           \
        }
    #define CORE_TOOLS_MUTEX_EXTERN(namespaceName) \
        [[nodiscard]] CoreTools::Mutex& SYSTEM_MULTIPLE_CONCATENATOR(Get, namespaceName, Mutex)()

#else  // !defined(TCRE_USE_GCC) && !defined(BUILDING_STATIC)

    #define CORE_TOOLS_MUTEX_INIT(namespaceName)                                       \
        CoreTools::DllMutex& SYSTEM_MULTIPLE_CONCATENATOR(Get, namespaceName, Mutex)() \
        {                                                                              \
            static CoreTools::DllMutex dllMutex{};                                     \
            return dllMutex;                                                           \
        }
    #define CORE_TOOLS_MUTEX_EXTERN(namespaceName) \
        [[nodiscard]] CoreTools::DllMutex& SYSTEM_MULTIPLE_CONCATENATOR(Get, namespaceName, Mutex)();

#endif  // defined(TCRE_USE_GCC) || defined(BUILDING_STATIC)

#ifdef TCRE_USE_GCC

    #define DLL_MAIN_FUNCTION(namespaceName) \
        CORE_TOOLS_MUTEX_INIT(namespaceName)

#else  // !TCRE_USE_GCC

    #define DLL_MAIN_FUNCTION(namespaceName)                                                                                             \
        CORE_TOOLS_MUTEX_INIT(namespaceName);                                                                                            \
        int SYSTEM_WINAPI DllMain(System::WindowHInstance instance, System::WindowDWord reason, System::WindowVoidPtr reserved) noexcept \
        {                                                                                                                                \
            try                                                                                                                          \
            {                                                                                                                            \
                CoreTools::ExecuteDllMain(instance, reason, reserved, SYSTEM_MULTIPLE_CONCATENATOR(Get, namespaceName, Mutex)());        \
            }                                                                                                                            \
            catch (...)                                                                                                                  \
            {                                                                                                                            \
                System::OutputDebugStringWithTChar(SYSTEM_TEXT("ExecuteDllMain �׳��쳣��"));                                                    \
            }                                                                                                                            \
            return System::g_True;                                                                                                       \
        }

#endif  // TCRE_USE_GCC

#endif  // CORE_TOOLS_HELPER_MAIN_FUNCTION_MACRO_H
