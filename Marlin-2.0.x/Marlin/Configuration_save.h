/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2019 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * Configuration.h
 *
 * Basic settings such as:
 *
 * - Type of electronics
 * - Type of temperature sensor
 * - Printer geometry
 * - Endstop configuration
 * - LCD controller
 * - Extra features
 *
 * Advanced settings can be found in Configuration_adv.h
 *
 */
#define CONFIGURATION_H_VERSION 020000

//===========================================================================
//============================= Getting Started =============================
//===========================================================================

// Author info of this build printed to the host during boot and M115
#define STRING_CONFIG_H_AUTHOR "(alpine, sappireTFT35)" // Who made the changes.

// Show the Marlin bootscreen on startup. ** ENABLE FOR PRODUCTION **
#define SHOW_BOOTSCREEN

// Show the bitmap in Marlin/_Bootscreen.h on startup.
//#define SHOW_CUSTOM_BOOTSCREEN

// Show the bitmap in Marlin/_Statusscreen.h on the status screen.
//#define CUSTOM_STATUS_SCREEN_IMAGE

// @section machine

#define SERIAL_PORT 3
#define SERIAL_PORT_2 1
#define NUM_SERIAL 2
#define BAUDRATE 115200
#define MOTHERBOARD BOARD_MKS_ROBIN_NANO
#define CUSTOM_MACHINE_NAME "CASTOR sapphire pro"

// @section extruder

#define EXTRUDERS 1
#define DEFAULT_NOMINAL_FILAMENT_DIA 1.75

// @section temperature

#define TEMP_SENSOR_0 1
#define TEMP_SENSOR_1 0
#define TEMP_SENSOR_2 0
#define TEMP_SENSOR_3 0
#define TEMP_SENSOR_4 0
#define TEMP_SENSOR_5 0
#define TEMP_SENSOR_BED 1
#define TEMP_SENSOR_CHAMBER 0

// Dummy thermistor constant temperature readings, for use with 998 and 999
#define DUMMY_THERMISTOR_998_VALUE 25
#define DUMMY_THERMISTOR_999_VALUE 100

// Use temp sensor 1 as a redundant sensor with sensor 0. If the readings
// from the two sensors differ too much the print will be aborted.
//#define TEMP_SENSOR_1_AS_REDUNDANT
#define MAX_REDUNDANT_TEMP_SENSOR_DIFF 10

#define TEMP_RESIDENCY_TIME     10  // (seconds) Time to wait for hotend to "settle" in M109
#define TEMP_WINDOW              1  // (°C) Temperature proximity for the "temperature reached" timer
#define TEMP_HYSTERESIS          3  // (°C) Temperature proximity considered "close enough" to the target

#define TEMP_BED_RESIDENCY_TIME 10  // (seconds) Time to wait for bed to "settle" in M190
#define TEMP_BED_WINDOW          1  // (°C) Temperature proximity for the "temperature reached" timer
#define TEMP_BED_HYSTERESIS      3  // (°C) Temperature proximity considered "close enough" to the target

// Below this temperature the heater will be switched off
// because it probably indicates a broken thermistor wire.
#define HEATER_0_MINTEMP   5
#define HEATER_1_MINTEMP   5
#define HEATER_2_MINTEMP   5
#define HEATER_3_MINTEMP   5
#define HEATER_4_MINTEMP   5
#define HEATER_5_MINTEMP   5
#define BED_MINTEMP        5

// Above this temperature the heater will be switched off.
// This can protect components from overheating, but NOT from shorts and failures.
// (Use MINTEMP for thermistor short/failure protection.)
#define HEATER_0_MAXTEMP 275
#define HEATER_1_MAXTEMP 275
#define HEATER_2_MAXTEMP 275
#define HEATER_3_MAXTEMP 275
#define HEATER_4_MAXTEMP 275
#define HEATER_5_MAXTEMP 275
#define BED_MAXTEMP      125

//===========================================================================
//============================= PID Settings ================================
//===========================================================================
// PID Tuning Guide here: http://reprap.org/wiki/PID_Tuning

