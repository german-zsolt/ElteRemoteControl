/**
 * Project ElteRemoteControlLib
 * @author Zsolt German
 * @version 0.1
 */

#ifndef _CONTROLLERCONVERTER_TEST_H
#define _CONTROLLERCONVERTER_TEST_H

#include <cxxtest/TestSuite.h>
#include "ControllerConverter/ControllerDecoder.h"
#include "ControllerConverter/ControllerEncoder.h"
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
using namespace ElteRemoteControlLib::NS_ControllerConverter;
using namespace ElteRemoteControlLib::NS_ControllerState;

class ControllerConverterTest: public CxxTest::TestSuite {
public:
	void testKeyboardButtonState() {
		assertEqualsControllerButtonState(KeyboardButtonState(0, false));
	}
	void testKeyboardButtonStateTrue() {
		assertEqualsControllerButtonState(KeyboardButtonState(1, true));
	}
	void testKeyboardLockStateFalse() {
		assertEqualsControllerButtonState(KeyboardLockState(127, false));
	}
	void testKeyboardLockStateTrue() {
		assertEqualsControllerButtonState(KeyboardLockState(128, true));
	}
	void testMouseButtonStateFalse() {
		assertEqualsControllerButtonState(MouseButtonState(254, false));
	}
	void testMouseButtonStateTrue() {
		assertEqualsControllerButtonState(MouseButtonState(255, true));
	}

	void testMousePositionState1byte() {
		assertEqualsController2DPositionState(MousePositionState(254, 0, 0xFF));
	}
	void testMousePositionState2byte() {
		assertEqualsController2DPositionState(
				MousePositionState(254, 0x100, 0xFFFF));
	}

	void testMouseScrollStateMinus() {
		assertEqualsControllerShiftingState(MouseScrollState(0, -128));
	}
	void testMouseScrollStateZero() {
		assertEqualsControllerShiftingState(MouseScrollState(1, 0));
	}
	void testMouseScrollStatePlus() {
		assertEqualsControllerShiftingState(MouseScrollState(2, 127));
	}
private:
	void assertEqualsControllerState(const ControllerState& a,
			const ControllerState& b) {
		TS_ASSERT_EQUALS(a.getControllerType(), b.getControllerType());
		TS_ASSERT_EQUALS(a.controller, b.controller);
	}
	void assertEqualsController2DPositionState(
			const Controller2DPositionState& a) {
		unique_ptr<ControllerState> p = encodeThenDecode(a);
		Controller2DPositionState& b =
				*dynamic_cast<Controller2DPositionState*>(p.get());
		assertEqualsControllerState(a, b);
		TS_ASSERT_EQUALS(a.positionX, b.positionX);
		TS_ASSERT_EQUALS(a.positionY, b.positionY);
	}
	void assertEqualsControllerButtonState(const ControllerButtonState& a) {
		unique_ptr<ControllerState> p = encodeThenDecode(a);
		ControllerButtonState& b =
				*dynamic_cast<ControllerButtonState*>(p.get());
		assertEqualsControllerState(a, b);
		TS_ASSERT_EQUALS(a.pressed, b.pressed);
	}
	void assertEqualsControllerShiftingState(const ControllerShiftingState& a) {
		unique_ptr<ControllerState> p = encodeThenDecode(a);
		ControllerShiftingState& b =
				*dynamic_cast<ControllerShiftingState*>(p.get());
		assertEqualsControllerState(a, b);
		TS_ASSERT_EQUALS(a.shifting, b.shifting);
	}
	unique_ptr<ControllerState> encodeThenDecode(const ControllerState& state) {
		unique_ptr<uint8[]> data = state.getData();
		return ControllerDecoder::getState(data.get());
	}
};

#endif //_CONTROLLERCONVERTER_TEST_H
