//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/24 17:05)

#include "System/SystemExport.h"

#include "AccessCheck.h"
#include "Flags/AccessCheckFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Window/WindowSystem.h"

void System::GetMapGenericMask([[maybe_unused]] WindowDWordPtr accessMask, [[maybe_unused]] AccessCheckGenericMappingPtr genericMapping) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    ::MapGenericMask(accessMask, genericMapping);
#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetAccessCheck([[maybe_unused]] SecurityDescriptorPtr securityDescriptor, [[maybe_unused]] WindowHandle clientToken, [[maybe_unused]] AccessGenericMask desiredAccess, [[maybe_unused]] AccessCheckGenericMappingPtr genericMapping,
                            [[maybe_unused]] SecurityPrivilegeSetPtr privilegeSet, [[maybe_unused]] WindowDWordPtr privilegeSetLength, [[maybe_unused]] WindowDWordPtr grantedAccess, [[maybe_unused]] bool* accessStatus) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    WindowBool resultAccessStatue{ g_False };
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
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetAccessCheckByType([[maybe_unused]] SecurityDescriptorPtr securityDescriptor, [[maybe_unused]] SecuritySIDPtr principalSelfSid, [[maybe_unused]] WindowHandle clientToken, [[maybe_unused]] AccessGenericMask desiredAccess,
                                  [[maybe_unused]] SecurityObjectTypeListPtr objectTypeList, [[maybe_unused]] WindowDWord objectTypeListLength, [[maybe_unused]] AccessCheckGenericMappingPtr genericMapping, [[maybe_unused]] SecurityPrivilegeSetPtr privilegeSet,
                                  [[maybe_unused]] WindowDWordPtr privilegeSetLength, [[maybe_unused]] WindowDWordPtr grantedAccess, [[maybe_unused]] bool* accessStatus) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    WindowBool resultAccessStatue{ g_False };
    if (::AccessCheckByType(securityDescriptor, principalSelfSid, clientToken, EnumCastUnderlying(desiredAccess), objectTypeList,
                            objectTypeListLength, genericMapping, privilegeSet, privilegeSetLength, grantedAccess, &resultAccessStatue) != g_False)
    {
        BoolConversion(resultAccessStatue, accessStatus);

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

bool System::GetAccessCheckByTypeResultList([[maybe_unused]] SecurityDescriptorPtr securityDescriptor, [[maybe_unused]] SecuritySIDPtr principalSelfSid, [[maybe_unused]] WindowHandle clientToken, [[maybe_unused]] AccessGenericMask desiredAccess,
                                            [[maybe_unused]] SecurityObjectTypeListPtr objectTypeList, [[maybe_unused]] WindowDWord objectTypeListLength, [[maybe_unused]] AccessCheckGenericMappingPtr genericMapping, [[maybe_unused]] SecurityPrivilegeSetPtr privilegeSet,
                                            [[maybe_unused]] WindowDWordPtr privilegeSetLength, [[maybe_unused]] WindowDWordPtr grantedAccessList, [[maybe_unused]] WindowDWordPtr accessStatusList) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::AccessCheckByTypeResultList(securityDescriptor, principalSelfSid, clientToken, EnumCastUnderlying(desiredAccess), objectTypeList,
                                      objectTypeListLength, genericMapping, privilegeSet, privilegeSetLength, grantedAccessList, accessStatusList) != g_False)
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

System::AccessGenericMask System::GetFileMapGenericMask(FileHandleDesiredAccess accessMask, AccessCheckGenericMapping& genericMapping) noexcept
{
    genericMapping.GenericRead = EnumCastUnderlying(AccessGenericMask::FileGenericRead);
    genericMapping.GenericWrite = EnumCastUnderlying(AccessGenericMask::FileGenericWrite);
    genericMapping.GenericExecute = EnumCastUnderlying(AccessGenericMask::FileGenericExecute);
    genericMapping.GenericAll = EnumCastUnderlying(AccessGenericMask::FileAllAccess);

    auto mapGenericMask = EnumCastUnderlying<WindowDWord>(accessMask);

    GetMapGenericMask(&mapGenericMask, &genericMapping);

    return UnderlyingCastEnum<AccessGenericMask>(mapGenericMask);
}

