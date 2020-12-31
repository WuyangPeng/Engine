// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 16:43)

#ifndef FRAMEWORK_LINUX_LINUX_FRAME_BUILD_H
#define FRAMEWORK_LINUX_LINUX_FRAME_BUILD_H

namespace Framework
{
	template <typename LinuxProcess>
	class LinuxFrameBuild
	{
	public:
		using ClassType = LinuxFrameBuild<LinuxProcess>;

	public:
		LinuxFrameBuild() noexcept;
		virtual ~LinuxFrameBuild();
		LinuxFrameBuild(const LinuxFrameBuild& rhs) noexcept = default;
		LinuxFrameBuild& operator=(const LinuxFrameBuild& rhs) noexcept = default;
		LinuxFrameBuild(LinuxFrameBuild&& rhs) noexcept = default;
		LinuxFrameBuild& operator=(LinuxFrameBuild&& rhs) noexcept = default;

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		void EnterMessageLoop() noexcept;
	};
}

#endif // FRAMEWORK_LINUX_LINUX_FRAME_BUILD_H
