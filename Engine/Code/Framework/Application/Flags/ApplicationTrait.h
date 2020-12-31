// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 13:42)

#ifndef FRAMEWORK_APPLICATION_APPLICATION_TRAIT_H
#define FRAMEWORK_APPLICATION_APPLICATION_TRAIT_H

#include "KeyIdentifiers.h"
#include "KeyboardModifiers.h"
#include "MouseButtons.h"
#include "MouseState.h"
#include "MouseModifiers.h"

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

	template <PlatformTypes types>
	struct ApplicationTrait;

	template<>
	struct ApplicationTrait<PlatformTypes::Window>
	{
		using KeyIdentifiers = WindowKeyIdentifiers;
		using KeyboardModifiers = WindowKeyboardModifiers;
		using MouseButtons = WindowMouseButtons;
		using MouseState = WindowMouseState;
		using MouseModifiers = WindowMouseModifiers;
	};

	using WindowApplicationTrait = ApplicationTrait<PlatformTypes::Window>;

	template<>
	struct ApplicationTrait<PlatformTypes::Glut>
	{
		using KeyIdentifiers = GlutKeyIdentifiers;
		using KeyboardModifiers = GlutKeyboardModifiers;
		using MouseButtons = GlutMouseButtons;
		using MouseState = GlutMouseState;
		using MouseModifiers = GlutMouseModifiers;
	};

	using GlutApplicationTrait = ApplicationTrait<PlatformTypes::Glut>;

	template<>
	struct ApplicationTrait<PlatformTypes::Android>
	{
		using KeyIdentifiers = AndroidKeyIdentifiers;
		using KeyboardModifiers = AndroidKeyboardModifiers;
		using MouseButtons = AndroidMouseButtons;
		using MouseState = AndroidMouseState;
		using MouseModifiers = AndroidMouseModifiers;
	};

	using AndroidApplicationTrait = ApplicationTrait<PlatformTypes::Android>;

	template<>
	struct ApplicationTrait<PlatformTypes::Linux>
	{
		using KeyIdentifiers = LinuxKeyIdentifiers;
		using KeyboardModifiers = LinuxKeyboardModifiers;
		using MouseButtons = LinuxMouseButtons;
		using MouseState = LinuxMouseState;
		using MouseModifiers = LinuxMouseModifiers;
	};

	using LinuxApplicationTrait = ApplicationTrait<PlatformTypes::Linux>;

	template<>
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

#endif // FRAMEWORK_APPLICATION_APPLICATION_TRAIT_H
