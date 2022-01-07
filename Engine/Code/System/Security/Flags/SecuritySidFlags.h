///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 10:41)

#ifndef SYSTEM_SECURITY_SECURITY_SID_FLAGS_H
#define SYSTEM_SECURITY_SECURITY_SID_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class MandatoryLabelAuthority
    {
        UntrustedRid = SECURITY_MANDATORY_UNTRUSTED_RID,
        LowRid = SECURITY_MANDATORY_LOW_RID,
        MediumRid = SECURITY_MANDATORY_MEDIUM_RID,
        MediumPlusRid = SECURITY_MANDATORY_MEDIUM_PLUS_RID,
        HighRid = SECURITY_MANDATORY_HIGH_RID,
        SystemRid = SECURITY_MANDATORY_SYSTEM_RID,
        ProtectedProcessRid = SECURITY_MANDATORY_PROTECTED_PROCESS_RID,
    };

    enum class WellKnownAliases
    {
        Admins = DOMAIN_ALIAS_RID_ADMINS,
        Users = DOMAIN_ALIAS_RID_USERS,
        Guests = DOMAIN_ALIAS_RID_GUESTS,
        PowerUsers = DOMAIN_ALIAS_RID_POWER_USERS,

        AccountOps = DOMAIN_ALIAS_RID_ACCOUNT_OPS,
        SystemOps = DOMAIN_ALIAS_RID_SYSTEM_OPS,
        PrintOps = DOMAIN_ALIAS_RID_PRINT_OPS,
        BackupOps = DOMAIN_ALIAS_RID_BACKUP_OPS,

        Replicator = DOMAIN_ALIAS_RID_REPLICATOR,
        RasServers = DOMAIN_ALIAS_RID_RAS_SERVERS,
        Prew2kCompAccess = DOMAIN_ALIAS_RID_PREW2KCOMPACCESS,
        RemoteDesktopUsers = DOMAIN_ALIAS_RID_REMOTE_DESKTOP_USERS,
        NetworkConfigurationOps = DOMAIN_ALIAS_RID_NETWORK_CONFIGURATION_OPS,
        IncomingForestTrustBuilder = DOMAIN_ALIAS_RID_INCOMING_FOREST_TRUST_BUILDERS,

        MonitoringUsers = DOMAIN_ALIAS_RID_MONITORING_USERS,
        LoggingUsers = DOMAIN_ALIAS_RID_LOGGING_USERS,
        Authorizationaccess = DOMAIN_ALIAS_RID_AUTHORIZATIONACCESS,
        TsLicenseServers = DOMAIN_ALIAS_RID_TS_LICENSE_SERVERS,
        DcomUsers = DOMAIN_ALIAS_RID_DCOM_USERS,
        Iusers = DOMAIN_ALIAS_RID_IUSERS,
        CryptoOperators = DOMAIN_ALIAS_RID_CRYPTO_OPERATORS,
        CacheablePrincipalsGroup = DOMAIN_ALIAS_RID_CACHEABLE_PRINCIPALS_GROUP,
        NonCacheablePrincipalsGroup = DOMAIN_ALIAS_RID_NON_CACHEABLE_PRINCIPALS_GROUP,
        EventLogReadersGroup = DOMAIN_ALIAS_RID_EVENT_LOG_READERS_GROUP,
        CertsvcDcomAccessGroup = DOMAIN_ALIAS_RID_CERTSVC_DCOM_ACCESS_GROUP,
    };

    enum class WellKnownSecurity
    {
        DialupRid = SECURITY_DIALUP_RID,
        NetworkRid = SECURITY_NETWORK_RID,
        BatchRid = SECURITY_BATCH_RID,
        InteractiveRid = SECURITY_INTERACTIVE_RID,
        LogonIdsRid = SECURITY_LOGON_IDS_RID,
        LogonIdsRidCount = SECURITY_LOGON_IDS_RID_COUNT,
        ServiceRid = SECURITY_SERVICE_RID,
        AnonymousLogonRid = SECURITY_ANONYMOUS_LOGON_RID,
        ProxyRid = SECURITY_PROXY_RID,
        EnterpriseControllersRid = SECURITY_ENTERPRISE_CONTROLLERS_RID,
        ServerLogonRid = SECURITY_SERVER_LOGON_RID,
        PrincipalSelfRid = SECURITY_PRINCIPAL_SELF_RID,
        AuthenticatedUserRid = SECURITY_AUTHENTICATED_USER_RID,
        RestrictedCodeRid = SECURITY_RESTRICTED_CODE_RID,
        TerminalServerRid = SECURITY_TERMINAL_SERVER_RID,
        RemoteLogonRid = SECURITY_REMOTE_LOGON_RID,
        ThisOrganizationRid = SECURITY_THIS_ORGANIZATION_RID,
        IuserRid = SECURITY_IUSER_RID,
        LocalSystemRid = SECURITY_LOCAL_SYSTEM_RID,
        LocalServiceRid = SECURITY_LOCAL_SERVICE_RID,
        NetworkServiceRid = SECURITY_NETWORK_SERVICE_RID,

        NtNonUnique = SECURITY_NT_NON_UNIQUE,
        NtNonUniqueSubAuthCount = SECURITY_NT_NON_UNIQUE_SUB_AUTH_COUNT,

        EnterpriseReadonlyControllersRid = SECURITY_ENTERPRISE_READONLY_CONTROLLERS_RID,

        BuiltinDomainRid = SECURITY_BUILTIN_DOMAIN_RID,
        WriteRestrictedCodeRid = SECURITY_WRITE_RESTRICTED_CODE_RID,

        PackageBaseRid = SECURITY_PACKAGE_BASE_RID,
        PackageRidCount = SECURITY_PACKAGE_RID_COUNT,
        PackageNtlmRid = SECURITY_PACKAGE_NTLM_RID,
        PackageSchannelRid = SECURITY_PACKAGE_SCHANNEL_RID,
        PackageDigestRid = SECURITY_PACKAGE_DIGEST_RID,

        CredTypeBaseRid = SECURITY_CRED_TYPE_BASE_RID,
        CredTypeRidCount = SECURITY_CRED_TYPE_RID_COUNT,
        CredTypeThisOrgCertRi = SECURITY_CRED_TYPE_THIS_ORG_CERT_RID,

        MinBaseRid = SECURITY_MIN_BASE_RID,

        ServiceIdBaseRid = SECURITY_SERVICE_ID_BASE_RID,
        ServiceIdRidCount = SECURITY_SERVICE_ID_RID_COUNT,

        ReservedIdBaseRid = SECURITY_RESERVED_ID_BASE_RID,

        ApppoolIdBaseRid = SECURITY_APPPOOL_ID_BASE_RID,
        ApppoolIdRidCount = SECURITY_APPPOOL_ID_RID_COUNT,

        VirtualserverIdBaseRid = SECURITY_VIRTUALSERVER_ID_BASE_RID,
        VirtualserverIdRidCount = SECURITY_VIRTUALSERVER_ID_RID_COUNT,

        UsermodedriverhostIdBaseRid = SECURITY_USERMODEDRIVERHOST_ID_BASE_RID,
        UsermodedriverhostIdRidCount = SECURITY_USERMODEDRIVERHOST_ID_RID_COUNT,

        CloudInfrastructureServicesIdBaseRid = SECURITY_CLOUD_INFRASTRUCTURE_SERVICES_ID_BASE_RID,
        CloudInfrastructureServicesIdRidCount = SECURITY_CLOUD_INFRASTRUCTURE_SERVICES_ID_RID_COUNT,

        WmihostIdBaseRid = SECURITY_WMIHOST_ID_BASE_RID,
        WmihostIdRidCount = SECURITY_WMIHOST_ID_RID_COUNT,

        TaskIdBaseRid = SECURITY_TASK_ID_BASE_RID,

        NfsIdBaseRid = SECURITY_NFS_ID_BASE_RID,

        ComIdBaseRid = SECURITY_COM_ID_BASE_RID,

        VirtualaccountIdRidCount = SECURITY_VIRTUALACCOUNT_ID_RID_COUNT,

        MaxBaseRid = SECURITY_MAX_BASE_RID,
        MaxAlwaysFiltered = SECURITY_MAX_ALWAYS_FILTERED,
        MinNeverFiltered = SECURITY_MIN_NEVER_FILTERED,

        OtherOrganizationRid = SECURITY_OTHER_ORGANIZATION_RID,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class MandatoryLabelAuthority
    {
        UntrustedRid = (0x00000000L),
        LowRid = (0x00001000L),
        MediumRid = (0x00002000L),
        MediumPlusRid = (MediumRid + 0x100),
        HighRid = (0x00003000L),
        SystemRid = (0x00004000L),
        ProtectedProcessRid = (0x00005000L),
    };

    enum class WellKnownAliases
    {
        Admins = (0x00000220L),
        Users = (0x00000221L),
        Guests = (0x00000222L),
        PowerUsers = (0x00000223L),

        AccountOps = (0x00000224L),
        SystemOps = (0x00000225L),
        PrintOps = (0x00000226L),
        BackupOps = (0x00000227L),

        Replicator = (0x00000228L),
        RasServers = (0x00000229L),
        Prew2kCompAccess = (0x0000022AL),
        RemoteDesktopUsers = (0x0000022BL),
        NetworkConfigurationOps = (0x0000022CL),
        IncomingForestTrustBuilder = (0x0000022DL),

        MonitoringUsers = (0x0000022EL),
        LoggingUsers = (0x0000022FL),
        Authorizationaccess = (0x00000230L),
        TsLicenseServers = (0x00000231L),
        DcomUsers = (0x00000232L),
        Iusers = (0x00000238L),
        CryptoOperators = (0x00000239L),
        CacheablePrincipalsGroup = (0x0000023BL),
        NonCacheablePrincipalsGroup = (0x0000023CL),
        EventLogReadersGroup = (0x0000023DL),
        CertsvcDcomAccessGroup = (0x0000023EL),
    };

    enum class WellKnownSecurity
    {
        DialupRid = (0x00000001L),
        NetworkRid = (0x00000002L),
        BatchRid = (0x00000003L),
        InteractiveRid = (0x00000004L),
        LogonIdsRid = (0x00000005L),
        LogonIdsRidCount = (3L),
        ServiceRid = (0x00000006L),
        AnonymousLogonRid = (0x00000007L),
        ProxyRid = (0x00000008L),
        EnterpriseControllersRid = (0x00000009L),
        ServerLogonRid = (0x00000009L),
        PrincipalSelfRid = (0x0000000AL),
        AuthenticatedUserRid = (0x0000000BL),
        RestrictedCodeRid = (0x0000000CL),
        TerminalServerRid = (0x0000000DL),
        RemoteLogonRid = (0x0000000EL),
        ThisOrganizationRid = (0x0000000FL),
        IuserRid = (0x00000011L),
        LocalSystemRid = (0x00000012L),
        LocalServiceRid = (0x00000013L),
        NetworkServiceRid = (0x00000014L),

        NtNonUnique = (0x00000015L),
        NtNonUniqueSubAuthCount = (3L),

        EnterpriseReadonlyControllersRid = (0x00000016L),

        BuiltinDomainRid = (0x00000020L),
        WriteRestrictedCodeRid = (0x00000021L),

        PackageBaseRid = (0x00000040L),
        PackageRidCount = (2L),
        PackageNtlmRid = (0x0000000AL),
        PackageSchannelRid = (0x0000000EL),
        PackageDigestRid = (0x00000015L),

        CredTypeBaseRid = (0x00000041L),
        CredTypeRidCount = (2L),
        CredTypeThisOrgCertRi = (0x00000001L),

        MinBaseRid = (0x00000050L),

        ServiceIdBaseRid = (0x00000050L),
        ServiceIdRidCount = (6L),

        ReservedIdBaseRid = (0x00000051L),

        ApppoolIdBaseRid = (0x00000052L),
        ApppoolIdRidCount = (6L),

        VirtualserverIdBaseRid = (0x00000053L),
        VirtualserverIdRidCount = (6L),

        UsermodedriverhostIdBaseRid = (0x00000054L),
        UsermodedriverhostIdRidCount = (6L),

        CloudInfrastructureServicesIdBaseRid = (0x00000055L),
        CloudInfrastructureServicesIdRidCount = (6L),

        WmihostIdBaseRid = (0x00000056L),
        WmihostIdRidCount = (6L),

        TaskIdBaseRid = (0x00000057L),

        NfsIdBaseRid = (0x00000058L),

        ComIdBaseRid = (0x00000059L),

        VirtualaccountIdRidCount = (6L),

        MaxBaseRid = (0x0000006FL),
        MaxAlwaysFiltered = (0x000003E7L),
        MinNeverFiltered = (0x000003E8L),

        OtherOrganizationRid = (0x000003E8L),
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_SECURITY_SECURITY_SID_FLAGS_H
