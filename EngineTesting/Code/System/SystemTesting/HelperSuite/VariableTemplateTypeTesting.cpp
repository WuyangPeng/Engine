/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/08 16:14)

#include "VariableTemplateTypeTesting.h"
#include "System/Helper/VariableTemplateType.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#define OPEN_VARIABLE_TEMPLATE_COUNT_ERROR
#define OPEN_VARIABLE_TEMPLATE_IS_SCALAR_ERROR

#undef OPEN_VARIABLE_TEMPLATE_COUNT_ERROR
#undef OPEN_VARIABLE_TEMPLATE_IS_SCALAR_ERROR

#include <string>

System::VariableTemplateTypeTesting::VariableTemplateTypeTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, VariableTemplateTypeTesting)

void System::VariableTemplateTypeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::VariableTemplateTypeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(VariableTemplateTypeCountTest);
    ASSERT_NOT_THROW_EXCEPTION_0(VariableTemplateTypeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IsScalarTest);
}

void System::VariableTemplateTypeTesting::VariableTemplateTypeCountTest() const noexcept
{
    static_assert(VariableTemplateType<int, uint16_t>::count == 2);
    static_assert(VariableTemplateType<int, uint16_t, bool, long>::count == 4);
}

void System::VariableTemplateTypeTesting::VariableTemplateTypeTest() const noexcept
{
    static_assert(std::is_same_v<VariableTemplateType<int, uint16_t>::Element<0>::Type, int>);
    static_assert(std::is_same_v<VariableTemplateType<int, uint16_t>::Element<1>::Type, uint16_t>);
    static_assert(std::is_same_v<VariableTemplateType<int, uint16_t>::ElementType<0>, int>);
    static_assert(std::is_same_v<VariableTemplateType<int, uint16_t>::ElementType<1>, uint16_t>);

    static_assert(std::is_same_v<VariableTemplateType<int, uint16_t, bool, long>::Element<0>::Type, int>);
    static_assert(std::is_same_v<VariableTemplateType<int, uint16_t, bool, long>::Element<1>::Type, uint16_t>);
    static_assert(std::is_same_v<VariableTemplateType<int, uint16_t, bool, long>::Element<2>::Type, bool>);
    static_assert(std::is_same_v<VariableTemplateType<int, uint16_t, bool, long>::Element<3>::Type, long>);
    static_assert(std::is_same_v<VariableTemplateType<int, uint16_t, bool, long>::ElementType<0>, int>);
    static_assert(std::is_same_v<VariableTemplateType<int, uint16_t, bool, long>::ElementType<1>, uint16_t>);
    static_assert(std::is_same_v<VariableTemplateType<int, uint16_t, bool, long>::ElementType<2>, bool>);
    static_assert(std::is_same_v<VariableTemplateType<int, uint16_t, bool, long>::ElementType<3>, long>);

#ifdef OPEN_VARIABLE_TEMPLATE_COUNT_ERROR

    VariableTemplateType<int, uint16_t, bool, long>::Element<4>::Type;

#endif  // OPEN_VARIABLE_TEMPLATE_COUNT_ERROR
}

void System::VariableTemplateTypeTesting::IsScalarTest() const noexcept
{
    static_assert(std::is_same_v<IsScalar<int, uint16_t>::Type, std::true_type>);
    static_assert(std::is_same_v<IsScalar<int, uint16_t, bool, long>::Type, std::true_type>);
    static_assert(std::is_same_v<IsScalarType<int, uint64_t>, std::true_type>);
    static_assert(std::is_same_v<IsScalarType<int, uint16_t, bool, int32_t>, std::true_type>);

#ifdef OPEN_VARIABLE_TEMPLATE_IS_SCALAR_ERROR

    IsScalar<int, uint16_t, bool, long, std::string>::Type;

#endif  // OPEN_VARIABLE_TEMPLATE_IS_SCALAR_ERROR
}
