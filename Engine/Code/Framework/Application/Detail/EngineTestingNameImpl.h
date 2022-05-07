///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/05 19:13)

#ifndef CORE_TOOLS_UNIT_TEST_SUITE_ENGINE_TESTING_NAME_IMPL_H
#define CORE_TOOLS_UNIT_TEST_SUITE_ENGINE_TESTING_NAME_IMPL_H

#include "Framework/FrameworkDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/UserMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

#include <vector>

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE EngineTestingNameImpl
    {
    public:
        using ClassType = EngineTestingNameImpl;
        using String = System::String;
        using OStreamShared = CoreTools::OStreamShared;

    public:
        explicit EngineTestingNameImpl(const String& endName);

        CLASS_INVARIANT_DECLARE;

        void PrintSelect(OStreamShared stream);
        NODISCARD bool IsSelectValid(int select) const;
        NODISCARD String GetEngineTestingName(int select) const;

    private:
        using TestingNameContainer = std::vector<String>;

    private:
        NODISCARD static std::string GetProjectTestingName();
        NODISCARD static TestingNameContainer GenerateEngineTestingName(const String& endName);

    private:
        TestingNameContainer container;
    };
}

#endif  // CORE_TOOLS_UNIT_TEST_SUITE_ENGINE_TESTING_NAME_IMPL_H