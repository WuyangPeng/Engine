/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:18)

#ifndef FRAMEWORK_HELPER_MAIN_FUNCTION_MACRO_H
#define FRAMEWORK_HELPER_MAIN_FUNCTION_MACRO_H

#include "MainFunctionEntryPoint.h"
#include "System/Helper/Tools.h"

#ifdef SYSTEM_PLATFORM_WIN32

    #define WINDOWS_MAIN_FUNCTION_WITH_INFORMATION(namespaceName, helperClassName, windowName, engineEnvironment, engineDirectory, windowSizeWidth, windowSizeHeight)                                        \
        int SYSTEM_WIN_API WinMain(SYSTEM_IN System::WindowsHInstance instance, SYSTEM_IN_OPT System::WindowsHInstance previousInstance, SYSTEM_IN char* commandLine, SYSTEM_IN int showCommand)             \
        {                                                                                                                                                                                                    \
            System::UnusedFunction(showCommand);                                                                                                                                                             \
            return Framework::WinMainEntryPoint<namespaceName::helperClassName>(instance, commandLine, engineEnvironment, engineDirectory, windowName, windowSizeWidth, windowSizeHeight, previousInstance); \
        }

    #define WINDOWS_MAIN_FUNCTION_USE_PARAMETER(namespaceName, helperClassName, engineEnvironment, engineDirectory, renderer)                                                                    \
        int SYSTEM_WIN_API WinMain(SYSTEM_IN System::WindowsHInstance instance, SYSTEM_IN_OPT System::WindowsHInstance previousInstance, SYSTEM_IN char* commandLine, SYSTEM_IN int showCommand) \
        {                                                                                                                                                                                        \
            System::UnusedFunction(showCommand);                                                                                                                                                 \
            return Framework::WinMainEntryPoint<namespaceName::helperClassName>(instance, commandLine, engineEnvironment, engineDirectory, renderer, previousInstance);                          \
        }

#else  // !SYSTEM_PLATFORM_WIN32

    #define WINDOWS_MAIN_FUNCTION_WITH_INFORMATION(namespaceName, helperClassName, windowName, engineEnvironment, engineDirectory, windowSizeWidth, windowSizeHeight) \
        int main(int argc, char** argv)                                                                                                                               \
        {                                                                                                                                                             \
            return Framework::MainEntryPoint<namespaceName::helperClassName>(argc, argv, windowName, engineEnvironment, engineDirectory);                             \
        }

    #define WINDOWS_MAIN_FUNCTION_USE_PARAMETER(namespaceName, helperClassName, engineEnvironment, engineDirectory, renderer)             \
        int main(int argc, char** argv)                                                                                                   \
        {                                                                                                                                 \
            return Framework::MainEntryPoint<namespaceName::helperClassName>(argc, argv, windowName, engineEnvironment, engineDirectory); \
        }

#endif  // SYSTEM_PLATFORM_WIN32

#define CONSOLE_MAIN_FUNCTION(namespaceName, helperClassName, consoleTitle, engineEnvironment, engineDirectory)                         \
    int main(int argc, char** argv)                                                                                                     \
    {                                                                                                                                   \
        return Framework::MainEntryPoint<namespaceName::helperClassName>(argc, argv, consoleTitle, engineEnvironment, engineDirectory); \
    }

#define GLUT_CONSOLE_MAIN_FUNCTION(namespaceName, helperClassName, engineEnvironment, engineDirectory, majorVersion, minorVersion, frame)                        \
    int main(int argc, char** argv)                                                                                                                              \
    {                                                                                                                                                            \
        return Framework::GlutMainEntryPoint<namespaceName::helperClassName>(argc, argv, engineEnvironment, engineDirectory, majorVersion, minorVersion, frame); \
    }

#ifndef SYSTEM_PLATFORM_ANDROID

    #define ANDROID_MAIN_FUNCTION(namespaceName, helperClassName, engineEnvironment, engineDirectory)                                 \
        int main()                                                                                                                    \
        {                                                                                                                             \
            System::AndroidApp androidApp{};                                                                                          \
            return Framework::AndroidMainEntryPoint<namespaceName::helperClassName>(&androidApp, engineEnvironment, engineDirectory); \
        }

#elif defined(FRAMEWORK_ANDROID_TEST)

    #define ANDROID_MAIN_FUNCTION(namespaceName, helperClassName, engineEnvironment, engineDirectory)                                 \
        int main()                                                                                                                    \
        {                                                                                                                             \
            System::AndroidApp androidApp{};                                                                                          \
            return Framework::AndroidMainEntryPoint<namespaceName::helperClassName>(&androidApp, engineEnvironment, engineDirectory); \
        }                                                                                                                             \
        void android_main(System::AndroidApp* androidApp)                                                                             \
        {                                                                                                                             \
        }

#else  // !FRAMEWORK_ANDROID_TEST && !SYSTEM_PLATFORM_ANDROID

    #define ANDROID_MAIN_FUNCTION(namespaceName, helperClassName, engineEnvironment, engineDirectory)                         \
        void android_main(System::AndroidApp* androidApp)                                                                     \
        {                                                                                                                     \
            Framework::AndroidMainEntryPoint<namespaceName::helperClassName>(androidApp, engineEnvironment, engineDirectory); \
        }

#endif  // SYSTEM_PLATFORM_ANDROID

#endif  // FRAMEWORK_HELPER_MAIN_FUNCTION_MACRO_H
