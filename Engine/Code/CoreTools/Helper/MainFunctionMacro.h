///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.2 (2023/02/12 18:05)

// main��������Ҫ�ĺ�
#ifndef CORE_TOOLS_HELPER_MAIN_FUNCTION_MACRO_H
#define CORE_TOOLS_HELPER_MAIN_FUNCTION_MACRO_H

#include "System/Helper/WindowsMacro.h"
#include "System/SystemOutput/OutputDebugString.h"
#include "CoreTools/MainFunctionHelper/ExecuteDllMain.h"
#include "CoreTools/Threading/Mutex.h"

#define MAIN_FUNCTION(namespaceName, helperClassName)                           \
    int main(int argc, char** argv) noexcept                                    \
    {                                                                           \
        try                                                                     \
        {                                                                       \
            namespaceName::helperClassName helper{ argc, argv };                \
            return helper.Run();                                                \
        }                                                                       \
        catch (...)                                                             \
        {                                                                       \
            System::OutputDebugStringWithTChar(SYSTEM_TEXT("main �׳��쳣��")); \
        }                                                                       \
        return 0;                                                               \
    }

#if defined(TCRE_USE_GCC) || defined(BUILDING_STATIC)

    #define CORE_TOOLS_MUTEX_INIT(namespaceName)                                         \
        CoreTools::Mutex& SYSTEM_MULTIPLE_CONCATENATOR(Get, namespaceName, Mutex)()      \
        {                                                                                \
            static CoreTools::Mutex mutex{ CoreTools::MutexCreate::UseCriticalSection }; \
            return mutex;                                                                \
        }
    #define CORE_TOOLS_MUTEX_EXTERN(namespaceName) \
        NODISCARD CoreTools::Mutex& SYSTEM_MULTIPLE_CONCATENATOR(Get, namespaceName, Mutex)()

#else  // !defined(TCRE_USE_GCC) && !defined(BUILDING_STATIC)

    #define CORE_TOOLS_MUTEX_INIT(namespaceName)                                               \
        CoreTools::DllMutex& SYSTEM_MULTIPLE_CONCATENATOR(Get, namespaceName, Mutex)()         \
        {                                                                                      \
            static CoreTools::DllMutex dllMutex{ CoreTools::MutexCreate::UseCriticalSection }; \
            return dllMutex;                                                                   \
        }
    #define CORE_TOOLS_MUTEX_EXTERN(namespaceName) \
        NODISCARD CoreTools::DllMutex& SYSTEM_MULTIPLE_CONCATENATOR(Get, namespaceName, Mutex)();

#endif  // defined(TCRE_USE_GCC) || defined(BUILDING_STATIC)

#ifdef TCRE_USE_GCC

    #define DLL_MAIN_FUNCTION(namespaceName) \
        CORE_TOOLS_MUTEX_INIT(namespaceName)

#else  // !TCRE_USE_GCC

    #define DLL_MAIN_FUNCTION(namespaceName)                                                                                                \
        CORE_TOOLS_MUTEX_INIT(namespaceName);                                                                                               \
        int SYSTEM_WINAPI DllMain(System::WindowsHInstance instance, System::WindowsDWord reason, System::WindowsVoidPtr reserved) noexcept \
        {                                                                                                                                   \
            try                                                                                                                             \
            {                                                                                                                               \
                CoreTools::ExecuteDllMain(instance, reason, reserved, SYSTEM_MULTIPLE_CONCATENATOR(Get, namespaceName, Mutex)());           \
            }                                                                                                                               \
            catch (...)                                                                                                                     \
            {                                                                                                                               \
                System::OutputDebugStringWithTChar(SYSTEM_TEXT("ExecuteDllMain �׳��쳣��"));                                               \
            }                                                                                                                               \
            return System::gTrue;                                                                                                           \
        }

#endif  // TCRE_USE_GCC

#endif  // CORE_TOOLS_HELPER_MAIN_FUNCTION_MACRO_H
