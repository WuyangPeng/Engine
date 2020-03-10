// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/19 15:20)

#include "CoreTools/CoreToolsExport.h"

#include "EnvironmentImpl.h"
#include "CFileManagerImpl.h"
#include "System/FileManager/CFile.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/CharacterString/StringConversion.h"

#include <boost/numeric/conversion/cast.hpp>

CoreTools::EnvironmentImpl
	::EnvironmentImpl()
	:m_Directories{}
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, EnvironmentImpl)

int CoreTools::EnvironmentImpl
	::GetNumDirectories() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return boost::numeric_cast<int>(m_Directories.size());
}

bool CoreTools::EnvironmentImpl
	::InsertDirectory(const String& directory)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	auto returnValue = m_Directories.insert(directory);

	return returnValue.second;
}

bool CoreTools::EnvironmentImpl
	::EraseDirectory(const String& directory)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	auto eraseNumber = m_Directories.erase(directory);

	return (eraseNumber != 0);
}

void CoreTools::EnvironmentImpl
	::EraseAllDirectories() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	m_Directories.clear();
}

System::String CoreTools::EnvironmentImpl
	::GetPathReading(const String& fileName) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return GetPath(fileName, SYSTEM_TEXT("r"));
}

System::String CoreTools::EnvironmentImpl
	::GetPathWriting(const String& fileName) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return GetPath(fileName, SYSTEM_TEXT("w"));
}

System::String CoreTools::EnvironmentImpl
	::GetPathReadingAndWriting(const String& fileName) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return GetPath(fileName, SYSTEM_TEXT("r+"));
}

// private
System::String CoreTools::EnvironmentImpl
	::GetPath(const String& fileName, const String& attributes) const
{
	for (const auto& path : m_Directories)
	{
		auto decorated = path + fileName;
		if (IsFileInPathExist(decorated, attributes))
		{
			return decorated;
		}
	}

	THROW_EXCEPTION(SYSTEM_TEXT("未找符合条件的文件名！"));
}

// private
bool CoreTools::EnvironmentImpl
	::IsFileInPathExist(const String& decorated, const String& attributes) const
{
	FILE* file{ nullptr };

	auto decoratedConversion = StringConversion::StandardConversionCFileString(decorated);
	auto attributesConversion = StringConversion::StandardConversionCFileString(attributes);

	if (System::OpenCFile(file, decoratedConversion, attributesConversion))
	{
		System::CloseCFile(file);
		return true;
	}
	else
	{
		return false;
	}
}

void CoreTools::EnvironmentImpl
	::SetConfigurationPath(const String& configurationPath)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	m_ConfigurationPath = configurationPath;
}

const System::String CoreTools::EnvironmentImpl
	::GetConfigurationPath() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_ConfigurationPath;
}

