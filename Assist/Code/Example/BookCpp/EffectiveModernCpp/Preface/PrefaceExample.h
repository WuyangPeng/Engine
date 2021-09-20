///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.2 (2021/08/28 9:37)

#ifndef EFFECTIVE_MODERN_CPP_PREFACE_PREFACE_EXAMPLE_H
#define EFFECTIVE_MODERN_CPP_PREFACE_PREFACE_EXAMPLE_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Preface
        {
            class EFFECTIVE_MODERN_CPP_DEFAULT_DECLARE PrefaceExample final
            {
            public:
                using ClassType = PrefaceExample;

            public:
                CLASS_INVARIANT_DECLARE;

            public:
                PrefaceExample() noexcept;

                void ProcessValsTest() const noexcept;
                void SomeFuncTest() const noexcept;
                void MatrixTest() const noexcept;
                NODISCARD bool DeclarationTest() const noexcept;
            };
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_PREFACE_PREFACE_EXAMPLE_H
