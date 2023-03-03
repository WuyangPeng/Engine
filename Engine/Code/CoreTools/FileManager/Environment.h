///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.3 (2023/03/02 10:05)

#ifndef CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_H
#define CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/SingletonMacro.h" 

CORE_TOOLS_EXPORT_UNIQUE_PTR(Environment);
CORE_TOOLS_NON_COPY_EXPORT_IMPL(EnvironmentImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Environment final : public Singleton<Environment>
    {
    public:
        NON_COPY_TYPE_DECLARE(Environment);
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

        SINGLETON_GET_PTR_DECLARE(Environment)

        CLASS_INVARIANT_DECLARE;

        // ֧��ʹ��·������λ�ļ�������ƽ̨�޹��ԣ�ʹ�á�/����Ϊ·���ָ�����
        // ���ԡ�/���������롰Ŀ¼����ֵ������/ɾ���������ء��桱���ҽ��������ɹ���
        NODISCARD int GetNumDirectories() const;

        NODISCARD bool InsertDirectory(const String& directory);
        NODISCARD bool EraseDirectory(const String& directory);
        void EraseAllDirectories();

        // GetPath*��������Ŀ¼�б�������������Ҫ�����������������ȫ���ε��ļ���������������߱������׳�һ���쳣��
        // GetPathReading�ɹ�ʱ�����Դ򿪽��ж�ȡ���ļ���
        // GetPathWriting�ɹ�ʱ�����Դ�����д����ļ���
        // GetPathReadingAndWriting�ɹ�ʱ�����Դ����ڶ�ȡ��/��д����ļ���
        NODISCARD String GetPathReading(const String& fileName) const;
        NODISCARD String GetPathWriting(const String& fileName) const;
        NODISCARD String GetPathReadingAndWriting(const String& fileName) const;

        void SetConfigurationPath(const String& configurationPath);
        NODISCARD const String GetConfigurationPath() const;

    private:
        using EnvironmentUniquePtr = std::unique_ptr<Environment>;

    private:
        static EnvironmentUniquePtr environment;
        PackageType impl;
    };
}

#define ENVIRONMENT_SINGLETON CoreTools::Environment::GetSingleton()

#endif  // CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_H
