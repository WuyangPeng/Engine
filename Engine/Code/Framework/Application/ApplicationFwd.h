/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:24)

#ifndef FRAMEWORK_APPLICATION_FWD_H
#define FRAMEWORK_APPLICATION_FWD_H

namespace Framework
{
    enum class PlatformTypes;

    struct WindowKeyIdentifiers;
    struct GlutKeyIdentifiers;
    struct AndroidKeyIdentifiers;
    struct LinuxKeyIdentifiers;
    struct MacintoshKeyIdentifiers;

    struct WindowKeyboardModifiers;
    struct GlutKeyboardModifiers;
    struct AndroidKeyboardModifiers;
    struct LinuxKeyboardModifiers;
    struct MacintoshKeyboardModifiers;

    struct WindowMouseButtons;
    struct GlutMouseButtons;
    struct AndroidMouseButtons;
    struct LinuxMouseButtons;
    struct MacintoshMouseButtons;

    struct WindowMouseState;
    struct GlutMouseState;
    struct AndroidMouseState;
    struct LinuxMouseState;
    struct MacintoshMouseState;

    struct WindowMouseModifiers;
    struct GlutMouseModifiers;
    struct AndroidMouseModifiers;
    struct LinuxMouseModifiers;
    struct MacintoshMouseModifiers;

    template <PlatformTypes Types>
    struct ApplicationTrait;

    class FontInformation;
    class MousePosition;
    class PerformanceMeasurements;
    class WindowApplicationInformation;
    class GLUTApplicationInformation;

    class PixelScreen;
    class CameraMotion;
    class ObjectMotion;
}

#endif  // FRAMEWORK_APPLICATION_FWD_H