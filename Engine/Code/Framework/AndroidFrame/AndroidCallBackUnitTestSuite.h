// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/08/01 13:23)

#ifndef FRAMEWORK_ANDROID_FRAME_ANDROID_CALL_BACK_UNIT_TEST_SUITE_H
#define FRAMEWORK_ANDROID_FRAME_ANDROID_CALL_BACK_UNIT_TEST_SUITE_H

#include "Framework/FrameworkDll.h"

#include "AndroidCallBackInterface.h"
#include "AndroidProcess.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>

namespace CoreTools
{
	class Suite;
	class UnitTestComposite;
}

FRAMEWORK_EXPORT_SHARED_PTR(AndroidCallBackUnitTestSuiteImpl);
FRAMEWORK_EXPORT_SHARED_PTR(WindowMessageUnitTestSuiteOsPtr);
EXPORT_NONCOPYABLE_CLASS(FRAMEWORK);

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE AndroidCallBackUnitTestSuite :	public AndroidCallBackInterface, private boost::noncopyable
	{
	public:
		typedef CoreTools::NonCopyClasses ClassShareType;
		typedef AndroidCallBackUnitTestSuite ClassType;
		typedef AndroidCallBackInterface ParentType;
		typedef AndroidCallBackUnitTestSuiteImpl ImplType;
		typedef WindowMessageUnitTestSuiteOsPtr OsPtrType;
		typedef CoreTools::Suite Suite;
		typedef std::shared_ptr<CoreTools::UnitTestComposite> UnitTestPtr;

	public:
		AndroidCallBackUnitTestSuite();
		virtual ~AndroidCallBackUnitTestSuite();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual bool Initialize();

		virtual int KeyDownMessage(struct AndroidApp* state,
			                           AndroidInputEvent* event);

		virtual void Display(struct AndroidApp* state,int64_t timeDelta);

		int GetPassedNumber() const;

		void AddTest(const std::string& suiteName,Suite& suite, 
			         const std::string& testName,const UnitTestPtr& unitTest);

	protected:
		std::ostream* GetOStream() const;

		void DoAddSuite(const Suite& suite);

		// 子类初始化必须调用。
		void GenerateSuite();

		bool IsPrintRun() const;

	private:
		typedef std::shared_ptr<ImplType> AndroidCallBackUnitTestSuiteImplPtr;
		typedef std::shared_ptr<OsPtrType> OsPtrTypePtr;

	private:
		virtual void AddSuite() = 0;
		virtual std::string GetSuiteName() const = 0;

		bool AddSuiteOnInitialize();
		void RunUnitTest();
		void ResetTestData();

	private:
		OsPtrTypePtr m_OsPtrTypePtr;
		AndroidCallBackUnitTestSuiteImplPtr m_Impl;
		bool m_IsInit;
	};

	using AndroidProcessUnitTestSuite = AndroidProcess<AndroidCallBackUnitTestSuite>;
}

#endif // FRAMEWORK_ANDROID_FRAME_ANDROID_CALL_BACK_UNIT_TEST_SUITE_H