// Comment the following line to disable PID and enable bang-bang.
#define PIDTEMP
#define BANG_MAX 255     // Limits current to nozzle while in bang-bang mode; 255=full current
#define PID_MAX BANG_MAX // Limits current to nozzle while PID is active (see PID_FUNCTIONAL_RANGE below); 255=full current
#define PID_K1 0.95      // Smoothing factor within any PID loop
#if ENABLED(PIDTEMP)
  #define PID_EDIT_MENU         // Add PID editing to the "Advanced Settings" menu. (~700 bytes of PROGMEM)
  #define PID_AUTOTUNE_MENU     // Add PID auto-tuning to the "Advanced Settings" menu. (~250 bytes of PROGMEM)
  //#define PID_DEBUG             // Sends debug data to the serial port.
  //#define PID_OPENLOOP 1        // Puts PID in open loop. M104/M140 sets the output power from 0 to PID_MAX
  //#define SLOW_PWM_HEATERS      // PWM with very low frequency (roughly 0.125Hz=8s) and minimum state time of approximately 1s useful for heaters driven by a relay
  //#define PID_PARAMS_PER_HOTEND // Uses separate PID parameters for each extruder (useful for mismatched extruders)
                                  // Set/get with gcode: M301 E[extruder number, 0-2]
  #define PID_FUNCTIONAL_RANGE 10 // If the temperature difference between the target temperature and the actual temperature
                                  // is more than PID_FUNCTIONAL_RANGE then the PID will be shut off and the heater will be set to min/max.

  // If you are using a pre-configured hotend then you can use one of the value sets by uncommenting it

  //@ SapphirePro 50W MonsterHeater (full metal heatbreak, no sock no fans @200° C)
  #define DEFAULT_Kp 15.36
  #define DEFAULT_Ki 1.13
  #define DEFAULT_Kd 52.03

#endif // PIDTEMP

#define PIDTEMPBED
#define MAX_BED_POWER 255 // limits duty cycle to bed; 255=full current

#if ENABLED(PIDTEMPBED)
  // SapphirePro 24V Heater C5 S50
  #define DEFAULT_bedKp 45.99
  #define DEFAULT_bedKi 8.69
  #define DEFAULT_bedKd 60.84
  // FIND YOUR OWN: "M303 E-1 C8 S90" to run autotune on the bed at 90 degreesC for 8 cycles.
#endif // PIDTEMPBED

// @section extruder

#define PREVENT_COLD_EXTRUSION
#define EXTRUDE_MINTEMP 170
#define PREVENT_LENGTHY_EXTRUDE
#define EXTRUDE_MAXLENGTH 650 //@ needed for filament loading

//===========================================================================
//======================== Thermal Runaway Protection =======================
//===========================================================================

#define THERMAL_PROTECTION_HOTENDS // Enable thermal protection for all extruders
#define THERMAL_PROTECTION_BED     // Enable thermal protection for the heated bed
#define THERMAL_PROTECTION_CHAMBER // Enable thermal protection for the heated chamber

//===========================================================================
//============================= Mechanical Settings =========================
//===========================================================================

// @section machine

#define COREXY

//===========================================================================
//============================== Endstop Settings ===========================
//===========================================================================

// @section homing

#define USE_XMIN_PLUG
#define USE_ZMIN_PLUG
#define USE_YMAX_PLUG

// Mechanical endstop with COM to ground and NC to Signal uses "false" here (most common setup).
//@ microswitches
#define X_MIN_ENDSTOP_INVERTING true // Set to true to invert the logic of the endstop.
#define Y_MIN_ENDSTOP_INVERTING false// Set to true to invert the logic of the endstop.
#define Z_MIN_ENDSTOP_INVERTING true // Set to true to invert the logic of the endstop.
#define X_MAX_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
#define Y_MAX_ENDSTOP_INVERTING true // Set to true to invert the logic of the endstop.
#define Z_MAX_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
#define Z_MIN_PROBE_ENDSTOP_INVERTING false // Set to true to invert the logic of the probe.

/**
 * Stepper Drivers
 *
*/

//@ Sapphire Pro setup
#define X_DRIVER_TYPE  TMC2208_STANDALONE
#define Y_DRIVER_TYPE  TMC2208_STANDALONE
#define Z_DRIVER_TYPE  A4988
#define E0_DRIVER_TYPE A4988

//=============================================================================
//============================== Movement Settings ============================
//=============================================================================
// @section motion

//@ settings from 1.0.3 stock firmware
#define DEFAULT_AXIS_STEPS_PER_UNIT   { 80.3, 80.4, 1600, 415 }
#define DEFAULT_MAX_FEEDRATE          { 200, 200, 4, 75 }

/**
 * Default Max Acceleration (change/s) change = mm/s
 * Override with M201
 */
