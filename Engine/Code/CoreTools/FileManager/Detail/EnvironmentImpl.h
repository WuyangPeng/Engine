//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/13 17:29)

#ifndef CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <set>
#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE EnvironmentImpl final
    {
    public:
        using ClassType = EnvironmentImpl;
        using String = System::String;

    public:
        EnvironmentImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        // ֧��ʹ��·������λ�ļ��� ����ƽ̨�޹��ԣ�ʹ�á�/����Ϊ·���ָ�����
        // ���ԡ�/���������롰Ŀ¼����ֵ�� ����/ɾ���������ء��桱���ҽ��������ɹ���
        [[nodiscard]] int GetNumDirectories() const;
        [[nodiscard]] bool InsertDirectory(const String& directory);
        [[nodiscard]] bool EraseDirectory(const String& directory);
        void EraseAllDirectories() noexcept;

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
        // ������Ҫ·�����ļ�������ʱ�������ظ��ļ���
        [[nodiscard]] String GetPath(const String& fileName, const String& attributes) const;
        [[nodiscard]] bool IsFileInPathExist(const String& decorated, const String& attributes) const;

    private:
        using DirectoriesContainer = std::set<String>;

    private:
        DirectoriesContainer m_Directories;
        String m_ConfigurationPath;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_IMPL_H
