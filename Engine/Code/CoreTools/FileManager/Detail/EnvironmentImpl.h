// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/19 13:40)

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

		// 支持使用路径来定位文件。 对于平台无关性，使用“/”作为路径分隔符。 
		// 并以“/”结束输入“目录”的值。 插入/删除函数返回“真”当且仅当操作成功。
		int GetNumDirectories() const;
		bool InsertDirectory(const String& directory);
		bool EraseDirectory(const String& directory);
		void EraseAllDirectories() noexcept;

		// GetPath*函数搜索目录列表，假设它满足所要求的条件，它返回完全修饰的文件名，如果条件不具备，它抛出一个异常。
		// GetPathReading成功时，可以打开进行读取的文件。
		// GetPathWriting成功时，可以打开用于写入的文件。
		// GetPathReadingAndWriting成功时，可以打开用于读取和/或写入的文件。
		String GetPathReading(const String& fileName) const;
		String GetPathWriting(const String& fileName) const;
		String GetPathReadingAndWriting(const String& fileName) const;

		void SetConfigurationPath(const String& configurationPath);
		const String GetConfigurationPath() const;

	private:
		// 当不需要路径而文件名存在时，不返回该文件！
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