//@ keep speed reasonable
#define DEFAULT_MAX_ACCELERATION      { 2000, 2000, 100, 1000 }

/**
 * Default Acceleration (change/s) change = mm/s
 * Override with M204
 */
//@ keep speed reasonable
#define DEFAULT_ACCELERATION          1500    // X, Y, Z and E acceleration for printing moves
#define DEFAULT_RETRACT_ACCELERATION  1000    // E acceleration for retracts
#define DEFAULT_TRAVEL_ACCELERATION   2000    // X, Y, Z acceleration for travel (non printing) moves

/**
 * Junction Deviation
 *
 * Use Junction Deviation instead of traditional Jerk Limiting
 *
 * See:
 *   https://reprap.org/forum/read.php?1,739819
 *   http://blog.kyneticcnc.com/2018/10/computing-junction-deviation-for-marlin.html
 */
//@ 
//#define JUNCTION_DEVIATION
#if ENABLED(JUNCTION_DEVIATION)
  #define JUNCTION_DEVIATION_MM 0.025  // (mm) Distance from real junction edge
#endif

/**
 * Default Jerk (mm/s)
 * Override with M205 X Y Z E
 */
#if DISABLED(JUNCTION_DEVIATION)
  #define DEFAULT_XJERK 15.0
  #define DEFAULT_YJERK 15.0
  #define DEFAULT_ZJERK  0.4
#endif
#define DEFAULT_EJERK    1.5  // May be used by Linear Advance @lowered to keep extruder from rattling


/**
 * S-Curve Acceleration
 *
 */
//@
#define S_CURVE_ACCELERATION

//===========================================================================
//============================= Z Probe Options =============================
//===========================================================================
// @section probes

//
// See http://marlinfw.org/docs/configuration/probes.html
//

/**
 * Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN
 *
 * Enable this option for a probe connected to the Z Min endstop pin.
 */
//#define Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN

/**
 * The "Manual Probe" provides a means to do "Auto" Bed Leveling without a probe.
 * Use G29 repeatedly, adjusting the Z height at each point with movement commands
 * or (with LCD_BED_LEVELING) the LCD controller.
 */

#define PROBE_MANUALLY

/**
 * Z Probe to nozzle (X,Y) offset, relative to (0, 0).
 */
#define NOZZLE_TO_PROBE_OFFSET { 0, 0, 0 }
#define MIN_PROBE_EDGE 10
#define XY_PROBE_SPEED 6000
#define Z_PROBE_SPEED_FAST HOMING_FEEDRATE_Z
#define Z_PROBE_SPEED_SLOW (Z_PROBE_SPEED_FAST / 2)

#define X_ENABLE_ON 0
#define Y_ENABLE_ON 0
#define Z_ENABLE_ON 0
#define E_ENABLE_ON 0 // For all extruders

// Disables axis stepper immediately when it's not being used.
// WARNING: When motors turn off there is a chance of losing position accuracy!
#define DISABLE_X false
#define DISABLE_Y false
#define DISABLE_Z false
#define DISABLE_E false             // For all extruders
#define DISABLE_INACTIVE_EXTRUDER   // Keep only the active extruder enabled

// @section machine

// Invert the stepper direction. Change (or reverse the motor connector) if an axis goes the wrong way.
//@ TMC2208 behavior
#define INVERT_X_DIR true
#define INVERT_Y_DIR true
#define INVERT_Z_DIR false

// @section extruder
// For direct drive extruder v9 set to true, for geared extruder set to false.
#define INVERT_E0_DIR false
#define INVERT_E1_DIR false
#define INVERT_E2_DIR false
#define INVERT_E3_DIR false
#define INVERT_E4_DIR false
#define INVERT_E5_DIR false

// @section homing

#define Z_HOMING_HEIGHT 2  // (mm) Minimal Z height before homing (G28) for Z clearance above the bed, clamps, ...
                           // Be sure you have this distance over your Z_MAX_POS in case.

// Direction of endstops when homing; 1=MAX, -1=MIN
// :[-1,1]
#define X_HOME_DIR -1
//@ home to Y-max
#define Y_HOME_DIR 1
#define Z_HOME_DIR -1

// @section machine

//@
//@ my measurements
//@

// The size of the print bed
#define X_BED_SIZE 210
#define Y_BED_SIZE 210

