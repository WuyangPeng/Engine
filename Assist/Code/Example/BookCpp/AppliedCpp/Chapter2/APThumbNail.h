///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.0 (2021/01/26 23:49)

#ifndef APPLIED_CPP_CHAPTER2_AP_THUMB_NAIL_H
#define APPLIED_CPP_CHAPTER2_AP_THUMB_NAIL_H

#include "Example/BookCpp/AppliedCpp/AppliedCppDll.h"

#include "APImage.h"

namespace BookIntermediate
{
    namespace AppliedCpp
    {
        ///  简单的独立缩略图生成器程序

        /// 标尺

        ///       1         2         3         4         5         6    6
        ///345678901234567890123456789012345678901234567890123456789012345

        /// APThumbNail读取输入文件并生成输出文件，该文件是原始文件的指定缩小版本。
        class APPLIED_CPP_DEFAULT_DECLARE APThumbNail final
        {
        public:
            using ClassType = APThumbNail;

        public:
            APThumbNail() noexcept;

        public:
            CLASS_INVARIANT_DECLARE;

            // 默认的复制构造函数和赋值运算符是ok的

            // 创建具有指定缩小系数（2,3,..）的缩略图
            void CreateThumbNail(const char* inputFile, const char* outputFile, int factor);

            // 检测到错误时将抛出异常
            class Invalid
            {
            };

        private:
            // 读取原始图像并写入缩略图。
            void ReadImage(const char* inputFile);
            void WriteImage(const char* outputFile) const;

            // 在缩略图图像中产生一个输出像素
            [[nodiscard]] unsigned char AveragePixels(int x0, int y0, int factor);

            // 输入像素
            APImage image;
            // 缩略图
            APImage thumbNail;
        };
    }
}

#endif  // APPLIED_CPP_CHAPTER2_AP_THUMB_NAIL_H
