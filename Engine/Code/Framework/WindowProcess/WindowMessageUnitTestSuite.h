// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/08/01 09:59)

#ifndef FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_UNIT_TEST_SUITE_H
#define FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_UNIT_TEST_SUITE_H

#include "Framework/FrameworkDll.h"

#include "WindowMessageInterface.h"
#include "WindowProcessHandleDetail.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>

namespace CoreTools
{
	class Suite;
	class UnitTestComposite;
}

FRAMEWORK_EXPORT_SHARED_PTR(WindowMessageUnitTestSuiteImpl);
FRAMEWORK_EXPORT_SHARED_PTR(WindowMessageUnitTestSuiteOsPtr);
EXPORT_NONCOPYABLE_CLASS(FRAMEWORK);

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE WindowMessageUnitTestSuite : public WindowMessageInterface, private boost::noncopyable
	{
	public:	
		using ClassShareType = CoreTools::NonCopyClasses;
		using ClassType = WindowMessageUnitTestSuite;
		using ParentType = WindowMessageInterface;
		using ImplType = WindowMessageUnitTestSuiteImpl;
		using OsPtrType = WindowMessageUnitTestSuiteOsPtr;
		using Suite = CoreTools::Suite;
		using UnitTestPtr = std::shared_ptr<CoreTools::UnitTestComposite>;

	public:
		WindowMessageUnitTestSuite();		
		virtual ~WindowMessageUnitTestSuite();
 
		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;	 

		virtual LResult CreateMessage(HWnd hwnd,WParam wParam,LParam lParam);	
		virtual LResult KeyDownMessage(HWnd hwnd,WParam wParam,LParam lParam);
		virtual void Display(HWnd hwnd,int64_t timeDelta);

		int GetPassedNumber() const;

	protected:	
		std::ostream* GetOStream();		

		void DoAddSuite(const Suite& suite);	

		// 子类初始化必须调用。
		void GenerateSuite();

		void AddTest(const std::string& suiteName, Suite& suite, const std::string& testName, const UnitTestPtr& unitTest);
		
		bool IsPrintRun() const;

	private:
		using WindowMessageUnitTestSuiteImplPtr = std::shared_ptr<ImplType>;
		using OsPtrTypePtr = std::shared_ptr<OsPtrType>;

	private:	
		virtual void AddSuite() = 0;
		virtual std::string GetSuiteName() const = 0;	

		LResult AddSuiteOnCreateMessage( HWnd hwnd, WParam wParam, LParam lParam );
		void RunUnitTest();
		void ResetTestData();

	private:		
		OsPtrTypePtr m_OsPtrTypePtr;
		WindowMessageUnitTestSuiteImplPtr m_Impl;
	};

	using WindowProcessUnitTestSuite = WindowProcessHandle<WindowMessageUnitTestSuite>;
}

#define WINDOW_MESSAGE_UNIT_TEST_SUITE_SUBCLASS_DECLARE(className) \
	    using ClassType = className;\
	    using ParentType = WindowMessageUnitTestSuite;\
	    public: className(); virtual ~className()

#define WINDOW_MESSAGE_UNIT_TEST_SUITE_SUBCLASS_DEFINE(namespaceName, \
	    className) namespaceName::className::className \
		() :ParentType{} { GenerateSuite(); FRAMEWORK_SELF_CLASS_IS_VALID_0; } \
		namespaceName::className::~className() { FRAMEWORK_SELF_CLASS_IS_VALID_0; }

#endif // FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_UNIT_TEST_SUITE_H
