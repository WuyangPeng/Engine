/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 15:24)

#ifndef CORE_TOOLS_UNIT_TEST_SUITE_ENGINE_TESTING_NAME_H
#define CORE_TOOLS_UNIT_TEST_SUITE_ENGINE_TESTING_NAME_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/UserMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

FRAMEWORK_NON_COPY_EXPORT_IMPL(EngineTestingNameImpl);

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE EngineTestingName
    {
    public:
        NON_COPY_TYPE_DECLARE(EngineTestingName);

        using String = System::String;
        using OStreamShared = CoreTools::OStreamShared;

    public:
        explicit EngineTestingName(const String& endName);

        CLASS_INVARIANT_DECLARE;

        void PrintSelect(const OStreamShared& stream);
        NODISCARD bool IsSelectValid(int select) const;
        NODISCARD String GetEngineTestingName(int select) const;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_UNIT_TEST_SUITE_ENGINE_TESTING_NAME_H