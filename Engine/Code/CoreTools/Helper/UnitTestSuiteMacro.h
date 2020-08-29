// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/18 10:58)

#ifndef CORE_TOOLS_HELPER_UNIT_TEST_SUITE_MACRO_H
#define CORE_TOOLS_HELPER_UNIT_TEST_SUITE_MACRO_H
 
// 单元测试框架所需要的宏
#include "CoreTools/UnitTestSuite/Suite.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#define UNIT_TEST_SUBCLASS_DECLARE_USE_PARENT_TYPE(className,parentType) \
		using ClassType = className;using ParentType = parentType; explicit className(const CoreTools::OStreamShared& osPtr); ~className()

#define UNIT_TEST_SUBCLASS_DECLARE(className) \
		UNIT_TEST_SUBCLASS_DECLARE_USE_PARENT_TYPE(className,UnitTest)

#define UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(className) \
		UNIT_TEST_SUBCLASS_DECLARE(className);CLASS_INVARIANT_OVERRIDE_DECLARE

#define UNIT_TEST_SUBCLASS_COMPLETE_DECLARE_USE_PARENT_TYPE(className,parentType) \
		UNIT_TEST_SUBCLASS_DECLARE_USE_PARENT_TYPE(className,parentType);CLASS_INVARIANT_OVERRIDE_DECLARE

#define UNIT_TEST_SUBCLASS_COMPLETE_DECLARE_USE_TESTING_TYPE(className) \
	    private: using TestingType = className;	TestingType SYSTEM_CONCATENATOR(m_,className); \
        public: UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(SYSTEM_CONCATENATOR(className,Testing))

#define UNIT_TEST_SUBCLASS_COMPLETE_DECLARE_USE_TESTING_TYPE_SHARED_PTR(className) \
	    private: using TestingType = className;using TestingSharedPtr = std::shared_ptr<TestingType>; \
        TestingSharedPtr SYSTEM_CONCATENATOR(m_,className); \
        public: UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(SYSTEM_CONCATENATOR(className,Testing))

#define UNIT_TEST_SUBCLASS_COMPLETE_DECLARE_USE_PARENT_TYPE_AND_TESTING_TYPE_SHARED_PTR(className,parentType) \
	    private: using TestingType = className;using TestingSharedPtr = std::shared_ptr<TestingType>; \
        TestingSharedPtr SYSTEM_CONCATENATOR(m_,className); \
		public: UNIT_TEST_SUBCLASS_COMPLETE_DECLARE_USE_PARENT_TYPE(SYSTEM_CONCATENATOR(className,Testing),parentType)

#define UNIT_TEST_SUBCLASS_DESTRUCTOR_DEFINE(namespaceName,className) \
	    namespaceName::className::~className() { SELF_CLASS_IS_VALID_0; }

#define UNIT_TEST_SUBCLASS_CONSTRUCTOR_DEFINE(namespaceName,className) \
	    namespaceName::className::className(const CoreTools::OStreamShared& osPtr) :ParentType{ osPtr } { SELF_CLASS_IS_VALID_0; } 

#define UNIT_TEST_SUBCLASS_DEFINE(namespaceName,className) \
	    UNIT_TEST_SUBCLASS_CONSTRUCTOR_DEFINE(namespaceName,className) \
        UNIT_TEST_SUBCLASS_DESTRUCTOR_DEFINE(namespaceName,className)

#define UNIT_TEST_DO_RUN_UNIT_TEST_DEFINE(namespaceName,className) \
	    void namespaceName::className::DoRunUnitTest() { CLASS_IS_VALID_0; ASSERT_NOT_THROW_EXCEPTION_0(MainTest); }

#define UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(namespaceName,className) \
		UNIT_TEST_SUBCLASS_DEFINE(namespaceName, className) CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(namespaceName, className) \
		UNIT_TEST_DO_RUN_UNIT_TEST_DEFINE(namespaceName, className)    

#define UNIT_TEST_SUBCLASS_WITHOUT_CONSTRUCTOR_DEFINE(namespaceName,className) \
		UNIT_TEST_SUBCLASS_DESTRUCTOR_DEFINE(namespaceName, className) CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(namespaceName, className) \
		UNIT_TEST_DO_RUN_UNIT_TEST_DEFINE(namespaceName, className) 

