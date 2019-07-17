#include "al2o3_platform/platform.h"
#include "al2o3_memory/memory.h"
#include "input_basic/input.h"
#include "gainput/gainput.h"

namespace {
class GAInputAlloctor : gainput::Allocator {
	void *Allocate(size_t size, size_t align) override {
		return MEMORY_MALLOC(size);
	}
	void Deallocate(void *ptr) override {
		return MEMORY_FREE(ptr);
	}
};

gainput::Key InputBasicKeyToGAInput(InputBasic_Key key) {
#define KEYMAP(key) case InputBasic_Key_##key: return gainput::Key::Key##key;
	switch (key) {
	KEYMAP(Escape)
	KEYMAP(F1)
	KEYMAP(F2)
	KEYMAP(F3)
	KEYMAP(F4)
	KEYMAP(F5)
	KEYMAP(F6)
	KEYMAP(F7)
	KEYMAP(F8)
	KEYMAP(F9)
	KEYMAP(F10)
	KEYMAP(F11)
	KEYMAP(F12)
	KEYMAP(F13)
	KEYMAP(F14)
	KEYMAP(F15)
	KEYMAP(F16)
	KEYMAP(F17)
	KEYMAP(F18)
	KEYMAP(F19)
	KEYMAP(Print)
	KEYMAP(ScrollLock)
	KEYMAP(Break)
	KEYMAP(Space)
	KEYMAP(Apostrophe)
	KEYMAP(Comma)
	KEYMAP(Minus)
	KEYMAP(Period)
	KEYMAP(Slash)
	KEYMAP(0)
	KEYMAP(1)
	KEYMAP(2)
	KEYMAP(3)
	KEYMAP(4)
	KEYMAP(5)
	KEYMAP(6)
	KEYMAP(7)
	KEYMAP(8)
	KEYMAP(9)
	KEYMAP(Semicolon)
	KEYMAP(Less)
	KEYMAP(Equal)
	KEYMAP(A)
	KEYMAP(B)
	KEYMAP(C)
	KEYMAP(D)
	KEYMAP(E)
	KEYMAP(F)
	KEYMAP(G)
	KEYMAP(H)
	KEYMAP(I)
	KEYMAP(J)
	KEYMAP(K)
	KEYMAP(L)
	KEYMAP(M)
	KEYMAP(N)
	KEYMAP(O)
	KEYMAP(P)
	KEYMAP(Q)
	KEYMAP(R)
	KEYMAP(S)
	KEYMAP(T)
	KEYMAP(U)
	KEYMAP(V)
	KEYMAP(W)
	KEYMAP(X)
	KEYMAP(Y)
	KEYMAP(Z)
	KEYMAP(BracketLeft)
	KEYMAP(Backslash)
	KEYMAP(BracketRight)
	KEYMAP(Grave)
	KEYMAP(Left)
	KEYMAP(Right)
	KEYMAP(Up)
	KEYMAP(Down)
	KEYMAP(Insert)
	KEYMAP(Home)
	KEYMAP(Delete)
	KEYMAP(End)
	KEYMAP(PageUp)
	KEYMAP(PageDown)
	KEYMAP(NumLock)
	KEYMAP(KpEqual)
	KEYMAP(KpDivide)
	KEYMAP(KpMultiply)
	KEYMAP(KpSubtract)
	KEYMAP(KpAdd)
	KEYMAP(KpEnter)
	KEYMAP(KpInsert)
	KEYMAP(KpEnd)
	KEYMAP(KpDown)
	KEYMAP(KpPageDown)
	KEYMAP(KpLeft)
	KEYMAP(KpBegin)
	KEYMAP(KpRight)
	KEYMAP(KpHome)
	KEYMAP(KpUp)
	KEYMAP(KpPageUp)
	KEYMAP(KpDelete)
	KEYMAP(BackSpace)
	KEYMAP(Tab)
	KEYMAP(Return)
	KEYMAP(CapsLock)
	KEYMAP(ShiftL)
	KEYMAP(CtrlL)
	KEYMAP(SuperL)
	KEYMAP(AltL)
	KEYMAP(AltR)
	KEYMAP(SuperR)
	KEYMAP(Menu)
	KEYMAP(CtrlR)
	KEYMAP(ShiftR)
	KEYMAP(Back)
	KEYMAP(SoftLeft)
	KEYMAP(SoftRight)
	KEYMAP(Call)
	KEYMAP(Endcall)
	KEYMAP(Star)
	KEYMAP(Pound)
	KEYMAP(DpadCenter)
	KEYMAP(VolumeUp)
	KEYMAP(VolumeDown)
	KEYMAP(Power)
	KEYMAP(Camera)
	KEYMAP(Clear)
	KEYMAP(Symbol)
	KEYMAP(Explorer)
	KEYMAP(Envelope)
	KEYMAP(Equals)
	KEYMAP(At)
	KEYMAP(Headsethook)
	KEYMAP(Focus)
	KEYMAP(Plus)
	KEYMAP(Notification)
	KEYMAP(Search)
	KEYMAP(MediaPlayPause)
	KEYMAP(MediaStop)
	KEYMAP(MediaNext)
	KEYMAP(MediaPrevious)
	KEYMAP(MediaRewind)
	KEYMAP(MediaFastForward)
	KEYMAP(Mute)
	KEYMAP(Pictsymbols)
	KEYMAP(SwitchCharset)
	KEYMAP(Forward)
	KEYMAP(Extra1)
	KEYMAP(Extra2)
	KEYMAP(Extra3)
	KEYMAP(Extra4)
	KEYMAP(Extra5)
	KEYMAP(Extra6)
	KEYMAP(Fn)
	KEYMAP(Circumflex)
	KEYMAP(Ssharp)
	KEYMAP(Acute)
	KEYMAP(AltGr)
	KEYMAP(Numbersign)
	KEYMAP(Udiaeresis)
	KEYMAP(Adiaeresis)
	KEYMAP(Odiaeresis)
	KEYMAP(Section)
	KEYMAP(Aring)
	KEYMAP(Diaeresis)
	KEYMAP(Twosuperior)
	KEYMAP(RightParenthesis)
	KEYMAP(Dollar)
	KEYMAP(Ugrave)
	KEYMAP(Asterisk)
	KEYMAP(Colon)
	KEYMAP(Exclam)
	KEYMAP(BraceLeft)
	KEYMAP(BraceRight)
	KEYMAP(SysRq)
	default: return gainput::Key::KeyEscape;
	}
#undef KEYMAP
}

gainput::MouseButton InputBasicMouseButtonToGAInput(InputBasic_MouseButton button) {
#define BUTTONMAP(butt) case InputBasic_MouseButton_##butt: return gainput::MouseButton::MouseButton##butt;
	switch (button) {
	BUTTONMAP(Left)
	BUTTONMAP(Middle)
	BUTTONMAP(Right)
	BUTTONMAP(WheelUp)
	BUTTONMAP(WheelDown)
	BUTTONMAP(5)
	BUTTONMAP(6)
	BUTTONMAP(7)
	BUTTONMAP(8)
	BUTTONMAP(9)
	BUTTONMAP(10)
	BUTTONMAP(11)
	BUTTONMAP(12)
	BUTTONMAP(13)
	BUTTONMAP(14)
	BUTTONMAP(15)
	BUTTONMAP(16)
	BUTTONMAP(17)
	BUTTONMAP(18)
	BUTTONMAP(19)
	BUTTONMAP(20)
	default: return gainput::MouseButton::MouseButtonLeft;
	}
#undef BUTTONMAP
}

gainput::PadButton InputBasicPadButtonToGAInput(InputBasic_PadButton button) {
#define BUTTONMAP(butt) case InputBasic_PadButton_##butt: return gainput::PadButton::PadButton##butt;
	switch (button) {
	BUTTONMAP(Start)
	BUTTONMAP(Select)
	BUTTONMAP(Left)
	BUTTONMAP(Right)
	BUTTONMAP(Up)
	BUTTONMAP(Down)
	BUTTONMAP(A)
	BUTTONMAP(B)
	BUTTONMAP(X)
	BUTTONMAP(Y)
	BUTTONMAP(L1)
	BUTTONMAP(R1)
	BUTTONMAP(L2)
	BUTTONMAP(R2)
	BUTTONMAP(L3)
	BUTTONMAP(R3)
	BUTTONMAP(Home)
	BUTTONMAP(17)
	BUTTONMAP(18)
	BUTTONMAP(19)
	BUTTONMAP(20)
	default: return gainput::PadButton::PadButtonStart;
	}
#undef BUTTONMAP
}
gainput::MouseButton InputBasicMouseAxisToGAInput(InputBasic_Axis axis) {
	switch(axis) {
	case InputBasis_Axis_X: return gainput::MouseButton::MouseAxisX;
	case InputBasis_Axis_Y: return gainput::MouseButton::MouseAxisX;
	case InputBasis_Axis_RightX:  return gainput::MouseButton::MouseAxisX;
	case InputBasis_Axis_RightY:  return gainput::MouseButton::MouseAxisY;
	default: return gainput::MouseButton::MouseAxisX;
	}
}

gainput::PadButton InputBasicPadAxisToGAInput(InputBasic_Axis axis) {
	switch(axis) {
	case InputBasis_Axis_X: return gainput::PadButton::PadButtonLeftStickX;
	case InputBasis_Axis_Y: return gainput::PadButton::PadButtonLeftStickY;
	case InputBasis_Axis_RightX:  return gainput::PadButton::PadButtonRightStickX;
	case InputBasis_Axis_RightY:  return gainput::PadButton::PadButtonRightStickY;
	default: return gainput::PadButton::PadButtonLeftStickX;
	}
}


} // end anon namespace
typedef struct InputBasic_Context {
	GAInputAlloctor allocator;
	gainput::InputManager manager;
	gainput::InputMap mapper;

	gainput::InputDeviceMouse* mouse;
	gainput::InputDeviceKeyboard* keyboard;

} InputBasic_Context;

