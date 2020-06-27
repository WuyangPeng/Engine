// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:59)

#include "System/SystemExport.h"

#include "CreateSecurity.h" 
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Window/WindowSystem.h"
#include "System/Helper/EnumCast.h"

bool System
	::SystemConvertToAutoInheritPrivateObjectSecurity(SecurityDescriptorPtr parentDescriptor, SecurityDescriptorPtr currentSecurityDescriptor, SecurityDescriptorPtr* newSecurityDescriptor,
													  SystemGUID* objectType, bool isDirectoryObject, AccessCheckGenericMappingPtr genericMapping) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::ConvertToAutoInheritPrivateObjectSecurity(parentDescriptor, currentSecurityDescriptor, newSecurityDescriptor, objectType,
													static_cast<WindowBoolean>(BoolConversion(isDirectoryObject)), genericMapping) != g_False)
	{
		return true;
	}
	else
	{
		return false;
	}
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(parentDescriptor);
	SYSTEM_UNUSED_ARG(currentSecurityDescriptor);
	SYSTEM_UNUSED_ARG(newSecurityDescriptor);
	SYSTEM_UNUSED_ARG(objectType);
	SYSTEM_UNUSED_ARG(isDirectoryObject);
	SYSTEM_UNUSED_ARG(genericMapping);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::CreateSystemPrivateObjectSecurity(SecurityDescriptorPtr parentDescriptor, SecurityDescriptorPtr creatorDescriptor, SecurityDescriptorPtr* newDescriptor,
										bool isDirectoryObject, WindowHandle token, AccessCheckGenericMappingPtr genericMapping) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::CreatePrivateObjectSecurity(parentDescriptor, creatorDescriptor, newDescriptor, BoolConversion(isDirectoryObject), token, genericMapping) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(parentDescriptor);
	SYSTEM_UNUSED_ARG(creatorDescriptor);
	SYSTEM_UNUSED_ARG(newDescriptor);
	SYSTEM_UNUSED_ARG(isDirectoryObject);
	SYSTEM_UNUSED_ARG(token);
	SYSTEM_UNUSED_ARG(genericMapping);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::CreateSystemPrivateObjectSecurity(SecurityDescriptorPtr parentDescriptor, SecurityDescriptorPtr creatorDescriptor, SecurityDescriptorPtr* newDescriptor, SystemGUID* objectType,
										bool isContainerObject, SecurityAutoInherit autoInheritFlags, WindowHandle token, AccessCheckGenericMappingPtr genericMapping) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::CreatePrivateObjectSecurityEx(parentDescriptor, creatorDescriptor, newDescriptor, objectType, isContainerObject, EnumCastUnderlying(autoInheritFlags), token, genericMapping) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(parentDescriptor);
	SYSTEM_UNUSED_ARG(creatorDescriptor);
	SYSTEM_UNUSED_ARG(newDescriptor);
	SYSTEM_UNUSED_ARG(objectType);
	SYSTEM_UNUSED_ARG(isContainerObject);
	SYSTEM_UNUSED_ARG(autoInheritFlags);
	SYSTEM_UNUSED_ARG(token);
	SYSTEM_UNUSED_ARG(genericMapping);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::CreateSystemPrivateObjectSecurityWithMultipleInheritance(SecurityDescriptorPtr parentDescriptor, SecurityDescriptorPtr creatorDescriptor, SecurityDescriptorPtr* newDescriptor,
															   SystemGUID** objectTypes, WindowULong guidCount, bool isContainerObject,
															   SecurityAutoInherit autoInheritFlags, WindowHandle token, AccessCheckGenericMappingPtr genericMapping) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::CreatePrivateObjectSecurityWithMultipleInheritance(parentDescriptor, creatorDescriptor, newDescriptor, objectTypes, guidCount,
															 BoolConversion(isContainerObject), EnumCastUnderlying(autoInheritFlags), token, genericMapping) != g_False)
	{
		return true;
	}
	else
	{
		return false;
	}
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(parentDescriptor);
	SYSTEM_UNUSED_ARG(creatorDescriptor);
	SYSTEM_UNUSED_ARG(newDescriptor);
	SYSTEM_UNUSED_ARG(objectType);
	SYSTEM_UNUSED_ARG(guidCount);
	SYSTEM_UNUSED_ARG(isContainerObject);
	SYSTEM_UNUSED_ARG(autoInheritFlags);
	SYSTEM_UNUSED_ARG(token);
	SYSTEM_UNUSED_ARG(genericMapping);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::DestroySystemPrivateObjectSecurity(SecurityDescriptorPtr* objectDescriptor) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::DestroyPrivateObjectSecurity(objectDescriptor) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(objectDescriptor);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetSystemFileSecurity(const String& fileName, SecurityRequestedInformation requestedInformation, SecurityDescriptorPtr securityDescriptor,
							WindowDWord length, WindowDWordPtr lengthNeeded) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::GetFileSecurity(fileName.c_str(), EnumCastUnderlying(requestedInformation), securityDescriptor, length, lengthNeeded) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(fileName);
	SYSTEM_UNUSED_ARG(requestedInformation);
	SYSTEM_UNUSED_ARG(securityDescriptor);
	SYSTEM_UNUSED_ARG(length);
	SYSTEM_UNUSED_ARG(lengthNeeded);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetSystemKernelObjectSecurity(ThreadHandle handle, SecurityRequestedInformation requestedInformation, SecurityDescriptorPtr securityDescriptor,
									WindowDWord length, WindowDWordPtr lengthNeeded) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::GetKernelObjectSecurity(handle, EnumCastUnderlying(requestedInformation), securityDescriptor, length, lengthNeeded) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(handle);
	SYSTEM_UNUSED_ARG(requestedInformation);
	SYSTEM_UNUSED_ARG(securityDescriptor);
	SYSTEM_UNUSED_ARG(length);
	SYSTEM_UNUSED_ARG(lengthNeeded);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetSystemPrivateObjectSecurity(SecurityDescriptorPtr objectDescriptor, SecurityRequestedInformation securityInformation, SecurityDescriptorPtr resultantDescriptor,
									 WindowDWord descriptorLength, WindowDWordPtr returnLength) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::GetPrivateObjectSecurity(objectDescriptor, EnumCastUnderlying(securityInformation), resultantDescriptor, descriptorLength, returnLength) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(objectDescriptor);
	SYSTEM_UNUSED_ARG(securityInformation);
	SYSTEM_UNUSED_ARG(resultantDescriptor);
	SYSTEM_UNUSED_ARG(descriptorLength);
	SYSTEM_UNUSED_ARG(returnLength);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SetSystemFileSecurity(const TChar* fileName, SecurityRequestedInformation securityInformation, SecurityDescriptorPtr securityDescriptor) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::SetFileSecurity(fileName, EnumCastUnderlying(securityInformation), securityDescriptor) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(fileName);
	SYSTEM_UNUSED_ARG(securityInformation);
	SYSTEM_UNUSED_ARG(securityDescriptor);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SetSystemKernelObjectSecurity(ThreadHandle handle, SecurityRequestedInformation securityInformation, SecurityDescriptorPtr securityDescriptor) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::SetKernelObjectSecurity(handle, EnumCastUnderlying(securityInformation), securityDescriptor) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(handle);
	SYSTEM_UNUSED_ARG(securityInformation);
	SYSTEM_UNUSED_ARG(securityDescriptor);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SetSystemPrivateObjectSecurity(SecurityRequestedInformation securityInformation, SecurityDescriptorPtr modificationDescriptor, SecurityDescriptorPtr* objectsSecurityDescriptor,
									 AccessCheckGenericMappingPtr genericMapping, WindowHandle token) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::SetPrivateObjectSecurity(EnumCastUnderlying(securityInformation), modificationDescriptor, objectsSecurityDescriptor, genericMapping, token) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(securityInformation);
	SYSTEM_UNUSED_ARG(modificationDescriptor);
	SYSTEM_UNUSED_ARG(objectsSecurityDescriptor);
	SYSTEM_UNUSED_ARG(genericMapping);
	SYSTEM_UNUSED_ARG(token);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::SetSystemSecurityAccessMask(SecurityRequestedInformation securityInformation, WindowDWordPtr desiredAccess) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::SetSecurityAccessMask(EnumCastUnderlying(securityInformation), desiredAccess);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(securityInformation);
	SYSTEM_UNUSED_ARG(desiredAccess);
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SetSystemPrivateObjectSecurity(SecurityRequestedInformation securityInformation, SecurityDescriptorPtr modificationDescriptor, SecurityDescriptorPtr* objectsSecurityDescriptor,
									 SecurityAutoInherit autoInheritFlags, AccessCheckGenericMappingPtr genericMapping, WindowHandle token) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::SetPrivateObjectSecurityEx(EnumCastUnderlying(securityInformation), modificationDescriptor, objectsSecurityDescriptor, EnumCastUnderlying(autoInheritFlags), genericMapping, token) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(securityInformation);
	SYSTEM_UNUSED_ARG(modificationDescriptor);
	SYSTEM_UNUSED_ARG(objectsSecurityDescriptor);
	SYSTEM_UNUSED_ARG(autoInheritFlags);
	SYSTEM_UNUSED_ARG(genericMapping);
	SYSTEM_UNUSED_ARG(token);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

