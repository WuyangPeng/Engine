// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:52)

#ifndef SYSTEM_SECURITY_SECURITY_FLAGS_FWD_H 
#define SYSTEM_SECURITY_SECURITY_FLAGS_FWD_H   

#include "System/Helper/ConfigMacro.h"

namespace System
{
	// AccessCheck
	enum class AccessGenericMask;

	// AddAccess
	enum class SpecificAccess;

	// CreateSecurity
	enum class SecurityRequestedInformation : uint32_t;
	enum class SecurityAutoInherit;

	// SecurityAce
	enum class ControlACEInheritance;
	enum class MandatoryPolicy;

	// SecurityAcl
	enum class AccessControlListRevision;

	// SecurityBase
	enum class SecurityTokenAttributesPrivilege : uint32_t;
	enum class SecurityTokenAttributesGroup : uint32_t;
	enum class SpecifiesAdditionalPrivilegeOptions;

	// SecurityDescriptor
	enum class InitializeSecurityDescriptorRevision;
	enum class SecurityDescriptorControlBits;
	enum class SecurityDescriptorRMControlReturn;

	// SecuritySid
	enum class MandatoryLabelAuthority;
	enum class WellKnownAliases;
	enum class WellKnownSecurity;
}

#endif // SYSTEM_SECURITY_SECURITY_FLAGS_FWD_H