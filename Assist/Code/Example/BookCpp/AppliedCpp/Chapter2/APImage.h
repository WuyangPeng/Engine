///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.0 (2021/01/26 23:40)

#ifndef APPLIED_CPP_CHAPTER2_AP_IMAGE_H
#define APPLIED_CPP_CHAPTER2_AP_IMAGE_H

#include "Example/BookCpp/AppliedCpp/AppliedCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <string>

namespace BookIntermediate
{
    namespace AppliedCpp
    {
        ///  简单的独立缩略图生成器程序

        /// 标尺
        ///       1         2         3         4         5         6    6
        ///345678901234567890123456789012345678901234567890123456789012345

        /// APImage是一个简单的图像类，可为8位单色图像分配内存，并允许随机访问图像数据。
        class APPLIED_CPP_DEFAULT_DECLARE APImage final
        {
        public:
            using ClassType = APImage;

        public:
            CLASS_INVARIANT_DECLARE;

        public:
            // 创建一个空图像，适用于以后的分配
            APImage() noexcept;

            // 创建指定大小的图像
            APImage(int width, int height);

            ~APImage();

            // 我们需要定义自己的复制构造函数和赋值运算符，因为成员复制无法满足要求。
            APImage(const APImage& src);
            APImage& operator=(const APImage& src);

            APImage(APImage&& src) noexcept;
            APImage& operator=(APImage&& src) noexcept;

            // 在赋值期间使用（Sutter，Exceptional C++）以使赋值运算符异常安全。
            void Swap(APImage& src) noexcept;

            // 写入/读取单个像素。
            // 如果坐标无效，则抛出rangeError。
            void SetPixel(int x, int y, unsigned char pixel);
            [[nodiscard]] unsigned char GetPixel(int x, int y) const;

            // 测试图像数据是否存在，并且大概有效。
            [[nodiscard]] bool IsImageValid() const noexcept;

            // 返回图像的范围
            [[nodiscard]] int Width() const noexcept;
            [[nodiscard]] int Height() const noexcept;

            // 如果请求的数据不在图像中，则会引发错误
            class RangeError
            {
            };

            APImage ArbitraryAlgorithm(const std::string& args);

        private:
            // 重新初始化对象并释放已分配的内存
            void Cleanup() noexcept;

            // 初始化图像数据
            void Init();

            // 图像宽度
            int width;
            // 图像高度
            int height;
            // 图像数据
            unsigned char* pixels;
        };
    }
}

#endif  // APPLIED_CPP_CHAPTER2_AP_IMAGE_H
