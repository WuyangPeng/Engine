// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/21 15:38)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_IN_TOP_LEVEL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_IN_TOP_LEVEL_H

#include "CoreTools/CoreToolsDll.h"

#include "ObjectInterface.h"
#include "CoreTools/Helper/ExportMacro.h"

CORE_TOOLS_EXPORT_SHARED_PTR(InTopLevelImpl);

namespace CoreTools
{
	// �����صĶ������
	class CORE_TOOLS_DEFAULT_DECLARE InTopLevel
	{
	public:
		DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(InTopLevel);

	public:
		InTopLevel();

		CLASS_INVARIANT_DECLARE;

		bool IsTopLevel(uint64_t uniqueID) const;
		int GetTopLevelSize() const;
		const ConstObjectInterfaceSmartPointer& operator [](int index) const;
		ObjectInterfaceSmartPointer& operator [](int index);

		// �Զ���Ķ�����б��档
		void Insert(const ObjectInterfaceSmartPointer& objectPtr);

	private:
		IMPL_TYPE_DECLARE(OutTopLevel);
	};
}

#endif // CORE_TOOLS_OBJECT_SYSTEMS_IN_TOP_LEVEL_H
