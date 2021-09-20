///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.2 (2021/08/28 9:37)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "PrefaceDeclaration.h"
#include "System/Helper/EnumCast.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Preface
        {
            namespace Declaration
            {
                // 对象定义
                int x;

                // 类定义
                class Widget final
                {
                public:
                    NODISCARD int Size() const noexcept
                    {
                        return 0;
                    }
                };

                // 函数定义
                NODISCARD bool Func(const Widget& w) noexcept
                {
                    return w.Size() < 10;
                }

                // 限定作用域的枚举定义
                enum class Color
                {
                    Yellow,
                    Red,
                    Blue,
                };
            }

            bool WidgetDeclaration() noexcept
            {
                Declaration::x = System::EnumCastUnderlying(Declaration::Color::Yellow);

                Declaration::Widget widget{};

                return Func(widget);
            }
        }
    }
}