AL2O3_EXTERN_C InputBasic_ContextHandle InputBasic_Create() {
	auto ctx = (InputBasic_Context *) MEMORY_CALLOC(1, sizeof(InputBasic_Context));
	if (!ctx)
		return nullptr;

	new(&ctx->allocator) GAInputAlloctor();
	new(&ctx->manager) gainput::InputManager(false, (gainput::Allocator &) ctx->allocator);
	new(&ctx->mapper) gainput::InputMap(ctx->manager, nullptr, (gainput::Allocator &) ctx->allocator);

	// always create a mouse and keyboard, if they are null tell the client we don't have one
	ctx->keyboard = ctx->manager.CreateAndGetDevice<gainput::InputDeviceKeyboard>();
	ctx->mouse = ctx->manager.CreateAndGetDevice<gainput::InputDeviceMouse>();

	return ctx;
}

AL2O3_EXTERN_C void InputBasic_Destroy(InputBasic_ContextHandle handle) {
	auto ctx = (InputBasic_Context *) handle;
	if (!ctx)
		return;

	ctx->mapper.~InputMap();
	ctx->manager.~InputManager();
	ctx->allocator.~GAInputAlloctor();

	MEMORY_FREE(ctx);
}

AL2O3_EXTERN_C void InputBasic_SetWindowSize(InputBasic_ContextHandle handle, uint32_t width, uint32_t height) {
	auto ctx = (InputBasic_Context *) handle;
	if (!ctx)
		return;

	ctx->manager.SetDisplaySize(width, height);
}

