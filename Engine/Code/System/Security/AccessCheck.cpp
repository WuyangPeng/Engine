///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.3 (2021/05/24 20:42)

#include "System/SystemExport.h"

#include "AccessCheck.h"
#include "Flags/AccessCheckFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Windows/WindowsSystem.h"

void System::GetMapGenericMask(WindowsDWordPtr accessMask, AccessCheckGenericMappingPtr genericMapping) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    ::MapGenericMask(accessMask, genericMapping);

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsDWordPtr, AccessCheckGenericMappingPtr>(accessMask, genericMapping);

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetAccessCheck(SecurityDescriptorPtr securityDescriptor,
                            WindowsHandle clientToken,
                            AccessGenericMask desiredAccess,
                            AccessCheckGenericMappingPtr genericMapping,
                            SecurityPrivilegeSetPtr privilegeSet,
                            WindowsDWordPtr privilegeSetLength,
                            WindowsDWordPtr grantedAccess,
                            bool* accessStatus) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    WindowsBool resultAccessStatue{ g_False };
    if (::AccessCheck(securityDescriptor, clientToken, EnumCastUnderlying(desiredAccess), genericMapping, privilegeSet, privilegeSetLength, grantedAccess, &resultAccessStatue) != g_False)
    {
        BoolConversion(resultAccessStatue, accessStatus);

        return true;
    }
    else
    {
        return false;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<SecurityDescriptorPtr,
                 WindowsHandle,
                 AccessGenericMask,
                 AccessCheckGenericMappingPtr,
                 SecurityPrivilegeSetPtr,
                 WindowsDWordPtr,
                 WindowsDWordPtr,
                 bool*>(securityDescriptor,
                        clientToken,
                        desiredAccess,
                        genericMapping,
                        privilegeSet,
                        privilegeSetLength,
                        grantedAccess,
                        &resultAccessStatue);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetAccessCheckByType(SecurityDescriptorPtr securityDescriptor,
                                  SecuritySIDPtr principalSelfSid,
                                  WindowsHandle clientToken,
                                  AccessGenericMask desiredAccess,
                                  SecurityObjectTypeListPtr objectTypeList,
                                  WindowsDWord objectTypeListLength,
                                  AccessCheckGenericMappingPtr genericMapping,
                                  SecurityPrivilegeSetPtr privilegeSet,
                                  WindowsDWordPtr privilegeSetLength,
                                  WindowsDWordPtr grantedAccess,
                                  bool* accessStatus) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    WindowsBool resultAccessStatue{ g_False };
    if (::AccessCheckByType(securityDescriptor,
                            principalSelfSid,
                            clientToken,
                            EnumCastUnderlying(desiredAccess),
                            objectTypeList,
                            objectTypeListLength,
                            genericMapping,
                            privilegeSet,
                            privilegeSetLength,
                            grantedAccess,
                            &resultAccessStatue) != g_False)
    {
        BoolConversion(resultAccessStatue, accessStatus);

        return true;
    }
    else
    {
        return false;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<SecurityDescriptorPtr,
                 SecuritySIDPtr,
                 WindowsHandle,
                 AccessGenericMask,
                 SecurityObjectTypeListPtr,
                 WindowsDWord,
                 AccessCheckGenericMappingPtr,
                 SecurityPrivilegeSetPtr,
                 WindowsDWordPtr,
                 WindowsDWordPtr,
                 bool*>(securityDescriptor,
                        principalSelfSid,
                        clientToken,
                        desiredAccess,
                        objectTypeList,
                        objectTypeListLength,
                        genericMapping,
                        privilegeSet,
                        privilegeSetLength,
                        grantedAccess,
                        &resultAccessStatue);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetAccessCheckByTypeResultList(SecurityDescriptorPtr securityDescriptor,
                                            SecuritySIDPtr principalSelfSid,
                                            WindowsHandle clientToken,
                                            AccessGenericMask desiredAccess,
                                            SecurityObjectTypeListPtr objectTypeList,
                                            WindowsDWord objectTypeListLength,
                                            AccessCheckGenericMappingPtr genericMapping,
                                            SecurityPrivilegeSetPtr privilegeSet,
                                            WindowsDWordPtr privilegeSetLength,
                                            WindowsDWordPtr grantedAccessList,
                                            WindowsDWordPtr accessStatusList) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::AccessCheckByTypeResultList(securityDescriptor,
                                      principalSelfSid,
                                      clientToken,
                                      EnumCastUnderlying(desiredAccess),
                                      objectTypeList,
                                      objectTypeListLength,
                                      genericMapping,
                                      privilegeSet,
                                      privilegeSetLength,
                                      grantedAccessList,
                                      accessStatusList) != g_False)
    {
        return true;
    }
    else
    {
        return false;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<SecurityDescriptorPtr,
                 SecuritySIDPtr,
                 WindowsHandle,
                 AccessGenericMask,
                 SecurityObjectTypeListPtr,
                 WindowsDWord,
                 AccessCheckGenericMappingPtr,
                 SecurityPrivilegeSetPtr,
                 WindowsDWordPtr,
                 WindowsDWordPtr,
                 WindowsDWordPtr>(securityDescriptor,
                                 principalSelfSid,
                                 clientToken,
                                 desiredAccess,
                                 objectTypeList,
                                 objectTypeListLength,
                                 genericMapping,
                                 privilegeSet,
                                 privilegeSetLength,
                                 grantedAccessList,
                                 accessStatusList);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::AccessGenericMask System::GetFileMapGenericMask(FileHandleDesiredAccess accessMask, AccessCheckGenericMapping& genericMapping) noexcept
{
    genericMapping.GenericRead = EnumCastUnderlying(AccessGenericMask::FileGenericRead);
    genericMapping.GenericWrite = EnumCastUnderlying(AccessGenericMask::FileGenericWrite);
    genericMapping.GenericExecute = EnumCastUnderlying(AccessGenericMask::FileGenericExecute);
    genericMapping.GenericAll = EnumCastUnderlying(AccessGenericMask::FileAllAccess);

    auto mapGenericMask = EnumCastUnderlying<WindowsDWord>(accessMask);

    GetMapGenericMask(&mapGenericMask, &genericMapping);

    return UnderlyingCastEnum<AccessGenericMask>(mapGenericMask);
}

System::AccessGenericMask System::GetTransactionManagerMapGenericMask(FileHandleDesiredAccess accessMask, AccessCheckGenericMapping& genericMapping) noexcept
{
    genericMapping.GenericRead = EnumCastUnderlying(AccessGenericMask::TransactionManagerGenericRead);
    genericMapping.GenericWrite = EnumCastUnderlying(AccessGenericMask::TransactionManagerGenericWrite);
    genericMapping.GenericExecute = EnumCastUnderlying(AccessGenericMask::TransactionManagerGenericExecute);
    genericMapping.GenericAll = EnumCastUnderlying(AccessGenericMask::TransactionManagerAllAccess);

    auto mapGenericMask = EnumCastUnderlying<WindowsDWord>(accessMask);

    GetMapGenericMask(&mapGenericMask, &genericMapping);

    return UnderlyingCastEnum<AccessGenericMask>(mapGenericMask);
}

System::AccessGenericMask System::GetTransactionMapGenericMask(FileHandleDesiredAccess accessMask, AccessCheckGenericMapping& genericMapping) noexcept
{
    genericMapping.GenericRead = EnumCastUnderlying(AccessGenericMask::TransactionGenericRead);
    genericMapping.GenericWrite = EnumCastUnderlying(AccessGenericMask::TransactionGenericWrite);
    genericMapping.GenericExecute = EnumCastUnderlying(AccessGenericMask::TransactionGenericExecute);
    genericMapping.GenericAll = EnumCastUnderlying(AccessGenericMask::TransactionAllAccess);

    auto mapGenericMask = EnumCastUnderlying<WindowsDWord>(accessMask);

    GetMapGenericMask(&mapGenericMask, &genericMapping);

    return UnderlyingCastEnum<AccessGenericMask>(mapGenericMask);
}

System::AccessGenericMask System::GetResourceManagerMapGenericMask(FileHandleDesiredAccess accessMask, AccessCheckGenericMapping& genericMapping) noexcept
{
    genericMapping.GenericRead = EnumCastUnderlying(AccessGenericMask::ResourceManagerGenericRead);
    genericMapping.GenericWrite = EnumCastUnderlying(AccessGenericMask::ResourceManagerGenericWrite);
    genericMapping.GenericExecute = EnumCastUnderlying(AccessGenericMask::ResourceManagerGenericExecute);
    genericMapping.GenericAll = EnumCastUnderlying(AccessGenericMask::ResourceManagerAllAccess);

    auto mapGenericMask = EnumCastUnderlying<WindowsDWord>(accessMask);

    GetMapGenericMask(&mapGenericMask, &genericMapping);

    return UnderlyingCastEnum<AccessGenericMask>(mapGenericMask);
}

System::AccessGenericMask System::GetEnlistmentMapGenericMask(FileHandleDesiredAccess accessMask, AccessCheckGenericMapping& genericMapping) noexcept
{
    genericMapping.GenericRead = EnumCastUnderlying(AccessGenericMask::EnlistmentGenericRead);
    genericMapping.GenericWrite = EnumCastUnderlying(AccessGenericMask::EnlistmentGenericWrite);
    genericMapping.GenericExecute = EnumCastUnderlying(AccessGenericMask::EnlistmentGenericExecute);
    genericMapping.GenericAll = EnumCastUnderlying(AccessGenericMask::EnlistmentAllAccess);

    auto mapGenericMask = EnumCastUnderlying<WindowsDWord>(accessMask);

    GetMapGenericMask(&mapGenericMask, &genericMapping);

    return UnderlyingCastEnum<AccessGenericMask>(mapGenericMask);
}