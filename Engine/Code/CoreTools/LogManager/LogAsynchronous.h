///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/28 16:08)

#ifndef CORE_TOOLS_LOG_MANAGER_LOG_ASYNCHRONOUS_H
#define CORE_TOOLS_LOG_MANAGER_LOG_ASYNCHRONOUS_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Base/SingletonDetail.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"
#include "CoreTools/LogManager/Flags/LogManagerFlags.h"
#include "CoreTools/LogManager/LogManagerFwd.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

CORE_TOOLS_EXPORT_UNIQUE_PTR(LogAsynchronous);
CORE_TOOLS_NON_COPY_EXPORT_IMPL(LogAsynchronousImpl);

namespace CoreTools
{
    // 由于实现类本身使用了锁，单例不再使用锁。
    class CORE_TOOLS_DEFAULT_DECLARE LogAsynchronous final : public Singleton<LogAsynchronous, MutexCreate::UseNull>
    {
    public:
        NON_COPY_TYPE_DECLARE(LogAsynchronous);
        using ParentType = Singleton<LogAsynchronous>;
        using String = System::String;
        using AppenderManagerSharedPtr = std::shared_ptr<AppenderManager>;

    private:
        enum class LogAsynchronousCreate
        {
            Init,
        };

    public:
        explicit LogAsynchronous(LogAsynchronousCreate logAsynchronousCreate);

        static void Create();
        static void Destroy() noexcept;

        SINGLETON_GET_PTR_DECLARE(LogAsynchronous)

        CLASS_INVARIANT_DECLARE;

        void Registered(const LogMessage& message, const AppenderManagerSharedPtr& appenderManager);
        void Registered(const String& fileName, const LogMessage& message, const AppenderManagerSharedPtr& appenderManager);
        void Registered(const OStreamShared& streamShared, const std::string& message, LogLevel logLevel = LogLevel::Trace);

        void Run();
        void Stop();

    private:
        using LogAsynchronousUniquePtr = std::unique_ptr<LogAsynchronous>;

    private:
        static LogAsynchronousUniquePtr logAsynchronous;
        PackageType impl;
    };
}

#define LOG_ASYNCHRONOUS_SINGLETON CoreTools::LogAsynchronous::GetSingleton()

#endif  // CORE_TOOLS_LOG_MANAGER_LOG_ASYNCHRONOUS_H
