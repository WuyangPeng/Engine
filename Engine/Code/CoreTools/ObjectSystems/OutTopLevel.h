// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/21 15:39)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OUT_TOP_LEVEL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OUT_TOP_LEVEL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "ObjectInterface.h"

CORE_TOOLS_EXPORT_SHARED_PTR(OutTopLevelImpl);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE OutTopLevel
	{
	public:
		DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(OutTopLevel);

	public:
		OutTopLevel();

		CLASS_INVARIANT_DECLARE;

		bool IsTopLevel(uint64_t uniqueID) const;
		int GetTopLevelSize() const;
		const ConstObjectInterfaceSmartPointer& operator [](int index) const;

		// 对顶层的对象进行保存。
		void Insert(const ObjectInterfaceSmartPointer& objectPtr);
		void SetUniqueID(int index, uint64_t uniqueID);

	private:
		IMPL_TYPE_DECLARE(OutTopLevel);
	};
}

#endif // CORE_TOOLS_OBJECT_SYSTEMS_OUT_TOP_LEVEL_H
