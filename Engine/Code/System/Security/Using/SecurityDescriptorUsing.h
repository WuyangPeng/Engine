// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:57)

#ifndef SYSTEM_SECURITY_SECURITY_DESCRIPTOR_USING_H
#define SYSTEM_SECURITY_SECURITY_DESCRIPTOR_USING_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

	using SecurityDescriptorControl = SECURITY_DESCRIPTOR_CONTROL;
	using SecurityDescriptorControlPtr = PSECURITY_DESCRIPTOR_CONTROL;

#else // !SYSTEM_PLATFORM_WIN32	

	using SecurityDescriptorControl = uint16_t;
	using SecurityDescriptorControlPtr = SecurityDescriptorControl*;

#endif // SYSTEM_PLATFORM_WIN32
}

#endif // SYSTEM_SECURITY_SECURITY_DESCRIPTOR_USING_H