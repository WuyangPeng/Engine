// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.2 (2020/06/04 10:29)

#ifndef FRAMEWORK_WINDOW_PROCESS_SUITE_VIRTUAL_KEYS_TYPES_TESTING_H
#define FRAMEWORK_WINDOW_PROCESS_SUITE_VIRTUAL_KEYS_TYPES_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
	class VirtualKeysTypesTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = VirtualKeysTypesTesting;
		using ParentType = UnitTest;

	public:
		explicit VirtualKeysTypesTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();

		void WindowKeysTest(); 
		void GlutKeysTest();
		void SetModifiersTest();

		static System::WindowsWParam RandomParam(System::WindowsWParam wParam,int mouseModifiers, bool isDown) noexcept;

		constexpr static bool IsKeyDown(int key, int mouseModifiers) noexcept
		{
			return key == mouseModifiers;
		}

		constexpr static bool IsButtonDown(int button, int mouseModifiers) noexcept
		{
			return button == mouseModifiers;
		}

		static int GetModifiers(int keyDown) noexcept;
		static int GetButton(int mouseDown) noexcept;
	};
}

#endif // FRAMEWORK_WINDOW_PROCESS_SUITE_VIRTUAL_KEYS_TYPES_TESTING_H