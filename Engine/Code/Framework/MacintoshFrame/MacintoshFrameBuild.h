// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 16:44)

#ifndef FRAMEWORK_MACINTOSH_MACINTOSH_FRAME_BUILD_H
#define FRAMEWORK_MACINTOSH_MACINTOSH_FRAME_BUILD_H

namespace Framework
{
	template <typename MacintoshProcess>
	class MacintoshFrameBuild
	{
	public:
		using ClassType = MacintoshFrameBuild<MacintoshProcess>;

	public:
		MacintoshFrameBuild() noexcept;
		virtual ~MacintoshFrameBuild();
		MacintoshFrameBuild(const MacintoshFrameBuild& rhs) noexcept = default;
		MacintoshFrameBuild& operator=(const MacintoshFrameBuild& rhs) noexcept = default;
		MacintoshFrameBuild(MacintoshFrameBuild&& rhs) noexcept = default;
		MacintoshFrameBuild& operator=(MacintoshFrameBuild&& rhs) noexcept = default;

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		void EnterMessageLoop() noexcept;
	};
}

#endif // FRAMEWORK_MACINTOSH_MACINTOSH_FRAME_BUILD_H
