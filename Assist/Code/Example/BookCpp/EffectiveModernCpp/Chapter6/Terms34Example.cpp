///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.7 (2021/12/03 19:42)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms34.h"
#include "Terms34Example.h"
#include "System/Helper/PragmaWarning.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

#include <functional>

BookExperience::EffectiveModernCpp::Chapter6::Terms34::Terms34Example::Terms34Example() noexcept
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::EffectiveModernCpp::Chapter6::Terms34, Terms34Example)

void BookExperience::EffectiveModernCpp::Chapter6::Terms34::Terms34Example::SetSound0Example() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    // setSoundL�Ǹ���������
    // ������ָ��һ��������
    // �����������趨��1Сʱ������������30��
    const auto setSoundL = [](Sound s) noexcept {
        // ʹstd::chrone��������޶��δʼ�����
        using namespace std::chrono;

        Example0::SetAlarm(steady_clock::now() + hours(1),  // ��������ʱ��Ϊ1Сʱ��
                           s,
                           seconds(30));  // ����30��
    };
}

void BookExperience::EffectiveModernCpp::Chapter6::Terms34::Terms34Example::SetSound1Example() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    const auto setSoundL = [](Sound s) noexcept {
        using namespace std::chrono;
        using namespace std::literals;  //  ����C++14ʵ�ֵĺ�׺

        Example0::SetAlarm(steady_clock::now() + 1h,  // C++14��������һ�δ���������ͬ
                           s,
                           30s);
    };
}

void BookExperience::EffectiveModernCpp::Chapter6::Terms34::Terms34Example::SetSound2Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    using namespace std::chrono;  // ͬǰ
    using namespace std::literals;

    using namespace std::placeholders;  // ��������Ϊ��Ҫʹ�á�_1��

    const auto setSoundB =  // ��B����ʾ��bind��
        std::bind(Example0::SetAlarm,
                  steady_clock::now() + 1h,  // ����
                  _1,
                  30s);
}

void BookExperience::EffectiveModernCpp::Chapter6::Terms34::Terms34Example::SetSound3Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    using namespace std::chrono;
    using namespace std::literals;

    using namespace std::placeholders;

    const auto setSoundB =
        std::bind(Example0::SetAlarm,
                  std::bind(std::plus<>(), std::bind(steady_clock::now), 1h),
                  _1,
                  30s);
}

void BookExperience::EffectiveModernCpp::Chapter6::Terms34::Terms34Example::SetSound4Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    using namespace std::chrono;  // ͬǰ
    using namespace std::placeholders;

    const auto setSoundB =
        std::bind(Example0::SetAlarm,
                  std::bind(std::plus<steady_clock::time_point>(), std::bind(steady_clock::now), hours(1)),
                  _1,
                  seconds(30));
}

void BookExperience::EffectiveModernCpp::Chapter6::Terms34::Terms34Example::SetSound5Example() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    const auto setSoundL = [](Sound s) noexcept {  // ͬǰ
        using namespace std::chrono;
        using namespace std::literals;

        Example1::SetAlarm(steady_clock::now() + 1h,  // û���⣬���õ������βΰ汾��SetAlarm
                           s,
                           30s);
    };

    setSoundL(Sound::Siren);  // ������SetAlarm�ĺ��������Ա�����
}

void BookExperience::EffectiveModernCpp::Chapter6::Terms34::Terms34Example::SetSound6Example() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    using namespace std::chrono;
    using namespace std::literals;

    using namespace std::placeholders;

    //  ����Ӧ��ѡ���ĸ�SetAlarm
    /*
    const auto setSoundB =
        std::bind(Example1::SetAlarm,
                  std::bind(std::plus<>(), std::bind(steady_clock::now) , 1h),
                  _1,
                  30s);
                  */
}

void BookExperience::EffectiveModernCpp::Chapter6::Terms34::Terms34Example::SetSound7Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    using namespace std::chrono;
    using namespace std::literals;

    using namespace std::placeholders;

    using SetAlarm3ParamType = void (*)(Time t, Sound s, Duration d);
    const auto setSoundB =
        std::bind(static_cast<SetAlarm3ParamType>(Example1::SetAlarm),  // ����OK��
                  std::bind(std::plus<>(), std::bind(steady_clock::now), 1h),
                  _1,
                  30s);

    setSoundB(Sound::Siren);  // ������SetAlarm�ĺ����屻�����Ŀ����Բ���
}

void BookExperience::EffectiveModernCpp::Chapter6::Terms34::Terms34Example::Between0Example() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    constexpr auto lowVal = 0;
    constexpr auto highVal = 0;

    const auto betweenL = [lowVal, highVal](const auto& val) {  // C++14
        return lowVal <= val && val <= highVal;
    };
}

void BookExperience::EffectiveModernCpp::Chapter6::Terms34::Terms34Example::Between1Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    using namespace std::placeholders;

    constexpr auto lowVal = 0;
    constexpr auto highVal = 0;

    const auto betweenL = std::bind(std::logical_and<>(),  // C++14
                                    std::bind(std::less_equal<>(), lowVal, _1),
                                    std::bind(std::less_equal<>(), _1, highVal));
}

void BookExperience::EffectiveModernCpp::Chapter6::Terms34::Terms34Example::Between2Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    using namespace std::placeholders;

    constexpr auto lowVal = 0;
    constexpr auto highVal = 0;

    const auto betweenL = std::bind(std::logical_and<bool>(),  // C++11�汾
                                    std::bind(std::less_equal<int>(), lowVal, _1),
                                    std::bind(std::less_equal<int>(), _1, highVal));
}

void BookExperience::EffectiveModernCpp::Chapter6::Terms34::Terms34Example::Between3Example() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    constexpr auto lowVal = 0;
    constexpr auto highVal = 0;

    const auto betweenL = [lowVal, highVal](int val) {  // C++11�汾
        return lowVal <= val && val <= highVal;
    };
}

void BookExperience::EffectiveModernCpp::Chapter6::Terms34::Terms34Example::CompressExample() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    Widget w;

    using namespace std::placeholders;

    auto compressRateB = std::bind(Compress, w, _1);

    // w�ǰ�ֵ����lev�ǰ�ֵ����
    const auto compressRateL = [w](CompLevel lev) noexcept {
        return Compress(w, lev);
    };

    // ʵ���ǰ�ֵ����
    compressRateL(CompLevel::High);

    compressRateB(CompLevel::High);
}

void BookExperience::EffectiveModernCpp::Chapter6::Terms34::Terms34Example::PolyWidget0Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    using namespace std::placeholders;

    PolyWidget pw;

    auto boundPW = std::bind(pw, _1);

    boundPW(1930);  // ����int��PolyWidget::operator()

    boundPW(nullptr);  // ����nullptr��PolyWidget::operator()

    boundPW("Rosebud");  // �����ַ�����������PolyWidget::operator()
}

void BookExperience::EffectiveModernCpp::Chapter6::Terms34::Terms34Example::PolyWidget1Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    PolyWidget pw;

    const auto boundPW = [pw](const auto& param) {  // C+++14
        pw(param);
    };
}
