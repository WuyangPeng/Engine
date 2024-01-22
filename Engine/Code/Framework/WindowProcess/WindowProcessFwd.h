/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 14:28)

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