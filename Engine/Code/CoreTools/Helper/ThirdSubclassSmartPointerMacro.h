// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/18 14:58)

#ifndef CORE_TOOLS_HELPER_THIRD_SUBCLASS_SMART_PIINTER_MACRO_H
#define CORE_TOOLS_HELPER_THIRD_SUBCLASS_SMART_PIINTER_MACRO_H

#include "System/Helper/PragmaWarning/PolymorphicCast.h"

#define CONST_SUBCLASS_SMART_POINTER_STATEMENT(subclassIndex,baseClassIndex) \
	    namespace CoreTools { template <typename SubClass,typename BaseClass = typename SubclassSmartPointerTraits<SubClass>::ParentType> \
		class SYSTEM_MULTIPLE_CONCATENATOR(Const,subclassIndex,SubclassSmartPointer) : public SYSTEM_MULTIPLE_CONCATENATOR(Const,baseClassIndex,SubclassSmartPointer)<BaseClass> \
		{ public: using SubclassType = SubClass; using BaseClassType = BaseClass; \
		static_assert((std::is_base_of<BaseClassType,SubclassType>::value),"BaseClass is the base class of SubClass"); \
		using ClassType = SYSTEM_MULTIPLE_CONCATENATOR(Const,subclassIndex,SubclassSmartPointer)<SubclassType,BaseClassType>; \
		using ParentType = SYSTEM_MULTIPLE_CONCATENATOR(Const,baseClassIndex,SubclassSmartPointer)<BaseClassType>; public: \
		explicit SYSTEM_MULTIPLE_CONCATENATOR(Const,subclassIndex,SubclassSmartPointer)(uint64_t address,const SubclassType* data = nullptr); \
		explicit SYSTEM_MULTIPLE_CONCATENATOR(Const,subclassIndex,SubclassSmartPointer)(const SubclassType* data); \
	    SYSTEM_MULTIPLE_CONCATENATOR(Const,subclassIndex,SubclassSmartPointer)() noexcept; \
		CLASS_INVARIANT_OVERRIDE_DECLARE; \
		const SubclassType* GetData() const override; const SubclassType& operator* () const override; const SubclassType* operator-> () const override; }; } 

#define SUBCLASS_SMART_POINTER_STATEMENT(subclassIndex,baseClassIndex) \
        namespace CoreTools { template <typename SubClass,typename BaseClass = typename SubclassSmartPointerTraits<SubClass>::ParentType> \
	    class  SYSTEM_CONCATENATOR(subclassIndex,SubclassSmartPointer) : public SYSTEM_CONCATENATOR(baseClassIndex,SubclassSmartPointer)<BaseClass> \
        { public: using SubclassType = SubClass; using BaseClassType = BaseClass; \
		static_assert((std::is_base_of<BaseClassType, SubclassType>::value), "BaseClass is the base class of SubClass"); \
		using ClassType = SYSTEM_CONCATENATOR(subclassIndex,SubclassSmartPointer)<SubclassType, BaseClassType>; \
		using ParentType = SYSTEM_CONCATENATOR(baseClassIndex,SubclassSmartPointer)<BaseClassType>; \
		using ConstType = SYSTEM_MULTIPLE_CONCATENATOR(Const,subclassIndex,SubclassSmartPointer)<SubclassType, BaseClassType>; \
		public: explicit SYSTEM_CONCATENATOR(subclassIndex,SubclassSmartPointer)(uint64_t address,SubclassType* data = nullptr); \
		explicit SYSTEM_CONCATENATOR(subclassIndex,SubclassSmartPointer)(SubclassType* data); \
		SYSTEM_CONCATENATOR(subclassIndex,SubclassSmartPointer)() noexcept; \
		CLASS_INVARIANT_OVERRIDE_DECLARE; SubclassType* GetData() override; SubclassType& operator* () override; \
		SubclassType* operator-> () override; const SubclassType* GetData() const override; const SubclassType& operator* () const override; \
		const SubclassType* operator-> () const override; ConstType GetConstSmartPointer() const; operator ConstType () const; }; }	

#ifdef OPEN_CLASS_INVARIANT

	#define CLASS_INVARIANT_CONST_SMART_POINTER_PARENT_IS_VALID_DEFINE(subclassIndex) \
			template <typename SubClass,typename BaseClass>	bool CoreTools::SYSTEM_MULTIPLE_CONCATENATOR(Const,subclassIndex,SubclassSmartPointer)<SubClass,BaseClass> \
			::IsValid() const noexcept { if(ParentType::IsValid()) return true; else return false; }

	#define CLASS_INVARIANT_SMART_POINTER_PARENT_IS_VALID_DEFINE(subclassIndex) \
			template <typename SubClass,typename BaseClass> bool CoreTools::SYSTEM_CONCATENATOR(subclassIndex,SubclassSmartPointer)<SubClass,BaseClass> \
			::IsValid() const noexcept { if(ParentType::IsValid()) return true;	else return false; }

