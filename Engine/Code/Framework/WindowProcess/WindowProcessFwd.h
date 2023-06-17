///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:07)

#ifndef FRAMEWORK_WINDOW_PROCESS_FWD_H
#define FRAMEWORK_WINDOW_PROCESS_FWD_H

namespace Framework
{
    enum class MouseButtonsTypes;
    enum class MouseStateTypes;

    class VirtualKeysTypes;
    class WindowMessageLoop;
    class WindowMessageInterface;

    template <typename MiddleLayer>
    class WindowMessage;

    class WindowProcessManager;

    template <typename WindowMessage>
    class WindowProcessHandle;

    class WindowMessageUnitTestSuite;
}

#endif  // FRAMEWORK_WINDOW_PROCESS_FWD_H