// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 13:40)

#ifndef CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <set>
#include <string>

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE EnvironmentImpl
	{
	public:
		using ClassType = EnvironmentImpl;
		using String = System::String;

	public:
		EnvironmentImpl() noexcept;

		CLASS_INVARIANT_DECLARE;

		// ֧��ʹ��·������λ�ļ��� ����ƽ̨�޹��ԣ�ʹ�á�/����Ϊ·���ָ����� 
		// ���ԡ�/���������롰Ŀ¼����ֵ�� ����/ɾ���������ء��桱���ҽ��������ɹ���
		int GetNumDirectories() const;
		bool InsertDirectory(const String& directory);
		bool EraseDirectory(const String& directory);
		void EraseAllDirectories() noexcept;

		// GetPath*��������Ŀ¼�б�������������Ҫ�����������������ȫ���ε��ļ���������������߱������׳�һ���쳣��
		// GetPathReading�ɹ�ʱ�����Դ򿪽��ж�ȡ���ļ���
		// GetPathWriting�ɹ�ʱ�����Դ�����д����ļ���
		// GetPathReadingAndWriting�ɹ�ʱ�����Դ����ڶ�ȡ��/��д����ļ���
		String GetPathReading(const String& fileName) const;
		String GetPathWriting(const String& fileName) const;
		String GetPathReadingAndWriting(const String& fileName) const;

		void SetConfigurationPath(const String& configurationPath);
		const String GetConfigurationPath() const;

	private:
		// ������Ҫ·�����ļ�������ʱ�������ظ��ļ���
		String GetPath(const String& fileName, const String& attributes) const;
		bool IsFileInPathExist(const String& decorated, const String& attributes) const;

	private:
		using DirectoriesContainer = std::set<String>;

	private:
		DirectoriesContainer m_Directories;
		String m_ConfigurationPath;
	};
}

#endif // CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_IMPL_H
