/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/11 13:52)

#ifndef CORE_TOOLS_LOG_MANAGER_LOG_H
#define CORE_TOOLS_LOG_MANAGER_LOG_H

#include "CoreTools/CoreToolsDll.h"

#include "LogAppenderIOManager.h"
#include "LogManagerFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"

CORE_TOOLS_EXPORT_UNIQUE_PTR(Log);
CORE_TOOLS_NON_COPY_EXPORT_IMPL(LogImpl);

/// ��־��
/// Log����һ����������ʹ������֤�̰߳�ȫ��
/// ��־д���߳�ֻ����һ������־��Ϣ��������������д�������֤���̡߳�
/// LoadConfiguration����������AppenderManager��������д����־�̱߳����AppenderManager�����Ǿɵģ����Ա�֤�̰߳�ȫ��
/// д����־ʱ�п��ܻ��AppenderManager�����޸ģ�����Ϊ��ͬһ�̴߳������Կ��Ա�֤�̰߳�ȫ��
namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Log final : public Singleton<Log, MutexCreate::UseStdRecursive>
    {
    public:
        NON_COPY_TYPE_DECLARE(Log);
        using ParentType = Singleton<Log>;

        using String = System::String;

    private:
        enum class LogCreate
        {
            Init,
        };

    public:
        explicit Log(LogCreate logCreate);

        static void Create();
        static void Destroy() noexcept;

        SINGLETON_GET_PTR_DECLARE(Log)

        CLASS_INVARIANT_DECLARE;

        void LoadConfiguration(const std::string& fileName);

        NODISCARD LogLevel GetMinLogLevelType(LogFilter filter) const;

        void Write(const LogMessage& logMessage);

    private:
        using LogUniquePtr = std::unique_ptr<Log>;

    private:
        static LogUniquePtr log;
        PackageType impl;
    };
}

#define LOG_SINGLETON CoreTools::Log::GetSingleton()

#endif  // CORE_TOOLS_LOG_MANAGER_LOG_H
