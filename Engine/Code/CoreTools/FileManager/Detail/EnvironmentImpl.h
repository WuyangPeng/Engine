///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.3 (2023/03/02 09:42)

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

        void SetConfigurationPath(const String& aConfigurationPath);
        NODISCARD const String GetConfigurationPath() const;

    private:
        // ������Ҫ·�����ļ�������ʱ�������ظ��ļ���
        NODISCARD String GetPath(const String& fileName, const String& attributes) const;
        NODISCARD static bool IsFileInPathExist(const String& decorated, const String& attributes);

    private:
        using DirectoriesContainer = std::set<String>;

    private:
        DirectoriesContainer directories;
        String configurationPath;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_IMPL_H
