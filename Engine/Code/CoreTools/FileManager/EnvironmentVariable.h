// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 14:20)

// ��ȡ�ַ�����Ӧ�Ļ���������
#ifndef CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_VARIABLE_H
#define CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_VARIABLE_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>
#include <string>

CORE_TOOLS_EXPORT_SHARED_PTR(EnvironmentVariableImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE EnvironmentVariable : private boost::noncopyable
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(EnvironmentVariable);
		using String = System::String;

	public:
		explicit EnvironmentVariable(const String& variableName);

		CLASS_INVARIANT_DECLARE;

		String GetVariable() const;

	private:
		IMPL_TYPE_DECLARE(EnvironmentVariable);
	};
}

#endif // CORE_TOOLS_FILE_MANAGER_ENVIRONMENT_VARIABLE_H