// Travel limits (mm) after homing, corresponding to endstop positions.
#define X_MIN_POS -5
#define Y_MIN_POS 0
#define Z_MIN_POS 0
#define X_MAX_POS X_BED_SIZE
#define Y_MAX_POS 215
#define Z_MAX_POS 220

/**
 * Software Endstops
 *
 * - Prevent moves outside the set machine bounds.
 * - Individual axes can be disabled, if desired.
 * - X and Y only apply to Cartesian robots.
 * - Use 'M211' to set software endstops on/off or report current state
 */

// Min software endstops constrain movement within minimum coordinate bounds
#define MIN_SOFTWARE_ENDSTOPS
#if ENABLED(MIN_SOFTWARE_ENDSTOPS)
  #define MIN_SOFTWARE_ENDSTOP_X
  #define MIN_SOFTWARE_ENDSTOP_Y
  #define MIN_SOFTWARE_ENDSTOP_Z
#endif

// Max software endstops constrain movement within maximum coordinate bounds
#define MAX_SOFTWARE_ENDSTOPS
#if ENABLED(MAX_SOFTWARE_ENDSTOPS)
  #define MAX_SOFTWARE_ENDSTOP_X
  #define MAX_SOFTWARE_ENDSTOP_Y
  #define MAX_SOFTWARE_ENDSTOP_Z
#endif

//===========================================================================
//=============================== Bed Leveling ==============================
//===========================================================================
// @section calibrate

// Add a menu item to move between bed corners for manual bed adjustment
//@
#define LEVEL_BED_CORNERS

#if ENABLED(LEVEL_BED_CORNERS)
  #define LEVEL_CORNERS_INSET 25    // (mm) An inset for corner leveling
  #define LEVEL_CORNERS_Z_HOP  4.0  // (mm) Move nozzle up before moving between corners
  #define LEVEL_CORNERS_HEIGHT 0.0  // (mm) Z height of nozzle at leveling points
  #define LEVEL_CENTER_TOO        // Move to the center after the last corner
#endif

// Homing speeds (mm/m)
//@
#define HOMING_FEEDRATE_XY (45*60)
#define HOMING_FEEDRATE_Z  (10*60)

// Validate that endstops are triggered on homing moves
#define VALIDATE_HOMING_ENDSTOPS

// @section calibrate

//=============================================================================
//============================= Additional Features ===========================
//=============================================================================

// @section extras

/**
 * EEPROM
 *
 * Persistent storage to preserve configurable settings across reboots.
 *
 *   M500 - Store settings to EEPROM.
 *   M501 - Read settings from EEPROM. (i.e., Throw away unsaved changes)
 *   M502 - Revert settings to "factory" defaults. (Follow with M500 to init the EEPROM.)
 */
#define EEPROM_SETTINGS     // Persistent storage with M500 and M501
//#define DISABLE_M503        // Saves ~2700 bytes of PROGMEM. Disable for release!
#define EEPROM_CHITCHAT       // Give feedback on EEPROM commands. Disable to save PROGMEM.
#if ENABLED(EEPROM_SETTINGS)
  //#define EEPROM_AUTO_INIT  // Init EEPROM automatically on any errors.
#endif

//
// Host Keepalive
//
// When enabled Marlin will send a busy status message to the host
// every couple of seconds when it can't accept commands.
//
#define HOST_KEEPALIVE_FEATURE        // Disable this if your host doesn't like keepalive messages
#define DEFAULT_KEEPALIVE_INTERVAL 2  // Number of seconds between "busy" messages. Set with M113.
#define BUSY_WHILE_HEATING            // Some hosts require "busy" messages even during heating

// @section temperature

// Preheat Constants
//@
#define PREHEAT_1_LABEL       "ABS"
#define PREHEAT_1_TEMP_HOTEND 240
#define PREHEAT_1_TEMP_BED    105
#define PREHEAT_1_FAN_SPEED     0 // Value from 0 to 255

//@
#define PREHEAT_2_LABEL       "PETG"
#define PREHEAT_2_TEMP_HOTEND 230
#define PREHEAT_2_TEMP_BED    70
#define PREHEAT_2_FAN_SPEED     0 // Value from 0 to 255

/**
 * Nozzle Park
 *
 * Park the nozzle at the given XYZ position on idle or G27.
 *
 * The "P" parameter controls the action applied to the Z axis:
 *
 *    P0  (Default) If Z is below park Z raise the nozzle.
 *    P1  Raise the nozzle always to Z-park height.
 *    P2  Raise the nozzle by Z-park amount, limited to Z_MAX_POS.
 */