#else // !OPEN_CLASS_INVARIANT

	#define CLASS_INVARIANT_CONST_SMART_POINTER_PARENT_IS_VALID_DEFINE(subclassIndex)

	#define CLASS_INVARIANT_SMART_POINTER_PARENT_IS_VALID_DEFINE(subclassIndex)

#endif // OPEN_CLASS_INVARIANT

#define CONST_SUBCLASS_SMART_POINTER_DEFINE(subclassIndex) \
	    template <typename SubClass,typename BaseClass>	CoreTools::SYSTEM_MULTIPLE_CONCATENATOR(Const,subclassIndex,SubclassSmartPointer)<SubClass,BaseClass> \
		::SYSTEM_MULTIPLE_CONCATENATOR(Const,subclassIndex,SubclassSmartPointer)(uint64_t address,const SubclassType* data) \
		:ParentType{ address,data } { CORE_TOOLS_SELF_CLASS_IS_VALID_9; } \
        template <typename SubClass,typename BaseClass> CoreTools::SYSTEM_MULTIPLE_CONCATENATOR(Const,subclassIndex,SubclassSmartPointer)<SubClass,BaseClass> \
		::SYSTEM_MULTIPLE_CONCATENATOR(Const,subclassIndex,SubclassSmartPointer)(const SubclassType* data) :ParentType{ data } { CORE_TOOLS_SELF_CLASS_IS_VALID_9; } \
		template <typename SubClass,typename BaseClass> CoreTools::SYSTEM_MULTIPLE_CONCATENATOR(Const,subclassIndex,SubclassSmartPointer)<SubClass,BaseClass> \
		::SYSTEM_MULTIPLE_CONCATENATOR(Const,subclassIndex,SubclassSmartPointer)() noexcept :ParentType{ } { CORE_TOOLS_SELF_CLASS_IS_VALID_9; } \
		CLASS_INVARIANT_CONST_SMART_POINTER_PARENT_IS_VALID_DEFINE(subclassIndex) \
		template <typename SubClass,typename BaseClass> const typename CoreTools::SYSTEM_MULTIPLE_CONCATENATOR(Const,subclassIndex,SubclassSmartPointer)<SubClass,BaseClass>::SubclassType* \
		CoreTools::SYSTEM_MULTIPLE_CONCATENATOR(Const,subclassIndex,SubclassSmartPointer)<SubClass,BaseClass>::GetData() const { CORE_TOOLS_CLASS_IS_VALID_CONST_9; \
		return boost::polymorphic_downcast<const SubclassType*>(ParentType::GetData()); } \
		template <typename SubClass,typename BaseClass> const typename CoreTools::SYSTEM_MULTIPLE_CONCATENATOR(Const,subclassIndex,SubclassSmartPointer)<SubClass,BaseClass>::SubclassType& \
		CoreTools::SYSTEM_MULTIPLE_CONCATENATOR(Const,subclassIndex,SubclassSmartPointer)<SubClass,BaseClass>::operator* () const \
        { CORE_TOOLS_CLASS_IS_VALID_CONST_9;return *GetData(); } template <typename SubClass,typename BaseClass> \
		const typename CoreTools::SYSTEM_MULTIPLE_CONCATENATOR(Const,subclassIndex,SubclassSmartPointer)<SubClass,BaseClass>::SubclassType*  \
		CoreTools::SYSTEM_MULTIPLE_CONCATENATOR(Const,subclassIndex,SubclassSmartPointer)<SubClass,BaseClass>::operator-> () const { CORE_TOOLS_CLASS_IS_VALID_CONST_9; return GetData(); } 

