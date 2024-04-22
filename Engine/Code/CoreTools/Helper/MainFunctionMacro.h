/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/28 11:01)

/// main函数所需要的宏
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
            System::OutputDebugStringWithTChar(SYSTEM_TEXT("main 抛出异常。")); \
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

    #define DLL_MAIN_FUNCTION(namespaceName)                                                                                                 \
        CORE_TOOLS_MUTEX_INIT(namespaceName);                                                                                                \
        int SYSTEM_WIN_API DllMain(System::WindowsHInstance instance, System::WindowsDWord reason, System::WindowsVoidPtr reserved) noexcept \
        {                                                                                                                                    \
            try                                                                                                                              \
            {                                                                                                                                \
                CoreTools::ExecuteDllMain(instance, reason, reserved, SYSTEM_MULTIPLE_CONCATENATOR(Get, namespaceName, Mutex)());            \
            }                                                                                                                                \
            catch (...)                                                                                                                      \
            {                                                                                                                                \
                System::OutputDebugStringWithTChar(SYSTEM_TEXT("ExecuteDllMain 抛出异常。"));                                                \
            }                                                                                                                                \
            return System::gTrue;                                                                                                            \
        }

#endif  // TCRE_USE_GCC

#endif  // CORE_TOOLS_HELPER_MAIN_FUNCTION_MACRO_H
