// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/18 10:37)

#ifndef CORE_TOOLS_HELPER_STREAM_MACRO_H
#define CORE_TOOLS_HELPER_STREAM_MACRO_H

#include "CoreTools/Assert/Assertion.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h" 
#include "CoreTools/ObjectSystems/InitTerm.h"

// CORE_TOOLS_STREAM_SIZE宏被流系统使用。
#define CORE_TOOLS_STREAM_SIZE(value) CoreTools::GetStreamSize(value) 

#if defined(CORE_TOOLS_USE_ASSERT) && 2 <= USER_ASSERT_LEVEL

	#define CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source) \
			auto beginLoad = source.GetBytesRead()
	#define CORE_TOOLS_END_DEBUG_STREAM_LOAD(source) \
			auto endLoad = source.GetBytesRead(); \
			auto usedLoad = endLoad - beginLoad + CORE_TOOLS_STREAM_SIZE(GetRttiType().GetName()); \
			auto usedReported = ClassType::GetStreamingSize(); \
			ASSERTION_2(usedLoad == usedReported,"读取不匹配的字节数：读取 = %d，所需 = %d\n",usedLoad,usedReported)
	#define CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target) \
			auto beginSave = target.GetBytesWritten()
	#define CORE_TOOLS_END_DEBUG_STREAM_SAVE(target) \
			auto endSave = target.GetBytesWritten();  \
			auto usedSave = endSave - beginSave; \
			auto usedReported = ClassType::GetStreamingSize(); \
			ASSERTION_2(usedSave == usedReported,"保存不匹配的字节数：保存 = %d，所需 = %d\n",usedSave, usedReported)

#else // !defined(CORE_TOOLS_USE_ASSERT) || USER_ASSERT_LEVEL < 2

	#define CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source)
	#define CORE_TOOLS_END_DEBUG_STREAM_LOAD(source)
	#define CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target)
	#define CORE_TOOLS_END_DEBUG_STREAM_SAVE(target)

#endif // defined(CORE_TOOLS_USE_ASSERT) && 2 <= USER_ASSERT_LEVEL

#define CORE_TOOLS_OBJECT_FACTORY_DECLARE(className) \
	    public: explicit className(LoadConstructor value); \
		private: static bool sm_StreamRegistered; \
		public: static bool RegisterFactory (); \
		static void InitializeFactory (); static void TerminateFactory (); \
		static CoreTools::ObjectInterfaceSmartPointer Factory (CoreTools::BufferSource& source)   

#define CORE_TOOLS_OBJECT_STREAM_OVERRIDE_DECLARE \
		void Load (CoreTools::BufferSource& source) override; void Link (CoreTools::ObjectLink& source) override; \
		void PostLink () override; uint64_t Register(CoreTools::ObjectRegister& target) const override; \
		void Save (CoreTools::BufferTarget& target) const override; int GetStreamingSize () const override;    

#define CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(className) \
        CORE_TOOLS_OBJECT_FACTORY_DECLARE(className); \
		CORE_TOOLS_OBJECT_STREAM_OVERRIDE_DECLARE; \
		CORE_TOOLS_RTTI_OVERRIDE_DECLARE

#define CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(namespaceName,className) \
	    CoreTools::ObjectInterfaceSmartPointer namespaceName::className::Factory (CoreTools::BufferSource& ){ \
		ASSERTION_0(false, "抽象类没有工厂！\n"); return CoreTools::ObjectInterfaceSmartPointer(); }

#define CORE_TOOLS_FACTORY_DEFINE(namespaceName,className) \
        CoreTools::ObjectInterfaceSmartPointer namespaceName::className::Factory(CoreTools::BufferSource& source) { \
        CoreTools::ObjectInterfaceSmartPointer object{ std::make_shared<className>(LoadConstructor::ConstructorLoader) }; \
        object->Load(source); return object; }

#define CORE_TOOLS_STREAM_REGISTER(className) \
	    static bool SYSTEM_MULTIPLE_CONCATENATOR(gs_,className,StreamRegistered) { className::RegisterFactory() }

#define CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(namespaceName,className) \
	    bool namespaceName::className::sm_StreamRegistered { false }; \
		bool namespaceName::className::RegisterFactory () { \
        if (!sm_StreamRegistered) { CoreTools::InitTerm::AddInitializer(className::InitializeFactory); sm_StreamRegistered = true; } return sm_StreamRegistered; } \
		void namespaceName::className::InitializeFactory() { OBJECT_MANAGER_SINGLETON.Insert(sm_Type.GetName(), Factory); } \
		void namespaceName::className::TerminateFactory() { OBJECT_MANAGER_SINGLETON.Remove(sm_Type.GetName()); }