System::AccessGenericMask System::GetTransactionManagerMapGenericMask(FileHandleDesiredAccess accessMask, AccessCheckGenericMapping& genericMapping) noexcept
{
    genericMapping.GenericRead = EnumCastUnderlying(AccessGenericMask::TransactionManagerGenericRead);
    genericMapping.GenericWrite = EnumCastUnderlying(AccessGenericMask::TransactionManagerGenericWrite);
    genericMapping.GenericExecute = EnumCastUnderlying(AccessGenericMask::TransactionManagerGenericExecute);
    genericMapping.GenericAll = EnumCastUnderlying(AccessGenericMask::TransactionManagerAllAccess);

    auto mapGenericMask = EnumCastUnderlying<WindowDWord>(accessMask);

    GetMapGenericMask(&mapGenericMask, &genericMapping);

    return UnderlyingCastEnum<AccessGenericMask>(mapGenericMask);
}

System::AccessGenericMask System::GetTransactionMapGenericMask(FileHandleDesiredAccess accessMask, AccessCheckGenericMapping& genericMapping) noexcept
{
    genericMapping.GenericRead = EnumCastUnderlying(AccessGenericMask::TransactionGenericRead);
    genericMapping.GenericWrite = EnumCastUnderlying(AccessGenericMask::TransactionGenericWrite);
    genericMapping.GenericExecute = EnumCastUnderlying(AccessGenericMask::TransactionGenericExecute);
    genericMapping.GenericAll = EnumCastUnderlying(AccessGenericMask::TransactionAllAccess);

    auto mapGenericMask = EnumCastUnderlying<WindowDWord>(accessMask);

    GetMapGenericMask(&mapGenericMask, &genericMapping);

    return UnderlyingCastEnum<AccessGenericMask>(mapGenericMask);
}

System::AccessGenericMask System::GetResourceManagerMapGenericMask(FileHandleDesiredAccess accessMask, AccessCheckGenericMapping& genericMapping) noexcept
{
    genericMapping.GenericRead = EnumCastUnderlying(AccessGenericMask::ResourceManagerGenericRead);
    genericMapping.GenericWrite = EnumCastUnderlying(AccessGenericMask::ResourceManagerGenericWrite);
    genericMapping.GenericExecute = EnumCastUnderlying(AccessGenericMask::ResourceManagerGenericExecute);
    genericMapping.GenericAll = EnumCastUnderlying(AccessGenericMask::ResourceManagerAllAccess);

    auto mapGenericMask = EnumCastUnderlying<WindowDWord>(accessMask);

    GetMapGenericMask(&mapGenericMask, &genericMapping);

    return UnderlyingCastEnum<AccessGenericMask>(mapGenericMask);
}

System::AccessGenericMask System::GetEnlistmentMapGenericMask(FileHandleDesiredAccess accessMask, AccessCheckGenericMapping& genericMapping) noexcept
{
    genericMapping.GenericRead = EnumCastUnderlying(AccessGenericMask::EnlistmentGenericRead);
    genericMapping.GenericWrite = EnumCastUnderlying(AccessGenericMask::EnlistmentGenericWrite);
    genericMapping.GenericExecute = EnumCastUnderlying(AccessGenericMask::EnlistmentGenericExecute);
    genericMapping.GenericAll = EnumCastUnderlying(AccessGenericMask::EnlistmentAllAccess);

    auto mapGenericMask = EnumCastUnderlying<WindowDWord>(accessMask);

    GetMapGenericMask(&mapGenericMask, &genericMapping);

    return UnderlyingCastEnum<AccessGenericMask>(mapGenericMask);
}