///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/09 14:45)

#ifndef FRAMEWORK_APPLICATION_APPLICATION_TRAIT_H
#define FRAMEWORK_APPLICATION_APPLICATION_TRAIT_H

#include "KeyIdentifiers.h"
#include "KeyboardModifiers.h"
#include "MouseButtons.h"
#include "MouseModifiers.h"
#include "MouseState.h"

namespace Framework
{
    enum class PlatformTypes
    {
        Window,
        Glut,
        Android,
        Linux,
        Macintosh
    };

    template <PlatformTypes Types>
    struct ApplicationTrait;

    template <>
    struct ApplicationTrait<PlatformTypes::Window>
    {
        using KeyIdentifiers = WindowKeyIdentifiers;
        using KeyboardModifiers = WindowKeyboardModifiers;
        using MouseButtons = WindowMouseButtons;
        using MouseState = WindowMouseState;
        using MouseModifiers = WindowMouseModifiers;
    };

    using WindowApplicationTrait = ApplicationTrait<PlatformTypes::Window>;

    template <>
    struct ApplicationTrait<PlatformTypes::Glut>
    {
        using KeyIdentifiers = GlutKeyIdentifiers;
        using KeyboardModifiers = GlutKeyboardModifiers;
        using MouseButtons = GlutMouseButtons;
        using MouseState = GlutMouseState;
        using MouseModifiers = GlutMouseModifiers;
    };

    using GlutApplicationTrait = ApplicationTrait<PlatformTypes::Glut>;

    template <>
    struct ApplicationTrait<PlatformTypes::Android>
    {
        using KeyIdentifiers = AndroidKeyIdentifiers;
        using KeyboardModifiers = AndroidKeyboardModifiers;
        using MouseButtons = AndroidMouseButtons;
        using MouseState = AndroidMouseState;
        using MouseModifiers = AndroidMouseModifiers;
    };

    using AndroidApplicationTrait = ApplicationTrait<PlatformTypes::Android>;

    template <>
    struct ApplicationTrait<PlatformTypes::Linux>
    {
        using KeyIdentifiers = LinuxKeyIdentifiers;
        using KeyboardModifiers = LinuxKeyboardModifiers;
        using MouseButtons = LinuxMouseButtons;
        using MouseState = LinuxMouseState;
        using MouseModifiers = LinuxMouseModifiers;
    };

    using LinuxApplicationTrait = ApplicationTrait<PlatformTypes::Linux>;

    template <>
    struct ApplicationTrait<PlatformTypes::Macintosh>
    {
        using KeyIdentifiers = MacintoshKeyIdentifiers;
        using KeyboardModifiers = MacintoshKeyboardModifiers;
        using MouseButtons = MacintoshMouseButtons;
        using MouseState = MacintoshMouseState;
        using MouseModifiers = MacintoshMouseModifiers;
    };

    using MacintoshApplicationTrait = ApplicationTrait<PlatformTypes::Macintosh>;
}

#endif  // FRAMEWORK_APPLICATION_APPLICATION_TRAIT_H
