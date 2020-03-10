// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:06)

#ifndef FRAMEWORK_APPLICATION_APPLICATION_TRAIT_H
#define FRAMEWORK_APPLICATION_APPLICATION_TRAIT_H

#include "KeyIdentifiers.h"
#include "KeyboardModifiers.h"
#include "MouseButtons.h"
#include "MouseState.h"
#include "MouseModifiers.h"

namespace Framework
{
	enum PlatformTypes
	{
		PlatformTypesWindow,
		PlatformTypesGlut,
		PlatformTypesAndroid
	};

	template <PlatformTypes types>
	struct ApplicationTrait;

	template<>
	struct ApplicationTrait<PlatformTypesWindow>
	{
		using KeyIdentifiers = WindowKeyIdentifiers;
		using KeyboardModifiers = WindowKeyboardModifiers;
		using MouseButtons = WindowMouseButtons;
		using MouseState = WindowMouseState;
		using MouseModifiers = WindowMouseModifiers;
	};

	using WindowApplicationTrait = ApplicationTrait<PlatformTypesWindow>;

	template<>
	struct ApplicationTrait<PlatformTypesGlut>
	{
		using KeyIdentifiers = GlutKeyIdentifiers;
		using KeyboardModifiers = GlutKeyboardModifiers;
		using MouseButtons = GlutMouseButtons;
		using MouseState = GlutMouseState;
		using MouseModifiers = GlutMouseModifiers;
	};

	using GlutApplicationTrait = ApplicationTrait<PlatformTypesGlut>;

	template<>
	struct ApplicationTrait<PlatformTypesAndroid>
	{
		using KeyIdentifiers = AndroidKeyIdentifiers;
		using KeyboardModifiers = AndroidKeyboardModifiers;
		using MouseButtons = AndroidMouseButtons;
		using MouseState = AndroidMouseState;
		using MouseModifiers = AndroidMouseModifiers;
	};

	using AndroidApplicationTrait = ApplicationTrait<PlatformTypesAndroid>;
}

#endif // FRAMEWORK_APPLICATION_APPLICATION_TRAIT_H
