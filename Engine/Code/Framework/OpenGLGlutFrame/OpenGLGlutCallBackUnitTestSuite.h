// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/08/01 13:18)

#ifndef FRAMEWORK_OPENGL_GLUT_FRAME_WINDOW_OPENGL_GLUT_CALL_BACK_UNIT_TEST_SUITE_H
#define FRAMEWORK_OPENGL_GLUT_FRAME_WINDOW_OPENGL_GLUT_CALL_BACK_UNIT_TEST_SUITE_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "OpenGLGlutCallBackInterface.h"
#include "OpenGLGlutProcess.h"
#include "CoreTools/UnitTestSuite/UnitTestComposite.h"

#include <boost/noncopyable.hpp>

namespace CoreTools
{
	class Suite;
}

FRAMEWORK_EXPORT_SHARED_PTR(OpenGLGlutCallBackUnitTestSuiteImpl);
FRAMEWORK_EXPORT_SHARED_PTR(WindowMessageUnitTestSuiteOsPtr);
EXPORT_NONCOPYABLE_CLASS(FRAMEWORK);

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE OpenGLGlutCallBackUnitTestSuite : 
		public OpenGLGlutCallBackInterface, private boost::noncopyable
	{
	public:	
		typedef CoreTools::NonCopyClasses ClassShareType;
		typedef OpenGLGlutCallBackUnitTestSuite ClassType;
		typedef OpenGLGlutCallBackInterface ParentType;
		typedef OpenGLGlutCallBackUnitTestSuiteImpl ImplType;
		typedef WindowMessageUnitTestSuiteOsPtr OsPtrType;
		typedef CoreTools::Suite Suite;
		typedef std::shared_ptr<CoreTools::UnitTestComposite> UnitTestPtr;

	public:
		OpenGLGlutCallBackUnitTestSuite();		
		virtual ~OpenGLGlutCallBackUnitTestSuite();
	
		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual bool Initialize();
	
		virtual bool SpecialKeysDown(int key,int xCoordinate,int yCoordinate);

		virtual bool IdleFunction();

		int GetPassedNumber() const;

	protected:	
		std::ostream* GetOStream();		

		void DoAddSuite(const Suite& suite);	

		// 子类初始化必须调用。
		void GenerateSuite();

		void AddTest(const std::string& suiteName,Suite& suite, 
			         const std::string& testName,const UnitTestPtr& unitTest);

		bool IsPrintRun() const;

	private:
		typedef std::shared_ptr<ImplType> OpenGLGlutCallBackUnitTestSuiteImplPtr;
		typedef std::shared_ptr<OsPtrType> OsPtrTypePtr;

	private:	
		virtual void AddSuite() = 0;
		virtual std::string GetSuiteName() const = 0;	

		bool AddSuiteOnInitialize();
		void RunUnitTest();
		void ResetTestData();

	private:		
		OsPtrTypePtr m_OsPtrTypePtr;
		OpenGLGlutCallBackUnitTestSuiteImplPtr m_Impl;
	    bool m_IsInit;
	};

	using OpenGLGlutProcessUnitTestSuite = OpenGLGlutProcess<OpenGLGlutCallBackUnitTestSuite>;
}

#endif // FRAMEWORK_OPENGL_GLUT_FRAME_WINDOW_OPENGL_GLUT_CALL_BACK_UNIT_TEST_SUITE_H
