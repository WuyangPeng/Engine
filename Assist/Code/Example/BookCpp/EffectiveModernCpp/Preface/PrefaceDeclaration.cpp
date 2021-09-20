///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.2 (2021/08/28 9:37)

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
                // ������
                int x;

                // �ඨ��
                class Widget final
                {
                public:
                    NODISCARD int Size() const noexcept
                    {
                        return 0;
                    }
                };

                // ��������
                NODISCARD bool Func(const Widget& w) noexcept
                {
                    return w.Size() < 10;
                }

                // �޶��������ö�ٶ���
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