// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/21 15:39)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_INTERFACE_H
#define CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_INTERFACE_H

#include "CoreTools/CoreToolsDll.h"

#include "ObjectSystemsFwd.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/RttiMacro.h"
#include "CoreTools/MemoryTools/FirstSubclassSmartPointer.h" 

namespace CoreTools
{
	using ObjectPtr = ObjectInterface*;

	// 指向常量的ObjectInterface指针
	using ConstObjectPtr = ObjectInterface const*;

	// 常量ObjectInterface指针
	using ObjectConstPtr = ObjectInterface* const;

	// 指向常量的常量ObjectInterface指针
	using ConstObjectConstPtr = const ObjectInterface* const;

	class CORE_TOOLS_DEFAULT_DECLARE ObjectInterface
	{
	public:
		using ClassType = ObjectInterface;
		using ObjectInterfaceSmartPointer = FirstSubclassSmartPointer<ObjectInterface>;
		using ConstObjectInterfaceSmartPointer = ConstFirstSubclassSmartPointer<ObjectInterface>;
		using FactoryFunction = ObjectInterfaceSmartPointer(*)(BufferSource& stream);

	public:
		ObjectInterface();
		virtual ~ObjectInterface();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		CORE_TOOLS_RTTI_DECLARE;

	public:
		// 运行时类型信息。
		bool IsExactly(const Rtti& type) const;
		bool IsDerived(const Rtti& type) const;
		bool IsExactlyTypeOf(const ObjectInterface* object) const;
		bool IsDerivedTypeOf(const ObjectInterface* object) const;

	public:
		// 流
		static bool RegisterFactory();
		static void InitializeFactory();
		static void TerminateFactory();
		static ObjectInterfaceSmartPointer Factory(BufferSource& source);

		uint64_t GetUniqueID() const noexcept;
		void SetUniqueID(uint64_t uniqueID) noexcept;

		virtual uint64_t Register(ObjectRegister& target) const = 0;
		virtual int GetStreamingSize() const = 0;
		virtual void Save(BufferTarget& target) const = 0;

		virtual void Link(ObjectLink& source) = 0;
		virtual void PostLink() = 0;
		virtual void Load(BufferSource& source) = 0;

	protected:
		// 加载系统所使用的构造函数。
		enum class LoadConstructor : uint32_t
		{
			ConstructorLoader
		};

		explicit ObjectInterface(LoadConstructor value);

	private:
		static bool sm_StreamRegistered;

		uint64_t m_UniqueID;
	};

	using ObjectInterfaceSmartPointer = ObjectInterface::ObjectInterfaceSmartPointer;
	using ConstObjectInterfaceSmartPointer = ObjectInterface::ConstObjectInterfaceSmartPointer;
}

#include "CoreTools/Helper/StreamMacro.h"

namespace CoreTools
{
#include STSTEM_WARNING_PUSH

#include SYSTEM_WARNING_DISABLE(26426)  
	CORE_TOOLS_STREAM_REGISTER(ObjectInterface);

#include STSTEM_WARNING_POP
}

#endif // CORE_TOOLS_OBJECT_SYSTEMS_OBJECT_INTERFACE_H
