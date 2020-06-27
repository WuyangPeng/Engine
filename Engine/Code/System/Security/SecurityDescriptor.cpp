// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:59)

#include "System/SystemExport.h"

#include "SecurityDescriptor.h" 
#include "Flags/SecurityDescriptorFlags.h"
#include "System/Window/WindowSystem.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Helper/EnumCast.h"

bool System
	::InitializeSystemSecurityDescriptor(SecurityDescriptorPtr securityDescriptor) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::InitializeSecurityDescriptor(securityDescriptor, EnumCastUnderlying(InitializeSecurityDescriptorRevision::Revision)) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(securityDescriptor);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SetSystemSecurityDescriptorControl(SecurityDescriptorPtr securityDescriptor, SecurityDescriptorControlBits controlBitsOfInterest, SecurityDescriptorControlBits controlBitsToSet) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::SetSecurityDescriptorControl(securityDescriptor, static_cast<SecurityDescriptorControl>(controlBitsOfInterest), static_cast<SecurityDescriptorControl>(controlBitsToSet)) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(securityDescriptor);
	SYSTEM_UNUSED_ARG(controlBitsOfInterest);
	SYSTEM_UNUSED_ARG(controlBitsToSet);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SetSecurityDescriptorDiscretionaryAccessControlList(SecurityDescriptorPtr securityDescriptor, bool daclPresent, AccessCheckACLPtr dacl, bool daclDefaulted) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::SetSecurityDescriptorDacl(securityDescriptor, BoolConversion(daclPresent), dacl, daclDefaulted) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(securityDescriptor);
	SYSTEM_UNUSED_ARG(daclPresent);
	SYSTEM_UNUSED_ARG(dacl);
	SYSTEM_UNUSED_ARG(daclDefaulted);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SetSystemSecurityDescriptorGroup(SecurityDescriptorPtr securityDescriptor, SecuritySIDPtr group, bool groupDefaulted) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::SetSecurityDescriptorGroup(securityDescriptor, group, BoolConversion(groupDefaulted)) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(securityDescriptor);
	SYSTEM_UNUSED_ARG(group);
	SYSTEM_UNUSED_ARG(groupDefaulted);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SetSystemSecurityDescriptorOwner(SecurityDescriptorPtr securityDescriptor, SecuritySIDPtr group, bool ownerDefaulted) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::SetSecurityDescriptorOwner(securityDescriptor, group, BoolConversion(ownerDefaulted)) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(securityDescriptor);
	SYSTEM_UNUSED_ARG(group);
	SYSTEM_UNUSED_ARG(ownerDefaulted);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SetSecurityDescriptorResourceManagerControl(SecurityDescriptorPtr securityDescriptor, WindowUCharPtr rmControl) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::SetSecurityDescriptorRMControl(securityDescriptor, rmControl) == EnumCastUnderlying<WindowDWord>(SecurityDescriptorRMControlReturn::Success))
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(securityDescriptor);
	SYSTEM_UNUSED_ARG(rmControl);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SetSecurityDescriptorSystemAccessControlList(SecurityDescriptorPtr securityDescriptor, bool saclPresent, AccessCheckACLPtr sacl, bool saclDefaulted) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::SetSecurityDescriptorSacl(securityDescriptor, BoolConversion(saclPresent), sacl, BoolConversion(saclDefaulted)) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(securityDescriptor);
	SYSTEM_UNUSED_ARG(saclPresent);
	SYSTEM_UNUSED_ARG(sacl);
	SYSTEM_UNUSED_ARG(saclDefaulted);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetSystemSecurityDescriptorControl(SecurityDescriptorPtr securityDescriptor, SecurityDescriptorControlBits* control, WindowDWordPtr revision) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	SecurityDescriptorControl securityDescriptorControl{ 0 };
	if (::GetSecurityDescriptorControl(securityDescriptor, &securityDescriptorControl, revision) != g_False)
	{
		UnderlyingCastEnumPtr(securityDescriptorControl, control);

		return true;
	}
	else
	{
		return false;
	}
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(securityDescriptor);
	SYSTEM_UNUSED_ARG(control);
	SYSTEM_UNUSED_ARG(revision);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetSecurityDescriptorDiscretionaryAccessControlList(SecurityDescriptorPtr securityDescriptor, WindowBoolPtr daclPresent, AccessCheckACLPtr* dacl, bool* daclDefaulted) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	WindowBool result{ g_False };
	if (::GetSecurityDescriptorDacl(securityDescriptor, daclPresent, dacl, &result) != g_False)
	{
		BoolConversion(result, daclDefaulted);

		return true;
	}		
	else
	{
		return false;
	}
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(securityDescriptor);
	SYSTEM_UNUSED_ARG(daclPresent);
	SYSTEM_UNUSED_ARG(dacl);
	SYSTEM_UNUSED_ARG(daclDefaulted);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetSystemSecurityDescriptorGroup(SecurityDescriptorPtr securityDescriptor, SecuritySIDPtr* group, bool* groupDefaulted) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	WindowBool result{ g_False };
	if (::GetSecurityDescriptorGroup(securityDescriptor, group, &result) != g_False)
	{
		BoolConversion(result, groupDefaulted);

		return true;
	}
	else
	{
		return false;
	}
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(securityDescriptor);
	SYSTEM_UNUSED_ARG(group);
	SYSTEM_UNUSED_ARG(groupDefaulted);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System
	::GetSystemSecurityDescriptorLength(SecurityDescriptorPtr securityDescriptor) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::GetSecurityDescriptorLength(securityDescriptor);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(securityDescriptor);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetSystemSecurityDescriptorOwner(SecurityDescriptorPtr securityDescriptor, SecuritySIDPtr* owner, bool* ownerDefaulted) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	WindowBool result{ g_False };
	if (::GetSecurityDescriptorOwner(securityDescriptor, owner, &result) != g_False)
	{
		BoolConversion(result, ownerDefaulted);

		return true;
	}
	else
	{
		return false;
	}
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(securityDescriptor);
	SYSTEM_UNUSED_ARG(owner);
	SYSTEM_UNUSED_ARG(ownerDefaulted);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetSecurityDescriptorResourceManagerControl(SecurityDescriptorPtr securityDescriptor, WindowUCharPtr rmControl) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::GetSecurityDescriptorRMControl(securityDescriptor, rmControl) == EnumCastUnderlying<WindowDWord>(SecurityDescriptorRMControlReturn::Success))
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(securityDescriptor);
	SYSTEM_UNUSED_ARG(rmControl);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetSecurityDescriptorSystemAccessControlList(SecurityDescriptorPtr securityDescriptor, WindowBoolPtr saclPresent, AccessCheckACLPtr* sacl, bool* saclDefaulted) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	WindowBool result{ g_False };
	if (::GetSecurityDescriptorSacl(securityDescriptor, saclPresent, sacl, &result) != g_False)
	{
		BoolConversion(result, saclDefaulted);

		return true;
	}
	else
	{
		return false;
	}
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(securityDescriptor);
	SYSTEM_UNUSED_ARG(saclPresent);
	SYSTEM_UNUSED_ARG(sacl);
	SYSTEM_UNUSED_ARG(saclDefaulted);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::IsSecurityDescriptorValid(SecurityDescriptorPtr securityDescriptor) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::IsValidSecurityDescriptor(securityDescriptor) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(securityDescriptor);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetUserObjectSystemSecurity(ThreadHandle obj, SecurityRequestedInformation requested, SecurityDescriptorPtr securityDescriptor, WindowDWord length, WindowDWordPtr lengthNeeded) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	SecurityInformation securityInformation{ EnumCastUnderlying<SecurityInformation>(requested) };
	if (g_False != ::GetUserObjectSecurity(obj, &securityInformation, securityDescriptor, length, lengthNeeded))
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(obj);
	SYSTEM_UNUSED_ARG(requested);
	SYSTEM_UNUSED_ARG(securityDescriptor);
	SYSTEM_UNUSED_ARG(length);
	SYSTEM_UNUSED_ARG(lengthNeeded);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

