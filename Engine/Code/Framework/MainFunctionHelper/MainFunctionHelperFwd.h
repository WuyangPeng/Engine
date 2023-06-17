///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:39)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_FWD_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_FWD_H

namespace Framework
{
    enum class EndianDirectory;
    enum class RenderingDirectory;
    enum class AnalysisDirectory;
    enum class UpperDirectory;
    enum class RenderingAnalysisDirectory;

    enum class MainFunctionSchedule;
    enum class ConsoleMainFunctionSchedule;
    enum class WindowMainFunctionSchedule;
    enum class OpenGLGlutMainFunctionSchedule;
    enum class AndroidMainFunctionSchedule;
    enum class MacintoshMainFunctionSchedule;

    class EnvironmentDirectory;
    class MainFunctionHelperBase;
    class ConsoleMainFunctionHelperBase;

    template <template <typename> class Build, typename Process>
    class ConsoleMainFunctionHelper;

    template <template <typename> class Build, typename Process>
    class WindowMainFunctionHelper;

    template <template <typename> class Build, typename Process>
    class OpenGLGlutMainFunctionHelper;

    template <template <typename> class Build, typename Process>
    class AndroidMainFunctionHelper;

    template <template <typename> class Build, typename Process>
    class MacintoshMainFunctionHelper;
}

#endif  // FRAMEWORK_MAIN_FUNCTION_HELPER_FWD_H