/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/14 12:05)

#ifndef CORE_TOOLS_HELPER_SUITE_PROPERTIES_H
#define CORE_TOOLS_HELPER_SUITE_PROPERTIES_H

#include "CoreTools/Helper/PropertiesMacro.h"
#include "CoreTools/Helper/UserMacro.h"
#include "CoreTools/Properties/MethodPropertyGetDetail.h"
#include "CoreTools/Properties/MethodPropertyGetSetDetail.h"
#include "CoreTools/Properties/MethodPropertySetDetail.h"
#include "CoreTools/Properties/PropertyDetail.h"

#include <string>

/// 测试PropertiesMacroTesting所需
namespace CoreTools
{
    class Properties final
    {
    public:
        using ClassType = Properties;

    public:
        Properties() noexcept;

        CLASS_INVARIANT_DECLARE;

    private:
        NODISCARD const int& GetValue0() const noexcept;
        NODISCARD int GetValue1() const noexcept;
        void SetValue2(const std::string& value);
        NODISCARD uint32_t GetValue3() const noexcept;
        void SetValue3(const uint32_t& value) noexcept;
        NODISCARD int GetValue4() const noexcept;
        void SetValue4(int value) noexcept;
        NODISCARD const std::string& GetValue5() const noexcept;
        void SetValue5(const std::string& value);

    public:
        NODISCARD std::string GetValue2() const;
        NODISCARD const std::string& GetValue6() const noexcept;
        void SetValue7(const std::string& value);
        NODISCARD std::string GetValue7() const;
        NODISCARD std::string GetValue8() const;
        void SetValue8(const std::string& value);

        TCRE_METHOD_PROPERTY_GET(int, const int&, ClassType, GetValue0, Value0, true);
        TCRE_METHOD_PROPERTY_GET(int, int, ClassType, GetValue1, Value1, true);
        TCRE_METHOD_PROPERTY_SET(std::string, const std::string&, ClassType, SetValue2, Value2, true);
        TCRE_METHOD_PROPERTY_GET_SET(uint32_t, uint32_t, const uint32_t&, ClassType, GetValue3, SetValue3, Value3, true);
        TCRE_DECLARE_PROPERTY(ClassType, int, int, Value4, SetValue4, GetValue4);
        TCRE_DECLARE_PROPERTY(ClassType, std::string, const std::string&, Value5, SetValue5, GetValue5);
        TCRE_PROPERTY_READ(std::string, Value6, GetValue6);
        TCRE_PROPERTY_WRITE(std::string, Value8, SetValue7);
        TCRE_PROPERTY_READ_WRITE(std::string, Value9, GetValue8, SetValue8);

    private:
        int value0;
        std::string value2;
        uint32_t value3;
        int value4;
        std::string value5;
        std::string value6;
        std::string value7;
        std::string value8;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_PROPERTIES_H