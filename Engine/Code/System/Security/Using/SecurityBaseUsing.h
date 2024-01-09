/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 16:27)

#ifndef SYSTEM_SECURITY_SECURITY_BASE_USING_H
#define SYSTEM_SECURITY_SECURITY_BASE_USING_H

#include "AccessCheckUsing.h"
#include "SecurityAclUsing.h"
#include "SecuritySidUsing.h"
#include "System/Helper/Platform.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using SecurityImpersonationLevel = SECURITY_IMPERSONATION_LEVEL;
    using SecurityImpersonationLevelPtr = PSECURITY_IMPERSONATION_LEVEL;
    using WindowSecurityAttributes = SECURITY_ATTRIBUTES;
    using WindowSecurityAttributesPtr = LPSECURITY_ATTRIBUTES;
    using SecuritySidAndAttributes = SID_AND_ATTRIBUTES;
    using SecuritySidAndAttributesPtr = PSID_AND_ATTRIBUTES;
    using SecurityTokenType = TOKEN_TYPE;
    using SecurityTokenTypePtr = PTOKEN_TYPE;
    using TokenInformationClass = TOKEN_INFORMATION_CLASS;
    using SecurityTokenUser = TOKEN_USER;
    using SecurityTokenUserPtr = PTOKEN_USER;
    using SecurityTokenGroups = TOKEN_GROUPS;
    using SecurityTokenGroupsPtr = PTOKEN_GROUPS;
    using SecurityTokenPrivileges = TOKEN_PRIVILEGES;
    using SecurityTokenPrivilegesPtr = PTOKEN_PRIVILEGES;
    using SecurityTokenElevation = TOKEN_ELEVATION;
    using SecurityTokenElevationPtr = PTOKEN_ELEVATION;
    using SecurityTokenOwner = TOKEN_OWNER;
    using SecurityTokenOwnerPtr = PTOKEN_OWNER;
    using SecurityTokenPrimaryGroup = TOKEN_PRIMARY_GROUP;
    using SecurityTokenPrimaryGroupPtr = PTOKEN_PRIMARY_GROUP;
    using SecurityTokenDefaultDacl = TOKEN_DEFAULT_DACL;
    using SecurityTokenDefaultDaclPtr = PTOKEN_DEFAULT_DACL;
    using SecurityTokenGroupsAndPrivileges = TOKEN_GROUPS_AND_PRIVILEGES;
    using SecurityTokenGroupsAndPrivilegesPtr = PTOKEN_GROUPS_AND_PRIVILEGES;
    using SecurityTokenLinkedToken = TOKEN_LINKED_TOKEN;
    using SecurityTokenLinkedTokenPtr = PTOKEN_LINKED_TOKEN;
    using SecurityTokenMandatoryLabel = TOKEN_MANDATORY_LABEL;
    using SecurityTokenMandatoryLabelPtr = PTOKEN_MANDATORY_LABEL;
    using SecurityTokenMandatoryPolicy = TOKEN_MANDATORY_POLICY;
    using SecurityTokenMandatoryPolicyPtr = PTOKEN_MANDATORY_POLICY;
    using SecurityTokenAccessInformation = TOKEN_ACCESS_INFORMATION;
    using SecurityTokenAccessInformationPtr = PTOKEN_ACCESS_INFORMATION;
    using SecuritySidAndAttributesHash = SID_AND_ATTRIBUTES_HASH;
    using SecuritySidAndAttributesHashPtr = PSID_AND_ATTRIBUTES_HASH;
    using SecuritySidHashEntry = SID_HASH_ENTRY;
    using SecurityTokenAuditPolicy = TOKEN_AUDIT_POLICY;
    using SecurityTokenAuditPolicyPtr = PTOKEN_AUDIT_POLICY;
    constexpr WindowsDWord tokenSourceLength{ TOKEN_SOURCE_LENGTH };
    using SecurityTokenSource = TOKEN_SOURCE;
    using SecurityTokenSourcePtr = PTOKEN_SOURCE;
    using SecurityTokenStatistics = TOKEN_STATISTICS;
    using SecurityTokenStatisticsPtr = PTOKEN_STATISTICS;
    using SecurityTokenControl = TOKEN_CONTROL;
    using SecurityTokenControlPtr = PTOKEN_CONTROL;
    using SecurityTokenOrigin = TOKEN_ORIGIN;
    using SecurityTokenOriginPtr = PTOKEN_ORIGIN;
    using SecurityTokenElevationType = TOKEN_ELEVATION_TYPE;
    using SecurityTokenElevationTypePtr = PTOKEN_ELEVATION_TYPE;
    using SecurityTokenAppContainerInformation = TOKEN_APPCONTAINER_INFORMATION;
    using SecurityTokenAppContainerInformationPtr = PTOKEN_APPCONTAINER_INFORMATION;

