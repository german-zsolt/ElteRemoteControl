/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#ifndef _CONTROLLERSTATE_TEST_H
#define _CONTROLLERSTATE_TEST_H

#include <cxxtest/TestSuite.h>
#include "ControllerState/Controller2DPositionState.h"
#include "ControllerState/ControllerButtonState.h"
#include "ControllerState/ControllerShiftingState.h"
#include "ControllerState/ControllerState.h"
#include "ControllerState/KeyboardButtonState.h"
#include "ControllerState/KeyboardLockState.h"
#include "ControllerState/MouseButtonState.h"
#include "ControllerState/MousePositionState.h"
#include "ControllerState/MouseScrollState.h"

using namespace ElteRemoteControlLib;
using namespace ElteRemoteControlLib::NS_ControllerState;

class ControllerStateTest: public CxxTest::TestSuite {
public:
	void testKeyboardButtonStateFalse() {
		runTestControllerButtonState<KeyboardButtonState>(1, 0, false);
	}
	void testKeyboardButtonStateTrue() {
		runTestControllerButtonState<KeyboardButtonState>(1, 1, true);
	}
	void testKeyboardLockStateFalse() {
		runTestControllerButtonState<KeyboardLockState>(2, 127, false);
	}
	void testKeyboardLockStateTrue() {
		runTestControllerButtonState<KeyboardLockState>(2, 128, true);
	}
	void testMouseButtonStateFalse() {
		runTestControllerButtonState<MouseButtonState>(3, 254, false);
	}
	void testMouseButtonStateTrue() {
		runTestControllerButtonState<MouseButtonState>(3, 255, true);
	}

	void testMousePositionState1byte() {
		runTestController2DPositionState<MousePositionState>(4, 254, 0, 0xFF);
	}
	void testMousePositionState2byte() {
		runTestController2DPositionState<MousePositionState>(4, 254, 0x100,
				0xFFFF);
	}

	void testMouseScrollStateMinus() {
		runTestControllerShiftingState<MouseScrollState>(5, 0, -128);
	}
	void testMouseScrollStateZero() {
		runTestControllerShiftingState<MouseScrollState>(5, 1, 0);
	}
	void testMouseScrollStatePlus() {
		runTestControllerShiftingState<MouseScrollState>(5, 2, 127);
	}
private:
	bool assertControllerState(const ControllerState& o,
			const uint8 controllerType, const uint8 controller) {
		TS_ASSERT_EQUALS(o.getControllerType(), controllerType);
		TS_ASSERT_EQUALS(o.controller, controller);
	}
	template<typename T> void runTestController2DPositionState(
			const uint8 controllerType, const uint8 controller,
			const uint16 positionX, const uint16 positionY) {
		const Controller2DPositionState& o = T(controller, new uint16[2] {
				positionX, positionY });
		assertControllerState(o, controllerType, controller);
		TS_ASSERT_EQUALS(o.position[0], positionX);
		TS_ASSERT_EQUALS(o.position[1], positionY);
	}
	template<typename T> void runTestControllerButtonState(
			const uint8 controllerType, const uint8 controller,
			const bool pressed) {
		const ControllerButtonState& o = T(controller, pressed);
		assertControllerState(o, controllerType, controller);
		TS_ASSERT_EQUALS(o.pressed, pressed);
	}
	template<typename T> void runTestControllerShiftingState(
			const uint8 controllerType, const uint8 controller,
			const int16 shifting) {
		const ControllerShiftingState& o = T(controller, shifting);
		assertControllerState(o, controllerType, controller);
		TS_ASSERT_EQUALS(o.shifting, shifting);
	}
};

#endif //_CONTROLLERSTATE_TEST_H
