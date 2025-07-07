/*
Copyright (c) 2025 Industrial Shields. All rights reserved

This file is part of node-librpiplc.

EUPL-1.2 notice:
LIBARY is licensed under the EUPL,
with extension of article 5 (compatibility clause) to any licence
for distributing derivative works that have been produced by the
normal use of the Work as a library.

LGPL-3.0-or-later notice:
node-librpiplc is free software: you can redistribute
it and/or modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation, either version
3 of the License, or (at your option) any later version.

node-librpiplc is distributed in the hope that it will
be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

const mapping = require("./mapping");

extras = {
        "RE": mapping.make_pin_direct(17),
        "DE": mapping.make_pin_direct(27),
        "CS0": mapping.make_pin_direct(8),
        "CS1": mapping.make_pin_direct(7),

        "EXP1_AN": 0xFFFFFFFF,
        "EXP1_PWM": 0xFFFFFFFF,
        "EXP1_INT": 0xFFFFFFFF,
        "EXP1_RST": 0xFFFFFFFF,

        "I0_4_20": mapping.make_pin_ads1015(0x49, 0x01),
        "I1_4_20": mapping.make_pin_ads1015(0x49, 0x00),
        "I0": mapping.make_pin_ads1015(0x49, 0x02),
        "I1": mapping.make_pin_ads1015(0x49, 0x03),
        "I2": mapping.make_pin_direct(20),
        "I3": mapping.make_pin_direct(21),
        "I4": mapping.make_pin_direct(26),

        "O0": mapping.make_pin_direct(19),
        "O1": mapping.make_pin_direct(6),
        "O2": mapping.make_pin_direct(5),
        "O3": mapping.make_pin_direct(22),
        "O4": mapping.make_pin_direct(4),
	"Q0": mapping.make_pin_direct(19),
        "Q1": mapping.make_pin_direct(6),
        "Q2": mapping.make_pin_direct(5),
        "Q3": mapping.make_pin_direct(22),
        "Q4": mapping.make_pin_direct(4),
}

module.exports = {
	"TOUCHBERRY_PI": {...extras},
};