#define SUBCLASS_SMART_POINTER_DEFINE(subclassIndex) \
        template <typename SubClass, typename BaseClass> CoreTools::SYSTEM_CONCATENATOR(subclassIndex,SubclassSmartPointer)<SubClass, BaseClass> \
		::SYSTEM_CONCATENATOR(subclassIndex,SubclassSmartPointer)(uint64_t address, SubclassType* data):ParentType{ address, data } { CORE_TOOLS_SELF_CLASS_IS_VALID_9; } \
		template <typename SubClass, typename BaseClass> CoreTools::SYSTEM_CONCATENATOR(subclassIndex,SubclassSmartPointer)<SubClass, BaseClass> \
	    ::SYSTEM_CONCATENATOR(subclassIndex,SubclassSmartPointer)(SubclassType* data):ParentType{ data } { CORE_TOOLS_SELF_CLASS_IS_VALID_9; } \
		template <typename SubClass, typename BaseClass> CoreTools::SYSTEM_CONCATENATOR(subclassIndex,SubclassSmartPointer)<SubClass, BaseClass> \
	    ::SYSTEM_CONCATENATOR(subclassIndex,SubclassSmartPointer)() noexcept :ParentType{ } { CORE_TOOLS_SELF_CLASS_IS_VALID_9; } \
		CLASS_INVARIANT_SMART_POINTER_PARENT_IS_VALID_DEFINE(subclassIndex) \
		template <typename SubClass, typename BaseClass> const typename CoreTools::SYSTEM_CONCATENATOR(subclassIndex,SubclassSmartPointer)<SubClass, BaseClass>::SubclassType* \
        CoreTools::SYSTEM_CONCATENATOR(subclassIndex,SubclassSmartPointer)<SubClass, BaseClass>::GetData() const \
        { CORE_TOOLS_CLASS_IS_VALID_CONST_9; return boost::polymorphic_downcast<const SubclassType*>(ParentType::GetData()); } \
        template <typename SubClass, typename BaseClass> const typename CoreTools::SYSTEM_CONCATENATOR(subclassIndex,SubclassSmartPointer)<SubClass, BaseClass>::SubclassType& \
        CoreTools::SYSTEM_CONCATENATOR(subclassIndex,SubclassSmartPointer)<SubClass, BaseClass>::operator* () const { CORE_TOOLS_CLASS_IS_VALID_CONST_9; return *GetData(); } \
        template <typename SubClass, typename BaseClass> const typename CoreTools::SYSTEM_CONCATENATOR(subclassIndex,SubclassSmartPointer)<SubClass, BaseClass>::SubclassType* \
        CoreTools::SYSTEM_CONCATENATOR(subclassIndex,SubclassSmartPointer)<SubClass, BaseClass>::operator-> () const \
        { CORE_TOOLS_CLASS_IS_VALID_CONST_9; return GetData(); } template <typename SubClass, typename BaseClass> \
		typename CoreTools::SYSTEM_CONCATENATOR(subclassIndex,SubclassSmartPointer)<SubClass, BaseClass>::SubclassType* \
        CoreTools::SYSTEM_CONCATENATOR(subclassIndex,SubclassSmartPointer)<SubClass, BaseClass>::GetData() { CORE_TOOLS_CLASS_IS_VALID_9; \
         return boost::polymorphic_downcast<SubclassType*>(ParentType::GetData()); } \
		template <typename SubClass, typename BaseClass> typename CoreTools::SYSTEM_CONCATENATOR(subclassIndex,SubclassSmartPointer)<SubClass, BaseClass>::SubclassType& \
        CoreTools::SYSTEM_CONCATENATOR(subclassIndex,SubclassSmartPointer)<SubClass, BaseClass>::operator* () { CORE_TOOLS_CLASS_IS_VALID_9; return *GetData(); } \
        template <typename SubClass, typename BaseClass> typename CoreTools::SYSTEM_CONCATENATOR(subclassIndex,SubclassSmartPointer)<SubClass, BaseClass>:: SubclassType* \
        CoreTools::SYSTEM_CONCATENATOR(subclassIndex,SubclassSmartPointer)<SubClass, BaseClass>::operator-> () { CORE_TOOLS_CLASS_IS_VALID_9; return GetData(); } \
        template <typename SubClass, typename BaseClass> typename CoreTools::SYSTEM_CONCATENATOR(subclassIndex,SubclassSmartPointer)<SubClass, BaseClass>::ConstType \
	    CoreTools::SYSTEM_CONCATENATOR(subclassIndex,SubclassSmartPointer)<SubClass, BaseClass>::GetConstSmartPointer() const { \
	    static_assert((boost::is_same<ConstType::IsConstType, CoreTools::TrueType>::value), "ConstType is const_type"); \
     	CORE_TOOLS_CLASS_IS_VALID_CONST_9;  return ConstType(GetData()); } template <typename SubClass, typename BaseClass> \
	    CoreTools::SYSTEM_CONCATENATOR(subclassIndex,SubclassSmartPointer)<SubClass, BaseClass>::operator ConstType() const { \
		static_assert((boost::is_same<ConstType::IsConstType, CoreTools::TrueType>::value), "ConstType is const_type"); \
        CORE_TOOLS_CLASS_IS_VALID_CONST_9;  return GetConstSmartPointer(); }

#endif // CORE_TOOLS_HELPER_THIRD_SUBCLASS_SMART_PIINTER_MACRO_H
