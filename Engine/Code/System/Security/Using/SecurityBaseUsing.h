//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/24 15:22)

#ifndef SYSTEM_SECURITY_SECURITY_BASE_USING_H
#define SYSTEM_SECURITY_SECURITY_BASE_USING_H

#include "System/Helper/Platform.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

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
    constexpr WindowDWord g_TokenSourceLength{ TOKEN_SOURCE_LENGTH };
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
    using SecurityImpersonationLevel = SECURITY_IMPERSONATION_LEVEL;
    using SecurityImpersonationLevelPtr = PSECURITY_IMPERSONATION_LEVEL;

#else  // !WIN32

    struct WindowSecurityAttributes
    {
        WindowDWord nLength;
        void* lpSecurityDescriptor;
        WindowBool bInheritHandle;
    };
    using WindowSecurityAttributesPtr = WindowSecurityAttributes*;
    struct SecuritySidAndAttributes
    {
        SecuritySIDPtr Sid;
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
        LUIDAndAttributes Privileges[1];
    };
    using SecurityTokenPrivilegesPtr = SecurityTokenPrivileges*;

    struct SecurityTokenOwner
    {
        SecuritySIDPtr Owner;
    };
    using SecurityTokenOwnerPtr = SecurityTokenOwner*;

    struct SecurityTokenPrimaryGroup
    {
        SecuritySIDPtr PrimaryGroup;
    };
    using SecurityTokenPrimaryGroupPtr = SecurityTokenPrimaryGroup*;

    struct SecurityTokenDefaultDacl
    {
        AccessCheckACLPtr DefaultDacl;
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
        LUIDAndAttributesPtr Privileges;
        LookupPrivilegeLUID AuthenticationId;
    };
    using SecurityTokenGroupsAndPrivilegesPtr = SecurityTokenGroupsAndPrivileges*;

    struct SecurityTokenLinkedToken
    {
        WindowHandle LinkedToken;
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
        LookupPrivilegeLUID AuthenticationId;
        SecurityTokenType TokenType;
        SecurityImpersonationLevel ImpersonationLevel;
        SecurityTokenMandatoryPolicy MandatoryPolicy;
        uint32_t Flags;
        uint32_t AppContainerNumber;
        SecuritySIDPtr PackageSid;
        SecuritySidAndAttributesHash CapabilitiesHash;
        SecuritySIDPtr TrustLevelSid;
    };
    using SecurityTokenAccessInformationPtr = SecurityTokenAccessInformation*;

    struct SecurityTokenAuditPolicy
    {
        uint8_t PerUserPolicy[((56) >> 1) + 1];
    };
    using SecurityTokenAuditPolicyPtr = SecurityTokenAuditPolicy*;

    constexpr WindowDWord g_TokenSourceLength{ 8 };

    struct SecurityTokenSource
    {
        char SourceName[g_TokenSourceLength];
        LookupPrivilegeLUID SourceIdentifier;
    };
    using SecurityTokenSourcePtr = SecurityTokenSource*;

    struct SecurityTokenStatistics
    {
        LookupPrivilegeLUID TokenId;
        LookupPrivilegeLUID AuthenticationId;
        WindowLargeInteger ExpirationTime;
        SecurityTokenType TokenType;
        SecurityImpersonationLevel ImpersonationLevel;
        uint32_t DynamicCharged;
        uint32_t DynamicAvailable;
        uint32_t GroupCount;
        uint32_t PrivilegeCount;
        LookupPrivilegeLUID ModifiedId;
    };
    using SecurityTokenStatisticsPtr = SecurityTokenStatistics*;

    struct SecurityTokenControl
    {
        LookupPrivilegeLUID TokenId;
        LookupPrivilegeLUID AuthenticationId;
        LookupPrivilegeLUID ModifiedId;
        SecurityTokenSource TokenSource;
    };
    using SecurityTokenControlPtr = SecurityTokenControl*;

    struct SecurityTokenOrigin
    {
        LookupPrivilegeLUID OriginatingLogonSession;
    };
    using SecurityTokenOriginPtr = SecurityTokenOrigin*;

    enum SecurityTokenElevationType
    {
        TokenElevationTypeDefault = 1,
        TokenElevationTypeFull,
        TokenElevationTypeLimited,
    };
    using SecurityTokenElevationTypePtr = SecurityTokenElevationType*;
    enum SecurityImpersonationLevel
    {
        SecurityAnonymous,
        SecurityIdentification,
        SecurityImpersonation,
        SecurityDelegation
    };
    using SecurityImpersonationLevelPtr = SecurityImpersonationLevel*;

#endif  // WIN32
}

#endif  // SYSTEM_SECURITY_SECURITY_BASE_USING_H