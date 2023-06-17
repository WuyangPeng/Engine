///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:43)

#ifndef CORE_TOOLS_UNIT_TEST_SUITE_ENGINE_TESTING_NAME_H
#define CORE_TOOLS_UNIT_TEST_SUITE_ENGINE_TESTING_NAME_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/UserMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

#include <vector>

FRAMEWORK_NON_COPY_EXPORT_IMPL(EngineTestingNameImpl);

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE EngineTestingName
    {
    public:
        using String = System::String;
        NON_COPY_TYPE_DECLARE(EngineTestingName);

    public:
        explicit EngineTestingName(const String& endName);

        CLASS_INVARIANT_DECLARE;

        void PrintSelect(CoreTools::OStreamShared stream);
        NODISCARD bool IsSelectValid(int select) const;
        NODISCARD String GetEngineTestingName(int select) const;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_UNIT_TEST_SUITE_ENGINE_TESTING_NAME_H