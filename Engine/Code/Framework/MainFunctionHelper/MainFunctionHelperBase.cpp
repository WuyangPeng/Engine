/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:10)

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

Framework::MainFunctionHelperBase::MainFunctionHelperBase(const EnvironmentDirectory& environmentDirectory)
    : impl{}, mainFunctionSchedule{ MainFunctionSchedule::Failure }
{
    MainFunctionHelperInit(environmentDirectory);

    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::MainFunctionHelperBase::MainFunctionHelperBase(MainFunctionHelperBase&& rhs) noexcept
    : impl{ std::move(rhs.impl) }, mainFunctionSchedule{ rhs.mainFunctionSchedule }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::MainFunctionHelperBase& Framework::MainFunctionHelperBase::operator=(MainFunctionHelperBase&& rhs) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    impl = std::move(rhs.impl);
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

void Framework::MainFunctionHelperBase::MainFunctionHelperInit(const EnvironmentDirectory& environmentDirectory)
{
    EXCEPTION_TRY
    {
        DoMainFunctionHelperInit(environmentDirectory);
    }
    EXCEPTION_ENTRY_POINT_CATCH
}

void Framework::MainFunctionHelperBase::DoMainFunctionHelperInit(const EnvironmentDirectory& environmentDirectory)
{
    InitUniqueIdManager();
    InitLog(environmentDirectory);
    InitInitTerm();
    InitImpl(environmentDirectory);
}

void Framework::MainFunctionHelperBase::InitUniqueIdManager()
{
    CoreTools::UniqueIdManager::Create(CoreTools::UniqueIdSelect::Max);
    mainFunctionSchedule = MainFunctionSchedule::UniqueId;
}

void Framework::MainFunctionHelperBase::InitLog(const EnvironmentDirectory& environmentDirectory)
{
    CoreTools::Log::Create();
    const auto logFileName = environmentDirectory.GetDirectory(UpperDirectory::Configuration) + SYSTEM_TEXT("Log.json");
    LOG_SINGLETON.LoadConfiguration(CoreTools::StringConversion::StandardConversionMultiByte(logFileName));
    mainFunctionSchedule = MainFunctionSchedule::Log;
}

void Framework::MainFunctionHelperBase::InitInitTerm()
{
    CoreTools::InitTerm::ExecuteInitializer();
    mainFunctionSchedule = MainFunctionSchedule::InitTerm;
}

void Framework::MainFunctionHelperBase::InitImpl(const EnvironmentDirectory& environmentDirectory)
{
    impl = std::make_shared<ImplType>(environmentDirectory);
    mainFunctionSchedule = MainFunctionSchedule::Max;
}

void Framework::MainFunctionHelperBase::MainFunctionHelperDestroy()
{
    DestroyMainImpl();
    DestroyInitTerm();
    DestroyLog();
    DestroyUniqueIdManager();
}

void Framework::MainFunctionHelperBase::DestroyMainImpl() noexcept
{
    if (MainFunctionSchedule::Max <= mainFunctionSchedule)
    {
        impl.reset();
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
        mainFunctionSchedule = MainFunctionSchedule::UniqueId;
    }
}

void Framework::MainFunctionHelperBase::DestroyUniqueIdManager() noexcept
{
    if (MainFunctionSchedule::UniqueId <= mainFunctionSchedule)
    {
        CoreTools::UniqueIdManager::Destroy();
        mainFunctionSchedule = MainFunctionSchedule::Failure;
    }
}

bool Framework::MainFunctionHelperBase::IsDestroy() const noexcept
{
    return (MainFunctionSchedule::Failure == mainFunctionSchedule);
}

Framework::EnvironmentDirectory Framework::MainFunctionHelperBase::GetEnvironmentDirectory() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    if (impl != nullptr)
    {
        return impl->GetEnvironmentDirectory();
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("获取环境目录失败！"s))
    }
}
