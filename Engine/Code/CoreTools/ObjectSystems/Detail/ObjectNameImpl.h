// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/21 15:37)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_NAME_IMPL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_NAME_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <string>

namespace CoreTools
{
	// Object�������
	class CORE_TOOLS_HIDDEN_DECLARE ObjectNameImpl
	{
	public:
		using ClassType = ObjectNameImpl;

	public:
		explicit ObjectNameImpl(const std::string& name);

		CLASS_INVARIANT_DECLARE;

		const std::string& GetName() const;
		bool IsExactly(const ClassType& name) const;

		void SetName(const std::string& name);

	private:
		std::string m_Name;
	};
}

#endif // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_NAME_IMPL_H
