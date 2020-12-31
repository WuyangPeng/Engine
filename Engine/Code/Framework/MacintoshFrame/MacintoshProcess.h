// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 16:44)

#ifndef FRAMEWORK_MACINTOSH_MACINTOSH_PROCESS_H
#define FRAMEWORK_MACINTOSH_MACINTOSH_PROCESS_H

#include "MacintoshCallBackInterface.h" 

#include <memory>
#include <type_traits> 

namespace Framework
{
	template <typename MacintoshCallBack>
	class MacintoshProcess
	{
	public:
		static_assert(std::is_base_of_v<MacintoshCallBackInterface, MacintoshCallBack>);

	public:
		using CallBackType = MacintoshCallBack;
		using ClassType = MacintoshProcess<CallBackType>;
		using MacintoshCallBackInterfaceSharedPtr = std::shared_ptr< MacintoshCallBackInterface>;

	public:
		MacintoshProcess() = default;
		virtual ~MacintoshProcess() = default;
		MacintoshProcess(const MacintoshProcess& rhs) noexcept = default;
		MacintoshProcess& operator=(const MacintoshProcess& rhs) noexcept = default;
		MacintoshProcess(MacintoshProcess&& rhs) noexcept = default;
		MacintoshProcess& operator=(MacintoshProcess&& rhs) noexcept = default;

		CLASS_INVARIANT_VIRTUAL_DECLARE;
	};

	using MacintoshProcessInterface = MacintoshProcess<MacintoshCallBackInterface>;
}

#endif // FRAMEWORK_MACINTOSH_MACINTOSH_PROCESS_H
