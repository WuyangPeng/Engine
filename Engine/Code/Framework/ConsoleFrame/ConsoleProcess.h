// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 16:45)

#ifndef FRAMEWORK_CONSOLE_CONSOLE_PROCESS_H
#define FRAMEWORK_CONSOLE_CONSOLE_PROCESS_H

#include "ConsoleCallBackInterface.h" 

#include <memory>
#include <type_traits> 

namespace Framework
{
	template <typename ConsoleCallBack>
	class ConsoleProcess
	{
	public:
		static_assert(std::is_base_of_v<ConsoleCallBackInterface, ConsoleCallBack>);

	public:
		using CallBackType = ConsoleCallBack;
		using ClassType = ConsoleProcess<CallBackType>;
		using ConsoleCallBackInterfaceSharedPtr = std::shared_ptr<ConsoleCallBackInterface>;

	public:
		ConsoleProcess() = default;
		virtual ~ConsoleProcess() = default;
		ConsoleProcess(const ConsoleProcess& rhs) noexcept = default;
		ConsoleProcess& operator=(const ConsoleProcess& rhs) noexcept = default;
		ConsoleProcess(ConsoleProcess&& rhs) noexcept = default;
		ConsoleProcess& operator=(ConsoleProcess&& rhs) noexcept = default;

		CLASS_INVARIANT_VIRTUAL_DECLARE;
	};

	using ConsoleProcessInterface = ConsoleProcess<ConsoleCallBackInterface>;
}

#endif // FRAMEWORK_CONSOLE_CONSOLE_PROCESS_H
