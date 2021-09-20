///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.4 (2021/05/27 11:52)

#include "LookupPrivilegeTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Security/Flags/LookupPrivilegeNameFlags.h"
#include "System/Security/LookupPrivilege.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>

using std::array;

System::LookupPrivilegeTesting::LookupPrivilegeTesting(const OStreamShared& stream)
    : ParentType{ stream },
      lookupPrivilegeNameCollection{ GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::CreateTokenName),
                                     GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::AssignPrimaryToken),
                                     GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::LockMemoryName),
                                     GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::IncreaseQuotaName),
                                     GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::MachineAccountName),
                                     GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::TcbName),
                                     GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::SecurityName),
                                     GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::TakeOwnershipName),
                                     GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::LoadDriverName),
                                     GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::SystemProfileName),
                                     GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::SystemtimeName),
                                     GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::ProfileSingleProcessName),
                                     GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::IncreaseBasePriorityName),
                                     GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::CreatePagefileName),
                                     GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::CreatePermanentName),
                                     GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::BackupName),
                                     GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::RestoreName),
                                     GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::ShutdownName),
                                     GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::DebugName),
                                     GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::AuditName),
                                     GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::SystemEnvironmentName),
                                     GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::ChangeNotifyName),
                                     GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::RemoteShutdownName),
                                     GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::UndockName),
                                     GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::SyncAgentName),
                                     GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::EnableDelegationName),
                                     GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::ManageVolumeName),
                                     GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::ImpersonateName),
                                     GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::CreateGlobalName),
                                     GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::TrustedCredManAccessName),
                                     GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::RelabelName),
                                     GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::IncreaseWorkingSetName),
                                     GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::TimeZoneName),
                                     GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription::CreateSymbolicLinkName) }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, LookupPrivilegeTesting)

void System::LookupPrivilegeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::LookupPrivilegeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetLookupPrivilegeTest);
}

void System::LookupPrivilegeTesting::GetLookupPrivilegeTest()
{
    constexpr WindowsDWord bufferSize{ 256 };
    array<TChar, bufferSize> buffer{};

    for (const auto& lookupPrivilegeName : lookupPrivilegeNameCollection)
    {
        buffer.fill(TChar{ '\0' });

        LookupPrivilegeLUID uid{};

        ASSERT_TRUE(GetLookupPrivilegeValue(nullptr, lookupPrivilegeName.c_str(), &uid));

        ASSERT_LESS(0u, uid.LowPart);

        WindowsDWord size{ boost::numeric_cast<WindowsDWord>(buffer.size()) };
        ASSERT_TRUE(GetLookupPrivilegeName(nullptr, &uid, buffer.data(), &size));

        String resultLookupPrivilegeName{ buffer.data() };

        ASSERT_EQUAL(size, resultLookupPrivilegeName.size());
        ASSERT_EQUAL_DO_NOT_USE_MESSAGE(resultLookupPrivilegeName, lookupPrivilegeName);

        buffer.fill(TChar{ '\0' });

        WindowsDWord languageId{ 0 };

        ASSERT_TRUE(GetLookupPrivilegeDisplayName(nullptr, lookupPrivilegeName.c_str(), buffer.data(), &size, &languageId));

        String resultLookupPrivilegeDisplayName{ buffer.data() };

        ASSERT_EQUAL(size, resultLookupPrivilegeDisplayName.size());
    }
}