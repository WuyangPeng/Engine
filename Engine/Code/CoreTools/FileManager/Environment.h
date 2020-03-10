// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 14:20)

#ifndef CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_H
#define CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"
#include "CoreTools/Threading/ThreadingFwd.h"

#include <shared_mutex>

CORE_TOOLS_EXPORT_SHARED_PTR(EnvironmentImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE Environment : public Singleton<Environment>
	{
	public:
		SINGLETON_INITIALIZE_DECLARE(Environment);
		using String = System::String;

	public:
		CLASS_INVARIANT_DECLARE;

		// ֧��ʹ��·������λ�ļ�������ƽ̨�޹��ԣ�ʹ�á�/����Ϊ·���ָ�����
		// ���ԡ�/���������롰Ŀ¼����ֵ������/ɾ���������ء��桱���ҽ��������ɹ���
		int GetNumDirectories() const;

		bool InsertDirectory(const String& directory);
		bool EraseDirectory(const String& directory);
		void EraseAllDirectories();

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
		SINGLETON_MEMBER_DECLARE_USE_SHARED(Environment);
	};
}

#define ENVIRONMENT_SINGLETON CoreTools::Environment::GetSingleton()

#endif // CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_H