#else  // !WIN32

    enum SecurityImpersonationLevel
    {
        SecurityAnonymous,
        SecurityIdentification,
        SecurityImpersonation,
        SecurityDelegation
    };
    using SecurityImpersonationLevelPtr = SecurityImpersonationLevel*;

    struct WindowSecurityAttributes
    {
        WindowsDWord nLength;
        void* lpSecurityDescriptor;
        WindowsBool bInheritHandle;
    };
    using WindowSecurityAttributesPtr = WindowSecurityAttributes*;

    struct SecuritySidAndAttributes
    {
        SecuritySidPtr Sid;
        uint32_t Attributes;
    };
    using SecuritySidAndAttributesPtr = SecuritySidAndAttributes*;

    enum SecurityTokenType
    {
        TokenPrimary = 1,
        TokenImpersonation
    };
    using SecurityTokenTypePtr = SecurityTokenType*;

    enum TokenInformationClass
    {
        TokenUser = 1,
        TokenGroups,
        TokenPrivileges,
        TokenOwner,
        TokenPrimaryGroup,
        TokenDefaultDacl,
        TokenSource,
        TokenType,
        TokenImpersonationLevel,
        TokenStatistics,
        TokenRestrictedSids,
        TokenSessionId,
        TokenGroupsAndPrivileges,
        TokenSessionReference,
        TokenSandBoxInert,
        TokenAuditPolicy,
        TokenOrigin,
        TokenElevationType,
        TokenLinkedToken,
        TokenElevation,
        TokenHasRestrictions,
        TokenAccessInformation,
        TokenVirtualizationAllowed,
        TokenVirtualizationEnabled,
        TokenIntegrityLevel,
        TokenUIAccess,
        TokenMandatoryPolicy,
        TokenLogonSid,
        TokenIsAppContainer,
        TokenCapabilities,
        TokenAppContainerSid,
        TokenAppContainerNumber,
        TokenUserClaimAttributes,
        TokenDeviceClaimAttributes,
        TokenRestrictedUserClaimAttributes,
        TokenRestrictedDeviceClaimAttributes,
        TokenDeviceGroups,
        TokenRestrictedDeviceGroups,
        TokenSecurityAttributes,
        TokenIsRestricted,
        TokenProcessTrustLevel,
        MaxTokenInfoClass
    };

    struct SecurityTokenUser
    {
        SecuritySidAndAttributes User;
    };
    using SecurityTokenUserPtr = SecurityTokenUser*;

    struct SecurityTokenGroups
    {
        uint32_t GroupCount;
        SecuritySidAndAttributes Groups[1];
    };
    using SecurityTokenGroupsPtr = SecurityTokenGroups*;

    struct SecurityTokenPrivileges
    {
        uint32_t PrivilegeCount;
        LuidAndAttributes Privileges[1];
    };
    using SecurityTokenPrivilegesPtr = SecurityTokenPrivileges*;

    struct SecurityTokenOwner
    {
        SecuritySidPtr Owner;
    };
    using SecurityTokenOwnerPtr = SecurityTokenOwner*;

    struct SecurityTokenPrimaryGroup
    {
        SecuritySidPtr PrimaryGroup;
    };
    using SecurityTokenPrimaryGroupPtr = SecurityTokenPrimaryGroup*;

    struct SecurityTokenDefaultDacl
    {
        AccessCheckAclPtr DefaultDacl;
    };
    using SecurityTokenDefaultDaclPtr = SecurityTokenDefaultDacl*;

    struct SecurityTokenGroupsAndPrivileges
    {
        uint32_t SidCount;
        uint32_t SidLength;
        SecuritySidAndAttributesPtr Sids;
        uint32_t RestrictedSidCount;
        uint32_t RestrictedSidLength;
        SecuritySidAndAttributesPtr RestrictedSids;
        uint32_t PrivilegeCount;
        uint32_t PrivilegeLength;
        LuidAndAttributesPtr Privileges;
        LookupPrivilegeLuid AuthenticationId;
    };
    using SecurityTokenGroupsAndPrivilegesPtr = SecurityTokenGroupsAndPrivileges*;

    struct SecurityTokenLinkedToken
    {
        WindowsHandle LinkedToken;
    };
    using SecurityTokenLinkedTokenPtr = SecurityTokenLinkedToken*;

    struct SecurityTokenElevation
    {
        uint32_t TokenIsElevated;
    };
    using SecurityTokenElevationPtr = SecurityTokenElevation*;

    struct SecurityTokenMandatoryLabel
    {
        SecuritySidAndAttributes Label;
    };
    using SecurityTokenMandatoryLabelPtr = SecurityTokenMandatoryLabel*;

    struct SecurityTokenMandatoryPolicy
    {
        uint32_t Policy;
    };
    using SecurityTokenMandatoryPolicyPtr = SecurityTokenMandatoryPolicy*;

    using SecuritySidHashEntry = uint64_t;
    struct SecuritySidAndAttributesHash
    {
        uint32_t SidCount;
        SecuritySidAndAttributesPtr SidAttr;
        SecuritySidHashEntry Hash[32];
    };
    using SecuritySidAndAttributesHashPtr = SecuritySidAndAttributesHash*;

    struct SecurityTokenAccessInformation
    {
        SecuritySidAndAttributesHash SidHash;
        SecuritySidAndAttributesHash RestrictedSidHash;
        SecurityTokenPrivilegesPtr Privileges;
        LookupPrivilegeLuid AuthenticationId;
        SecurityTokenType TokenType;
        SecurityImpersonationLevel ImpersonationLevel;
        SecurityTokenMandatoryPolicy MandatoryPolicy;
        uint32_t Flags;
        uint32_t AppContainerNumber;
        SecuritySidPtr PackageSid;
        SecuritySidAndAttributesHash CapabilitiesHash;
        SecuritySidPtr TrustLevelSid;
    };
    using SecurityTokenAccessInformationPtr = SecurityTokenAccessInformation*;

    struct SecurityTokenAuditPolicy
    {
        uint8_t PerUserPolicy[((56) >> 1) + 1];
    };
    using SecurityTokenAuditPolicyPtr = SecurityTokenAuditPolicy*;

    constexpr WindowsDWord tokenSourceLength{ 8 };

    struct SecurityTokenSource
    {
        char SourceName[tokenSourceLength];
        LookupPrivilegeLuid SourceIdentifier;
    };
    using SecurityTokenSourcePtr = SecurityTokenSource*;

    struct SecurityTokenStatistics
    {
        LookupPrivilegeLuid TokenId;
        LookupPrivilegeLuid AuthenticationId;
        WindowsLargeInteger ExpirationTime;
        SecurityTokenType TokenType;
        SecurityImpersonationLevel ImpersonationLevel;
        uint32_t DynamicCharged;
        uint32_t DynamicAvailable;
        uint32_t GroupCount;
        uint32_t PrivilegeCount;
        LookupPrivilegeLuid ModifiedId;
    };
    using SecurityTokenStatisticsPtr = SecurityTokenStatistics*;

    struct SecurityTokenControl
    {
        LookupPrivilegeLuid TokenId;
        LookupPrivilegeLuid AuthenticationId;
        LookupPrivilegeLuid ModifiedId;
        SecurityTokenSource TokenSource;
    };
    using SecurityTokenControlPtr = SecurityTokenControl*;

    struct SecurityTokenOrigin
    {
        LookupPrivilegeLuid OriginatingLogonSession;
    };
    using SecurityTokenOriginPtr = SecurityTokenOrigin*;

    enum SecurityTokenElevationType
    {
        TokenElevationTypeDefault = 1,
        TokenElevationTypeFull,
        TokenElevationTypeLimited,
    };
    using SecurityTokenElevationTypePtr = SecurityTokenElevationType*;

    struct SecurityTokenAppContainerInformation
    {
        SecuritySidPtr TokenAppContainer;
    };
    using SecurityTokenAppContainerInformationPtr = SecurityTokenAppContainerInformation*;

#endif  // WIN32
}

#endif  // SYSTEM_SECURITY_SECURITY_BASE_USING_H