AL2O3_EXTERN_C void InputBasic_Update(InputBasic_ContextHandle handle, double deltaTimeInMS) {
	auto ctx = (InputBasic_Context *) handle;
	if (!ctx)
		return;

	ctx->manager.Update((uint64_t) deltaTimeInMS);
}

AL2O3_EXTERN_C InputBasic_MapperHandle InputBasic_GetMapper(InputBasic_ContextHandle handle) {
	auto ctx = (InputBasic_Context *) handle;
	if (!ctx) return nullptr;

	return (InputBasic_MapperHandle) &ctx->mapper;
}

AL2O3_EXTERN_C void InputBasic_MapToMouseButton(InputBasic_MapperHandle handle,
																								uint32_t userId,
																								InputBasic_MouseHandle mouse,
																								InputBasic_MouseButton button) {
	auto mapper = (gainput::InputMap *) handle;
	auto gamouse = (gainput::InputDeviceMouse *) mouse;
	if (!mapper || !gamouse)
		return;
	auto mouseId = gamouse->GetDeviceId();

	mapper->MapBool(userId, mouseId, InputBasicMouseButtonToGAInput(button));
}

AL2O3_EXTERN_C void InputBasic_MapToKey(InputBasic_MapperHandle handle,
																				uint32_t userId,
																				InputBasic_KeyboardHandle keyboard,
																				InputBasic_Key key) {
	auto mapper = (gainput::InputMap *) handle;
	auto gakb = (gainput::InputDeviceKeyboard *) keyboard;
	if (!mapper || !gakb)
		return;
	auto kbId = gakb->GetDeviceId();

	mapper->MapBool(userId, kbId, InputBasicKeyToGAInput(key));

}
AL2O3_EXTERN_C void InputBasic_MapToPadButton(InputBasic_MapperHandle handle,
																							uint32_t userId,
																							InputBasic_PadHandle pad,
																							InputBasic_PadButton button) {
	auto mapper = (gainput::InputMap *) handle;
	auto gapad = (gainput::InputDevicePad *)pad;
	if (!mapper || !gapad)
		return;
	auto padId = gapad->GetDeviceId();

	mapper->MapBool(userId, padId, InputBasicPadButtonToGAInput(button));
}

