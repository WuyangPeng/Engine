// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 10:47)

#ifndef FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_UNIT_TEST_SUITE_H
#define FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_UNIT_TEST_SUITE_H

#include "Framework/FrameworkDll.h"

#include "WindowMessageInterface.h"
#include "WindowProcessHandleDetail.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/UnitTestSuite/OStreamShared.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

FRAMEWORK_EXPORT_SHARED_PTR(WindowMessageUnitTestSuiteImpl);
FRAMEWORK_EXPORT_SHARED_PTR(WindowMessageUnitTestSuiteStream);

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE WindowMessageUnitTestSuite : public WindowMessageInterface
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(WindowMessageUnitTestSuite);
		using ParentType = WindowMessageInterface;
		using StreamType = WindowMessageUnitTestSuiteStream;
		using Suite = CoreTools::Suite;
		using OStreamShared = CoreTools::OStreamShared;
		using UnitTestPtr = std::shared_ptr<CoreTools::UnitTestComposite>;

	public:
		WindowMessageUnitTestSuite(int64_t delta, const std::string& suiteName);

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		int GetPassedNumber() const noexcept;

		LResult CreateMessage(HWnd hwnd, WParam wParam, LParam lParam) override;
		LResult KeyDownMessage(HWnd hwnd, WParam wParam, LParam lParam) override;
		void Display(HWnd hwnd, int64_t timeDelta) override;

	protected:
		bool IsPrintRun() const noexcept;
		OStreamShared GetStreamShared() noexcept;
		void AddSuite(const Suite& suite);

		void AddTest(const std::string& suiteName, Suite& suite, const std::string& testName, const UnitTestPtr& unitTest);

		template<typename TestType, typename... Types>
		void AddTest(Suite& suite, const std::string& suiteName, const std::string& testName, Types&&... args);

		Suite GenerateSuite(const std::string& name);

	private:
		using StreamSharedPtr = std::shared_ptr<StreamType>;

	private:	 
		virtual void InitSuite() = 0;

		LResult AddSuiteOnCreateMessage(HWnd hwnd, WParam wParam, LParam lParam);

	private:
		StreamSharedPtr m_Stream;
		IMPL_TYPE_DECLARE(WindowMessageUnitTestSuite);
	};

	using WindowProcessUnitTestSuite = WindowProcessHandle<WindowMessageUnitTestSuite>;
}

#endif // FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_UNIT_TEST_SUITE_H
