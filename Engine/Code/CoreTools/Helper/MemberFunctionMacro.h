// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/18 10:22)

// ��Ա��������Ҫ�ĺ�
#ifndef CORE_TOOLS_HELPER_MEMBER_FUNCTION_MACRO_H
#define CORE_TOOLS_HELPER_MEMBER_FUNCTION_MACRO_H

#include <utility>
#include <type_traits>

#define IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(namespaceName,className,functionName,returnType) \
		returnType namespaceName::className::functionName() const { CLASS_IS_VALID_CONST_0; return m_Impl->functionName(); }

#define IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(namespaceName,className,functionName,parameterType,returnType) \
	    returnType namespaceName::className::functionName(const parameterType& parameter) const \
		{ CLASS_IS_VALID_CONST_0; return m_Impl->functionName(parameter); }

#define IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(namespaceName,className,functionName,parameterType,returnType) \
		returnType namespaceName::className::functionName(parameterType parameter) const \
        { CLASS_IS_VALID_CONST_0; return m_Impl->functionName(parameter); }

#define IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CP(namespaceName,className,functionName,parameterType,returnType) \
		returnType namespaceName::className::functionName(const parameterType* parameter) const \
		{ CLASS_IS_VALID_CONST_0; return m_Impl->functionName(parameter); }

#define IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(namespaceName,className,functionName,returnType) \
		returnType namespaceName::className::functionName() const noexcept { \
        CLASS_IS_VALID_CONST_0; return m_Impl->functionName(); }

#define IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(namespaceName,className,functionName,parameterType,returnType) \
	    returnType namespaceName::className::functionName(const parameterType& parameter) const noexcept { \
        CLASS_IS_VALID_CONST_0; return m_Impl->functionName(parameter); }

#define IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(namespaceName,className,functionName,parameterType,returnType) \
		returnType namespaceName::className::functionName(parameterType parameter) const noexcept { \
        CLASS_IS_VALID_CONST_0; return m_Impl->functionName(parameter); }

#define IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CP_NOEXCEPT(namespaceName,className,functionName,parameterType,returnType) \
		returnType namespaceName::className::functionName(const parameterType* parameter) const noexcept { \
        CLASS_IS_VALID_CONST_0; return m_Impl->functionName(parameter); }

#define IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT \
	    static_assert(std::is_same_v<ClassShareType::NonConstMember,CoreTools::TrueType>,"Non-const member functions are forbidden"); \
        CLASS_IS_VALID_0

#define IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT \
	    static_assert(std::is_same_v<ClassShareType::NonConstCopyMember,CoreTools::TrueType>,"Non-const copy member functions are forbidden"); \
        CLASS_IS_VALID_0; Copy()

#define IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT \
	    static_assert(std::is_same_v<ClassShareType::CopyConstructor,CoreTools::TrueType>,"CopyConstructor functions are forbidden")

#define IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(namespaceName,className,functionName,returnType) \
		returnType namespaceName::className::functionName() { IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT; return m_Impl->functionName(); }

#define IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(namespaceName,className,functionName,parameterType,returnType) \
		returnType namespaceName::className::functionName(const parameterType& parameter) { \
		IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT; return m_Impl->functionName(parameter); }

#define IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(namespaceName,className,functionName,parameterType,returnType) \
		returnType namespaceName::className::functionName(parameterType parameter) { \
		IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT; return m_Impl->functionName(parameter); }

#define IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CP(namespaceName,className,functionName,parameterType,returnType) \
		returnType namespaceName::className::functionName(const parameterType* parameter) { \
		IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT; return m_Impl->functionName(parameter); }

#define IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(namespaceName,className,functionName,returnType) \
		returnType namespaceName::className::functionName() noexcept { IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT; return m_Impl->functionName(); }

#define IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(namespaceName,className,functionName,parameterType,returnType) \
		returnType namespaceName::className::functionName(const parameterType& parameter) noexcept { \
		IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT; return m_Impl->functionName(parameter); }

#define IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(namespaceName,className,functionName,parameterType,returnType) \
		returnType namespaceName::className::functionName(parameterType parameter) noexcept { \
		IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT; return m_Impl->functionName(parameter); }

#define IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CP_NOEXCEPT(namespaceName,className,functionName,parameterType,returnType) \
		returnType namespaceName::className::functionName(const parameterType* parameter) noexcept { \
		IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT; return m_Impl->functionName(parameter); }

#define IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_0(namespaceName,className,functionName,returnType) \
        returnType namespaceName::className::functionName() { \
        IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT; return m_Impl->functionName(); }

#define IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_CR(namespaceName,className,functionName,parameterType,returnType) \
		returnType namespaceName::className::functionName(const parameterType& parameter) { \
		IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT; return m_Impl->functionName(parameter); }

#define IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(namespaceName,className,functionName,parameterType,returnType) \
		returnType namespaceName::className::functionName(parameterType parameter) { \
		IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;return m_Impl->functionName(parameter); }

#define IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_CP(namespaceName,className,functionName,parameterType,returnType) \
		returnType namespaceName::className::functionName(const parameterType* parameter) \
		{ IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT; return m_Impl->functionName(parameter); }

#define OPERATOR_SQUARE_BRACKETS(returnType,index) \
	    const_cast<returnType&>(static_cast<const ClassType&>(*this)[index]);

