///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/06 15:21)

#include "Framework/FrameworkExport.h"

#include "MainFunctionHelperBase.h"
#include "Flags/Directory.h"
#include "Flags/MainFunctionSchedule.h"
#include "Detail/DirectoryDefaultName.h"
#include "Detail/MainFunctionHelperBaseImpl.h"
#include "CoreTools/Base/Flags/UniqueIdSelect.h"
#include "CoreTools/Base/UniqueIDManagerDetail.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/FileManager/Environment.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/InitTerm.h"

#include <iostream>

using std::make_shared;
using std::move;
using namespace std::literals;

Framework::MainFunctionHelperBase::MainFunctionHelperBase(const EnvironmentDirectory& environmentDirectory)
    : impl{}, mainFunctionSchedule{ MainFunctionSchedule::Failure }
{
    MainFunctionHelperInit(environmentDirectory);

    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::MainFunctionHelperBase::MainFunctionHelperBase(MainFunctionHelperBase&& rhs) noexcept
    : impl{ move(rhs.impl) }, mainFunctionSchedule{ rhs.mainFunctionSchedule }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::MainFunctionHelperBase& Framework::MainFunctionHelperBase::operator=(MainFunctionHelperBase&& rhs) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    impl = move(rhs.impl);
    mainFunctionSchedule = rhs.mainFunctionSchedule;

    return *this;
}

Framework::MainFunctionHelperBase::~MainFunctionHelperBase() noexcept
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;

    CoreTools::NoexceptNoReturn(*this, &ClassType::Destroy);
}

#ifdef OPEN_CLASS_INVARIANT

bool Framework::MainFunctionHelperBase::IsValid() const noexcept
{
    if ((mainFunctionSchedule == MainFunctionSchedule::Max) ^ (impl == nullptr))
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

System::String Framework::MainFunctionHelperBase::GetEngineInstallationDirectory() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    if (impl != nullptr)
        return impl->GetEngineInstallationDirectory();
    else
        return DirectoryDefaultName::GetDefaultNullName();
}

void Framework::MainFunctionHelperBase::Destroy()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (MainFunctionSchedule::Failure < mainFunctionSchedule)
    {
        MainFunctionHelperDestroy();
    }
}

int Framework::MainFunctionHelperBase::Run()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    EXCEPTION_TRY
    {
        if (impl != nullptr)
        {
            return DoRun();
        }
    }
    EXCEPTION_ALL_CATCH(Framework)

    return -1;
}

// private
void Framework::MainFunctionHelperBase::MainFunctionHelperInit(const EnvironmentDirectory& environmentDirectory)
{
    EXCEPTION_TRY
    {
        DoMainFunctionHelperInit(environmentDirectory);
    }
    EXCEPTION_ENTRY_POINT_CATCH
}

// private
void Framework::MainFunctionHelperBase::DoMainFunctionHelperInit(const EnvironmentDirectory& environmentDirectory)
{
    InitUniqueIDManager();
    InitLog(environmentDirectory);
    InitInitTerm();
    InitEnvironment();
    InitImpl(environmentDirectory);
}

// private
void Framework::MainFunctionHelperBase::InitUniqueIDManager()
{
    CoreTools::UniqueIdManager::Create(CoreTools::UniqueIdSelect::Max);
    mainFunctionSchedule = MainFunctionSchedule::UniqueID;
}

void Framework::MainFunctionHelperBase::InitLog(const EnvironmentDirectory& environmentDirectory)
{
    CoreTools::Log::Create();
    auto logFileName = environmentDirectory.GetDirectory(UpperDirectory::Configuration) + SYSTEM_TEXT("Log.json"s);
    LOG_SINGLETON.LoadConfiguration(CoreTools::StringConversion::StandardConversionMultiByte(logFileName));
    mainFunctionSchedule = MainFunctionSchedule::Log;
}

void Framework::MainFunctionHelperBase::InitInitTerm()
{
    CoreTools::InitTerm::ExecuteInitializer();
    mainFunctionSchedule = MainFunctionSchedule::InitTerm;
}

void Framework::MainFunctionHelperBase::InitEnvironment()
{
    CoreTools::Environment::Create();
    mainFunctionSchedule = MainFunctionSchedule::Environment;
}

void Framework::MainFunctionHelperBase::InitImpl(const EnvironmentDirectory& environmentDirectory)
{
    impl = make_shared<ImplType>(environmentDirectory);
    mainFunctionSchedule = MainFunctionSchedule::Max;
}

// private
void Framework::MainFunctionHelperBase::MainFunctionHelperDestroy()
{
    DestroyImpl();
    DestroyEnvironment();
    DestroyInitTerm();
    DestroyLog();
    DestroyUniqueIDManager();
}

void Framework::MainFunctionHelperBase::DestroyImpl() noexcept
{
    if (MainFunctionSchedule::Max <= mainFunctionSchedule)
    {
        impl.reset();
        mainFunctionSchedule = MainFunctionSchedule::Environment;
    }
}

void Framework::MainFunctionHelperBase::DestroyEnvironment() noexcept
{
    if (MainFunctionSchedule::Environment <= mainFunctionSchedule)
    {
        CoreTools::Environment::Destroy();
        mainFunctionSchedule = MainFunctionSchedule::InitTerm;
    }
}

void Framework::MainFunctionHelperBase::DestroyInitTerm()
{
    if (MainFunctionSchedule::InitTerm <= mainFunctionSchedule)
    {
        CoreTools::InitTerm::ExecuteTerminator();
        mainFunctionSchedule = MainFunctionSchedule::Log;
    }
}

void Framework::MainFunctionHelperBase::DestroyLog() noexcept
{
    if (MainFunctionSchedule::Log <= mainFunctionSchedule)
    {
        CoreTools::Log::Destroy();
        mainFunctionSchedule = MainFunctionSchedule::UniqueID;
    }
}

void Framework::MainFunctionHelperBase::DestroyUniqueIDManager() noexcept
{
    if (MainFunctionSchedule::UniqueID <= mainFunctionSchedule)
    {
        CoreTools::UniqueIdManager::Destroy();
        mainFunctionSchedule = MainFunctionSchedule::Failure;
    }
}

// protected
bool Framework::MainFunctionHelperBase::IsDestroy() const noexcept
{
    return (MainFunctionSchedule::Failure == mainFunctionSchedule);
}

// protected
Framework::EnvironmentDirectory Framework::MainFunctionHelperBase::GetEnvironmentDirectory() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    if (impl != nullptr)
    {
        return impl->GetEnvironmentDirectory();
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("获取环境目录失败！"s));
    }
}
