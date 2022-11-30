///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/19 18:52)

#ifndef SYSTEM_SECURITY_SECURITY_SID_USING_H
#define SYSTEM_SECURITY_SECURITY_SID_USING_H

#include "LookupPrivilegeUsing.h"
#include "System/Helper/Platform.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using SecuritySIDIndentifierAuthority = SID_IDENTIFIER_AUTHORITY;
    using SecuritySIDIndentifierAuthorityPtr = PSID_IDENTIFIER_AUTHORITY;
    using SecuritySID = SID;
    using SecuritySIDPtr = PSID;
    using SecurityWellKnownSidType = WELL_KNOWN_SID_TYPE;

    constexpr WindowsDWord gSecurityMaxSidSize{ SECURITY_MAX_SID_SIZE };
    constexpr WindowsDWord gSecuritySidSubAuthorities{ SID_MAX_SUB_AUTHORITIES };

#else  // !SYSTEM_PLATFORM_WIN32

    struct SecuritySIDIndentifierAuthority
    {
        uint8_t Value[6];
    };
    using SecuritySIDIndentifierAuthorityPtr = SecuritySIDIndentifierAuthority*;

    struct SecuritySID
    {
        uint8_t Revision;
        uint8_t SubAuthorityCount;
        SecuritySIDIndentifierAuthority IdentifierAuthority;
        unsigned long SubAuthority[1];
    };
    using SecuritySIDPtr = void*;

    enum SecurityWellKnownSidType
    {
        WinNullSid = 0,
        WinWorldSid = 1,
        WinLocalSid = 2,
        WinCreatorOwnerSid = 3,
        WinCreatorGroupSid = 4,
        WinCreatorOwnerServerSid = 5,
        WinCreatorGroupServerSid = 6,
        WinNtAuthoritySid = 7,
        WinDialupSid = 8,
        WinNetworkSid = 9,
        WinBatchSid = 10,
        WinInteractiveSid = 11,
        WinServiceSid = 12,
        WinAnonymousSid = 13,
        WinProxySid = 14,
        WinEnterpriseControllersSid = 15,
        WinSelfSid = 16,
        WinAuthenticatedUserSid = 17,
        WinRestrictedCodeSid = 18,
        WinTerminalServerSid = 19,
        WinRemoteLogonIdSid = 20,
        WinLogonIdsSid = 21,
        WinLocalSystemSid = 22,
        WinLocalServiceSid = 23,
        WinNetworkServiceSid = 24,
        WinBuiltinDomainSid = 25,
        WinBuiltinAdministratorsSid = 26,
        WinBuiltinUsersSid = 27,
        WinBuiltinGuestsSid = 28,
        WinBuiltinPowerUsersSid = 29,
        WinBuiltinAccountOperatorsSid = 30,
        WinBuiltinSystemOperatorsSid = 31,
        WinBuiltinPrintOperatorsSid = 32,
        WinBuiltinBackupOperatorsSid = 33,
        WinBuiltinReplicatorSid = 34,
        WinBuiltinPreWindows2000CompatibleAccessSid = 35,
        WinBuiltinRemoteDesktopUsersSid = 36,
        WinBuiltinNetworkConfigurationOperatorsSid = 37,
        WinAccountAdministratorSid = 38,
        WinAccountGuestSid = 39,
        WinAccountKrbtgtSid = 40,
        WinAccountDomainAdminsSid = 41,
        WinAccountDomainUsersSid = 42,
        WinAccountDomainGuestsSid = 43,
        WinAccountComputersSid = 44,
        WinAccountControllersSid = 45,
        WinAccountCertAdminsSid = 46,
        WinAccountSchemaAdminsSid = 47,
        WinAccountEnterpriseAdminsSid = 48,
        WinAccountPolicyAdminsSid = 49,
        WinAccountRasAndIasServersSid = 50,
        WinNTLMAuthenticationSid = 51,
        WinDigestAuthenticationSid = 52,
        WinSChannelAuthenticationSid = 53,
        WinThisOrganizationSid = 54,
        WinOtherOrganizationSid = 55,
        WinBuiltinIncomingForestTrustBuildersSid = 56,
        WinBuiltinPerfMonitoringUsersSid = 57,
        WinBuiltinPerfLoggingUsersSid = 58,
        WinBuiltinAuthorizationAccessSid = 59,
        WinBuiltinTerminalServerLicenseServersSid = 60,
        WinBuiltinDCOMUsersSid = 61,
        WinBuiltinIUsersSid = 62,
        WinIUserSid = 63,
        WinBuiltinCryptoOperatorsSid = 64,
        WinUntrustedLabelSid = 65,
        WinLowLabelSid = 66,
        WinMediumLabelSid = 67,
        WinHighLabelSid = 68,
        WinSystemLabelSid = 69,
        WinWriteRestrictedCodeSid = 70,
        WinCreatorOwnerRightsSid = 71,
        WinCacheablePrincipalsGroupSid = 72,
        WinNonCacheablePrincipalsGroupSid = 73,
        WinEnterpriseReadonlyControllersSid = 74,
        WinAccountReadonlyControllersSid = 75,
        WinBuiltinEventLogReadersGroup = 76,
        WinNewEnterpriseReadonlyControllersSid = 77,
        WinBuiltinCertSvcDComAccessGroup = 78,
        WinMediumPlusLabelSid = 79,
        WinLocalLogonSid = 80,
        WinConsoleLogonSid = 81,
        WinThisOrganizationCertificateSid = 82,
        WinApplicationPackageAuthoritySid = 83,
        WinBuiltinAnyPackageSid = 84,
        WinCapabilityInternetClientSid = 85,
        WinCapabilityInternetClientServerSid = 86,
        WinCapabilityPrivateNetworkClientServerSid = 87,
        WinCapabilityPicturesLibrarySid = 88,
        WinCapabilityVideosLibrarySid = 89,
        WinCapabilityMusicLibrarySid = 90,
        WinCapabilityDocumentsLibrarySid = 91,
        WinCapabilitySharedUserCertificatesSid = 92,
        WinCapabilityEnterpriseAuthenticationSid = 93,
        WinCapabilityRemovableStorageSid = 94,
        WinBuiltinRDSRemoteAccessServersSid = 95,
        WinBuiltinRDSEndpointServersSid = 96,
        WinBuiltinRDSManagementServersSid = 97,
        WinUserModeDriversSid = 98,
        WinBuiltinHyperVAdminsSid = 99,
        WinAccountCloneableControllersSid = 100,
        WinBuiltinAccessControlAssistanceOperatorsSid = 101,
        WinBuiltinRemoteManagementUsersSid = 102,
        WinAuthenticationAuthorityAssertedSid = 103,
        WinAuthenticationServiceAssertedSid = 104,
        WinLocalAccountSid = 105,
        WinLocalAccountAndAdministratorSid = 106,
        WinAccountProtectedUsersSid = 107,
    };

    constexpr WindowsDWord gSecuritySidSubAuthorities{ 15 };
    constexpr WindowsDWord gSecurityMaxSidSize{ (sizeof(SecuritySID) - sizeof(WindowsDWord) + (gSecuritySidSubAuthorities * sizeof(WindowsDWord))) };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_SECURITY_SECURITY_SID_USING_H