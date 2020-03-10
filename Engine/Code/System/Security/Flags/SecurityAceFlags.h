// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:50)

#ifndef SYSTEM_SECURITY_SECURITY_ACE_FLAGS_H
#define SYSTEM_SECURITY_SECURITY_ACE_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{	 
#ifdef SYSTEM_PLATFORM_WIN32 
	 
	enum class ControlACEInheritance 
	{
		ObjectInheritAce = OBJECT_INHERIT_ACE,
		ContainerInheritAce = CONTAINER_INHERIT_ACE,
		NoPropagateInheritAce = NO_PROPAGATE_INHERIT_ACE,
		InheritOnlyAce = INHERIT_ONLY_ACE,
		InheritedAce = INHERITED_ACE,
		ValidInheritFlags = VALID_INHERIT_FLAGS,              
	};	
	
	enum class MandatoryPolicy
	{
		LabelNoWriteUp = SYSTEM_MANDATORY_LABEL_NO_WRITE_UP,   
		LabelNoReadUp = SYSTEM_MANDATORY_LABEL_NO_READ_UP, 
		LabelNoExecuteUp = SYSTEM_MANDATORY_LABEL_NO_EXECUTE_UP,        
	};
	
#else // !SYSTEM_PLATFORM_WIN32  

	enum class ControlACEInheritance 
	{
		ObjectInheritAce = (0x1),
		ContainerInheritAce = (0x2),
		NoPropagateInheritAce = (0x4),
		InheritOnlyAce = (0x8),
		InheritedAce = (0x10),
		ValidInheritFlags = (0x1F),
	};
	
	enum class MandatoryPolicy
	{
		LabelNoWriteUp = 0x1,
		LabelNoReadUp = 0x2,
		LabelNoExecuteUp = 0x4,
	};
	
#endif // SYSTEM_PLATFORM_WIN32
}

#endif // SYSTEM_SECURITY_SECURITY_ACE_FLAGS_H
