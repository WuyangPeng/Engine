// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 13:43)

#ifndef NETWORK_ACE_WRAPPERS_STRING_CONVERSION_H
#define NETWORK_ACE_WRAPPERS_STRING_CONVERSION_H

#include "Network/NetworkDll.h"

#ifdef NETWORK_USE_ACE

#include "Network/Interface/Detail/BaseMainManagerImpl.h"

#include <ace/OS_main.h>

namespace Network
{
	class NETWORK_HIDDEN_DECLARE StringConversion
	{
	public:
		using ClassType = StringConversion;

	public:
		StringConversion() noexcept;

		CLASS_INVARIANT_DECLARE;

		static std::string ACEStringConversionMultiByte(const ACEString& character);
	};
}

#endif // NETWORK_USE_ACE

#endif // NETWORK_ACE_WRAPPERS_STRING_CONVERSION_H
