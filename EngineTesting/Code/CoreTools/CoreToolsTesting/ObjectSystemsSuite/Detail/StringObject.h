// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.0.2.3 (2020/03/06 13:29)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_STRING_OBJECT_H
#define CORE_TOOLS_OBJECT_SYSTEMS_STRING_OBJECT_H

#include "CoreTools/CoreToolsDll.h"

#include "NullObject.h" 

#include <string>

// String值对象，这个类用于演示Object使用String值和String值的数组。
namespace CoreTools
{
	class StringObject : public NullObject
	{
	public:
		using ClassType = StringObject;
		using ParentType = NullObject;

	public:
		StringObject();
		virtual ~StringObject();

		StringObject(const StringObject& rhs);
		StringObject& operator = (const StringObject& rhs);

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(StringObject);
                ObjectInterfaceSharedPtr CloneObject() const override;
	private:
		void AllocationArray1(const std::string& value);
		void AllocationArray2(const std::string& value);
		void Release();
		void Swap(StringObject& rhs);
		bool IsLoadValidity() const;

	private:
		static constexpr auto bufferSize = 5;

		std::string* m_StringValue;
		std::string* m_StringArray1;
		std::string* m_StringArray2;
	};
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
	CORE_TOOLS_STREAM_REGISTER(StringObject);
	#include STSTEM_WARNING_POP
	CORE_TOOLS_SHARED_PTR_DECLARE( StringObject);
}

#endif // CORE_TOOLS_OBJECT_SYSTEMS_STRING_OBJECT_H
