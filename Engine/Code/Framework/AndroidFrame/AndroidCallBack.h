// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 16:40)

#ifndef FRAMEWORK_ANDROID_FRAME_ANDROID_CALL_BACK_H
#define FRAMEWORK_ANDROID_FRAME_ANDROID_CALL_BACK_H

#include "AndroidCallBackInterface.h"

namespace Framework
{
	template <typename MiddleLayer>
	class AndroidCallBack : public AndroidCallBackInterface
	{
	public:
		using MiddleLayerType = MiddleLayer;
		using ClassType = AndroidCallBack<MiddleLayer>;
		using ParentType = AndroidCallBackInterface;

	public:
		explicit AndroidCallBack(int64_t delta);

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		void RedrawNeededMessage(AndroidApp* androidApp) override;
		void ResizedMessage(AndroidApp* androidApp) override;
		void RectChanged(AndroidApp* androidApp) override;
		void InitMessage(AndroidApp* androidApp) override;
		void TermMessage(AndroidApp* androidApp) override;
		void Display(AndroidApp* androidApp, int64_t timeDelta) override;
		int KeyDownMessage(AndroidApp* androidApp, AndroidInputEvent* androidInputEvent) override;
		int KeyUpMessage(AndroidApp* androidApp, AndroidInputEvent* androidInputEvent) override;
		int ActionDownMessage(AndroidApp* androidApp, AndroidInputEvent* androidInputEvent) override;
		int ActionUpMessage(AndroidApp* androidApp, AndroidInputEvent* androidInputEvent) override;
		int ActionMoveMessage(AndroidApp* androidApp, AndroidInputEvent* androidInputEvent) override;

	private:
		using MiddleLayerTypeSharedPtr = std::shared_ptr<MiddleLayerType>;

	private:
		MiddleLayerTypeSharedPtr m_MiddleLayer;
	};
}

#endif // FRAMEWORK_ANDROID_FRAME_ANDROID_CALL_BACK_H
