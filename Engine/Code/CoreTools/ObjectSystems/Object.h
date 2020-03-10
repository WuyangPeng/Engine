// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/21 15:38)

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
	// 根类对象系统的根类。
	// 它提供了一个面向对象库的一些基本服务，这是一个抽象类。
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
		// 对象名字
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
