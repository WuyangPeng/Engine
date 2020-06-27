// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 16:43)

#ifndef FRAMEWORK_LINUX_LINUX_PROCESS_H
#define FRAMEWORK_LINUX_LINUX_PROCESS_H

#include "LinuxCallBackInterface.h" 

#include <type_traits> 

namespace Framework
{
	template <typename LinuxCallBack>
	class LinuxProcess
	{
	public:
		static_assert(std::is_base_of_v<LinuxCallBackInterface, LinuxCallBack>);

	public:
		using CallBackType = LinuxCallBack;
		using ClassType = LinuxProcess<CallBackType>;
		using LinuxCallBackInterfaceSharedPtr = std::shared_ptr< LinuxCallBackInterface>;

	public:
		LinuxProcess() = default;
		virtual ~LinuxProcess() = default;
		LinuxProcess(const LinuxProcess& rhs) noexcept = default;
		LinuxProcess& operator=(const LinuxProcess& rhs) noexcept = default;
		LinuxProcess(LinuxProcess&& rhs) noexcept = default;
		LinuxProcess& operator=(LinuxProcess&& rhs) noexcept = default;

		CLASS_INVARIANT_VIRTUAL_DECLARE;
	};

	using LinuxProcessInterface = LinuxProcess<LinuxCallBackInterface>;
}

#endif // FRAMEWORK_LINUX_LINUX_PROCESS_H
