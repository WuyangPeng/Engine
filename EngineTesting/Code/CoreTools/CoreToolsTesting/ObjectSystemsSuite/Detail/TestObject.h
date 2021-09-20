// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 13:30)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_SUITE_TEST_OBJECT_H
#define CORE_TOOLS_OBJECT_SYSTEMS_SUITE_TEST_OBJECT_H

#include "CoreTools/ObjectSystems/Object.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class TestObject : public Object
	{
	public:
		using ClassType = TestObject;
		using ParentType = Object;

	public:
		TestObject();
		virtual ~TestObject();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		CORE_TOOLS_OBJECT_FACTORY_DECLARE(TestObject);
		CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

		ObjectInterfaceSharedPtr CloneObject() const override;
	};
	#include STSTEM_WARNING_PUSH
	#include SYSTEM_WARNING_DISABLE(26426)
	CORE_TOOLS_STREAM_REGISTER(TestObject);
	#include STSTEM_WARNING_POP
        CORE_TOOLS_SHARED_PTR_DECLARE( TestObject);
}

#endif // CORE_TOOLS_OBJECT_SYSTEMS_SUITE_TEST_OBJECT_H