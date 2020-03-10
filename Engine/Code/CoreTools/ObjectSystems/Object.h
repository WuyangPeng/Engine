// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/21 15:38)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_H

#include "CoreTools/CoreToolsDll.h"

#include "ObjectInterface.h"
#include "ObjectName.h"
#include "CoreTools/Helper/NameMacro.h"
#include "CoreTools/Helper/SubclassSmartPointerMacro.h"
#include "CoreTools/MemoryTools/SubclassSmartPointer.h"

#include <string>
#include <vector>

namespace CoreTools
{
	// �������ϵͳ�ĸ��ࡣ
	// ���ṩ��һ�����������һЩ������������һ�������ࡣ
	class CORE_TOOLS_DEFAULT_DECLARE Object : public ObjectInterface
	{
	public:
		using ClassType = Object;
		using ParentType = ObjectInterface;
		using ObjectSmartPointer = SecondSubclassSmartPointer<Object>;
		using ConstObjectSmartPointer = ConstSecondSubclassSmartPointer<Object>;

	public:
		explicit Object(const std::string& name);
		virtual ~Object() = 0;

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Object);
		CORE_TOOLS_NAMES_DECLARE;

	public:
		// ��������
		const std::string& GetName() const;
		void SetName(const std::string& name);

	protected:
		virtual void Swap(Object& rhs) noexcept;

	private:
		ObjectName m_Name;
	};

	CORE_TOOLS_STREAM_REGISTER(Object);
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Second, Object);
}

#endif // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_H
