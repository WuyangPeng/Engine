// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:51)

#ifndef SYSTEM_SECURITY_SECURITY_ACL_FLAGS_H
#define SYSTEM_SECURITY_SECURITY_ACL_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{	 
#ifdef SYSTEM_PLATFORM_WIN32 

	enum class AccessControlListRevision 
	{
		Revision = ACL_REVISION,     
		RevisionDs = ACL_REVISION_DS,
	};
	
#else // !SYSTEM_PLATFORM_WIN32  

	enum class AccessControlListRevision 
	{
		Revision = 2, 
		RevisionDs = 4,
	};
	
#endif // SYSTEM_PLATFORM_WIN32
}

#endif // SYSTEM_SECURITY_SECURITY_ACL_FLAGS_H
