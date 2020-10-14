//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/13 20:27)

#ifndef CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_H
#define CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"
#include "CoreTools/Threading/ThreadingFwd.h"

#include <shared_mutex>

CORE_TOOLS_EXPORT_UNIQUE_PTR(Environment);
CORE_TOOLS_EXPORT_SHARED_PTR(EnvironmentImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Environment final : public Singleton<Environment>
    {
    public:
        NON_COPY_CLASSES_TYPE_DECLARE(Environment);
        using ParentType = Singleton<Environment>;
        using String = System::String;

    private:
        enum class EnvironmentCreate
        {
            Init,
        };

    public:
        explicit Environment(EnvironmentCreate environmentCreate);

        static void Create();
        static void Destroy() noexcept;

        SINGLETON_GET_PTR_DECLARE(Environment);

        CLASS_INVARIANT_DECLARE;

        // ֧��ʹ��·������λ�ļ�������ƽ̨�޹��ԣ�ʹ�á�/����Ϊ·���ָ�����
        // ���ԡ�/���������롰Ŀ¼����ֵ������/ɾ���������ء��桱���ҽ��������ɹ���
        [[nodiscard]] int GetNumDirectories() const;

        [[nodiscard]] bool InsertDirectory(const String& directory);
        [[nodiscard]] bool EraseDirectory(const String& directory);
        void EraseAllDirectories();

        // GetPath*��������Ŀ¼�б�������������Ҫ�����������������ȫ���ε��ļ���������������߱������׳�һ���쳣��
        // GetPathReading�ɹ�ʱ�����Դ򿪽��ж�ȡ���ļ���
        // GetPathWriting�ɹ�ʱ�����Դ�����д����ļ���
        // GetPathReadingAndWriting�ɹ�ʱ�����Դ����ڶ�ȡ��/��д����ļ���
        [[nodiscard]] String GetPathReading(const String& fileName) const;
        [[nodiscard]] String GetPathWriting(const String& fileName) const;
        [[nodiscard]] String GetPathReadingAndWriting(const String& fileName) const;

        void SetConfigurationPath(const String& configurationPath);
        [[nodiscard]] const String GetConfigurationPath() const;

    private:
        using EnvironmentUniquePtr = std::unique_ptr<Environment>;

    private:
        static EnvironmentUniquePtr sm_Environment;
        IMPL_TYPE_DECLARE(Environment);
    };
}

#define ENVIRONMENT_SINGLETON CoreTools::Environment::GetSingleton()

#endif  // CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_H
