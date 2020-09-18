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
#include "System/Helper/PragmaWarning.h"
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
		using ObjectSmartPointer = std::shared_ptr<Object>;
		using ConstObjectSmartPointer = std::shared_ptr<const Object>;

	public:
		explicit Object(const std::string& name); 

		#include STSTEM_WARNING_PUSH

#include SYSTEM_WARNING_DISABLE(26456)

                ~Object() = default;
                Object(const Object&)  = default;
                virtual Object& operator=(const Object&)  = default;
                Object(Object&&) noexcept = default;
                virtual Object& operator=(Object&&) noexcept = default;

#include STSTEM_WARNING_POP

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Object);
		CORE_TOOLS_NAMES_DECLARE;

	public:
		// 对象名字
		  std::string  GetName() const  ;
		void SetName(const std::string& name);

	protected:
		virtual void Swap(Object& rhs) noexcept;

	private:
		ObjectName m_Name;
	};
#include STSTEM_WARNING_PUSH

#include SYSTEM_WARNING_DISABLE(26426)  
	CORE_TOOLS_STREAM_REGISTER(Object);
#include STSTEM_WARNING_POP

	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Second, Object);
}

#endif // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_H
