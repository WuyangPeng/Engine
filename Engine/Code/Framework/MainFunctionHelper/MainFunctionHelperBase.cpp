// Copyright (c) 2010-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.3.0.1 (2020/05/20 11:53)

#include "Framework/FrameworkExport.h"

#include "MainFunctionHelperBase.h"
#include "Flags/Directory.h"
#include "Flags/MainFunctionSchedule.h"
#include "Detail/DirectoryDefaultName.h"
#include "Detail/MainFunctionHelperBaseImpl.h"
#include "CoreTools/Base/Flags/UniqueIDSelectFlags.h"
#include "CoreTools/Base/UniqueIDManagerDetail.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/FileManager/Environment.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#include "CoreTools/ObjectSystems/InitTerm.h"

using std::make_shared;
using std::move;
using namespace std::literals;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
Framework::MainFunctionHelperBase ::MainFunctionHelperBase(const EnvironmentDirectory& environmentDirectory)
    : impl{}, m_MainFunctionSchedule{ MainFunctionSchedule::Failure }
{
    MainFunctionHelperInit(environmentDirectory);

    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::MainFunctionHelperBase ::MainFunctionHelperBase(MainFunctionHelperBase&& rhs) noexcept
    : impl{ move(rhs.impl) }, m_MainFunctionSchedule{ rhs.m_MainFunctionSchedule }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::MainFunctionHelperBase& Framework::MainFunctionHelperBase ::operator=(MainFunctionHelperBase&& rhs) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    impl = move(rhs.impl);
    m_MainFunctionSchedule = rhs.m_MainFunctionSchedule;

    return *this;
}

Framework::MainFunctionHelperBase ::~MainFunctionHelperBase() noexcept
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;

    CoreTools::NoexceptNoReturn(*this, &ClassType::Destroy);
}

#ifdef OPEN_CLASS_INVARIANT
bool Framework::MainFunctionHelperBase ::IsValid() const noexcept
{
    if ((m_MainFunctionSchedule == MainFunctionSchedule::Max) ^ (impl == nullptr))
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

System::String Framework::MainFunctionHelperBase ::GetEngineInstallationDirectory() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    if (impl != nullptr)
        return impl->GetEngineInstallationDirectory();
    else
        return DirectoryDefaultName::GetDefaultNullName();
}

void Framework::MainFunctionHelperBase ::Destroy()
{
    ;

    if (MainFunctionSchedule::Failure < m_MainFunctionSchedule)
    {
        MainFunctionHelperDestroy();
    }
}

int Framework::MainFunctionHelperBase ::Run()
{
    ;

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
void Framework::MainFunctionHelperBase ::MainFunctionHelperInit(const EnvironmentDirectory& environmentDirectory)
{
    EXCEPTION_TRY
    {
        DoMainFunctionHelperInit(environmentDirectory);
    }
    EXCEPTION_ENTRY_POINT_CATCH
}

// private
void Framework::MainFunctionHelperBase ::DoMainFunctionHelperInit(const EnvironmentDirectory& environmentDirectory)
{
    InitUniqueIDManager();
    InitLog(environmentDirectory);
    InitInitTerm();
    InitEnvironment(); 
    InitImpl(environmentDirectory);
}

// private
void Framework::MainFunctionHelperBase ::InitUniqueIDManager()
{
    CoreTools::UniqueIDManager::Create(CoreTools::UniqueIDSelect::Max);
    m_MainFunctionSchedule = MainFunctionSchedule::UniqueID;
}

void Framework::MainFunctionHelperBase ::InitLog(const EnvironmentDirectory& environmentDirectory)
{
    CoreTools::Log::Create();
    auto logFileName = environmentDirectory.GetDirectory(UpperDirectory::Configuration) + SYSTEM_TEXT("Log.json"s);
    LOG_SINGLETON.LoadConfiguration(CoreTools::StringConversion::StandardConversionMultiByte(logFileName));
    m_MainFunctionSchedule = MainFunctionSchedule::Log;
}

void Framework::MainFunctionHelperBase ::InitInitTerm()
{
    CoreTools::InitTerm::ExecuteInitializers();
    m_MainFunctionSchedule = MainFunctionSchedule::InitTerm;
}

void Framework::MainFunctionHelperBase ::InitEnvironment()
{
    CoreTools::Environment::Create();
    m_MainFunctionSchedule = MainFunctionSchedule::Environment;
}

void Framework::MainFunctionHelperBase ::InitImpl(const EnvironmentDirectory& environmentDirectory)
{
    impl = make_shared<ImplType>(environmentDirectory);
    m_MainFunctionSchedule = MainFunctionSchedule::Max;
}

// private
void Framework::MainFunctionHelperBase ::MainFunctionHelperDestroy()
{
    DestroyImpl();
    DestroySmartPointer();
    DestroyEnvironment();
    DestroyInitTerm();
    DestroyLog();
    DestroyUniqueIDManager();
}

void Framework::MainFunctionHelperBase ::DestroyImpl() noexcept
{
    if (MainFunctionSchedule::Max <= m_MainFunctionSchedule)
    {
        impl.reset();
        m_MainFunctionSchedule = MainFunctionSchedule::SmartPointer;
    }
}

void Framework::MainFunctionHelperBase ::DestroySmartPointer() noexcept
{
    if (MainFunctionSchedule::SmartPointer <= m_MainFunctionSchedule)
    {
        m_MainFunctionSchedule = MainFunctionSchedule::Environment;
    }
}

void Framework::MainFunctionHelperBase ::DestroyEnvironment() noexcept
{
    if (MainFunctionSchedule::Environment <= m_MainFunctionSchedule)
    {
        CoreTools::Environment::Destroy();
        m_MainFunctionSchedule = MainFunctionSchedule::InitTerm;
    }
}

void Framework::MainFunctionHelperBase ::DestroyInitTerm()
{
    if (MainFunctionSchedule::InitTerm <= m_MainFunctionSchedule)
    {
        CoreTools::InitTerm::ExecuteTerminators();
        m_MainFunctionSchedule = MainFunctionSchedule::Memory;
    }
}

void Framework::MainFunctionHelperBase ::DestroyLog() noexcept
{
    if (MainFunctionSchedule::Log <= m_MainFunctionSchedule)
    {
        CoreTools::Log::Destroy();
        m_MainFunctionSchedule = MainFunctionSchedule::UniqueID;
    }
}

void Framework::MainFunctionHelperBase ::DestroyUniqueIDManager() noexcept
{
    if (MainFunctionSchedule::UniqueID <= m_MainFunctionSchedule)
    {
        CoreTools::UniqueIDManager::Destroy();
        m_MainFunctionSchedule = MainFunctionSchedule::Failure;
    }
}

// protected
bool Framework::MainFunctionHelperBase ::IsDestroy() const noexcept
{
    return (MainFunctionSchedule::Failure == m_MainFunctionSchedule);
}

// protected
Framework::EnvironmentDirectory Framework::MainFunctionHelperBase ::GetEnvironmentDirectory() const
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

#include STSTEM_WARNING_POP