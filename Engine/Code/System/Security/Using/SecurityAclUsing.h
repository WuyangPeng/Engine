// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.0 (2020/01/02 15:56)

#ifndef SYSTEM_SECURITY_SECURITY_ACL_USING_H
#define SYSTEM_SECURITY_SECURITY_ACL_USING_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32	

	using AccessCheckACL = ACL;
	using AccessCheckACLPtr = PACL;
	using SecurityAclInformationClass = ACL_INFORMATION_CLASS;
	using SecurityAclRevisionInformation = ACL_REVISION_INFORMATION;
	using SecurityAclRevisionInformationPtr = PACL_REVISION_INFORMATION;
	using SecurityAclSizeInformation = ACL_SIZE_INFORMATION;
	using SecurityAclSizeInformationPtr = PACL_SIZE_INFORMATION;

#else // !SYSTEM_PLATFORM_WIN32	

	struct AccessCheckACL
	{
		uint8_t AclRevision;
		uint8_t Sbz1;
		uint16_t AclSize;
		uint16_t AceCount;
		uint16_t Sbz2;
	};

	using AccessCheckACLPtr = AccessCheckACL*;
	enum SecurityAclInformationClass
	{
		AclRevisionInformation = 1,
		AclSizeInformation
	};

	struct SecurityAclRevisionInformation
	{
		uint32_t AclRevision;
	};
	using SecurityAclRevisionInformationPtr = SecurityAclRevisionInformation*;
	struct SecurityAclSizeInformation
	{
		uint32_t AceCount;
		uint32_t AclBytesInUse;
		uint32_t AclBytesFree;
	};
	using SecurityAclSizeInformationPtr = SecurityAclSizeInformation*;

#endif // SYSTEM_PLATFORM_WIN32
}

#endif // SYSTEM_SECURITY_SECURITY_ACL_USING_H