AL2O3_EXTERN_C void InputBasic_MapToMouseAxis(InputBasic_MapperHandle handle,
																							uint32_t userId,
																							InputBasic_MouseHandle mouse,
																							InputBasic_Axis axis) {
	auto mapper = (gainput::InputMap *) handle;
	auto gamouse = (gainput::InputDeviceMouse *) mouse;
	if (!mapper || !gamouse)
		return;
	auto mouseId = gamouse->GetDeviceId();

	mapper->MapFloat(userId, mouseId, InputBasicMouseAxisToGAInput(axis));
}

AL2O3_EXTERN_C void InputBasic_MapToPadAxis(InputBasic_MapperHandle handle,
																						uint32_t userId,
																						InputBasic_PadHandle pad,
																						InputBasic_Axis axis) {
	auto mapper = (gainput::InputMap *) handle;
	auto gapad = (gainput::InputDevicePad *)pad;
	if (!mapper || !gapad)
		return;
	auto padId = gapad->GetDeviceId();

	mapper->MapFloat(userId, padId, InputBasicPadAxisToGAInput(axis));
}

AL2O3_EXTERN_C bool InputBasic_GetAsBool(InputBasic_ContextHandle handle, uint32_t userId) {
	auto ctx = (InputBasic_Context *) handle;
	if (!ctx) return false;

	return ctx->mapper.GetBool(userId);
}

AL2O3_EXTERN_C float InputBasic_GetAsFloat(InputBasic_MapperHandle handle, uint32_t userId) {
	auto ctx = (InputBasic_Context *) handle;
	if (!ctx) return 0.0f;

	return ctx->mapper.GetFloat(userId);
}


AL2O3_EXTERN_C uint32_t InputBasic_GetMouseCount(InputBasic_ContextHandle handle) {
	auto ctx = (InputBasic_Context *) handle;
	if (!ctx)
		return 0;

	return ctx->mouse->GetVariant() == gainput::InputDevice::DV_NULL ? 0 : 1;
}
AL2O3_EXTERN_C InputBasic_MouseHandle InputBasic_MouseCreate(InputBasic_ContextHandle handle, uint32_t index) {
	auto ctx = (InputBasic_Context *) handle;
	if (!ctx)
		return nullptr;

	return (InputBasic_MouseHandle)ctx->mouse;

}
AL2O3_EXTERN_C void InputBasic_MouseDestroy(InputBasic_MouseHandle handle) {
	// ignore we destroy it when the context is
}

AL2O3_EXTERN_C uint32_t InputBasic_GetKeyboardCount(InputBasic_ContextHandle handle) {
	auto ctx = (InputBasic_Context *) handle;
	if (!ctx)
		return 0;

	return ctx->keyboard->GetVariant() == gainput::InputDevice::DV_NULL ? 0 : 1;
}
AL2O3_EXTERN_C InputBasic_KeyboardHandle InputBasic_KeyboardCreate(InputBasic_ContextHandle handle, uint32_t index) {
	auto ctx = (InputBasic_Context *) handle;
	if (!ctx)
		return nullptr;

	return (InputBasic_KeyboardHandle) ctx->keyboard;
}
AL2O3_EXTERN_C void InputBasic_KeyboardDestroy(InputBasic_KeyboardHandle handle) {
	// ignore we destroy it when the context is
}

AL2O3_EXTERN_C uint32_t InputBasic_GetPadCount(InputBasic_ContextHandle handle) {
	auto ctx = (InputBasic_Context *) handle;
	if (!ctx)
		return 0;

	// TODO this deosn't work as this
	return ctx->manager.GetDeviceCountByType(gainput::InputDevice::DT_PAD);
}
AL2O3_EXTERN_C InputBasic_PadHandle InputBasic_PadCreate(InputBasic_ContextHandle handle, uint32_t index) {
	auto ctx = (InputBasic_Context *) handle;
	if (!ctx)
		return nullptr;

	return (InputBasic_PadHandle) ctx->manager.CreateAndGetDevice<gainput::InputDevicePad>(index);
}

AL2O3_EXTERN_C void InputBasic_PadDestroy(InputBasic_PadHandle handle) {
	// ignore we destroy it when the context is
}
