///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.3 (2021/09/03 14:05)

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
        NODISCARD int GetNumDirectories() const;
        NODISCARD bool InsertDirectory(const String& directory);
        NODISCARD bool EraseDirectory(const String& directory);
        void EraseAllDirectories() noexcept;

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
        // ������Ҫ·�����ļ�������ʱ�������ظ��ļ���
        NODISCARD String GetPath(const String& fileName, const String& attributes) const;
        NODISCARD bool IsFileInPathExist(const String& decorated, const String& attributes) const;

    private:
        using DirectoriesContainer = std::set<String>;

    private:
        DirectoriesContainer directories;
        String m_ConfigurationPath;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_IMPL_H
