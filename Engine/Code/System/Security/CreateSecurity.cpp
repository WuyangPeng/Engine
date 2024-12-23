/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.2 (2024/10/26 17:39)

#include "System/SystemExport.h"

#include "CreateSecurity.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/Tools.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Windows/WindowsSystem.h"

#include <gsl/util>

bool System::SystemConvertToAutoInheritPrivateObjectSecurity(SecurityDescriptorPtr parentDescriptor,
                                                             SecurityDescriptorPtr currentSecurityDescriptor,
                                                             SecurityDescriptorPtr* newSecurityDescriptor,
                                                             SystemGloballyUniqueIdentifier* objectType,
                                                             bool isDirectoryObject,
                                                             AccessCheckGenericMappingPtr genericMapping) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::ConvertToAutoInheritPrivateObjectSecurity(parentDescriptor,
                                                       currentSecurityDescriptor,
                                                       newSecurityDescriptor,
                                                       objectType,
                                                       gsl::narrow_cast<WindowsBoolean>(BoolConversion(isDirectoryObject)),
                                                       genericMapping) != gFalse;

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

    return ::CreatePrivateObjectSecurity(parentDescriptor, creatorDescriptor, newDescriptor, BoolConversion(isDirectoryObject), token, genericMapping) != gFalse;

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
                                               SystemGloballyUniqueIdentifier* objectType,
                                               bool isContainerObject,
                                               SecurityAutoInherit autoInheritFlags,
                                               WindowsHandle token,
                                               AccessCheckGenericMappingPtr genericMapping) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::CreatePrivateObjectSecurityEx(parentDescriptor, creatorDescriptor, newDescriptor, objectType, isContainerObject, EnumCastUnderlying(autoInheritFlags), token, genericMapping) != gFalse;

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
                                                                      SystemGloballyUniqueIdentifier** objectTypes,
                                                                      WindowsULong guidCount,
                                                                      bool isContainerObject,
                                                                      SecurityAutoInherit autoInheritFlags,
                                                                      WindowsHandle token,
                                                                      AccessCheckGenericMappingPtr genericMapping) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::CreatePrivateObjectSecurityWithMultipleInheritance(parentDescriptor,
                                                                creatorDescriptor,
                                                                newDescriptor,
                                                                objectTypes,
                                                                guidCount,
                                                                BoolConversion(isContainerObject),
                                                                EnumCastUnderlying(autoInheritFlags),
                                                                token,
                                                                genericMapping) != gFalse;

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

    return ::DestroyPrivateObjectSecurity(objectDescriptor) != gFalse;

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

    return ::GetFileSecurity(fileName.c_str(), EnumCastUnderlying(requestedInformation), securityDescriptor, length, lengthNeeded) != gFalse;

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

    return ::GetKernelObjectSecurity(handle, EnumCastUnderlying(requestedInformation), securityDescriptor, length, lengthNeeded) != gFalse;

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

    return ::GetPrivateObjectSecurity(objectDescriptor, EnumCastUnderlying(securityInformation), resultantDescriptor, descriptorLength, returnLength) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(objectDescriptor,
                   securityInformation,
                   resultantDescriptor,
                   descriptorLength,
                   returnLength);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemFileSecurity(const String& fileName, SecurityRequestedInformation securityInformation, SecurityDescriptorPtr securityDescriptor) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::SetFileSecurity(fileName.c_str(), EnumCastUnderlying(securityInformation), securityDescriptor) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(fileName, securityInformation, securityDescriptor);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemKernelObjectSecurity(ThreadHandle handle, SecurityRequestedInformation securityInformation, SecurityDescriptorPtr securityDescriptor) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::SetKernelObjectSecurity(handle, EnumCastUnderlying(securityInformation), securityDescriptor) != gFalse;

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

    return ::SetPrivateObjectSecurity(EnumCastUnderlying(securityInformation), modificationDescriptor, objectsSecurityDescriptor, genericMapping, token) != gFalse;

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

    return ::SetPrivateObjectSecurityEx(EnumCastUnderlying(securityInformation), modificationDescriptor, objectsSecurityDescriptor, EnumCastUnderlying(autoInheritFlags), genericMapping, token) != gFalse;

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