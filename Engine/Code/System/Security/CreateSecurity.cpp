///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/19 18:53)

#include "System/SystemExport.h"

#include "CreateSecurity.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Windows/WindowsSystem.h"

#include <gsl/util>

bool System::SystemConvertToAutoInheritPrivateObjectSecurity(SecurityDescriptorPtr parentDescriptor,
                                                             SecurityDescriptorPtr currentSecurityDescriptor,
                                                             SecurityDescriptorPtr* newSecurityDescriptor,
                                                             SystemGUID* objectType,
                                                             bool isDirectoryObject,
                                                             AccessCheckGenericMappingPtr genericMapping) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::ConvertToAutoInheritPrivateObjectSecurity(parentDescriptor,
                                                    currentSecurityDescriptor,
                                                    newSecurityDescriptor,
                                                    objectType,
                                                    gsl::narrow_cast<WindowsBoolean>(BoolConversion(isDirectoryObject)),
                                                    genericMapping) != gFalse)
    {
        return true;
    }
    else
    {
        return false;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(parentDescriptor,
                   currentSecurityDescriptor,
                   newSecurityDescriptor,
                   objectType,
                   isDirectoryObject,
                   genericMapping);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CreateSystemPrivateObjectSecurity(SecurityDescriptorPtr parentDescriptor,
                                               SecurityDescriptorPtr creatorDescriptor,
                                               SecurityDescriptorPtr* newDescriptor,
                                               bool isDirectoryObject,
                                               WindowsHandle token,
                                               AccessCheckGenericMappingPtr genericMapping) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::CreatePrivateObjectSecurity(parentDescriptor, creatorDescriptor, newDescriptor, BoolConversion(isDirectoryObject), token, genericMapping) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(parentDescriptor,
                   creatorDescriptor,
                   newDescriptor,
                   isDirectoryObject,
                   token,
                   genericMapping);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CreateSystemPrivateObjectSecurity(SecurityDescriptorPtr parentDescriptor,
                                               SecurityDescriptorPtr creatorDescriptor,
                                               SecurityDescriptorPtr* newDescriptor,
                                               SystemGUID* objectType,
                                               bool isContainerObject,
                                               SecurityAutoInherit autoInheritFlags,
                                               WindowsHandle token,
                                               AccessCheckGenericMappingPtr genericMapping) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::CreatePrivateObjectSecurityEx(parentDescriptor, creatorDescriptor, newDescriptor, objectType, isContainerObject, EnumCastUnderlying(autoInheritFlags), token, genericMapping) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(parentDescriptor,
                   creatorDescriptor,
                   newDescriptor,
                   objectType,
                   isContainerObject,
                   autoInheritFlags,
                   token,
                   genericMapping);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CreateSystemPrivateObjectSecurityWithMultipleInheritance(SecurityDescriptorPtr parentDescriptor,
                                                                      SecurityDescriptorPtr creatorDescriptor,
                                                                      SecurityDescriptorPtr* newDescriptor,
                                                                      SystemGUID** objectTypes,
                                                                      WindowsULong guidCount,
                                                                      bool isContainerObject,
                                                                      SecurityAutoInherit autoInheritFlags,
                                                                      WindowsHandle token,
                                                                      AccessCheckGenericMappingPtr genericMapping) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::CreatePrivateObjectSecurityWithMultipleInheritance(parentDescriptor,
                                                             creatorDescriptor,
                                                             newDescriptor,
                                                             objectTypes,
                                                             guidCount,
                                                             BoolConversion(isContainerObject),
                                                             EnumCastUnderlying(autoInheritFlags),
                                                             token,
                                                             genericMapping) != gFalse)
    {
        return true;
    }
    else
    {
        return false;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(parentDescriptor,
                   creatorDescriptor,
                   newDescriptor,
                   objectTypes,
                   guidCount,
                   isContainerObject,
                   autoInheritFlags,
                   token,
                   genericMapping);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::DestroySystemPrivateObjectSecurity(SecurityDescriptorPtr* objectDescriptor) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::DestroyPrivateObjectSecurity(objectDescriptor) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(objectDescriptor);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemFileSecurity(const String& fileName,
                                   SecurityRequestedInformation requestedInformation,
                                   SecurityDescriptorPtr securityDescriptor,
                                   WindowsDWord length,
                                   WindowsDWordPtr lengthNeeded) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::GetFileSecurity(fileName.c_str(), EnumCastUnderlying(requestedInformation), securityDescriptor, length, lengthNeeded) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(fileName,
                   requestedInformation,
                   securityDescriptor,
                   length,
                   lengthNeeded);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemKernelObjectSecurity(ThreadHandle handle,
                                           SecurityRequestedInformation requestedInformation,
                                           SecurityDescriptorPtr securityDescriptor,
                                           WindowsDWord length,
                                           WindowsDWordPtr lengthNeeded) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::GetKernelObjectSecurity(handle, EnumCastUnderlying(requestedInformation), securityDescriptor, length, lengthNeeded) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(handle,
                   requestedInformation,
                   securityDescriptor,
                   length,
                   lengthNeeded);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemPrivateObjectSecurity(SecurityDescriptorPtr objectDescriptor,
                                            SecurityRequestedInformation securityInformation,
                                            SecurityDescriptorPtr resultantDescriptor,
                                            WindowsDWord descriptorLength,
                                            WindowsDWordPtr returnLength) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::GetPrivateObjectSecurity(objectDescriptor, EnumCastUnderlying(securityInformation), resultantDescriptor, descriptorLength, returnLength) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(objectDescriptor,
                   securityInformation,
                   resultantDescriptor,
                   descriptorLength,
                   returnLength);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemFileSecurity(const TChar* fileName, SecurityRequestedInformation securityInformation, SecurityDescriptorPtr securityDescriptor) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::SetFileSecurity(fileName, EnumCastUnderlying(securityInformation), securityDescriptor) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(fileName, securityInformation, securityDescriptor);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemKernelObjectSecurity(ThreadHandle handle, SecurityRequestedInformation securityInformation, SecurityDescriptorPtr securityDescriptor) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::SetKernelObjectSecurity(handle, EnumCastUnderlying(securityInformation), securityDescriptor) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(handle, securityInformation, securityDescriptor);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemPrivateObjectSecurity(SecurityRequestedInformation securityInformation,
                                            SecurityDescriptorPtr modificationDescriptor,
                                            SecurityDescriptorPtr* objectsSecurityDescriptor,
                                            AccessCheckGenericMappingPtr genericMapping,
                                            WindowsHandle token) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::SetPrivateObjectSecurity(EnumCastUnderlying(securityInformation), modificationDescriptor, objectsSecurityDescriptor, genericMapping, token) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(securityInformation, modificationDescriptor, objectsSecurityDescriptor, genericMapping, token);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::SetSystemSecurityAccessMask(SecurityRequestedInformation securityInformation, WindowsDWordPtr desiredAccess) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::SetSecurityAccessMask(EnumCastUnderlying(securityInformation), desiredAccess);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(securityInformation, desiredAccess);

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemPrivateObjectSecurity(SecurityRequestedInformation securityInformation,
                                            SecurityDescriptorPtr modificationDescriptor,
                                            SecurityDescriptorPtr* objectsSecurityDescriptor,
                                            SecurityAutoInherit autoInheritFlags,
                                            AccessCheckGenericMappingPtr genericMapping,
                                            WindowsHandle token) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::SetPrivateObjectSecurityEx(EnumCastUnderlying(securityInformation), modificationDescriptor, objectsSecurityDescriptor, EnumCastUnderlying(autoInheritFlags), genericMapping, token) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(securityInformation,
                   modificationDescriptor,
                   objectsSecurityDescriptor,
                   autoInheritFlags,
                   genericMapping,
                   token);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
