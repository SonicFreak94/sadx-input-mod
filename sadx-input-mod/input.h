#pragma once

#include "DreamPad.h"

struct KeyboardMapping
{
	Uint8 Analog1_Up;
	Uint8 Analog1_Down;
	Uint8 Analog1_Left;
	Uint8 Analog1_Right;
	Uint8 Analog2_Up;
	Uint8 Analog2_Down;
	Uint8 Analog2_Left;
	Uint8 Analog2_Right;
	Uint8 LT;
	Uint8 RT;
	Uint8 DPad_Up;
	Uint8 DPad_Down;
	Uint8 DPad_Left;
	Uint8 DPad_Right;
	Uint8 Button_A;
	Uint8 Button_B;
	Uint8 Button_X;
	Uint8 Button_Y;
	Uint8 Button_Start;
	Uint8 Button_LeftShoulder;
	Uint8 Button_RightShoulder;
	Uint8 Button_Back;
	Uint8 Button_LeftStick;
	Uint8 Button_RightStick;
};

struct DemoControllerData
{
	int HeldButtons;
	__int16 LTrigger;
	__int16 RTrigger;
	__int16 StickX;
	__int16 StickY;
	int NotHeldButtons;
	int PressedButtons;
	int ReleasedButtons;
};

namespace input
{
	void poll_controllers();
	void WriteAnalogs_hook();
	void InitRawControllers_hook();
	void __cdecl EnableController_r(Uint8 index);
	void __cdecl DisableController_r(Uint8 index);

	extern ControllerData raw_input[GAMEPAD_COUNT];
	extern bool controller_enabled[GAMEPAD_COUNT];
	extern bool debug;
	extern bool disable_mouse;
	extern bool e_held;
	extern bool demo;
	extern KeyboardMapping keys;
}
