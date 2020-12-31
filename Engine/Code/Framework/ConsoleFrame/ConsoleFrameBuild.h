// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 16:45)

#ifndef FRAMEWORK_CONSOLE_CONSOLE_FRAME_BUILD_H
#define FRAMEWORK_CONSOLE_CONSOLE_FRAME_BUILD_H

namespace Framework
{
	template <typename ConsoleProcess>
	class ConsoleFrameBuild
	{
	public:
		using ClassType = ConsoleFrameBuild<ConsoleProcess>;

	public:
		ConsoleFrameBuild() noexcept;
		virtual ~ConsoleFrameBuild();
		ConsoleFrameBuild(const ConsoleFrameBuild& rhs) noexcept = default;
		ConsoleFrameBuild& operator=(const ConsoleFrameBuild& rhs) noexcept = default;
		ConsoleFrameBuild(ConsoleFrameBuild&& rhs) noexcept = default;
		ConsoleFrameBuild& operator=(ConsoleFrameBuild&& rhs) noexcept = default;

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		void EnterMessageLoop() noexcept;
	};
}

#endif // FRAMEWORK_CONSOLE_CONSOLE_FRAME_BUILD_H
