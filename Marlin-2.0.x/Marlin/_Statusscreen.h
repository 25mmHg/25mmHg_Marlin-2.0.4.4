/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
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

/**
 * Custom Status Screen bitmap
 *
 * Place this file in the root with your configuration files
 * and enable CUSTOM_STATUS_SCREEN_IMAGE in Configuration.h.
 *
 * Use the Marlin Bitmap Converter to make your own:
 * http://marlinfw.org/tools/u8glib/converter.html
 */

#pragma once

#define STATUS_LOGO_Y           2//10
#define STATUS_LOGO_WIDTH       56

const unsigned char status_logo_bmp[] PROGMEM = {
  B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111, // ########################################################
  B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111, // ########################################################
  B11000011,B10000001,B11111111,B11111111,B11111111,B10011001,B11111111, // ##....###......##########################..##..#########
  B10000001,B10000001,B11111111,B11111111,B11111111,B10011001,B11111111, // #......##......##########################..##..#########
  B10011001,B10011111,B10010001,B00111001,B00110011,B10011001,B10001001, // #..##..##..######..#...#..###..#..##..###..##..##...#..#
  B10011001,B10011111,B10000000,B00011000,B00000001,B10011001,B10000001, // #..##..##.....###..........##..........##..##..##......#
  B10011001,B10000011,B10000000,B00011000,B00000001,B10011001,B10000001, // #..##..##.....###..........##..........##..##..##......#
  B11110001,B10000001,B10011001,B00011001,B10011001,B10000001,B10001001, // ####...##......##..##..#...##..##..##..##......##...#..#
  B11110001,B10011001,B10011001,B10011001,B10011001,B10000001,B10011001, // ####...##..#...##..##..##..##..##..##..##......##..##..#
  B11100011,B11111001,B10011001,B10011001,B10011001,B10000001,B10011001, // ###...#######..##..##..##..##..##..##..##......##..##..#
  B11000111,B11111001,B10011001,B10011001,B10011001,B10011001,B10011001, // ##...########..##..##..##..##..##..##..##..##..##..##..#
  B11000111,B00011001,B10011001,B10011001,B10011001,B10011001,B10011001, // ##...###...##..##..##..##..##..##..##..##..##..##..##..#
  B10001111,B00011001,B10011001,B10011001,B10011001,B10011001,B10000001, // #...####...##..##..##..##..##..##..##..##..##..##......#
  B10000001,B10000001,B10011001,B10011001,B10011001,B10011001,B11100001, // #......##......##..##..##..##..##..##..##..##..####....#
  B10000001,B10000001,B10011001,B10011001,B10011001,B10011001,B10011001, // #......##......##..##..##..##..##..##..##..##..##..##..#
  B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B10000001, // #################################################......#
  B10000000,B00000000,B00000000,B00000000,B00000000,B00000001,B11000011, // #..............................................###....##
  B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111, // ########################################################
};

//
// Use default bitmaps
//
#define STATUS_HOTEND_ANIM
#define STATUS_BED_ANIM
#define STATUS_HEATERS_X      60//48
#define STATUS_BED_X          78//74
