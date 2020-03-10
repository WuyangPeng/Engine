// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/21 15:39)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_NAME_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_NAME_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <string>

CORE_TOOLS_EXPORT_SHARED_PTR(ObjectNameImpl);

namespace CoreTools
{
	// Object类的名字
	class CORE_TOOLS_DEFAULT_DECLARE ObjectName
	{
	public:
		DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(ObjectName);

	public:
		explicit ObjectName(const std::string& name = "");

		CLASS_INVARIANT_DECLARE;

		const std::string& GetName() const;
		bool IsExactly(const ObjectName& name) const;

		void SetName(const std::string& name);

		void Swap(ClassType& rhs) noexcept;

	private:
		IMPL_TYPE_DECLARE(ObjectName);
	};
}

#endif // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_NAME_H