#define CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(namespaceName,className) \
	    namespaceName::className::className(LoadConstructor value) : ParentType{ value } { SELF_CLASS_IS_VALID_0; }  

#define CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_CONSTRUCTOR_DEFINE(namespaceName,className) \
	    namespaceName::className::className(LoadConstructor value) : ParentType{ value },m_Impl{ std::make_shared<ImplType>() } { SELF_CLASS_IS_VALID_0; }  

#define CORE_TOOLS_WITH_IMPL_OBJECT_GET_STREAMING_SIZE_DEFINE(namespaceName,className) \
		int namespaceName::className::GetStreamingSize () const { \
		CLASS_IS_VALID_CONST_0;	auto size = ParentType::GetStreamingSize(); \
		size += m_Impl->GetStreamingSize();	return size; }

#define CORE_TOOLS_DEFAULT_OBJECT_REGISTER_DEFINE(namespaceName,className) \
		uint64_t namespaceName::className::Register( CoreTools::ObjectRegister& target ) const { \
		CLASS_IS_VALID_CONST_0;	return ParentType::Register(target); }

#define CORE_TOOLS_WITH_IMPL_OBJECT_REGISTER_DEFINE(namespaceName,className) \
		uint64_t namespaceName::className::Register( CoreTools::ObjectRegister& target ) const { \
		CLASS_IS_VALID_CONST_0; const auto uniqueID = ParentType::Register(target); \
		if (uniqueID != 0) { m_Impl->Register(target); } return uniqueID; }

#define CORE_TOOLS_WITH_IMPL_OBJECT_SAVE_DEFINE(namespaceName,className) \
		void namespaceName::className::Save (CoreTools::BufferTarget& target) const { \
		CLASS_IS_VALID_CONST_0;	CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target); \
		ParentType::Save(target); m_Impl->Save(target); CORE_TOOLS_END_DEBUG_STREAM_SAVE(target); }

#define CORE_TOOLS_DEFAULT_OBJECT_LINK_DEFINE(namespaceName,className) \
		void namespaceName::className::Link (CoreTools::ObjectLink& source) { \
		IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT; ParentType::Link(source); } 

#define CORE_TOOLS_WITH_IMPL_OBJECT_LINK_DEFINE(namespaceName,className) \
		void namespaceName::className::Link (CoreTools::ObjectLink& source) { \
		IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT; ParentType::Link(source); m_Impl->Link(source); } 

#define CORE_TOOLS_DEFAULT_OBJECT_POST_LINK_DEFINE(namespaceName,className) \
		void namespaceName::className::PostLink () { IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT; ParentType::PostLink(); } 

#define CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_DEFINE(namespaceName,className) \
		void namespaceName::className::Load(CoreTools::BufferSource& source) { \
		IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT; CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source); \
		ParentType::Load(source); m_Impl->Load(source);	CORE_TOOLS_END_DEBUG_STREAM_LOAD(source); } 

#define CORE_TOOLS_IMPL_NON_OBJECT_PTR_DEFAULT_STREAM(namespaceName,className) \
		CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_CONSTRUCTOR_DEFINE(namespaceName,className) \
		CORE_TOOLS_WITH_IMPL_OBJECT_GET_STREAMING_SIZE_DEFINE(namespaceName,className) \
		CORE_TOOLS_DEFAULT_OBJECT_REGISTER_DEFINE(namespaceName,className) \
		CORE_TOOLS_WITH_IMPL_OBJECT_SAVE_DEFINE(namespaceName,className) \
		CORE_TOOLS_DEFAULT_OBJECT_LINK_DEFINE(namespaceName,className) \
		CORE_TOOLS_DEFAULT_OBJECT_POST_LINK_DEFINE(namespaceName,className) \
		CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_DEFINE(namespaceName,className)

#define CORE_TOOLS_IMPL_OBJECT_PTR_DEFAULT_STREAM(namespaceName,className) \
	    CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_CONSTRUCTOR_DEFINE(namespaceName,className) \
		CORE_TOOLS_WITH_IMPL_OBJECT_GET_STREAMING_SIZE_DEFINE(namespaceName,className) \
		CORE_TOOLS_WITH_IMPL_OBJECT_REGISTER_DEFINE(namespaceName,className) \
		CORE_TOOLS_WITH_IMPL_OBJECT_SAVE_DEFINE(namespaceName,className) \
		CORE_TOOLS_WITH_IMPL_OBJECT_LINK_DEFINE(namespaceName,className) \
		CORE_TOOLS_DEFAULT_OBJECT_POST_LINK_DEFINE(namespaceName,className) \
		CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_DEFINE(namespaceName,className)

#endif // CORE_TOOLS_HELPER_STREAM_MACRO_H