//@
#define NOZZLE_PARK_FEATURE

#if ENABLED(NOZZLE_PARK_FEATURE)
  // Specify a park position as { X, Y, Z_raise }
  #define NOZZLE_PARK_POINT { (X_MIN_POS + 2), (Y_MAX_POS - 120), 50 }
  #define NOZZLE_PARK_XY_FEEDRATE 100   // (mm/s) X and Y axes feedrate (also used for delta Z axis)
  #define NOZZLE_PARK_Z_FEEDRATE 5      // (mm/s) Z axis feedrate (not used for delta printers)
#endif

/**
 * Print Job Timer
 *
 * Automatically start and stop the print job timer on M104/M109/M190.
 *
 *   M104 (hotend, no wait) - high temp = none,        low temp = stop timer
 *   M109 (hotend, wait)    - high temp = start timer, low temp = stop timer
 *   M190 (bed, wait)       - high temp = start timer, low temp = none
 *
 * The timer can also be controlled with the following commands:
 *
 *   M75 - Start the print job timer
 *   M76 - Pause the print job timer
 *   M77 - Stop the print job timer
 */
#define PRINTJOB_TIMER_AUTOSTART

/**
 * Print Counter 
 * View the current statistics with M78.
 */
//#define PRINTCOUNTER

//=============================================================================
//============================= LCD and SD support ============================
//=============================================================================

// @section lcd

/**
 * LCD LANGUAGE
 * :{ 'en':'English', 'an':'Aragonese', 'bg':'Bulgarian', 'ca':'Catalan', 'cz':'Czech', 'da':'Danish', 'de':'German', 'el':'Greek', 'el-gr':'Greek (Greece)', 'es':'Spanish', 'eu':'Basque-Euskera', 'fi':'Finnish', 'fr':'French', 'gl':'Galician', 'hr':'Croatian', 'it':'Italian', 'jp-kana':'Japanese', 'ko_KR':'Korean (South Korea)', 'nl':'Dutch', 'pl':'Polish', 'pt':'Portuguese', 'pt-br':'Portuguese (Brazilian)', 'ru':'Russian', 'sk':'Slovak', 'tr':'Turkish', 'uk':'Ukrainian', 'vi':'Vietnamese', 'zh_CN':'Chinese (Simplified)', 'zh_TW':'Chinese (Traditional)', 'test':'TEST' }
 */
#define LCD_LANGUAGE en
#define DISPLAY_CHARSET_HD44780 JAPANESE

#define LCD_INFO_SCREEN_STYLE 0
#define SDSUPPORT
#define SDIO_SUPPORT
#define SD_CHECK_AND_RETRY
//
// Individual Axis Homing
//
// Add individual axis homing items (Home X, Home Y, and Home Z) to the LCD menu.
//
//@
#define INDIVIDUAL_AXIS_HOMING_MENU

//
// SPEAKER/BUZZER
//
// If you have a speaker that can produce tones, enable it here.
// By default Marlin assumes you have a buzzer with a fixed frequency.
//
//#define SPEAKER
// Note: Test audio output with the G-Code:
//  M300 S<frequency Hz> P<duration ms>
//
//#define LCD_FEEDBACK_FREQUENCY_DURATION_MS 2
//#define LCD_FEEDBACK_FREQUENCY_HZ 5000

//=============================================================================
//=============================== Graphical TFTs ==============================
//=============================================================================
//
// FSMC display (MKS Robin, Alfawise U20, JGAurora A5S, REXYZ A1, etc.)
//
#define FSMC_GRAPHICAL_TFT

//=============================================================================
//============================  Other Controllers  ============================
//=============================================================================

#define TOUCH_BUTTONS
#if ENABLED(TOUCH_BUTTONS)
  #define BUTTON_DELAY_EDIT  50 // (ms) Button repeat delay for edit screens
  #define BUTTON_DELAY_MENU 250 // (ms) Button repeat delay for menus
  //@ different calib for 3.5"TFT
  #define XPT2046_X_CALIBRATION    12013
  #define XPT2046_X_OFFSET           -32
  #define XPT2046_Y_CALIBRATION    -8711
  #define XPT2046_Y_OFFSET           256
#endif

#define SOFT_PWM_SCALE 0
#define SERVO_DELAY { 300 }