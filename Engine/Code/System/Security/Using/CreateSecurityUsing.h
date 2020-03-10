// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:53)

#ifndef SYSTEM_SECURITY_CREATE_SECURITY_USING_H
#define SYSTEM_SECURITY_CREATE_SECURITY_USING_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32	

	using SecurityInformation = SECURITY_INFORMATION;
	using SecurityDescriptor = SECURITY_DESCRIPTOR;
	using SecurityDescriptorPtr = PSECURITY_DESCRIPTOR;
	using AccessCheckGenericMapping = GENERIC_MAPPING;
	using AccessCheckGenericMappingPtr = PGENERIC_MAPPING;

#else // !SYSTEM_PLATFORM_WIN32	 

	using SecurityInformation = uint32_t;
	struct SecurityDescriptor
	{
		uint8_t Revision;
		uint8_t Sbz1;
		uint16_t Control;
		uint16_t Owner;
		uint16_t Group;
		AccessCheckACLPtr Sacl;
		AccessCheckACLPtr Dacl;
	};
	using SecurityDescriptorPtr = void*;
	struct AccessCheckGenericMapping
	{
		AccessMask GenericRead;
		AccessMask GenericWrite;
		AccessMask GenericExecute;
		AccessMask GenericAll;
	};
	using AccessCheckGenericMappingPtr = AccessCheckGenericMapping*;

#endif // SYSTEM_PLATFORM_WIN32
}

#endif // SYSTEM_SECURITY_CREATE_SECURITY_USING_H