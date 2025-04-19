/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/03/30 22:54)

#ifndef CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_H
#define CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"

CORE_TOOLS_NON_COPY_EXPORT_IMPL(EnvironmentImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Environment final
    {
    public:
        NON_COPY_TYPE_DECLARE(Environment);

        using String = System::String;

    private:
        enum class EnvironmentCreate
        {
            Init,
        };

    public:
        NODISCARD static Environment Create();

        explicit Environment(EnvironmentCreate environmentCreate);

        CLASS_INVARIANT_DECLARE;

        /// ֧��ʹ��·������λ�ļ�������ƽ̨�����ԣ�ʹ�á�/����Ϊ·���ָ�����
        /// �������ġ�Ŀ¼����ֵδ�ԡ�/����\\����β���������Զ�����һ��β��ġ�/����
        /// ��������ɹ�������/ɾ���������ء��桱��
        NODISCARD int GetNumDirectories() const;
        NODISCARD String GetDirectory(int index) const;
        NODISCARD bool InsertDirectory(const String& directory);
        NODISCARD bool EraseDirectory(const String& directory);
        void EraseAllDirectories() noexcept;

        /// GetPath*��������Ŀ¼�б�������������Ҫ�����������������ȫ���ε��ļ���������������߱������׳�һ���쳣��
        /// GetPathReading�ɹ�ʱ�����Դ����ڶ�ȡ���ļ���
        /// GetPathWriting�ɹ�ʱ�����Դ�����д����ļ���
        /// GetPathReadingAndWriting�ɹ�ʱ�����Դ����ڶ�ȡ��/��д����ļ���
        NODISCARD String GetPathReading(const String& fileName) const;
        NODISCARD String GetPathWriting(const String& fileName) const;
        NODISCARD String GetPathReadingAndWriting(const String& fileName) const;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_H
