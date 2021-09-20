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
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include <boost/noncopyable.hpp>
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
        ~EngineTestingName() noexcept = default;
        EngineTestingName(const EngineTestingName&) noexcept = delete;
        EngineTestingName& operator=(const EngineTestingName&) noexcept = delete;
        EngineTestingName(EngineTestingName&&) noexcept = delete;
        EngineTestingName& operator=(EngineTestingName&&) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        void PrintSelect(CoreTools::OStreamShared stream);
        bool IsSelectValid(int select) const;
        const String GetEngineTestingName(int select) const;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_UNIT_TEST_SUITE_ENGINE_TESTING_NAME_H