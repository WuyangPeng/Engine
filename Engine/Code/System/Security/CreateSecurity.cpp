// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:59)

#include "System/SystemExport.h"

#include "CreateSecurity.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Window/WindowSystem.h"

#include <gsl/gsl_util>

bool System::SystemConvertToAutoInheritPrivateObjectSecurity([[maybe_unused]] SecurityDescriptorPtr parentDescriptor, [[maybe_unused]] SecurityDescriptorPtr currentSecurityDescriptor, [[maybe_unused]] SecurityDescriptorPtr* newSecurityDescriptor,
                                                             [[maybe_unused]] SystemGUID* objectType, [[maybe_unused]] bool isDirectoryObject, [[maybe_unused]] AccessCheckGenericMappingPtr genericMapping) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::ConvertToAutoInheritPrivateObjectSecurity(parentDescriptor, currentSecurityDescriptor, newSecurityDescriptor, objectType,
                                                    gsl::narrow_cast<WindowBoolean>(BoolConversion(isDirectoryObject)), genericMapping) != g_False)
    {
        return true;
    }
    else
    {
        return false;
    }
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CreateSystemPrivateObjectSecurity([[maybe_unused]] SecurityDescriptorPtr parentDescriptor, [[maybe_unused]] SecurityDescriptorPtr creatorDescriptor, [[maybe_unused]] SecurityDescriptorPtr* newDescriptor,
                                               [[maybe_unused]] bool isDirectoryObject, [[maybe_unused]] WindowHandle token, [[maybe_unused]] AccessCheckGenericMappingPtr genericMapping) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::CreatePrivateObjectSecurity(parentDescriptor, creatorDescriptor, newDescriptor, BoolConversion(isDirectoryObject), token, genericMapping) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CreateSystemPrivateObjectSecurity([[maybe_unused]] SecurityDescriptorPtr parentDescriptor, [[maybe_unused]] SecurityDescriptorPtr creatorDescriptor, [[maybe_unused]] SecurityDescriptorPtr* newDescriptor, [[maybe_unused]] SystemGUID* objectType,
                                               [[maybe_unused]] bool isContainerObject, [[maybe_unused]] SecurityAutoInherit autoInheritFlags, [[maybe_unused]] WindowHandle token, [[maybe_unused]] AccessCheckGenericMappingPtr genericMapping) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::CreatePrivateObjectSecurityEx(parentDescriptor, creatorDescriptor, newDescriptor, objectType, isContainerObject, EnumCastUnderlying(autoInheritFlags), token, genericMapping) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CreateSystemPrivateObjectSecurityWithMultipleInheritance([[maybe_unused]] SecurityDescriptorPtr parentDescriptor, [[maybe_unused]] SecurityDescriptorPtr creatorDescriptor, [[maybe_unused]] SecurityDescriptorPtr* newDescriptor,
                                                                      [[maybe_unused]] SystemGUID** objectTypes, [[maybe_unused]] WindowULong guidCount, [[maybe_unused]] bool isContainerObject,
                                                                      [[maybe_unused]] SecurityAutoInherit autoInheritFlags, [[maybe_unused]] WindowHandle token, [[maybe_unused]] AccessCheckGenericMappingPtr genericMapping) noexcept
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
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::DestroySystemPrivateObjectSecurity([[maybe_unused]] SecurityDescriptorPtr* objectDescriptor) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::DestroyPrivateObjectSecurity(objectDescriptor) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemFileSecurity([[maybe_unused]] const String& fileName, [[maybe_unused]] SecurityRequestedInformation requestedInformation, [[maybe_unused]] SecurityDescriptorPtr securityDescriptor,
                                   [[maybe_unused]] WindowDWord length, [[maybe_unused]] WindowDWordPtr lengthNeeded) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::GetFileSecurity(fileName.c_str(), EnumCastUnderlying(requestedInformation), securityDescriptor, length, lengthNeeded) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemKernelObjectSecurity([[maybe_unused]] ThreadHandle handle, [[maybe_unused]] SecurityRequestedInformation requestedInformation, [[maybe_unused]] SecurityDescriptorPtr securityDescriptor,
                                           [[maybe_unused]] WindowDWord length, [[maybe_unused]] WindowDWordPtr lengthNeeded) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::GetKernelObjectSecurity(handle, EnumCastUnderlying(requestedInformation), securityDescriptor, length, lengthNeeded) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemPrivateObjectSecurity([[maybe_unused]] SecurityDescriptorPtr objectDescriptor, [[maybe_unused]] SecurityRequestedInformation securityInformation, [[maybe_unused]] SecurityDescriptorPtr resultantDescriptor,
                                            [[maybe_unused]] WindowDWord descriptorLength, [[maybe_unused]] WindowDWordPtr returnLength) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::GetPrivateObjectSecurity(objectDescriptor, EnumCastUnderlying(securityInformation), resultantDescriptor, descriptorLength, returnLength) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemFileSecurity([[maybe_unused]] const TChar* fileName, [[maybe_unused]] SecurityRequestedInformation securityInformation, [[maybe_unused]] SecurityDescriptorPtr securityDescriptor) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SetFileSecurity(fileName, EnumCastUnderlying(securityInformation), securityDescriptor) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemKernelObjectSecurity([[maybe_unused]] ThreadHandle handle, [[maybe_unused]] SecurityRequestedInformation securityInformation, [[maybe_unused]] SecurityDescriptorPtr securityDescriptor) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SetKernelObjectSecurity(handle, EnumCastUnderlying(securityInformation), securityDescriptor) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemPrivateObjectSecurity([[maybe_unused]] SecurityRequestedInformation securityInformation, [[maybe_unused]] SecurityDescriptorPtr modificationDescriptor, [[maybe_unused]] SecurityDescriptorPtr* objectsSecurityDescriptor,
                                            [[maybe_unused]] AccessCheckGenericMappingPtr genericMapping, [[maybe_unused]] WindowHandle token) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SetPrivateObjectSecurity(EnumCastUnderlying(securityInformation), modificationDescriptor, objectsSecurityDescriptor, genericMapping, token) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32

    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

void System::SetSystemSecurityAccessMask([[maybe_unused]] SecurityRequestedInformation securityInformation, [[maybe_unused]] WindowDWordPtr desiredAccess) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::SetSecurityAccessMask(EnumCastUnderlying(securityInformation), desiredAccess);
#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemPrivateObjectSecurity([[maybe_unused]] SecurityRequestedInformation securityInformation, [[maybe_unused]] SecurityDescriptorPtr modificationDescriptor, [[maybe_unused]] SecurityDescriptorPtr* objectsSecurityDescriptor,
                                            [[maybe_unused]] SecurityAutoInherit autoInheritFlags, [[maybe_unused]] AccessCheckGenericMappingPtr genericMapping, [[maybe_unused]] WindowHandle token) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SetPrivateObjectSecurityEx(EnumCastUnderlying(securityInformation), modificationDescriptor, objectsSecurityDescriptor, EnumCastUnderlying(autoInheritFlags), genericMapping, token) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}
