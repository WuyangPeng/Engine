// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 13:23)

#ifndef FRAMEWORK_ANDROID_FRAME_ANDROID_CALL_BACK_H
#define FRAMEWORK_ANDROID_FRAME_ANDROID_CALL_BACK_H

#include "AndroidCallBackInterface.h"

#include <boost/shared_ptr.hpp>

namespace Framework
{
	template <typename ModelViewControllerMiddleLayerContainer>
	class AndroidCallBack : public AndroidCallBackInterface
	{
	public:
		typedef ModelViewControllerMiddleLayerContainer MiddleLayerType;
		typedef AndroidCallBack<ModelViewControllerMiddleLayerContainer> ClassType;
		typedef AndroidCallBackInterface ParentType;

	public:
		AndroidCallBack();
		virtual ~AndroidCallBack();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual void RedrawNeededMessage(struct AndroidApp* state);
		virtual void ResizedMessage(struct AndroidApp* state);
		virtual void RectChanged(struct AndroidApp* state);
		virtual void InitMessage(struct AndroidApp* state);
		virtual void TermMessage(struct AndroidApp* state);
		virtual void Display(struct AndroidApp* state ,int64_t timeDelta);
		virtual int KeyDownMessage(struct AndroidApp* state,
			                           AndroidInputEvent* event);
		virtual int KeyUpMessage(struct AndroidApp* state,
			                         AndroidInputEvent* event);
		virtual int ActionDownMessage(struct AndroidApp* state,
			                              AndroidInputEvent* event);
		virtual int ActionUpMessage(struct AndroidApp* state, 
			                            AndroidInputEvent* event);
		virtual int ActionMoveMessage(struct AndroidApp* state, 
			                              AndroidInputEvent* event);	

	private:
		typedef std::shared_ptr<MiddleLayerType> MiddleLayerTypePtr;

	private:
		MiddleLayerTypePtr m_MiddleLayerPtr;
	};
}

#endif // FRAMEWORK_ANDROID_FRAME_ANDROID_CALL_BACK_H
