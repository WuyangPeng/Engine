// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 17:05)

#ifndef CORE_TOOLS_MESSAGE_EVENT_PARAMETERS_INTERFACE_H
#define CORE_TOOLS_MESSAGE_EVENT_PARAMETERS_INTERFACE_H

#include "CoreTools/CoreToolsDll.h" 

#include "MessageEventFwd.h"

#include <memory> 

template class CORE_TOOLS_DEFAULT_DECLARE std::weak_ptr<CoreTools::ParametersInterface>;
template class CORE_TOOLS_DEFAULT_DECLARE std::enable_shared_from_this<CoreTools::ParametersInterface>;

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE ParametersInterface : public std::enable_shared_from_this<ParametersInterface>
	{
	public:
		using ClassType = ParametersInterface;
		using BaseSharedPtr = std::shared_ptr<ClassType>;

	public:
		ParametersInterface() noexcept = default;
		virtual ~ParametersInterface() noexcept = default;
		ParametersInterface(const ParametersInterface&) noexcept = default;
		ParametersInterface& operator=(const ParametersInterface&) noexcept = default;
		ParametersInterface(ParametersInterface&&) noexcept = default;
		ParametersInterface& operator=(ParametersInterface&&) noexcept = default;

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual const BaseSharedPtr Clone() const;
	};

	using ParametersInterfaceSharedPtr = std::shared_ptr<ParametersInterface>;
	using ConstParametersInterfaceSharedPtr = std::shared_ptr<const ParametersInterface>;
}

#endif // CORE_TOOLS_MESSAGE_EVENT_CALLBACK_PARAMETERS_H
