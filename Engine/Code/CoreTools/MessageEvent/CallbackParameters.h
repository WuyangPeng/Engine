//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/26 15:18)

#ifndef CORE_TOOLS_MESSAGE_EVENT_CALLBACK_PARAMETERS_H
#define CORE_TOOLS_MESSAGE_EVENT_CALLBACK_PARAMETERS_H

#include "CoreTools/CoreToolsDll.h"

#include "ParametersInterface.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <string>

CORE_TOOLS_EXPORT_SHARED_PTR(CallbackParametersImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE CallbackParameters final
    {
    public:
        DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(CallbackParameters);
        using String = System::String;

    public:
        explicit CallbackParameters(int count = 0);

        CLASS_INVARIANT_DECLARE;

        void SetValue(int index, bool value);
        void SetValue(int index, int8_t value);
        void SetValue(int index, uint8_t value);
        void SetValue(int index, int16_t value);
        void SetValue(int index, uint16_t value);
        void SetValue(int index, int32_t value);
        void SetValue(int index, uint32_t value);
        void SetValue(int index, int64_t value);
        void SetValue(int index, uint64_t value);
        void SetValue(int index, float value);
        void SetValue(int index, double value);
        void SetValue(int index, const ParametersInterface& parameters);
        void SetValue(int index, const std::string& value);
        void SetValue(int index, const std::wstring& value);

        [[nodiscard]] bool GetBoolValue(int index) const;
        [[nodiscard]] int8_t GetInt8Value(int index) const;
        [[nodiscard]] uint8_t GetUInt8Value(int index) const;
        [[nodiscard]] int16_t GetInt16Value(int index) const;
        [[nodiscard]] uint16_t GetUInt16Value(int index) const;
        [[nodiscard]] int32_t GetInt32Value(int index) const;
        [[nodiscard]] uint32_t GetUInt32Value(int index) const;
        [[nodiscard]] int64_t GetInt64Value(int index) const;
        [[nodiscard]] uint64_t GetUInt64Value(int index) const;
        [[nodiscard]] float GetFloatValue(int index) const;
        [[nodiscard]] double GetDoubleValue(int index) const;
        [[nodiscard]] std::string GetStringValue(int index) const;
        [[nodiscard]] std::wstring GetWStringValue(int index) const;
        [[nodiscard]] String GetTStringValue(int index) const;
        [[nodiscard]] const ConstParametersInterfaceSharedPtr GetParametersInterfaceValue(int index) const;

        // 向下转型，必须保证转型成功。
        template <typename ConstSubclass>
        [[nodiscard]] std::shared_ptr<const ConstSubclass> GetParametersInterfacePolymorphicDowncast(int index) const;

        // 向下转型，失败抛出异常。
        template <typename ConstSubclass>
        [[nodiscard]] std::shared_ptr<const ConstSubclass> GetParametersInterfacePolymorphicCast(int index) const;

        [[nodiscard]] int GetContainerSize() const;

    private:
        IMPL_TYPE_DECLARE(CallbackParameters);
    };
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_CALLBACK_PARAMETERS_H
