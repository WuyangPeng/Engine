///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.7 (2021/12/03 19:42)

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

    // setSoundL是个函数对象，
    // 它接受指定一个声音，
    // 该声音将在设定后1小时发出，并持续30秒
    const auto setSoundL = [](Sound s) noexcept {
        // 使std::chrone组件不加限定饰词即可用
        using namespace std::chrono;

        Example0::SetAlarm(steady_clock::now() + hours(1),  // 警报发出时刻为1小时后
                           s,
                           seconds(30));  // 持续30秒
    };
}

void BookExperience::EffectiveModernCpp::Chapter6::Terms34::Terms34Example::SetSound1Example() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    const auto setSoundL = [](Sound s) noexcept {
        using namespace std::chrono;
        using namespace std::literals;  //  汇入C++14实现的后缀

        Example0::SetAlarm(steady_clock::now() + 1h,  // C++14，但和上一段代码意义相同
                           s,
                           30s);
    };
}

void BookExperience::EffectiveModernCpp::Chapter6::Terms34::Terms34Example::SetSound2Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    using namespace std::chrono;  // 同前
    using namespace std::literals;

    using namespace std::placeholders;  // 本句是因为需要使用“_1”

    const auto setSoundB =  // “B”表示“bind”
        std::bind(Example0::SetAlarm,
                  steady_clock::now() + 1h,  // 错误
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

    using namespace std::chrono;  // 同前
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

    const auto setSoundL = [](Sound s) noexcept {  // 同前
        using namespace std::chrono;
        using namespace std::literals;

        Example1::SetAlarm(steady_clock::now() + 1h,  // 没问题，调用的是三形参版本的SetAlarm
                           s,
                           30s);
    };

    setSoundL(Sound::Siren);  // 在这里SetAlarm的函数体大可以被内联
}

void BookExperience::EffectiveModernCpp::Chapter6::Terms34::Terms34Example::SetSound6Example() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    using namespace std::chrono;
    using namespace std::literals;

    using namespace std::placeholders;

    //  错误！应该选择哪个SetAlarm
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
        std::bind(static_cast<SetAlarm3ParamType>(Example1::SetAlarm),  // 总算OK了
                  std::bind(std::plus<>(), std::bind(steady_clock::now), 1h),
                  _1,
                  30s);

    setSoundB(Sound::Siren);  // 在这里SetAlarm的函数体被内联的可能性不大
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

    const auto betweenL = std::bind(std::logical_and<bool>(),  // C++11版本
                                    std::bind(std::less_equal<int>(), lowVal, _1),
                                    std::bind(std::less_equal<int>(), _1, highVal));
}

void BookExperience::EffectiveModernCpp::Chapter6::Terms34::Terms34Example::Between3Example() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    constexpr auto lowVal = 0;
    constexpr auto highVal = 0;

    const auto betweenL = [lowVal, highVal](int val) {  // C++11版本
        return lowVal <= val && val <= highVal;
    };
}

void BookExperience::EffectiveModernCpp::Chapter6::Terms34::Terms34Example::CompressExample() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    Widget w;

    using namespace std::placeholders;

    auto compressRateB = std::bind(Compress, w, _1);

    // w是按值捕获，lev是按值传递
    const auto compressRateL = [w](CompLevel lev) noexcept {
        return Compress(w, lev);
    };

    // 实参是按值传递
    compressRateL(CompLevel::High);

    compressRateB(CompLevel::High);
}

void BookExperience::EffectiveModernCpp::Chapter6::Terms34::Terms34Example::PolyWidget0Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    using namespace std::placeholders;

    PolyWidget pw;

    auto boundPW = std::bind(pw, _1);

    boundPW(1930);  // 传递int给PolyWidget::operator()

    boundPW(nullptr);  // 传递nullptr给PolyWidget::operator()

    boundPW("Rosebud");  // 传递字符串字面量给PolyWidget::operator()
}

void BookExperience::EffectiveModernCpp::Chapter6::Terms34::Terms34Example::PolyWidget1Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    PolyWidget pw;

    const auto boundPW = [pw](const auto& param) {  // C+++14
        pw(param);
    };
}