#define UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(namespaceName,className) \
	    UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(namespaceName, SYSTEM_CONCATENATOR(className,Testing)) \
		namespace namespaceName { using TestingType = className; }

#define UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_PARAMETER_0(namespaceName,className) \
		namespaceName::SYSTEM_CONCATENATOR(className,Testing)::SYSTEM_CONCATENATOR(className,Testing)(const CoreTools::OStreamShared& osPtr) \
		:ParentType{ osPtr },SYSTEM_CONCATENATOR(m_,className){} { SELF_CLASS_IS_VALID_0; } \
		namespaceName::SYSTEM_CONCATENATOR(className,Testing)::~SYSTEM_CONCATENATOR(className,Testing)() { SELF_CLASS_IS_VALID_0; } \
		CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(namespaceName, SYSTEM_CONCATENATOR(className,Testing)) \
		UNIT_TEST_DO_RUN_UNIT_TEST_DEFINE(namespaceName,SYSTEM_CONCATENATOR(className,Testing))     	 

#define UNIT_TEST_DO_RUN_DEFINE(namespaceName,className,suiteName) \
	    int namespaceName::className::DoRun() { m_SuitePtr = std::make_shared<Suite>("【"##suiteName##"】单元测试套件",GetStreamShared(),IsPrintRun()); \
	    AddSuite();	m_SuitePtr->RunUnitTest(); SystemPause(); m_SuitePtr->PrintReport(); SystemPause(); return m_SuitePtr->GetFailedNumber(); }

#define ADD_TEST_BEGIN(suite,suiteName) \
	    const auto printRun = IsPrintRun(); Suite suite("【"##suiteName##"组件】单元测试套件",GetStreamShared(),printRun)

#define ADD_TEST(suite,testing) \
	    AddTest<testing>((suite),(#suite),(#testing))

#define ADD_TEST_USE_PARAMETER_1(suite,testing,parameter) \
	    AddTest<testing>((suite),(#suite),(#testing),(parameter))

#define ADD_TEST_USE_PARAMETER_2(suite,testing,parameter1,parameter2) \
	    AddTest<testing>((suite),(#suite),(#testing),(parameter1),(parameter2))

#define SUITE_ADD_TEST(suite,testing) \
	    AddTest((#suite),(suite),(#testing),(std::make_shared<testing>(GetStreamShared())))

#define SUITE_ADD_TEST_USE_PARAMETER_1(suite,testing,parameter) \
	    AddTest((#suite),(suite),(#testing),(std::make_shared<testing>(parameter,GetStreamShared())))

#define SUITE_ADD_TEST_USE_PARAMETER_2(suite,testing,parameter1,parameter2) \
	    AddTest((#suite),(suite),(#testing),(std::make_shared<testing>(parameter1,parameter2,GetStreamShared())))

#define ADD_TEST_END(suite) \
	    m_SuitePtr->AddSuite(suite)

#define CMAIN_FUNCTION_TESTING_HELPER_SUBCLASS_DECLARE(className) \
	    using ClassType = className;using ParentType = CMainFunctionTestingHelper; \
		using Suite = CoreTools::Suite;	public:	className(int argc,char** argv); ~className()    

#define CMAIN_FUNCTION_TESTING_HELPER_SUBCLASS_COMPLETE_DECLARE(className) \
		CMAIN_FUNCTION_TESTING_HELPER_SUBCLASS_DECLARE(className); CLASS_INVARIANT_OVERRIDE_DECLARE

#define CMAIN_FUNCTION_HELPER_SUBCLASS_SUITE_PTR_DECLARE \
		using SuitePtr = std::shared_ptr<Suite>; private: SuitePtr m_SuitePtr

#define CMAIN_FUNCTION_HELPER_SUBCLASS_DEFINE(namespaceName, className) \
        namespaceName::className::className( int argc,char** argv ) :ParentType{ argc,argv },m_SuitePtr{} \
		{ SELF_CLASS_IS_VALID_0; } namespaceName::className::~className() { SELF_CLASS_IS_VALID_0; }

#define CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(namespaceName,className,testName) \
	    CMAIN_FUNCTION_HELPER_SUBCLASS_DEFINE(namespaceName, className) CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(namespaceName, className) \
		UNIT_TEST_DO_RUN_DEFINE(namespaceName,className,testName)

#endif // CORE_TOOLS_HELPER_UNIT_TEST_SUITE_MACRO_H

