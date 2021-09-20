///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.2 (2021/03/31 20:12)

#include "SoftwareExceptionTesting.h"
#include "System/CharacterString/FormatErrorMessage.h"
#include "System/Windows/Flags/PlatformErrorFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using std::max;
using std::uniform_int;

System::SoftwareExceptionTesting::SoftwareExceptionTesting(const OStreamShared& stream)
    : ParentType{ stream },
      severityFlags{ Severity::Success, Severity::Informational, Severity::Warning, Severity::Error },
      facilityFlags{ Facility::Xps,
                     Facility::Winrm,
                     Facility::WindowSupdate,
                     Facility::WindowsDefender,
                     Facility::WindowsCE,
                     Facility::Windows,
                     Facility::UsermodeVolmgr,
                     Facility::UsermodeVirtualization,
                     Facility::UsermodeVhd,
                     Facility::Urt,
                     Facility::Umi,
                     Facility::UI,
                     Facility::TpmSoftware,
                     Facility::TpmServices,
                     Facility::Sxs,
                     Facility::Storage,
                     Facility::StateManagement,
                     Facility::Sspi,
                     Facility::Scard,
                     Facility::Shell,
                     Facility::Setupapi,
                     Facility::Security,
                     Facility::Sdiag,
                     Facility::Rpc,
                     Facility::Ras,
                     Facility::Pla,
                     Facility::Opc,
                     Facility::Win32,
                     Facility::Control,
                     Facility::Webservices,
                     Facility::Null,
                     Facility::Ndis,
                     Facility::Metadirectory,
                     Facility::Msmq,
                     Facility::Mediaserver,
                     Facility::Mbn,
                     Facility::Internet,
                     Facility::Itf,
                     Facility::UsermodeHypervisor,
                     Facility::Http,
                     Facility::Graphics,
                     Facility::Fwp,
                     Facility::Fve,
                     Facility::UsermodeFilterManager,
                     Facility::Dplay,
                     Facility::Dispatch,
                     Facility::Directoryservice,
                     Facility::Configuration,
                     Facility::Complus,
                     Facility::UsermodeCommonlog,
                     Facility::Cmi,
                     Facility::Cert,
                     Facility::Bcd,
                     Facility::Backgroundcopy,
                     Facility::Acs,
                     Facility::Aaf },
      maxSize{ max(severityFlags.size(), facilityFlags.size()) },
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
    shuffle(severityFlags.begin(), severityFlags.end(), randomEngine);
    shuffle(facilityFlags.begin(), facilityFlags.end(), randomEngine);

    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(MakeSoftwareExceptionTest);
}

bool System::SoftwareExceptionTesting::MakeSoftwareExceptionTest()
{
    constexpr auto facilityShift = 16u;
    constexpr auto severityShift = 30u;
    constexpr auto exceptionBit = (1u << facilityShift) - 1u;
    constexpr auto facilityBit = 0x0FFF0000u;
    const std::uniform_int<uint32_t> randomDistribution{ 0u, exceptionBit };

    for (auto index = 0u; index < maxSize; ++index)
    {
        auto severityFlag = severityFlags.at(index % severityFlags.size());
        auto facilityFlag = facilityFlags.at(index % facilityFlags.size());

        auto exceptionFlag = randomDistribution(randomEngine);

        const auto softwareException = MakeSoftwareException(severityFlag, facilityFlag, exceptionFlag);

        ASSERT_ENUM_EQUAL(UnderlyingCastEnum<Severity>(softwareException >> severityShift), severityFlag);
        ASSERT_ENUM_EQUAL(UnderlyingCastEnum<Facility>((softwareException & facilityBit) >> facilityShift), facilityFlag);
        ASSERT_EQUAL(softwareException & exceptionBit, exceptionFlag);
    }

    return true;
}