#define OPERATOR_SQUARE_BRACKETS_TO_POINTER(returnType,index) \
	    const_cast<returnType*>(static_cast<const ClassType&>(*this)[index]);

#define NON_CONST_MEMBER_CALL_CONST_MEMBER(returnType,function) \
	    const_cast<returnType>(static_cast<const ClassType*>(this)->function())

#define COPY_CONSTRUCTION_DEFINE(namespaceName,className) \
	    namespaceName::className::className(const className& rhs):m_Impl{ std::make_shared<ImplType>(*rhs.m_Impl) } \
        { IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;SELF_CLASS_IS_VALID_0; } \
		namespaceName::className& namespaceName::className::operator=( const className& rhs ) { \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT; className temp{ rhs }; Swap(temp); return *this; } \
        void namespaceName::className::Swap( className& rhs ) noexcept { \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT; std::swap(m_Impl,rhs.m_Impl); } 

#define COPY_CONSTRUCTION_DO_NOT_USE_SWAP_DEFINE(namespaceName,className) \
	    namespaceName::className::className(const className& rhs) \
		:m_Impl{ std::make_shared<ImplType>(*rhs.m_Impl) } { IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;SELF_CLASS_IS_VALID_0; } \
		namespaceName::className& namespaceName::className::operator=( const className& rhs ) { \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT; m_Impl = std::make_shared<ImplType>(*rhs.m_Impl); return *this; }  

#define COPY_CONSTRUCTION_DEFINE_WITH_PARENT(namespaceName,className) \
	    namespaceName::className::className(const className& rhs) : ParentType{ rhs }, \
        m_Impl{ std::make_shared<ImplType>(*rhs.m_Impl) } { IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;SELF_CLASS_IS_VALID_0; } \
		namespaceName::className& namespaceName::className::operator=(const className& rhs) { \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;ParentType::operator=(rhs); m_Impl = std::make_shared<ImplType>(*rhs.m_Impl); return *this; }

#define COPY_CONSTRUCTION_CLONE_DEFINE(namespaceName,className) \
	    namespaceName::className::className(const className& rhs) : m_Impl{ rhs.m_Impl->Clone() } { IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;SELF_CLASS_IS_VALID_0; } \
		namespaceName::className& namespaceName::className::operator=(const className& rhs) { \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;m_Impl = rhs.m_Impl->Clone(); return *this; }

#define COPY_CONSTRUCTION_CLONE_DEFINE_WITH_PARENT(namespaceName,className) \
	    namespaceName::className::className(const className& rhs) : ParentType{ rhs }, m_Impl{ rhs.m_Impl->Clone() } { IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;SELF_CLASS_IS_VALID_0; } \
		namespaceName::className& namespaceName::className::operator=(const className& rhs) { \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT; ParentType::operator=(rhs); m_Impl = rhs.m_Impl->Clone(); return *this; }

#define DELAY_COPY_CONSTRUCTION_DEFINE(namespaceName,className) \
	    void namespaceName::className::Copy() { \
        static_assert((std::is_same<ClassShareType::NonConstCopyMember,CoreTools::TrueType>::value),"It is not allowed to define the Copy function used for copy delayed."); \
		CLASS_IS_VALID_0; if(m_Impl.use_count() != 1) m_Impl = std::make_shared<ImplType>(*m_Impl); }

#define DELAY_COPY_CONSTRUCTION_CLONE_DEFINE(namespaceName,className)  \
	    void namespaceName::className::Copy() {	\
        static_assert((std::is_same<ClassShareType::NonConstCopyMember,CoreTools::TrueType>::value),"It is not allowed to define the Copy function used for copy delayed."); \
		CLASS_IS_VALID_0; if(m_Impl.use_count() != 1) m_Impl = m_Impl->Clone(); }

#define DELAY_COPY_CONSTRUCTION_SHALLOW_COPY_DEFINE(namespaceName,className) \
	    namespaceName::className::className(const className& rhs) : m_Impl{ rhs.m_Impl } { IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;SELF_CLASS_IS_VALID_0; } \
		namespaceName::className& namespaceName::className::operator=(const className& rhs) { \
		IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT; SELF_CLASS_IS_VALID_0;m_Impl = rhs.m_Impl; return *this; }

#define PERFORMANCE_COPY_CONSTRUCTION_DEFINE(namespaceName,className) \
	    namespaceName::className::className(const className& rhs) : m_Impl{ rhs.m_Impl } { IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;SELF_CLASS_IS_VALID_0; } \
		namespaceName::className& namespaceName::className::operator=(const className& rhs) { \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT; SELF_CLASS_IS_VALID_0;m_Impl = rhs.m_Impl; return *this; }

#define IMPL_MOVE_OPERATOR_DEFINE(namespaceName,className) \
		namespaceName::className::className(className&& rhs) noexcept : m_Impl{ std::move(rhs.m_Impl) }{ SELF_CLASS_IS_VALID_0; } \
		namespaceName::className& namespaceName::className::operator=(className&& rhs) noexcept \
		{ CLASS_IS_VALID_0; m_Impl = std::move(rhs.m_Impl); return *this; }

#define IMPL_MOVE_OPERATOR_COMPLETE_DEFINE(namespaceName,className) \
		IMPL_MOVE_OPERATOR_DEFINE(namespaceName,className); CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(namespaceName,className);

#endif // CORE_TOOLS_HELPER_MEMBER_FUNCTION_MACRO_H
