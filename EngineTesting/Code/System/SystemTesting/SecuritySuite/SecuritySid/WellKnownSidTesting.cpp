///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/01/29 21:33)

#include "WellKnownSidTesting.h"
#include "System/Security/SecuritySid.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>

System::WellKnownSidTesting::WellKnownSidTesting(const OStreamShared& stream)
    : ParentType{ stream },
      securityWellKnownSidTypes{ WinNullSid,
                                 WinWorldSid,
                                 WinLocalSid,
                                 WinCreatorOwnerSid,
                                 WinCreatorGroupSid,
                                 WinCreatorOwnerServerSid,
                                 WinCreatorGroupServerSid,
                                 WinNtAuthoritySid,
                                 WinDialupSid,
                                 WinNetworkSid,
                                 WinBatchSid,
                                 WinInteractiveSid,
                                 WinServiceSid,
                                 WinAnonymousSid,
                                 WinProxySid,
                                 WinEnterpriseControllersSid,
                                 WinSelfSid,
                                 WinAuthenticatedUserSid,
                                 WinRestrictedCodeSid,
                                 WinTerminalServerSid,
                                 WinRemoteLogonIdSid,
                                 WinLocalSystemSid,
                                 WinLocalServiceSid,
                                 WinNetworkServiceSid,
                                 WinBuiltinDomainSid,
                                 WinBuiltinAdministratorsSid,
                                 WinBuiltinUsersSid,
                                 WinBuiltinGuestsSid,
                                 WinBuiltinPowerUsersSid,
                                 WinBuiltinAccountOperatorsSid,
                                 WinBuiltinSystemOperatorsSid,
                                 WinBuiltinPrintOperatorsSid,
                                 WinBuiltinBackupOperatorsSid,
                                 WinBuiltinReplicatorSid,
                                 WinBuiltinPreWindows2000CompatibleAccessSid,
                                 WinBuiltinRemoteDesktopUsersSid,
                                 WinBuiltinNetworkConfigurationOperatorsSid,
                                 WinNTLMAuthenticationSid,
                                 WinDigestAuthenticationSid,
                                 WinSChannelAuthenticationSid,
                                 WinThisOrganizationSid,
                                 WinOtherOrganizationSid,
                                 WinBuiltinIncomingForestTrustBuildersSid,
                                 WinBuiltinPerfMonitoringUsersSid,
                                 WinBuiltinPerfLoggingUsersSid,
                                 WinBuiltinAuthorizationAccessSid,
                                 WinBuiltinTerminalServerLicenseServersSid,
                                 WinBuiltinDCOMUsersSid,
                                 WinBuiltinIUsersSid,
                                 WinIUserSid,
                                 WinBuiltinCryptoOperatorsSid,
                                 WinUntrustedLabelSid,
                                 WinLowLabelSid,
                                 WinMediumLabelSid,
                                 WinHighLabelSid,
                                 WinSystemLabelSid,
                                 WinWriteRestrictedCodeSid,
                                 WinCreatorOwnerRightsSid,
                                 WinEnterpriseReadonlyControllersSid,
                                 WinBuiltinEventLogReadersGroup,
                                 WinBuiltinCertSvcDComAccessGroup,
                                 WinMediumPlusLabelSid,
                                 WinConsoleLogonSid,
                                 WinThisOrganizationCertificateSid }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, WellKnownSidTesting)

void System::WellKnownSidTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::WellKnownSidTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateWellKnownSecurityIdentifierTest);
}

void System::WellKnownSidTesting::CreateWellKnownSecurityIdentifierTest()
{
    for (auto securityWellKnownSidType : securityWellKnownSidTypes)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoCreateWellKnownSecurityIdentifierTest, securityWellKnownSidType);
    }
}

void System::WellKnownSidTesting::DoCreateWellKnownSecurityIdentifierTest(SecurityWellKnownSidType securityWellKnownSidType)
{
    BufferType buffer{};
    auto sidCount = securityMaxSidSize;
    ASSERT_TRUE(CreateWellKnownSecurityIdentifier(securityWellKnownSidType, nullptr, buffer.data(), &sidCount));

    ASSERT_TRUE(IsWellKnownSecurityIdentifier(buffer.data(), securityWellKnownSidType));
}
