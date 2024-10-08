/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 14:17)

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
                  Facility::MessageQueuing,
                  Facility::SetupApi,
                  Facility::SmartCard,
                  Facility::ComponentServices,
                  Facility::Aaf,
                  Facility::Urt,
                  Facility::Acs,
                  Facility::DirectPlay,
                  Facility::Umi,
                  Facility::Sxs,
                  Facility::WindowsCe,
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
                  Facility::WindowsRemoteManagement,
                  Facility::NetworkDriverInterfaceSpecification,
                  Facility::UserModeHypervisor,
                  Facility::Cmi,
                  Facility::UserModeVirtualization,
                  Facility::UserModeVolumeManager,
                  Facility::Bcd,
                  Facility::UserModeVhd,
                  Facility::UserModeHns,
                  Facility::SystemDiagnostics,
                  Facility::WebServices,
                  Facility::WinPe,
                  Facility::Wpn,
                  Facility::WindowsStore,
                  Facility::Input,
                  Facility::QuickUdpInternetConnections,
                  Facility::Eap,
                  Facility::WindowsDefender,
                  Facility::Opc,
                  Facility::Xps,
                  Facility::Mbn,
                  Facility::PowerShell,
                  Facility::Ras,
                  Facility::P2PInt,
                  Facility::P2P,
                  Facility::Daf,
                  Facility::BluetoothAttribute,
                  Facility::Audio,
                  Facility::StateRepository,
                  Facility::VisualCpp,
                  Facility::Script,
                  Facility::Parse,
                  Facility::Blb,
                  Facility::BlbCli,
                  Facility::WindowsServerBackupApplication,
                  Facility::BacklogUserInterface,
                  Facility::Usn,
                  Facility::UserModeVolumeShadowCopy,
                  Facility::Tiering,
                  Facility::WsbOnline,
                  Facility::OnlineId,
                  Facility::DeviceUpdateAgent,
                  Facility::DrvServicing,
                  Facility::Dls,
                  Facility::DeliveryOptimization,
                  Facility::UserModeSpaces,
                  Facility::UserModeSecurityCore,
                  Facility::UserModeLicensing,
                  Facility::Sos,
                  Facility::Debuggers,
                  Facility::Spp,
                  Facility::Restore,
                  Facility::DmServer,
                  Facility::DeploymentServicesServer,
                  Facility::DeploymentServicesImaging,
                  Facility::DeploymentServicesManagement,
                  Facility::DeploymentServicesUtil,
                  Facility::DeploymentServicesBootInformationNegotiationLayerService,
                  Facility::DeploymentServicesPxe,
                  Facility::DeploymentServicesTrivialFileTransferProtocol,
                  Facility::DeploymentServicesTransportManagement,
                  Facility::DeploymentServicesDriverProvisioning,
                  Facility::DeploymentServicesMulticastServer,
                  Facility::DeploymentServicesMulticastClient,
                  Facility::DeploymentServicesContentProvider,
                  Facility::LinguisticServices,
                  Facility::AudioStreaming,
                  Facility::Ttd,
                  Facility::Accelerator,
                  Facility::WindowsMediaAudioEncoderControlMessageArchitecture,
                  Facility::DirectMusic,
                  Facility::Direct3D10,
                  Facility::DirectXGraphicsInfrastructure,
                  Facility::DirectXGraphicsInfrastructureDdi,
                  Facility::Direct3D11,
                  Facility::Direct3D11Debug,
                  Facility::Direct3D12,
                  Facility::Direct3D12Debug,
                  Facility::DxCore,
                  Facility::Leap,
                  Facility::AudioClient,
                  Facility::WinCodecDirectWriteDwm,
                  Facility::WinMl,
                  Facility::Direct2D,
                  Facility::DeFrag,
                  Facility::UserModeSdBus,
                  Facility::JScript,
                  Facility::ProcessIdentificationGeneratorX,
                  Facility::Eas,
                  Facility::Web,
                  Facility::WebSocket,
                  Facility::Mobile,
                  Facility::SqLite,
                  Facility::Utc,
                  Facility::Wep,
                  Facility::SyncEngine,
                  Facility::XBox,
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
    std::ranges::shuffle(severities, randomEngine);
    std::ranges::shuffle(facilities, randomEngine);

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
    std::uniform_int_distribution randomDistribution{ 0u, exceptionBit };

    const auto severity = severities.at(index % severities.size());
    const auto facility = facilities.at(index % facilities.size());

    const auto exception = randomDistribution(randomEngine);

    const auto softwareException = MakeSoftwareException(severity, facility, exception);

    ASSERT_EQUAL(UnderlyingCastEnum<Severity>(softwareException >> severityShift), severity);
    ASSERT_EQUAL(UnderlyingCastEnum<Facility>((softwareException & facilityBit) >> facilityShift), facility);
    ASSERT_EQUAL(softwareException & exceptionBit, exception);
}
