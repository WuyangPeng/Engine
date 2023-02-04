///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.4 (2022/11/26 20:33)

#include "SoftwareExceptionTesting.h"
#include "System/CharacterString/FormatErrorMessage.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Windows/Flags/PlatformErrorFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::SoftwareExceptionTesting::SoftwareExceptionTesting(const OStreamShared& stream)
    : ParentType{ stream },
      severities{ Severity::Success,
                  Severity::Informational,
                  Severity::Warning,
                  Severity::Error },
      facilities{ Facility::Null,
                  Facility::Rpc,
                  Facility::Dispatch,
                  Facility::Storage,
                  Facility::Itf,
                  Facility::Win32,
                  Facility::Windows,
                  Facility::Sspi,
                  Facility::Security,
                  Facility::Control,
                  Facility::Cert,
                  Facility::Internet,
                  Facility::MediaServer,
                  Facility::Msmq,
                  Facility::SetupApi,
                  Facility::Scard,
                  Facility::Complus,
                  Facility::Aaf,
                  Facility::Urt,
                  Facility::Acs,
                  Facility::Dplay,
                  Facility::Umi,
                  Facility::Sxs,
                  Facility::WindowsCE,
                  Facility::Http,
                  Facility::UserModeCommonLog,
                  Facility::Wer,
                  Facility::UserModeFilterManager,
                  Facility::BackGroundCopy,
                  Facility::Configuration,
                  Facility::Wia,
                  Facility::StateManagement,
                  Facility::MetaDirectory,
                  Facility::WindowsUpdate,
                  Facility::DirectoryService,
                  Facility::Graphics,
                  Facility::Shell,
                  Facility::Nap,
                  Facility::TpmServices,
                  Facility::TpmSoftware,
                  Facility::Ui,
                  Facility::Xaml,
                  Facility::ActionQueue,
                  Facility::Pla,
                  Facility::WindowsSetup,
                  Facility::Fve,
                  Facility::Fwp,
                  Facility::Winrm,
                  Facility::Ndis,
                  Facility::UserModeHypervisor,
                  Facility::Cmi,
                  Facility::UserModeVirtualization,
                  Facility::UserModeVolmgr,
                  Facility::Bcd,
                  Facility::UserModeVhd,
                  Facility::UserModeHns,
                  Facility::Sdiag,
                  Facility::WebServices,
                  Facility::Winpe,
                  Facility::Wpn,
                  Facility::WindowsStore,
                  Facility::Input,
                  Facility::Quic,
                  Facility::Eap,
                  Facility::WindowsDefender,
                  Facility::Opc,
                  Facility::Xps,
                  Facility::Mbn,
                  Facility::PowerShell,
                  Facility::Ras,
                  Facility::P2pInt,
                  Facility::P2p,
                  Facility::Daf,
                  Facility::BluetoothAtt,
                  Facility::Audio,
                  Facility::StateRepository,
                  Facility::VisualCpp,
                  Facility::Script,
                  Facility::Parse,
                  Facility::Blb,
                  Facility::BlbCli,
                  Facility::Wsbapp,
                  Facility::Blbui,
                  Facility::Usn,
                  Facility::UserModeVolsnap,
                  Facility::Tiering,
                  Facility::WsbOnline,
                  Facility::OnlineID,
                  Facility::DeviceUpdateAgent,
                  Facility::Drvservicing,
                  Facility::Dls,
                  Facility::DeliveryOptimization,
                  Facility::UserModeSpaces,
                  Facility::UserModeSecurityCore,
                  Facility::UserModeLicensing,
                  Facility::Sos,
                  Facility::Debuggers,
                  Facility::Spp,
                  Facility::Restore,
                  Facility::Dmserver,
                  Facility::DeploymentServicesServer,
                  Facility::DeploymentServicesImaging,
                  Facility::DeploymentServicesManagement,
                  Facility::DeploymentServicesUtil,
                  Facility::DeploymentServicesBinlsvc,
                  Facility::DeploymentServicesPxe,
                  Facility::DeploymentServicesTftp,
                  Facility::DeploymentServicesTransportManagement,
                  Facility::DeploymentServicesDriverProvisioning,
                  Facility::DeploymentServicesMulticAstServer,
                  Facility::DeploymentServicesMulticAstClient,
                  Facility::DeploymentServicesContentProvider,
                  Facility::LinguisticServices,
                  Facility::AudioStreaming,
                  Facility::Ttd,
                  Facility::Accelerator,
                  Facility::Wmaaecma,
                  Facility::DirectMusic,
                  Facility::Direct3D10,
                  Facility::Dxgi,
                  Facility::DxgiDdi,
                  Facility::Direct3D11,
                  Facility::Direct3D11Debug,
                  Facility::Direct3D12,
                  Facility::Direct3D12Debug,
                  Facility::Dxcore,
                  Facility::Leap,
                  Facility::Audclnt,
                  Facility::WincodecDwriteDwm,
                  Facility::Winml,
                  Facility::Direct2D,
                  Facility::Defrag,
                  Facility::UsermodeSdbus,
                  Facility::Jscript,
                  Facility::Pidgenx,
                  Facility::Eas,
                  Facility::Web,
                  Facility::WebSocket,
                  Facility::Mobile,
                  Facility::Sqlite,
                  Facility::Utc,
                  Facility::Wep,
                  Facility::Syncengine,
                  Facility::Xbox,
                  Facility::Game,
                  Facility::Pix },
      maxSize{ std::max(severities.size(), facilities.size()) },
      randomEngine{ GetEngineRandomSeed() }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, SoftwareExceptionTesting)

void System::SoftwareExceptionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::SoftwareExceptionTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MakeSoftwareExceptionTest);
}

void System::SoftwareExceptionTesting::RandomShuffleFlags()
{
    shuffle(severities.begin(), severities.end(), randomEngine);
    shuffle(facilities.begin(), facilities.end(), randomEngine);

    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(MakeSoftwareExceptionTest);
}

bool System::SoftwareExceptionTesting::MakeSoftwareExceptionTest()
{
    for (auto index = 0u; index < maxSize; ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoMakeSoftwareExceptionTest, index);
    }

    return true;
}

void System::SoftwareExceptionTesting::DoMakeSoftwareExceptionTest(size_t index)
{
    const std::uniform_int<uint32_t> randomDistribution{ 0u, exceptionBit };

    const auto severity = severities.at(index % severities.size());
    const auto facility = facilities.at(index % facilities.size());

    const auto exception = randomDistribution(randomEngine);

    const auto softwareException = MakeSoftwareException(severity, facility, exception);

    ASSERT_ENUM_EQUAL(UnderlyingCastEnum<Severity>(softwareException >> severityShift), severity);
    ASSERT_ENUM_EQUAL(UnderlyingCastEnum<Facility>((softwareException & facilityBit) >> facilityShift), facility);
    ASSERT_EQUAL(softwareException & exceptionBit, exception);
}
