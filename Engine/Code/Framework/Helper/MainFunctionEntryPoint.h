/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:18)

#ifndef FRAMEWORK_HELPER_MAIN_FUNCTION_ENTRY_POINT_H
#define FRAMEWORK_HELPER_MAIN_FUNCTION_ENTRY_POINT_H

#include "Framework/FrameworkDll.h"

#include "System/Android/Using/AndroidNativeAppGlueUsing.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Rendering/RendererEngine/RendererParameter.h"
#include "Framework/Application/GLUTApplicationInformation.h"
#include "Framework/Application/WindowApplicationInformation.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"
#include "Framework/MainFunctionHelper/Flags/Directory.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutFrameFwd.h"
#include "Framework/WindowCreate/WindowSize.h"

#include <iostream>

namespace Framework
{
    template <typename T>
    NODISCARD int WinMainEntryPoint(System::WindowsHInstance instance,
                                    char* commandLine,
                                    const System::TChar* engineEnvironment,
                                    const System::TChar* engineDirectory,
                                    const System::TChar* windowName,
                                    int width,
                                    int height,
                                    System::WindowsHInstance previousInstance)
    {
        EXCEPTION_TRY
        {
            const WindowSize windowSize{ width, height };
            WindowApplicationInformation windowApplicationInformation{ windowName, windowSize };
            EnvironmentDirectory environmentDirectory{ engineEnvironment, engineDirectory };

            T helper{ instance, commandLine, windowApplicationInformation, environmentDirectory };

            return helper.Run();
        }
        EXCEPTION_ENTRY_POINT_CATCH

        System::UnusedFunction(commandLine, previousInstance);

        return -1;
    }

    template <typename T>
    NODISCARD int WinMainEntryPoint(System::WindowsHInstance instance, char* commandLine, const System::TChar* engineEnvironment, const System::TChar* engineDirectory, const System::TChar* renderer, System::WindowsHInstance previousInstance)
    {
        EXCEPTION_TRY
        {
            EnvironmentDirectory environmentDirectory{ engineEnvironment, engineDirectory };
            const auto fileName = environmentDirectory.GetDirectory(UpperDirectory::Configuration) + renderer;

            const Rendering::RendererParameter rendererParameter{ CoreTools::StringConversion::StandardConversionMultiByte(fileName) };
            WindowApplicationInformation windowApplicationInformation{ instance, rendererParameter };

            T helper{ instance, commandLine, windowApplicationInformation, environmentDirectory };

            return helper.Run();
        }
        EXCEPTION_ENTRY_POINT_CATCH

        System::UnusedFunction(commandLine, previousInstance);

        return -1;
    }

    template <typename T>
    NODISCARD int MainEntryPoint(int argc, char** argv, const System::TChar* consoleTitle, const System::TChar* engineEnvironment, const System::TChar* engineDirectory)
    {
        EXCEPTION_TRY
        {
            EnvironmentDirectory environmentDirectory{ engineEnvironment, engineDirectory };

            T helper{ argc, argv, consoleTitle, environmentDirectory };

            return helper.Run();
        }
        EXCEPTION_ENTRY_POINT_CATCH

        return -1;
    }

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)

    template <typename T>
    NODISCARD int GlutMainEntryPoint(int argc, char** argv, const System::TChar* engineEnvironment, const System::TChar* engineDirectory, int majorVersion, int minorVersion, FrameParameter frame)
    {
        EXCEPTION_TRY
        {
            EnvironmentDirectory environmentDirectory{ engineEnvironment, engineDirectory };
            GLUTApplicationInformation glutApplicationInformation{ majorVersion, minorVersion, frame };

            auto helper = std::make_shared<T>(argc, argv, glutApplicationInformation, environmentDirectory);

            helper->Init();

            return helper->Run();
        }
        EXCEPTION_ENTRY_POINT_CATCH

        return -1;
    }

#include SYSTEM_WARNING_POP

    template <typename T>
    NODISCARD int AndroidMainEntryPoint(System::AndroidApp* androidApp, const System::TChar* engineEnvironment, const System::TChar* engineDirectory)
    {
        EXCEPTION_TRY
        {
            EnvironmentDirectory environmentDirectory{ engineEnvironment, engineDirectory };

            T helper{ androidApp, environmentDirectory };

            return helper.Run();
        }
        EXCEPTION_ENTRY_POINT_CATCH

        return -1;
    }

}

#endif  // FRAMEWORK_HELPER_MAIN_FUNCTION_ENTRY_POINT_H
