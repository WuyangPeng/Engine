// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 13:42)

#ifndef CORE_TOOLS_UNIT_TEST_SUITE_ENGINE_TESTING_NAME_H
#define CORE_TOOLS_UNIT_TEST_SUITE_ENGINE_TESTING_NAME_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/UserMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

#include <boost/noncopyable.hpp>
#include <vector>

FRAMEWORK_EXPORT_SHARED_PTR(EngineTestingNameImpl);
EXPORT_NONCOPYABLE_CLASS(FRAMEWORK);

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE EngineTestingName : private boost::noncopyable
	{
	public:
		using String = System::String;
		NON_COPY_CLASSES_TYPE_DECLARE(EngineTestingName);

	public:
		explicit EngineTestingName(const String& endName);

		CLASS_INVARIANT_DECLARE;

		void PrintSelect(CoreTools::OStreamShared stream);
		bool IsSelectValid(int select) const;
		const String GetEngineTestingName(int select) const;

	private:
		IMPL_TYPE_DECLARE(EngineTestingName);
	};
}

#endif // CORE_TOOLS_UNIT_TEST_SUITE_ENGINE_TESTING_NAME_H