///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.4 (2021/05/31 22:34)

#include "WellKnownSidTesting.h"
#include "System/Security/SecuritySid.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>

using std::array;

System::WellKnownSidTesting::WellKnownSidTesting(const OStreamShared& stream)
    : ParentType{ stream },
      securityWellKnownSidType{ WinNullSid,
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
    array<WindowsDWord, g_SecurityMaxSidSize> buffer{};

    for (auto wellKnownSidType : securityWellKnownSidType)
    {
        buffer.fill(0);
        auto sidCount = g_SecurityMaxSidSize;
        ASSERT_TRUE(CreateWellKnownSecurityIdentifier(wellKnownSidType, nullptr, buffer.data(), &sidCount));

        ASSERT_TRUE(IsWellKnownSecurityIdentifier(buffer.data(), wellKnownSidType));
    }
}